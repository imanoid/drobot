#include <iostream>

#include "DRobotServoMotor.h"

namespace drobot {

DRobotServoMotor::DRobotServoMotor(CPhidgetServoHandle servo) {
	this->servo = servo;
}

void DRobotServoMotor::setMotorPosition(double position) {
	if (position < this->min)
		position = this->min;
	else if (position > this->max)
		position = this->max;
	CPhidgetServo_setPosition(servo, this->getIndex(), position);
}

double DRobotServoMotor::getMotorPosition() {
	double position;
	CPhidgetServo_getPosition(servo, this->getIndex(), &position);
	return position;
}

void DRobotServoMotor::engage() {
	CPhidgetServo_setEngaged(servo, this->index, 1);
}

void DRobotServoMotor::disengage() {
	CPhidgetServo_setEngaged(servo, this->index, 0);
}

bool DRobotServoMotor::isEngaged() {
	int engaged = 0;
	CPhidgetServo_getEngaged(servo, this->index, &engaged);
	return engaged == 1;
}

}
