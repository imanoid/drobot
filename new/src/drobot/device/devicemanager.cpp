#include "devicemanager.h"
#include <QFile>
#include <QtXml/QDomDocument>
#include "vestibular/phidgetvestibularfactory.h"
#include "deviceboard.h"

namespace drobot {
namespace device {

//public
DeviceManager::DeviceManager() : Manager() {
    _channels = new channel::ChannelManager;
    _deviceBoards = new object::Manager<DeviceBoard>();
}

DeviceManager::DeviceManager(std::vector<Device*> items) : Manager(items) {
    _channels = new channel::ChannelManager;
}

DeviceManager::~DeviceManager() {
    std::vector<DeviceBoard*> boards = _deviceBoards->values();
    for (std::vector<DeviceBoard*>::iterator iBoard = boards.begin(); iBoard != boards.end(); iBoard++) {
        (*iBoard)->disable();
    }
    disable();
    delete _deviceBoards;
    delete _channels;
}

void DeviceManager::onAdd(Device* item) {
    _channels->add(item->getChannels()->values());
}

void DeviceManager::onRemove(Device* item) {
    _channels->remove(item->getChannels()->values());
}

void DeviceManager::enable() {
    std::vector<Device*> devices = values();
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        (*iDevice)->enable();
    }
}

void DeviceManager::disable() {
    std::vector<Device*> devices = values();
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        (*iDevice)->disable();
    }
}

channel::ChannelManager* DeviceManager::getChannels() {
    return _channels;
}

object::Manager<DeviceBoard>*  DeviceManager::getDeviceBoards() {
    return _deviceBoards;
}

}
}
