#ifndef DROBOT_EXPERIMENT_TACTILETEST_PROGRAM_PROGRAMFACTORY_H
#define DROBOT_EXPERIMENT_TACTILETEST_PROGRAM_PROGRAMFACTORY_H

#include "../../../program/programfactory.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

class ProgramFactory : public drobot::program::ProgramFactory
{
public:
    ProgramFactory();
    virtual drobot::program::Program* createInstance();
};

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot

#endif // DROBOT_DEVICE_PROGRAM_TACTILETESTPROGRAMFACTORY_H
