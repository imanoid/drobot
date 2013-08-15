#include "channelmanager.h"

namespace drobot {
namespace device {
namespace channel {

bool ChannelManager::addInputChannel(Channel* channel) {
    if (hasInputChannel(channel))
        return false;
    _inputChannels.push_back(channel);
    return true;
}

bool ChannelManager::addOutputChannel(Channel* channel) {
    if (hasInputChannel(channel))
        return false;
    _outputChannels.push_back(channel);
    return true;
}

void ChannelManager::addInputChannels(std::vector<Channel *> channels) {
    for (std::vector<Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        addInputChannel(*iChannel);
    }
}

void ChannelManager::addOutputChannels(std::vector<Channel *> channels) {
    for (std::vector<Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        addOutputChannel(*iChannel);
    }
}

bool ChannelManager::removeInputChannel(Channel* channel) {
    for (std::vector<Channel*>::iterator iChannel = _inputChannels.begin(); iChannel != _inputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            _inputChannels.erase(iChannel);
            return true;
        }
    }
    return false;
}

bool ChannelManager::removeOutputChannel(Channel* channel) {
    for (std::vector<Channel*>::iterator iChannel = _outputChannels.begin(); iChannel != _outputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            _outputChannels.erase(iChannel);
            return true;
        }
    }
    return false;
}

void ChannelManager::removeInputChannels(std::vector<Channel *> channels) {
    for (std::vector<Channel *>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        removeInputChannel(*iChannel);
    }
}

void ChannelManager::removeOutputChannels(std::vector<Channel *> channels) {
    for (std::vector<Channel *>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        removeOutputChannel(*iChannel);
    }
}

bool ChannelManager::hasInputChannel(Channel* channel) {
    for (std::vector<Channel*>::iterator iChannel = _inputChannels.begin(); iChannel != _inputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            return true;
        }
    }
    return false;
}

bool ChannelManager::hasOutputChannel(Channel* channel) {
    for (std::vector<Channel*>::iterator iChannel = _outputChannels.begin(); iChannel != _outputChannels.end(); iChannel++) {
        if (*iChannel == channel) {
            return true;
        }
    }
    return false;
}

void ChannelManager::clearInputChannels() {
    _inputChannels.clear();
}

void ChannelManager::clearOutputChannels() {
    _outputChannels.clear();
}

std::map<Channel*, double> ChannelManager::getInputs() {
    std::map<Channel*, double> inputs;
    for (std::vector<Channel*>::iterator iChannel = _inputChannels.begin(); iChannel != _inputChannels.end(); iChannel++) {
        inputs[*iChannel] = (*iChannel)->getValue();
    }
    return inputs;
}

void ChannelManager::setOutputs(std::map<Channel*, double> outputs) {
    for (std::map<Channel*, double>::iterator iOutput = outputs.begin(); iOutput != outputs.end(); iOutput++) {
        iOutput->first->setValue(iOutput->second);
    }
}

std::vector<Channel*> ChannelManager::getInputChannels() {
    return _inputChannels;
}

std::vector<Channel*> ChannelManager::getOutputChannels() {
    return _outputChannels;
}

} // namespace channel
} // namespace device
} // namespace drobot
