#include "tactiletestprogram.h"
#include "../widget/tactiletestmainwidget.h"
#include "../../../device/tactile/simpletactilesensorboard.h"
#include "../../../device/tactile/simpletactilesensor.h"

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
    drobot::device::tactile::SimpleTactileSensorBoard* board = new drobot::device::tactile::SimpleTactileSensorBoard("board0", "/dev/ttyUSB0");
    board->enable();
    board->initAllSensors();
    board->initChannels();
    std::vector<device::Device*> sensors = board->getDevices();

    device::DeviceManager* deviceManager = new device::DeviceManager();
    deviceManager->addDevices(sensors);

    event::EventManager* eventManager = new event::EventManager();

    drobot::robot::Controller* controller = new robot::StupidController();

    drobot::robot::Robot* robo = new drobot::robot::Robot(deviceManager, controller, eventManager);
    robo->run();
}

QWidget* Program::getWidget() {
    return new drobot::experiment::tactileTest::widget::MainWidget();
}

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
