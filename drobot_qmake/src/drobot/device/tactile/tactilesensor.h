#ifndef DROBOT_DEVICE_TACTILE_TACTILESENSOR_H
#define DROBOT_DEVICE_TACTILE_TACTILESENSOR_H

#include "../device.h"

namespace drobot {
namespace device {
namespace tactile {

class TactileSensor : public Device
{
public:
    TactileSensor(std::string name);
    virtual double getValue() = 0;
    virtual double getValueMin() = 0;
    virtual double getValueMax() = 0;
};

}
}
}

#endif // TACTILESENSOR_H
