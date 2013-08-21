#ifndef DROBOT_DEVICE_CHANNEL_CHANNELFACTORY_H
#define DROBOT_DEVICE_CHANNEL_CHANNELFACTORY_H

#include "../../object/item.h"
#include <QDomElement>
#include "../device.h"

namespace drobot {
namespace device {
class DeviceManager;

namespace channel {

class ChannelFactory : public object::Item
{
public:
    ChannelFactory(std::string name);
    virtual void createFromDomElement(QDomElement element, Device* device) = 0;
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_CHANNEL_CHANNELFACTORY_H
