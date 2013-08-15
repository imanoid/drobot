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
public:
    VestibularAngularRateChannel(std::string name, int dimension);
    VestibularAngularRateChannel(std::string name, int dimension, device::channel::Normalizer* normalizer, device::Device* device);
    virtual void setValue(double value);
    virtual double getValue();
};

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARANGULARRATECHANNEL_H
