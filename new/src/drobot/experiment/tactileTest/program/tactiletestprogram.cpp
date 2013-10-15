#include "tactiletestprogram.h"
#include "../widget/tactiletestmainwidget.h"
#include "../../../widget/plot/curveplotter.h"
#include "../../../util/exception.h"
#include <QGridLayout>
#include <iostream>

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace program {

Program::Program(std::string name) : drobot::program::Program::Program(name) {
}

void Program::run() {
    try {
        _robo.loadFromFile("/home/imanol/workspace/drobot/new/resources/robots/robot.xml");
        _robo.run();
    } catch (util::Exception ex) {
        std::cerr << ex.getMessage() << std::endl;
        exit(1);
    }
}

QWidget* Program::getWidget() {
    drobot::experiment::tactileTest::widget::MainWidget* mainWidget = new drobot::experiment::tactileTest::widget::MainWidget();
    std::vector<device::channel::Channel*> channels = _robo.getDeviceManager()->getChannels()->values();
    mainWidget->setLayout(new QGridLayout());
    QLayout* layout = mainWidget->layout();
    drobot::widget::plot::CurvePlotter* plotter = new drobot::widget::plot::CurvePlotter("test", 0, 0, 100, 100, channels);
    plotter->setMaxValues(150);
    drobot::widget::plot::CurvePlotter* plotter2 = new drobot::widget::plot::CurvePlotter("test", 0, 0, 100, 100, channels);
    plotter2->setMaxValues(150);
    layout->addWidget(plotter);
    _robo.getEventManager()->registerEventListener(plotter);
    layout->addWidget(plotter2);
    _robo.getEventManager()->registerEventListener(plotter2);
    return mainWidget;
}

} // namespace program
} // namespace tactileTest
} // namespace experiment
} // namespace drobot
