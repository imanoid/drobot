#include "stupidcontroller.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace robot {

StupidController::StupidController(std::string name) : Controller(name) {
    _enabled = false;
}

void StupidController::tick(long tick) {
}

} // namespace robot
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
