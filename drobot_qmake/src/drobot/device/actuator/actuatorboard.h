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
    const std::vector<Actuator*> getActuators() const;
    Actuator* getActuator(std::string name) const;
};

}
}
}

#endif // PHIDGETABSTRACTBOARD_H
