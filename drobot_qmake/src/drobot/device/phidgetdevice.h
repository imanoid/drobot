#ifndef _DROBOT_DEVICE_PHIDGETDEVICE_H_
#define _DROBOT_DEVICE_PHIDGETDEVICE_H_

#include "device.h"
#include <phidget21.h>

namespace drobot {
namespace device {

class PhidgetDevice
{
private:
    CPhidgetHandle _phidgetHandle;
public:
    PhidgetDevice(CPhidgetHandle phidgetHandle);
    PhidgetDevice();
    virtual ~PhidgetDevice();
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
