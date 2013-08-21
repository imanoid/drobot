#include "vestibularmagneticfieldchannelfactory.h"
#include "vestibularmagneticfieldchannel.h"
#include "../../channel/linearnormalizer.h"
#include <boost/lexical_cast.hpp>
#include "../vestibular.h"

namespace drobot {
namespace device {
namespace vestibular {
namespace channel {

VestibularMagneticFieldChannelFactory::VestibularMagneticFieldChannelFactory() : ChannelFactory("channel:magneticField") {
}

void VestibularMagneticFieldChannelFactory::createFromDomElement(QDomElement element, Device *device) {
    std::string name = element.attribute("name", "position").toStdString();
    int dimension = element.attribute("dimension").toInt();
    std::stringstream fullName;
    fullName << name << "." << dimension;
    name = fullName.str();
    double min = element.attribute("min", boost::lexical_cast<std::string>(device->toVestibular()->getMagneticFieldMin()[dimension]).c_str()).toDouble();
    double max = element.attribute("max", boost::lexical_cast<std::string>(device->toVestibular()->getMagneticFieldMax()[dimension]).c_str()).toDouble();
    device::channel::ChannelType type = device::channel::channelTypeFromString(element.attribute("type").toStdString());

    device->getChannels()->add(new VestibularMagneticFieldChannel(name, type, dimension, new device::channel::LinearNormalizer(min, max), device));
}

} // namespace channel
} // namespace vestibular
} // namespace device
} // namespace drobot
