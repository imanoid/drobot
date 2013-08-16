#include "stupidcontroller.h"

namespace drobot {
namespace experiment {
namespace robot {

StupidController::StupidController(std::string name) : Controller(name) {
    _enabled = false;
}

void StupidController::step(long tick, device::channel::ChannelManager* channels) {

}

void StupidController::initChannels() {

}

} // namespace robot
} // namespace experiment
} // namespace drobot
