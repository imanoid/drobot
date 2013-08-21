#ifndef _DROBOT_DROBOTVISION_H_
#define _DROBOT_DROBOTVISION_H_

#include <string>
#include <list>

#include "opencv2/opencv.hpp"
#include "capture/DRobotCapture.h"

namespace drobot {

class DRobotVision {

private:
	void init();

	double getTDPixelActivity(cv::Mat tdFrame);

public:

	DRobotVision();
	DRobotVision(int idx, int fps);

	virtual ~DRobotVision();

	cv::Mat getFrame();

	void applyTransforms();
	void applySegmentation(cv::Scalar minThresh, cv::Scalar maxThresh, int nRows, int nCols);

	double getTDPixelActivity();
	double getTD2PixelActivity();

	cv::Point getLastBallCenter();

private:

	DRobotCapture* capture;

	cv::LogPolar_Adjacent* lp;

	cv::Mat frameTmp;		// temporary storage

	cv::Point lastCenter;
	int lastRadius;

public:

	static const int FRAME_WIDTH = 240;
	static const int FRAME_HEIGHT = 180;

	cv::Mat frame;			// current frame
	cv::Mat frameResized;		// current frame resized
	cv::Mat frameGray;		// current frame in grey scale

	cv::Mat frameHsv;		// current frame in HSV color space
	cv::Mat frameFiltered;		// current frame filtered
	cv::Mat frameSegmented;		// current frame segmented
	cv::Mat frameSegmentedX;	// current frame segmented into NxM pixels

	cv::Mat frameLPCortical;	// current log-polar frame in cortical coordinates
	cv::Mat pFrameLPCortical;	// previous log-polar frame
	cv::Mat ppFrameLPCortical;	// pre-previous log-polar frame
	cv::Mat tdFrameLPCortical;	// temporal-difference log-polar frame in cartesian coordinates
	cv::Mat td2FrameLPCortical;	// 2nd order temporal-difference log-polar frame in cartesian coordinates
	cv::Mat frameSegLPCortical;
	cv::Mat pFrameSegLPCortical;
	cv::Mat tdFrameSegLPCortical;

	cv::Mat frameLPCartesian;	// current log-polar frame in cartesian coordinates
	cv::Mat pFrameLPCartesian;	// previous log-polar frame
	cv::Mat ppFrameLPCartesian;	// pre-previous log-polar frame
	cv::Mat tdFrameLPCartesian;	// temporal-difference log-polar frame in cartesian coordinates
	cv::Mat frameSegLPCartesian;
	cv::Mat td2FrameLPCartesian;	// 2nd order temporal-difference log-polar frame in cartesian coordinates
	cv::Mat pFrameSegLPCartesian;
	cv::Mat tdFrameSegLPCartesian;
};

}

#endif /* _DROBOT_DROBOTVISION_H_ */
