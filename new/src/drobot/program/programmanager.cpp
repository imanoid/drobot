#include "programmanager.h"
#include "../experiment/tactileTest/program/tactiletestprogramfactory.h"
#include <sstream>
#include <string>
#include "../util/util.h"

namespace drobot {
namespace program {

ProgramManager::ProgramManager() {
    registerProgramFactory(new drobot::experiment::tactileTest::program::ProgramFactory());
}

ProgramManager::~ProgramManager() {
}

void ProgramManager::registerProgramFactory(ProgramFactory* programFactory) {
    _programFactories.add(programFactory);
}

void ProgramManager::unregisterProgramFactory(ProgramFactory* programFactory) {
    _programFactories.remove(programFactory);
}

std::vector<std::string> ProgramManager::listProgramFactoryNames() {
    return _programFactories.keys();
}

Program* ProgramManager::launchProgram(std::string programName) {
    Program* task = _programFactories.get(programName)->createInstance();
    _programs.add(task);
    task->run_thread();
    return task;
}

void ProgramManager::killProgram(std::string programName) {
    Program* program = _programs.remove(programName);
    program->cancel();
    delete program;
}

void ProgramManager::killAll() {
    std::vector<std::string> programNames = _programs.keys();
    for (std::vector<std::string>::iterator iProgram = programNames.begin(); iProgram != programNames.end(); iProgram++) {
        killProgram(*iProgram);
    }
}

std::vector<std::string> ProgramManager::listProgramNames() {
    return _programs.keys();
}

} // namespace program
} // namespace drobot
