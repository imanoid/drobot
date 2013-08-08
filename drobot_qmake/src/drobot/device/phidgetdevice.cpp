#include "phidgetdevice.h"

namespace drobot {
namespace device {

PhidgetDevice::PhidgetDevice(CPhidgetHandle phidgetHandle) : _phidgetHandle(phidgetHandle) {
}

PhidgetDevice::PhidgetDevice() : _phidgetHandle(0) {
}

PhidgetDevice::~PhidgetDevice() {
    CPhidget_delete(_phidgetHandle);
}

std::string PhidgetDevice::getPhidgetName() {
    const char** name;
    CPhidget_getDeviceName(_phidgetHandle, name);
    return std::string(*name);
}

int PhidgetDevice::getPhidgetSerialNumber() {
    int* serial;
    CPhidget_getSerialNumber(_phidgetHandle, serial);
    return *serial;
}

int PhidgetDevice::getPhidgetVersion() {
    int* version;
    CPhidget_getDeviceVersion(_phidgetHandle, version);
    return *version;
}

int PhidgetDevice::getPhidgetStatus() {
    int* status;
    CPhidget_getDeviceStatus(_phidgetHandle, status);
    return *status;
}

std::string PhidgetDevice::getPhidgetType() {
    const char** type;
    CPhidget_getDeviceType(_phidgetHandle, type);
    return std::string(*type);
}

std::string PhidgetDevice::getPhidgetLabel() {
    const char** label;
    CPhidget_getDeviceLabel(_phidgetHandle, label);
    return std::string(*label);
}

void PhidgetDevice::setPhidgetLabel(std::string label) {
    CPhidget_setDeviceLabel(_phidgetHandle, label.c_str());
}

CPhidget_DeviceID PhidgetDevice::getPhidgetId() {
    CPhidget_DeviceID* id;
    CPhidget_getDeviceID(_phidgetHandle, id);
    return *id;
}

} // namespace device
} // namespace drobot
