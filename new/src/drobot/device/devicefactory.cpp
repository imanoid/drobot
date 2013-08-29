#include "devicefactory.h"

namespace drobot {
namespace device {

DeviceFactory::DeviceFactory(std::string name) : Item(name) {
    _channelFactories = new object::Manager<channel::ChannelFactory>();
}

DeviceFactory::~DeviceFactory() {
    delete _channelFactories;
}

} // namespace device
} // namespace drobot
