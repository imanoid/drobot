#ifndef _DROBOT_DROBOTSERVOMOTOR_H_
#define _DROBOT_DROBOTSERVOMOTOR_H_

#include <string>
#include <vector>

#include "phidget21.h"
#include "DRobotAbstractServoMotor.h"

namespace drobot {

class DRobotServoMotor: public DRobotAbstractServoMotor {

public:
	DRobotServoMotor(CPhidgetServoHandle servo);

	virtual double getMotorPosition();
	virtual void setMotorPosition(double position);
    virtual void engage();
    virtual void disengage();
    virtual bool isEngaged();
private:
	// Servo handle
	CPhidgetServoHandle servo;
};

}

#endif
