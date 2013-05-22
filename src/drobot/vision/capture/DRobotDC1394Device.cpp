
#include <iostream>

#include "DRobotDC1394Device.h"

namespace drobot
{

DRobotDC1394Device::DRobotDC1394Device( ) : DRobotCapture()
{

	capture = cvCaptureFromCAM(CV_CAP_FIREWARE);

	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH, 320);	//opencv doesnt like 640x480
	cvSetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT, 240);	//as most webcams use YUYV/YUY2 codecs.
	cvSetCaptureProperty(capture, CV_CAP_PROP_FPS, 30 );			//Playstation Eye Only: Max FPS goes to 120!!!

	if(!capture){
		std::cerr << "[DRobotVision] Error: camera not found." << std::endl;
		return;
	}else{
		std::cerr << "[DRobotVision] Camera found." << std::endl;
	}

}

DRobotDC1394Device::~DRobotDC1394Device()
{

}

//void
//DRobotDC1394Device::start()
//{
//}



void
DRobotDC1394Device::init()
{

}

void
DRobotDC1394Device::execute()
{

//	IplImage* capimg;

	while(1)
	{

		IplImage* capimg = cvQueryFrame(capture);

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
