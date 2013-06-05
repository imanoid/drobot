#include <iostream>
#include <sstream>

#include "DRobotActuationEvents.h"
#include "DRobotActuation.h"

namespace drobot {

DRobotActuation::DRobotActuation() :
		servo(0) {

	//create the servo object
	CPhidgetServo_create(&servo);

	//Set the handlers to be run when the device is plugged in or opened from software,
	//unplugged or closed from software, or generates an error.
	CPhidget_set_OnAttach_Handler((CPhidgetHandle) servo, AttachHandler, NULL);
	CPhidget_set_OnDetach_Handler((CPhidgetHandle) servo, DetachHandler, NULL);
	CPhidget_set_OnError_Handler((CPhidgetHandle) servo, ErrorHandler, NULL);

	//Registers a callback that will run when the motor position is changed.
	//Requires the handle for the Phidget, the function that will be called,
	//and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetServo_set_OnPositionChange_Handler(servo, PositionChangeHandler,
			NULL);

	initCommunication();

}

void DRobotActuation::addServoMotor(std::string name, int board, int index,
		double iPosition, double min, double max) {
	DRobotServoMotor* motor = new DRobotServoMotor(servo);
	motor->setName(name);
	motor->setBoard(board, index);
	motor->setInitialPosition(iPosition);
	motor->setMinMax(min, max);

	_motors.push_back(motor);
}

void DRobotActuation::initCommunication() {

	int result;
	const char *err;

	//open the servo for device connections
	CPhidget_open((CPhidgetHandle) servo, -1);

	//get the program to wait for an servo device to be attached
	std::cout << "Waiting for Servo controller to be attached..." << std::endl;

	if ((result = CPhidget_waitForAttachment((CPhidgetHandle) servo, 20000))) {
		CPhidget_getErrorDescription(result, &err);
		std::stringstream errorMsg;
		errorMsg << "Problem waiting for attachment: " << err;
		std::cerr << errorMsg.str() << std::endl;
		throw errorMsg.str();
	}

	//Display the properties of the attached servo device
	this->displayProperties();

	//read servo event data
	std::cout << "Reading..." << std::endl;

}

// Display the properties of the attached phidget to the screen.
// We will be displaying the name, serial number and version of the attached device.
int DRobotActuation::displayProperties() {
	int serialNo, version, numMotors;
	const char* deviceType;

	CPhidget_getDeviceType((CPhidgetHandle) servo, &deviceType);
	CPhidget_getSerialNumber((CPhidgetHandle) servo, &serialNo);
	CPhidget_getDeviceVersion((CPhidgetHandle) servo, &version);

	CPhidgetServo_getMotorCount(servo, &numMotors);

	std::cout << deviceType << std::endl;
	std::cout << "Serial number: " << serialNo << std::endl;
	std::cout << "Version: " << version << std::endl;
	std::cout << "# Motors: " << numMotors << std::endl;

	return 0;
}

}
