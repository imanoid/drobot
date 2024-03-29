#include <iostream>

#include <sys/resource.h>

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

using drobot::DRobotPerceptron;

enum {
	OUTPUT_LINEAR = 0,
	OUTPUT_SIGMOID = 1,
};

class VisuoMotorLearning
{

public:
	/*
	 * Experiment parameters
	 */
	static const bool RUN_FOREVER = false;		// whether to run the experiment forever (until Ctrl-C)
	static const int MAX_STEPS = 25000;		// if not running forever: number of steps to perform the experiment
	static const int N_INPUT_ROWS = 25;		// number of rows in the input
	static const int N_INPUT_COLS = 25;		// number of columns in the input
	static const int N_OUTPUTS = 10;		// number of output neurons per perceptron
	// Original: -0.005, 0.005
	// McMillen: 0.0, 1.0
	// Oja: -0.25, 0.25
	static const double WEIGHT_MIN = 0.0;		// minimum weight for initialization
	static const double WEIGHT_MAX = 1.0;		// maximum weight for initialization
	static const int OUTPUT_FN = OUTPUT_LINEAR;	// sigmoid or linear output
	static const double SIGMOID_BETA = 0.3;		// beta value for sigmoid function
	static const DRobotPerceptron::learn_rule_t LEARNING_RULE = DRobotPerceptron::LEARN_MCMILLEN;
	static const double LEARNING_RATE = 0.15;	// learning rate
	static const int WTA_LEARNING_NEIGH = 1; 	// # of neighbour neurons on each side for WTA-learning
	static const double REWARD_MIN = -1.0;		// negative reward
	static const double REWARD_MAX = 1.0;		// positive reward
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
	static const int LEARNING_STEPS_INTERVAL = 10; 	// # of cycles after the movement execution to wait before learning
	static const int RANDOM_MOVE_INTERVAL = 250;	// # of cycles after which a random move is performed

	VisuoMotorLearning()
	{
		init();
	}

