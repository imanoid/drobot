#ifndef DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORBOARDFACTORY_H
#define DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORBOARDFACTORY_H

#include "../devicefactory.h"

namespace drobot {
namespace device {
namespace tactile {

class SimpleTactileSensorBoardFactory : public DeviceFactory
{
public:
    virtual std::vector<Device*> createFromDomElement(QDomElement element);
};

} // namespace tactile
} // namespace device
} // namespace drobot

#endif // DROBOT_DEVICE_TACTILE_SIMPLETACTILESENSORBOARDFACTORY_H
