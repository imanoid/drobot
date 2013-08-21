#include "simpletactilesensorfactory.h"
#include <sstream>
#include "../../object/manager.h"
#include "simpletactilesensor.h"
#include "simpletactilesensorboard.h"
#include "channel/tactilesensorvaluechannelfactory.h"

namespace drobot {
namespace device {
namespace tactile {

SimpleTactileSensorFactory::SimpleTactileSensorFactory() : DeviceFactory("device:simpleTactileSensor") {
    _channelFactories->add(new channel::TactileSensorValueChannelFactory());
}

void SimpleTactileSensorFactory::createFromDomElement(QDomElement element, DeviceManager *devices) {
    std::string path = element.attribute("path").toStdString();
    std::string name = element.attribute("name").toStdString();
    bool enabled = element.attribute("enabled", "true").compare("true") == 0;
    int index = element.attribute("index").toInt();

    std::stringstream boardName;
    boardName << "SimpleTactileSensor:" << path;

    SimpleTactileSensorBoard* board;

    object::Manager<DeviceBoard>* boards = devices->getDeviceBoards();
    if (boards->has(boardName.str())) {
        board = dynamic_cast<SimpleTactileSensorBoard*>(boards->get(boardName.str()));
    } else {
        board = new SimpleTactileSensorBoard(boardName.str(), path);
        boards->add(board);
    }

    Device* device = board->initSensor(index, name);
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

} // namespace tactile
} // namespace device
} // namespace drobot
