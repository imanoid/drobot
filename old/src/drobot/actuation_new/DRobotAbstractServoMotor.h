#ifndef _DROBOT_DROBOTABSTRACTSERVOMOTOR_H_
#define _DROBOT_DROBOTABSTRACTSERVOMOTOR_H_

namespace drobot {

class DRobotAbstractServoMotor {
public:
	virtual ~DRobotAbstractServoMotor() {};

	virtual void engage() = 0;
	virtual void disengage() = 0;

	void rotate(double angle);

	virtual double getPosition() = 0;
	virtual void setPosition(double position) = 0;
	virtual double getPositionMin() = 0;
	virtual void setPositionMin(double positionMin) = 0;
	virtual double getPositionMax() = 0;
	virtual void setPositionMax(double positionMax) = 0;

	virtual double getAcceleration() = 0;
	virtual void setAcceleration(double acceleration) = 0;
	virtual double getAccelerationMin() = 0;
	virtual double getAccelerationMax() = 0;

	virtual double getVelocity() = 0;
	virtual void setVelocity(double velocity) = 0;
	virtual double getVelocityMin() = 0;
	virtual double getVelocityMax() = 0;
	virtual double getVelocityLimit() = 0;
	virtual void setVelocityLimit(double velocityLimit) = 0;

	virtual bool isMoving() = 0;

	virtual bool isSpeedRamping() = 0;
	virtual void setSpeedRamping(bool speedRamping) = 0;

	virtual double getCurrent() = 0;
};

}

#endif
