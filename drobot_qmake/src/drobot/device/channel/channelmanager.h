#ifndef DROBOT_DEVICE_CHANNEL_CHANNELMANAGER_H
#define DROBOT_DEVICE_CHANNEL_CHANNELMANAGER_H

#include "channel.h"
#include <vector>
#include <map>
#include "../../object/manager.h"
#include "channeltype.h"

namespace drobot {
namespace device {
namespace channel {

/**
 * @brief Special implementation of a Manager for Channel Items.
 */
class ChannelManager : public object::Manager<Channel> {
public:
    ChannelManager();
    ChannelManager(std::vector<Channel*> items);
    /**
     * @brief returns channels filtered by type
     * @param type
     * @return channels
     */
    std::vector<Channel*> listByType(ChannelType type);
    /**
     * @brief executes the read() method on all channels
     */
    void read();
    /**
     * @brief executes the write() method on all channels
     */
    void write();
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_CHANNEL_CHANNELMANAGER_H
