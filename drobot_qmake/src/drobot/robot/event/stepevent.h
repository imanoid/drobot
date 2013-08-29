#ifndef DROBOT_ROBOT_EVENT_STEPEVENT_H
#define DROBOT_ROBOT_EVENT_STEPEVENT_H

#include "../../event/event.h"
#include <map>
#include <vector>
#include "../../device/channel/channel.h"

namespace drobot {
namespace robot {
namespace event {

/**
 * @brief The StepEvent class. This event is fired in the robot's run method after every tick.
 * @details It contains information about the number of the tick and the current values of the different channels in the ChannelManager
 *  of the robot.
 *
 */
class StepEvent : public drobot::event::Event
{
private:
    long _tick;
    std::map<device::channel::Channel*, double> _values;
public:
    StepEvent(long tick, std::vector<device::channel::Channel*> channels);
    virtual std::string toString();
    std::map<device::channel::Channel*, double> getValues();
    long getTick();
};

} // namespace event
} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_EVENT_STEPEVENT_H
