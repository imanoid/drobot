#include "phidgetvestibularfactory.h"
#include "phidgetvestibular.h"
#include <phidget21.h>
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace vestibular {

std::vector<Device*> PhidgetVestibularFactory::createFromDomElement(QDomElement element) {
    std::vector<Device*> devices;

    int serial = element.attribute("serial").toInt();
    std::string name = element.attribute("name").toStdString();
    bool enabled = element.attribute("enabled").compare("true") == 0;

    PhidgetVestibular* device = new PhidgetVestibular(name, serial);
    if (enabled)
        device->enable();
    devices.push_back(device);

    return devices;
}

} // namespace vestibular
} // namespace device
} // namespace drobot
