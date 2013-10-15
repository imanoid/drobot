#include "demoprogramfactory.h"
#include "demoprogram.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace program {

DemoProgramFactory::DemoProgramFactory() : drobot::program::ProgramFactory::ProgramFactory("Demo")
{
}

drobot::program::Program* DemoProgramFactory::createInstance() {
    return new DemoProgram(nextProgramName());
}
} // namespace program
} // namespace demo
} // namespace experiment
} // namespace drobot
