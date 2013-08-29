
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
		drobot::DRobotAdvancedActuation* actuation1 = new drobot::DRobotAdvancedActuation();
		drobot::DRobotAdvancedActuation* actuation2 = new drobot::DRobotAdvancedActuation();
		drobot::DRobotAdvancedActuation* actuation3 = new drobot::DRobotAdvancedActuation();

		drobot::DRobotAdvancedActuation* testActuation = actuation3;

		testActuation->addServoMotor("1-1", 2, 0, 100, 0, 100);
		testActuation->addServoMotor("1-2", 2, 1, 100, 0, 100);
		testActuation->addServoMotor("1-3", 2, 2, 100, 0, 100);
		testActuation->addServoMotor("1-4", 2, 3, 100, 0, 100);
		testActuation->addServoMotor("1-5", 2, 4, 100, 0, 100);
		testActuation->addServoMotor("1-6", 2, 5, 100, 0, 100);
		testActuation->engage();
		usleep(1000000);
		testActuation->setMotorPosition(5, 100);
		usleep(2000000);
		testActuation->setMotorPosition(5, 120);
		usleep(2000000);
		testActuation->disengage();
		exit(0);
	}
};

int main(int argc, char *argv[]) {

	QApplication application(argc, argv);

	ActuationTester* a = new ActuationTester();
	boost::thread* t = new boost::thread(boost::bind(&ActuationTester::run, a));

	return application.exec();

}

