#include "robot.h"
#include "event/stepevent.h"
#include <unistd.h>
#include <iostream>
#include "../device/actuator/phidgetadvancedservofactory.h"
#include "../device/actuator/phidgetsimpleservofactory.h"
#include "../device/tactile/simpletactilesensorfactory.h"
#include "../device/vestibular/phidgetvestibularfactory.h"
#include "../experiment/tactileTest/robot/stupidcontrollerfactory.h"
#include <QFile>
#include <QDomDocument>
#include "../util/util.h"

namespace drobot {
namespace robot {

//private
void Robot::parseElement(QDomElement element) {
    QString name = element.tagName();
    if (name.compare("deviceGroup") == 0) {
        parseDeviceGroup(element);
    } else if (name.compare("devices") == 0) {
        QDomNodeList children = element.childNodes();
        for (int iChild = 0; iChild < children.count(); iChild++) {
            QDomElement child = children.item(iChild).toElement();
            parseElement(child);
        }
    } else if (name.startsWith("device:")) {
        parseDevice(element);
    } else if (name.startsWith("controller:")) {
        parseDevice(element);
    }
}

void Robot::parseDeviceGroup(QDomElement element) {
    QString skip = element.attribute("skip", "false");
    if (skip.compare("false") == 0) {
        QDomNodeList children = element.childNodes();

        for (int iChild = 0; iChild < children.count(); iChild++) {
            QDomElement child = children.item(iChild).toElement();
            parseElement(child);
        }
    }
}

void Robot::parseDevice(QDomElement element) {
    QString skip = element.attribute("skip", "false");
    if (skip.compare("false") == 0) {
        _deviceFactories->get(element.nodeName().toStdString())->createFromDomElement(element, this);
    }
}

void Robot::initDeviceFactories() {
    _deviceFactories = new object::Manager<device::DeviceFactory>();
    _deviceFactories->add(new drobot::experiment::tactileTest::robot::StupidControllerFactory());
    _deviceFactories->add(new device::actuator::PhidgetAdvancedServoFactory());
    _deviceFactories->add(new device::actuator::PhidgetSimpleServoFactory());
    _deviceFactories->add(new device::tactile::SimpleTactileSensorFactory());
    _deviceFactories->add(new device::vestibular::PhidgetVestibularFactory());
}

//public
Robot::Robot() {
    _deviceManager = new device::DeviceManager;
    _eventManager = new drobot::event::EventManager;
    _clock = new util::Clock;
    _controller = 0;
    initDeviceFactories();
}

Robot::Robot(device::DeviceManager* deviceManager, Controller* controller, drobot::event::EventManager* eventManager, util::Clock* clock) {
    _deviceManager = deviceManager;
    _controller = controller;
    _controller->setRobot(this);
    _eventManager = eventManager;
    _clock = clock;
    initDeviceFactories();
}

Robot::~Robot() {
    cancel();
    delete _deviceManager;
    delete _eventManager;
    delete _clock;
    delete _deviceFactories;
    std::cout << "robot deleted" << std::endl;
}

void Robot::run() {
    if (_running)
        return;
    _clock->init();
    _running = true;
    //enable all the devices
    _deviceManager->enable();

    long tick = 0;
    //get reference to all the channels
    device::channel::ChannelManager* channels = _deviceManager->getChannels();

    while (_running) {
        //wait for next timestep
        _clock->waitForTick();
        //copy device values to cache
        channels->read();
        //calculate outputs
        _controller->step(tick, channels);
        //copy device outputs from cache to devices
        channels->write();
        //fire step event (for logging)
        _eventManager->fireEvent(new event::StepEvent(tick, channels->values()));
        tick++;
    }
    //shutdown the robot's devices
    _deviceManager->disable();
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

void Robot::loadFromFile(std::string path) {
    QFile* file = new QFile(QString::fromStdString(path));
    QDomDocument doc("mydocument");
    doc.setContent(file);
    QDomElement rootElement = doc.documentElement();
    _clock->setFrequency(rootElement.attribute("frequency").toInt());

    QDomNodeList children = rootElement.childNodes();
    for (int i = 0; i < children.count(); i++) {
        parseElement(children.at(i).toElement());
    }
}

object::Manager<device::DeviceFactory>* Robot::getDeviceFactories() {
    return _deviceFactories;
}

} // namespace robot
} // namespace drobot