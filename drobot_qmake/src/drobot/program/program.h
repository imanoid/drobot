#ifndef DROBOT_PROGRAM_PROGRAM_H
#define DROBOT_PROGRAM_PROGRAM_H

#include <QWidget>
#include <string>

namespace drobot {
namespace program {

class Program
{
protected:
    QWidget* _widget;
    bool _running;
    std::string _name;
public:
    Program(std::string name);
    void start();
    void stop();
    bool isRunning();
    std::string getName();
    void setName(std::string name);
    virtual QWidget* getWidget() = 0;
    virtual void loop() = 0;
};

}
}

#endif // PROGRAM_H
