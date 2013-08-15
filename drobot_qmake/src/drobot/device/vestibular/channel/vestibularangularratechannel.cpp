#include "vestibularangularratechannel.h"
#include "../../device.h"
#include "../../vestibular/vestibular.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

VestibularAngularRateChannel::VestibularAngularRateChannel(std::string name, int dimension) :
    Channel(name) {
    _dimension = dimension;
}

VestibularAngularRateChannel::VestibularAngularRateChannel(std::string name, int dimension, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, normalizer, device) {
    _dimension = dimension;
}

void VestibularAngularRateChannel::setValue(double value) {
}

double VestibularAngularRateChannel::getValue() {
    return _device->toVestibular()->getAngularRate()[_dimension];
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
