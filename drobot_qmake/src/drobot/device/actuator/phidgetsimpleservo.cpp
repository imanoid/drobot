#include "phidgetsimpleservo.h"

namespace drobot {
namespace device {
namespace actuator {

PhidgetSimpleServo::PhidgetSimpleServo(
        CPhidgetServoHandle phidgetHandle, int index) : PhidgetDevice::PhidgetDevice((CPhidgetHandle)phidgetHandle) {
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
    int* engaged;
    CPhidgetServo_getEngaged(_phidgetHandle, _index, engaged);
    return (*engaged) == 1;
}

double PhidgetSimpleServo::getPosition() {
    double* position;
    CPhidgetServo_getPosition(_phidgetHandle, _index, position);
    return *position;
}

void PhidgetSimpleServo::setPosition(double position) {
    CPhidgetServo_setPosition(_phidgetHandle, _index, position);
}

double PhidgetSimpleServo::getPositionMin() {
    double* positionMin;
    CPhidgetServo_getPositionMin(_phidgetHandle, _index, positionMin);
    return *positionMin;
}

double PhidgetSimpleServo::getPositionMax() {
    double* positionMax;
    CPhidgetServo_getPositionMax(_phidgetHandle, _index, positionMax);
    return *positionMax;
}



double PhidgetSimpleServo::getVelocity() {
    return 0.0;
}

void PhidgetSimpleServo::setVelocity(double velocity) {

}

double PhidgetSimpleServo::getAcceleration() {
    return 0.0;
}

void PhidgetSimpleServo::setAcceleration(double acceleration) {

}

}
}
}
