#include "actuatorpositionchannel.h"
#include "../../device.h"
#include "../../actuator/actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorPositionChannel::ActuatorPositionChannel(std::string name) :
    Channel(name) {}

ActuatorPositionChannel::ActuatorPositionChannel(std::string name, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, normalizer, device) {}

void ActuatorPositionChannel::setValue(double value) {
    _device->toActuator()->setPosition(value);
}

double ActuatorPositionChannel::getValue() {
    return _device->toActuator()->getPosition();
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
