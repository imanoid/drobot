#ifndef DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARACCELERATIONCHANNELFACTORY_H
#define DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARACCELERATIONCHANNELFACTORY_H

#include "../../channel/channelfactory.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

class VestibularAccelerationChannelFactory : public device::channel::ChannelFactory
{
public:
    VestibularAccelerationChannelFactory();
    virtual void createFromDomElement(QDomElement element, Device *device);
};

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARACCELERATIONCHANNELFACTORY_H
