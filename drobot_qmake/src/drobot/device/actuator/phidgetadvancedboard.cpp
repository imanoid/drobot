#include "phidgetadvancedboard.h"
#include <phidget21.h>
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace actuator {

PhidgetAdvancedBoard::PhidgetAdvancedBoard(int serial) {
    _phidgetHandle = 0;

    CPhidgetAdvancedServo_create(&_phidgetHandle);
    CPhidget_open((CPhidgetHandle)_phidgetHandle, serial);

    int result;
    if((result = CPhidget_waitForAttachment((CPhidgetHandle)_phidgetHandle, 2000))) {
        //TODO: throw Exception
    }
}

const int PhidgetAdvancedBoard::getMaxActuators() const {
    int* count;
    CPhidgetAdvancedServo_getMotorCount(_phidgetHandle, count);
    return *count;
}

std::vector<Actuator*> PhidgetAdvancedBoard::initAllActuators() {
    for (int iMotor = 0; iMotor < getMaxActuators(); iMotor++) {
        PhidgetAdvancedServo* servo = new PhidgetAdvancedServo(_phidgetHandle, iMotor);
        if (hasDevice(servo))
            removeDevice(servo);
        addDevice(servo);
    }
    return drobot::util::castVector<Device*, Actuator*>(getDevices());
}

Actuator* PhidgetAdvancedBoard::initActuator(int index) {
    PhidgetAdvancedServo* servo = new PhidgetAdvancedServo(_phidgetHandle, index);
    if (hasDevice(servo))
        removeDevice(servo);
    addDevice(servo);
    return servo;
}

}
}
}
