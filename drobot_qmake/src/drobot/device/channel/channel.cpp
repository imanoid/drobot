#include "channel.h"
#include "../device.h"
#include <sstream>
#include <iostream>

namespace drobot {
namespace device {
namespace channel {

Channel::Channel(std::string name, ChannelType type) : Item(name) {
    _type = type;
    if (_type == INPUT) {
        _update = true;
    } else if (_type == OUTPUT) {
        _update = false;
        _value = 0;
    }
}

Channel::Channel(std::string name, ChannelType type, Normalizer* normalizer, Device* device) : Item(name) {
    _type = type;
    _normalizer = normalizer;
    _device = device;
    if (_type == INPUT) {
        _update = true;
    } else if (_type == OUTPUT) {
        _update = false;
        _value = 0;
    }
}

void Channel::setNormalizer(Normalizer* normalizer) {
    _normalizer = normalizer;
}

Normalizer* Channel::getNormalizer() {
    return _normalizer;
}

void Channel::setDevice(Device* device) {
    std::cout << this << "setDevice" << std::endl;
    _device = device;
}

Device* Channel::getDevice() {
    return _device;
}

void Channel::setNormalizedValue(double value) {
    _value = _normalizer->denormalize(value);
    if (_type == OUTPUT)
        _update = true;
}

double Channel::getNormalizedValue() {
    return _normalizer->normalize(_value);
}

void Channel::setRealValue(double value) {
    _value = value;
    if (_type == OUTPUT)
        _update = true;
}

double Channel::getRealValue() {
    return _value;
}

std::string Channel::getName() {
    if (_device != 0) {
        std::stringstream name;
        name << _device->getName() << "_" << _name;
        return name.str();
    } else {
        return Item::getName();
    }
}

void Channel::setType(ChannelType type) {
    _type = type;
}

ChannelType Channel::getType() {
    return _type;
}

void Channel::read() {
    if (_type == INPUT) {
        _value = getValue();
    }
}

void Channel::write() {
    if (_update && _type == OUTPUT) {
        setValue(_value);
        _update = false;
    }
}

} // namespace channel
} // namespace device
} // namespace drobot
