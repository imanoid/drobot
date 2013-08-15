#ifndef DROBOT_EVENT_EVENTLISTENER_H
#define DROBOT_EVENT_EVENTLISTENER_H

#include <string>
#include "event.h"

namespace drobot {
namespace event {

class EventListener
{
private:
    std::string _type;
public:
    EventListener(std::string type);
    std::string getType();
    virtual void onEvent(Event* event) = 0;
};

} // namespace event
} // namespace drobot

#endif // DROBOT_EVENT_EVENTLISTENER_H
