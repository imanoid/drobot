#include "device.h"
#include "vestibular/vestibular.h"
#include "tactile/tactilesensor.h"
#include "actuator/actuator.h"

namespace drobot {
namespace device {

Device::Device(std::string name) {
    _name = name;
}

bool Device::addInputChannel(channel::Channel* channel) {
    if (hasInputChannel(channel))
        return false;
    _inputChannels.push_back(channel);
    return true;
}

bool Device::removeInputChannel(channel::Channel* channel) {
    for (std::vector<channel::Channel*>::iterator iChannel = _inputChannels.begin(); iChannel != _inputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            _inputChannels.erase(iChannel);
            return true;
        }
    }
    return false;
}

bool Device::hasInputChannel(channel::Channel* channel) {
    for (std::vector<channel::Channel*>::iterator iChannel = _inputChannels.begin(); iChannel != _inputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            return true;
        }
    }
    return false;
}

bool Device::addOutputChannel(channel::Channel* channel) {
    if (hasInputChannel(channel))
        return false;
    _outputChannels.push_back(channel);
    return true;
}

bool Device::removeOutputChannel(channel::Channel* channel) {
    for (std::vector<channel::Channel*>::iterator iChannel = _outputChannels.begin(); iChannel != _outputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            _outputChannels.erase(iChannel);
            return true;
        }
    }
    return false;
}

bool Device::hasOutputChannel(channel::Channel* channel) {
    for (std::vector<channel::Channel*>::iterator iChannel = _outputChannels.begin(); iChannel != _outputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            return true;
        }
    }
    return false;
}

DeviceBoard* Device::getDeviceBoard() {
    return _deviceBoard;
}

void Device::setDeviceBoard(DeviceBoard* deviceBoard) {
    _deviceBoard = deviceBoard;
}

std::string Device::getName() {
    return _name;
}

void Device::setName(std::string name) {
    _name = name;
}

const std::vector<channel::Channel*> Device::getInputChannels() const {
    return _inputChannels;
}

const std::vector<channel::Channel*> Device::getOutputChannels() const {
    return _outputChannels;
}

actuator::Actuator* Device::toActuator() {
    return dynamic_cast<actuator::Actuator*>(this);
}

tactile::TactileSensor* Device::toTactileSensor() {
    return dynamic_cast<tactile::TactileSensor*>(this);
}

vestibular::Vestibular* Device::toVestibular() {
    return dynamic_cast<vestibular::Vestibular*>(this);
}

}
}
