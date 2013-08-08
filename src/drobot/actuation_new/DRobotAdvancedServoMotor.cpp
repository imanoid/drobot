#include "DRobotAdvancedServoMotor.h"

namespace drobot {

DRobotAdvancedServoMotor::DRobotAdvancedServoMotor(
		CPhidgetAdvancedServoHandle phidgetHandle, int index) {
	_phidgetHandle = phidgetHandle;
	_index = index;
}

void DRobotAdvancedServoMotor::engage() {
	CPhidgetAdvancedServo_setEngaged(_phidgetHandle, _index, 1);
}

void DRobotAdvancedServoMotor::disengage() {
	CPhidgetAdvancedServo_setEngaged(_phidgetHandle, _index, 0);
}

double DRobotAdvancedServoMotor::getPosition() {
	double* position;
	CPhidgetAdvancedServo_getPosition(_phidgetHandle, _index, position);
	return *position;
}

void DRobotAdvancedServoMotor::setPosition(double position) {
	CPhidgetAdvancedServo_setPosition(_phidgetHandle, _index, position);
}

double DRobotAdvancedServoMotor::getPositionMin() {
	double* positionMin;
	CPhidgetAdvancedServo_getPositionMin(_phidgetHandle, _index, positionMin);
	return *positionMin;
}

void DRobotAdvancedServoMotor::setPositionMin(double positionMin) {
	CPhidgetAdvancedServo_setPositionMin(_phidgetHandle, _index, positionMin);
}

double DRobotAdvancedServoMotor::getPositionMax() {
	double* positionMax;
	CPhidgetAdvancedServo_getPositionMax(_phidgetHandle, _index, positionMax);
	return *positionMax;
}

void DRobotAdvancedServoMotor::setPositionMax(double positionMax) {
	CPhidgetAdvancedServo_setPositionMax(_phidgetHandle, _index, positionMax);
}

double DRobotAdvancedServoMotor::getAcceleration() {
	double* acceleration;
	CPhidgetAdvancedServo_getAcceleration(_phidgetHandle, _index, acceleration);
	return *acceleration;
}

void DRobotAdvancedServoMotor::setAcceleration(double acceleration) {
	CPhidgetAdvancedServo_setAcceleration(_phidgetHandle, _index, acceleration);
}

double DRobotAdvancedServoMotor::getAccelerationMin() {
	double* accelerationMin;
	CPhidgetAdvancedServo_getAccelerationMin(_phidgetHandle, _index,
			accelerationMin);
	return *accelerationMin;
}

double DRobotAdvancedServoMotor::getAccelerationMax() {
	double* accelerationMax;
	CPhidgetAdvancedServo_getAccelerationMax(_phidgetHandle, _index,
			accelerationMax);
	return *accelerationMax;
}

double DRobotAdvancedServoMotor::getVelocity() {
	double* velocity;
	CPhidgetAdvancedServo_getVelocity(_phidgetHandle, _index, velocity);
	return *velocity;
}

void DRobotAdvancedServoMotor::setVelocity(double velocity) {
	CPhidgetAdvancedServo_setVelocity(_phidgetHandle, _index, velocity);
}

double DRobotAdvancedServoMotor::getVelocityMin() {
	double* velocityMin;
	CPhidgetAdvancedServo_getVelocityMin(_phidgetHandle, _index, velocityMin);
	return *velocityMin;
}

double DRobotAdvancedServoMotor::getVelocityMax() {
	double* velocityMax;
	CPhidgetAdvancedServo_getVelocityMax(_phidgetHandle, _index, velocityMax);
	return *velocityMax;
}

double DRobotAdvancedServoMotor::getVelocityLimit() {
	double* velocityLimit;
	CPhidgetAdvancedServo_getVelocityLimit(_phidgetHandle, _index,
			velocityLimit);
	return *velocityLimit;
}

void DRobotAdvancedServoMotor::setVelocityLimit(double velocityLimit) {
	CPhidgetAdvancedServo_setVelocityLimit(_phidgetHandle, _index,
			velocityLimit);
}

bool DRobotAdvancedServoMotor::isMoving() {
	int* stopped;
	CPhidgetAdvancedServo_getStopped(_phidgetHandle, _index, stopped);
	return stopped == 0;
}

bool DRobotAdvancedServoMotor::isSpeedRamping() {
	int* speedRamping;
	CPhidgetAdvancedServo_getSpeedRampingOn(_phidgetHandle, _index,
			speedRamping);
	return *speedRamping == 1;
}

void DRobotAdvancedServoMotor::setSpeedRamping(bool speedRamping) {
	CPhidgetAdvancedServo_setSpeedRampingOn(_phidgetHandle, _index,
			speedRamping);
}

double DRobotAdvancedServoMotor::getCurrent() {
	double* current;
	CPhidgetAdvancedServo_getCurrent(_phidgetHandle, _index, current);
	return *current;
}

}
