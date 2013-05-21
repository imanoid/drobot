
#ifndef _DROBOT_DROBOTSERVOMOTOR_H_
#define _DROBOT_DROBOTSERVOMOTOR_H_

#include <string>
#include <vector>

#include "phidget21.h"

namespace drobot {

class DRobotServoMotor
{

public:

	DRobotServoMotor( CPhidgetServoHandle servo );

	~DRobotServoMotor();

	double
	getInitialPosition();

	void
	setInitialPosition(double iPosition);

	double
	getMotorPosition();

	void
	setMotorPosition(double position);

	void
	setInitialPosition();

	void
	setMinMax(double min, double max);

	void
	setName(std::string name);

	void
	setBoard(int board, int index);


private:

	// Servo handle
	CPhidgetServoHandle servo;


public:

	std::string name;

	double min;

	double max;

	double iPosition;

	int board;

	int index;

};

}


#endif
