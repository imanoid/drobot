#ifndef DROBOT_PROGRAM_RUNNABLE_H
#define DROBOT_PROGRAM_RUNNABLE_H

namespace drobot {
namespace program {

/**
 * @brief base class for different kinds of threads.
 */
class Runnable
{
private:
    void run_interval_loop(int msec);
protected:
    bool _running;
public:
    Runnable();
    virtual ~Runnable();
    /**
     * @brief run_thread launches the run method in a new thread
     */
    void run_thread();
    /**
     * @brief run_interval repeatedly runs the run method in a specific interval
     * @param msec
     */
    void run_interval(int msec);
    /**
     * @brief cancel sets changes the isRunning() method to return false
     */
    void cancel();
    /**
     * @brief isRunning returns true if the program is running. False otherwhise
     * @return true if running, false otherwhise
     */
    bool isRunning();
    /**
     * @brief run has to be implemented by the child class. It should periodically
     *  check if isRunning() still returns true. If it returns false the program should abort.
     */
    virtual void run() = 0;
};

} // namespace program
} // namespace drobot

#endif // DROBOT_PROGRAM_RUNNABLE_H
