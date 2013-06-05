#include <iostream>
#include <QApplication>
#include <boost/thread.hpp>
#include <vector>
#include <string>
#include "../utils/rs232/rs232.h"
#include <algorithm>
#include "DRobotTactileSensorBoard.h"
#include "../actuation/DRobotAdvancedActuation.h"
#include <stdio.h>

class TactileTester {
public:
	TactileTester() {
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
			for (int index = 0; index < sensorBoard->getMaxSensors(); index++) {
				char val[3];
				sprintf(val, "%3d;", sensorBoard->getSensorActivation(index));
				std::cout << val;
			}
			std::cout << std::endl;
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

