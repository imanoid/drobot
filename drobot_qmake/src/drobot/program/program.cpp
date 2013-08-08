#include "program.h"
#include <boost/thread.hpp>

namespace drobot {
namespace program {

Program::Program(std::string name) : _name(name) {
}

void Program::start() {
    _running = true;
    boost::thread* loopThread = new boost::thread(boost::bind(&Program::loop, this));
}

void Program::stop() {
    _running = false;
}

bool Program::isRunning() {
    return _running;
}

std::string Program::getName() {
    return _name;
}

void Program::setName(std::string name) {
    _name = name;
}

} // namespace program
} // namespace drobot
