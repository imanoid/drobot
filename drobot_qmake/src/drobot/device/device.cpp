#include "device.h"
#include "vestibular/vestibular.h"
#include "tactile/tactilesensor.h"
#include "actuator/actuator.h"
#include "deviceboard.h"
#include <sstream>

namespace drobot {
namespace device {

Device::Device(std::string name) : Item(name) {
    _channelManager = new channel::ChannelManager;
    _deviceBoard = 0;
}

std::string Device::getName() {
    if (_deviceBoard != 0) {
        std::stringstream name;
        name << _deviceBoard->getName() << "." << _name;
        return name.str();
    } else {
        return Item::getName();
    }
}

DeviceBoard* Device::getDeviceBoard() {
    return _deviceBoard;
}

void Device::setDeviceBoard(DeviceBoard* deviceBoard) {
    _deviceBoard = deviceBoard;
}

Device* Device::toDevice() {
    return dynamic_cast<Device*>(this);
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

channel::ChannelManager* Device::getChannelManager() {
    return _channelManager;
}

}
}
