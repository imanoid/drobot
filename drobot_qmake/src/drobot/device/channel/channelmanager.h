#ifndef DROBOT_CHANNEL_CHANNELMANAGER_H
#define DROBOT_CHANNEL_CHANNELMANAGER_H

#include "channel.h"
#include <vector>
#include <map>

namespace drobot {
namespace device {
namespace channel {

class ChannelManager
{
private:
    std::vector<Channel*> _inputChannels;
    std::vector<Channel*> _outputChannels;
public:
    bool addInputChannel(Channel* channel);
    bool addOutputChannel(Channel* channel);
    void addInputChannels(std::vector<Channel*> channels);
    void addOutputChannels(std::vector<Channel*> channels);
    bool removeInputChannel(Channel* channel);
    bool removeOutputChannel(Channel* channel);
    void removeInputChannels(std::vector<Channel*> channels);
    void removeOutputChannels(std::vector<Channel*> channels);
    bool hasInputChannel(Channel* channel);
    bool hasOutputChannel(Channel* channel);
    void clearInputChannels();
    void clearOutputChannels();
    std::map<Channel*, double> getInputs();
    void setOutputs(std::map<Channel*, double> outputs);
    std::vector<Channel*> getInputChannels();
    std::vector<Channel*> getOutputChannels();
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_CHANNEL_CHANNELMANAGER_H
