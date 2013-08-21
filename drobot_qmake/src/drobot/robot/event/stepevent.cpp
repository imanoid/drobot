#include "stepevent.h"
#include <sstream>

namespace drobot {
namespace robot {
namespace event {

StepEvent::StepEvent(long tick, std::vector<device::channel::Channel*> channels) : Event("step") {
    _tick = tick;

    for (std::vector<device::channel::Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        _values[*iChannel] = (*iChannel)->getNormalizedValue();
    }
}

std::string StepEvent::toString() {
    std::stringstream str;
    str << "tick: " << _tick << std::endl;
    str << "values" << std::endl << "======" << std::endl;
    for (std::map<device::channel::Channel*, double>::iterator iChannel = _values.begin(); iChannel != _values.end(); iChannel++) {
        str << iChannel->first->getName() << "=" << iChannel->second << std::endl;
        //str << iChannel->second << ";";
    }
    str << std::endl;
    return str.str();
}

} // namespace event
} // namespace robot
} // namespace drobot
