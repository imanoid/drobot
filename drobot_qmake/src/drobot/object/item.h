#ifndef DROBOT_OBJECT_ITEM_H
#define DROBOT_OBJECT_ITEM_H

#include <string>

namespace drobot {
namespace object {

class Item
{
protected:
    std::string _name;
public:
    Item(std::string name);
    virtual ~Item();
    void setName(std::string name);
    virtual std::string getName();
};

} // namespace object
} // namespace drobot

#endif // DROBOT_OBJECT_ITEM_H
