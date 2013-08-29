#ifndef DROBOT_DATALOGGER_SIMPLEDATALOGENTRY_H
#define DROBOT_DATALOGGER_SIMPLEDATALOGENTRY_H

#include <map>
#include "../device/channel/channel.h"

namespace drobot {
namespace datalogger {

/**
 * @brief The SimpleDataLogEntry struct contains the information about the channel values of one tick
 */
struct SimpleDataLogEntry {
    long tick;
    std::map<device::channel::Channel*, double> values;

    SimpleDataLogEntry() {}
    SimpleDataLogEntry(long tick, std::map<device::channel::Channel*, double> values) {
        this->tick = tick;
        this->values = values;
    }
};

} // namespace datalogger
} // namespace drobot

#endif // DROBOT_DATALOGGER_SIMPLEDATALOGENTRY_H