	void setup()
	{
		struct rlimit rlim;
		getrlimit(RLIMIT_NOFILE, &rlim);
		std::cout << "cur: " << rlim.rlim_cur << "/max: " << rlim.rlim_max << std::endl;

		rlim.rlim_cur = rlim.rlim_max = 16384;

		setrlimit(RLIMIT_NOFILE, &rlim);
		getrlimit(RLIMIT_NOFILE, &rlim);
		std::cout << "cur: " << rlim.rlim_cur << "/max: " << rlim.rlim_max << std::endl;

		actuation->setInitialPositions();

		/* Make sure we have both differentials (1st and 2nd) */
		processVision();
		usleep(10000);
		processVision();
		usleep(10000);
		processVision();

		nRows = N_INPUT_ROWS;
		nCols = N_INPUT_COLS;
		nInputs = nRows * nCols;
		nOutputs = N_OUTPUTS;
		inputs = new double[nInputs];
		xOutputs = new double[nOutputs];
		yOutputs = new double[nOutputs];

		xPerceptron = new drobot::DRobotPerceptron(
				LEARNING_RULE,
				nInputs, nOutputs);
		xPerceptron->initWeights(WEIGHT_MIN, WEIGHT_MAX);

		yPerceptron = new drobot::DRobotPerceptron(
				LEARNING_RULE,
				nInputs, nOutputs);
		yPerceptron->initWeights(WEIGHT_MIN, WEIGHT_MAX);

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
		vision->applySegmentation(minThresh, maxThresh, N_INPUT_ROWS, N_INPUT_COLS);

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
		double maxOut = 0.0, absMaxOutY = 0.0;
		int iMaxOut = -1, iMaxOutY = -1;

		setup();

		struct timeval t_start, t_end, t_now;
		memset(&t_now, 0, sizeof(t_now));

		const char *param_names[] = {
			"nRowsIn", "nColsIn", "nOutputs",
			"popMinX", "popMaxX",
			"popMinY", "popMaxY",
			"weightMin", "weightMax", "outputFn", "sigmoidBeta",
			"learningRule", "learningRate", "wtaLearningNeigh",
			"rewardMin", "rewardMax",
			"T", "updateStepsInterval", "learningStepsInterval",
			"randomMoveInterval",
		};
		const double params[] = {
			nRows, nCols, N_OUTPUTS,
			POPULATION_MIN_X, POPULATION_MAX_X,
			POPULATION_MIN_Y, POPULATION_MAX_Y,
			WEIGHT_MIN, WEIGHT_MAX, OUTPUT_FN, SIGMOID_BETA,
			LEARNING_RULE, LEARNING_RATE, WTA_LEARNING_NEIGH,
			REWARD_MIN, REWARD_MAX,
			T, UPDATE_STEPS_INTERVAL, LEARNING_STEPS_INTERVAL,
			RANDOM_MOVE_INTERVAL,
		};

		build_bug_on(array_size(param_names) != array_size(params));

		paramLogger->header(array_size(params), param_names);
		paramLogger->log(&t_now, array_size(params), params);

		bug_on(gettimeofday(&t_start, NULL));

		(*tout) << "Running experiment ";
		if (RUN_FOREVER)
			(*tout) << "forever" << std::endl;
		else
			(*tout) << " for " << MAX_STEPS << " steps" << std::endl;

		while (RUN_FOREVER || cStep <= MAX_STEPS) {
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
			if (!manualControl && enableRandom && cStep % RANDOM_MOVE_INTERVAL == 0) {
				double max_x = actuation->getMotorMax(0);
				double max_y = actuation->getMotorMax(1);
				double min_x = actuation->getMotorMin(0);
				double min_y = actuation->getMotorMin(1);
				double px = (((double) rand() / RAND_MAX) * (max_x - min_x)) + min_x;
				double py = (((double) rand() / RAND_MAX) * (max_y - min_y)) + min_y;

				x_before = actuation->getMotorPosition(0);
				y_before = actuation->getMotorPosition(1);

				(*tout) << "[" << cStep << "] performing random movement to: "
					<< px << "/" << py << std::endl;
				actuation->setMotorPosition(0, px);
				actuation->setMotorPosition(1, py);

				// make sure we also learn from random movements
				mStep = cStep;
			} else if (cStep % UPDATE_STEPS_INTERVAL == 0) {
				/* Calculate outputs and update motor position */

				bug_on(gettimeofday(&t_now, NULL));
				timersub(&t_now, &t_start, &t_now);

				convertPixelsToDoubleArray(vision->frameSegmentedX.data, inputs, nInputs);

				if (OUTPUT_FN == OUTPUT_SIGMOID && SIGMOID_BETA > 0.0) {
					/* sigmoid output */
					xOutputs = xPerceptron->calculateOutputSigmoid(inputs, SIGMOID_BETA);
					yOutputs = yPerceptron->calculateOutputSigmoid(inputs, SIGMOID_BETA);
				} else {
					/* linear output */
					xOutputs = xPerceptron->calculateOutput(inputs);
					yOutputs = yPerceptron->calculateOutput(inputs);
				}

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
				dist = center - ball;
				distLogger->log(&t_now, 2, dist.x, dist.y);
				ddistLogger->log(&t_now, 2, pdist.x - dist.x, pdist.y - dist.y);

				y[0] = dist.x;
				y[1] = dist.y;
				dist_plotter->update(cStep, y);

				x_after = actuation->getMotorPosition(0);
				y_after = actuation->getMotorPosition(1);

				double reward_x, reward_y;
				double b_dx = std::abs(dist.x);
				double b_dy = std::abs(dist.y);
				double b_pdx = std::abs(pdist.x);
				double b_pdy = std::abs(pdist.y);

				if (b_dx < 4.0
					|| ((x_after != x_before)
						&& (b_dx < b_pdx)))
					reward_x = REWARD_MAX;
				else
					reward_x = REWARD_MIN;

				if (b_dy < 4.0
					|| ((y_after != y_before)
						&& (b_dy < b_pdy)))
					reward_y = REWARD_MAX;
				else
					reward_y = REWARD_MIN;

				rewardLogger->log(&t_now, 2, reward_x, reward_y);

				(*tout) << "[" << cStep << "] learning: "
						<< "dist=" << dist
						<< ", pdist=" << pdist
						<< ", ddist=" << pdist - dist
						<< ", reward=" << reward_x << "/" << reward_y
						<< std::endl;

				xPerceptron->updateWeightsWTA(reward_x, LEARNING_RATE, WTA_LEARNING_NEIGH);
				yPerceptron->updateWeightsWTA(reward_y, LEARNING_RATE, WTA_LEARNING_NEIGH);
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
			cv::resize(vision->frameSegmentedX, scaled, cv::Size(200, 200), 0, 0, cv::INTER_NEAREST);
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

		(*tout) << "Experiment successfully finished" << std::endl;
	}

	void init()
	{
		srand((unsigned int) time(0));

		initServoMotors();

		vision = new drobot::DRobotVision();
		actuation = new drobot::DRobotActuation();

		for (int i = 0; i < servoLabels.size(); i++) {
			actuation->addServoMotor(servoLabels[i], 0, servoIdx[i], servoInits[i], servoMins[i], servoMaxs[i]);
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

		servoIdx.push_back(3);
		servoIdx.push_back(2);
		servoIdx.push_back(1);

		servoInits.push_back(82);
		servoInits.push_back(101);
		servoInits.push_back(90);

		servoMins.push_back(74);
		servoMins.push_back(85);
		servoMins.push_back(40);

		servoMaxs.push_back(114);
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
	std::vector<int> servoIdx;

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
