#include "actuatoraccelerationchannelfactory.h"
#include "actuatoraccelerationchannel.h"
#include "../../channel/linearnormalizer.h"
#include <boost/lexical_cast.hpp>
#include "../actuator.h"

namespace drobot {
namespace device {
namespace actuator {
namespace channel {

ActuatorAccelerationChannelFactory::ActuatorAccelerationChannelFactory() : ChannelFactory("channel:acceleration") {
}

void ActuatorAccelerationChannelFactory::createFromDomElement(QDomElement element, Device *device) {
    std::string name = element.attribute("name", "acceleration").append(QString(".")).append(element.attribute("type").toLower()).toStdString();
    double min = element.attribute("min", boost::lexical_cast<std::string>(device->toActuator()->getAccelerationMin()).c_str()).toDouble();
    double max = element.attribute("max", boost::lexical_cast<std::string>(device->toActuator()->getAccelerationMax()).c_str()).toDouble();
    device::channel::ChannelType type = device::channel::channelTypeFromString(element.attribute("type").toStdString());

    device->getChannels()->add(new ActuatorAccelerationChannel(name, type, new device::channel::LinearNormalizer(min, max), device));
}

} // namespace channel
} // namespace actuator
} // namespace device
} // namespace drobot
