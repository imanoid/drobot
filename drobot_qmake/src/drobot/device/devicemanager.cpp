#include "devicemanager.h"
#include <QFile>
#include <QtXml/QDomDocument>
#include <iostream>

namespace drobot {
namespace device {

//protected
void DeviceManager::parseElement(QDomElement element) {
    QString name = element.tagName();
    if (name.compare("deviceGroup") == 0) {
        parseDeviceGroup(element);
    }
}

void DeviceManager::parseDeviceGroup(QDomElement element) {
    QString skip = element.attribute("skip", "false");
    if (skip.compare("false") == 0) {
        QDomNodeList children = element.childNodes();

        for (int iChild = 0; iChild < children.count(); iChild++) {
            QDomElement child = children.item(iChild).toElement();
            parseElement(child);
        }
    }
}

void DeviceManager::parseDevice(QDomElement element) {
    QString skip = element.attribute("skip", "false");
    if (skip.compare("false") == 0) {
        QString type = element.attribute("type");
        std::vector<Device*> devices = _deviceFactories[type.toStdString()]->createFromDomElement(element);
        this->add(devices);
    }
}

//public

DeviceManager::DeviceManager() : Manager() {
    _channelManager = new channel::ChannelManager;
}

DeviceManager::DeviceManager(std::vector<Device*> items) : Manager(items) {
    _channelManager = new channel::ChannelManager;
}

void DeviceManager::onAdd(Device* item) {
    _channelManager->add(item->getChannelManager()->list());
}

void DeviceManager::onRemove(Device* item) {
    _channelManager->remove(item->getChannelManager()->list());
}

void DeviceManager::enable() {
    std::vector<Device*> devices = list();
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        (*iDevice)->enable();
    }
}

void DeviceManager::disable() {
    std::vector<Device*> devices = list();
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        (*iDevice)->disable();
    }
}

void DeviceManager::loadFromFile(std::string path) {
    QFile* file = new QFile(QString::fromStdString(path));
    QDomDocument doc("mydocument");
    doc.setContent(file);
    parseElement(doc.documentElement());
}

void DeviceManager::registerDeviceFactory(DeviceFactory* deviceFactory) {
    _deviceFactories[deviceFactory->getName()] = deviceFactory;
}

void DeviceManager::unregisterDeviceFactory(DeviceFactory* deviceFactory) {
    _deviceFactories.erase(deviceFactory->getName());
}

channel::ChannelManager* DeviceManager::getChannelManager() {
    return _channelManager;
}

}
}
