#include "phidgetvestibular.h"
#include <sstream>
#include <iostream>

namespace drobot {
namespace device {
namespace vestibular {

PhidgetVestibular::PhidgetVestibular() {
    _phid = 0;
    CPhidgetSpatial_create (&_phid);
    CPhidget_open((CPhidgetHandle) _phid, -1);

    int result;
    const char *err;
    if ((result = CPhidget_waitForAttachment((CPhidgetHandle) _phid, 10000))) {
        CPhidget_getErrorDescription(result, &err);
        std::stringstream errorMsg;
        errorMsg << "Problem waiting for attachment: " << err;
        std::cerr << errorMsg.str() << std::endl;
        throw errorMsg.str();
    }
}

PhidgetVestibular::PhidgetVestibular(int serial) {
    _phid = 0;
    CPhidgetSpatial_create (&_phid);
    CPhidget_open((CPhidgetHandle) _phid, serial);

    int result;
    const char *err;
    if ((result = CPhidget_waitForAttachment((CPhidgetHandle) _phid, 10000))) {
        CPhidget_getErrorDescription(result, &err);
        std::stringstream errorMsg;
        errorMsg << "Problem waiting for attachment: " << err;
        std::cerr << errorMsg.str() << std::endl;
        throw errorMsg.str();
    }

}

int PhidgetVestibular::getAccelerationAxisCount() {
    int count;
    CPhidgetSpatial_getAccelerationAxisCount(_phid, &count);
    return count;
}

int PhidgetVestibular::getGyroAxisCount() {
    int* count;
    CPhidgetSpatial_getGyroAxisCount(_phid, count);
    return *count;
}

int PhidgetVestibular::getCompassAxisCount() {
    int* count;
    CPhidgetSpatial_getCompassAxisCount(_phid, count);
    return *count;
}

std::vector<double> PhidgetVestibular::getAcceleration() {
    std::vector<double> accelerations;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double acceleration;
        CPhidgetSpatial_getAcceleration(_phid, dim, &acceleration);
        accelerations.push_back(acceleration);
    }
    return accelerations;
}

std::vector<double> PhidgetVestibular::getAccelerationMax() {
    std::vector<double> accelerations;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double acceleration;
        CPhidgetSpatial_getAccelerationMax(_phid, dim, &acceleration);
        accelerations.push_back(acceleration);
    }
    return accelerations;
}

std::vector<double> PhidgetVestibular::getAccelerationMin() {
    std::vector<double> accelerations;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double acceleration;
        CPhidgetSpatial_getAccelerationMin(_phid, dim, &acceleration);
        accelerations.push_back(acceleration);
    }
    return accelerations;
}

std::vector<double> PhidgetVestibular::getAngularRate() {
    std::vector<double> angularRates;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double angularRate;
        CPhidgetSpatial_getAngularRate(_phid, dim, &angularRate);
        angularRates.push_back(angularRate);
    }
    return angularRates;
}

std::vector<double> PhidgetVestibular::getAngularRateMax() {
    std::vector<double> angularRates;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double angularRate;
        CPhidgetSpatial_getAngularRateMax(_phid, dim, &angularRate);
        angularRates.push_back(angularRate);
    }
    return angularRates;
}

std::vector<double> PhidgetVestibular::getAngularRateMin() {
    std::vector<double> angularRates;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double angularRate;
        CPhidgetSpatial_getAngularRateMin(_phid, dim, &angularRate);
        angularRates.push_back(angularRate);
    }
    return angularRates;
}

std::vector<double> PhidgetVestibular::getMagneticField() {
    std::vector<double> magneticFields;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double magneticField;
        CPhidgetSpatial_getMagneticField(_phid, dim, &magneticField);
        magneticFields.push_back(magneticField);
    }
    return magneticFields;
}

std::vector<double> PhidgetVestibular::getMagneticFieldMax() {
    std::vector<double> magneticFields;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double magneticField;
        CPhidgetSpatial_getMagneticFieldMax(_phid, dim, &magneticField);
        magneticFields.push_back(magneticField);
    }
    return magneticFields;

}

std::vector<double> PhidgetVestibular::getMagneticFieldMin() {
    std::vector<double> magneticFields;
    for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
        double magneticField;
        CPhidgetSpatial_getMagneticFieldMin(_phid, dim, &magneticField);
        magneticFields.push_back(magneticField);
    }
    return magneticFields;

}

void PhidgetVestibular::zeroGyro() {
    CPhidgetSpatial_zeroGyro (_phid);
}

int PhidgetVestibular::getDataRate() {
    int milliseconds;
    CPhidgetSpatial_getDataRate(_phid, &milliseconds);
    return milliseconds;
}

void PhidgetVestibular::setDataRate(int milliseconds) {
    CPhidgetSpatial_setDataRate(_phid, milliseconds);
}

int PhidgetVestibular::getDataRateMax() {
    int max;
    CPhidgetSpatial_getDataRateMax(_phid, &max);
    return max;
}

int PhidgetVestibular::getDataRateMin() {
    int min;
    CPhidgetSpatial_getDataRateMax(_phid, &min);
    return min;
}

void PhidgetVestibular::setCompassCorrectionParameters(double magneticField,
        std::vector<double> offset, std::vector<double> gain, std::vector<double> T) {
    while (offset.size() < 3)
        offset.push_back(0);
    while (gain.size() < 3)
        gain.push_back(0);
    while (T.size() < 6)
        T.push_back(0);

    CPhidgetSpatial_setCompassCorrectionParameters(_phid, magneticField,
            offset[0], offset[1], offset[2], gain[0], gain[1], gain[2], T[0],
            T[1], T[2], T[3], T[4], T[5]);

}

void PhidgetVestibular::resetCompassCorrectionParameters() {
    CPhidgetSpatial_resetCompassCorrectionParameters(_phid);
}

void PhidgetVestibular::enable() {
    _enabled = true;
}

void PhidgetVestibular::disable() {
    _enabled = false;
}

bool PhidgetVestibular::isEnabled() {
    return _enabled;
}

}
}
}
