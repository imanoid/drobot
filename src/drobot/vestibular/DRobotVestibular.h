#ifndef _DROBOT_DROBOTSERVOMOTOR_H_
#define _DROBOT_DROBOTVESTIBULAR_H_

#include <vector>
#include "phidget21.h"

using std::vector;

namespace drobot {
class DRobotVestibular {
public:
	DRobotVestibular();
	DRobotVestibular(int serial);
	DRobotVestibular(CPhidgetSpatialHandle* phid) :
			_phid(phid) {
	}
	virtual ~DRobotVestibular();
	int getAccelerationAxisCount();
	int getGyroAxisCount();
	int getCompassAxisCount();
	vector<double> getAcceleration();
	vector<double> getAccelerationMax();
	vector<double> getAccelerationMin();
	vector<double> getAngularRate();
	vector<double> getAngularRateMax();
	vector<double> getAngularRateMin();
	vector<double> getMagneticField();
	vector<double> getMagneticFieldMax();
	vector<double> getMagneticFieldMin();
	void zeroGyro();
	int getDataRate();
	void setDataRate(int, milliseconds);
	int getDataRateMax();
	int getDataRateMin();
	void setCompassCorrectionParameters(double magneticField,
			vector<double> offset, vector<double> gain, vector<double> T);
	void resetCompassCorrectionParameters();
private:
	CPhidgetSpatialHandle _phid;
};
}

#endif
