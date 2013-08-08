#include "tactilesensorboard.h"
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace tactile {

const std::vector<TactileSensor*> TactileSensorBoard::getTactileSensors() const {
    return util::castVector<Device*, TactileSensor*>(getDevices());
}

TactileSensor* TactileSensorBoard::getTactileSensor(std::string name) const {
    return dynamic_cast<TactileSensor*>(getDevice(name));
}

}
}
}

