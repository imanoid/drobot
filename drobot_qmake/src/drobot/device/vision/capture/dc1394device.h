#ifndef _DROBOT_DEVICE_VISION_CAPTURE_DC1394DEVICE_H_
#define _DROBOT_DEVICE_VISION_CAPTURE_DC1394DEVICE_H_

#include <boost/signals2/mutex.hpp>

#include "capture.h"

namespace drobot {
namespace device {
namespace vision {
namespace capture {

  class DC1394Device : public Capture
  {

  public:

    DC1394Device( );

    virtual ~DC1394Device();

 //   void
 //  start();

 //   void
 //   stop();


    void
    init();

    void
    execute();

    void
    terminate();


    virtual std::string
    getInfo();

//	cv::Mat
//	getFrame();


  private:

    boost::mutex _captureMutex;

    CvCapture* _capture;
  };



}
}
}
}

#endif
