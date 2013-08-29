#include "DRobotAbstractServoMotor.h"

namespace drobot {

void DRobotAbstractServoMotor::rotate(double angle) {
	setPosition(getPosition() + angle);
}

}
