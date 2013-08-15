#include "stupidcontroller.h"

namespace drobot {
namespace experiment {
namespace robot {

std::map<device::channel::Channel*, double> StupidController::step(long tick, std::map<device::channel::Channel*, double> inputs) {
    return std::map<device::channel::Channel*, double>();
}

} // namespace robot
} // namespace experiment
} // namespace drobot
