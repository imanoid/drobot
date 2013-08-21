#ifndef DROBOT_UTIL_EXCEPTION_H
#define DROBOT_UTIL_EXCEPTION_H

#include <string>
#include <sstream>

namespace drobot {
namespace util {

class Exception
{
private:
    std::string _message;
public:
    Exception(std::string message);
    Exception();
    std::string getMessage();
    Exception& operator<<(std::string message);
    Exception& operator<<(int message);
    Exception& operator<<(double message);
};

} // namespace util
} // namespace drobot

#endif // DROBOT_UTIL_EXCEPTION_H
