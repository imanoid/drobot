#include "devicefactory.h"

namespace drobot {
namespace device {

DeviceFactory::DeviceFactory(std::string name) : Item(name) {
    _channelFactories = new object::Manager<channel::ChannelFactory>();
}

object::Manager<channel::ChannelFactory>* DeviceFactory::getChannelFactories() {
    return _channelFactories;
}

} // namespace device
} // namespace drobot
