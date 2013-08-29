#ifndef DROBOT_DEVICE_DEVICE_H
#define DROBOT_DEVICE_DEVICE_H

#include <string>
#include <vector>
#include <map>
#include "channel/channelmanager.h"
#include "../object/item.h"

namespace drobot {
namespace device {
namespace actuator {
    class Actuator;
}
namespace tactile {
    class TactileSensor;
}
namespace vestibular {
    class Vestibular;
}
namespace vision {
    class Vision;
}

class DeviceBoard;

/**
 * @brief Represents a physical or virtual (simulated) device
 * @details A device can be any part of a robot actuator or sensor.
 *  It can also be used to implement a virtual device like a robot controller for instance.
 *  A device contains different kinds of channels represented by the drobot::device::channel::Channel
 *  class which are managed by the _channels property. To add and remove channels use the _channels property (See object::Manager).
 *  Certain devices belong to a DeviceBoard (See actuator::PhidgetAdvancedServo for example).
 */
class Device : public object::Item {
private:
    /**
     * @brief _deviceBoard The DeviceBoard it belongs to
     */
    DeviceBoard* _deviceBoard;
    /**
     * @brief _channels Data structure containing the channels
     */
    channel::ChannelManager* _channels;
public:
    Device(std::string name);
    virtual ~Device();
    /**
     * @brief enables the device.
     * @details This function has to be implemented by the specific device. For physical devices like actuators this method should power on the device.
     */
    virtual void enable();
    /**
     * @brief disables the device.
     * @details This function has to be implemented by the specific device. For physical devices like actuators this method should power off the device;
     */
    virtual void disable();
    /**
     * @brief check if the device is enabled
     * @return true if enabled else false
     * @details While the drobot::robot::Robot is running this property is checked to see whether the device should be used or not.
     */
    virtual bool isEnabled() = 0;
    /**
     * @return the DeviceBoard
     */
    DeviceBoard* getDeviceBoard();
    /**
     * @brief sets the DeviceBoard
     * @param deviceBoard
     */
    void setDeviceBoard(DeviceBoard* deviceBoard);
    /**
     * @brief cast to Device
     * @return Device Pointer
     */
    Device* toDevice();
    /**
     * @brief cast to actuator::Actuator
     * @return actuator::Actuator Pointer
     */
    actuator::Actuator* toActuator();
    /**
     * @brief cast to tactile::TactileSensor
     * @return tactile::TactileSensor Pointer
     */
    tactile::TactileSensor* toTactileSensor();
    /**
     * @brief cast to vestibular::Vestibular
     * @return vestibular::Vestibular Pointer
     */
    vestibular::Vestibular* toVestibular();
    /**
     * @brief cast to vision::Vision
     * @return vision::Vision Pointer
     */
    vision::Vision* toVision();
    /**
     * @return Data structure containing the devices channels.
     */
    virtual channel::ChannelManager* getChannels();
};

}
}

#endif // DEVICE_H
