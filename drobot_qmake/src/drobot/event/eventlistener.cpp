#include "eventlistener.h"

namespace drobot {
namespace event {

EventListener::EventListener(std::string type) {
    _type = type;
}

std::string EventListener::getType() {
    return _type;
}

} // namespace event
} // namespace drobot
