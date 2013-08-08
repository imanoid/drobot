#ifndef _DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULAR_H_
#define _DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULAR_H_

#include "vestibular.h"
#include "phidget21.h"

namespace drobot {
namespace device {
namespace vestibular {

class PhidgetVestibular : public Vestibular
{
public:
    PhidgetVestibular();
    PhidgetVestibular(int serial);
    PhidgetVestibular(CPhidgetSpatialHandle phid) :
            _phid(phid) {
    }
    int getAccelerationAxisCount();
    int getGyroAxisCount();
    int getCompassAxisCount();
    virtual std::vector<double> getAcceleration();
    std::vector<double> getAccelerationMax();
    std::vector<double> getAccelerationMin();
    virtual std::vector<double> getAngularRate();
    std::vector<double> getAngularRateMax();
    std::vector<double> getAngularRateMin();
    std::vector<double> getMagneticField();
    std::vector<double> getMagneticFieldMax();
    std::vector<double> getMagneticFieldMin();
    void zeroGyro();
    int getDataRate();
    void setDataRate(int milliseconds);
    int getDataRateMax();
    int getDataRateMin();
    void setCompassCorrectionParameters(double magneticField,
            std::vector<double> offset, std::vector<double> gain, std::vector<double> T);
    void resetCompassCorrectionParameters();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
private:
    CPhidgetSpatialHandle _phid;
    bool _enabled;
};

}
}
}

#endif // PHIDGETVESTIBULAR_H
