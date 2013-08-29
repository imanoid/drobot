#include <iostream>

#include "DRobotAdvancedServoMotor.h"

namespace drobot {

DRobotAdvancedServoMotor::DRobotAdvancedServoMotor(
		CPhidgetAdvancedServoHandle servo) {
	this->servo = servo;
}

void DRobotAdvancedServoMotor::setMotorPosition(double position) {
	std::cout << servo << " " << this->index << std::endl;
	CPhidgetAdvancedServo_setPosition(servo, this->index, position);
}

double DRobotAdvancedServoMotor::getMotorPosition() {
	double position;
	CPhidgetAdvancedServo_getPosition(servo, this->index, &position);
	return position;
}

void DRobotAdvancedServoMotor::engage() {
	CPhidgetAdvancedServo_setEngaged(servo, this->index, 1);
}

void DRobotAdvancedServoMotor::disengage() {
	CPhidgetAdvancedServo_setEngaged(servo, this->index, 0);
}

bool DRobotAdvancedServoMotor::isEngaged() {
	int engaged = 0;
	CPhidgetAdvancedServo_getEngaged(servo, this->index, &engaged);
	return engaged == 1;
}

}
