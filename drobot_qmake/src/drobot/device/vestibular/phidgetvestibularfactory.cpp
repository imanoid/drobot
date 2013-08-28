#include "phidgetvestibularfactory.h"
#include "phidgetvestibular.h"
#include <phidget21.h>
#include "../../util/util.h"
#include "../devicemanager.h"
#include "../../robot/robot.h"
#include "channel/vestibularaccelerationchannelfactory.h"
#include "channel/vestibularangularratechannelfactory.h"
#include "channel/vestibularmagneticfieldchannelfactory.h"

namespace drobot {
namespace device {
namespace vestibular {

PhidgetVestibularFactory::PhidgetVestibularFactory() : DeviceFactory("device:phidgetVestibular") {
    _channelFactories->add(new channel::VestibularAccelerationChannelFactory);
    _channelFactories->add(new channel::VestibularAngularRateChannelFactory);
    _channelFactories->add(new channel::VestibularMagneticFieldChannelFactory);
}

void PhidgetVestibularFactory::createFromDomElement(QDomElement element, robot::Robot* robot) {
    DeviceManager* devices = robot->getDeviceManager();
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
