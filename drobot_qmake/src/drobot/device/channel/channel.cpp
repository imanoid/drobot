#include "channel.h"
#include "../device.h"
#include <sstream>

namespace drobot {
namespace device {
namespace channel {

Channel::Channel(std::string name) {
    _name = name;
}

Channel::Channel(std::string name, Normalizer* normalizer, Device* device) {
    _name = name;
    _normalizer = normalizer;
    _device = device;
}

void Channel::setNormalizer(Normalizer* normalizer) {
    _normalizer = normalizer;
}

Normalizer* Channel::getNormalizer() {
    return _normalizer;
}

void Channel::setDevice(Device* device) {
    _device = device;
}

Device* Channel::getDevice() {
    return _device;
}

void Channel::setNormalizedValue(double value) {
    setValue(_normalizer->denormalize(value));
}

double Channel::getNormalizedValue() {
    return _normalizer->normalize(getValue());
}

void Channel::setName(std::string name) {
    _name = name;
}

std::string Channel::getName() {
    return _name;
}

std::string Channel::getFullName() {
    std::stringstream name;
    name << getDevice()->getName() << "." << _name;
    return name.str();
}

} // namespace channel
} // namespace device
} // namespace drobot
