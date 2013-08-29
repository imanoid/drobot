#include "vestibularmagneticfieldchannel.h"
#include "../../device.h"
#include "../vestibular.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

VestibularMagneticFieldChannel::VestibularMagneticFieldChannel(std::string name, device::channel::ChannelType type, int dimension) :
    Channel(name, type) {
    _dimension = dimension;
}

VestibularMagneticFieldChannel::VestibularMagneticFieldChannel(std::string name, device::channel::ChannelType type, int dimension, device::channel::Normalizer* normalizer, device::Device* device) :
    Channel(name, type, normalizer, device) {
    _dimension = dimension;
}

void VestibularMagneticFieldChannel::setValue(double value) {
}

double VestibularMagneticFieldChannel::getValue() {
    return getDevice()->toVestibular()->getMagneticField()[_dimension];
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
