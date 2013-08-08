#include "devicemanager.h"
#include <QFile>
#include <QtXml/QDomDocument>
#include <iostream>

namespace drobot {
namespace device {

std::vector<Device*> DeviceManager::getDevices() {
    std::vector<Device*> devices;

    for (std::map<std::string, Device*>::iterator iDevice = _devices.begin(); iDevice != _devices.end(); iDevice++) {
        devices.push_back(iDevice->second);
    }

    return devices;
}

Device* DeviceManager::getDevice(std::string name) {
    return _devices[name];
}

void DeviceManager::addDevice(Device* device) {
    _devices[device->getName()] = device;
}

void DeviceManager::addDevices(std::vector<Device *> devices) {
    for (int iDevice = 0; iDevice < devices.size(); iDevice++) {
        addDevice(devices[iDevice]);
    }
}

void DeviceManager::loadFromFile(std::string path) {
    QFile* file = new QFile(QString::fromStdString(path));
    QDomDocument doc("mydocument");
    doc.setContent(file);
    parseElement(doc.documentElement());
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
        this->addDevices(devices);
    }
}

void DeviceManager::parseElement(QDomElement element) {
    QString name = element.tagName();
    if (name.compare("deviceGroup") == 0) {
        parseDeviceGroup(element);
    }
}
void DeviceManager::registerDeviceFactory(DeviceFactory* deviceFactory) {
    _deviceFactories[deviceFactory->getName()] = deviceFactory;
}

void DeviceManager::unregisterDeviceFactory(DeviceFactory* deviceFactory) {
    _deviceFactories.erase(deviceFactory->getName());
}

}
}
