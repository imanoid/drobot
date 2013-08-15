#ifndef _DROBOT_DEVICE_TACTILE_TACTILESENSOR_H_
#define _DROBOT_DEVICE_TACTILE_TACTILESENSOR_H_

#include "../device.h"

namespace drobot {
namespace device {
namespace tactile {

class TactileSensor : public Device
{
public:
    TactileSensor(std::string name);
    virtual double getValue() = 0;
};

}
}
}

#endif // TACTILESENSOR_H
