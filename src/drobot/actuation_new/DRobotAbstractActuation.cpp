#include "DRobotAbstractActuation.h"

namespace drobot {

const std::vector<drobot::DRobotAbstractServoMotor*> DRobotAbstractActuation::getMotors() const {
	return this->_motors;
}

}
