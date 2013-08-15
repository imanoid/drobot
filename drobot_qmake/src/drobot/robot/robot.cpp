#include "robot.h"

namespace drobot {
namespace robot {

Robot::Robot()
{
}

Robot::Robot(device::DeviceManager* deviceManager, Controller* controller, event::EventManager* eventManager) {
    setDeviceManager(deviceManager);
    setController(controller);
    setEventManager(eventManager);
}

void Robot::start() {

}

void Robot::start_thread() {

}

void Robot::stop() {
    _running = false;
}

void Robot::setDeviceManager(device::DeviceManager* deviceManager) {
    _deviceManager = deviceManager;
}

device::DeviceManager* Robot::getDeviceManager() {
    return _deviceManager;
}

void Robot::setController(Controller* controller) {
    _controller = controller;
}

Controller* Robot::getController() {
    return _controller;
}

void Robot::setEventManager(event::EventManager* eventManager) {
    _eventManager = eventManager;
}

event::EventManager* Robot::getEventManager() {
    return _eventManager;
}

} // namespace robot
} // namespace drobot
