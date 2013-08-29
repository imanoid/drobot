#ifndef DROBOT_PROGRAM_PROGRAMMANAGER_H
#define DROBOT_PROGRAM_PROGRAMMANAGER_H

#include <map>
#include <string>
#include "programfactory.h"
#include "../object/manager.h"

namespace drobot {
namespace program {

/**
 * @brief The ProgramManager class keeps track of the available ProgramFactory and Program instances
 */
class ProgramManager {
private:
    object::Manager<ProgramFactory> _programFactories;
    object::Manager<Program> _programs;
public:
    ProgramManager();
    virtual ~ProgramManager();

    /**
     * @brief registerProgramFactory adds a ProgramFactory
     * @param programFactory
     */
    void registerProgramFactory(ProgramFactory* programFactory);
    /**
     * @brief unregisterProgramFactory removes a ProgramFactory
     * @param programFactory
     */
    void unregisterProgramFactory(ProgramFactory* programFactory);
    /**
     * @brief listProgramFactoryNames
     * @return the names of the known ProgramFactory instances
     */
    std::vector<std::string> listProgramFactoryNames();
    /**
     * @brief launchProgram creates a new program instance and starts it.
     * @param programName is the type of the program to launch
     * @return the new program instance
     */
    Program* launchProgram(std::string programName);
    /**
     * @brief killProgram cancels a program instance
     * @param programName
     */
    void killProgram(std::string programName);
    /**
     * @brief killAll cancels all program instances
     */
    void killAll();
    std::vector<std::string> listProgramNames();
};

} // namespace program
} // namespace drobot

#endif // DROBOT_PROGRAM_PROGRAMMANAGER_H
