#include "actuatorvelocitychannel.h"
#include "../../device.h"
#include "../../actuator/actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorVelocityChannel::ActuatorVelocityChannel(std::string name) :
    Channel(name) {}

ActuatorVelocityChannel::ActuatorVelocityChannel(std::string name, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, normalizer, device) {}

void ActuatorVelocityChannel::setValue(double value) {
    _device->toActuator()->setVelocity(value);
}

double ActuatorVelocityChannel::getValue() {
    return _device->toActuator()->getVelocity();
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
