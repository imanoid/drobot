#include "tactilesensorboard.h"
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace tactile {

TactileSensorBoard::TactileSensorBoard(std::string name) : DeviceBoard(name) {
}

std::vector<TactileSensor*> TactileSensorBoard::getTactileSensors() {
    return util::castVector<Device*, TactileSensor*>(list());
}

TactileSensor* TactileSensorBoard::getTactileSensor(std::string name) {
    return dynamic_cast<TactileSensor*>(get(name));
}

}
}
}

