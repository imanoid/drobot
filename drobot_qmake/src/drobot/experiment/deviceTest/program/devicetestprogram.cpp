#include "devicetestprogram.h"

namespace drobot {
namespace experiment {
namespace deviceTest {
namespace program {

Program::Program(std::string name, drobot::device::DeviceManager* deviceManager) : drobot::program::Program::Program(name), _deviceManager(deviceManager) {
}

void Program::loop() {

}

QWidget* Program::getWidget() {
    return 0;
}

} // namespace program
} // namespace deviceTest
} // namespace experiment
} // namespace drobot
