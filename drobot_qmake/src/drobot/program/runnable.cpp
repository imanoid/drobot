#include "runnable.h"
#include <boost/thread.hpp>
#include "../util/clock.h"

namespace drobot {
namespace program {

void Runnable::run_interval_loop(int msec) {
    util::Clock clock(1000.0 / (double) msec);
    while (_running) {
        clock.waitForTick();
        run();
    }
}

Runnable::Runnable() {
    _running = false;
}

Runnable::~Runnable() {
    cancel();
    std::cout << "runnable deleted" << std::endl;
}

void Runnable::run_thread() {
    boost::thread* t = new boost::thread(boost::bind(&Runnable::run, this));
}

void Runnable::run_interval(int msec) {
    boost::thread* t = new boost::thread(boost::bind(&Runnable::run_interval_loop, this, msec));
}

void Runnable::cancel() {
    _running = false;
}

bool Runnable::isRunning() {
    return _running;
}

} // namespace program
} // namespace drobot
