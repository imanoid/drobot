#include "simpledatalogger.h"

namespace drobot {
namespace datalogger {

SimpleDataLogger::SimpleDataLogger() {
    _maxValues = 0;
    _modulo = 1;
}

SimpleDataLogger::SimpleDataLogger(int maxValues, int modulo) {
    _maxValues = maxValues;
    _modulo = modulo;
}

void SimpleDataLogger::log(long tick, std::map<device::channel::Channel*, double> values) {
    if (_modulo <= 1 || tick % _modulo == 0) {
        _data.push_back(new SimpleDataLogEntry(tick, values));
    }
    while (_maxValues > -1 && _data.size() > _maxValues) {
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

void SimpleDataLogger::loadFromFile(std::string path, device::channel::ChannelManager channels) {

}

std::vector<SimpleDataLogEntry*> SimpleDataLogger::getData() {
    return _data;
}

} // namespace datalogger
} // namespace drobot
