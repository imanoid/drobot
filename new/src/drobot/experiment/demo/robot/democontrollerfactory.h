#ifndef DROBOT_EXPERIMENT_DEMO_ROBOT_DEMOCONTROLLERFACTORY_H
#define DROBOT_EXPERIMENT_DEMO_ROBOT_DEMOCONTROLLERFACTORY_H

#include "../../../device/devicefactory.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace demo {
namespace robot {

class DemoControllerFactory : public device::DeviceFactory {
public:
    DemoControllerFactory();
    virtual void createFromDomElement(QDomElement element, drobot::robot::Robot* robot);
};

} // namespace robot
} // namespace demo
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_DEMO_ROBOT_DEMOCONTROLLERFACTORY_H
