#include "tickevent.h"
#include <sstream>

namespace drobot {
namespace robot {
namespace event {

TickEvent::TickEvent(long tick, std::vector<device::channel::Channel*> channels) : Event("step") {
    _tick = tick;

    for (std::vector<device::channel::Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        _values[*iChannel] = (*iChannel)->getNormalizedValue();
    }
}

std::string TickEvent::toString() {
    std::stringstream str;
    str << "tick: " << _tick << std::endl;
    str << "values" << std::endl << "======" << std::endl;
    for (std::map<device::channel::Channel*, double>::iterator iChannel = _values.begin(); iChannel != _values.end(); iChannel++) {
        str << iChannel->first->getName() << "=" << iChannel->second << std::endl;
    }
    str << std::endl;
    return str.str();
}

std::map<device::channel::Channel*, double> TickEvent::getValues() {
    return _values;
}

long TickEvent::getTick() {
    return _tick;
}

} // namespace event
} // namespace robot
} // namespace drobot
