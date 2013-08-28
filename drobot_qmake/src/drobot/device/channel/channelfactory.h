#ifndef DROBOT_DEVICE_CHANNEL_CHANNELFACTORY_H
#define DROBOT_DEVICE_CHANNEL_CHANNELFACTORY_H

#include "../../object/item.h"
#include <QDomElement>
#include "../device.h"

namespace drobot {
namespace device {
class DeviceManager;

namespace channel {

/**
 * @brief The ChannelFactory class
 * @details used to create a channel from a Dom Tree element (QDomElement) and add it to a device.
 *  The name of the ChannelFactory must be the same as the tagName of the xml elements.
 */
class ChannelFactory : public object::Item
{
public:
    ChannelFactory(std::string name);
    /**
     * @brief create channel from Dom Tree element
     * @details this method has to create one or more channels from the element and add it to the device.
     * @param element
     * @param device
     */
    virtual void createFromDomElement(QDomElement element, Device* device) = 0;
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_CHANNEL_CHANNELFACTORY_H
