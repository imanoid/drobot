#include "eventlistener.h"

namespace drobot {
namespace event {

EventListener::EventListener(std::string type) {
    _type = type;
    _async = false;
}

std::string EventListener::getType() {
    return _type;
}

void EventListener::setAsync(bool async) {
    _async = async;
}

bool EventListener::isAsync() {
    return _async;
}

} // namespace event
} // namespace drobot
