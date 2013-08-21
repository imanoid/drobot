#include "item.h"
#include <iostream>

namespace drobot {
namespace object {

Item::Item(std::string name) {
    _name = name;
}

Item::~Item() {
    std::cout << _name << " destroyed." << std::endl;
}

void Item::setName(std::string name) {
    _name = name;
}

std::string Item::getName() {
    return _name;
}

} // namespace object
} // namespace drobot
