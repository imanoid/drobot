#include "actuatorboard.h"
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace actuator {

ActuatorBoard::ActuatorBoard(std::string name) : DeviceBoard(name) {
}

const std::vector<Actuator*> ActuatorBoard::getActuators() const {
    return drobot::util::castVector<Device*, Actuator*>(getDevices());
}

Actuator* ActuatorBoard::getActuator(std::string name) const {
    return dynamic_cast<Actuator*>(getDevice(name));
}

}
}
}
