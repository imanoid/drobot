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
    std::string name = element.attribute("name").toStdString();
    bool useBoard = element.attribute("useBoard", "false").compare("true") == 0;
    bool enabled = element.attribute("enabled", "true").compare("true") == 0;

    SimpleTactileSensorBoard* sensorBoard = new SimpleTactileSensorBoard(name, path);

    if (enabled)
        sensorBoard->enable();

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
