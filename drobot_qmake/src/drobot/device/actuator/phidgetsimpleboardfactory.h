#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARDFACTORY_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARDFACTORY_H

#include "../devicefactory.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetSimpleBoardFactory : public DeviceFactory
{
public:
    virtual std::vector<Device*> createFromDomElement(QDomElement element);
};

} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARDFACTORY_H
