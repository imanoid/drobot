#include "eventmanager.h"

namespace drobot {
namespace event {

EventManager::EventManager()
{
}

void EventManager::registerEventListener(EventListener* eventListener) {
    std::string type = eventListener->getType();
    if (_eventListeners.find(type) == _eventListeners.end())
        _eventListeners[type] = std::vector<EventListener*>();
    _eventListeners[type].push_back(eventListener);
}

void EventManager::unregisterEventListener(EventListener* eventListener) {
    std::string type = eventListener->getType();
    if (_eventListeners.find(type) == _eventListeners.end())
        return;
    std::vector<EventListener*> eventListeners = _eventListeners[type];
    for (std::vector<EventListener*>::iterator iEventListener = eventListeners.begin(); iEventListener != eventListeners.end(); iEventListener++) {
        if (*iEventListener == eventListener) {
            eventListeners.erase(iEventListener);
            return;
        }
    }
}

void EventManager::fireEvent(Event* event) {
    std::string type = eventListener->getType();
    if (_eventListeners.find(type) == _eventListeners.end())
        return;
    std::vector<EventListener*> eventListeners = _eventListeners[type];
    for (std::vector<EventListener*>::iterator iEventListener = eventListeners.begin(); iEventListener != eventListeners.end(); iEventListener++) {
        (*iEventListener)->onEvent(event);
    }
}

} // namespace event
} // namespace drobot
