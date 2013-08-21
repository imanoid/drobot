#include "devicemanager.h"
#include <QFile>
#include <QtXml/QDomDocument>

namespace drobot {
namespace device {

//protected
void DeviceManager::parseElement(QDomElement element) {
    QString name = element.tagName();
    if (name.compare("deviceGroup") == 0) {
        parseDeviceGroup(element);
    } else if (name.startsWith("device")) {
        parseDevice(element);
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
        _deviceFactories->get(element.nodeName().toStdString())->createFromDomElement(element, this);
    }
}

//public
DeviceManager::DeviceManager() : Manager() {
    _channels = new channel::ChannelManager;
    _deviceBoards = new object::Manager<DeviceBoard>();
    _deviceFactories = new object::Manager<DeviceFactory>();
    _deviceFactories->add(new tactile::SimpleTactileSensorFactory());
    _deviceFactories->add(new actuator::PhidgetAdvancedServoFactory());
}

DeviceManager::DeviceManager(std::vector<Device*> items) : Manager(items) {
    _channels = new channel::ChannelManager;
}

void DeviceManager::onAdd(Device* item) {
    _channels->add(item->getChannels()->list());
}

void DeviceManager::onRemove(Device* item) {
    _channels->remove(item->getChannels()->list());
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
    QDomElement rootElement = doc.documentElement();
    QDomNodeList children = rootElement.childNodes();
    for (int i = 0; i < children.count(); i++) {
        parseElement(children.at(i).toElement());
    }
}

channel::ChannelManager* DeviceManager::getChannels() {
    return _channels;
}

object::Manager<DeviceFactory>* DeviceManager::getDeviceFactories() {
    return _deviceFactories;
}

object::Manager<DeviceBoard>*  DeviceManager::getDeviceBoards() {
    return _deviceBoards;
}

}
}
