
#include <iostream>

#include "DRobotVestibular.h"
#include <QApplication>
#include <boost/thread.hpp>

//#include "DRobotTimePlotter/DRobotTimePlotter.h"

//#include "DRobotPlotter.h"

class VestibularTester {

public:

	void run() {

		int key;


		usleep(1000000);
	}
};

int main(int argc, char *argv[]) {

	QApplication application(argc, argv);

	VestibularTester* a = new VestibularTester();
	boost::thread* t = new boost::thread(boost::bind(&VestibularTester::run, a));

	return application.exec();

}

