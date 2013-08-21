#ifndef DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORACCELERATIONCHANNELFACTORY_H
#define DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORACCELERATIONCHANNELFACTORY_H

#include "../../channel/channelfactory.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

class ActuatorAccelerationChannelFactory : public device::channel::ChannelFactory
{
public:
    ActuatorAccelerationChannelFactory();
    virtual void createFromDomElement(QDomElement element, Device *device);
};

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORACCELERATIONCHANNELFACTORY_H
