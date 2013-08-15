#include "stepevent.h"
#include <sstream>

namespace drobot {
namespace robot {
namespace event {

StepEvent::StepEvent(long tick, std::map<device::channel::Channel*, double> inputs, std::map<device::channel::Channel*, double> outputs) : Event("step") {
    _tick = tick;
    _inputs = inputs;
    _outputs = outputs;
}

StepEvent::StepEvent(long tick, std::vector<device::channel::Channel*> inputChannels, std::vector<device::channel::Channel*> outputChannels) : Event("step") {
    _tick = tick;

    for (std::vector<device::channel::Channel*>::iterator iChannel = inputChannels.begin(); iChannel != inputChannels.end(); iChannel++) {
        _inputs[*iChannel] = 0;
    }
    for (std::vector<device::channel::Channel*>::iterator iChannel = outputChannels.begin(); iChannel != outputChannels.end(); iChannel++) {
        _outputs[*iChannel] = 0;
    }
}

void StepEvent::setInputValue(device::channel::Channel* channel, double value) {
    _inputs[channel] = value;
}

void StepEvent::setOutputValue(device::channel::Channel* channel, double value) {
    _outputs[channel] = value;
}

std::string StepEvent::toString() {
    std::stringstream str;
    str << "tick: " << _tick << std::endl;
    str << "inputs" << std::endl << "======" << std::endl;
    for (std::map<device::channel::Channel*, double>::iterator iChannel = _inputs.begin(); iChannel != _inputs.end(); iChannel++) {
        str << iChannel->first->getFullName() << "=" << iChannel->second << std::endl;
    }
    str << std::endl;

    str << "outputs" << std::endl << "======" << std::endl;
    for (std::map<device::channel::Channel*, double>::iterator iChannel = _outputs.begin(); iChannel != _outputs.end(); iChannel++) {
        str << iChannel->first->getFullName() << "=" << iChannel->second << std::endl;
    }
    str << std::endl;
    return str.str();
}

} // namespace event
} // namespace robot
} // namespace drobot
