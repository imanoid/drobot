#ifndef DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARACCELERATIONCHANNEL_H
#define DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARACCELERATIONCHANNEL_H

#include "../../channel/channel.h"
#include "../../device.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

class VestibularAccelerationChannel : public device::channel::Channel
{
private:
    int _dimension;
public:
    VestibularAccelerationChannel(std::string name, device::channel::ChannelType type, int dimension);
    VestibularAccelerationChannel(std::string name, device::channel::ChannelType type, int dimension, device::channel::Normalizer* normalizer, device::Device* device);
    virtual void setValue(double value);
    virtual double getValue();
};

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARACCELERATIONCHANNEL_H
