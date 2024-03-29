#include "phidgetsimpleboard.h"
#include "phidgetsimpleservo.h"
#include <phidget21.h>
#include "../../util/util.h"
#include "../../util/exception.h"
#include <sstream>

namespace drobot {
namespace device {
namespace actuator {

PhidgetSimpleBoard::PhidgetSimpleBoard(std::string name) : ActuatorBoard(name) {
    int serial = -1;
    _phidgetHandle = 0;

    CPhidgetServo_create(&_phidgetHandle);
    CPhidget_open((CPhidgetHandle)_phidgetHandle, serial);

    int result;
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)_phidgetHandle, 10000))) {
        util::Exception ex;
        ex << "PhidgetSimpleBoard(" << serial << ") couldn't be attached!";
        throw ex;
    }
}

PhidgetSimpleBoard::PhidgetSimpleBoard(std::string name, int serial) : ActuatorBoard(name) {
    _phidgetHandle = 0;

    CPhidgetServo_create(&_phidgetHandle);
    CPhidget_open((CPhidgetHandle)_phidgetHandle, serial);

    int result;
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)_phidgetHandle, 10000))) {
        util::Exception ex;
        ex << "PhidgetSimpleBoard(" << serial << ") couldn't be attached!";
        throw ex;
    }
}

PhidgetSimpleBoard::PhidgetSimpleBoard(std::string name, CPhidgetServoHandle phidgetHandle) : ActuatorBoard(name) {
    _phidgetHandle = phidgetHandle;
}

PhidgetSimpleBoard::~PhidgetSimpleBoard() {
    disable();
    CPhidget_close((CPhidgetHandle)_phidgetHandle);
    CPhidget_delete((CPhidgetHandle)_phidgetHandle);
}

int PhidgetSimpleBoard::getMaxActuators() {
    int count;
    CPhidgetServo_getMotorCount(_phidgetHandle, &count);
    return count;
}

std::vector<Actuator*> PhidgetSimpleBoard::initAllActuators() {
    std::vector<Actuator*> result;
    for (int iMotor = 0; iMotor < getMaxActuators(); iMotor++) {
        Actuator* a = initActuator(iMotor);
        result.push_back(a);
    }
    return result;
}

Actuator* PhidgetSimpleBoard::initActuator(int index, std::string name) {
    PhidgetSimpleServo* servo = new PhidgetSimpleServo(name, _phidgetHandle, index);
    if (has(servo))
        remove(servo->toDevice());
    add(servo);
    return servo;
}

Actuator* PhidgetSimpleBoard::initActuator(int index) {
    std::stringstream name;
    name << getName() << "." << index;
    return initActuator(index, name.str());
}

}
}
}
