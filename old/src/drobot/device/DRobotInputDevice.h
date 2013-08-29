#ifndef _DROBOT_DROBOTINPUTDEVICE_H_
#define _DROBOT_DROBOTINPUTDEVICE_H_

#include <map>
#include <string>
#include <vector>

namespace drobot {
class DRobotInputDevice {
public:
	virtual std::map<std::string, double> getInputs() = 0;
	virtual std::vector<std::string> getAvailableInputs() = 0;
};
}

#endif
