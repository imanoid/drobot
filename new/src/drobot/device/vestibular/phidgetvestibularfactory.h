#ifndef DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULARFACTORY_H
#define DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULARFACTORY_H

#include "../../object/manager.h"
#include "../devicefactory.h"
#include "../channel/channelfactory.h"

namespace drobot {
namespace device {
namespace vestibular {

class PhidgetVestibularFactory : public DeviceFactory
{
public:
    PhidgetVestibularFactory();
    virtual void createFromDomElement(QDomElement element, robot::Robot* robot);
};

} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULARFACTORY_H
