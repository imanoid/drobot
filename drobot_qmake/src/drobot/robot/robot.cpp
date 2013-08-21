#include "robot.h"
#include "event/stepevent.h"
#include <unistd.h>
#include <iostream>

namespace drobot {
namespace robot {

Robot::Robot()
{
}

Robot::Robot(device::DeviceManager* deviceManager, Controller* controller, drobot::event::EventManager* eventManager, util::Clock* clock) {
    setDeviceManager(deviceManager);
    setController(controller);
    setEventManager(eventManager);
    setClock(clock);
}

void Robot::run() {
    if (_running)
        return;
    _clock->init();
    _running = true;

    long tick = 0;
    device::channel::ChannelManager* channels = _deviceManager->getChannels();

    while (_running) {
        channels->read();
        _controller->step(tick, channels);
        channels->write();
        _eventManager->fireEvent(new event::StepEvent(tick, channels->list()));
        tick++;
        _clock->waitForTick();
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
    _controller->setRobot(this);
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

void Robot::setClock(util::Clock *clock) {
    _clock = clock;
}

util::Clock* Robot::getClock() {
    return _clock;
}

} // namespace robot
} // namespace drobot
