#ifndef DROBOT_DEVICE_DEVICEBOARD_H
#define DROBOT_DEVICE_DEVICEBOARD_H

#include "device.h"
#include "devicemanager.h"

namespace drobot {
namespace device {

/**
 * @brief Represents a board with devices plugged into it
 * @details This class should be used as a base class for Phidget boards etc. It can be treated as a device and also as a device manager.
 *  it also contains all the channels of the devices.
 */
class DeviceBoard : public Device , public DeviceManager
{
private:
    /**
     * @brief flag indicating whether it is enabled or not
     */
    bool _enabled;
public:
    DeviceBoard(std::string name);
    virtual ~DeviceBoard();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
    /**
     * @brief this method is called every time a device is added.
     *  It automatically adds the devices channels to the channel::ChannelManager and sets the reverse dependency on the device to this.
     * @param item
     */
    virtual void onAdd(Device *item);
    /**
     * @brief this method is called every time a device is removed.
     *  It automatically removes the devices channels from the channel::ChannelManager and sets the reverse dependency on the device to 0.
     * @param item
     */
    virtual void onRemove(Device *item);
    /**
     * @return the channels of the Devices.
     */
    virtual channel::ChannelManager* getChannels();
};

} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_DEVICEBOARD_H
