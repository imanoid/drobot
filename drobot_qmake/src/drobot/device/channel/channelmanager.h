#ifndef DROBOT_CHANNEL_CHANNELMANAGER_H
#define DROBOT_CHANNEL_CHANNELMANAGER_H

#include "channel.h"
#include <vector>
#include <map>
#include "../../object/manager.h"
#include "channeltype.h"

namespace drobot {
namespace device {
namespace channel {

class ChannelManager : public object::Manager<Channel>
{
public:
    ChannelManager();
    ChannelManager(std::vector<Channel*> items);
    std::vector<Channel*> listByType(ChannelType type);
    void read();
    void write();
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_CHANNEL_CHANNELMANAGER_H
