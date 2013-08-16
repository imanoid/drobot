#include "actuatorvelocitychannel.h"
#include "../../device.h"
#include "../../actuator/actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorVelocityChannel::ActuatorVelocityChannel(std::string name, ChannelType type) :
    Channel(name, type) {}

ActuatorVelocityChannel::ActuatorVelocityChannel(std::string name, ChannelType type, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, type, normalizer, device) {}

void ActuatorVelocityChannel::setValue(double value) {
    getDevice()->toActuator()->setVelocity(value);
}

double ActuatorVelocityChannel::getValue() {
    return getDevice()->toActuator()->getVelocity();
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
