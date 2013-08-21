#include "deviceboard.h"

namespace drobot {
namespace device {

DeviceBoard::DeviceBoard(std::string name) : Device::Device(name) {
    _enabled = false;
}

void DeviceBoard::enable() {
    _enabled = true;
    std::vector<Device*> devices = list();
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        (*iDevice)->enable();
    }
}

void DeviceBoard::disable() {
    _enabled = false;
    std::vector<Device*> devices = list();
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        (*iDevice)->disable();
    }
}

bool DeviceBoard::isEnabled() {
    return _enabled;
}

void DeviceBoard::onAdd(Device *item) {
    item->setDeviceBoard(this);
}

void DeviceBoard::onRemove(Device *item) {
    item->setDeviceBoard(0);
}


channel::ChannelManager* DeviceBoard::getChannels() {
    return DeviceManager::getChannels();
}

} // namespace device
} // namespace drobot
