#ifndef DROBOT_EXPERIMENT_ROBOT_STUPIDCONTROLLER_H
#define DROBOT_EXPERIMENT_ROBOT_STUPIDCONTROLLER_H

#include "../../../robot/controller.h""

namespace drobot {
namespace experiment {
namespace robot {

class StupidController : public drobot::robot::Controller
{
public:
    virtual std::map<device::channel::Channel*, double> step(long tick, std::map<device::channel::Channel*, double> inputs);
};

} // namespace robot
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_ROBOT_STUPIDCONTROLLER_H
