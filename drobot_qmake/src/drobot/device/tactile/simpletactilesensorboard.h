#ifndef DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORBOARD_H
#define DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORBOARD_H

#include "tactilesensorboard.h"
#include "simpletactilesensor.h"

namespace drobot {
namespace device {
namespace tactile {

class SimpleTactileSensorBoard : public TactileSensorBoard
{
private:
    std::string _path;
    int _maxSensors;
public:
    SimpleTactileSensorBoard(std::string name, std::string path);
    SimpleTactileSensorBoard(std::string name, std::string path, int maxSensors);
    virtual void enable();
    void updateLoop();
    std::vector<TactileSensor*> initAllSensors();
    TactileSensor* initSensor(int index, std::string name);
    TactileSensor* initSensor(int index);
    SimpleTactileSensor* getTactileSensor(int index);
};

}
}
}

#endif // SIMPLETACTILESENSORBOARD_H
