#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDSERVO_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDSERVO_H

#include "actuator.h"
#include "phidget21.h"
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetAdvancedServo : public Actuator, public PhidgetDevice
{
public:
    PhidgetAdvancedServo(std::string name, CPhidgetAdvancedServoHandle phidgetHandle, int index);

    virtual void initChannels();

    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();

    virtual double getPosition();
    virtual void setPosition(double position);
    double getPositionMin();
    void setPositionMin(double positionMin);
    double getPositionMax();
    void setPositionMax(double positionMax);

    virtual double getAcceleration();
    virtual void setAcceleration(double acceleration);
    double getAccelerationMin();
    double getAccelerationMax();

    virtual double getVelocity();
    virtual void setVelocity(double velocity);
    double getVelocityMin();
    double getVelocityMax();
    double getVelocityLimit();
    void setVelocityLimit(double velocityLimit);

    bool isMoving();

    bool isSpeedRamping();
    void setSpeedRamping(bool speedRamping);

    int getIndex();

    double getCurrent();
private:
    CPhidgetAdvancedServoHandle _phidgetHandle;
    int _index;
};

}
}
}

#endif // PHIDGETADVANCEDSERVO_H
