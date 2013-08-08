#ifndef _DROBOT_DROBOTABSTRACTACTUATION_H_
#define _DROBOT_DROBOTABSTRACTACTUATION_H_

#include <vector>
#include "DRobotAbstractServoMotor.h"

namespace drobot {

class DRobotAbstractActuation {
public:
	virtual ~DRobotAbstractActuation() {};
	virtual void engage() = 0;
	virtual void disengage() = 0;
	const std::vector<drobot::DRobotAbstractServoMotor*> getMotors() const;
	static drobot::DRobotAbstractActuation createActuation(int number);
private:
	virtual const int getMotorCount() = 0;
	std::vector<drobot::DRobotAbstractServoMotor*> _motors;
};

}

#endif
