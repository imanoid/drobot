#include "simpledatalogger.h"

namespace drobot {
namespace datalogger {

SimpleDataLogger::SimpleDataLogger() : DataLogger() {
}

SimpleDataLogger::SimpleDataLogger(int modulo, int maxValues) : DataLogger(modulo, maxValues) {
}

SimpleDataLogger::SimpleDataLogger(std::vector<device::channel::Channel*> channels) : DataLogger(channels) {
}

SimpleDataLogger::SimpleDataLogger(std::vector<device::channel::Channel*> channels, int modulo, int maxValues) : DataLogger(channels, modulo, maxValues) {
}

void SimpleDataLogger::log(long tick, std::map<device::channel::Channel*, double> values) {
    if (_modulo <= 1 || tick % _modulo == 0) {
        _data.push_back(new SimpleDataLogEntry(tick, values));
    }
    while (_maxValues > -1 && _data.size() > _maxValues) {
        _data.erase(_data.begin());
    }
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
