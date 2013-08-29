#ifndef _DROBOT_DROBOTADVANCEDSERVOMOTOR_H_
#define _DROBOT_DROBOTADVANCEDSERVOMOTOR_H_

#include "phidget21.h"
#include "DRobotAdvancedServoMotor.h"

namespace drobot {

class DRobotAdvancedServoMotor {
public:
	DRobotAdvancedServoMotor(CPhidgetAdvancedServoHandle phidgetHandle, int index);
	virtual ~DRobotAdvancedServoMotor() {};

	virtual void engage();
	virtual void disengage();

	virtual double getPosition();
	virtual void setPosition(double position);
	virtual double getPositionMin();
	virtual void setPositionMin(double positionMin);
	virtual double getPositionMax();
	virtual void setPositionMax(double positionMax);

	virtual double getAcceleration();
	virtual void setAcceleration(double acceleration);
	virtual double getAccelerationMin();
	virtual double getAccelerationMax();

	virtual double getVelocity();
	virtual void setVelocity(double velocity);
	virtual double getVelocityMin();
	virtual double getVelocityMax();
	virtual double getVelocityLimit();
	virtual void setVelocityLimit(double velocityLimit);

	virtual bool isMoving();

	virtual bool isSpeedRamping();
	virtual void setSpeedRamping(bool speedRamping);

	virtual double getCurrent();
private:
	CPhidgetAdvancedServoHandle _phidgetHandle;
	int index;
};

}

#endif
