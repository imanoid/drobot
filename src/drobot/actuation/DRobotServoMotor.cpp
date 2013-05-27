
#include <iostream>

#include "DRobotServoMotor.h"


namespace drobot
{


DRobotServoMotor::DRobotServoMotor( CPhidgetServoHandle servo )
{
	this->servo = servo;
}

DRobotServoMotor::~DRobotServoMotor()
{

}

void
DRobotServoMotor::setInitialPosition()
{
	setMotorPosition(iPosition);
}

double
DRobotServoMotor::getInitialPosition()
{
	return iPosition;
}

void
DRobotServoMotor::setInitialPosition(double iPosition)
{
	this->iPosition = iPosition;
}


void
DRobotServoMotor::setMotorPosition(double position)
{
	CPhidgetServo_setPosition(servo, index, position);
}

double
DRobotServoMotor::getMotorPosition()
{
	double position;
	CPhidgetServo_getPosition(servo, index, &position);
	return position;

}

void
DRobotServoMotor::setMinMax(double min, double max)
{
	this->min = min;
	this->max = max;
}

double
DRobotServoMotor::getMin() {
    return this->min;
}

double
DRobotServoMotor::getMax() {
    return this->max;
}

void
DRobotServoMotor::setName(string name)
{
	this->name = name;
}

void
DRobotServoMotor::setBoard(int board, int index)
{
	this->board = board;
	this->index = index;
}



}
