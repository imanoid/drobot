#include "tactiletestprogram.h"
#include "../widget/tactiletestmainwidget.h"
#include <iostream>
#include "../../../util/exception.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

Program::Program(std::string name) : drobot::program::Program::Program(name) {
}

void Program::run() {
    try {
        _robo.loadFromFile("/home/imanol/workspace/drobot_qmake/resources/robots/robot.xml");
        _robo.run();
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
