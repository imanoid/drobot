#include "programmanager.h"
#include "../experiment/tactileTest/program/tactiletestprogramfactory.h"
#include <sstream>
#include <string>

namespace drobot {
namespace program {

ProgramManager::ProgramManager() {
    registerProgramFactory(new drobot::experiment::tactileTest::program::ProgramFactory());
}

void ProgramManager::registerProgramFactory(ProgramFactory* programFactory) {
    _programFactories[programFactory->getName()] = programFactory;
}

void ProgramManager::unregisterProgramFactory(ProgramFactory* programFactory) {
    _programFactories.erase(programFactory->getName());
}

std::vector<std::string> ProgramManager::listProgramFactories() {
    std::vector<std::string> factories;
    for (std::map<std::string, ProgramFactory*>::iterator iFactory = _programFactories.begin(); iFactory != _programFactories.end(); iFactory++) {
        factories.push_back(iFactory->first);
    }
    return factories;
}

Program* ProgramManager::launchProgram(std::string programName) {
    Program* task = _programFactories[programName]->createInstance();
    _programs[task->getName()] = task;
    task->run_thread();
    return task;
}

void ProgramManager::killProgram(std::string task) {
    _programs.erase(task);
}

std::vector<std::string> ProgramManager::listPrograms() {
    std::vector<std::string> programs;
    for (std::map<std::string, Program*>::iterator iProgram = _programs.begin(); iProgram != _programs.end(); iProgram++) {
        programs.push_back(iProgram->first);
    }
    return programs;
}

} // namespace program
} // namespace drobot
