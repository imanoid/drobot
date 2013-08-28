#ifndef DROBOT_DEVICE_DEVICEFACTORY_H
#define DROBOT_DEVICE_DEVICEFACTORY_H

#include <QtXml/QDomElement>
#include <vector>
#include "../object/item.h"
#include "channel/channelfactory.h"

namespace drobot {
namespace robot {
class Robot;
}
namespace device {

/**
 * @brief Base class for DeviceFactories.
 * @details used to create a device from a Dom Tree element (QDomElement) and add it to a robot.
 *  The name of the DeviceFactory must be the same as the tagName of the xml elements.
 */
class DeviceFactory : public object::Item
{
protected:
    /**
     * @brief list of this device type's ChannelFactories.
     */
    object::Manager<channel::ChannelFactory>* _channelFactories;
public:
    DeviceFactory(std::string name);
    virtual ~DeviceFactory();
    /**
     * @brief createFromDomElement
     * @param element
     * @param robot
     *
     * @details Creates a device from a QDomElement. This method should add the device of the robots DeviceManager.
     *  If the created Device is a Controller the controller property of the robot should also be set. Each device element
     *  may contain channel elements which have to be parsed by the channelFactories. Also if the device have need of a DeviceBoard
     *  it should be added to the DeviceManager too. See actuator/phidgetadvancedservofactory.cpp for an example.
     */
    virtual void createFromDomElement(QDomElement element, robot::Robot* robot) = 0;
};

} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_DEVICEFACTORY_H
