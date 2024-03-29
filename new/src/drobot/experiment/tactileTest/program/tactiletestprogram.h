#ifndef DROBOT_EXPERIMENT_TACTILETEST_PROGRAM_PROGRAM_H
#define DROBOT_EXPERIMENT_TACTILETEST_PROGRAM_PROGRAM_H

#include "../../../program/program.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

class Program : public drobot::program::Program
{
private:
    drobot::robot::Robot _robo;
public:
    Program(std::string name);
    virtual void run();
    virtual QWidget* getWidget();
};

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot

#endif // DROBOT_DEVICE_PROGRAM_TACTILETESTPROGRAM_H
