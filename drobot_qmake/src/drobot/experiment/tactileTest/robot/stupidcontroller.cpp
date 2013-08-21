#include "stupidcontroller.h"

namespace drobot {
namespace experiment {
namespace robot {

StupidController::StupidController(std::string name) : Controller(name) {
    _enabled = false;
}

void StupidController::step(long tick, device::channel::ChannelManager* channels) {
    double newPos = channels->get("LeftHandTactileSensor_value")->getNormalizedValue();
    channels->get("NeckServo_position")->setNormalizedValue(newPos);
}

void StupidController::initChannels() {

}

} // namespace robot
} // namespace experiment
} // namespace drobot
