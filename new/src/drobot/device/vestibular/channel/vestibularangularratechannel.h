#ifndef DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARANGULARRATECHANNEL_H
#define DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARANGULARRATECHANNEL_H

#include "../../channel/channel.h"
#include "../../device.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

class VestibularAngularRateChannel : public device::channel::Channel
{
private:
    int _dimension;
protected:
    virtual void setValue(double value);
    virtual double getValue();
public:
    VestibularAngularRateChannel(std::string name, device::channel::ChannelType type, int dimension);
    VestibularAngularRateChannel(std::string name, device::channel::ChannelType type, int dimension, device::channel::Normalizer* normalizer, device::Device* device);
};

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARANGULARRATECHANNEL_H
