#include "phidgetadvancedservofactory.h"
#include "phidgetadvancedboard.h"
#include "../devicemanager.h"
#include "../../robot/robot.h"
#include <sstream>
#include "channel/actuatorpositionchannelfactory.h"

namespace drobot {
namespace device {
namespace actuator {

PhidgetAdvancedServoFactory::PhidgetAdvancedServoFactory() : DeviceFactory("device:phidgetAdvancedServo") {
    _channelFactories->add(new channel::ActuatorPositionChannelFactory());
}

void PhidgetAdvancedServoFactory::createFromDomElement(QDomElement element, robot::Robot* robot) {
    DeviceManager* devices = robot->getDeviceManager();
    int serial = element.attribute("serial").toInt();
    std::string name = element.attribute("name").toStdString();
    bool enabled = element.attribute("enabled", "true").compare("true") == 0;
    int index = element.attribute("index").toInt();

    std::stringstream boardName;
    boardName << "PhidgetAdvancedBoard:" << serial;

    PhidgetAdvancedBoard* board;

    object::Manager<DeviceBoard>* boards = devices->getDeviceBoards();
    if (boards->has(boardName.str())) {
        board = dynamic_cast<PhidgetAdvancedBoard*>(boards->get(boardName.str()));
    } else {
        board = new PhidgetAdvancedBoard(boardName.str(), serial);
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
