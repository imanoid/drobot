#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARD_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETSIMPLEBOARD_H

#include "actuatorboard.h"
#include <phidget21.h>
#include "../phidgetdevice.h"

namespace drobot {
namespace device {
namespace actuator {
/**
 * @brief The Phidget Simple Board class
 * @details This Class handles the "Phidget Servo" board. The Phidget Simple Board contains Phidget Simple Servo objects which
 *  can be initialized and used independently.
 */
class PhidgetSimpleBoard : public ActuatorBoard
{
private:
    CPhidgetServoHandle _phidgetHandle;
protected:
    virtual CPhidgetHandle& getPhidgetHandle();
public:
    /**
     * @brief Initializes a random connected Phidget Simple Board
     * @param name
     */
    PhidgetSimpleBoard(std::string name);
    /**
     * @brief Initializes the Phidget Simple Board with the given serial
     * @param name
     * @param serial
     */
    PhidgetSimpleBoard(std::string name, int serial);
    /**
     * @brief Initializes a Phidget Simple Board by the given CPhidgetServoHandle
     * @param name
     * @param phidgetHandle
     */
    PhidgetSimpleBoard(std::string name, CPhidgetServoHandle phidgetHandle);
    virtual ~PhidgetSimpleBoard();
    /**
     * @return max number of actuators
     */
    int getMaxActuators();
    /**
     * @brief initializes all the connected Servo Motors and adds them to the board
     * @return initialized servos
     */
    std::vector<Actuator*> initAllActuators();
    /**
     * @brief initializes the servomotor at the given index and adds it to the board
     * @param index
     * @param name of the servomotor
     * @return the initialized servomotor
     */
    Actuator* initActuator(int index, std::string name);
    /**
     * @brief initializes the servomotor at the given index and adds it to the board
     * @param index
     * @return the initialized servomotor
     */
    Actuator* initActuator(int index);
};

}
}
}

#endif // PHIDGETSIMPLEBOARD_H
