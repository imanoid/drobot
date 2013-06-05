#ifndef _DROBOT_DROBOTOUTPUTDEVICE_H_
#define _DROBOT_DROBOTOUTPUTDEVICE_H_

#include <map>
#include <vector>
#include <string>

namespace drobot {
class DRobotOutputDevice {
	virtual std::vector<std::string> getAvailableOutputs() = 0;
	virtual void setOutputs(std::map<std::string, double> outputs) = 0;
};
}

#endif
