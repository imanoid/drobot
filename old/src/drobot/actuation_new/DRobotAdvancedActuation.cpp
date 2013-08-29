#include "DRobotAdvancedActuation.h"
#include <sstream>

namespace drobot {

DRobotAdvancedActuation::DRobotAdvancedActuation(int serial) {
	int result;
	const char *err;
	_phidgetHandle = 0;

	//create handle
	CPhidgetAdvancedServo_create(&_phidgetHandle);

	//open the servo for device connections
	CPhidget_open((CPhidgetHandle) _phidgetHandle, serial);

	//get the program to wait for an servo device to be attached
	if ((result = CPhidget_waitForAttachment((CPhidgetHandle) _phidgetHandle,
			20000))) {
		CPhidget_getErrorDescription(result, &err);
		std::stringstream errorMsg;
		errorMsg << "Problem waiting for attachment: " << err;
		throw errorMsg.str();
	}

	for (int i = 0; i < getMotorCount(); i++) {
		_motors.push_back(new DRobotAdvancedServoMotor(_phidgetHandle, i));
	}
}

void DRobotAdvancedActuation::engage() {
	for (int i = 0; i < _motors.size(); i++) {
		_motors[i].engage();
	}
}

void DRobotAdvancedActuation::disengage() {
	for (int i = 0; i < _motors.size(); i++) {
		_motors[i].disengage();
	}
}

const int DRobotAdvancedActuation::getMotorCount() {
	int* count;
	CPhidgetAdvancedServo_getMotorCount(_phidgetHandle, count);
	return *count;
}

}
