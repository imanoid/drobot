#include "simpledatalogger.h"

namespace drobot {
namespace datalogger {

SimpleDataLogger::SimpleDataLogger() {
    _modulo = 1;
    _maxValues = 0;
}

SimpleDataLogger::SimpleDataLogger(int maxValues, int modulo) {
    _modulo = modulo;
    _maxValues = maxValues;
}

void SimpleDataLogger::log(long tick, std::map<device::channel::Channel*, double> inputs, std::map<device::channel::Channel*, double> outputs) {
    if (tick % getModulo() == 0) {
        _data.push_back(new SimpleDataLogEntry(tick, inputs, outputs));
    }
    if (getMaxValues() > -1 && _data.size() > getMaxValues()) {
        _data.erase(_data.begin());
    }
}

void SimpleDataLogger::setMaxValues(int maxValues) {
    _maxValues = maxValues;
}

int SimpleDataLogger::getMaxValues() {
    return _maxValues;
}

void SimpleDataLogger::setModulo(int modulo) {
    _modulo = modulo;
}

int SimpleDataLogger::getModulo() {
    return _modulo;
}

void SimpleDataLogger::saveToFile(std::string path) {

}

void SimpleDataLogger::loadFromFile(std::string path) {

}

std::vector<SimpleDataLogEntry*> SimpleDataLogger::getData() {
    return _data;
}

} // namespace datalogger
} // namespace drobot
