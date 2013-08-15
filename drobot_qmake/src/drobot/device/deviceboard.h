#ifndef DROBOT_DEVICE_DEVICEBOARD_H
#define DROBOT_DEVICE_DEVICEBOARD_H

#include "device.h"
#include "devicemanager.h"

namespace drobot {
namespace device {

class DeviceBoard : public Device , public DeviceManager
{
private:
    std::vector<Device*> _devices;
    bool _enabled;
public:
    DeviceBoard(std::string name);
    virtual void initChannels();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
};

} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_DEVICEBOARD_H
