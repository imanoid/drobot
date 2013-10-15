#ifndef DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSOR_H
#define DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSOR_H

#include "tactilesensor.h"

namespace drobot {
namespace device {
namespace tactile {

/**
 * @brief The SimpleTactileSensor class represents a tactile sensor which is connected to a SimpleTactileSensorBoard.
 * The value is set by the SimpleTactileSensorBoard in a loop.
 */
class SimpleTactileSensor : public TactileSensor
{
private:
    double _value;
    bool _enabled;
    int _index;
public:
    SimpleTactileSensor(std::string name, int index);
    SimpleTactileSensor(std::string name, int index, double value);
    /**
     * @return index of the slot the sensor is plugged into the sensor board
     */
    int getIndex();
    virtual double getValue();
    void setValue(double value);
    virtual double getValueMin();
    virtual double getValueMax();
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
};

}
}
}

#endif // SIMPLETACTILESENSOR_H
