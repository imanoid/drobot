#include "tactilesensorvaluechannel.h"
#include "../../device.h"
#include "../../tactile/tactilesensor.h"

namespace drobot {
namespace device {
namespace tactile {
namespace channel {

TactileSensorValueChannel::TactileSensorValueChannel(std::string name) :
    Channel(name) {}

TactileSensorValueChannel::TactileSensorValueChannel(std::string name, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, normalizer, device) {}

void TactileSensorValueChannel::setValue(double value) {
    _device->toTactileSensor()->setValue(value);
}

double TactileSensorValueChannel::getValue() {
    return _device->toTactileSensor()->getValue();
}

} // namespace channel
} // namespace tactile
} // namespace device
} // namespace drobot
