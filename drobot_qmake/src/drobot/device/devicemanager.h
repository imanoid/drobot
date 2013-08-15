#ifndef _DROBOT_DEVICE_DEVICEMANAGER_H_
#define _DROBOT_DEVICE_DEVICEMANAGER_H_

#include <string>
#include <map>
#include <vector>
#include "device.h"
#include "devicefactory.h"
#include <QtXml/QDomElement>
#include "channel/channelmanager.h"

namespace drobot {
namespace device {

class DeviceManager : public channel::ChannelManager
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
    bool addDevice(Device* device);
    void addDevices(std::vector<Device*> devices);
    bool removeDevice(std::string name);
    bool removeDevice(Device* device);
    void removeDevices(std::vector<Device*> devices);
    bool hasDevice(std::string name);
    bool hasDevice(Device* device);
    void clearDevices();
    void loadFromFile(std::string path);
    void registerDeviceFactory(DeviceFactory* deviceFactory);
    void unregisterDeviceFactory(DeviceFactory* deviceFactory);
};

}
}

#endif // DEVICEMANAGER_H
