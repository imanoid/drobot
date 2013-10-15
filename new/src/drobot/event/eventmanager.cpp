#include "eventmanager.h"
#include <iostream>
#include <boost/thread.hpp>

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
    std::string type = event->getType();

    //std::cout << "=====fireEvent(" << type << ")=====" << std::endl << event->toString() << std::endl;

    if (_eventListeners.find(type) == _eventListeners.end())
        return;
    std::vector<EventListener*> eventListeners = _eventListeners[type];
    for (std::vector<EventListener*>::iterator iEventListener = eventListeners.begin(); iEventListener != eventListeners.end(); iEventListener++) {
        EventListener* listener = (*iEventListener);
        if (!listener->isAsync()) {
            listener->onEvent(event);
        } else {
            boost::thread* t = new boost::thread(boost::bind(&EventListener::onEvent, listener, event));
        }
    }
}

} // namespace event
} // namespace drobot
