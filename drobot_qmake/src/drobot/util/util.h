#ifndef DROBOT_UTIL_UTIL_H
#define DROBOT_UTIL_UTIL_H

#include "../device/device.h"
#include <algorithm>

namespace drobot {
namespace util {

template<typename Source, typename Target>
struct Source2Target { Target operator ()( Source source ) const { return dynamic_cast<Target>(source); } };

template<typename Source, typename Target>
std::vector<Target> castVector(std::vector<Source> source) {
    std::vector<Target> target;
    for (typename std::vector<Source>::iterator iSource = source.begin(); iSource != source.end(); iSource++) {
        target.push_back(dynamic_cast<Target>(*iSource));
    }
    return target;
}

}
}

#endif // UTIL_H
