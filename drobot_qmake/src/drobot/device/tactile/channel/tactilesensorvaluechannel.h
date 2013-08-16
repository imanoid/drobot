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
public:
    TactileSensorValueChannel(std::string name, ChannelType type);
    TactileSensorValueChannel(std::string name, ChannelType type, device::channel::Normalizer* normalizer, device::Device* device);
    virtual void setValue(double value);
    virtual double getValue();
};

} // namespace channel
} // namespace tactile
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_TACTILE_CHANNEL_TACTILESENSORVALUECHANNEL_H
