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
        this->addDevices(devices);
    }
}

//public
std::vector<Device*> DeviceManager::getDevices() {
    std::vector<Device*> devices;

    for (std::map<std::string, Device*>::iterator iDevice = _devices.begin(); iDevice != _devices.end(); iDevice++) {
        devices.push_back(iDevice->second);
    }

    return devices;
}

Device* DeviceManager::getDevice(std::string name) {
    std::map<std::string, Device*>::iterator dev = _devices.find(name);
    if (dev == _devices.end())
        return 0;
    else
        return dev->second;
}

bool DeviceManager::addDevice(Device* device) {
    if (!hasDevice(device->getName())) {
        _devices[device->getName()] = device;
        addInputChannels(device->getInputChannels());
        addOutputChannels(device->getOutputChannels());
        return true;
    } else {
        return false;
    }
}

void DeviceManager::addDevices(std::vector<Device *> devices) {
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        addDevice(*iDevice);
    }
}

bool DeviceManager::removeDevice(std::string name) {
    if (hasDevice(name)) {
        Device* dev = _devices[name];
        _devices.erase(name);
        removeInputChannels(dev->getInputChannels());
        removeOutputChannels(dev->getOutputChannels());
        return true;
    } else {
        return false;
    }
}

bool DeviceManager::removeDevice(Device* device) {
    removeDevice(device->getName());
}

void DeviceManager::removeDevices(std::vector<Device*> devices) {
    for (std::vector<Device*>::iterator iDevice = devices.begin(); iDevice != devices.end(); iDevice++) {
        removeDevice((*iDevice)->getName());
    }
}

bool DeviceManager::hasDevice(std::string name) {
    return _devices.find(name) != _devices.end();
}

bool DeviceManager::hasDevice(Device* device) {
    return hasDevice(device->getName());
}

void DeviceManager::clearDevices() {
    _devices.clear();
    clearInputChannels();
    clearOutputChannels();
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

}
}
