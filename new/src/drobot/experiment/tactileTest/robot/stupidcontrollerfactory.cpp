#include "stupidcontrollerfactory.h"
#include "stupidcontroller.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace robot {

StupidControllerFactory::StupidControllerFactory() : DeviceFactory("controller:stupidController") {
}

void StupidControllerFactory::createFromDomElement(QDomElement element, drobot::robot::Robot *robot) {
    std::string name = element.attribute("name").toStdString();

    drobot::robot::Controller* controller = new StupidController(name);
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
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
