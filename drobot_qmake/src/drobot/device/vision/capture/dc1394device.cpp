
#include <iostream>

#include "dc1394device.h"

namespace drobot {
namespace device {
namespace vision {
namespace capture {

DC1394Device::DC1394Device( ) : Capture()
{

    _capture = cvCaptureFromCAM(CV_CAP_FIREWARE);

    cvSetCaptureProperty(_capture, CV_CAP_PROP_FRAME_WIDTH, 320);	//opencv doesnt like 640x480
    cvSetCaptureProperty(_capture, CV_CAP_PROP_FRAME_HEIGHT, 240);	//as most webcams use YUYV/YUY2 codecs.
    cvSetCaptureProperty(_capture, CV_CAP_PROP_FPS, 30 );			//Playstation Eye Only: Max FPS goes to 120!!!

    if(!_capture){
        std::cerr << "[DRobotVision] Error: camera not found." << std::endl;
        return;
    }else{
        std::cerr << "[DRobotVision] Camera found." << std::endl;
    }

}

DC1394Device::~DC1394Device()
{

}

//void
//DRobotDC1394Device::start()
//{
//}



void
DC1394Device::init()
{

}

void
DC1394Device::execute()
{

//	IplImage* capimg;

    while(1)
    {

        IplImage* capimg = cvQueryFrame(_capture);

        // TODO: this has to be threaded and include a mutex
        _captureMutex.lock();
        _frame = cv::Mat(240, 320, CV_8UC3, capimg->imageData);
        _captureMutex.unlock();

    //	delete capimg;

        usleep(1000);
    }


}



void
DC1394Device::terminate()
{

}


std::string
DC1394Device::getInfo()
{
    return "Device: dc1394";
}

}
}
}
}
