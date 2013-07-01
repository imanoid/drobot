

#include <iostream>

#include <QApplication>
#include <boost/thread.hpp>

#include "DRobotActuation.h"
#include "DRobotVision.h"

#include "DRobotSliderGroup/DRobotSliderGroup.h"
#include "DRobotTimePlotter/DRobotTimePlotter.h"
#include "DRobotImageDisplay/DRobotImageDisplay.h"
#include "DRobotColorRangeSelector/DRobotColorRangeSelector.h"

#include "DRobotPerceptron/DRobotPerceptron.h"
#include "DRobotPopulationCoding/DRobotPopulationCoding.h"

class VisuoMotorLearning
{

public:

	VisuoMotorLearning()
	{
		init();
	}

	void run()
	{
		actuation->setInitialPositions();

		vision->getFrame();
		vision->applyTransforms();
		usleep(10000);
		vision->getFrame();
		vision->applyTransforms();
		usleep(10000);
		vision->getFrame();
		vision->applyTransforms();

		int nRows = vision->tdFrameLPCortical.rows;
		int nCols = vision->tdFrameLPCortical.cols;
		int nInputs = nRows * nCols;
		int nOutputs = 10;
		double* inputs = new double[nInputs];
		double* outputs = new double[nOutputs];

		drobot::DRobotPerceptron* xPerceptron = new drobot::DRobotPerceptron(nInputs, nOutputs);
		xPerceptron->initWeights(-0.005, 0.005);

		drobot::DRobotPerceptron* yPerceptron = new drobot::DRobotPerceptron(nInputs, nOutputs);
		yPerceptron->initWeights(-0.005, 0.005);

		std::cerr << "Neural perceptron created - #inputs: " << nInputs << "   #outputs: " << nOutputs << std::endl;

		double t = 0;
		double y[2];

		cv::Mat hsv;

		double REWARD_FACTOR = 1;
		double LEARNING_RATE = 0.01;
		int LEARNING_STEPS_INTERVAL = 5; 	// number of time steps after the movement execution that the system uses to learn;
		int cStep = 5; 				// current timestep
		int mStep = 0;				// movement step
		double cAct = 0; 			// current activity;
		double cAct2nd = 0; 			// current activity; 2nd derivative
		double pAct = 0; 			// previous activity;
 		double dAct = 0; 			// activity derivative
		double dActAcc = 0; 		// activity derivativce accumulator
		double reward;
		bool manualControl = true;

		std::cerr << "OLE " << std::endl;

		while(1)
		{
			vision->getFrame();
			vision->applyTransforms();

			manualControl = expSliders->getValue(0) > 0 ? true : false;

			cAct = vision->getTDPixelActivity(); // / (double) nInputs / 255.0;
			cAct2nd = vision->getTD2PixelActivity(); // / (double) nInputs / 255.0;
			dAct = cAct - pAct;
			pAct = cAct;
			dActAcc += dAct;

			if(cStep % 30 == 0)
			{
				std::cerr << "OLE 1" << std::endl;

				convertPixelsToDoubleArray(vision->tdFrameLPCortical.data, inputs, nInputs);

				outputs = xPerceptron->calculateOutput(inputs);
				double xIncrement = drobot::DRobotPopulationCoding::decodePopulationActivity1D(outputs, nOutputs, -20, 20);

				outputs = yPerceptron->calculateOutput(inputs);
				double yIncrement = drobot::DRobotPopulationCoding::decodePopulationActivity1D(outputs, nOutputs, -20, 20);

				std::cerr << "Calculated increment (" << cStep << "): " << xIncrement << ", " << yIncrement << std::endl;

				if(!manualControl)
				{
					actuation->setMotorIncrement(0, xIncrement);
					actuation->setMotorIncrement(1, yIncrement);
				}
				dActAcc = 0;
				mStep = cStep;
			}

//			if (cStep - mStep == LEARNING_STEPS_INTERVAL)
//			{
//				reward = REWARD_FACTOR * dActAcc;
//				xPerceptron->updateWeights(reward, LEARNING_RATE);
//				yPerceptron->updateWeights(reward, LEARNING_RATE);
//			}

			y[0] = cAct;
			y[1] = cAct2nd;
			plotter->update(cStep, y);

			display_color->imshow(vision->frameResized);
			display_thresh->imshow(vision->tdFrameLPCartesian);
			display_thresh_2nd->imshow(vision->td2FrameLPCartesian);

			if (manualControl)
			{
				std::cerr << " manual control is set to ON" << std::endl;
				for(int i=0; i<servoLabels.size(); i++)
				{
					double position = servoSliders->getValue(i);
					actuation->setMotorPosition(i, position);
					std::cerr << " manual control (" << i << "): " << position << std::endl;
				}
			}
//			actuation->displayMotorPositions();

			usleep(50000);

			cStep++;
		}
	}

