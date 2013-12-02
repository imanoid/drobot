#include "handmouthprogramfactory.h"
#include "handmouthprogram.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace program {

HandMouthProgramFactory::HandMouthProgramFactory() :
	drobot::program::ProgramFactory::ProgramFactory("HandMouth")
{
}

drobot::program::Program* HandMouthProgramFactory::createInstance() {
    return new HandMouthProgram(nextProgramName());
}

}
}
}
}
