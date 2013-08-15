#ifndef DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORVELOCITYCHANNEL_H
#define DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORVELOCITYCHANNEL_H

#include "../../channel/channel.h"
#include "../../device.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

class ActuatorVelocityChannel : public device::channel::Channel
{
public:
    ActuatorVelocityChannel(std::string name);
    ActuatorVelocityChannel(std::string name, device::channel::Normalizer* normalizer, device::Device* device);
    virtual void setValue(double value);
    virtual double getValue();
};

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_ACTUATOR_CHANNEL_ACTUATORVELOCITYCHANNEL_H
