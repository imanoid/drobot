#include <iostream>

#include <QApplication>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/filesystem.hpp>

#include "opencv2/opencv.hpp"

#include "built_in.h"

#include "DRobotActuation.h"
#include "DRobotVision.h"

#include "DRobotDataLogger/DRobotDataLogger.h"

#include "DRobotSliderGroup/DRobotSliderGroup.h"
#include "DRobotTimePlotter/DRobotTimePlotter.h"
#include "DRobotImageDisplay/DRobotImageDisplay.h"
#include "DRobotColorRangeSelector/DRobotColorRangeSelector.h"

#include "DRobotPerceptron/DRobotPerceptron.h"
#include "DRobotPopulationCoding/DRobotPopulationCoding.h"

using boost::shared_ptr;

typedef boost::iostreams::tee_device<std::ostream, std::ofstream> boost_tee_device_t;
typedef boost::iostreams::stream<boost_tee_device_t> boost_tee_stream_t;

class VisuoMotorLearning
{

public:
	/*
	 * Experiment parameters
	 */
	static const double LEARNING_RATE = 0.05;	// learning rate
	static const int WTA_LEARNING_NEIGH = 1; 	// # of neighbour neurons on each side for WTA-learning
	// min/max values for population coding
	static const int POPULATION_MIN_X = -20;	// motor pos. leftmost
	static const int POPULATION_MAX_X = 20;		// motor pos. rightmost
	static const int POPULATION_MIN_Y = -20;	// motor pos. upmost
	static const int POPULATION_MAX_Y = 20;		// motor pos. downmost

	/*
	 * Runtime cycle parameters
	 */
	static const unsigned int T = 50000;		// duration of 1 cycle
	static const int UPDATE_STEPS_INTERVAL = 20;	// # of cycles after which to update motor positions
	static const int LEARNING_STEPS_INTERVAL = 5; 	// # of cycles after the movement execution to wait before learning
	static const int RANDOM_MOVE_INTERVAL = 500;	// # of cycles after which a random move is performed

	VisuoMotorLearning()
	{
		init();
	}

	void setup()
	{
		actuation->setInitialPositions();

		/* Make sure we have both differentials (1st and 2nd) */
		processVision();
		usleep(10000);
		processVision();
		usleep(10000);
		processVision();

//		int nRows = vision->tdFrameLPCortical.rows;
//		int nCols = vision->tdFrameLPCortical.cols;
//		int nRows = vision->frameSegmented.rows;
//		int nCols = vision->frameSegmented.cols;
		nRows = vision->frameSegmented5x5.rows;
		nCols = vision->frameSegmented5x5.cols;

		nInputs = nRows * nCols;
		nOutputs = 10;
		inputs = new double[nInputs];
		xOutputs = new double[nOutputs];
		yOutputs = new double[nOutputs];

		xPerceptron = new drobot::DRobotPerceptron(
				drobot::DRobotPerceptron::LEARN_MCMILLEN,
				nInputs, nOutputs);
		// Original
//		xPerceptron->initWeights(-0.005, 0.005);
		// for McMillen
		xPerceptron->initWeights(0.0, 1.0);
		// for Oja
//		xPerceptron->initWeights(-0.25, 0.25);
		// for Hebbian Cov
//		xPerceptron->initWeights(0.0, 0.0005);

		yPerceptron = new drobot::DRobotPerceptron(
				drobot::DRobotPerceptron::LEARN_MCMILLEN,
				nInputs, nOutputs);
		yPerceptron->initWeights(0.0, 1.0);

		struct timeval ts;
		char str_ts[128];

		bug_on(gettimeofday(&ts, NULL));
		strftime(str_ts, sizeof(str_ts), "%Y-%m-%d-%H-%M-%S", localtime(&ts.tv_sec));

		inLogger = drobot::DRobotDataLoggerPtr(new drobot::DRobotDataLogger(str_ts, "in.log"));
		outXLogger = drobot::DRobotDataLoggerPtr(new drobot::DRobotDataLogger(str_ts, "out_x.log"));
		outYLogger = drobot::DRobotDataLoggerPtr(new drobot::DRobotDataLogger(str_ts, "out_y.log"));
		distLogger = drobot::DRobotDataLoggerPtr(new drobot::DRobotDataLogger(str_ts, "distance.log"));
		ddistLogger = drobot::DRobotDataLoggerPtr(new drobot::DRobotDataLogger(str_ts, "diff_distance.log"));
		rewardLogger = drobot::DRobotDataLoggerPtr(new drobot::DRobotDataLogger(str_ts, "reward.log"));

		for (int i = 0; i < nInputs; i++) {
			char name[32];

			snprintf(name, sizeof(name), "weights_x_in_%d.log", i);
			drobot::DRobotDataLoggerPtr p(new drobot::DRobotDataLogger(str_ts, name));
			weightXInLogger.push_back(p);

			snprintf(name, sizeof(name), "weights_y_in_%d.log", i);
			drobot::DRobotDataLoggerPtr q(new drobot::DRobotDataLogger(str_ts, name));
			weightYInLogger.push_back(q);
		}

		for (int i = 0; i < nOutputs; i++) {
			char name[32];

			snprintf(name, sizeof(name), "weights_x_out_%d.log", i);
			drobot::DRobotDataLoggerPtr p(new drobot::DRobotDataLogger(str_ts, name));
			weightXOutLogger.push_back(p);

			snprintf(name, sizeof(name), "weights_y_out_%d.log", i);
			drobot::DRobotDataLoggerPtr q(new drobot::DRobotDataLogger(str_ts, name));
			weightYOutLogger.push_back(q);
		}

		paramLogger = drobot::DRobotDataLoggerPtr(new drobot::DRobotDataLogger(str_ts, "params.log"));

		// write all output to the log file as well as to cout
		boost::filesystem::path p(str_ts);
		p /= "drobot.log";
		ofs = shared_ptr<std::ofstream>(new std::ofstream(p.c_str()));
		tee = shared_ptr<boost_tee_device_t>(new boost_tee_device_t(std::cout, *ofs));
		tout = shared_ptr<boost_tee_stream_t>(new boost_tee_stream_t(*tee));

		(*tout) << "VisuoMotorLearning experiment started at " << str_ts << std::endl;
	}

	void processVision()
	{
		vision->getFrame();

		double minH = colorBounds->getValue(0);
		double minS = colorBounds->getValue(1);
		double minV = colorBounds->getValue(2);
		double maxH = colorBounds->getValue(3);
		double maxS = colorBounds->getValue(4);
		double maxV = colorBounds->getValue(5);

		// H is allowed to wrap around -> min > max
		minS = std::min(minS, maxS);
		minV = std::min(minV, maxV);

		cv::Scalar minThresh(minH, minS, minV);
		cv::Scalar maxThresh(maxH, maxS, maxV);
		vision->applySegmentation(minThresh, maxThresh);

		vision->applyTransforms();
	}

	void run()
	{
		double t = 0;
		double y[2];

		cv::Mat hsv;
		cv::Point ball;
		cv::Point center(drobot::DRobotVision::FRAME_WIDTH / 2,
				 drobot::DRobotVision::FRAME_HEIGHT / 2);
		const double MAX_DIST_X = drobot::DRobotVision::FRAME_WIDTH / 2;
		const double MAX_DIST_Y = drobot::DRobotVision::FRAME_HEIGHT / 2;
		const double MAX_DIST_2D = sqrt(pow(drobot::DRobotVision::FRAME_WIDTH / 2, 2)
						+ pow(drobot::DRobotVision::FRAME_HEIGHT / 2, 2));

		int cStep = 0; 				// current timestep
		int mStep = 0;				// movement step
		double cAct = 0; 			// current activity;
		double cAct2nd = 0; 			// current activity; 2nd derivative
		double pAct = 0; 			// previous activity;
 		double dAct = 0; 			// activity derivative
		double dActAcc = 0;			// activity derivative accumulator
		double dx, dy;
		double x_before, y_before, x_after, y_after;
		bool manualControl = true, learning = false, enableRandom = true;;

		cv::Point dist, pdist;
		dist.x = pdist.x = MAX_DIST_X;
		dist.y = pdist.y = MAX_DIST_Y;
		double ndist, pndist;			// euclidean distance
		double maxOut = 0.0, absMaxOutY = 0.0;
		int iMaxOut = -1, iMaxOutY = -1;

		setup();

		struct timeval t_start, t_end, t_now;
		memset(&t_now, 0, sizeof(t_now));

		const char *param_names[] = {
			"nRowsIn", "inColsIn", "nOutputs",
			"popMinX", "popMaxX",
			"popMinY", "popMaxY",
			"learningRate", "wtaLearnNeigh",
			"T", "updStepsInterval", "learnStepsInterval",
			"randMoveInterval",
		};
		const int params[] = {
			nRows, nCols, nOutputs,
			POPULATION_MIN_X, POPULATION_MAX_X,
			POPULATION_MIN_Y, POPULATION_MAX_Y,
			LEARNING_RATE, WTA_LEARNING_NEIGH,
			T, UPDATE_STEPS_INTERVAL, LEARNING_STEPS_INTERVAL,
			RANDOM_MOVE_INTERVAL,
		};

		paramLogger->header(array_size(params), param_names);
		paramLogger->log(&t_now, array_size(params), params);

		bug_on(gettimeofday(&t_start, NULL));

		while(1) {
			processVision();

			manualControl = expSliders->getValue(0) > 0 ? true : false;
			learning = expSliders->getValue(1) > 0 ? true : false;
			enableRandom = expSliders->getValue(2) > 0 ? true : false;

			cAct = vision->getTDPixelActivity(); // / (double) nInputs / 255.0;
			cAct2nd = vision->getTD2PixelActivity(); // / (double) nInputs / 255.0;
			dAct = cAct - pAct;
			pAct = cAct;
			dActAcc += dAct;

			/* Random movement every RANDOM_MOVE_INTERVAL steps */
			if (enableRandom && cStep % RANDOM_MOVE_INTERVAL == 0) {
				double max_x = actuation->getMotorMax(0);
				double max_y = actuation->getMotorMax(1);
				double dx = (((double) rand() / RAND_MAX) * max_x) - (max_x / 2.0);
				double dy = (((double) rand() / RAND_MAX) * max_y) - (max_y / 2.0);

				(*tout) << "[" << cStep << "] performing random movement: "
					<< dx << "/" << dy << std::endl;
				x_before = actuation->getMotorPosition(0);
				actuation->setMotorIncrement(0, dx);
				y_before = actuation->getMotorPosition(1);
				actuation->setMotorIncrement(1, dy);

				// make sure we also learn from random movements
				mStep = cStep;
			} else if (cStep % UPDATE_STEPS_INTERVAL == 0) {
				/* Calculate outputs and update motor position */

				bug_on(gettimeofday(&t_now, NULL));
				timersub(&t_now, &t_start, &t_now);

				convertPixelsToDoubleArray(vision->frameSegmented5x5.data, inputs, nInputs);

//				xOutputs = xPerceptron->calculateOutputSigmoid(inputs, 0.3);
//				yOutputs = yPerceptron->calculateOutputSigmoid(inputs, 0.3);
				xOutputs = xPerceptron->calculateOutput(inputs);
				yOutputs = yPerceptron->calculateOutput(inputs);

				inLogger->log(&t_now, nInputs, inputs);
				outXLogger->log(&t_now, nOutputs, xOutputs);
				outYLogger->log(&t_now, nOutputs, yOutputs);

				for (int i = 0; i < nInputs; i++) {
					weightXInLogger[i]->log(&t_now, nOutputs, xPerceptron->getWeightsIn(i));
					weightYInLogger[i]->log(&t_now, nOutputs, yPerceptron->getWeightsIn(i));
				}

				for (int i = 0; i < nOutputs; i++) {
					weightXOutLogger[i]->log(&t_now, nInputs, xPerceptron->getWeightsOut(i));
					weightYOutLogger[i]->log(&t_now, nInputs, yPerceptron->getWeightsOut(i));
				}

				(*tout) << "[" << cStep << "] x out:";
				maxOut = 0.0;
				iMaxOut = -1;
				for (int i = 0; i < nOutputs; i++) {
					if (xOutputs[i] > maxOut) {
						maxOut = xOutputs[i];
						iMaxOut = i;
					}
					(*tout) << " " << xOutputs[i];
				}
				(*tout) << std::endl;
				(*tout) << "[" << cStep << "] max x out: " << maxOut << " (" << iMaxOut << ")" << std::endl;

				(*tout) << "[" << cStep << "] y out:";
				maxOut = 0.0;
				iMaxOut = -1;
				for (int i = 0; i < nOutputs; i++) {
					if (yOutputs[i] > maxOut) {
						maxOut = yOutputs[i];
						iMaxOut = i;
					}
					(*tout) << " " << yOutputs[i];
				}
				(*tout) << std::endl;
				(*tout) << "[" << cStep << "] max y out: " << maxOut << " (" << iMaxOut << ")" << std::endl;

				dx = drobot::DRobotPopulationCoding::decodePopulationActivity1D(xOutputs, nOutputs, POPULATION_MIN_X, POPULATION_MAX_X);
				dy = drobot::DRobotPopulationCoding::decodePopulationActivity1D(yOutputs, nOutputs, POPULATION_MIN_Y, POPULATION_MAX_Y);

				(*tout) << "[" << cStep << "] Calculated increment: " << dx << ", " << dy << std::endl;

				if (!manualControl) {
					x_before = actuation->getMotorPosition(0);
					actuation->setMotorIncrement(0, dx);
					y_before = actuation->getMotorPosition(1);
					actuation->setMotorIncrement(1, dy);
				}

				dActAcc = 0;
				mStep = cStep;
			}

			/* Learn */
			if (learning && cStep - mStep == LEARNING_STEPS_INTERVAL) {
				struct timeval t_now;

				bug_on(gettimeofday(&t_now, NULL));
				timersub(&t_now, &t_start, &t_now);

				ball = vision->getLastBallCenter();
				pdist = dist;
				pndist = cv::norm(pdist);
				dist = center - ball;
				ndist = cv::norm(dist);
				distLogger->log(&t_now, 2, dist.x, dist.y);
				ddistLogger->log(&t_now, 2, pdist.x - dist.x, pdist.y - dist.y);

				y[0] = dist.x;
				y[1] = dist.y;
				dist_plotter->update(cStep, y);

				x_after = actuation->getMotorPosition(0);
				y_after = actuation->getMotorPosition(1);

				double reward;

				if (ndist < 4.0
					|| (std::abs(x_after - x_before) > 0.0
						&& (pndist - ndist) > 0.0))
					reward = 1.0;
				else
					reward = -1.0;

				rewardLogger->log(&t_now, 2, reward, reward);

				(*tout) << "[" << cStep << "] learning: "
						<< "dist=" << dist
						<< ", pdist=" << pdist
						<< ", ddist=" << pdist - dist
						<< ", ndist=" << ndist
						<< ", pndist=" << pndist
						<< ", dndist=" << pndist - ndist
						<< ", reward=" << reward
						<< ", dActAcc=" << dActAcc
						<< std::endl;

				xPerceptron->updateWeightsWTA(reward, LEARNING_RATE, WTA_LEARNING_NEIGH);
				yPerceptron->updateWeightsWTA(reward, LEARNING_RATE, WTA_LEARNING_NEIGH);
			}

			y[0] = cAct;
			y[1] = cAct2nd;
			plotter->update(cStep, y);

			// calculate FPS
			bug_on(gettimeofday(&t_end, NULL));
			cStep++;

			struct timeval t_diff;
			timersub(&t_end, &t_start, &t_diff);
			double fps = cStep / ((double) t_diff.tv_sec);
			char buf[32];
			snprintf(buf, sizeof(buf), "FPS: %.2lf", fps);

			putText(vision->frameResized, buf, cvPoint(20, 20),
					cv::FONT_HERSHEY_COMPLEX_SMALL, 0.8,
					cvScalar(0, 0, 0), 1, CV_AA);

			display_color->imshow(vision->frameResized);
			display_thresh->imshow(vision->tdFrameLPCartesian);
//			display_thresh_2nd->imshow(vision->td2FrameLPCartesian);
			display_filter->imshow(vision->frameFiltered);
			cv::Mat scaled;
			cv::resize(vision->frameSegmented5x5, scaled, cv::Size(100, 100), 0, 0, cv::INTER_NEAREST);
			display_seg->imshow(scaled);

			if (manualControl) {
				for (int i = 0; i < servoLabels.size(); i++) {
					double position = servoSliders->getValue(i);
					actuation->setMotorPosition(i, position);
				}
			}

			tout->flush();
			usleep(T);
		}
	}

