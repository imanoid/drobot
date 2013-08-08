#ifndef DROBOT_EXPERIMENT_DEVICETEST_PROGRAM_PROGRAMFACTORY_H
#define DROBOT_EXPERIMENT_DEVICETEST_PROGRAM_PROGRAMFACTORY_H

#include "../../../program/programfactory.h"
#include "../../../device/devicemanager.h"


namespace drobot {
namespace experiment {
namespace deviceTest {
namespace program {

class ProgramFactory : public drobot::program::ProgramFactory
{
private:
    drobot::device::DeviceManager* _deviceManager;
public:
    ProgramFactory(drobot::device::DeviceManager* deviceManager);
    virtual drobot::program::Program* createInstance();
};

} // namespace program
} // namespace deviceTest
} // namespace experiment
} // namespace drobot

#endif // DROBOT_PROGRAM_DEVICETESTPROGRAMFACTORY_H
