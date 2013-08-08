#include "simpletactilesensorboardfactory.h"
#include "simpletactilesensor.h"
#include "simpletactilesensorboard.h"
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace tactile {

std::vector<Device*> SimpleTactileSensorBoardFactory::createFromDomElement(QDomElement element) {
    std::vector<Device*> devices;

    std::string path = element.attribute("path").toStdString();
    bool useBoard = element.attribute("useBoard", "true").compare("true") == 0;

    SimpleTactileSensorBoard* sensorBoard = new SimpleTactileSensorBoard(path);
    std::vector<TactileSensor*> tactileSensors;
    if (!element.hasChildNodes()) {
        tactileSensors = sensorBoard->initAllSensors();
    } else {
        //TODO init child nodes
    }

    if (useBoard) {
        devices.push_back(sensorBoard);
    } else {
        devices = drobot::util::castVector<TactileSensor*, Device*>(tactileSensors);
    }

    return devices;
}

} // namespace tactile
} // namespace device
} // namespace drobot
