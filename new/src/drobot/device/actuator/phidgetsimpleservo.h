#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLESERVO_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLESERVO_H

#include "actuator.h"
#include <phidget21.h>
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace actuator {

/**
 * @brief The PhidgetSimpleServo class
 * @details The PhidgetSimpleServo only supports movement by setting the position. The acceleration and velocity properties aren't
 *  implemented by the Phidget Servo module but they can be simulated by setting the position according to the acceleration/velocity
 *  set if needed.
 */
class PhidgetSimpleServo : public Actuator
{
private:
    CPhidgetServoHandle _phidgetHandle;
    int _index;
protected:
    virtual CPhidgetHandle& getPhidgetHandle();
public:
    PhidgetSimpleServo(std::string name, CPhidgetServoHandle phidgetHandle, int index);

    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();

    virtual double getPosition();
    virtual void setPosition(double position);
    virtual double getPositionMin();
    virtual double getPositionMax();

    virtual double getVelocity();
    virtual void setVelocity(double velocity);
    virtual double getVelocityMin();
    virtual double getVelocityMax();

    virtual double getAcceleration();
    virtual void setAcceleration(double acceleration);
    virtual double getAccelerationMin();
    virtual double getAccelerationMax();
};

}
}
}

#endif // PHIDGETSIMPLESERVO_H
