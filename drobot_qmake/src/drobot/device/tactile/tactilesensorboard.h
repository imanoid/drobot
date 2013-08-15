#ifndef _DROBOT_DEVICE_TACTILE_TACTILESENSORBOARD_H_
#define _DROBOT_DEVICE_TACTILE_TACTILESENSORBOARD_H_

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
