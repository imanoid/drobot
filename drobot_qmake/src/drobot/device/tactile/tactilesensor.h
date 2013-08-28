#ifndef DROBOT_DEVICE_TACTILE_TACTILESENSOR_H
#define DROBOT_DEVICE_TACTILE_TACTILESENSOR_H

#include "../device.h"

namespace drobot {
namespace device {
namespace tactile {

/**
 * @brief Base class for all tactile sensors
 */
class TactileSensor : public Device
{
public:
    TactileSensor(std::string name);
    /**
     * @return current value of the tactile sensor
     */
    virtual double getValue() = 0;
    /**
     * @return minimal possible value
     */
    virtual double getValueMin() = 0;
    /**
     * @return maximal possible value
     */
    virtual double getValueMax() = 0;
};

}
}
}

#endif // TACTILESENSOR_H
