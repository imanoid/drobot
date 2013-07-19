#include <iostream>
#include <sstream>

#include "DRobotActuationEvents.h"
#include "DRobotAbstractActuation.h"

namespace drobot {

DRobotAbstractActuation::~DRobotAbstractActuation() {

}

void DRobotAbstractActuation::setInitialPositions() {
	std::cerr << "N MOTORS: " << _motors.size() << std::endl;

	for (int i = 0; i < _motors.size(); i++) {
		_motors[i]->setInitialPosition();
	}

}

double DRobotAbstractActuation::getMotorPosition(int index)
{
	return _motors[index]->getMotorPosition();
}

std::vector<double> DRobotAbstractActuation::getMotorPositions() {
	std::vector<double> mPositions;

	for (int i = 0; i < _motors.size(); i++) {
		double position = _motors[i]->getMotorPosition();
		mPositions.push_back(position);
	}

	return mPositions;
}

void DRobotAbstractActuation::setMotorPosition(int index, double position) {
	_motors[index]->setMotorPosition(position);
}

void DRobotAbstractActuation::setMotorPositions(std::vector<double> positions) {

}

void DRobotAbstractActuation::setMotorIncrement(int index, double increment) {
	_motors[index]->setMotorPosition(
			_motors[index]->getMotorPosition() + increment);
}

void DRobotAbstractActuation::displayMotorPositions() {
	std::cout << "Motor Positions (" << _motors.size() << "): " << std::endl;

	for (int i = 0; i < _motors.size(); i++) {
		std::cout << "Motor " << i << " : " << _motors[i]->getMotorPosition()
				<< std::endl;
	}
}

void DRobotAbstractActuation::engage() {
	for (std::vector<DRobotAbstractServoMotor*>::iterator iMotor = _motors.begin(); iMotor != _motors.end(); iMotor++) {
		(*iMotor)->engage();
	}
}

void DRobotAbstractActuation::disengage() {
	for (std::vector<DRobotAbstractServoMotor*>::iterator iMotor = _motors.begin(); iMotor != _motors.end(); iMotor++) {
		(*iMotor)->disengage();
	}
}

}
