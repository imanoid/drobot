#ifndef _DROBOT_DROBOTADVANCEDACTUATION_H_
#define _DROBOT_DROBOTADVANCEDACTUATION_H_

#include <string>
#include <vector>

#include "DRobotAbstractActuation.h"
#include "DRobotAdvancedServoMotor.h"
#include "phidget21.h"

namespace drobot {

class DRobotAdvancedActuation: public DRobotAbstractActuation {

public:
	DRobotAdvancedActuation();

	virtual void addServoMotor(std::string name, int board, int index,
			double iPosition, double min, double max);
private:
	void initCommunication();
	virtual int displayProperties();
	// Servo handle
	CPhidgetAdvancedServoHandle servo;

};

}

#endif
