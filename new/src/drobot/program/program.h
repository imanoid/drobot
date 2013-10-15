#ifndef DROBOT_PROGRAM_PROGRAM_H
#define DROBOT_PROGRAM_PROGRAM_H

#include "runnable.h"
#include "../object/item.h"
#include <QWidget>
#include <string>

namespace drobot {
namespace program {

/**
 * @brief The Program class represents a running program and serves as a base class. It has a GUI associated with it. See getWidget().
 */
class Program : public Runnable, public object::Item
{
protected:
    QWidget* _widget;
public:
    Program(std::string name);
    /**
     * @brief getWidget. This method returns a widget for this program containing its GUI.
     * @return the widget
     */
    virtual QWidget* getWidget() = 0;
};

}
}

#endif // PROGRAM_H
