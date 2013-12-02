#ifndef _DROBOT_EXPERIMENT_HANDMOUTH_PROGRAM_HANDMOUTHPROGRAMFACTORY_H
#define _DROBOT_EXPERIMENT_HANDMOUTH_PROGRAM_HANDMOUTHPROGRAMFACTORY_H

#include "../../../program/programfactory.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace program {

class HandMouthProgramFactory : public drobot::program::ProgramFactory {
public:
    HandMouthProgramFactory();
    virtual drobot::program::Program* createInstance();
};

} // namespace program
} // namespace demo
} // namespace experiment
} // namespace drobot

#endif /* _DROBOT_EXPERIMENT_HANDMOUTH_PROGRAM_HANDMOUTHPROGRAMFACTORY_H */
