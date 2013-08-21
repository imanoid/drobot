#ifndef DROBOT_DEVICE_TACTILE_TACTILESENSORBOARD_H
#define DROBOT_DEVICE_TACTILE_TACTILESENSORBOARD_H

#include <string>
#include <vector>
#include "tactilesensor.h"
#include "../deviceboard.h"

namespace drobot {
namespace device {
namespace tactile {

class TactileSensorBoard : public DeviceBoard
{
public:
    TactileSensorBoard(std::string name);
    std::vector<TactileSensor*> getTactileSensors();
    TactileSensor* getTactileSensor(std::string name);
};

}
}
}

#endif // TACTILESENSORBOARD_H
