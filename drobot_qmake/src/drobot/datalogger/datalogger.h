#ifndef DROBOT_DATALOGGER_DATALOGGER_H
#define DROBOT_DATALOGGER_DATALOGGER_H

#include <map>
#include "../device/channel/channel.h"

namespace drobot {
namespace datalogger {

class DataLogger
{
public:
    virtual void log(long tick, std::map<device::channel::Channel*, double> inputs, std::map<device::channel::Channel*, double> outputs) = 0;
    virtual void setMaxValues(int maxValues) = 0;
    virtual int getMaxValues() = 0;
    virtual void setModulo(int modulo) = 0;
    virtual int getModulo() = 0;
};

} // namespace datalogger
} // namespace drobot

#endif // DROBOT_DATALOGGER_DATALOGGER_H
