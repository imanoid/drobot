#include "phidgetsimpleservo.h"
#include "../channel/linearnormalizer.h"
#include "../deviceConstants.h"

namespace drobot {
namespace device {
namespace actuator {

PhidgetSimpleServo::PhidgetSimpleServo(std::string name, CPhidgetServoHandle phidgetHandle, int index) :
    Actuator(name) {
    _phidgetHandle = phidgetHandle;
    _index = index;
}

void PhidgetSimpleServo::enable() {
    CPhidgetServo_setEngaged(_phidgetHandle, _index, 1);
}

void PhidgetSimpleServo::disable() {
    CPhidgetServo_setEngaged(_phidgetHandle, _index, 0);
}

bool PhidgetSimpleServo::isEnabled() {
    int engaged;
    CPhidgetServo_getEngaged(_phidgetHandle, _index, &engaged);
    return engaged == 1;
}

double PhidgetSimpleServo::getPosition() {
    double position;
    CPhidgetServo_getPosition(_phidgetHandle, _index, &position);
    return position;
}

void PhidgetSimpleServo::setPosition(double position) {
    CPhidgetServo_setPosition(_phidgetHandle, _index, position);
}

double PhidgetSimpleServo::getPositionMin() {
    double positionMin;
    CPhidgetServo_getPositionMin(_phidgetHandle, _index, &positionMin);
    return positionMin;
}

double PhidgetSimpleServo::getPositionMax() {
    double positionMax;
    CPhidgetServo_getPositionMax(_phidgetHandle, _index, &positionMax);
    return positionMax;
}

double PhidgetSimpleServo::getVelocity() {
    return 0;
}

void PhidgetSimpleServo::setVelocity(double velocity __maybe_unused) {

}

double PhidgetSimpleServo::getVelocityMin() {
    return PHIDGET_SIMPLE_SERVO_MIN_VELOCITY_DEFAULT;
}

double PhidgetSimpleServo::getVelocityMax() {
    return PHIDGET_SIMPLE_SERVO_MAX_VELOCITY_DEFAULT;
}

double PhidgetSimpleServo::getAcceleration() {
    return 0;
}

void PhidgetSimpleServo::setAcceleration(double acceleration __maybe_unused) {

}

double PhidgetSimpleServo::getAccelerationMin() {
    return PHIDGET_SIMPLE_SERVO_MIN_VELOCITY_DEFAULT;
}

double PhidgetSimpleServo::getAccelerationMax() {
    return PHIDGET_SIMPLE_SERVO_MAX_VELOCITY_DEFAULT;
}

}
}
}
