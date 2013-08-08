#ifndef DROBOT_EXPERIMENT_DEVICETEST_PROGRAM_PROGRAM_H
#define DROBOT_EXPERIMENT_DEVICETEST_PROGRAM_PROGRAM_H

#include "../../../program/program.h"
#include "../../../device/devicemanager.h"


namespace drobot {
namespace experiment {
namespace deviceTest {
namespace program {

class Program : public drobot::program::Program
{
private:
    drobot::device::DeviceManager* _deviceManager;
public:
    Program(std::string name, drobot::device::DeviceManager* deviceManager);
    virtual void loop();
    virtual QWidget* getWidget();
};

} // namespace program
} // namespace deviceTest
} // namespace experiment
} // namespace drobot

#endif // DROBOT_PROGRAM_DEVICETESTPROGRAM_H
