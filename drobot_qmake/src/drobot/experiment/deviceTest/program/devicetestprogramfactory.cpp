#include "devicetestprogramfactory.h"
#include "devicetestprogram.h"


namespace drobot {
namespace experiment {
namespace deviceTest {
namespace program {

ProgramFactory::ProgramFactory(drobot::device::DeviceManager* deviceManager): _deviceManager(deviceManager), drobot::program::ProgramFactory::ProgramFactory("DeviceTest") {
}

drobot::program::Program* ProgramFactory::createInstance() {
    return new Program(nextProgramName(), _deviceManager);
}

} // namespace program
} // namespace deviceTest
} // namespace experiment
} // namespace drobot
