#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLESERVO_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLESERVO_H

#include "actuator.h"
#include <phidget21.h>
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetSimpleServo : public Actuator, public PhidgetDevice
{
private:
    CPhidgetServoHandle _phidgetHandle;
    int _index;

public:
    PhidgetSimpleServo(std::string name, CPhidgetServoHandle phidgetHandle, int index);

    virtual void initChannels();

    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();

    virtual double getPosition();
    virtual void setPosition(double position);

    virtual double getVelocity();
    virtual void setVelocity(double velocity);

    virtual double getAcceleration();
    virtual void setAcceleration(double acceleration);

    double getPositionMin();
    double getPositionMax();
};

}
}
}

#endif // PHIDGETSIMPLESERVO_H
