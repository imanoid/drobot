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

class Channel : public object::Item
{
private:
    Normalizer* _normalizer;
    Device* _device;
    ChannelType _type;
    double _value;
    bool _update;
public:
    Channel(std::string name, ChannelType type);
    Channel(std::string name, ChannelType type, Normalizer* normalizer, Device* device);
    void setNormalizer(Normalizer* normalizer);
    Normalizer* getNormalizer();
    void setDevice(Device* device);
    Device* getDevice();
    void setNormalizedValue(double value);
    double getNormalizedValue();
    void setRealValue(double value);
    double getRealValue();
    std::string getName();
    void setType(ChannelType type);
    ChannelType getType();
    virtual double getValue() = 0;
    virtual void setValue(double value) = 0;
    void read();
    void write();
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_CHANNEL_H
