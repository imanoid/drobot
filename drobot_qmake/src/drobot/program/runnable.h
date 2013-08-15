#ifndef DROBOT_PROGRAM_RUNNABLE_H
#define DROBOT_PROGRAM_RUNNABLE_H

namespace drobot {
namespace program {

class Runnable
{
protected:
    bool _running;
public:
    Runnable();
    void run_thread();
    void cancel();
    bool isRunning();
    virtual void run() = 0;
};

} // namespace program
} // namespace drobot

#endif // DROBOT_PROGRAM_RUNNABLE_H
