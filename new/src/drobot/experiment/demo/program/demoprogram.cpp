#include "demoprogram.h"
#include "../widget/demowidget.h"
#include "../../../widget/plot/curveplotter.h"
#include "../../../util/exception.h"
#include <QGridLayout>
#include <iostream>

namespace drobot {
namespace experiment {
namespace demo {
namespace program {

DemoProgram::DemoProgram(std::string name) : drobot::program::Program::Program(name) {
}

void DemoProgram::run() {
    try {
        _robo.loadFromFile("/home/imanol/workspace/drobot/new/resources/robots/maggie.xml");
        _robo.run();
    } catch (util::Exception ex) {
        std::cerr << ex.getMessage() << std::endl;
        exit(1);
    }
}

QWidget* DemoProgram::getWidget() {
    drobot::experiment::demo::widget::DemoWidget* mainWidget = new drobot::experiment::demo::widget::DemoWidget();
    drobot::device::channel::ChannelManager* channels = _robo.getDeviceManager()->getChannels();
    mainWidget->setLayout(new QGridLayout());
    QLayout* layout = mainWidget->layout();

    // init hand tactile sensor plot
    std::vector<device::channel::Channel*> handChannels;
    handChannels.push_back(channels->get("leftHandSensor.value.input"));
    handChannels.push_back(channels->get("rightHandSensor.value.input"));

    drobot::widget::plot::CurvePlotter* handPlotter = new drobot::widget::plot::CurvePlotter("hands", 0, 0, 100, 100, handChannels);
    handPlotter->setMaxValues(150);
    layout->addWidget(handPlotter);
    _robo.getEventManager()->registerEventListener(handPlotter);

    // init eye tile servo plot
    std::vector<device::channel::Channel*> tiltChannels;
    tiltChannels.push_back(channels->get("leftEyeTiltServo.position.output"));
    tiltChannels.push_back(channels->get("rightEyeTiltServo.position.output"));
    tiltChannels.push_back(channels->get("rightEyeTiltServo.position.input"));

    drobot::widget::plot::CurvePlotter* tiltPlotter = new drobot::widget::plot::CurvePlotter("eye tilt", 0, 0, 100, 100, tiltChannels);
    tiltPlotter->setMaxValues(150);
    layout->addWidget(tiltPlotter);
    _robo.getEventManager()->registerEventListener(tiltPlotter);

    return mainWidget;
}

} // namespace program
} // namespace demo
} // namespace experiment
} // namespace drobot