	void init()
	{
		srand((unsigned int) time(0));

		initServoMotors();

		vision = new drobot::DRobotVision();
		actuation = new drobot::DRobotActuation();

		for (int i = 0; i < servoLabels.size(); i++) {
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
		plotter = new drobot::DRobotTimePlotter("Activity", 20, 20, 500, 300, labels, colors);
		plotter->show();

		labels.clear();
		labels.push_back("x ball-center");
		labels.push_back("y ball-center");
		colors.clear();
		colors.push_back(QColor(0, 240, 50, 127));
		colors.push_back(QColor(180, 200, 25, 127));
		dist_plotter = new drobot::DRobotTimePlotter("Distance", 20, 20, 500, 300, labels, colors);
		dist_plotter->show();

		display_thresh = new drobot::DRobotImageDisplay();
		display_thresh->setWindowTitle("Threshold");
		display_thresh->show();

		/*
		display_thresh_2nd = new drobot::DRobotImageDisplay();
		display_thresh_2nd->setWindowTitle("2nd Order Derivative");
		display_thresh_2nd->show();
		*/

		display_color = new drobot::DRobotImageDisplay();
		display_color->setWindowTitle("Original Color Image");
		display_color->show();

		display_filter = new drobot::DRobotImageDisplay();
		display_filter->setWindowTitle("Filtered Image");
		display_filter->show();

		display_seg = new drobot::DRobotImageDisplay();
		display_seg->setWindowTitle("Segmented Image");
		display_seg->show();

		std::vector<std::string> expLabels;
		expLabels.push_back("Manual control");
		expLabels.push_back("Learning");
		expLabels.push_back("Random movement");

		std::vector<double> inits, mins, maxs;
		inits.push_back(1);
		inits.push_back(0);
		inits.push_back(1);
		mins.push_back(0);
		mins.push_back(0);
		mins.push_back(0);
		maxs.push_back(1);
		maxs.push_back(1);
		maxs.push_back(1);

		expSliders = new drobot::DRobotSliderGroup("Experiment control", expLabels, inits, mins, maxs);
		expSliders->show();

		initColorSliders();
	}

	void initServoMotors()
	{
		servoLabels.push_back("Left eye pan");
		servoLabels.push_back("Left eye tilt");
		servoLabels.push_back("Ball motion");

		servoInits.push_back(82);
		servoInits.push_back(101);
		servoInits.push_back(90);

		servoMins.push_back(74);
		servoMins.push_back(87);
		servoMins.push_back(40);

		servoMaxs.push_back(112);
		servoMaxs.push_back(114);
		servoMaxs.push_back(170);
	}

	void convertPixelsToDoubleArray(unsigned char* in, double* out, int size)
	{
		for (int i=0;i<size; i++)
			out[i] = ((int) in[i]) / 255.0;

	}

	void initColorSliders()
	{
		std::vector<std::string> colorLabels;
		colorLabels.push_back("H min:");
		colorLabels.push_back("S min:");
		colorLabels.push_back("V min:");
		colorLabels.push_back("H max:");
		colorLabels.push_back("S max:");
		colorLabels.push_back("V max:");

		std::vector<double> colorInits;
		colorInits.push_back(160.0);
		colorInits.push_back(74.0);
		colorInits.push_back(214.5);
		colorInits.push_back(180.0);
		colorInits.push_back(84.0);
		colorInits.push_back(224.5);

		std::vector<double> colorMins;
		std::vector<double> colorMaxs;

		for (int i = 0; i < colorLabels.size(); i++) {
			if (i == 0 || i == 3) {
				// H is in range 0-180
				colorMins.push_back(0);
				colorMaxs.push_back(180);
			} else {
				colorMins.push_back(0);
				colorMaxs.push_back(255);
			}
		}

		colorBounds = new drobot::DRobotSliderGroup("Color Bounds", colorLabels, colorInits, colorMins, colorMaxs);
		colorBounds->show();
	}

public:
	drobot::DRobotVision *vision;
	drobot::DRobotActuation *actuation;
	drobot::DRobotTimePlotter *plotter;
	drobot::DRobotTimePlotter *dist_plotter;
	drobot::DRobotImageDisplay *display_thresh;
	drobot::DRobotImageDisplay *display_thresh_2nd;
	drobot::DRobotImageDisplay *display_color;
	drobot::DRobotImageDisplay *display_filter;
	drobot::DRobotImageDisplay *display_seg;
	drobot::DRobotSliderGroup *colorBounds;
	drobot::DRobotSliderGroup *servoSliders;
	drobot::DRobotSliderGroup *expSliders;

	std::vector<std::string> servoLabels;
	std::vector<double> servoMins;
	std::vector<double> servoMaxs;
	std::vector<double> servoInits;

private:
	int nRows, nCols;
	int nInputs, nOutputs;
	double *inputs, *xOutputs, *yOutputs;

	drobot::DRobotPerceptron *xPerceptron, *yPerceptron;

	drobot::DRobotDataLoggerPtr paramLogger;
	drobot::DRobotDataLoggerPtr inLogger;
	drobot::DRobotDataLoggerPtr outXLogger, outYLogger;
	drobot::DRobotDataLoggerPtr distLogger, ddistLogger;
	drobot::DRobotDataLoggerPtr rewardLogger;
	std::vector<shared_ptr<drobot::DRobotDataLogger> > weightXInLogger, weightYInLogger;
	std::vector<shared_ptr<drobot::DRobotDataLogger> > weightXOutLogger, weightYOutLogger;

	shared_ptr<std::ofstream> ofs;
	shared_ptr<boost_tee_device_t> tee;
	shared_ptr<boost_tee_stream_t> tout;
};

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	VisuoMotorLearning* a = new VisuoMotorLearning();
	boost::thread* t = new boost::thread( boost::bind(&VisuoMotorLearning::run, a) );

	return application.exec();
}
