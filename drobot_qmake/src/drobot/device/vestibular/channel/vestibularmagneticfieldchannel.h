#ifndef DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARMAGNETICFIELDCHANNEL_H
#define DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARMAGNETICFIELDCHANNEL_H

#include "../../channel/channel.h"
#include "../../device.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

class VestibularMagneticFieldChannel : public device::channel::Channel
{
private:
    int _dimension;
protected:
    virtual void setValue(double value);
    virtual double getValue();
public:
    VestibularMagneticFieldChannel(std::string name, device::channel::ChannelType type, int dimension);
    VestibularMagneticFieldChannel(std::string name, device::channel::ChannelType type, int dimension, device::channel::Normalizer* normalizer, device::Device* device);
};

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_VESTIBULAR_CHANNEL_VESTIBULARMAGNETICFIELDCHANNEL_H
