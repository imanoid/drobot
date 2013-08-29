#ifndef _DROBOT_DROBOTSERVOMOTOR_H_
#define _DROBOT_DROBOTVESTIBULAR_H_

#include <vector>
#include "phidget21.h"

namespace drobot {
class DRobotVestibular {
public:
	DRobotVestibular();
	DRobotVestibular(int serial);
	DRobotVestibular(CPhidgetSpatialHandle phid) :
			_phid(phid) {
	}
	virtual ~DRobotVestibular();
	int getAccelerationAxisCount();
	int getGyroAxisCount();
	int getCompassAxisCount();
	std::vector<double> getAcceleration();
	std::vector<double> getAccelerationMax();
	std::vector<double> getAccelerationMin();
	std::vector<double> getAngularRate();
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
private:
	CPhidgetSpatialHandle _phid;
};
}

#endif
