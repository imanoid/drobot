#ifndef DROBOT_EVENT_EVENT_H
#define DROBOT_EVENT_EVENT_H

#include <string>

namespace drobot {
namespace event {

class Event
{
private:
    std::string _type;
public:
    Event(std::string type);
    std::string getType();
    virtual std::string toString() = 0;
};

} // namespace event
} // namespace drobot

#endif // DROBOT_EVENT_EVENT_H
