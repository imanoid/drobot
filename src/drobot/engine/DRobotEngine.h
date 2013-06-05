#ifndef _DROBOT_DROBOTENGINE_H_
#define _DROBOT_DROBOTENGINE_H_

#include <string>
#include <vector>
#include <map>
#include "../device/InputDevice.h"
#include "../device/OutputDevice.h"
#include "../learning/DRobotPerceptron.h"

namespace drobot {
class DRobotEngine {
private:
	std::vector<DRobotInputDevice> _inputDevices;
	std::vector<DRobotOutputDevice> _outputDevices;
	DRobotPerceptron* _perceptron;
public:
	DRobotEngine() {
	}

	DRobotEngine(std::vector<InputDevice> inputDevices, std::vector<OutputDevice> outputDevices) :
			_inputDevices(inputDevices), _outputDevices(outputDevices) {
		this->initialize();
	}

	void initialize();

	void step(int time);
};
}

#endif
