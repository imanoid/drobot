#include "actuatorpositionchannelfactory.h"
#include "actuatorpositionchannel.h"
#include "../../channel/linearnormalizer.h"
#include <boost/lexical_cast.hpp>
#include "../actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorPositionChannelFactory::ActuatorPositionChannelFactory() : ChannelFactory("channel:position") {
}

void ActuatorPositionChannelFactory::createFromDomElement(QDomElement element, Device *device) {
    std::string name = element.attribute("name", "position").append(QString(".")).append(element.attribute("type").toLower()).toStdString();
    double min = element.attribute("min", boost::lexical_cast<std::string>(device->toActuator()->getPositionMin()).c_str()).toDouble();
    double max = element.attribute("max", boost::lexical_cast<std::string>(device->toActuator()->getPositionMax()).c_str()).toDouble();
    device::channel::ChannelType type = device::channel::channelTypeFromString(element.attribute("type").toStdString());

    device->getChannels()->add(new ActuatorPositionChannel(name, type, new device::channel::LinearNormalizer(min, max), device));
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
