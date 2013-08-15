#ifndef DROBOT_ROBOT_CONTROLLER_H
#define DROBOT_ROBOT_CONTROLLER_H

#include <vector>
#include "../device/channel/channel.h"

namespace drobot {
namespace robot {

class Robot;

class Controller
{
private:
    Robot* _robot;
public:
    virtual void step(long tick, std::vector<device::channel::Channel*> inputChannels, std::vector<device::channel::Channel*> outputChannel) = 0;
    void setRobot(Robot* robot);
    Robot* getRobot();
};

} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_CONTROLLER_H
