#ifndef DROBOT_EXPERIMENT_TACTILETEST_ROBOT_STUPIDCONTROLLER_H
#define DROBOT_EXPERIMENT_TACTILETEST_ROBOT_STUPIDCONTROLLER_H

#include "../../../robot/controller.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace robot {

class StupidController : public drobot::robot::Controller {
public:
    StupidController(std::string name);
    virtual void step(long tick, device::channel::ChannelManager* channels);
};

} // namespace robot
} // namespace tactileTest
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_ROBOT_STUPIDCONTROLLER_H
