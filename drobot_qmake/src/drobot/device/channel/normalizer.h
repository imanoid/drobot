#ifndef DROBOT_DEVICE_CHANNEL_NORMALIZER_H
#define DROBOT_DEVICE_CHANNEL_NORMALIZER_H

namespace drobot {
namespace device {
namespace channel {

class Normalizer
{
public:
    virtual double normalize(double value) = 0;
    virtual double denormalize(double value) = 0;
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_NORMALIZER_H
