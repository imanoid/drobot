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
    std::map<device::channel::Channel*, double> _values;
public:
    StepEvent(long tick, std::vector<device::channel::Channel*> channels);
    virtual std::string toString();
};

} // namespace event
} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_EVENT_STEPEVENT_H
