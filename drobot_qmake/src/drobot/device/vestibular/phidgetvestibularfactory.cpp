#include "phidgetvestibularfactory.h"
#include "phidgetvestibular.h"
#include <phidget21.h>
#include "../../util/util.h"
#include "../devicemanager.h"

namespace drobot {
namespace device {
namespace vestibular {

PhidgetVestibularFactory::PhidgetVestibularFactory() : DeviceFactory("device:phidgetVestibular") {
}

void PhidgetVestibularFactory::createFromDomElement(QDomElement element, DeviceManager* devices) {
    int serial = element.attribute("serial").toInt();
    std::string name = element.attribute("name").toStdString();
    bool enabled = element.attribute("enabled").compare("true") == 0;

    Device* device = new PhidgetVestibular(name, serial);
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

} // namespace vestibular
} // namespace device
} // namespace drobot
