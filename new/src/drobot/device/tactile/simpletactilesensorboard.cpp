#include <iostream>
#include <boost/thread.hpp>

#include "simpletactilesensorboard.h"
#include "simpletactilesensor.h"
#include "../driver/rs232.h"
#include "../../util/util.h"

namespace drobot {
namespace device {
namespace tactile {

SimpleTactileSensorBoard::SimpleTactileSensorBoard(std::string name, std::string path) :
    TactileSensorBoard(name), _path(path), _maxSensors(32) {}

SimpleTactileSensorBoard::SimpleTactileSensorBoard(std::string name, std::string path, int maxSensors) :
    TactileSensorBoard(name), _path(path), _maxSensors(maxSensors) {}

std::vector<TactileSensor*> SimpleTactileSensorBoard::initAllSensors() {
    clear();
    std::vector<TactileSensor*> result;
    for (int iSensor = 0; iSensor < _maxSensors; iSensor++) {
        result.push_back(initSensor(iSensor));
    }
    return result;
}

TactileSensor* SimpleTactileSensorBoard::initSensor(int index, std::string name) {
    SimpleTactileSensor* sensor = new SimpleTactileSensor(name, index);
    if (has(sensor))
        remove(sensor);
    add(sensor);
    return sensor;

}

TactileSensor* SimpleTactileSensorBoard::initSensor(int index) {
    std::stringstream name;
    name << getName() << "." << index;
    return initSensor(index, name.str());
}

SimpleTactileSensor* SimpleTactileSensorBoard::getTactileSensor(int index) {
    std::vector<SimpleTactileSensor*> sensors = util::castVector<TactileSensor*, SimpleTactileSensor*>(getTactileSensors());
    for (std::vector<SimpleTactileSensor*>::iterator iSensor = sensors.begin(); iSensor != sensors.end(); iSensor++) {
        if ((*iSensor)->getIndex() == index)
            return *iSensor;
    }
    return 0;
}

void SimpleTactileSensorBoard::enable() {
    if (isEnabled())
        return;
    DeviceBoard::enable();
    new boost::thread(boost::bind(&SimpleTactileSensorBoard::updateLoop, this));
}

void SimpleTactileSensorBoard::updateLoop() {
    struct termios initialPortSettings;
    int portFileDescriptor;
    //is the buffer aligned?
    bool aligned = false;

    //Open device
    if ((portFileDescriptor = driver::rs232::RS232_OpenPort(_path.c_str(), 230400, true,
            &initialPortSettings)) == -1) {
        std::cerr << "Couldn't open port! Device name is: '" << _path << "'."
                << std::endl;
        return;
    }

    //allocate memory for activation cache
    unsigned char* activations = new unsigned char[_maxSensors + 2];

    //Read values while isEnabled()
    while (isEnabled()) {
        //Allign the buffer first
        while (!aligned) {
            driver::rs232::RS232_ReceiveBuffer(portFileDescriptor, activations, _maxSensors);
            for (int index = 1; index < 34; index++) {
                if (activations[index - 1] == 255
                        && activations[index] == 255) {
                    if (driver::rs232::RS232_ReceiveBuffer(portFileDescriptor, activations,
                            _maxSensors - index + 1)
                            == _maxSensors - index + 1) {
                        aligned = true;
                    }

                    break;
                }
            }

            if (activations[0] == 255 && activations[_maxSensors + 1] == 255) {
                if (driver::rs232::RS232_ReceiveBuffer(portFileDescriptor, activations, 1)
                        == 1) {
                    aligned = true;
                }
            }
        }

        int read = 0;
        //read the values from the buffer
        while (read < _maxSensors + 2) {
            read += std::max(
                    driver::rs232::RS232_ReceiveBuffer(portFileDescriptor, activations + read,
                            _maxSensors + 2 - read), 0); //usleep(100);
        }

        //check if still aligned otherwhise return to the beginning of the loop
        if (activations[_maxSensors] != 255
                || activations[_maxSensors + 1] != 255) {
            aligned = false;
            std::cout << "not aligned" << std::endl;
            continue;
        }

        //copy the activation values to the SimpleTactileSensors
        for (int iSensor = 0; iSensor < _maxSensors; iSensor++) {
            SimpleTactileSensor* sensor = getTactileSensor(iSensor);
            if (sensor != 0) {
                sensor->setValue((double) activations[iSensor]);
            }
        }
        //the sensor readings are stored in a blocking fifo, no need to sleep
    }
    //clean up memory
    delete[] activations;

    //close device
    driver::rs232::RS232_ClosePort(portFileDescriptor, &initialPortSettings);
}

}
}
}
