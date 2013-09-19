#ifndef DROBOT_EVENT_EVENTLISTENER_H
#define DROBOT_EVENT_EVENTLISTENER_H

#include <string>
#include "event.h"

namespace drobot {
namespace event {

/**
 * @brief Abstract class to be implemented by EventListeners
 */
class EventListener {
private:
    /**
     * @brief type of events that are handled by this eventListener
     */
    std::string _type;
    /**
     * @brief _async is true if onEvent should be executed in a new thread. false otherwhise
     */
    bool _async;
public:
    EventListener(std::string type);
    /**
     * @brief getType. type of events that are handled by this eventListener
     * @return the event type
     */
    std::string getType();
    /**
     * @brief setAsync
     * @details this property is true if onEvent should be executed in a new thread. false otherwhise
     * @param async
     */
    void setAsync(bool async);
    /**
     * @brief isAsync
     * @return true if asynchronous, false otherwhise
     */
    bool isAsync();
    /**
     * @brief onEvent. This method is called when an event of this type is fired.
     * @param event fired
     */
    virtual void onEvent(Event* event) = 0;
};

} // namespace event
} // namespace drobot

#endif // DROBOT_EVENT_EVENTLISTENER_H
