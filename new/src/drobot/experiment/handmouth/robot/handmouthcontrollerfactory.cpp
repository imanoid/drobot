#include "handmouthcontrollerfactory.h"
#include "handmouthcontroller.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace robot {

HandMouthControllerFactory::HandMouthControllerFactory() : DeviceFactory("controller:handMouthController") {
}

void HandMouthControllerFactory::createFromDomElement(QDomElement element, drobot::robot::Robot *robot) {
    std::string name = element.attribute("name").toStdString();

    drobot::robot::Controller* controller = new HandMouthController(name);
    if (element.hasChildNodes()) {
        QDomNodeList children = element.childNodes();
        for (int i = 0; i < children.count(); i++) {
            QDomElement child = children.item(i).toElement();
            _channelFactories->get(child.nodeName().toStdString())->createFromDomElement(child, controller);
        }
    }
    robot->setController(controller);
}

} // namespace robot
} // namespace handmouth
} // namespace experiment
} // namespace drobot
