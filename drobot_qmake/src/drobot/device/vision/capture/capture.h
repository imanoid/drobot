
#ifndef _DROBOT_DEVICE_VISION_CAPTURE_CAPTURE_H_
#define _DROBOT_DEVICE_VISION_CAPTURE_CAPTURE_H_

#include <boost/thread.hpp>
#include "opencv2/opencv.hpp"

// #include "DRobotCaptureDevices.h"

namespace drobot {
namespace device {
namespace vision {
namespace capture {

class Capture
{

public:

    Capture();

    virtual ~Capture();

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

    cv::Mat _frame;

    boost::thread* _captureThread;

};

}
}
}
}

#endif
