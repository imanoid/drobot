#ifndef DROBOT_DEVICE_DEVICEMANAGER_H
#define DROBOT_DEVICE_DEVICEMANAGER_H

#include <string>
#include <map>
#include <vector>
#include "device.h"
#include "channel/channelmanager.h"
#include <QtXml/QDomElement>
#include "../object/manager.h"

namespace drobot {
namespace device {

/**
 * @brief Special implementation of a Manager for Device Items.
 * @details Additionally to the normal Manager implementation it also knows about all the Channels and DeviceBoards of the devices.
 */
class DeviceManager : public object::Manager<Device>
{
private:
    channel::ChannelManager* _channels;
    object::Manager<DeviceBoard>* _deviceBoards;
public:
    DeviceManager();
    DeviceManager(std::vector<Device*> items);
    virtual ~DeviceManager();
    virtual void onAdd(Device* item);
    virtual void onRemove(Device* item);

    /**
     * @brief enable all devices
     */
    void enable();
    /**
     * @brief disable all devices
     */
    void disable();
    virtual channel::ChannelManager* getChannels();
    object::Manager<DeviceBoard>* getDeviceBoards();
};

}
}

#endif // DEVICEMANAGER_H
