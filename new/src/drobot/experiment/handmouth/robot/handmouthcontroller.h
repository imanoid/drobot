#ifndef DROBOT_EXPERIMENT_HANDMOUTH_ROBOT_HANDMOUTHCONTROLLER_H
#define DROBOT_EXPERIMENT_HANDMOUTH_ROBOT_HANDMOUTHCONTROLLER_H

#include "../../../robot/controller.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace robot {

class HandMouthController : public drobot::robot::Controller {
public:
    HandMouthController(std::string name);
    virtual void tick(long tick);
};

} // namespace robot
} // namespace handmouth
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_HANDMOUTH_ROBOT_HANDMOUTHCONTROLLER_H


