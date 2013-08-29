#include "actuatorpositionchannel.h"
#include "../../device.h"
#include "../../actuator/actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorPositionChannel::ActuatorPositionChannel(std::string name, device::channel::ChannelType type) :
    Channel(name, type) {}

ActuatorPositionChannel::ActuatorPositionChannel(std::string name, device::channel::ChannelType type, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, type, normalizer, device) {}

void ActuatorPositionChannel::setValue(double value) {
    getDevice()->toActuator()->setPosition(value);
}

double ActuatorPositionChannel::getValue() {
    return getDevice()->toActuator()->getPosition();
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
