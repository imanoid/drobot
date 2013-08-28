#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDSERVO_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDSERVO_H

#include "actuator.h"
#include "phidget21.h"
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace actuator {

/**
 * @brief The PhidgetAdvancedServo class
 * @details The PhidgetAdvancedServo only supports movement by setting the position. The movingAcceleration and movingVelocity properties
 *  refer to the movement initiated in this way. The acceleration and velocity properties aren't implemented by the Phidget Servo module
 *  but they can be simulated by setting the position according to the acceleration/velocity set if needed.
 */
class PhidgetAdvancedServo : public Actuator
{
protected:
    virtual CPhidgetHandle& getPhidgetHandle();
public:
    PhidgetAdvancedServo(std::string name, CPhidgetAdvancedServoHandle phidgetHandle, int index);

    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();

    virtual double getPosition();
    virtual void setPosition(double position);
    virtual double getPositionMin();
    void setPositionMin(double positionMin);
    virtual double getPositionMax();
    void setPositionMax(double positionMax);

    virtual double getAcceleration();
    virtual void setAcceleration(double acceleration);
    virtual double getAccelerationMin();
    virtual double getAccelerationMax();

    virtual double getVelocity();
    virtual void setVelocity(double velocity);
    virtual double getVelocityMin();
    virtual double getVelocityMax();

    double getMovingAcceleration();
    void setMovingAcceleration(double acceleration);
    double getMovingAccelerationMin();
    double getMovingAccelerationMax();

    double getMovingVelocity();
    void setMovingVelocity(double velocity);
    double getMovingVelocityMin();
    double getMovingVelocityMax();
    double getMovingVelocityLimit();
    void setMovingVelocityLimit(double velocityLimit);

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
