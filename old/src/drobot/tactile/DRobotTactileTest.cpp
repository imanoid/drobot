#include <iostream>
#include <QApplication>
#include <boost/thread.hpp>
#include <vector>
#include <string>
#include "../utils/rs232/rs232.h"
#include <algorithm>
#include "DRobotTactileSensorBoard.h"
#include "../actuation/DRobotAdvancedActuation.h"
#include "../utils/DRobotTimePlotter/DRobotTimePlotter.h"
#include <stdio.h>
#include <boost/lexical_cast.hpp>

class TactileTester {
private:
	drobot::DRobotTimePlotter* _plotter;
public:
	TactileTester() {
		std::vector < std::string > labels;
		labels.push_back("sensor0");
		_plotter = new drobot::DRobotTimePlotter("test", 20, 20, 500, 300,
				labels);
		_plotter->show();
	}

	void run() {
		drobot::DRobotTactileSensorBoard* sensorBoard =
				new drobot::DRobotTactileSensorBoard("/dev/ttyUSB0");
		sensorBoard->enable();
		int tick = 0;
		while (true) {
			double* readings = new double[sensorBoard->getMaxSensors()];
			for (int index = 0; index < sensorBoard->getMaxSensors(); index++) {
				char val[4];
				sprintf(val, "%03d", sensorBoard->getSensorActivation(index));
				if (index == 15)
					readings[0] = boost::lexical_cast<int>(val);
			}
			_plotter->update(tick, readings);
			usleep(50000);
			++tick;
		}
	}
};

int main(int argc, char *argv[]) {
	QApplication application(argc, argv);
	TactileTester* a = new TactileTester();
	boost::thread* t = new boost::thread(boost::bind(&TactileTester::run, a));

	return application.exec();
}

