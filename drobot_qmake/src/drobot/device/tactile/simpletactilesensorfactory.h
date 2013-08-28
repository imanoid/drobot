#ifndef DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORFACTORY_H
#define DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORFACTORY_H

#include "../devicefactory.h"

namespace drobot {
namespace device {
namespace tactile {

class SimpleTactileSensorFactory : public DeviceFactory {
public:
    SimpleTactileSensorFactory();
    virtual void createFromDomElement(QDomElement element, robot::Robot* robot);
};

} // namespace tactile
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORFACTORY_H