	void init()
	{
		initServoMotors();

		vision = new drobot::DRobotVision();
		actuation = new drobot::DRobotActuation();

		for(int i=0; i<servoLabels.size(); i++)
		{
			actuation->addServoMotor(servoLabels[i],0,i,servoInits[i], servoMins[i], servoMaxs[i]);
		}

		servoSliders = new drobot::DRobotSliderGroup("Servos", servoLabels, servoInits, servoMins, servoMaxs);
		servoSliders->show();

		std::vector<std::string> labels;
		labels.push_back("Photoreceptor Activation");
		labels.push_back("Photoreceptor Activation, 2nd derivative");
		std::vector<QColor> colors;
		colors.push_back(QColor(240, 0, 10, 127));
		colors.push_back(QColor(10, 0, 240, 127));
		plotter = new drobot::DRobotTimePlotter("Plots", 20, 20, 500, 300, labels, colors);
		plotter->show();

		display_thresh = new drobot::DRobotImageDisplay();
		display_thresh->setWindowTitle("Threshold");
		display_thresh->show();

		display_thresh_2nd = new drobot::DRobotImageDisplay();
		display_thresh_2nd->setWindowTitle("2nd Order Derivative");
		display_thresh_2nd->show();

		display_color = new drobot::DRobotImageDisplay();
		display_color->setWindowTitle("Original Color Image");
		display_color->show();

		std::vector<std::string> expLabels;
		expLabels.push_back("Manual control");

		expSliders = new drobot::DRobotSliderGroup("Experiment control", expLabels, 1, 0, 1);
		expSliders->show();
	}

	void initServoMotors()
	{
		servoLabels.push_back("Left eye pan");
		servoLabels.push_back("Left eye tilt");
		servoLabels.push_back("Ball motion");

		servoInits.push_back(100);
		servoInits.push_back(98);
		servoInits.push_back(90);

		servoMins.push_back(80);
		servoMins.push_back(80);
		servoMins.push_back(40);

		servoMaxs.push_back(180);
		servoMaxs.push_back(120);
		servoMaxs.push_back(170);
	}

	void convertPixelsToDoubleArray(unsigned char* in, double* out, int size)
	{
		for (int i=0;i<size; i++)
			out[i] = ((int) in[i]) / 255.0;

	}

/*
	void
	initColorSliders()
	{
		std::vector<std::string> colorLabels;
		colorLabels.push_back("H min:");
		colorLabels.push_back("S min:");
		colorLabels.push_back("V min:");
		colorLabels.push_back("H max:");
		colorLabels.push_back("S max:");
		colorLabels.push_back("V max:");

		std::vector<double> colorInits;
		colorInits.push_back(87);
		colorInits.push_back(95);
		colorInits.push_back(113);
		colorInits.push_back(140);
		colorInits.push_back(179);
		colorInits.push_back(125);


		std::vector<double> colorMins;
		std::vector<double> colorMaxs;

		for(int i=0;i<colorLabels.size(); i++)
		{
			colorMins.push_back(0);
			colorMaxs.push_back(255);
		}

		colorBounds = new drobot::DRobotSliderGroup("Color Bounds", colorLabels, colorInits, colorMins, colorMaxs);
		colorBounds->show();

		std::cerr << " PASSED COLOR SLIDERS" << std::endl;
	}

	double
	countActivePixels(cv::Mat image, int x0, int y0, int x1, int y1)
	{

		unsigned char*pixels = (unsigned char*) image.data;

		double activity = 0;
		int index;
		for(int i=y0; i<y1; i++)
		{
			index = i * image.cols + x0;

			for(int j=x0; j<x1; j++)
			{
				activity += (int) pixels[index];
				index++;
			}
		}

		activity /= (double) (x1-x0) * (y1-y0);
		return activity;
	}
*/

public:

	drobot::DRobotVision* vision;
	drobot::DRobotActuation* actuation;
	drobot::DRobotTimePlotter* plotter;
	drobot::DRobotImageDisplay* display_thresh;
	drobot::DRobotImageDisplay* display_thresh_2nd;
	drobot::DRobotImageDisplay* display_color;
	drobot::DRobotSliderGroup* colorBounds;
	drobot::DRobotSliderGroup* servoSliders;
	drobot::DRobotSliderGroup* expSliders;

	std::vector<std::string> servoLabels;
	std::vector<double> servoMins;
	std::vector<double> servoMaxs;
	std::vector<double> servoInits;
};

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	VisuoMotorLearning* a = new VisuoMotorLearning();
	boost::thread* t = new boost::thread( boost::bind(&VisuoMotorLearning::run, a) );

	return application.exec();
}
