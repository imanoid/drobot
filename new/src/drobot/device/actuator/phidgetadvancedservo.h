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

    /**
     * @brief getMovingAcceleration
     * @return the acceleration of the movement
     */
    double getMovingAcceleration();
    /**
     * @brief setMovingAcceleration
     * @details this property controls the acceleration of the movement if the servo is set to a new position
     * @param acceleration
     */
    void setMovingAcceleration(double acceleration);
    /**
     * @brief getMovingAccelerationMin
     * @return minimum acceleration
     */
    double getMovingAccelerationMin();
    /**
     * @brief getMovingAccelerationMax
     * @return maximum acceleration
     */
    double getMovingAccelerationMax();

    /**
     * @brief getMovingVelocity
     * @return the velocity of the movement
     */
    double getMovingVelocity();
    /**
     * @brief setMovingVelocity
     * @details this property controls the velocity of the movement if the servo is set to a new position
     * @param velocity
     */
    void setMovingVelocity(double velocity);
    /**
     * @brief getMovingVelocityMin
     * @return minimum possible velocity of the servo device
     */
    double getMovingVelocityMin();
    /**
     * @brief getMovingVelocityMax
     * @return maximum possible velocity of the servo device
     */
    double getMovingVelocityMax();
    /**
     * @brief getMovingVelocityLimit
     * @return velocity
     */
    double getMovingVelocityLimit();
    /**
     * @brief setMovingVelocityLimit
     * @param velocityLimit
     */
    void setMovingVelocityLimit(double velocityLimit);

    /**
     * @brief isMoving
     * @return true if motor is moving. false otherwhise
     */
    bool isMoving();

    bool isSpeedRamping();
    void setSpeedRamping(bool speedRamping);

    /**
     * @brief getIndex
     * @return index of the motor in the servo board
     */
    int getIndex();

    /**
     * @brief getCurrent
     * @return amount of current the motor is using
     */
    double getCurrent();
private:
    CPhidgetAdvancedServoHandle _phidgetHandle;
    int _index;
};

}
}
}

#endif // PHIDGETADVANCEDSERVO_H
