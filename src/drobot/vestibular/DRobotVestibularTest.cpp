
#include <iostream>
#include "DRobotVestibular.h"
#include <QApplication>
#include <boost/thread.hpp>
#include "../utils/DRobotTimePlotter/DRobotTimePlotter.h"
#include <vector>
#include <string>

//#include "DRobotPlotter.h"

class VestibularTester {
private:
	drobot::DRobotTimePlotter* _plotter;
public:
	VestibularTester() {
		std::vector<std::string> labels;
		labels.push_back("angularRateX");
		labels.push_back("angularRateY");
		labels.push_back("angularRateZ");
		labels.push_back("accelerationX");
		labels.push_back("accelerationY");
		labels.push_back("accelerationZ");
		_plotter = new drobot::DRobotTimePlotter("test", 20, 20, 500, 300,
						labels);
		_plotter->show();
	}

	void run() {

		int key;

		drobot::DRobotVestibular* v = new drobot::DRobotVestibular();
		v->zeroGyro();

		double values[6];
		int count = 0;

		while (true) {
			std::vector<double> ang = v->getAngularRate();
			std::vector<double> acc = v->getAcceleration();

			values[0] = ang[0];
			values[1] = ang[1];
			values[2] = ang[2];
			values[3] = acc[0];
			values[4] = acc[1];
			values[5] = acc[2];

			_plotter->update(count, values);

			std::cout << "Angular rate: ";
			for (std::vector<double>::iterator iAng = ang.begin(); iAng != ang.end(); iAng++) {
				std::cout << *iAng << " ";
			}
			std::cout << std::endl;

			std::cout << "Acceleration: ";
			for (std::vector<double>::iterator iAcc = acc.begin(); iAcc != acc.end(); iAcc++) {
				std::cout << *iAcc << " ";
			}
			std::cout << std::endl;

			usleep(500000);
			count++;
		}
	}
};

int main(int argc, char *argv[]) {

	QApplication application(argc, argv);
	VestibularTester* a = new VestibularTester();
	boost::thread* t = new boost::thread(boost::bind(&VestibularTester::run, a));

	return application.exec();

}

