#include "vestibularangularratechannelfactory.h"
#include "vestibularangularratechannel.h"
#include "../../channel/linearnormalizer.h"
#include <boost/lexical_cast.hpp>
#include "../vestibular.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

VestibularAngularRateChannelFactory::VestibularAngularRateChannelFactory() : ChannelFactory("channel:angularRate") {
}

void VestibularAngularRateChannelFactory::createFromDomElement(QDomElement element, Device *device) {
    std::string name = element.attribute("name", "angularRate").toStdString();
    int dimension = element.attribute("dimension").toInt();
    std::stringstream fullName;
    fullName << name << "." << dimension;
    name = fullName.str();
    double min = element.attribute("min", boost::lexical_cast<std::string>(device->toVestibular()->getAngularRateMin()[dimension]).c_str()).toDouble();
    double max = element.attribute("max", boost::lexical_cast<std::string>(device->toVestibular()->getAngularRateMax()[dimension]).c_str()).toDouble();
    device::channel::ChannelType type = device::channel::channelTypeFromString(element.attribute("type").toStdString());

    device->getChannels()->add(new VestibularAngularRateChannel(name, type, dimension, new device::channel::LinearNormalizer(min, max), device));
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
