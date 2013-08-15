#ifndef DROBOT_ROBOT_ROBOT_H
#define DROBOT_ROBOT_ROBOT_H

#include "../event/eventmanager.h"
#include "../device/devicemanager.h"
#include "controller.h"

namespace drobot {
namespace robot {

class Robot
{
private:
    device::DeviceManager* _deviceManager;
    Controller* _controller;
    event::EventManager* _eventManager;
public:
    Robot();
    void start();
    void start_thread();
    void stop();
    void setDeviceManager(device::DeviceManager* deviceManager);
    device::DeviceManager* getDeviceManager();
    void setController(Controller* controller);
    Controller* getController();
    void setEventManager(event::EventManager* eventManager);
    event::EventManager* getEventManager();
};

} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_ROBOT_H
