#ifndef DROBOT_EVENT_EVENTMANAGER_H
#define DROBOT_EVENT_EVENTMANAGER_H

#include "event.h"
#include "eventlistener.h"
#include <map>
#include <vector>
#include <string>

namespace drobot {
namespace event {

class EventManager
{
private:
    std::map<std::string, std::vector<EventListener*> > _eventListeners;
public:
    EventManager();
    void registerEventListener(EventListener* eventListener);
    void unregisterEventListener(EventListener* eventListener);
    void fireEvent(Event* event);
};

} // namespace event
} // namespace drobot

#endif // DROBOT_EVENT_EVENTMANAGER_H
