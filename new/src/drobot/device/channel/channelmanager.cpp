#include "channelmanager.h"

namespace drobot {
namespace device {
namespace channel {

ChannelManager::ChannelManager() : Manager() {
}

ChannelManager::ChannelManager(std::vector<Channel *> items) : Manager(items) {
}

std::vector<Channel*> ChannelManager::listByType(ChannelType type) {
    std::vector<Channel*> channels = values();
    std::vector<Channel*> result;

    for (std::vector<Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        if ((*iChannel)->getType() == type)
            result.push_back(*iChannel);
    }

    return result;
}

void ChannelManager::read() {
    std::vector<Channel*> channels = values();

    for (std::vector<Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        (*iChannel)->read();
    }
}

void ChannelManager::write() {
    std::vector<Channel*> channels = values();

    for (std::vector<Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        (*iChannel)->write();
    }
}

} // namespace channel
} // namespace device
} // namespace drobot
