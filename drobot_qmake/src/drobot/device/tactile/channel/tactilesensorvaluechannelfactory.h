#ifndef DROBOT_DEVICE_TACTILE_CHANNEL_TACTILESENSORVALUECHANNELFACTORY_H
#define DROBOT_DEVICE_TACTILE_CHANNEL_TACTILESENSORVALUECHANNELFACTORY_H

#include "../../channel/channelfactory.h"

namespace drobot {
namespace device {
namespace tactile {
namespace channel {

class TactileSensorValueChannelFactory : public device::channel::ChannelFactory {
public:
    TactileSensorValueChannelFactory();
    virtual void createFromDomElement(QDomElement element, Device *device);
};

} // namespace channel
} // namespace tactile
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_TACTILE_CHANNEL_TACTILESENSORVALUECHANNELFACTORY_H
