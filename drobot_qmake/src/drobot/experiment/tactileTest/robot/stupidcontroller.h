#ifndef DROBOT_EXPERIMENT_ROBOT_STUPIDCONTROLLER_H
#define DROBOT_EXPERIMENT_ROBOT_STUPIDCONTROLLER_H

#include "../../../robot/controller.h""

namespace drobot {
namespace experiment {
namespace robot {

class StupidController : public drobot::robot::Controller
{
public:
    virtual void step(long tick, std::vector<device::channel::Channel*> inputChannels, std::vector<device::channel::Channel*> outputChannel) = 0;
};

} // namespace robot
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_ROBOT_STUPIDCONTROLLER_H
