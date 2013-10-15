#ifndef DROBOT_EXPERIMENT_DEMO_PROGRAM_DEMOPROGRAMFACTORY_H
#define DROBOT_EXPERIMENT_DEMO_PROGRAM_DEMOPROGRAMFACTORY_H

#include "../../../program/programfactory.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace program {

class DemoProgramFactory : public drobot::program::ProgramFactory {
public:
    DemoProgramFactory();
    virtual drobot::program::Program* createInstance();
};

} // namespace program
} // namespace demo
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_DEMO_PROGRAM_DEMOPROGRAMFACTORY_H
