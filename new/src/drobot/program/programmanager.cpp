#include <sstream>
#include <string>
#include <unistd.h>

#include "programmanager.h"
#include "../experiment/tactileTest/program/tactiletestprogramfactory.h"
#include "../experiment/demo/program/demoprogramfactory.h"
#include "../experiment/handmouth/program/handmouthprogramfactory.h"
#include "../util/util.h"

namespace drobot {
namespace program {

ProgramManager::ProgramManager() {
    registerProgramFactory(new drobot::experiment::tactileTest::program::ProgramFactory());
    registerProgramFactory(new drobot::experiment::demo::program::DemoProgramFactory());
    registerProgramFactory(new drobot::experiment::handmouth::program::HandMouthProgramFactory());
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

Program* ProgramManager::launchProgram(std::string programFactoryName) {
    Program* task = _programFactories.get(programFactoryName)->createInstance();
    _programs.add(task);
    task->run_thread();
    usleep(4000000);
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
