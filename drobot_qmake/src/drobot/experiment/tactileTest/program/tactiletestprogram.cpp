#include "tactiletestprogram.h"
#include "../widget/tactiletestmainwidget.h"
#include "../../../device/tactile/simpletactilesensorboard.h"
#include "../../../device/tactile/simpletactilesensor.h"

#include <iostream>
#include <unistd.h>

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

Program::Program(std::string name) : drobot::program::Program::Program(name) {
}

void Program::loop() {
    drobot::device::tactile::SimpleTactileSensorBoard* board = new drobot::device::tactile::SimpleTactileSensorBoard("/dev/ttyUSB0");
    board->enable();
    std::vector<drobot::device::tactile::TactileSensor*> sensors = board->getTactileSensors();
    while(_running) {
        for (int i = 0; i < sensors.size(); i++) {
            drobot::device::tactile::TactileSensor* sensor = sensors[i];
            std::cout << sensor->getValue() << " ";
        }
        std::cout << std::endl;
        usleep(1000);
    }
}

QWidget* Program::getWidget() {
    return new drobot::experiment::tactileTest::widget::MainWidget();
}

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
