#ifndef DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORVELOCITYCHANNELFACTORY_H
#define DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORVELOCITYCHANNELFACTORY_H

#include "../../channel/channelfactory.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

class ActuatorVelocityChannelFactory : public device::channel::ChannelFactory
{
public:
    ActuatorVelocityChannelFactory();
    virtual void createFromDomElement(QDomElement element, Device *device);
};

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORVELOCITYCHANNELFACTORY_H
