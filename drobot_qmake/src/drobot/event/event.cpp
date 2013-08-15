#include "event.h"

namespace drobot {
namespace event {

Event::Event(std::string type) {
    _type = type;
}

std::string Event::getType() {
    return _type;
}

} // namespace event
} // namespace drobot
