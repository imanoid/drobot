#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARD_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARD_H

#include "actuatorboard.h"
#include <phidget21.h>
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetSimpleBoard : public ActuatorBoard, public PhidgetDevice
{
private:
    CPhidgetServoHandle _phidgetHandle;
public:
    PhidgetSimpleBoard(std::string name);
    PhidgetSimpleBoard(std::string name, int serial);
    PhidgetSimpleBoard(std::string name, CPhidgetServoHandle phidgetHandle);
    const int getMaxActuators() const;
    std::vector<Actuator*> initAllActuators();
    Actuator* initActuator(int index);
};

}
}
}

#endif // PHIDGETSIMPLEBOARD_H
