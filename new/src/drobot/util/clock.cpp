#include "clock.h"
#include <unistd.h>
#include <iostream>
#include <boost/thread.hpp>

namespace drobot {
namespace util {

Clock::Clock() {
    _frequency = 24;
}

Clock::Clock(double frequency) {
    _frequency = frequency;
}

void Clock::init() {
    _lock = false;
}

void Clock::waitForTick() {
    while (_lock) {
        usleep(1000);
    }
    _lock = true;
    boost::thread* t = new boost::thread(boost::bind(&Clock::unlock, this));
    return;
}

void Clock::setFrequency(double frequency) {
    _frequency = frequency;
}

double Clock::getFrequency() {
    return _frequency;
}

void Clock::unlock() {
    usleep((1.0f / _frequency) * 1000000.0f);
    _lock = false;
}

} // namespace util
} // namespace drobot
