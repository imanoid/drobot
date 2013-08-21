#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDSERVOFACTORY_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDSERVOFACTORY_H

#include "../devicefactory.h"
#include "../channel/channelfactory.h"
#include "../../object/manager.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetAdvancedServoFactory : public DeviceFactory
{
public:
    PhidgetAdvancedServoFactory();
    virtual void createFromDomElement(QDomElement element, DeviceManager *devices);
};

} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDSERVOFACTORY_H
