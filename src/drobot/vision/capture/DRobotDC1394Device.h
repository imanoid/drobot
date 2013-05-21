
#ifndef _DROBOT_DROBOTDC1394DEVICE_H_
#define _DROBOT_DROBOTDC1394DEVICE_H_

#include <boost/signals2/mutex.hpp>

#include "DRobotCapture.h"

namespace drobot
{

  class DRobotDC1394Device : public DRobotCapture
  {

  public:

	DRobotDC1394Device( );

    virtual ~DRobotDC1394Device();

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

    boost::mutex captureMutex;

	CvCapture* capture;
  };



}

#endif
