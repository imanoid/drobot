#include "tactiletestprogramfactory.h"
#include "tactiletestprogram.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

ProgramFactory::ProgramFactory() : drobot::program::ProgramFactory::ProgramFactory("TactileTest")
{
}

drobot::program::Program* ProgramFactory::createInstance() {
    return new Program(nextProgramName());
}

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
