#include "runnable.h"
#include <boost/thread.hpp>

namespace drobot {
namespace program {

void Runnable::run_thread() {
    boost::thread* t = new boost::thread(boost::bind(&Runnable::run, this));
}

void Runnable::cancel() {
    _running = false;
}

bool Runnable::isRunning() {
    return _running;
}

} // namespace program
} // namespace drobot
