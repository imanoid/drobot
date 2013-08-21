#include "actuatorvelocitychannelfactory.h"
#include "actuatorvelocitychannel.h"
#include "../../channel/linearnormalizer.h"
#include <boost/lexical_cast.hpp>
#include "../actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorVelocityChannelFactory::ActuatorVelocityChannelFactory() : ChannelFactory("channel:velocity") {
}

void ActuatorVelocityChannelFactory::createFromDomElement(QDomElement element, Device *device) {
    std::string name = element.attribute("name", "velocity").toStdString();
    double min = element.attribute("min", boost::lexical_cast<std::string>(device->toActuator()->getVelocityMin()).c_str()).toDouble();
    double max = element.attribute("max", boost::lexical_cast<std::string>(device->toActuator()->getVelocityMin()).c_str()).toDouble();
    device::channel::ChannelType type = device::channel::channelTypeFromString(element.attribute("type").toStdString());

    device->getChannels()->add(new ActuatorVelocityChannel(name, type, new device::channel::LinearNormalizer(min, max), device));
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
