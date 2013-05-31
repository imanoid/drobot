#include <iostream>

#include "phidget21.h"
#include "DRobotActuationEvents.h"

int CCONV AttachHandler(CPhidgetHandle SERV, void *userptr) {
	int serialNo;
	const char *name;

	CPhidget_getDeviceName (SERV, &name);
	CPhidget_getSerialNumber(SERV, &serialNo);
	std::cout << name << ": " << serialNo << " attached!" << std::endl;

	return 0;
}

int CCONV DetachHandler(CPhidgetHandle SERV, void *userptr) {
	int serialNo;
	const char *name;

	CPhidget_getDeviceName (SERV, &name);
	CPhidget_getSerialNumber(SERV, &serialNo);
	std::cout << name << ": " << serialNo << " detached!" << std::endl;

	return 0;
}

int CCONV ErrorHandler(CPhidgetHandle SERV, void *userptr, int ErrorCode, const char *Description) {
	std::cout << "Error handled. " << ErrorCode << ": " << Description << std::endl;

	return 0;
}

int CCONV PositionChangeHandler(CPhidgetServoHandle SERV, void *usrptr, int Index, double Value) {
	std::cout << "Motor " << Index << ": Current Position: " << Value << std::endl;

	return 0;
}

int CCONV AdvancedPositionChangeHandler(CPhidgetServoHandle SERV, void *usrptr, int Index, double Value) {
	std::cout << "Motor " << Index << ": Current Position: " << Value << std::endl;

	return 0;
}
