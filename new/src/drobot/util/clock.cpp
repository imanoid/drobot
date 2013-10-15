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
    //wait until lock is released (start of next tick)
    while (_lock) {
        usleep(1000);
    }
    _lock = true;
    //start background thread to unlock on start of next tick
    boost::thread* t = new boost::thread(boost::bind(&Clock::unlock, this));
    return;
}

void Clock::unlock() {
    //wait for one tick
    usleep((1.0f / _frequency) * 1000000.0f);
    _lock = false;
}

void Clock::setFrequency(double frequency) {
    _frequency = frequency;
}

double Clock::getFrequency() {
    return _frequency;
}

} // namespace util
} // namespace drobot
