#include "simpletactilesensor.h"
#include "../deviceboard.h"

namespace drobot {
namespace device {
namespace tactile {

SimpleTactileSensor::SimpleTactileSensor(int index) {
    _index = index;
    _value = 0;
    _enabled = false;
}

SimpleTactileSensor::SimpleTactileSensor(int index, double value) {
    _index = index;
    _value = value;
    _enabled = false;
}

double SimpleTactileSensor::getValue() {
    return _value;
}

void SimpleTactileSensor::setValue(double value) {
    _value = value;
}

void SimpleTactileSensor::enable() {
    _enabled = true;
    DeviceBoard* deviceBoard = getDeviceBoard();
    if (deviceBoard != 0 && !deviceBoard->isEnabled())
        deviceBoard->enable();
}

void SimpleTactileSensor::disable() {
    _enabled = false;
}

bool SimpleTactileSensor::isEnabled() {
    return _enabled;
}

}
}
}
