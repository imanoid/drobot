#include "deviceboard.h"

namespace drobot {
namespace device {

DeviceBoard::DeviceBoard(std::string name) : Device::Device(name) {
}

void DeviceBoard::initChannels() {
    Device::clearInputChannels();
    Device::clearOutputChannels();
    std::vector<Device*> devices = getDevices();
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        Device* dev = *iDevice;
        dev->initChannels();
        Device::addInputChannels(dev->getInputChannels());
        Device::addOutputChannels(dev->getOutputChannels());
    }
}

void DeviceBoard::enable() {
    for (std::vector<Device*>::iterator iDevice = getDevices().begin(); iDevice != getDevices().end(); iDevice++) {
        (*iDevice)->enable();
    }
    _enabled = true;
}

void DeviceBoard::disable() {
    for (std::vector<Device*>::iterator iDevice = getDevices().begin(); iDevice != getDevices().end(); iDevice++) {
        (*iDevice)->disable();
    }
    _enabled = false;
}

bool DeviceBoard::isEnabled() {
    return _enabled;
}

} // namespace device
} // namespace drobot
