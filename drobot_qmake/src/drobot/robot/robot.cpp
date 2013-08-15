#include "robot.h"
#include "event/stepevent.h"

namespace drobot {
namespace robot {

Robot::Robot()
{
}

Robot::Robot(device::DeviceManager* deviceManager, Controller* controller, drobot::event::EventManager* eventManager) {
    setDeviceManager(deviceManager);
    setController(controller);
    setEventManager(eventManager);
}

void Robot::run() {
    if (_running)
        return;
    _running = true;

    std::vector<device::channel::Channel*> inputChannels;
    std::vector<device::channel::Channel*> outputChannels;

    long tick = 0;
    while (_running) {
        _controller->step(tick, inputChannels, outputChannels);
        _eventManager->fireEvent(new event::StepEvent(tick, _deviceManager->getInputChannels(), _deviceManager->getOutputChannels()));
        tick++;
    }
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

void Robot::setEventManager(drobot::event::EventManager* eventManager) {
    _eventManager = eventManager;
}

drobot::event::EventManager* Robot::getEventManager() {
    return _eventManager;
}

} // namespace robot
} // namespace drobot
