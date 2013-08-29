
#ifndef _DROBOT_DROBOTDC1394DEVICE_H_
#define _DROBOT_DROBOTDC1394DEVICE_H_

#include <boost/signals2/mutex.hpp>

#include "DRobotCapture.h"

namespace drobot
{

class DRobotDC1394Device : public DRobotCapture
{

public:
	static const int DEFAULT_WIDTH = 320;
	static const int DEFAULT_HEIGHT = 240;
	static const int DEFAULT_FPS = 30;

	DRobotDC1394Device();
	DRobotDC1394Device(int idx, int fps);

	virtual ~DRobotDC1394Device();

	void init();

	void execute();

	void terminate();

	virtual std::string getInfo();

private:
	void init(int idx, int width, int height, int fps);

	boost::mutex captureMutex;
	CvCapture *_capture;
  };

}

#endif
