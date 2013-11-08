#ifndef DROBOT_EXPERIMENT_DEMO_ROBOT_DEMOCONTROLLER_H
#define DROBOT_EXPERIMENT_DEMO_ROBOT_DEMOCONTROLLER_H

#include "../../../robot/controller.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace robot {

class DemoController : public drobot::robot::Controller {
public:
    DemoController(std::string name);
    virtual void tick(long tick);
};

} // namespace robot
} // namespace demo
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_DEMO_ROBOT_DEMOCONTROLLER_H
