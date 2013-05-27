
#include <iostream>
#include <sstream>

using std::stringstream;

#include "DRobotActuationEvents.h"
#include "DRobotActuation.h"


namespace drobot
{

DRobotActuation::DRobotActuation( ) :
servo(0)
{

	//create the servo object
	CPhidgetServo_create(&servo);

	//Set the handlers to be run when the device is plugged in or opened from software,
	//unplugged or closed from software, or generates an error.
	CPhidget_set_OnAttach_Handler((CPhidgetHandle)servo, AttachHandler, NULL);
	CPhidget_set_OnDetach_Handler((CPhidgetHandle)servo, DetachHandler, NULL);
	CPhidget_set_OnError_Handler((CPhidgetHandle)servo, ErrorHandler, NULL);

	//Registers a callback that will run when the motor position is changed.
	//Requires the handle for the Phidget, the function that will be called,
	//and an arbitrary pointer that will be supplied to the callback function (may be NULL).
	CPhidgetServo_set_OnPositionChange_Handler(servo, PositionChangeHandler, NULL);

	initCommunication();

}


DRobotActuation::~DRobotActuation( )
{


}


void
DRobotActuation::addServoMotor(std::string name, int board, int index, double iPosition, double min, double max)
{
	DRobotServoMotor* motor = new DRobotServoMotor(servo);
	motor->setName(name);
	motor->setBoard(board, index);
	motor->setInitialPosition(iPosition);
	motor->setMinMax(min, max);

	motors.push_back(motor);
}


void
DRobotActuation::setInitialPositions()
{
	std::cerr << "N MOTORS: " << motors.size() << std::endl;

	for(int i=0; i < motors.size(); i++)
	{
		motors[i]->setInitialPosition();
	}

}


int
DRobotActuation::getMotorPosition(int index)
{
	return motors[index]->getMotorPosition();
}


std::vector<double>
DRobotActuation::getMotorPositions()
{
	std::vector<double> mPositions;

	for(int i=0; i < motors.size(); i++)
	{
		double position = motors[i]->getMotorPosition();
		mPositions.push_back(position);
	}

	return mPositions;
}


void
DRobotActuation::setMotorPosition(int index, double position)
{
	motors[index]->setMotorPosition(position);
}


void
DRobotActuation::setMotorPositions(std::vector<double> positions)
{

}

void
DRobotActuation::setMotorIncrement(int index, double increment)
{
	motors[index]->setMotorPosition(motors[index]->getMotorPosition() + increment);
}



void
DRobotActuation::displayMotorPositions( )
{
	std::cout << "Motor Positions (" << motors.size() << "): " << std::endl;

	for(int i=0; i < motors.size(); i++)
	{
		std::cout << "Motor " << i << " : " << motors[i]->getMotorPosition() << std::endl;
	}
}


void
DRobotActuation::initCommunication()
{

	int result;
	const char *err;

	//open the servo for device connections
    CPhidget_open((CPhidgetHandle)servo, -1);

	//get the program to wait for an servo device to be attached
	std::cout << "Waiting for Servo controller to be attached..." << std::endl;

    if((result = CPhidget_waitForAttachment((CPhidgetHandle)servo, 20000)))
	{
		CPhidget_getErrorDescription(result, &err);
        stringstream errorMsg;
        errorMsg << "Problem waiting for attachment: " << err;
        std::cerr << errorMsg.str() << std::endl;
        throw errorMsg.str();
	}

	//Display the properties of the attached servo device
	this->displayProperties(servo);

	//read servo event data
	std::cout << "Reading..." << std::endl;

}


// Display the properties of the attached phidget to the screen.
// We will be displaying the name, serial number and version of the attached device.
int
DRobotActuation::displayProperties(CPhidgetServoHandle phid)
{
	int serialNo, version, numMotors;
	const char* ptr;

	CPhidget_getDeviceType((CPhidgetHandle)phid, &ptr);
	CPhidget_getSerialNumber((CPhidgetHandle)phid, &serialNo);
	CPhidget_getDeviceVersion((CPhidgetHandle)phid, &version);

	CPhidgetServo_getMotorCount (phid, &numMotors);

	std::cout << ptr << std::endl;
	std::cout << "Serial number: " << serialNo << std::endl;
	std::cout << "Version: " << version << std::endl;
	std::cout << "# Motors: " << numMotors << std::endl;

	return 0;
}




}
