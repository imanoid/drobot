#ifndef DROBOT_DEVICE_DEVICEFACTORY_H
#define DROBOT_DEVICE_DEVICEFACTORY_H

#include <QtXml/QDomElement>
#include <vector>
#include "../object/item.h"
#include "channel/channelfactory.h"

namespace drobot {
namespace device {

class DeviceManager;

class DeviceFactory : public object::Item
{
protected:
    object::Manager<channel::ChannelFactory>* _channelFactories;
public:
    DeviceFactory(std::string name);
    virtual void createFromDomElement(QDomElement element, DeviceManager* devices) = 0;
    object::Manager<channel::ChannelFactory>* getChannelFactories();
};

} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_DEVICEFACTORY_H
