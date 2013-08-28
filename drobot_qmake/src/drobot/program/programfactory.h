#ifndef DROBOT_PROGRAM_PROGRAMFACTORY_H
#define DROBOT_PROGRAM_PROGRAMFACTORY_H

#include "program.h"
#include <string>

namespace drobot {
namespace program {

/**
 * @brief The ProgramFactory class is used for launching programs defined by the experimenter.
 */
class ProgramFactory
{
protected:
    std::string _name;
    int _programNumber;
public:
    ProgramFactory(std::string name);
    /**
     * @brief this method should instanciate a new program instance and call nextProgramName() to determine it's name.
     * @return Program instance
     */
    virtual Program* createInstance() = 0;
    /**
     * @brief getName. The base name of the programs
     * @return the name
     */
    std::string getName();
    /**
     * @brief nextProgramName. Creates a program name for the createInstance() method.
     * @details The program name is composed of the base name and an integer. On each call the integer is increased by 1.
     * @return next program's name
     */
    std::string nextProgramName();
};

}
}

#endif // PROGRAMFACTORY_H
