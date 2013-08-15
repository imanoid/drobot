#ifndef DROBOT_DEVICE_DEVICEBOARD_H
#define DROBOT_DEVICE_DEVICEBOARD_H

#include "device.h"

namespace drobot {
namespace device {

class DeviceBoard : public Device
{
private:
    std::vector<Device*> _devices;
    bool _enabled;
public:
    DeviceBoard(std::string name);
    virtual void initChannels();
    const std::vector<Device*> getDevices() const;
    bool addDevice(Device* device);
    bool removeDevice(std::string name);
    bool removeDevice(Device* device);
    Device* getDevice(std::string name) const;
    bool hasDevice(std::string name) const;
    bool hasDevice(Device* device) const;
    void clearDevices();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
};

} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_DEVICEBOARD_H
