#ifndef DROBOT_DEVICE_ACTUATOR_ACTUATORBOARD_H
#define DROBOT_DEVICE_ACTUATOR_ACTUATORBOARD_H

#include <vector>
#include "actuator.h"
#include "../deviceboard.h"

namespace drobot {
namespace device {
namespace actuator {

class ActuatorBoard : public DeviceBoard
{
public:
    ActuatorBoard(std::string name);
    std::vector<Actuator*> getActuators();
    Actuator* getActuator(std::string name);
};

}
}
}

#endif // PHIDGETABSTRACTBOARD_H
