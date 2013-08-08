#ifndef _DROBOT_DEVICE_DEVICEMANAGER_H_
#define _DROBOT_DEVICE_DEVICEMANAGER_H_

#include <string>
#include <map>
#include <vector>
#include "device.h"
#include "devicefactory.h"
#include <QtXml/QDomElement>

namespace drobot {
namespace device {

class DeviceManager
{
private:
    std::map<std::string, Device*> _devices;
    std::map<std::string, DeviceFactory*> _deviceFactories;

    void parseElement(QDomElement element);
    void parseDeviceGroup(QDomElement element);
    void parseDevice(QDomElement element);
public:
    std::vector<Device*> getDevices();
    Device* getDevice(std::string name);
    void addDevice(Device* device);
    void addDevices(std::vector<Device*> devices);
    void loadFromFile(std::string path);
    void registerDeviceFactory(DeviceFactory* deviceFactory);
    void unregisterDeviceFactory(DeviceFactory* deviceFactory);
};

}
}

#endif // DEVICEMANAGER_H
