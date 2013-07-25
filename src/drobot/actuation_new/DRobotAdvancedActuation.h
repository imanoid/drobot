#ifndef _DROBOT_DROBOTADVANCEDACTUATION_H_
#define _DROBOT_DROBOTADVANCEDACTUATION_H_

#include "phidget21.h"
#include "DRobotAbstractActuation.h"

namespace drobot {

class DRobotAdvancedActuation : DRobotAbstractActuation {
public:
	DRobotAdvancedActuation(int serial);
	virtual ~DRobotAdvancedActuation() {};
	virtual void engage();
	virtual void disengage();
private:
	virtual const int getMotorCount();
	CPhidgetAdvancedServoHandle _phidgetHandle;
};

}

#endif
