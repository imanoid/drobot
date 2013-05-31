
#include <iostream>
using std::cout;
using std::endl;
#include "DRobotVestibular.h"
using drobot::DRobotVestibular;
#include <QApplication>
#include <boost/thread.hpp>
#include "../utils/DRobotTimePlotter/DRobotTimePlotter.h"
using drobot::DRobotTimePlotter;
#include <vector>
using std::vector;
#include <string>
using std::string;

//#include "DRobotPlotter.h"

class VestibularTester {
private:
	DRobotTimePlotter* _plotter;
public:
	VestibularTester() {
		vector<string> labels;
		labels.push_back("angularRateX");
		labels.push_back("angularRateY");
		labels.push_back("angularRateZ");
		labels.push_back("accelerationX");
		labels.push_back("accelerationY");
		labels.push_back("accelerationZ");
		_plotter = new DRobotTimePlotter("test", 20, 20, 500, 300,
						labels);
		_plotter->show();
	}

	void run() {

		int key;

		DRobotVestibular* v = new DRobotVestibular();
		v->zeroGyro();

		double values[6];
		int count = 0;

		while (true) {
			vector<double> ang = v->getAngularRate();
			vector<double> acc = v->getAcceleration();

			values[0] = ang[0];
			values[1] = ang[1];
			values[2] = ang[2];
			values[3] = acc[0];
			values[4] = acc[1];
			values[5] = acc[2];

			_plotter->update(count, values);

			cout << "Angular rate: ";
			for (vector<double>::iterator iAng = ang.begin(); iAng != ang.end(); iAng++) {
				cout << *iAng << " ";
			}
			cout << endl;

			cout << "Acceleration: ";
			for (vector<double>::iterator iAcc = acc.begin(); iAcc != acc.end(); iAcc++) {
				cout << *iAcc << " ";
			}
			cout << endl;

			usleep(500000);
			count++;
		}
	}
};

int main(int argc, char *argv[]) {

	QApplication application(argc, argv);
	cout << "start" << endl;
	VestibularTester* a = new VestibularTester();
	boost::thread* t = new boost::thread(boost::bind(&VestibularTester::run, a));

	cout << "exec" << endl;
	return application.exec();

}

