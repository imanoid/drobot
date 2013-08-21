#include "tactilesensorvaluechannelfactory.h"
#include "tactilesensorvaluechannel.h"
#include "../../channel/linearnormalizer.h"
#include <boost/lexical_cast.hpp>
#include "../tactilesensor.h"

namespace drobot {
namespace device {
namespace tactile {
namespace channel {

TactileSensorValueChannelFactory::TactileSensorValueChannelFactory() : ChannelFactory("channel:value") {
}

void TactileSensorValueChannelFactory::createFromDomElement(QDomElement element, Device *device) {
    std::string name = element.attribute("name", "value").toStdString();
    double min = element.attribute("min", boost::lexical_cast<std::string>(device->toTactileSensor()->getValueMin()).c_str()).toDouble();
    double max = element.attribute("max", boost::lexical_cast<std::string>(device->toTactileSensor()->getValueMax()).c_str()).toDouble();
    device::channel::ChannelType type = device::channel::channelTypeFromString(element.attribute("type").toStdString());

    device->getChannels()->add(new TactileSensorValueChannel(name, type, new device::channel::LinearNormalizer(min, max), device));
}

} // namespace channel
} // namespace tactile
} // namespace device
} // namespace drobot
