#ifndef DROBOT_DEVICE_CHANNEL_CHANNELTYPE_H
#define DROBOT_DEVICE_CHANNEL_CHANNELTYPE_H

#include <string>

namespace drobot {
namespace device {
namespace channel {

/**
 * @brief The ChannelType
 */
enum ChannelType { INPUT, OUTPUT, LOG };
ChannelType channelTypeFromString(std::string name);
std::string channelTypeToString(ChannelType type);

}
}
}

#endif // CHANNELTYPE_H
