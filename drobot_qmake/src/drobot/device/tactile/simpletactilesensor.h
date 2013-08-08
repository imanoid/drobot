#ifndef DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSOR_H
#define DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSOR_H

#include "tactilesensor.h"

namespace drobot {
namespace device {
namespace tactile {

class SimpleTactileSensor : public TactileSensor
{
private:
    double _value;
    bool _enabled;
    int _index;
public:
    SimpleTactileSensor(int index);
    SimpleTactileSensor(int index, double value);
    virtual double getValue();
    void setValue(double value);
    virtual void enable();
    virtual void disable();
    virtual bool isEnabled();
};

}
}
}

#endif // SIMPLETACTILESENSOR_H
