#ifndef _DROBOT_DEVICE_VISION_H_
#define _DROBOT_DEVICE_VISION_H_

#include <string>
#include <list>

#include "opencv2/opencv.hpp"
#include "capture/capture.h"
#include "../device.h"

namespace drobot {
namespace device {
namespace vision {

class Vision : public Device {

private:

    capture::Capture* _capture;

    cv::LogPolar_Adjacent* _lp;
//	CvCapture* capture2;

public:

    Vision();

    virtual ~Vision();

    cv::Mat
    getFrame();

    void
    applyTransforms();

    double
    getTDPixelActivity();

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
}
}

#endif
