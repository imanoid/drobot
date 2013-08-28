#ifndef DROBOT_DEVICE_VESTIBULAR_VESTIBULAR_H
#define DROBOT_DEVICE_VESTIBULAR_VESTIBULAR_H

#include "../device.h"
#include <vector>

namespace drobot {
namespace device {
namespace vestibular {

/**
 * @brief The Vestibular class is the base for all Vestibular system like sensors
 */
class Vestibular : public Device
{
public:
    Vestibular(std::string name);
    /**
     * @brief getAcceleration
     * @return acceleration vector
     */
    virtual std::vector<double> getAcceleration() = 0;
    /**
     * @brief getAccelerationMin
     * @return min acceleration values for each dimension
     */
    virtual std::vector<double> getAccelerationMin() = 0;
    /**
     * @brief getAccelerationMax
     * @return max acceleration values for each dimension
     */
    virtual std::vector<double> getAccelerationMax() = 0;
    /**
     * @brief getAngularRate
     * @return angularRate vector
     */
    virtual std::vector<double> getAngularRate() = 0;
    /**
     * @brief getAngularRateMin
     * @return min angularRate values for each dimension
     */
    virtual std::vector<double> getAngularRateMin() = 0;
    /**
     * @brief getAngularRateMax
     * @return max angularRate values for each dimension
     */
    virtual std::vector<double> getAngularRateMax() = 0;
    /**
     * @brief getMagneticField
     * @return magneticField vector
     */
    virtual std::vector<double> getMagneticField() = 0;
    /**
     * @brief getMagneticFieldMin
     * @return min magneticField values for each dimension
     */
    virtual std::vector<double> getMagneticFieldMin() = 0;
    /**
     * @brief getMagneticFieldMax
     * @return max magneticField values for each dimension
     */
    virtual std::vector<double> getMagneticFieldMax() = 0;
};

}
}
}

#endif // VESTIBULAR_H
