#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARD_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARD_H

#include "actuatorboard.h"
#include <phidget21.h>
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetSimpleBoard : public ActuatorBoard
{
private:
    CPhidgetServoHandle _phidgetHandle;
protected:
    virtual CPhidgetHandle& getPhidgetHandle();
public:
    PhidgetSimpleBoard(std::string name);
    PhidgetSimpleBoard(std::string name, int serial);
    PhidgetSimpleBoard(std::string name, CPhidgetServoHandle phidgetHandle);
    int getMaxActuators();
    std::vector<Actuator*> initAllActuators();
    Actuator* initActuator(int index, std::string name);
    Actuator* initActuator(int index);
};

}
}
}

#endif // PHIDGETSIMPLEBOARD_H
