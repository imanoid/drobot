#ifndef DROBOT_EXPERIMENT_HANDMOUTH_ROBOT_HANDMOUTHCONTROLLERFACTORY_H
#define DROBOT_EXPERIMENT_HANDMOUTH_ROBOT_HANDMOUTHCONTROLLERFACTORY_H

#include "../../../device/devicefactory.h"
#include "../../../robot/robot.h"

namespace drobot {
namespace experiment {
namespace handmouth {
namespace robot {

class HandMouthControllerFactory : public device::DeviceFactory {
public:
    HandMouthControllerFactory();
    virtual void createFromDomElement(QDomElement element, drobot::robot::Robot* robot);
};

} // namespace robot
} // namespace handmouth
} // namespace experiment
} // namespace drobot

#endif // DROBOT_EXPERIMENT_HANDMOUTH_ROBOT_HANDMOUTHCONTROLLERFACTORY_H
