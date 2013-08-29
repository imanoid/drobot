#include "linearnormalizer.h"

namespace drobot {
namespace device {
namespace channel {

LinearNormalizer::LinearNormalizer(double min, double max) {
    _min = min;
    _max = max;
}

double LinearNormalizer::normalize(double value) {
    return (value - _min) / (_max - _min);
}

double LinearNormalizer::denormalize(double value) {
    return value * (_max - _min) + _min;
}

} // namespace channel
} // namespace device
} // namespace drobot
