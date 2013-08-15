#ifndef DROBOT_PROGRAM_PROGRAM_H
#define DROBOT_PROGRAM_PROGRAM_H

#include "runnable.h"
#include <QWidget>
#include <string>

namespace drobot {
namespace program {

class Program : public Runnable
{
protected:
    QWidget* _widget;
    std::string _name;
public:
    Program(std::string name);
    std::string getName();
    void setName(std::string name);
    virtual QWidget* getWidget() = 0;
};

}
}

#endif // PROGRAM_H
