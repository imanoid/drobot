#ifndef EVENTHANDLERS_H
#define EVENTHANDLERS_H

#include "phidget21.h"

int CCONV AttachHandler(CPhidgetHandle SERV, void *userptr);
int CCONV DetachHandler(CPhidgetHandle SERV, void *userptr);
int CCONV ErrorHandler(CPhidgetHandle SERV, void *userptr, int ErrorCode, const char *Description);
int CCONV PositionChangeHandler(CPhidgetServoHandle SERV, void *usrptr, int Index, double Value);
int CCONV AdvancedPositionChangeHandler(CPhidgetServoHandle SERV, void *usrptr, int Index, double Value);

#endif // EVENTHANDLERS_H
