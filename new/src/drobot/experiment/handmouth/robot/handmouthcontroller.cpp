#include <iostream>

#include "handmouthcontroller.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace robot {

HandMouthController::HandMouthController(std::string name) : Controller(name)
{
    _enabled = false;
}

void HandMouthController::tick(long tick __maybe_unused)
{
    drobot::device::channel::ChannelManager* channels = getRobot()->getDeviceManager()->getChannels();

    std::cout << "HandMouthController tick" << std::endl;
}

} // namespace robot
} // namespace handmouth
} // namespace experiment
} // namespace drobot
