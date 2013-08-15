#ifndef DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULARFACTORY_H
#define DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULARFACTORY_H

#include "../devicefactory.h"

namespace drobot {
namespace device {
namespace vestibular {

class PhidgetVestibularFactory : public DeviceFactory
{
public:
    virtual std::vector<Device*> createFromDomElement(QDomElement element);
};

} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULARFACTORY_H
