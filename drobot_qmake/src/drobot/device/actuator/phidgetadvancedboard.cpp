#include "phidgetadvancedboard.h"
#include <phidget21.h>
#include "../../util/util.h"
#include <sstream>

namespace drobot {
namespace device {
namespace actuator {

PhidgetAdvancedBoard::PhidgetAdvancedBoard(std::string name) : ActuatorBoard(name) {
    int serial = -1;
    _phidgetHandle = 0;

    CPhidgetAdvancedServo_create(&_phidgetHandle);
    CPhidget_open((CPhidgetHandle)_phidgetHandle, serial);

    int result;
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)_phidgetHandle, 2000))) {
        //TODO: throw Exception
    }
}

PhidgetAdvancedBoard::PhidgetAdvancedBoard(std::string name, int serial) : ActuatorBoard(name) {
    _phidgetHandle = 0;

    CPhidgetAdvancedServo_create(&_phidgetHandle);
    CPhidget_open((CPhidgetHandle)_phidgetHandle, serial);

    int result;
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)_phidgetHandle, 2000))) {
        //TODO: throw Exception
    }
}

PhidgetAdvancedBoard::PhidgetAdvancedBoard(std::string name, CPhidgetAdvancedServoHandle phidgetHandle) : ActuatorBoard(name) {
    _phidgetHandle = phidgetHandle;
}

int PhidgetAdvancedBoard::getMaxActuators() {
    int* count;
    CPhidgetAdvancedServo_getMotorCount(_phidgetHandle, count);
    return *count;
}

std::vector<Actuator*> PhidgetAdvancedBoard::initAllActuators() {
    std::vector<Actuator*> result;
    for (int iMotor = 0; iMotor < getMaxActuators(); iMotor++) {
        result.push_back(initActuator(iMotor));
    }
    return result;
}

Actuator* PhidgetAdvancedBoard::initActuator(int index, std::string name) {
    PhidgetAdvancedServo* servo = new PhidgetAdvancedServo(name, _phidgetHandle, index);
    if (has(servo))
        remove(servo->getName());
    add(servo);
    return servo;
}

Actuator* PhidgetAdvancedBoard::initActuator(int index) {
    std::stringstream name;
    name << getName() << "." << index;
    return initActuator(index, name.str());
}

}
}
}
