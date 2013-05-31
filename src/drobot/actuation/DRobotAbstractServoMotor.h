#ifndef _DROBOT_DROBOTABSTRACTSERVOMOTOR_H_
#define _DROBOT_DROBOTABSTRACTSERVOMOTOR_H_

#include <string>
#include <vector>

using std::string;

#include "phidget21.h"

namespace drobot {

class DRobotAbstractServoMotor {

public:
	virtual ~DRobotAbstractServoMotor();

	double getInitialPosition();
	void setInitialPosition(double iPosition);
	virtual double getMotorPosition() = 0;
	virtual void setMotorPosition(double position) = 0;
	void setInitialPosition();
	double getMin();
	double getMax();
	void setMinMax(double min, double max);
	void setName(string name);
	void setBoard(int board, int index);
	int getBoard();
	int getIndex();
	virtual void engage()=0;
	virtual void disengage()=0;
	virtual bool isEngaged()=0;
protected:
	string name;
	double min;
	double max;
	double iPosition;
	int board;
	int index;
};

}

#endif
