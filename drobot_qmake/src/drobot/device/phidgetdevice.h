#ifndef DROBOT_DEVICE_PHIDGETDEVICE_H
#define DROBOT_DEVICE_PHIDGETDEVICE_H

#include "device.h"
#include <phidget21.h>

namespace drobot {
namespace device {

class PhidgetDevice
{
protected:
    virtual CPhidgetHandle& getPhidgetHandle() = 0;
public:
    std::string getPhidgetName();
    int getPhidgetSerialNumber();
    int getPhidgetVersion();
    int getPhidgetStatus();
    std::string getPhidgetType();
    std::string getPhidgetLabel();
    void setPhidgetLabel(std::string label);
    CPhidget_DeviceID getPhidgetId();
};

} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_PHIDGETDEVICE_H
