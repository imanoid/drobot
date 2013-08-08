QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drobot_qtgui
TEMPLATE = app

HEADERS += \
    src/drobot/device/actuator/actuator.h \
    src/drobot/device/actuator/actuatorboard.h \
    src/drobot/device/actuator/phidgetadvancedboard.h \
    src/drobot/device/actuator/phidgetadvancedboardfactory.h \
    src/drobot/device/actuator/phidgetadvancedservo.h \
    src/drobot/device/actuator/phidgetsimpleboard.h \
    src/drobot/device/actuator/phidgetsimpleboardfactory.h \
    src/drobot/device/actuator/phidgetsimpleservo.h \
    src/drobot/device/tactile/simpletactilesensor.h \
    src/drobot/device/tactile/simpletactilesensorboard.h \
    src/drobot/device/tactile/simpletactilesensorboardfactory.h \
    src/drobot/device/tactile/tactilesensor.h \
    src/drobot/device/tactile/tactilesensorboard.h \
    src/drobot/device/vestibular/phidgetvestibular.h \
    src/drobot/device/vestibular/phidgetvestibularfactory.h \
    src/drobot/device/vestibular/vestibular.h \
    src/drobot/device/vision/capture/capture.h \
    src/drobot/device/vision/capture/capturedevices.h \
    src/drobot/device/vision/capture/dc1394device.h \
    src/drobot/device/vision/vision.h \
    src/drobot/device/device.h \
    src/drobot/device/deviceboard.h \
    src/drobot/device/devicefactory.h \
    src/drobot/device/devicemanager.h \
    src/drobot/device/phidgetdevice.h \
    src/drobot/device/rs232.h \
    src/drobot/program/program.h \
    src/drobot/program/programfactory.h \
    src/drobot/program/programmanager.h \
    src/drobot/util/util.h \
    src/drobot/widget/mainwindow.h \
    src/drobot/experiment/deviceTest/program/devicetestprogram.h \
    src/drobot/experiment/deviceTest/program/devicetestprogramfactory.h \
    src/drobot/experiment/tactileTest/program/tactiletestprogram.h \
    src/drobot/experiment/tactileTest/program/tactiletestprogramfactory.h \
    src/drobot/experiment/tactileTest/widget/tactiletestmainwidget.h

SOURCES += \
    src/drobot/device/actuator/actuatorboard.cpp \
    src/drobot/device/actuator/phidgetadvancedboard.cpp \
    src/drobot/device/actuator/phidgetadvancedboardfactory.cpp \
    src/drobot/device/actuator/phidgetadvancedservo.cpp \
    src/drobot/device/actuator/phidgetsimpleboard.cpp \
    src/drobot/device/actuator/phidgetsimpleboardfactory.cpp \
    src/drobot/device/actuator/phidgetsimpleservo.cpp \
    src/drobot/device/tactile/simpletactilesensor.cpp \
    src/drobot/device/tactile/simpletactilesensorboard.cpp \
    src/drobot/device/tactile/simpletactilesensorboardfactory.cpp \
    src/drobot/device/tactile/tactilesensorboard.cpp \
    src/drobot/device/vestibular/phidgetvestibular.cpp \
    src/drobot/device/vestibular/phidgetvestibularfactory.cpp \
    src/drobot/device/vision/capture/capture.cpp \
    src/drobot/device/vision/capture/dc1394device.cpp \
    src/drobot/device/vision/vision.cpp \
    src/drobot/device/device.cpp \
    src/drobot/device/deviceboard.cpp \
    src/drobot/device/devicefactory.cpp \
    src/drobot/device/devicemanager.cpp \
    src/drobot/device/phidgetdevice.cpp \
    src/drobot/device/rs232.cpp \
    src/drobot/program/program.cpp \
    src/drobot/program/programfactory.cpp \
    src/drobot/program/programmanager.cpp \
    src/drobot/util/util.cpp \
    src/drobot/widget/mainwindow.cpp \
    src/drobot/main.cpp \
    src/drobot/experiment/deviceTest/program/devicetestprogram.cpp \
    src/drobot/experiment/deviceTest/program/devicetestprogramfactory.cpp \
    src/drobot/experiment/tactileTest/program/tactiletestprogram.cpp \
    src/drobot/experiment/tactileTest/program/tactiletestprogramfactory.cpp \
    src/drobot/experiment/tactileTest/widget/tactiletestmainwidget.cpp

OTHER_FILES +=

FORMS += \
    src/drobot/widget/mainwindow.ui \
    src/drobot/experiment/tactileTest/widget/tactiletestmainwidget.ui

unix|win32: LIBS += \
-lboost_filesystem \
-lboost_thread \
-lboost_system \
-lphidget21 \
-lopencv_core \
-lopencv_contrib \
-lopencv_imgproc \
-lopencv_highgui
