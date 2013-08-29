#include "programfactory.h"
#include <sstream>

namespace drobot {
namespace program {

ProgramFactory::ProgramFactory(std::string name) : _name(name), _programNumber(0){
}

std::string ProgramFactory::getName() {
    return _name;
}

std::string ProgramFactory::nextProgramName() {
    std::stringstream name;
    name << _name;
    name << "-" << _programNumber;
    _programNumber++;
    return name.str();
}

} // namespace program
} // namespace drobot
