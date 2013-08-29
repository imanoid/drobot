#include "actuatoraccelerationchannel.h"
#include "../../device.h"
#include "../../actuator/actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorAccelerationChannel::ActuatorAccelerationChannel(std::string name, device::channel::ChannelType type) :
    Channel(name, type) {}

ActuatorAccelerationChannel::ActuatorAccelerationChannel(std::string name, device::channel::ChannelType type, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, type, normalizer, device) {}

void ActuatorAccelerationChannel::setValue(double value) {
    _device->toActuator()->setAcceleration(value);
}

double ActuatorAccelerationChannel::getValue() {
    return _device->toActuator()->getAcceleration();
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
