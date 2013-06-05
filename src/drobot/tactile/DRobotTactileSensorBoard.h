#ifndef _DROBOT_DROBOTTACTILESENSORBOARD_H_
#define _DROBOT_DROBOTTACTILESENSORBOARD_H_

#include <vector>
#include <string>

namespace drobot {
class DRobotTactileSensorBoard {
private:
	bool _enabled;
	unsigned char* _activations;
	int _maxSensors;
	std::string _device;
public:
	DRobotTactileSensorBoard(std::string device) : _device(device), _maxSensors(32) {
	}
	DRobotTactileSensorBoard(std::string device, int maxSensors) : _device(device), _maxSensors(maxSensors) {
	}
	int getSensorActivation(int index);
	void enable();
	void disable();
	void updateLoop();
	void setMaxSensors(int maxSensors);
	int getMaxSensors();
};
}

#endif
