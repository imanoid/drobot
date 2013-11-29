#include "phidgetadvancedservo.h"
#include "../channel/linearnormalizer.h"
#include "../deviceConstants.h"

namespace drobot {
namespace device {
namespace actuator {

PhidgetAdvancedServo::PhidgetAdvancedServo(std::string name, CPhidgetAdvancedServoHandle phidgetHandle, int index) :
    Actuator(name) {
    _phidgetHandle = phidgetHandle;
    _index = index;
}

void PhidgetAdvancedServo::enable() {
    CPhidgetAdvancedServo_setEngaged(_phidgetHandle, _index, 1);
}

void PhidgetAdvancedServo::disable() {
    CPhidgetAdvancedServo_setEngaged(_phidgetHandle, _index, 0);
}

bool PhidgetAdvancedServo::isEnabled() {
    int engaged;
    CPhidgetAdvancedServo_getEngaged(_phidgetHandle, _index, &engaged);
    return engaged == 1;
}

double PhidgetAdvancedServo::getPosition() {
    double position;
    CPhidgetAdvancedServo_getPosition(_phidgetHandle, _index, &position);
    return position;
}

void PhidgetAdvancedServo::setPosition(double position) {
    CPhidgetAdvancedServo_setPosition(_phidgetHandle, _index, position);
}

double PhidgetAdvancedServo::getPositionMin() {
    double positionMin;
    CPhidgetAdvancedServo_getPositionMin(_phidgetHandle, _index, &positionMin);
    return positionMin;
}

void PhidgetAdvancedServo::setPositionMin(double positionMin) {
    CPhidgetAdvancedServo_setPositionMin(_phidgetHandle, _index, positionMin);
}

double PhidgetAdvancedServo::getPositionMax() {
    double positionMax;
    CPhidgetAdvancedServo_getPositionMax(_phidgetHandle, _index, &positionMax);
    return positionMax;
}

void PhidgetAdvancedServo::setPositionMax(double positionMax) {
    CPhidgetAdvancedServo_setPositionMax(_phidgetHandle, _index, positionMax);
}

double PhidgetAdvancedServo::getMovingAcceleration() {
    double acceleration;
    CPhidgetAdvancedServo_getAcceleration(_phidgetHandle, _index, &acceleration);
    return acceleration;
}

void PhidgetAdvancedServo::setMovingAcceleration(double acceleration) {
    CPhidgetAdvancedServo_setAcceleration(_phidgetHandle, _index, acceleration);
}

double PhidgetAdvancedServo::getMovingAccelerationMin() {
    double accelerationMin;
    CPhidgetAdvancedServo_getAccelerationMin(_phidgetHandle, _index, &accelerationMin);
    return accelerationMin;
}

double PhidgetAdvancedServo::getMovingAccelerationMax() {
    double accelerationMax;
    CPhidgetAdvancedServo_getAccelerationMax(_phidgetHandle, _index, &accelerationMax);
    return accelerationMax;
}

double PhidgetAdvancedServo::getAcceleration() {
    return 0;
}

void PhidgetAdvancedServo::setAcceleration(double acceleration) {

}

double PhidgetAdvancedServo::getAccelerationMin() {
    return PHIDGET_ADVANCED_SERVO_MIN_ACCELERATION_DEFAULT;
}

double PhidgetAdvancedServo::getAccelerationMax() {
    return PHIDGET_ADVANCED_SERVO_MAX_ACCELERATION_DEFAULT;
}

double PhidgetAdvancedServo::getVelocity() {
    return 0;
}

void PhidgetAdvancedServo::setVelocity(double velocity) {

}

double PhidgetAdvancedServo::getVelocityMin() {
    return PHIDGET_ADVANCED_SERVO_MIN_VELOCITY_DEFAULT;
}

double PhidgetAdvancedServo::getVelocityMax() {
    return PHIDGET_ADVANCED_SERVO_MAX_VELOCITY_DEFAULT;
}

double PhidgetAdvancedServo::getMovingVelocity() {
    double velocity;
    CPhidgetAdvancedServo_getVelocity(_phidgetHandle, _index, &velocity);
    return velocity;
}

void PhidgetAdvancedServo::setMovingVelocity(double velocity) {
}

double PhidgetAdvancedServo::getMovingVelocityMin() {
    double velocityMin;
    CPhidgetAdvancedServo_getVelocityMin(_phidgetHandle, _index, &velocityMin);
    return velocityMin;
}

double PhidgetAdvancedServo::getMovingVelocityMax() {
    double velocityMax;
    CPhidgetAdvancedServo_getVelocityMax(_phidgetHandle, _index, &velocityMax);
    return velocityMax;
}

double PhidgetAdvancedServo::getMovingVelocityLimit() {
    double velocityLimit;
    CPhidgetAdvancedServo_getVelocityLimit(_phidgetHandle, _index, &velocityLimit);
    return velocityLimit;
}

void PhidgetAdvancedServo::setMovingVelocityLimit(double velocityLimit) {
    CPhidgetAdvancedServo_setVelocityLimit(_phidgetHandle, _index, velocityLimit);
}

int PhidgetAdvancedServo::getIndex() {
    return _index;
}

bool PhidgetAdvancedServo::isMoving() {
    int stopped;
    CPhidgetAdvancedServo_getStopped(_phidgetHandle, _index, &stopped);
    return stopped == 0;
}

bool PhidgetAdvancedServo::isSpeedRamping() {
    int speedRamping;
    CPhidgetAdvancedServo_getSpeedRampingOn(_phidgetHandle, _index, &speedRamping);
    return speedRamping == 1;
}

void PhidgetAdvancedServo::setSpeedRamping(bool speedRamping) {
    CPhidgetAdvancedServo_setSpeedRampingOn(_phidgetHandle, _index, speedRamping);
}

double PhidgetAdvancedServo::getCurrent() {
    double current;
    CPhidgetAdvancedServo_getCurrent(_phidgetHandle, _index, &current);
    return current;
}

}
}
}
