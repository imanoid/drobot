#ifndef DROBOT_ROBOT_EVENT_STEPEVENT_H
#define DROBOT_ROBOT_EVENT_STEPEVENT_H

#include "../../event/event.h"
#include <map>
#include <vector>
#include "../../device/channel/channel.h"

namespace drobot {
namespace robot {
namespace event {

class StepEvent : public drobot::event::Event
{
private:
    long _tick;
    std::map<device::channel::Channel*, double> _inputs;
    std::map<device::channel::Channel*, double> _outputs;
public:
    StepEvent(long tick, std::map<device::channel::Channel*, double> inputs, std::map<device::channel::Channel*, double> outputs);
    StepEvent(long tick, std::vector<device::channel::Channel*> inputChannels, std::vector<device::channel::Channel*> outputChannels);
    void setInputValue(device::channel::Channel* channel, double value);
    void setOutputValue(device::channel::Channel* channel, double value);
    virtual std::string toString();
};

} // namespace event
} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_EVENT_STEPEVENT_H
