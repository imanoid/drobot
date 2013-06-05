#ifndef _DROBOT_DROBOTACTUATION_H_
#define _DROBOT_DROBOTACTUATION_H_

#include <string>
#include <vector>

#include "DRobotAbstractActuation.h"
#include "DRobotServoMotor.h"
#include "phidget21.h"

namespace drobot {

class DRobotActuation: public DRobotAbstractActuation {

public:
	DRobotActuation();

	virtual void addServoMotor(std::string name, int board, int index,
			double iPosition, double min, double max);
private:
	void initCommunication();
	virtual int displayProperties();
	// Servo handle
	CPhidgetServoHandle servo;

};

}

#endif
