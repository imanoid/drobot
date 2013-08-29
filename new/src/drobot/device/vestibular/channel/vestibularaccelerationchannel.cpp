#include "vestibularaccelerationchannel.h"
#include "../../device.h"
#include "../../vestibular/vestibular.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

VestibularAccelerationChannel::VestibularAccelerationChannel(std::string name, device::channel::ChannelType type, int dimension) :
    Channel(name, type) {
    _dimension = dimension;
}

VestibularAccelerationChannel::VestibularAccelerationChannel(std::string name, device::channel::ChannelType type, int dimension, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, type, normalizer, device) {
    _dimension = dimension;
}

void VestibularAccelerationChannel::setValue(double value) {
}

double VestibularAccelerationChannel::getValue() {
    return getDevice()->toVestibular()->getAcceleration()[_dimension];
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
