#include "datalogger.h"
#include "../robot/event/tickevent.h"

namespace drobot {
namespace datalogger {

DataLogger::DataLogger() : EventListener("step") {
    _maxValues = 0;
    _modulo = 1;
}

DataLogger::DataLogger(int maxValues, int modulo) : EventListener("step") {
    _maxValues = maxValues;
    _modulo = modulo;
}

DataLogger::DataLogger(std::vector<device::channel::Channel*> channels) : DataLogger() {
    _channels = channels;
}

DataLogger::DataLogger(std::vector<device::channel::Channel*> channels, int maxValues, int modulo) : DataLogger(maxValues, modulo) {
    _channels = channels;
}

void DataLogger::onEvent(event::Event *event) {
    drobot::robot::event::TickEvent* stepEvent = dynamic_cast<drobot::robot::event::TickEvent*>(event);
    this->log(stepEvent->getTick(), stepEvent->getValues());
}

std::vector<device::channel::Channel*> DataLogger::getChannels() {
    return _channels;
}

void DataLogger::log(long tick, std::map<device::channel::Channel*, double> values) {

}

void DataLogger::setMaxValues(int maxValues) {
    _maxValues = maxValues;
}

int DataLogger::getMaxValues() {
    return _maxValues;
}

void DataLogger::setModulo(int modulo) {
    _modulo = modulo;
}

int DataLogger::getModulo() {
    return _modulo;
}

}
}
