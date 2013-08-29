
#ifndef _DROBOT_DROBOTCAPTURE_H_
#define _DROBOT_DROBOTCAPTURE_H_

#include <boost/thread.hpp>
#include "opencv2/opencv.hpp"

// #include "DRobotCaptureDevices.h"

namespace drobot {

class DRobotCapture
{

public:

	DRobotCapture();

	virtual ~DRobotCapture();

	void
	start();

	void
	stop();

	virtual cv::Mat
	getFrame();

	virtual void
	execute() = 0;

	virtual void
	init() = 0;

	virtual void
	terminate() = 0;



protected:

	cv::Mat frame;

	boost::thread* captureThread;

};

}

#endif
