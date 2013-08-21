#include "tactiletestprogram.h"
#include "../widget/tactiletestmainwidget.h"
#include "../../../device/tactile/simpletactilesensorboard.h"
#include "../../../device/tactile/simpletactilesensor.h"
#include "../../../util/clock.h"
#include <sstream>
#include <unistd.h>
#include "../../../robot/robot.h"
#include "../robot/stupidcontroller.h"
#include <stdlib.h>
#include "../../../util/exception.h"
#include "../../../device/actuator/phidgetadvancedboard.h"
#include <iostream>
#include <phidget21.h>

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

Program::Program(std::string name) : drobot::program::Program::Program(name) {
}

void Program::run() {
    try {
        /*std::cout << "board initializing..." << std::endl;
        device::actuator::PhidgetAdvancedBoard* board = new device::actuator::PhidgetAdvancedBoard("test", 303292);
        std::cout << "board initialized" << std::endl;
        std::cout << board->getPhidgetType() << std::endl;
        device::actuator::Actuator* actuator1 = board->initActuator(2);
        actuator1->enable();
        actuator1->setPosition(100);
        usleep(2000000);
        actuator1->setPosition(80);
        usleep(1000000);
        actuator1->disable();
        delete board;
        delete actuator1;
        exit(0);*/


        util::Clock* clock = new util::Clock(24);

        device::DeviceManager* deviceManager = new device::DeviceManager();

        deviceManager->loadFromFile("/home/imanol/workspace/drobot_qmake/resources/robots/tactiletest.xml");

        event::EventManager* eventManager = new event::EventManager();

        drobot::robot::Controller* controller = new robot::StupidController("booo");

        deviceManager->enable();
        drobot::robot::Robot* robo = new drobot::robot::Robot(deviceManager, controller, eventManager, clock);
        std::cout << "robot running" << std::endl << std::endl;
        robo->run();
    } catch (util::Exception ex) {
        std::cerr << ex.getMessage() << std::endl;
        exit(1);
    }
}

QWidget* Program::getWidget() {
    return new drobot::experiment::tactileTest::widget::MainWidget();
}

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
