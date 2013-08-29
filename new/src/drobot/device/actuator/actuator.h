#ifndef DROBOT_DEVICE_ACTUATOR_ACTUATOR_H
#define DROBOT_DEVICE_ACTUATOR_ACTUATOR_H

#include "../device.h"

namespace drobot {
namespace device {
namespace actuator {

/**
 * @brief Base class for all the actuators.
 */
class Actuator : public Device
{
public:
    Actuator(std::string name);

    /**
     * @return current motor position
     */
    virtual double getPosition() = 0;
    /**
     * @brief set motor position. The motor will always move to the last set position.
     * @param position
     */
    virtual void setPosition(double position) = 0;
    /**
     * @return maximal possible position
     */
    virtual double getPositionMin() = 0;
    /**
     * @return minimal possible position
     */
    virtual double getPositionMax() = 0;

    /**
     * @return current velocity
     */
    virtual double getVelocity() = 0;
    /**
     * @brief set current velocity
     * @param velocity
     */
    virtual void setVelocity(double velocity) = 0;
    /**
     * @return minimal possible velocity
     */
    virtual double getVelocityMin() = 0;
    /**
     * @return maximal possible velocity
     */
    virtual double getVelocityMax() = 0;

    /**
     * @return current acceleration
     */
    virtual double getAcceleration() = 0;
    /**
     * @brief set current acceleration
     * @param acceleration
     */
    virtual void setAcceleration(double acceleration) = 0;
    /**
     * @return minimal possible acceleration
     */
    virtual double getAccelerationMin() = 0;
    /**
     * @return maximal possible acceleration
     */
    virtual double getAccelerationMax() = 0;
};

}
}
}

#endif // ACTUATOR_H
