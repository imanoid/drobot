#ifndef DROBOT_ROBOT_CONTROLLER_H
#define DROBOT_ROBOT_CONTROLLER_H

#include "../device/channel/channel.h"
#include <map>

namespace drobot {
namespace robot {

class Robot;

class Controller
{
private:
    Robot* _robot;
public:
    virtual std::map<device::channel::Channel*, double> step(long tick, std::map<device::channel::Channel*, double> inputs) = 0;
    void setRobot(Robot* robot);
    Robot* getRobot();
};

} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_CONTROLLER_H
