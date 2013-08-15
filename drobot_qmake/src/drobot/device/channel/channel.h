#ifndef DROBOT_DEVICE_CHANNEL_H
#define DROBOT_DEVICE_CHANNEL_H

#include "normalizer.h"
#include <string>

namespace drobot {
namespace device {

class Device;

namespace channel {

class Channel
{
protected:
    Normalizer* _normalizer;
    Device* _device;
    std::string _name;
public:
    Channel(std::string name);
    Channel(std::string name, Normalizer* normalizer, Device* device);
    void setNormalizer(Normalizer* normalizer);
    Normalizer* getNormalizer();
    void setDevice(Device* device);
    Device* getDevice();
    void setNormalizedValue(double value);
    double getNormalizedValue();
    void setName(std::string name);
    std::string getName();
    virtual double getValue() = 0;
    virtual void setValue(double value) = 0;
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_CHANNEL_H
