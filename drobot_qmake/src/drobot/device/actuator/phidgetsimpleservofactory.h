#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLESERVOFACTORY_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLESERVOFACTORY_H

#include "../devicefactory.h"
#include "../channel/channelfactory.h"
#include "../../object/manager.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetSimpleServoFactory : public DeviceFactory
{
public:
    PhidgetSimpleServoFactory();
    virtual void createFromDomElement(QDomElement element, DeviceManager *devices);
};

} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLESERVOFACTORY_H
