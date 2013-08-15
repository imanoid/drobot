#ifndef DROBOT_DATALOGGER_SIMPLEDATALOGENTRY_H
#define DROBOT_DATALOGGER_SIMPLEDATALOGENTRY_H

#include <map>
#include "../device/channel/channel.h"

namespace drobot {
namespace datalogger {

struct SimpleDataLogEntry {
    long tick;
    std::map<device::channel::Channel*, double> inputs;
    std::map<device::channel::Channel*, double> outputs;

    SimpleDataLogEntry() {}
    SimpleDataLogEntry(long tick, std::map<device::channel::Channel*, double> inputs, std::map<device::channel::Channel*, double> outputs) {
        this->tick = tick;
        this->inputs = inputs;
        this->outputs = outputs;
    }
};

} // namespace datalogger
} // namespace drobot

#endif // DROBOT_DATALOGGER_SIMPLEDATALOGENTRY_H
