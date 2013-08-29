#include "DRobotVestibular.h"
#include <iostream>
#include <sstream>

namespace drobot {

DRobotVestibular::DRobotVestibular() {
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

DRobotVestibular::DRobotVestibular(int serial) {
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

DRobotVestibular::~DRobotVestibular() {

}

int DRobotVestibular::getAccelerationAxisCount() {
	int count;
	CPhidgetSpatial_getAccelerationAxisCount(_phid, &count);
	return count;
}

int DRobotVestibular::getGyroAxisCount() {
	int* count;
	CPhidgetSpatial_getGyroAxisCount(_phid, count);
	return *count;
}

int DRobotVestibular::getCompassAxisCount() {
	int* count;
	CPhidgetSpatial_getCompassAxisCount(_phid, count);
	return *count;
}

std::vector<double> DRobotVestibular::getAcceleration() {
	std::vector<double> accelerations;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double acceleration;
		CPhidgetSpatial_getAcceleration(_phid, dim, &acceleration);
		accelerations.push_back(acceleration);
	}
	return accelerations;
}

std::vector<double> DRobotVestibular::getAccelerationMax() {
	std::vector<double> accelerations;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double acceleration;
		CPhidgetSpatial_getAccelerationMax(_phid, dim, &acceleration);
		accelerations.push_back(acceleration);
	}
	return accelerations;
}

std::vector<double> DRobotVestibular::getAccelerationMin() {
	std::vector<double> accelerations;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double acceleration;
		CPhidgetSpatial_getAccelerationMin(_phid, dim, &acceleration);
		accelerations.push_back(acceleration);
	}
	return accelerations;
}

std::vector<double> DRobotVestibular::getAngularRate() {
	std::vector<double> angularRates;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double angularRate;
		CPhidgetSpatial_getAngularRate(_phid, dim, &angularRate);
		angularRates.push_back(angularRate);
	}
	return angularRates;
}

std::vector<double> DRobotVestibular::getAngularRateMax() {
	std::vector<double> angularRates;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double angularRate;
		CPhidgetSpatial_getAngularRateMax(_phid, dim, &angularRate);
		angularRates.push_back(angularRate);
	}
	return angularRates;
}

std::vector<double> DRobotVestibular::getAngularRateMin() {
	std::vector<double> angularRates;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double angularRate;
		CPhidgetSpatial_getAngularRateMin(_phid, dim, &angularRate);
		angularRates.push_back(angularRate);
	}
	return angularRates;
}

std::vector<double> DRobotVestibular::getMagneticField() {
	std::vector<double> magneticFields;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double magneticField;
		CPhidgetSpatial_getMagneticField(_phid, dim, &magneticField);
		magneticFields.push_back(magneticField);
	}
	return magneticFields;
}

std::vector<double> DRobotVestibular::getMagneticFieldMax() {
	std::vector<double> magneticFields;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double magneticField;
		CPhidgetSpatial_getMagneticFieldMax(_phid, dim, &magneticField);
		magneticFields.push_back(magneticField);
	}
	return magneticFields;

}

std::vector<double> DRobotVestibular::getMagneticFieldMin() {
	std::vector<double> magneticFields;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		double magneticField;
		CPhidgetSpatial_getMagneticFieldMin(_phid, dim, &magneticField);
		magneticFields.push_back(magneticField);
	}
	return magneticFields;

}

void DRobotVestibular::zeroGyro() {
	CPhidgetSpatial_zeroGyro (_phid);
}

int DRobotVestibular::getDataRate() {
	int milliseconds;
	CPhidgetSpatial_getDataRate(_phid, &milliseconds);
	return milliseconds;
}

void DRobotVestibular::setDataRate(int milliseconds) {
	CPhidgetSpatial_setDataRate(_phid, milliseconds);
}

int DRobotVestibular::getDataRateMax() {
	int max;
	CPhidgetSpatial_getDataRateMax(_phid, &max);
	return max;
}

int DRobotVestibular::getDataRateMin() {
	int min;
	CPhidgetSpatial_getDataRateMax(_phid, &min);
	return min;
}

void DRobotVestibular::setCompassCorrectionParameters(double magneticField,
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

void DRobotVestibular::resetCompassCorrectionParameters() {
	CPhidgetSpatial_resetCompassCorrectionParameters(_phid);
}

}
