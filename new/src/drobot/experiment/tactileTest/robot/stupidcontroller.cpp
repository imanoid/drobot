#include "stupidcontroller.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace robot {

StupidController::StupidController(std::string name) : Controller(name) {
    _enabled = false;
}

void StupidController::step(long tick, device::channel::ChannelManager* channels) {
    double newPos = channels->get("LeftHandTactileSensor_value")->getNormalizedValue();
    channels->get("NeckServo_position")->setNormalizedValue(newPos);
    channels->get("LeftEyeServo0_position")->setNormalizedValue(newPos);
    channels->get("LeftEyeServo1_position")->setNormalizedValue(newPos);
}

} // namespace robot
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
