#ifndef DROBOT_ROBOT_CONTROLLER_H
#define DROBOT_ROBOT_CONTROLLER_H

#include "../device/channel/channelmanager.h"
#include <map>
#include "../device/device.h"

namespace drobot {
namespace robot {

class Robot;

class Controller : public device::Device
{
protected:
    Robot* _robot;
    bool _enabled;
public:
    Controller(std::string name);
    virtual void step(long tick, device::channel::ChannelManager* channels) = 0;
    void setRobot(Robot* robot);
    Robot* getRobot();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
};

} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_CONTROLLER_H
