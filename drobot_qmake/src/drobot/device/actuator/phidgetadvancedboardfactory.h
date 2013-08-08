#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARDFACTORY_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARDFACTORY_H

#include "../devicefactory.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetAdvancedBoardFactory : public DeviceFactory
{
public:
    virtual std::vector<Device*> createFromDomElement(QDomElement element);
};

} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARDFACTORY_H
