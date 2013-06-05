#include "DRobotTactileSensorBoard.h"
#include <algorithm>
#include <boost/thread.hpp>
#include "../utils/rs232/rs232.h"

namespace drobot {
int DRobotTactileSensorBoard::getSensorActivation(int index) {
	if (!_enabled)
		return 0;
	else
		return (int)_activations[index];
}

void DRobotTactileSensorBoard::enable() {
	if (!_enabled) {
		_enabled = true;
		boost::thread* t = new boost::thread(
				boost::bind(&DRobotTactileSensorBoard::updateLoop, this));
	}
}

void DRobotTactileSensorBoard::disable() {
	_enabled = false;
}

void DRobotTactileSensorBoard::updateLoop() {
	struct termios initialPortSettings;
	int portFileDescriptor;
	bool aligned = false;

	if ((portFileDescriptor = RS232_OpenPort(_device.c_str(), 230400, true,
			&initialPortSettings)) == -1) {
		std::cerr << "Couldn't open port! Device name is: '" << _device << "'."
				<< std::endl;
		return;
	}

	while (_enabled) {
		_activations = new unsigned char[_maxSensors + 2];
		while (!aligned) {
			RS232_ReceiveBuffer(portFileDescriptor, _activations, _maxSensors);
			for (int index = 1; index < 34; index++) {
				if (_activations[index - 1] == 255 && _activations[index] == 255) {
					if (RS232_ReceiveBuffer(portFileDescriptor, _activations,
							_maxSensors - index + 1)
							== _maxSensors - index + 1) {
						aligned = true;
					}

					break;
				}
			}

			if (_activations[0] == 255 && _activations[_maxSensors + 1] == 255) {
				if (RS232_ReceiveBuffer(portFileDescriptor, _activations, 1) == 1) {
					aligned = true;
				}
			}
		}

		int read = 0;
		while (read < _maxSensors + 2) {
			read += std::max(
					RS232_ReceiveBuffer(portFileDescriptor, _activations + read,
							_maxSensors + 2 - read), 0); //usleep(100);
		}

		/*
		for (int signal = 0; signal < _maxSensors; signal++) {
			std::cout << (int) _activations[signal] << "; ";
		}
		std::cout << std::endl << std::endl;
		*/

		if (_activations[_maxSensors] != 255 || _activations[_maxSensors + 1] != 255) {
			aligned = false;
			//std::cout << "not aligned" << std::endl;
			continue;
		}

		usleep(1000);
	}

	RS232_ClosePort(portFileDescriptor, &initialPortSettings);
}

void DRobotTactileSensorBoard::setMaxSensors(int maxSensors) {
	_maxSensors = maxSensors;
}

int DRobotTactileSensorBoard::getMaxSensors() {
	return _maxSensors;
}

}
