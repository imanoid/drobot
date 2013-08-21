#ifndef DROBOT_DEVICE_VESTIBULAR_VESTIBULAR_H
#define DROBOT_DEVICE_VESTIBULAR_VESTIBULAR_H

#include "../device.h"
#include <vector>

namespace drobot {
namespace device {
namespace vestibular {

class Vestibular : public Device
{
public:
    Vestibular(std::string name);
    virtual std::vector<double> getAcceleration() = 0;
    virtual std::vector<double> getAccelerationMin() = 0;
    virtual std::vector<double> getAccelerationMax() = 0;
    virtual std::vector<double> getAngularRate() = 0;
    virtual std::vector<double> getAngularRateMin() = 0;
    virtual std::vector<double> getAngularRateMax() = 0;
    virtual std::vector<double> getMagneticField() = 0;
    virtual std::vector<double> getMagneticFieldMin() = 0;
    virtual std::vector<double> getMagneticFieldMax() = 0;
};

}
}
}

#endif // VESTIBULAR_H
