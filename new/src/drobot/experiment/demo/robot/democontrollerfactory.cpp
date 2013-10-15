#include "democontrollerfactory.h"
#include "democontroller.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace robot {

DemoControllerFactory::DemoControllerFactory() : DeviceFactory("controller:demoController") {
}

void DemoControllerFactory::createFromDomElement(QDomElement element, drobot::robot::Robot *robot) {
    std::string name = element.attribute("name").toStdString();

    drobot::robot::Controller* controller = new DemoController(name);
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
} // namespace demo
} // namespace experiment
} // namespace drobot
