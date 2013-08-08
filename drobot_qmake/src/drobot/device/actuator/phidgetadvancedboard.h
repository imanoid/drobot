#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARD_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARD_H

#include "actuatorboard.h"
#include "phidget21.h"
#include "../phidgetdevice.h"
#include "phidgetadvancedservo.h"

namespace drobot {
namespace device {
namespace actuator {

class PhidgetAdvancedBoard : public ActuatorBoard, public PhidgetDevice
{
private:
    CPhidgetAdvancedServoHandle _phidgetHandle;
public:
    PhidgetAdvancedBoard(int serial);
    const int getMaxActuators() const;
    std::vector<Actuator*> initAllActuators();
    Actuator* initActuator(int index);
};

}
}
}

#endif // PHIDGETADVANCEDBOARD_H
