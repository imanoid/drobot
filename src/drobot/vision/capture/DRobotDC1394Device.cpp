
#include <iostream>

#include "DRobotDC1394Device.h"

namespace drobot
{

DRobotDC1394Device::DRobotDC1394Device() : DRobotCapture()
{
	init(CV_CAP_FIREWIRE, DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_FPS); 
}

DRobotDC1394Device::DRobotDC1394Device(int idx, int fps) : DRobotCapture()
{
	init(idx, DEFAULT_WIDTH, DEFAULT_HEIGHT, fps > 0 ? fps : DEFAULT_FPS);
}

DRobotDC1394Device::~DRobotDC1394Device()
{

}

void DRobotDC1394Device::init()
{
	init(CV_CAP_FIREWIRE, DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_FPS);
}

void DRobotDC1394Device::init(int idx, int width, int height, int fps)
{
	_capture = cvCaptureFromCAM(idx);

	if (!_capture) {
		std::cerr << "[DRobotVision] Error: camera not found." << std::endl;
		return;
	} else {
		std::cerr << "[DRobotVision] Camera found." << std::endl;
	}

	cvSetCaptureProperty(_capture, CV_CAP_PROP_FRAME_WIDTH, width);		//opencv doesnt like 640x480
	cvSetCaptureProperty(_capture, CV_CAP_PROP_FRAME_HEIGHT, height);	//as most webcams use YUYV/YUY2 codecs.
	cvSetCaptureProperty(_capture, CV_CAP_PROP_FPS, fps);		//Playstation Eye Only: Max FPS goes to 120!!!
}

void
DRobotDC1394Device::execute()
{

//	IplImage* capimg;

	while(1) {

		IplImage* capimg = cvQueryFrame(_capture);

		// TODO: this has to be threaded and include a mutex
		captureMutex.lock();
		frame = cv::Mat(240, 320, CV_8UC3, capimg->imageData);
		captureMutex.unlock();

	//	delete capimg;

		usleep(1000);
	}


}



void
DRobotDC1394Device::terminate()
{

}


std::string
DRobotDC1394Device::getInfo()
{
	return "Device: dc1394";
}

}
