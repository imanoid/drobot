#include "deviceboard.h"

namespace drobot {
namespace device {

DeviceBoard::DeviceBoard(std::string name) : Device::Device(name) {
}

void DeviceBoard::initChannels() {
}

const std::vector<Device*> DeviceBoard::getDevices() const {
    return _devices;
}

bool DeviceBoard::addDevice(Device* device) {
    if (!hasDevice(device)) {
        _devices.push_back(device);
        device->setDeviceBoard(this);
        return true;
    } else {
        return false;
    }
}

bool DeviceBoard::removeDevice(std::string name) {
    for (std::vector<Device*>::iterator iDevice = _devices.begin(); iDevice != _devices.end(); iDevice++) {
        Device* device = *iDevice;
        if (device->getName() == name) {
            _devices.erase(iDevice);
            device->setDeviceBoard(0);
            return true;
        }
    }
    return false;
}

bool DeviceBoard::removeDevice(Device* device) {
    removeDevice(device->getName());
}

Device* DeviceBoard::getDevice(std::string name) const {
    for (int iDevice = 0; iDevice < _devices.size(); iDevice++) {
        Device* device = _devices[iDevice];
        if (device->getName() == name) {
            return device;
        }
    }
    return 0;
}

bool DeviceBoard::hasDevice(std::string name) const {
    return getDevice(name) != 0;
}

bool DeviceBoard::hasDevice(Device* device) const {
    return hasDevice(device->getName());
}

void DeviceBoard::clearDevices() {
    _devices.clear();
}

void DeviceBoard::enable() {
    for (int iDevice = 0; iDevice < _devices.size(); iDevice++) {
        Device* device = _devices[iDevice];
        device->enable();
    }
    _enabled = true;
}

void DeviceBoard::disable() {
    for (int iDevice = 0; iDevice < _devices.size(); iDevice++) {
        Device* device = _devices[iDevice];
        device->disable();
    }
    _enabled = false;
}

bool DeviceBoard::isEnabled() {
    return _enabled;
}

} // namespace device
} // namespace drobot
