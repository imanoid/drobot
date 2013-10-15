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
        _robo.loadFromFile("/home/imanol/workspace/drobot/new/resources/robots/robot.xml");
        _robo.run();
    } catch (util::Exception ex) {
        std::cerr << ex.getMessage() << std::endl;
        exit(1);
    }
}

QWidget* DemoProgram::getWidget() {
    drobot::experiment::demo::widget::DemoWidget* mainWidget = new drobot::experiment::demo::widget::DemoWidget();
    std::vector<device::channel::Channel*> channels = _robo.getDeviceManager()->getChannels()->values();
    mainWidget->setLayout(new QGridLayout());
    QLayout* layout = mainWidget->layout();

    // init mouth plot
    std::vector<device::channel::Channel*> mouthChannels;
    for (std::vector<device::channel::Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        device::channel::Channel* channel = *iChannel;
        if (channel->getName().find("mouthSensor") != std::string::npos) {
            mouthChannels.push_back(channel);
        }
    }
    // only show if devices are active
    if (mouthChannels.size() > 0) {
        drobot::widget::plot::CurvePlotter* mouthPlotter = new drobot::widget::plot::CurvePlotter("mouth", 0, 0, 100, 100, mouthChannels);
        mouthPlotter->setMaxValues(150);
        layout->addWidget(mouthPlotter);
        _robo.getEventManager()->registerEventListener(mouthPlotter);
    }

    // init vestibular plot
    std::vector<device::channel::Channel*> vestibularChannels;
    for (std::vector<device::channel::Channel*>::iterator iChannel = channels.begin(); iChannel != channels.end(); iChannel++) {
        device::channel::Channel* channel = *iChannel;
        if (channel->getName().find("Vestibular") != std::string::npos) {
            vestibularChannels.push_back(channel);
        }
    }
    // only show if devices are active
    if (vestibularChannels.size() > 0) {
        drobot::widget::plot::CurvePlotter* vestibularPlotter = new drobot::widget::plot::CurvePlotter("vestibular", 0, 0, 100, 100, vestibularChannels);
        vestibularPlotter->setMaxValues(150);
        layout->addWidget(vestibularPlotter);
        _robo.getEventManager()->registerEventListener(vestibularPlotter);
    }

    return mainWidget;
}

} // namespace program
} // namespace demo
} // namespace experiment
} // namespace drobot
