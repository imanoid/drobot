#include "program.h"
#include <boost/thread.hpp>

namespace drobot {
namespace program {

Program::Program(std::string name) : _name(name) {
}

std::string Program::getName() {
    return _name;
}

void Program::setName(std::string name) {
    _name = name;
}

} // namespace program
} // namespace drobot
