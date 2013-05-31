#include "DRobotVestibular.h"

DRobotVestibular::DRobotVestibular() {
	_phid = 0;
	CPhidgetSpatial_create (&_phid);
	CPhidget_open((CPhidgetHandle) spatial, -1);

	if ((result = CPhidget_waitForAttachment((CPhidgetHandle) spatial, 10000))) {
		CPhidget_getErrorDescription(result, &err);
		stringstream errorMsg;
		errorMsg << "Problem waiting for attachment: " << err;
		std::cerr << errorMsg.str() << std::endl;
		throw errorMsg.str();
	}
}

DRobotVestibular::DRobotVestibular(int serial) {
	_phid = 0;
	CPhidgetSpatial_create (&_phid);
	CPhidget_open((CPhidgetHandle) spatial, serial);

	if ((result = CPhidget_waitForAttachment((CPhidgetHandle) spatial, 10000))) {
		CPhidget_getErrorDescription(result, &err);
		stringstream errorMsg;
		errorMsg << "Problem waiting for attachment: " << err;
		std::cerr << errorMsg.str() << std::endl;
		throw errorMsg.str();
	}

}

DRobotVestibular::~DRobotVestibular() {

}

int DRobotVestibular::getAccelerationAxisCount() {
	int* count;
	CPhidgetSpatial_getAccelerationAxisCount(_phid, count);
	return *count;
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

vector<double> DRobotVestibular::getAcceleration() {
	vector<double> accelerations;
	double* acceleration;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getAcceleration(_phid, dim, acceleration);
		accelerations.append(*acceleration);
	}
	return accelerations;
}

vector<double> DRobotVestibular::getAccelerationMax() {
	vector<double> accelerations;
	double* acceleration;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getAccelerationMax(_phid, dim, acceleration);
		accelerations.append(*acceleration);
	}
	return accelerations;
}

vector<double> DRobotVestibular::getAccelerationMin() {
	vector<double> accelerations;
	double* acceleration;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getAccelerationMin(_phid, dim, acceleration);
		accelerations.append(*acceleration);
	}
	return accelerations;
}

vector<double> DRobotVestibular::getAngularRate() {
	vector<double> angularRates;
	double* angularRate;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getAngularRate(_phid, dim, angularRate);
		angularRates.append(*angularRate);
	}
	return angularRates;
}

vector<double> DRobotVestibular::getAngularRateMax() {
	vector<double> angularRates;
	double* angularRate;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getAngularRateMax(_phid, dim, angularRate);
		angularRates.append(*angularRate);
	}
	return angularRates;
}

vector<double> DRobotVestibular::getAngularRateMin() {
	vector<double> angularRates;
	double* angularRate;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getAngularRateMin(_phid, dim, angularRate);
		angularRates.append(*angularRate);
	}
	return angularRates;
}

vector<double> DRobotVestibular::getMagneticField() {
	vector<double> magneticFields;
	double* magneticField;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getMagneticField(_phid, dim, magneticField);
		magneticFields.append(magneticField);
	}
	return magneticFields;
}

vector<double> DRobotVestibular::getMagneticFieldMax() {
	vector<double> magneticFields;
	double* magneticField;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getMagneticFieldMax(_phid, dim, magneticField);
		magneticFields.append(magneticField);
	}
	return magneticFields;

}

vector<double> DRobotVestibular::getMagneticFieldMin() {
	vector<double> magneticFields;
	double* magneticField;
	for (int dim = 0; dim < this->getAccelerationAxisCount(); dim++) {
		CPhidgetSpatial_getMagneticFieldMin(_phid, dim, magneticField);
		magneticFields.append(magneticField);
	}
	return magneticFields;

}

void DRobotVestibular::zeroGyro() {
	CPhidgetSpatial_zeroGyro (_phid);
}

int DRobotVestibular::getDataRate() {
	int* milliseconds;
	CPhidgetSpatial_getDataRate(_phid, milliseconds);
	return *milliseconds;
}

void DRobotVestibular::setDataRate(int, milliseconds) {
	CPHidgetSpatial_setDataRate(_phid, milliseconds);
}

int DRobotVestibular::getDataRateMax() {
	int* max;
	CPhidgetSpatial_getDataRateMax(_phid, max);
	return *max;
}

int DRobotVestibular::getDataRateMin() {
	int* min;
	CPhidgetSpatial_getDataRateMax(_phid, min);
	return *min;
}

void DRobotVestibular::setCompassCorrectionParameters(double magneticField,
		vector<double> offset, vector<double> gain, vector<double> T) {
	while (offset.size() < 3)
		offset.append(0);
	while (gain.size() < 3)
		gain.append(0);
	while (T.size() < 6)
		T.append(0);

	CPhidgetSpatial_setCompassCOrrectionParameters(_phid, magneticField,
			offset[0], offset[1], offset[2], gain[0], gain[1], gain[2], T[0],
			T[1], T[2], T[3], T[4], T[5]);

}

void DRobotVestibular::resetCompassCorrectionParameters() {
	CPhidgetSpatial_resetCompassCorrectionParameters(_phid);
}
