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
		drobot::DRobotAdvancedActuation* actuation =
				new drobot::DRobotAdvancedActuation();

		actuation->addServoMotor("Left eye pan", 0, 0, 100, 80, 120);
		actuation->engage();
		actuation->setMotorPosition(0, 0);

		usleep(1000000);
		actuation->setMotorPosition(0, 90);
		usleep(500000);

		drobot::DRobotTactileSensorBoard* sensorBoard =
				new drobot::DRobotTactileSensorBoard("/dev/ttyUSB0");
		sensorBoard->enable();

		int tick = 0;
		while (tick < 100) {
			double* readings = new double[sensorBoard->getMaxSensors()];
			for (int index = 0; index < sensorBoard->getMaxSensors(); index++) {
				char val[3];
				sprintf(val, "%3d;", sensorBoard->getSensorActivation(index));
				readings[index] = boost::lexical_cast<float>(val);
			}
			_plotter->update(tick, readings);
			usleep(50000);
			++tick;
		}
		actuation->disengage();
	}
};

int main(int argc, char *argv[]) {
	TactileTester* a = new TactileTester();
	a->run();
}

