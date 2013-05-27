
#ifndef _DROBOT_DROBOTACTUATION_H_
#define _DROBOT_DROBOTACTUATION_H_

#include <string>
#include <vector>

using std::vector;

#include "DRobotServoMotor.h"
#include "phidget21.h"

namespace drobot {

class DRobotActuation
{

public:

	DRobotActuation( );

	virtual ~DRobotActuation( );

	void
	addServoMotor(std::string name, int board, int index, double iPosition, double min, double max);

	void
	setInitialPositions();

	int
	getMotorPosition(int index);

	std::vector<double>
	getMotorPositions();

	void
	setMotorPosition(int index, double position);

	void
	setMotorPositions(std::vector<double> mPositions);

	void
	setMotorIncrement(int index, double increment);

    vector<DRobotServoMotor*>
    getMotors() {return this->motors;}

	void
	displayMotorPositions( );

private:

	void
	initCommunication();

	int
	displayProperties(CPhidgetServoHandle phid);



private:

	// Servo handle
	CPhidgetServoHandle servo;
    std::vector<DRobotServoMotor*> motors;

public:

	static const int L_EYE_PAN = 0;

	static const int L_EYE_TILT = 1;

};

}


#endif
