#include "vestibularaccelerationchannel.h"
#include "../../device.h"
#include "../../vestibular/vestibular.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

VestibularAccelerationChannel::VestibularAccelerationChannel(std::string name, int dimension) :
    Channel(name) {
    _dimension = dimension;
}

VestibularAccelerationChannel::VestibularAccelerationChannel(std::string name, int dimension, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, normalizer, device) {
    _dimension = dimension;
}

void VestibularAccelerationChannel::setValue(double value) {
}

double VestibularAccelerationChannel::getValue() {
    return _device->toVestibular()->getAcceleration()[_dimension];
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
