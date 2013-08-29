#ifndef DROBOT_DEVICE_CHANNEL_H
#define DROBOT_DEVICE_CHANNEL_H

#include "normalizer.h"
#include <string>
#include "channeltype.h"
#include "../../object/item.h"

namespace drobot {
namespace device {

class Device;

namespace channel {

/**
 * @brief The Channel class is used to handle inputs and outputs from devices and log values.
 * @details The Channel represents a property of a physical or virtual (simulated) device or simply a value you want to log.
 *  During runtime on each time step first all the read methods of the robot's channels are executed. The read() method takes the current
 *  value via the getValue() method and copies it into the _value property (if it is an input). Then the controller takes the inputs
 *  and calculates the outputs. These are set via setRealValue() or setNormalizedValue() to the _value property. After the write() method is
 *  executed which set's the _value to the device via the setValue() method. For details see the robot::Robot and robot::Controller classes.
 */
class Channel : public object::Item
{
private:
    /**
     * @brief _normalizer used to convert the realValue to a normalized value between 0 and 1 and back again.
     */
    Normalizer* _normalizer;
    /**
     * @brief _type of the channel
     */
    ChannelType _type;
    /**
     * @brief _value serves as a cache
     */
    double _value;
    /**
     * @brief _update true if output has been set during this timestep. Tells the system to set the value to the device via setDevice()
     */
    bool _update;
protected:
    /**
     * @brief the device this Channel belongs to
     */
    Device* _device;
    /**
     * @brief returns the value directly from the device.
     * @return
     */
    virtual double getValue() = 0;
    /**
     * @brief sets the value directly to the device
     * @param value
     */
    virtual void setValue(double value) = 0;
public:
    Channel(std::string name, ChannelType type);
    Channel(std::string name, ChannelType type, Normalizer* normalizer, Device* device);
    virtual ~Channel();
    void setNormalizer(Normalizer* normalizer);
    Normalizer* getNormalizer();
    void setDevice(Device* device);
    Device* getDevice();
    /**
     * @brief set value in a normalized scale
     * @details set a normalized value to this channel (for instance an output from a neural network). Is automatically converted
     *  to a device recognizable value.
     * @param value
     */
    void setNormalizedValue(double value);
    /**
     * @brief getNormalizedValue
     * @return the normalized value
     */
    double getNormalizedValue();
    /**
     * @brief sets the value in the device recognizable format
     * @param value
     */
    void setRealValue(double value);
    /**
     * @brief getRealValue
     * @return the real value
     */
    double getRealValue();
    std::string getName();
    void setType(ChannelType type);
    ChannelType getType();
    /**
     * @brief read value from device
     * @details copies the value from the device to the _value property using getValue() if it is an input channel.
     */
    void read();
    /**
     * @brief write value to device
     * @details writes the value from the _value property to the device using setValue() if it is an output channel
     *  and a value has been set since the last call of write().
     */
    void write();
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_CHANNEL_H
