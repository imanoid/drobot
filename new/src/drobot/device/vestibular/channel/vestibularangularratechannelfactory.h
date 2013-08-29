#ifndef DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARANGULARRATECHANNELFACTORY_H
#define DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARANGULARRATECHANNELFACTORY_H

#include "../../channel/channelfactory.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

class VestibularAngularRateChannelFactory : public device::channel::ChannelFactory
{
public:
    VestibularAngularRateChannelFactory();
    virtual void createFromDomElement(QDomElement element, Device *device);
};

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARANGULARRATECHANNELFACTORY_H
