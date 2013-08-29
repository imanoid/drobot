#ifndef DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORBOARD_H
#define DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORBOARD_H

#include "tactilesensorboard.h"
#include "simpletactilesensor.h"

namespace drobot {
namespace device {
namespace tactile {

/**
 * @brief The SimpleTactileSensorBoard class
 */
class SimpleTactileSensorBoard : public TactileSensorBoard
{
private:
    std::string _path;
    int _maxSensors;
public:
    SimpleTactileSensorBoard(std::string name, std::string path);
    SimpleTactileSensorBoard(std::string name, std::string path, int maxSensors);
    virtual void enable();
    /**
     * @brief updates the values of the SimpleTactileSensors in a loop.
     * @details reads the values from the SensorBoard. The SensorBoard has a blocking fifo in from which the values can be read.
     *  this method is launched in the enable() method in a separate thread and canceled in the disable() function.
     */
    void updateLoop();
    /**
     * @brief initializes all the sensors and adds them to the board
     * @return initialized sensors
     */
    std::vector<TactileSensor*> initAllSensors();
    /**
     * @brief initializes a sensor at the given index and adds them to the board
     * @param index
     * @param name
     * @return initialized sensor
     */
    TactileSensor* initSensor(int index, std::string name);
    /**
     * @brief initializes a sensor at the given index and adds it to the board
     * @param index
     * @return initialized sensor
     */
    TactileSensor* initSensor(int index);
    SimpleTactileSensor* getTactileSensor(int index);
};

}
}
}

#endif // SIMPLETACTILESENSORBOARD_H
