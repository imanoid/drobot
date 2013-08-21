#ifndef DROBOT_DEVICE_DEVICE_H
#define DROBOT_DEVICE_DEVICE_H

#include <string>
#include <vector>
#include <map>
#include "channel/channelmanager.h"
#include "../object/item.h"

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
namespace vision {
    class Vision;
}

class DeviceBoard;

class Device : public object::Item {
private:
    DeviceBoard* _deviceBoard;
    channel::ChannelManager* _channelManager;
public:
    Device(std::string name);
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual bool isEnabled() = 0;
    DeviceBoard* getDeviceBoard();
    void setDeviceBoard(DeviceBoard* deviceBoard);
    Device* toDevice();
    actuator::Actuator* toActuator();
    tactile::TactileSensor* toTactileSensor();
    vestibular::Vestibular* toVestibular();
    vision::Vision* toVision();
    virtual channel::ChannelManager* getChannels();
};

}
}

#endif // DEVICE_H
