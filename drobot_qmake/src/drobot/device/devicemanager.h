#ifndef DROBOT_DEVICE_DEVICEMANAGER_H
#define DROBOT_DEVICE_DEVICEMANAGER_H

#include <string>
#include <map>
#include <vector>
#include "device.h"
#include "devicefactory.h"
#include "channel/channelmanager.h"
#include <QtXml/QDomElement>
#include "../object/manager.h"
#include "actuator/phidgetadvancedservofactory.h"
#include "tactile/simpletactilesensorfactory.h"

namespace drobot {
namespace device {

class DeviceManager : public object::Manager<Device>
{
private:
    object::Manager<DeviceFactory>* _deviceFactories;
    channel::ChannelManager* _channels;
    object::Manager<DeviceBoard>* _deviceBoards;

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
    virtual channel::ChannelManager* getChannels();
    object::Manager<DeviceFactory>* getDeviceFactories();
    object::Manager<DeviceBoard>* getDeviceBoards();
};

}
}

#endif // DEVICEMANAGER_H
