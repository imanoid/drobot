#ifndef DROBOT_UTIL_UTIL_H
#define DROBOT_UTIL_UTIL_H

#include "../device/device.h"
#include <algorithm>

namespace drobot {
namespace util {

template<typename Source, typename Target>
struct Source2Target { Target operator ()( Source source ) const { return dynamic_cast<Target>(source); } };

template<typename Source, typename Target>
std::vector<Target> castVector(const std::vector<Source> source) {
    std::vector<Target> target;
    std::transform( source.begin(), source.end(), target.begin(), Source2Target<Source, Target>() );
}

}
}

#endif // UTIL_H
