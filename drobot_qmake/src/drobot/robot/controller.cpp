#include "controller.h"

namespace drobot {
namespace robot {

void Controller::setRobot(Robot* robot) {
    _robot = robot;
}

Robot* Controller::getRobot() const {
    return _robot;
}

} // namespace robot
} // namespace drobot
