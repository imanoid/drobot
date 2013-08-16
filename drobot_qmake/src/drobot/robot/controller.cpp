#include "controller.h"

namespace drobot {
namespace robot {

Controller::Controller(std::string name) : Device(name) {
    _robot = 0;
    _enabled = false;
}

void Controller::setRobot(Robot* robot) {
    _robot = robot;
}

Robot* Controller::getRobot() {
    return _robot;
}

void Controller::enable() {
    _enabled = true;
}

void Controller::disable() {
    _enabled = false;
}

bool Controller::isEnabled() {
    return _enabled;
}

} // namespace robot
} // namespace drobot
