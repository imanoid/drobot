#include "robot.h"
#include "event/stepevent.h"
#include <unistd.h>
#include <iostream>

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

    long tick = 0;
    while (_running) {
        std::map<device::channel::Channel*, double> inputs = _deviceManager->getInputs();
        std::cout << inputs.size() << std::endl;
        std::cout << inputs.begin()->first->getName() << " " << inputs.begin()->second << std::endl;
        std::map<device::channel::Channel*, double> outputs = _controller->step(tick, inputs);
        _deviceManager->setOutputs(outputs);
        _eventManager->fireEvent(new event::StepEvent(tick, inputs, outputs));
        tick++;
        usleep(20000);
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
