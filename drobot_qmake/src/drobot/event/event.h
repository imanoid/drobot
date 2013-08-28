#ifndef DROBOT_EVENT_EVENT_H
#define DROBOT_EVENT_EVENT_H

#include <string>

namespace drobot {
namespace event {

/**
 * @brief The Event class
 */
class Event {
private:
    /**
     * @brief _type of the event. Used to determine which EventListeners to use by the EventManager class
     */
    std::string _type;
public:
    Event(std::string type);
    /**
     * @brief getType. Used to determine which EventListeners to use by the EventManager class
     * @return the type
     */
    std::string getType();
    /**
     * @brief create a string representatio of this event used for console debugging
     * @return the string representation
     */
    virtual std::string toString() = 0;
};

} // namespace event
} // namespace drobot

#endif // DROBOT_EVENT_EVENT_H
