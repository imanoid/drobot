#ifndef DROBOT_DATALOGGER_SIMPLEDATALOGGER_H
#define DROBOT_DATALOGGER_SIMPLEDATALOGGER_H

#include "datalogger.h"
#include <vector>
#include "simpledatalogentry.h"
#include "../device/channel/channelmanager.h"

namespace drobot {
namespace datalogger {

/**
 * @brief The SimpleDataLogger class implements the DataLogger class to save it into a file and also load it from there.
 */
class SimpleDataLogger : public DataLogger {
private:
    std::vector<SimpleDataLogEntry*> _data;
public:
    SimpleDataLogger();
    SimpleDataLogger(int modulo, int maxValues);
    SimpleDataLogger(std::vector<device::channel::Channel*> channels);
    SimpleDataLogger(std::vector<device::channel::Channel*> channels, int modulo, int maxValues);
    virtual void log(long tick, std::map<device::channel::Channel*, double> values);
    void saveToFile(std::string path);
    void loadFromFile(std::string path, device::channel::ChannelManager channels);
    std::vector<SimpleDataLogEntry*> getData();
};

} // namespace datalogger
} // namespace drobot

#endif // DROBOT_DATALOGGER_SIMPLEDATALOGGER_H
