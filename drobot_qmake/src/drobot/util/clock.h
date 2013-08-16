#ifndef DROBOT_UTIL_CLOCK_H
#define DROBOT_UTIL_CLOCK_H


namespace drobot {
namespace util {

class Clock
{
private:
    bool _lock;
    double _frequency;
public:
    Clock(double frequency);
    void init();
    void waitForTick();
    void setFrequency(double frequency);
    double getFrequency();
    void lock();
};

} // namespace util
} // namespace drobot

#endif // DROBOT_UTIL_CLOCK_H
