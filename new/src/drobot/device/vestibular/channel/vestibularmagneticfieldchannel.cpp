#include "vestibularmagneticfieldchannel.h"
#include "../../device.h"
#include "../vestibular.h"
#include <iostream>

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
    double value = getDevice()->toVestibular()->getMagneticField()[_dimension];
    double normalizedValue = getNormalizer()->normalize(value);
    //magnetic field sensor bugs sometimes and sends unreasonably high values (in the order of 1e+300)
    if (normalizedValue > 1) {
        return getRealValue();
    }
    return value;
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
