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
public:
    PhidgetSimpleBoard(int serial);
    const int getMaxActuators() const;
    std::vector<Actuator*> initAllActuators();
    Actuator* initActuator(int index);
private:
    CPhidgetServoHandle _phidgetHandle;
};

}
}
}

#endif // PHIDGETSIMPLEBOARD_H
