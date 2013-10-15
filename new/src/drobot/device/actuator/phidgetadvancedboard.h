#ifndef DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARD_H
#define DROBOT_DEVICE_ACTUATOR_PHIDGETADVANCEDBOARD_H

#include "actuatorboard.h"
#include "phidget21.h"
#include "phidgetadvancedservo.h"

namespace drobot {
namespace device {
namespace actuator {

/**
 * @brief The PhidgetAdvancedBoard class
 * @details The Phidget Advanced Board contains Phidget Advanced Servo objects which can be initialized and used independently.
 */
class PhidgetAdvancedBoard : public ActuatorBoard
{
private:
    CPhidgetAdvancedServoHandle _phidgetHandle;
public:
    /**
     * @brief Initializes a random connected Phidget Advanced Board
     * @param name
     */
    PhidgetAdvancedBoard(std::string name);
    /**
     * @brief Initializes the Phidget Advanced Board with the given serial
     * @param name
     * @param serial
     */
    PhidgetAdvancedBoard(std::string name, int serial);
    /**
     * @brief Initializes a Phidget Advanced Board by the given CPhidgetAdvancedServoHandle
     * @param name
     * @param phidgetHandle
     */
    PhidgetAdvancedBoard(std::string name, CPhidgetAdvancedServoHandle phidgetHandle);
    virtual ~PhidgetAdvancedBoard();
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

#endif // PHIDGETADVANCEDBOARD_H
