#ifndef DROBOT_EVENT_EVENTMANAGER_H
#define DROBOT_EVENT_EVENTMANAGER_H

#include "event.h"
#include "eventlistener.h"
#include <map>
#include <vector>
#include <string>

namespace drobot {
namespace event {

/**
 * @brief Used for managing events.
 * @details Each robot has it's own EventManager.
 */
class EventManager {
private:
    std::map<std::string, std::vector<EventListener*> > _eventListeners;
public:
    EventManager();
    /**
     * @brief add an EventListener
     * @param eventListener
     */
    void registerEventListener(EventListener* eventListener);
    /**
     * @brief remove an EventListener
     * @param eventListener
     */
    void unregisterEventListener(EventListener* eventListener);
    /**
     * @brief fire Event
     * @param event
     */
    void fireEvent(Event* event);
};

} // namespace event
} // namespace drobot

#endif // DROBOT_EVENT_EVENTMANAGER_H
