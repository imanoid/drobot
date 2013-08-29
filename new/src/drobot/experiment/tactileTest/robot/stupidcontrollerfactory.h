#ifndef DROBOT_EXPERIMENT_TACTILETEST_ROBOT_STUPIDCONTROLLERFACTORY_H
#define DROBOT_EXPERIMENT_TACTILETEST_ROBOT_STUPIDCONTROLLERFACTORY_H

#include "../../../device/devicefactory.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace tactileTest {
namespace robot {

class StupidControllerFactory : public device::DeviceFactory {
public:
    StupidControllerFactory();
    virtual void createFromDomElement(QDomElement element, drobot::robot::Robot* robot);
};

} // namespace robot
} // namespace tactileTest
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_TACTILETEST_ROBOT_STUPIDCONTROLLERFACTORY_H
