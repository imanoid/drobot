#ifndef DROBOT_DATALOGGER_SIMPLEDATALOGGER_H
#define DROBOT_DATALOGGER_SIMPLEDATALOGGER_H

#include "datalogger.h"
#include <vector>
#include "simpledatalogentry.h"

namespace drobot {
namespace datalogger {

class SimpleDataLogger : public DataLogger
{
private:
    std::vector<SimpleDataLogEntry*> _data;
    int _modulo;
    int _maxValues;
public:
    SimpleDataLogger();
    SimpleDataLogger(int maxValues, int modulo);
    virtual void log(long tick, std::map<device::channel::Channel*, double> inputs, std::map<device::channel::Channel*, double> outputs);
    virtual void setMaxValues(int maxValues);
    virtual int getMaxValues();
    virtual void setModulo(int modulo);
    virtual int getModulo();
    void saveToFile(std::string path);
    void loadFromFile(std::string path);
    std::vector<SimpleDataLogEntry*> getData();
};

} // namespace datalogger
} // namespace drobot

#endif // DROBOT_DATALOGGER_SIMPLEDATALOGGER_H
