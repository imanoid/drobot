#include <iostream>
#include <QWidget>
#include <QGridLayout>

#include "../../../util/exception.h"
#include "../../../widget/plot/curveplotter.h"
#include "../../../widget/slider/slider.h"
#include "../../../widget/slider/slidergroup.h"
#include "../widget/handmouthwidget.h"
#include "handmouthprogram.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace program {

HandMouthProgram::HandMouthProgram(std::string name) :
    drobot::program::Program::Program(name)
{
}

void HandMouthProgram::run()
{
    try {
        _robot.loadFromFile("../resources/robots/maggie.xml");
        _robot.run();
    } catch (util::Exception ex) {
        std::cerr << ex.getMessage() << std::endl;
        exit(1);
    }
}

QWidget* HandMouthProgram::getWidget()
{
    drobot::experiment::handmouth::widget::HandMouthWidget* w = new drobot::experiment::handmouth::widget::HandMouthWidget();
    w->setLayout(new QGridLayout());
    QLayout* layout = w->layout();

    drobot::device::channel::ChannelManager* channels = _robot.getDeviceManager()->getChannels();

    std::vector<std::string> keys = channels->keys();
    for (std::vector<std::string>::iterator iChannel = keys.begin(); iChannel != keys.end(); iChannel++)
        std::cout << (*iChannel) << std::endl;
    std::cout << "---" << std::endl;

    // init hand tactile sensor plot
    std::vector<device::channel::Channel*> handChannels;
    handChannels.push_back(channels->get("leftHandSensor.value.input"));
    handChannels.push_back(channels->get("rightHandSensor.value.input"));

    drobot::widget::plot::CurvePlotter* handPlotter = new drobot::widget::plot::CurvePlotter("hands", 0, 0, 100, 100, handChannels);
    handPlotter->setMaxValues(150);
//    layout->addWidget(handPlotter);
//    _robot.getEventManager()->registerEventListener(handPlotter);

    // init motor control sliders
    std::vector<device::channel::Channel*> leftShoulderChannels;
    leftShoulderChannels.push_back(channels->get("leftShoulderProximalServo.position.output"));
    leftShoulderChannels.push_back(channels->get("leftShoulderMedialServo.position.output"));
    leftShoulderChannels.push_back(channels->get("leftShoulderDistalServo.position.output"));

    drobot::widget::plot::CurvePlotter* leftShoulderPlotter = new drobot::widget::plot::CurvePlotter("left shoulder", 0, 0, 100, 100, leftShoulderChannels);
    leftShoulderPlotter->setMaxValues(150);
//    layout->addWidget(leftShoulderPlotter);
//    _robot.getEventManager()->registerEventListener(leftShoulderPlotter);

    // TODO: min, max and init values should come from XML
    std::vector<double> mins;
    std::vector<double> maxs;
    std::vector<double> inits;

    mins.push_back(0.0);
    mins.push_back(0.0);
    mins.push_back(0.0);

    maxs.push_back(100.0);
    maxs.push_back(100.0);
    maxs.push_back(100.0);

    inits.push_back(50);
    inits.push_back(42);
    inits.push_back(23);

    layout->addWidget(new drobot::widget::slider::SliderGroup("left shoulder motors", leftShoulderChannels, mins, maxs, inits));

    return w;
}

}
}
}
}
