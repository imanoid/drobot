#ifndef DROBOT_DEVICE_DEVICE_H
#define DROBOT_DEVICE_DEVICE_H

#include <string>
#include <vector>
#include <map>
#include "channel/channelmanager.h"

namespace drobot {
namespace device {
namespace actuator {
    class Actuator;
}
namespace tactile {
    class TactileSensor;
}
namespace vestibular {
    class Vestibular;
}

class DeviceBoard;

class Device : public channel::ChannelManager
{
private:
    std::string _name;
    DeviceBoard* _deviceBoard;
public:
    Device(std::string name);
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual bool isEnabled() = 0;
    virtual void initChannels() = 0;
    DeviceBoard* getDeviceBoard();
    void setDeviceBoard(DeviceBoard* deviceBoard);
    std::string getName();
    void setName(std::string name);
    actuator::Actuator* toActuator();
    tactile::TactileSensor* toTactileSensor();
    vestibular::Vestibular* toVestibular();
};

}
}

#endif // DEVICE_H
