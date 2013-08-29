#include "actuatorboard.h"
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace actuator {

ActuatorBoard::ActuatorBoard(std::string name) : DeviceBoard(name) {
}

std::vector<Actuator*> ActuatorBoard::getActuators() {
    return drobot::util::castVector<Device*, Actuator*>(values());
}

Actuator* ActuatorBoard::getActuator(std::string name) {
    return dynamic_cast<Actuator*>(get(name));
}

}
}
}
