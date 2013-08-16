#ifndef _DROBOT_DEVICE_DEVICEMANAGER_H_
#define _DROBOT_DEVICE_DEVICEMANAGER_H_

#include <string>
#include <map>
#include <vector>
#include "device.h"
#include "devicefactory.h"
#include "channel/channelmanager.h"
#include <QtXml/QDomElement>
#include "../object/manager.h"

namespace drobot {
namespace device {

class DeviceManager : public object::Manager<Device>
{
private:
    std::map<std::string, DeviceFactory*> _deviceFactories;

    channel::ChannelManager* _channelManager;

    void parseElement(QDomElement element);
    void parseDeviceGroup(QDomElement element);
    void parseDevice(QDomElement element);
public:
    DeviceManager();
    DeviceManager(std::vector<Device*> items);
    virtual void onAdd(Device* item);
    virtual void onRemove(Device* item);

    void enable();
    void disable();

    void loadFromFile(std::string path);
    void registerDeviceFactory(DeviceFactory* deviceFactory);
    void unregisterDeviceFactory(DeviceFactory* deviceFactory);
    virtual channel::ChannelManager* getChannelManager();
};

}
}

#endif // DEVICEMANAGER_H
