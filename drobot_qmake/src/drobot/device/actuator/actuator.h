#ifndef DROBOT_DEVICE_ACTUATOR_ACTUATOR_H
#define DROBOT_DEVICE_ACTUATOR_ACTUATOR_H

#include "../device.h"

namespace drobot {
namespace device {
namespace actuator {

class Actuator : public Device
{
public:
    virtual double getPosition() = 0;
    virtual void setPosition(double position) = 0;
    virtual double getVelocity() = 0;
    virtual void setVelocity(double velocity) = 0;
    virtual double getAcceleration() = 0;
    virtual void setAcceleration(double acceleration) = 0;
};

}
}
}

#endif // ACTUATOR_H
