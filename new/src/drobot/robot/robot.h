#ifndef DROBOT_ROBOT_ROBOT_H
#define DROBOT_ROBOT_ROBOT_H

#include "../event/eventmanager.h"
#include "../device/devicemanager.h"
#include "../device/devicefactory.h"
#include "../program/runnable.h"
#include "controller.h"
#include "../util/clock.h"

namespace drobot {
namespace robot {

class Robot : public program::Runnable
{
private:
    /**
     * @brief _deviceManager contains all devices which make this robot
     */
    device::DeviceManager* _deviceManager;
    /**
     * @brief _controller controls this robot
     */
    Controller* _controller;
    /**
     * @brief _eventManager is the EventManager of this robot
     */
    event::EventManager* _eventManager;
    /**
     * @brief _clock influences the tick frequency of this robot
     */
    util::Clock* _clock;
    object::Manager<device::DeviceFactory>* _deviceFactories;
    void parseElement(QDomElement element);
    void parseDeviceGroup(QDomElement element);
    void parseDevice(QDomElement element);
    void initDeviceFactories();
public:
    Robot();
    Robot(device::DeviceManager* deviceManager, Controller* controller, event::EventManager* eventManager, util::Clock* clock);
    virtual ~Robot();
    virtual void run();
    void setDeviceManager(device::DeviceManager* deviceManager);
    device::DeviceManager* getDeviceManager();
    void setController(Controller* controller);
    Controller* getController();
    void setEventManager(drobot::event::EventManager* eventManager);
    drobot::event::EventManager* getEventManager();
    void setClock(util::Clock* clock);
    util::Clock* getClock();
    /**
     * @brief parse robot from xml file
     * @param path
     */
    void loadFromFile(std::string path);
    /**
     * @brief returns DeviceFactories used for parsing files
     * @return DeviceFactories
     */
    object::Manager<device::DeviceFactory>* getDeviceFactories();
};

} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_ROBOT_H
