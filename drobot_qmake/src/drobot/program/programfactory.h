#ifndef DROBOT_PROGRAM_PROGRAMFACTORY_H
#define DROBOT_PROGRAM_PROGRAMFACTORY_H

#include "program.h"
#include <string>

namespace drobot {
namespace program {

class ProgramFactory
{
protected:
    std::string _name;
    int _programNumber;
public:
    ProgramFactory(std::string name);
    virtual Program* createInstance() = 0;
    std::string getName();
    std::string nextProgramName();
};

}
}

#endif // PROGRAMFACTORY_H
