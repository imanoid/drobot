#include "simpletactilesensor.h"
#include "../deviceboard.h"
#include "channel/tactilesensorvaluechannel.h"
#include "../channel/linearnormalizer.h"
#include "../deviceConstants.h"

namespace drobot {
namespace device {
namespace tactile {

SimpleTactileSensor::SimpleTactileSensor(std::string name, int index) : TactileSensor(name) {
    _index = index;
    _value = 0;
    _enabled = false;
}

SimpleTactileSensor::SimpleTactileSensor(std::string name, int index, double value) : TactileSensor(name) {
    _index = index;
    _value = value;
    _enabled = false;
}

int SimpleTactileSensor::getIndex() {
    return _index;
}

double SimpleTactileSensor::getValue() {
    return _value;
}

void SimpleTactileSensor::setValue(double value) {
    if (value <= 2)
        value = 0;
    _value = value;
}

double SimpleTactileSensor::getValueMin() {
    return SIMPLE_TACTILE_SENSOR_MIN_VALUE_DEFAULT;
}

double SimpleTactileSensor::getValueMax() {
    return SIMPLE_TACTILE_SENSOR_MAX_VALUE_DEFAULT;
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
