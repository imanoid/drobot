#ifndef DROBOT_UTIL_EXCEPTION_H
#define DROBOT_UTIL_EXCEPTION_H

#include <string>
#include <sstream>

namespace drobot {
namespace util {

/**
 * @brief The Exception class is the base class for all exceptions.
 */
class Exception
{
private:
    std::string _message;
public:
    Exception(std::string message);
    Exception();
    std::string getMessage();
    /**
     * @brief operator << is used to append a string to the message
     * @param message
     * @return reference to the exception
     */
    Exception& operator<<(std::string message);
    /**
     * @brief operator << is used to append a int to the message
     * @param message
     * @return reference to the exception
     */
    Exception& operator<<(int message);
    /**
     * @brief operator << is used to append a double to the message
     * @param message
     * @return reference to the exception
     */
    Exception& operator<<(double message);
};

} // namespace util
} // namespace drobot

#endif // DROBOT_UTIL_EXCEPTION_H
