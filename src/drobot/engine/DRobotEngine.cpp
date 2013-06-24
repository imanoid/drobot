#include "DRobotEngine.h"

namespace drobot {
void DRobotEngine::initialize() {
	std::vector < std::string > inputs;
	for (std::vector<DRobotInputDevice>::iterator iDRobotInputDevice =
			_inputDevices.begin(); iDRobotInputDevice != _inputDevices.end();
			iDRobotInputDevice++) {
		std::vector < std::string > deviceInputs =
				iDRobotInputDevice->getAvailableInputs();
		inputs.insert(inputs.end(), deviceInputs.begin(), deviceInputs.end());
	}
	std::vector < std::string > outputs;

	for (std::vector<DRobotOutputDevice>::iterator iDRobotOutputDevice =
			_outputDevices.begin(); iDRobotOutputDevice != _outputDevices.end();
			iDRobotOutputDevice++) {
		std::vector < std::string > deviceOutputs =
				iDRobotOutputDevice->getAvailableOutputs();
		outputs.insert(outputs.end(), deviceOutputs.begin(),
				deviceOutputs.end());
	}

	_perceptron = new DRobotPerceptron(inputs, outputs);
}

void DRobotEngine::step(int time) {
	std::map<std::string, double> inputs;
	for (std::vector<DRobotInputDevice>::iterator iDRobotInputDevice =
			_inputDevices.begin(); iDRobotInputDevice != _inputDevices.end();
			iDRobotInputDevice++) {
		std::map<std::string, double> deviceInputs =
				iDRobotInputDevice->getInputs();
		inputs.insert(deviceInputs.begin(), deviceInputs.end());
	}
	/*
	 * TODO:
	 * 1. apply inputs to perceptron
	 * 2. do learning algorithm
	 * 3. fill "outputs" map
	 */
	std::map<std::string, double> outputs; //<-- perceptron outputs go here

	for (std::vector<DRobotOutputDevice>::iterator iDRobotOutputDevice =
			_outputDevices.begin(); iDRobotOutputDevice != _outputDevices.end();
			iDRobotOutputDevice++) {
		std::vector < string > availableDeviceOutputs =
				iDRobotOutputDevice->getAvailableOutputs();
		std::map<std::string, double> deviceOutputs;
		for (vector<string>::iterator iOutput = availableDeviceOutputs.begin();
				iOutput != availableDeviceOutputs.end(); iOutput++) {
			deviceOutputs[*iOutput] = outputs[*iOutput];
		}
		iDRobotOutputDevice->setOutputs(deviceOutputs);
	}
}
}
