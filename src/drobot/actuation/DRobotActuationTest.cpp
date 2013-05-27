

#include <iostream>

#include "DRobotActuation.h"
#include <QApplication>
#include <boost/thread.hpp>

//#include "DRobotTimePlotter/DRobotTimePlotter.h"

//#include "DRobotPlotter.h"

class ActuationTester
{

public:

	void run()
	{

		int key;

		drobot::DRobotActuation* actuation = new drobot::DRobotActuation();

		int count = 0;

		std::vector<double> motors;

        actuation->addServoMotor("Left eye pan",0,0,100,80,120);

		actuation->setInitialPositions();

		while(1)
		{
            actuation->setMotorIncrement(0, 1);
			actuation->displayMotorPositions();

            usleep(5000000);

			count++;
		}

	}
};



int main(int argc, char *argv[])
{

	QApplication application(argc, argv);

	ActuationTester* a = new ActuationTester();
	boost::thread* t = new boost::thread( boost::bind(&ActuationTester::run, a) );

	return application.exec();

}


