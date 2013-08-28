#ifndef DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULAR_H
#define DROBOT_DEVICE_VESTIBULAR_PHIDGETVESTIBULAR_H

#include "vestibular.h"
#include "phidget21.h"
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace vestibular {

/**
 * @brief The PhidgetVestibular class represents a Phidget Spatial module.
 */
class PhidgetVestibular : public Vestibular, public PhidgetDevice
{
private:
    CPhidgetSpatialHandle _phidgetHandle;
    bool _enabled;
protected:
    virtual CPhidgetHandle getPhidgetHandle();
public:
    PhidgetVestibular(std::string name);
    PhidgetVestibular(std::string name, int serial);
    PhidgetVestibular(std::string name, CPhidgetSpatialHandle phidgetHandle);
    virtual ~PhidgetVestibular();
    int getAccelerationAxisCount();
    int getGyroAxisCount();
    int getCompassAxisCount();
    virtual std::vector<double> getAcceleration();
    virtual std::vector<double> getAccelerationMax();
    virtual std::vector<double> getAccelerationMin();
    virtual std::vector<double> getAngularRate();
    virtual std::vector<double> getAngularRateMax();
    virtual std::vector<double> getAngularRateMin();
    virtual std::vector<double> getMagneticField();
    virtual std::vector<double> getMagneticFieldMax();
    virtual std::vector<double> getMagneticFieldMin();
    void zeroGyro();
    int getDataRate();
    void setDataRate(int milliseconds);
    int getDataRateMax();
    int getDataRateMin();
    void setCompassCorrectionParameters(double magneticField, std::vector<double> offset, std::vector<double> gain, std::vector<double> T);
    void resetCompassCorrectionParameters();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
};

}
}
}

#endif // PHIDGETVESTIBULAR_H
