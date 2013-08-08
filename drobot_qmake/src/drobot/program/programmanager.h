#ifndef _DROBOT_PROGRAM_PROGRAMMANAGER_H_
#define _DROBOT_PROGRAM_PROGRAMMANAGER_H_

#include <map>
#include <string>
#include "programfactory.h"

namespace drobot {
namespace program {

class ProgramManager
{
private:
    std::map<std::string, ProgramFactory*> _programFactories;
    std::map<std::string, Program*> _programs;
public:
    ProgramManager();

    void registerProgramFactory(ProgramFactory* programFactory);
    void unregisterProgramFactory(ProgramFactory* programFactory);
    std::vector<std::string> listProgramFactories();
    Program* launchProgram(std::string programName);
    void killProgram(std::string task);
    std::vector<std::string> listPrograms();
};

} // namespace program
} // namespace drobot

#endif // DROBOT_PROGRAM_PROGRAMMANAGER_H
