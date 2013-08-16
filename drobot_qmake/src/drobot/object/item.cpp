#include "item.h"

namespace drobot {
namespace object {

Item::Item(std::string name) {
    _name = name;
}

void Item::setName(std::string name) {
    _name = name;
}

std::string Item::getName() {
    return _name;
}

} // namespace object
} // namespace drobot
