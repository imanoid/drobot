#include "simpletactilesensor.h"
#include "../deviceboard.h"
#include "channel/tactilesensorvaluechannel.h"
#include "../channel/linearnormalizer.h"

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

void SimpleTactileSensor::initChannels() {
    channel::TactileSensorValueChannel* value = new channel::TactileSensorValueChannel("value", new device::channel::LinearNormalizer(0, 255), this);
    addInputChannel(value);
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
