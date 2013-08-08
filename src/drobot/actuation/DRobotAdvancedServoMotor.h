#ifndef _DROBOT_DROBOTADVANCEDSERVOMOTOR_H_
#define _DROBOT_DROBOTADVANCEDSERVOMOTOR_H_

#include <string>
#include <vector>

#include "phidget21.h"
#include "DRobotAbstractServoMotor.h"

namespace drobot {

class DRobotAdvancedServoMotor: public DRobotAbstractServoMotor {

public:
	DRobotAdvancedServoMotor(CPhidgetAdvancedServoHandle servo);

	virtual double getMotorPosition();
	virtual void setMotorPosition(double position);
    virtual void engage();
    virtual void disengage();
    virtual bool isEngaged();

private:
	CPhidgetAdvancedServoHandle servo;
};

}

#endif
