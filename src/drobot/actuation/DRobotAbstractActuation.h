#ifndef _DROBOT_DROBOTABSTRACTACTUATION_H_
#define _DROBOT_DROBOTABSTRACTACTUATION_H_

#include <string>
#include <vector>

#include "DRobotAbstractServoMotor.h"
#include "phidget21.h"

namespace drobot {

class DRobotAbstractActuation {

public:
	virtual ~DRobotAbstractActuation();

	virtual void addServoMotor(std::string name, int board, int index, double iPosition,
			double min, double max) = 0;
	void setInitialPositions();
	double getMotorPosition(int index);
	std::vector<double> getMotorPositions();
	void setMotorPosition(int index, double position);
	void setMotorPositions(std::vector<double> mPositions);
	void setMotorIncrement(int index, double increment);
	double getMotorMin(int index);
	double getMotorMax(int index);
	void displayMotorPositions();
	void engage();
	void disengage();

	static const int L_EYE_PAN = 0;
	static const int L_EYE_TILT = 1;

protected:
	virtual int displayProperties() = 0;
	std::vector<DRobotAbstractServoMotor*> _motors;

};

}

#endif
