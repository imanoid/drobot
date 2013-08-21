#include "exception.h"

namespace drobot {
namespace util {

Exception::Exception(std::string message) {
    _message = message;
}

Exception::Exception() {
}

std::string Exception::getMessage() {
    return _message;
}

Exception& Exception::operator<<(std::string message) {
    std::stringstream input;
    input << _message << message;
    _message = input.str();
    return *this;
}


Exception& Exception::operator<<(int message) {
    std::stringstream input;
    input << _message << message;
    _message = input.str();
    return *this;
}

Exception& Exception::operator<<(double message) {
    std::stringstream input;
    input << _message << message;
    _message = input.str();
    return *this;
}

} // namespace util
} // namespace drobot
