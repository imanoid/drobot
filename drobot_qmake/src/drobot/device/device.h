#ifndef DROBOT_DEVICE_DEVICE_H
#define DROBOT_DEVICE_DEVICE_H

#include <string>
#include <vector>
#include <map>
#include "channel/channel.h"

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

class Device
{
private:
    std::string _name;
    DeviceBoard* _deviceBoard;
    std::vector<channel::Channel*> _inputChannels;
    std::vector<channel::Channel*> _outputChannels;
public:
    Device(std::string name);
    bool addInputChannel(channel::Channel* channel);
    bool removeInputChannel(channel::Channel* channel);
    bool hasInputChannel(channel::Channel* channel);
    bool addOutputChannel(channel::Channel* channel);
    bool removeOutputChannel(channel::Channel* channel);
    bool hasOutputChannel(channel::Channel* channel);
    virtual void enable() = 0;
    virtual void disable() = 0;
    virtual bool isEnabled() = 0;
    virtual void initChannels() = 0;
    DeviceBoard* getDeviceBoard();
    void setDeviceBoard(DeviceBoard* deviceBoard);
    std::string getName();
    void setName(std::string name);
    const std::vector<channel::Channel*> getInputChannels() const;
    const std::vector<channel::Channel*> getOutputChannels() const;
    actuator::Actuator* toActuator();
    tactile::TactileSensor* toTactileSensor();
    vestibular::Vestibular* toVestibular();
};

}
}

#endif // DEVICE_H
