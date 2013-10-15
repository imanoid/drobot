#ifndef DROBOT_EXPERIMENT_DEMO_PROGRAM_DEMOPROGRAM_H
#define DROBOT_EXPERIMENT_DEMO_PROGRAM_DEMOPROGRAM_H

#include "../../../program/program.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace program {

class DemoProgram : public drobot::program::Program {
private:
    drobot::robot::Robot _robo;
public:
    DemoProgram(std::string name);
    virtual void run();
    virtual QWidget* getWidget();
};

} // namespace program
} // namespace demo
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_DEMO_PROGRAM_DEMOPROGRAM_H
