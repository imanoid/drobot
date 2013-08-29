#include "DRobotCapture.h"


namespace drobot
{

DRobotCapture::DRobotCapture() : frame()
{

}


DRobotCapture::~DRobotCapture()
{

}

void
DRobotCapture::start()
{
	init();
	captureThread = new boost::thread( boost::bind(&DRobotCapture::execute, this) );
}


void
DRobotCapture::stop()
{
	captureThread->interrupt();
	terminate();
}


cv::Mat
DRobotCapture::getFrame()
{

	return frame;
}


}
