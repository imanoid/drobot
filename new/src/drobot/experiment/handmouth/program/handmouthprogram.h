#ifndef _DROBOT_EXPERIMENT_HANDMOUTH_PROGRAM_HANDMOUTHPROGRAM_H
#define _DROBOT_EXPERIMENT_HANDMOUTH_PROGRAM_HANDMOUTHPROGRAM_H

#include "../../../program/program.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace program {

class HandMouthProgram : public drobot::program::Program {
private:
    drobot::robot::Robot _robot;
public:
    HandMouthProgram(std::string name);
    virtual void run();
    virtual QWidget* getWidget();
};

} // namespace program
} // namespace handmouth
} // namespace experiment
} // namespace drobot

#endif /* _DROBOT_EXPERIMENT_HANDMOUTH_PROGRAM_HANDMOUTHPROGRAM_H */
