#include "democontroller.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace robot {

DemoController::DemoController(std::string name) : Controller(name) {
    _enabled = false;
}

void DemoController::tick(long tick) {
    drobot::device::channel::ChannelManager* channels = getRobot()->getDeviceManager()->getChannels();
    double rightHandSensor = channels->get("rightHandSensor.value.input")->getNormalizedValue();
    double leftHandSensor = channels->get("leftHandSensor.value.input")->getNormalizedValue();

    channels->get("leftEyeTiltServo.position.output")->setNormalizedValue(leftHandSensor);
    channels->get("rightEyeTiltServo.position.output")->setNormalizedValue(rightHandSensor);
}

} // namespace robot
} // namespace demo
} // namespace experiment
} // namespace drobot
