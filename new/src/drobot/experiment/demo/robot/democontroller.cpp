#include "democontroller.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace robot {

DemoController::DemoController(std::string name) : Controller(name) {
    _enabled = false;
}

void DemoController::tick(long tick, device::channel::ChannelManager* channels) {
}

} // namespace robot
} // namespace demo
} // namespace experiment
} // namespace drobot
