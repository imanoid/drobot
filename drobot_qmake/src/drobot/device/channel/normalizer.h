#ifndef DROBOT_DEVICE_CHANNEL_NORMALIZER_H
#define DROBOT_DEVICE_CHANNEL_NORMALIZER_H

namespace drobot {
namespace device {
namespace channel {

/**
 * @brief The Normalizer class
 * @details used to normalize a value to the interval from 0 to 1 (for use in neural networks etc) and back again.
 */
class Normalizer
{
public:
    /**
     * @brief normalize value to the interval from 0 to 1
     * @param value
     * @return normalized value
     */
    virtual double normalize(double value) = 0;
    /**
     * @brief denormalize value from an interval from 0 to 1 to it's original range
     * @param value
     * @return denormalized value
     */
    virtual double denormalize(double value) = 0;
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_NORMALIZER_H
