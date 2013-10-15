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
    int _modulo;
    int _maxValues;
public:
    DataLogger();
    DataLogger(int modulo, int maxValues);
    DataLogger(std::vector<device::channel::Channel*> channels);
    DataLogger(std::vector<device::channel::Channel*> channels, int modulo, int maxValues);
    virtual void onEvent(event::Event* event);
    std::vector<device::channel::Channel*> getChannels();
    /**
     * @brief log is called in the onEvent method after an event.
     * @param tick
     * @param values of the different channels
     */
    virtual void log(long tick, std::map<device::channel::Channel*, double> values);
    /**
     * @brief setMaxValues. max count of values.
     * @details If bigger than 0 the values from the oldest ticks are deleted so that the size doesn't exceeds maxValues
     * @param maxValues
     */
    virtual void setMaxValues(int maxValues);
    /**
     * @brief getMaxValues. max count of values.
     * @details If bigger than 0 the values from the oldest ticks are deleted so that the size doesn't exceeds maxValues
     * @return maxValues
     */
    virtual int getMaxValues();
    /**
     * @brief setModulo. which ticks are recorded
     * @details if bigger than 0 only ticks with (tick % module == 0) are recorded
     * @param modulo
     */
    virtual void setModulo(int modulo);
    /**
     * @brief getModulo. which ticks are recorded
     * @details if bigger than 0 only ticks with (tick % module == 0) are recorded
     * @return modulo
     */
    virtual int getModulo();
};

} // namespace datalogger
} // namespace drobot

#endif // DROBOT_DATALOGGER_DATALOGGER_H
