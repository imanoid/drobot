#ifndef DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORACCELERATIONCHANNEL_H
#define DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORACCELERATIONCHANNEL_H

#include "../../channel/channel.h"
#include "../../device.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

class ActuatorAccelerationChannel : public device::channel::Channel
{
protected:
    virtual void setValue(double value);
    virtual double getValue();
public:
    ActuatorAccelerationChannel(std::string name, device::channel::ChannelType type);
    ActuatorAccelerationChannel(std::string name, device::channel::ChannelType type, device::channel::Normalizer* normalizer, device::Device* device);
};

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORACCELERATIONCHANNEL_H
