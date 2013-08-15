#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARD_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARD_H

#include "actuatorboard.h"
#include "phidget21.h"
#include "../phidgetdevice.h"
#include "phidgetadvancedservo.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetAdvancedBoard : public ActuatorBoard, public PhidgetDevice
{
private:
    CPhidgetAdvancedServoHandle _phidgetHandle;
public:
    PhidgetAdvancedBoard(std::string name);
    PhidgetAdvancedBoard(std::string name, int serial);
    PhidgetAdvancedBoard(std::string name, CPhidgetAdvancedServoHandle phidgetHandle);
    int getMaxActuators();
    std::vector<Actuator*> initAllActuators();
    Actuator* initActuator(int index, std::string name);
    Actuator* initActuator(int index);
};

}
}
}

#endif // PHIDGETADVANCEDBOARD_H
