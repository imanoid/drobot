#include "phidgetadvancedboardfactory.h"
#include "phidgetadvancedboard.h"
#include "phidgetadvancedservo.h"
#include <phidget21.h>
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace actuator {

std::vector<Device*> PhidgetAdvancedBoardFactory::createFromDomElement(QDomElement element) {
    std::vector<Device*> devices;

    int serial = element.attribute("serial", "-1").toInt();
    std::string name = element.attribute("name").toStdString();
    bool useBoard = element.attribute("useBoard", "false").compare("true") == 0;
    bool enabled = element.attribute("enabled", "true").compare("true") == 0;

    PhidgetAdvancedBoard* phidgetBoard = new PhidgetAdvancedBoard(name, serial);

    if (enabled)
        phidgetBoard->enable();

    std::vector<Actuator*> actuators;
    if (!element.hasChildNodes()) {
        actuators = phidgetBoard->initAllActuators();
    } else {
        //TODO init child nodes
    }

    if (useBoard) {
        devices.push_back(phidgetBoard);
    } else {
        devices = drobot::util::castVector<Actuator*, Device*>(actuators);
    }

    return devices;
}

} // namespace actuator
} // namespace device
} // namespace drobot
