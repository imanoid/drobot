#ifndef _DROBOT_DEVICE_VESTIBULAR_VESTIBULAR_H_
#define _DROBOT_DEVICE_VESTIBULAR_VESTIBULAR_H_

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
    virtual std::vector<double> getAngularRate() = 0;
};

}
}
}

#endif // VESTIBULAR_H
