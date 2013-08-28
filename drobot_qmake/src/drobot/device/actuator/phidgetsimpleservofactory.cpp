#include "phidgetsimpleservofactory.h"
#include "phidgetsimpleboard.h"
#include "../devicemanager.h"
#include "../../robot/robot.h"
#include "channel/actuatorpositionchannelfactory.h"
#include <sstream>

namespace drobot {
namespace device {
namespace actuator {

PhidgetSimpleServoFactory::PhidgetSimpleServoFactory() : DeviceFactory("device:phidgetSimpleServo") {
    _channelFactories->add(new channel::ActuatorPositionChannelFactory());
}

void PhidgetSimpleServoFactory::createFromDomElement(QDomElement element, robot::Robot* robot) {
    DeviceManager* devices = robot->getDeviceManager();
    int serial = element.attribute("serial").toInt();
    std::string name = element.attribute("name").toStdString();
    bool enabled = element.attribute("enabled", "true").compare("true") == 0;
    int index = element.attribute("index").toInt();

    std::stringstream boardName;
    boardName << "PhidgetSimpleBoard:" << serial;

    PhidgetSimpleBoard* board;

    object::Manager<DeviceBoard>* boards = devices->getDeviceBoards();
    if (boards->has(boardName.str())) {
        board = dynamic_cast<PhidgetSimpleBoard*>(boards->get(boardName.str()));
    } else {
        board = new PhidgetSimpleBoard(boardName.str(), serial);
        boards->add(board);
    }

    Device* device = board->initActuator(index, name);
    if (element.hasChildNodes()) {
        QDomNodeList children = element.childNodes();
        for (int i = 0; i < children.count(); i++) {
            QDomElement child = children.item(i).toElement();
            _channelFactories->get(child.nodeName().toStdString())->createFromDomElement(child, device);
        }
    }
    if (enabled)
        device->enable();

    devices->add(device);
}

} // namespace actuator
} // namespace device
} // namespace drobot
