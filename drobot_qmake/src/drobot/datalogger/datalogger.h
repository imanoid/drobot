#ifndef DROBOT_DATALOGGER_DATALOGGER_H
#define DROBOT_DATALOGGER_DATALOGGER_H

#include <map>
#include "../device/channel/channel.h"
#include "../event/eventlistener.h"
#include <vector>

namespace drobot {
namespace datalogger {

/**
 * @brief The DataLogger class is a base class for collecting data from the robot.
 */
class DataLogger : public event::EventListener {
protected:
    std::vector<device::channel::Channel*> _channels;
public:
    DataLogger();
    DataLogger(std::vector<device::channel::Channel*> channels);
    virtual void onEvent(event::Event* event);
    std::vector<device::channel::Channel*> getChannels();
    virtual void log(long tick, std::map<device::channel::Channel*, double> values);
    /**
     * @brief setMaxValues. max count of values.
     * @details If bigger than 0 the values from the oldest ticks are deleted so that the size doesn't exceeds maxValues
     * @param maxValues
     */
    virtual void setMaxValues(int maxValues) = 0;
    /**
     * @brief getMaxValues. max count of values.
     * @details If bigger than 0 the values from the oldest ticks are deleted so that the size doesn't exceeds maxValues
     * @return maxValues
     */
    virtual int getMaxValues() = 0;
    /**
     * @brief setModulo. which ticks are recorded
     * @details if bigger than 0 only ticks with (tick % module == 0) are recorded
     * @param modulo
     */
    virtual void setModulo(int modulo) = 0;
    /**
     * @brief getModulo. which ticks are recorded
     * @details if bigger than 0 only ticks with (tick % module == 0) are recorded
     * @return modulo
     */
    virtual int getModulo() = 0;
};

} // namespace datalogger
} // namespace drobot

#endif // DROBOT_DATALOGGER_DATALOGGER_H
