#include "vestibularangularratechannel.h"
#include "../../device.h"
#include "../../vestibular/vestibular.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

VestibularAngularRateChannel::VestibularAngularRateChannel(std::string name, ChannelType type, int dimension) :
    Channel(name, type) {
    _dimension = dimension;
}

VestibularAngularRateChannel::VestibularAngularRateChannel(std::string name, ChannelType type, int dimension, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, type, normalizer, device) {
    _dimension = dimension;
}

void VestibularAngularRateChannel::setValue(double value) {
}

double VestibularAngularRateChannel::getValue() {
    return getDevice()->toVestibular()->getAngularRate()[_dimension];
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
