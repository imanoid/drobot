#include <iostream>

#include "DRobotAbstractServoMotor.h"

namespace drobot {

DRobotAbstractServoMotor::~DRobotAbstractServoMotor() {

}

void DRobotAbstractServoMotor::setInitialPosition() {
	setMotorPosition(iPosition);
}

double DRobotAbstractServoMotor::getInitialPosition() {
	return iPosition;
}

void DRobotAbstractServoMotor::setInitialPosition(double iPosition) {
	this->iPosition = iPosition;
}

void DRobotAbstractServoMotor::setMinMax(double min, double max) {
	this->min = min;
	this->max = max;
}

double DRobotAbstractServoMotor::getMin() {
	return this->min;
}

double DRobotAbstractServoMotor::getMax() {
	return this->max;
}

void DRobotAbstractServoMotor::setName(string name) {
	this->name = name;
}

void DRobotAbstractServoMotor::setBoard(int board, int index) {
	this->board = board;
	this->index = index;
}

int DRobotAbstractServoMotor::getBoard() {
	return this->board;
}

int DRobotAbstractServoMotor::getIndex() {
	return this->index;
}

}
