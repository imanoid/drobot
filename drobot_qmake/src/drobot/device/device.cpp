#include "device.h"
#include "vestibular/vestibular.h"
#include "tactile/tactilesensor.h"
#include "actuator/actuator.h"

namespace drobot {
namespace device {

Device::Device(std::string name) {
    _name = name;
}

DeviceBoard* Device::getDeviceBoard() {
    return _deviceBoard;
}

void Device::setDeviceBoard(DeviceBoard* deviceBoard) {
    _deviceBoard = deviceBoard;
}

std::string Device::getName() {
    return _name;
}

void Device::setName(std::string name) {
    _name = name;
}

actuator::Actuator* Device::toActuator() {
    return dynamic_cast<actuator::Actuator*>(this);
}

tactile::TactileSensor* Device::toTactileSensor() {
    return dynamic_cast<tactile::TactileSensor*>(this);
}

vestibular::Vestibular* Device::toVestibular() {
    return dynamic_cast<vestibular::Vestibular*>(this);
}

}
}
