#include "tactilesensorvaluechannel.h"
#include "../../device.h"
#include "../../tactile/tactilesensor.h"

namespace drobot {
namespace device {
namespace tactile {
namespace channel {

TactileSensorValueChannel::TactileSensorValueChannel(std::string name, device::channel::ChannelType type) :
    Channel(name, type) {}

TactileSensorValueChannel::TactileSensorValueChannel(std::string name, device::channel::ChannelType type, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, type, normalizer, device) {}

void TactileSensorValueChannel::setValue(double value) {
}

double TactileSensorValueChannel::getValue() {
    return getDevice()->toTactileSensor()->getValue();
}

} // namespace channel
} // namespace tactile
} // namespace device
} // namespace drobot
