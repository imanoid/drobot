
#include <iostream>

#include "DRobotActuation.h"
#include "DRobotAdvancedActuation.h"
#include <QApplication>
#include <boost/thread.hpp>

//#include "DRobotTimePlotter/DRobotTimePlotter.h"

//#include "DRobotPlotter.h"

class ActuationTester {

public:

	void run() {

		int key;

		drobot::DRobotAdvancedActuation* actuation = new drobot::DRobotAdvancedActuation();

		int count = 0;

		std::vector<double> motors;

		actuation->addServoMotor("Left eye pan", 0, 0, 100, 80, 120);
		actuation->addServoMotor("Right eye pan", 0, 1, 100, 80, 120);
		actuation->addServoMotor("Arm rotate", 0, 2, 100, 80, 120);
		actuation->engage();
		actuation->setInitialPositions();

		actuation->setMotorPosition(2, 10);
		usleep(1000000);
		actuation->setMotorPosition(2, 30);
		usleep(1000000);
		actuation->setMotorPosition(2, 90);
		usleep(1000000);
		actuation->setMotorPosition(2, 150);
		usleep(1000000);
		actuation->disengage();
	}
};

int main(int argc, char *argv[]) {

	QApplication application(argc, argv);

	ActuationTester* a = new ActuationTester();
	boost::thread* t = new boost::thread(boost::bind(&ActuationTester::run, a));

	return application.exec();

}

