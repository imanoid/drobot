#ifndef DROBOT_EXPERIMENT_TACTILETEST_PROGRAM_PROGRAM_H
#define DROBOT_EXPERIMENT_TACTILETEST_PROGRAM_PROGRAM_H

#include "../../../program/program.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

class Program : public drobot::program::Program
{
public:
    Program(std::string name);
    virtual void loop();
    virtual QWidget* getWidget();
};

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot

#endif // DROBOT_DEVICE_PROGRAM_TACTILETESTPROGRAM_H
