#include "phidgetsimpleboard.h"
#include "phidgetsimpleservo.h"
#include <phidget21.h>
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace actuator {

PhidgetSimpleBoard::PhidgetSimpleBoard(std::string name) : ActuatorBoard(name) {
    int serial = -1;
    _phidgetHandle = 0;

    CPhidgetServo_create(&_phidgetHandle);
    CPhidget_open((CPhidgetHandle)_phidgetHandle, serial);

    int result;
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)_phidgetHandle, 2000))) {
        //TODO: throw Exception
    }
}

PhidgetSimpleBoard::PhidgetSimpleBoard(std::string name, int serial) : ActuatorBoard(name) {
    _phidgetHandle = 0;

    CPhidgetServo_create(&_phidgetHandle);
    CPhidget_open((CPhidgetHandle)_phidgetHandle, serial);

    int result;
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)_phidgetHandle, 2000))) {
        //TODO: throw Exception
    }
}

PhidgetSimpleBoard::PhidgetSimpleBoard(std::string name, CPhidgetServoHandle phidgetHandle) : ActuatorBoard(name) {
    _phidgetHandle = phidgetHandle;
}

const int PhidgetSimpleBoard::getMaxActuators() const {
    int* count;
    CPhidgetServo_getMotorCount(_phidgetHandle, count);
    return *count;
}

std::vector<Actuator*> PhidgetSimpleBoard::initAllActuators() {
    for (int iMotor = 0; iMotor < getMaxActuators(); iMotor++) {
        PhidgetSimpleServo* servo = new PhidgetSimpleServo(_phidgetHandle, iMotor);
        if (hasDevice(servo))
            removeDevice(servo);
        addDevice(servo);
    }
    return drobot::util::castVector<Device*, Actuator*>(getDevices());
}

Actuator* PhidgetSimpleBoard::initActuator(int index) {
    PhidgetSimpleServo* servo = new PhidgetSimpleServo(_phidgetHandle, index);
    if (hasDevice(servo))
        removeDevice(servo);
    addDevice(servo);
    return servo;
}

}
}
}
