#ifndef DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORPOSITIONCHANNEL_H
#define DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORPOSITIONCHANNEL_H

#include "../../channel/channel.h"
#include "../../device.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

class ActuatorPositionChannel : public device::channel::Channel
{
public:
    ActuatorPositionChannel(std::string name, device::channel::ChannelType type);
    ActuatorPositionChannel(std::string name, device::channel::ChannelType type, device::channel::Normalizer* normalizer, device::Device* device);
    virtual void setValue(double value);
    virtual double getValue();
};

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORPOSITIONCHANNEL_H
