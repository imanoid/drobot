#include "tactiletestprogram.h"
#include "../widget/tactiletestmainwidget.h"
#include "../../../device/tactile/simpletactilesensorboard.h"
#include "../../../device/tactile/simpletactilesensor.h"
#include "../../../util/clock.h"
#include <iostream>
#include <unistd.h>
#include "../../../robot/robot.h"
#include "../robot/stupidcontroller.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

Program::Program(std::string name) : drobot::program::Program::Program(name) {
}

void Program::run() {
    util::Clock* clock = new util::Clock(24);
    drobot::device::tactile::SimpleTactileSensorBoard* board = new drobot::device::tactile::SimpleTactileSensorBoard("board0", "/dev/ttyUSB0");
    board->initAllSensors();
    board->initChannels();
    std::vector<device::Device*> sensors = board->list();

    device::DeviceManager* deviceManager = new device::DeviceManager();
    deviceManager->add(sensors);

    event::EventManager* eventManager = new event::EventManager();

    drobot::robot::Controller* controller = new robot::StupidController("booo");

    deviceManager->enable();
    drobot::robot::Robot* robo = new drobot::robot::Robot(deviceManager, controller, eventManager, clock);
    robo->run();
}

QWidget* Program::getWidget() {
    return new drobot::experiment::tactileTest::widget::MainWidget();
}

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
