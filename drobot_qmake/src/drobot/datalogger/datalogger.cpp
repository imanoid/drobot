#include "datalogger.h"
#include "../robot/event/stepevent.h"

namespace drobot {
namespace datalogger {

DataLogger::DataLogger() : EventListener("step") {
}

DataLogger::DataLogger(std::vector<device::channel::Channel*> channels) : EventListener("step") {
    _channels = channels;
}

void DataLogger::onEvent(event::Event *event) {
    drobot::robot::event::StepEvent* stepEvent = dynamic_cast<drobot::robot::event::StepEvent*>(event);
    this->log(stepEvent->getTick(), stepEvent->getValues());
}

std::vector<device::channel::Channel*> DataLogger::getChannels() {
    return _channels;
}

void DataLogger::log(long tick, std::map<device::channel::Channel*, double> values) {

}

}
}
