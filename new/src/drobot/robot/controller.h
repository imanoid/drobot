#ifndef DROBOT_ROBOT_CONTROLLER_H
#define DROBOT_ROBOT_CONTROLLER_H

#include "../device/channel/channelmanager.h"
#include <map>
#include "../device/device.h"

namespace drobot {
namespace robot {

class Robot;

/**
 * @brief Base class for Robot Controllers
 * @details this class derives from the Device class so that you may add Channels of type LOG to it. See device::channel::Channel for details.
 */
class Controller : public device::Device
{
protected:
    /**
     * @brief the robot being controlled
     */
    Robot* _robot;
    bool _enabled;
public:
    Controller(std::string name);
    /**
     * @brief This function is called at a specific frequency defined in the Robot.
     * @details This method should first read the values of the input channels,
     *  then calculate the output and write it to the output channels. Additionally other stuff can be written to log channels for logging.
     * @param tick the timestep
     * @param channels of the robot
     */
    virtual void tick(long tick, device::channel::ChannelManager* channels) = 0;
    void setRobot(Robot* robot);
    Robot* getRobot();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
};

} // namespace robot
} // namespace drobot

#endif // DROBOT_ROBOT_CONTROLLER_H
