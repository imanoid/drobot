#ifndef DROBOT_DEVICE_CHANNEL_LINEARNORMALIZER_H
#define DROBOT_DEVICE_CHANNEL_LINEARNORMALIZER_H

#include "normalizer.h"

namespace drobot {
namespace device {
namespace channel {

/**
 * @brief The LinearNormalizer class
 * @details linearly normalizes values from _min to _max to a 0 to 1 interval
 */
class LinearNormalizer : public Normalizer
{
private:
    double _min;
    double _max;
public:
    LinearNormalizer(double min, double max);
    virtual double normalize(double value);
    virtual double denormalize(double value);
};

} // namespace channel
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_CHANNEL_LINEARNORMALIZER_H
