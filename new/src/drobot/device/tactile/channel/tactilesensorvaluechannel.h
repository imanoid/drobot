#ifndef DROBOT_DEVICE_TACTILE_CHANNEL_TACTILESENSORVALUECHANNEL_H
#define DROBOT_DEVICE_TACTILE_CHANNEL_TACTILESENSORVALUECHANNEL_H

#include "../../channel/channel.h"
#include "../../device.h"

namespace drobot {
namespace device {
namespace tactile {
namespace channel {

class TactileSensorValueChannel : public device::channel::Channel
{
protected:
    virtual void setValue(double value);
    virtual double getValue();
public:
    TactileSensorValueChannel(std::string name, device::channel::ChannelType type);
    TactileSensorValueChannel(std::string name, device::channel::ChannelType type, device::channel::Normalizer* normalizer, device::Device* device);
};

} // namespace channel
} // namespace tactile
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_TACTILE_CHANNEL_TACTILESENSORVALUECHANNEL_H
