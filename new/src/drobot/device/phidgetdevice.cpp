#include "phidgetdevice.h"
#include <iostream>

namespace drobot {
namespace device {


std::string PhidgetDevice::getPhidgetName() {
    const char** name;
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_getDeviceName(handle, name);
    return std::string(*name);
}

int PhidgetDevice::getPhidgetSerialNumber() {
    int* serial;
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_getSerialNumber(handle, serial);
    return *serial;
}

int PhidgetDevice::getPhidgetVersion() {
    int* version;
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_getDeviceVersion(handle, version);
    return *version;
}

int PhidgetDevice::getPhidgetStatus() {
    int* status;
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_getDeviceStatus(handle, status);
    return *status;
}

std::string PhidgetDevice::getPhidgetType() {
    const char** type;
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_getDeviceType(handle, type);
    return std::string(*type);
}

std::string PhidgetDevice::getPhidgetLabel() {
    const char** label;
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_getDeviceLabel(handle, label);
    return std::string(*label);
}

void PhidgetDevice::setPhidgetLabel(std::string label) {
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_setDeviceLabel(handle, label.c_str());
}

CPhidget_DeviceID PhidgetDevice::getPhidgetId() {
    CPhidget_DeviceID* id;
    CPhidgetHandle handle = this->getPhidgetHandle();
    CPhidget_getDeviceID(handle, id);
    return *id;
}

} // namespace device
} // namespace drobot
