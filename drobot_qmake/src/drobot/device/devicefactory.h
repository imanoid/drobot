#ifndef DROBOT_DEVICE_DEVICEFACTORY_H
#define DROBOT_DEVICE_DEVICEFACTORY_H

#include <QtXml/QDomElement>
#include "device.h"
#include <vector>

namespace drobot {
namespace device {

class DeviceFactory
{
private:
    std::string _name;
public:
    virtual std::vector<Device*> createFromDomElement(QDomElement) = 0;
    std::string getName();
};

} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_DEVICEFACTORY_H
