#ifndef DROBOT_UTIL_CLOCK_H
#define DROBOT_UTIL_CLOCK_H


namespace drobot {
namespace util {

/**
 * @brief The Clock class can be used to synchronize a loop to a specific frequency
 */
class Clock
{
private:
    bool _lock;
    double _frequency;
    void unlock();
public:
    Clock();
    Clock(double frequency);
    void init();
    /**
     * @brief waitForTick is used to wait for the next timestep.
     * @details It returns immediately in the first call. After that it blocks until the next tick's
     *  time has arrived. This method should be called at the beginning of the loop.
     */
    void waitForTick();
    void setFrequency(double frequency);
    double getFrequency();
};

} // namespace util
} // namespace drobot

#endif // DROBOT_UTIL_CLOCK_H
