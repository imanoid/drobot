#ifndef DROBOT_DEVICE_CHANNEL_NORMALIZERFACTORY_H
#define DROBOT_DEVICE_CHANNEL_NORMALIZERFACTORY_H

#include <QDomElement>
#include "channel.h"

namespace drobot {
namespace device {
namespace channel {

class NormalizerFactory
{
public:
    virtual void createFromDomElement(QDomElement element, Channel* channel) = 0;
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_CHANNEL_NORMALIZERFACTORY_H
