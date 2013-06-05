#ifndef _DROBOT_DROBOTVISION_H_
#define _DROBOT_DROBOTVISION_H_

#include <string>
#include <list>

#include "opencv2/opencv.hpp"
#include "capture/DRobotCapture.h"

namespace drobot {

class DRobotVision {

public:

	DRobotVision();

	virtual ~DRobotVision();

	cv::Mat
	getFrame();

	void
	applyTransforms();

	double
	getTDPixelActivity();

private:

	DRobotCapture* capture;

	cv::LogPolar_Adjacent* lp;
//	CvCapture* capture2;

public:

	static const int FRAME_WIDTH = 240;

	static const int FRAME_HEIGHT = 180;

	cv::Mat frame; 				// current frame

	cv::Mat frameResized;		// current frame resized

	cv::Mat frameGray; 			// current frame in grey scale

	cv::Mat frameLPCortical; // current log-polar frame in cortical coordinates

	cv::Mat pFrameLPCortical;	// previous log-polar frame

	cv::Mat tdFrameLPCortical; // temporal-difference log-polar frame in cartesian coordinates

	cv::Mat frameLPCartesian; // current log-polar frame in cartesian coordinates

	cv::Mat pFrameLPCartesian;	// previous log-polar frame

	cv::Mat tdFrameLPCartesian; // temporal-difference log-polar frame in cartesian coordinates

};

}

#endif
