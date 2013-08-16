#ifndef DROBOT_ROBOT_ROBOT_H
#define DROBOT_ROBOT_ROBOT_H

#include "../event/eventmanager.h"
#include "../device/devicemanager.h"
#include "../program/runnable.h"
#include "controller.h"
#include "../util/clock.h"

namespace drobot {
namespace robot {

class Robot : public program::Runnable
{
private:
    device::DeviceManager* _deviceManager;
    Controller* _controller;
    event::EventManager* _eventManager;
    util::Clock* _clock;
public:
    Robot();
    Robot(device::DeviceManager* deviceManager, Controller* controller, event::EventManager* eventManager, util::Clock* clock);
    virtual void run();
    void setDeviceManager(device::DeviceManager* deviceManager);
    device::DeviceManager* getDeviceManager();
    void setController(Controller* controller);
    Controller* getController();
    void setEventManager(drobot::event::EventManager* eventManager);
    drobot::event::EventManager* getEventManager();
    void setClock(util::Clock* clock);
    util::Clock* getClock();
};

} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_ROBOT_H
