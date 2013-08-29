#ifndef DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORPOSITIONCHANNELFACTORY_H
#define DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORPOSITIONCHANNELFACTORY_H

#include "../../channel/channelfactory.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

class ActuatorPositionChannelFactory : public device::channel::ChannelFactory
{
public:
    ActuatorPositionChannelFactory();
    virtual void createFromDomElement(QDomElement element, Device *device);
};

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORPOSITIONCHANNELFACTORY_H
