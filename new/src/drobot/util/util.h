#ifndef DROBOT_UTIL_UTIL_H
#define DROBOT_UTIL_UTIL_H

#include <vector>
#include <map>

namespace drobot {
namespace util {

template<typename Source, typename Target>
struct Source2Target { Target operator ()( Source source ) const { return dynamic_cast<Target>(source); } };

template<typename Source, typename Target>
/**
 * @brief castVector casts a vector containing Source elements elementwise to a vector containing Target elements.
 * @details The Source and Target template parameters need to be of type pointer.
 * @param source
 * @return new vector containing Target elements
 */
std::vector<Target> castVector(std::vector<Source> source) {
    std::vector<Target> target;
    for (typename std::vector<Source>::iterator iSource = source.begin(); iSource != source.end(); iSource++) {
        target.push_back(dynamic_cast<Target>(*iSource));
    }
    return target;
}

template<typename T>
/**
 * @brief deleteVectorValues deletes the values of the vector and clears it. Use for pointer vectors only.
 * @param values
 */
void deleteVectorValues(std::vector<T> values) {
    for (typename std::vector<T>::iterator iValue = values.begin(); iValue != values.end(); iValue++) {
        delete (*iValue);
    }
    values.clear();
}

template<typename K, typename V>
/**
 * @brief deleteMapValues deletes the values of the map and clears it. Use for maps with pointer values only.
 * @param values
 */
void deleteMapValues(std::map<K, V> values) {
    for (typename std::map<K, V>::iterator iValue = values.begin(); iValue != values.end(); iValue++) {
        delete iValue->second;
    }
    values.clear();
}

}
}

#endif // UTIL_H
