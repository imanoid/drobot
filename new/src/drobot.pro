QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += qwt

TARGET = drobot
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    drobot/device/actuator/actuator.h \
    drobot/device/actuator/actuatorboard.h \
    drobot/device/actuator/phidgetadvancedboard.h \
    drobot/device/actuator/phidgetadvancedservo.h \
    drobot/device/actuator/phidgetsimpleboard.h \
    drobot/device/actuator/phidgetsimpleservo.h \
    drobot/device/tactile/simpletactilesensor.h \
    drobot/device/tactile/simpletactilesensorboard.h \
    drobot/device/tactile/tactilesensor.h \
    drobot/device/tactile/tactilesensorboard.h \
    drobot/device/vestibular/phidgetvestibular.h \
    drobot/device/vestibular/phidgetvestibularfactory.h \
    drobot/device/vestibular/vestibular.h \
    drobot/device/vision/vision.h \
    drobot/device/device.h \
    drobot/device/deviceboard.h \
    drobot/device/devicemanager.h \
    drobot/device/driver/rs232.h \
    drobot/program/program.h \
    drobot/program/programfactory.h \
    drobot/program/programmanager.h \
    drobot/util/util.h \
    drobot/widget/mainwindow.h \
    drobot/experiment/tactileTest/program/tactiletestprogram.h \
    drobot/experiment/tactileTest/program/tactiletestprogramfactory.h \
    drobot/experiment/tactileTest/widget/tactiletestmainwidget.h \
    drobot/event/event.h \
    drobot/event/eventmanager.h \
    drobot/event/eventlistener.h \
    drobot/device/channel/channel.h \
    drobot/device/channel/normalizer.h \
    drobot/device/channel/linearnormalizer.h \
    drobot/device/actuator/channel/actuatorpositionchannel.h \
    drobot/device/actuator/channel/actuatorvelocitychannel.h \
    drobot/device/tactile/channel/tactilesensorvaluechannel.h \
    drobot/device/vestibular/channel/vestibularaccelerationchannel.h \
    drobot/device/vestibular/channel/vestibularangularratechannel.h \
    drobot/robot/robot.h \
    drobot/robot/controller.h \
    drobot/program/runnable.h \
    drobot/device/channel/channelmanager.h \
    drobot/experiment/tactileTest/robot/stupidcontroller.h \
    drobot/datalogger/datalogger.h \
    drobot/datalogger/simpledatalogger.h \
    drobot/datalogger/simpledatalogentry.h \
    drobot/object/item.h \
    drobot/object/manager.h \
    drobot/device/channel/channeltype.h \
    drobot/util/clock.h \
    drobot/device/actuator/phidgetadvancedservofactory.h \
    drobot/device/actuator/phidgetsimpleservofactory.h \
    drobot/device/devicefactory.h \
    drobot/device/tactile/simpletactilesensorfactory.h \
    drobot/device/channel/channelfactory.h \
    drobot/device/actuator/channel/actuatorpositionchannelfactory.h \
    drobot/device/tactile/channel/tactilesensorvaluechannelfactory.h \
    drobot/device/vision/pixel.h \
    drobot/util/exception.h \
    drobot/device/vestibular/channel/vestibularaccelerationchannelfactory.h \
    drobot/device/vestibular/channel/vestibularangularratechannelfactory.h \
    drobot/device/actuator/channel/actuatoraccelerationchannel.h \
    drobot/device/actuator/channel/actuatoraccelerationchannelfactory.h \
    drobot/device/actuator/channel/actuatorvelocitychannelfactory.h \
    drobot/device/deviceConstants.h \
    drobot/device/vestibular/channel/vestibularmagneticfieldchannel.h \
    drobot/device/vestibular/channel/vestibularmagneticfieldchannelfactory.h \
    drobot/experiment/tactileTest/robot/stupidcontrollerfactory.h \
    drobot/widget/plot/curveplotter.h \
    drobot/experiment/demo/program/demoprogram.h \
    drobot/experiment/demo/program/demoprogramfactory.h \
    drobot/experiment/demo/robot/democontroller.h \
    drobot/experiment/demo/robot/democontrollerfactory.h \
    drobot/experiment/demo/widget/demowidget.h \
    drobot/robot/event/tickevent.h \
    drobot/experiment/handmouth/program/handmouthprogramfactory.h \
    drobot/experiment/handmouth/program/handmouthprogram.h \
    drobot/experiment/handmouth/robot/handmouthcontrollerfactory.h \
    drobot/experiment/handmouth/robot/handmouthcontroller.h \
    drobot/widget/slider/slidergroup.h \
    drobot/widget/slider/slider.h \
    drobot/experiment/handmouth/widget/handmouthwidget.h

SOURCES += \
    drobot/device/actuator/actuatorboard.cpp \
    drobot/device/actuator/phidgetadvancedboard.cpp \
    drobot/device/actuator/phidgetadvancedservo.cpp \
    drobot/device/actuator/phidgetsimpleboard.cpp \
    drobot/device/actuator/phidgetsimpleservo.cpp \
    drobot/device/tactile/simpletactilesensor.cpp \
    drobot/device/tactile/simpletactilesensorboard.cpp \
    drobot/device/tactile/tactilesensorboard.cpp \
    drobot/device/vestibular/phidgetvestibular.cpp \
    drobot/device/vestibular/phidgetvestibularfactory.cpp \
    drobot/device/device.cpp \
    drobot/device/deviceboard.cpp \
    drobot/device/devicemanager.cpp \
    drobot/device/driver/rs232.cpp \
    drobot/program/program.cpp \
    drobot/program/programfactory.cpp \
    drobot/program/programmanager.cpp \
    drobot/widget/mainwindow.cpp \
    drobot/main.cpp \
    drobot/experiment/tactileTest/program/tactiletestprogram.cpp \
    drobot/experiment/tactileTest/program/tactiletestprogramfactory.cpp \
    drobot/experiment/tactileTest/widget/tactiletestmainwidget.cpp \
    drobot/event/event.cpp \
    drobot/event/eventmanager.cpp \
    drobot/event/eventlistener.cpp \
    drobot/device/channel/channel.cpp \
    drobot/device/channel/linearnormalizer.cpp \
    drobot/device/actuator/channel/actuatorpositionchannel.cpp \
    drobot/device/actuator/channel/actuatorvelocitychannel.cpp \
    drobot/device/tactile/channel/tactilesensorvaluechannel.cpp \
    drobot/device/vestibular/channel/vestibularaccelerationchannel.cpp \
    drobot/device/vestibular/channel/vestibularangularratechannel.cpp \
    drobot/device/actuator/actuator.cpp \
    drobot/robot/robot.cpp \
    drobot/robot/controller.cpp \
    drobot/program/runnable.cpp \
    drobot/device/channel/channelmanager.cpp \
    drobot/device/tactile/tactilesensor.cpp \
    drobot/device/vestibular/vestibular.cpp \
    drobot/experiment/tactileTest/robot/stupidcontroller.cpp \
    drobot/datalogger/simpledatalogger.cpp \
    drobot/object/item.cpp \
    drobot/util/clock.cpp \
    drobot/device/actuator/phidgetadvancedservofactory.cpp \
    drobot/device/actuator/phidgetsimpleservofactory.cpp \
    drobot/device/devicefactory.cpp \
    drobot/device/tactile/simpletactilesensorfactory.cpp \
    drobot/device/channel/channelfactory.cpp \
    drobot/device/actuator/channel/actuatorpositionchannelfactory.cpp \
    drobot/device/channel/channeltype.cpp \
    drobot/device/tactile/channel/tactilesensorvaluechannelfactory.cpp \
    drobot/util/exception.cpp \
    drobot/device/vestibular/channel/vestibularaccelerationchannelfactory.cpp \
    drobot/device/vestibular/channel/vestibularangularratechannelfactory.cpp \
    drobot/device/actuator/channel/actuatoraccelerationchannel.cpp \
    drobot/device/actuator/channel/actuatoraccelerationchannelfactory.cpp \
    drobot/device/actuator/channel/actuatorvelocitychannelfactory.cpp \
    drobot/device/vestibular/channel/vestibularmagneticfieldchannel.cpp \
    drobot/device/vestibular/channel/vestibularmagneticfieldchannelfactory.cpp \
    drobot/experiment/tactileTest/robot/stupidcontrollerfactory.cpp \
    drobot/widget/plot/curveplotter.cpp \
    drobot/datalogger/datalogger.cpp \
    drobot/experiment/demo/program/demoprogram.cpp \
    drobot/experiment/demo/program/demoprogramfactory.cpp \
    drobot/experiment/demo/robot/democontroller.cpp \
    drobot/experiment/demo/robot/democontrollerfactory.cpp \
    drobot/experiment/demo/widget/demowidget.cpp \
    drobot/robot/event/tickevent.cpp \
    drobot/experiment/handmouth/program/handmouthprogramfactory.cpp \
    drobot/experiment/handmouth/program/handmouthprogram.cpp \
    drobot/experiment/handmouth/robot/handmouthcontrollerfactory.cpp \
    drobot/experiment/handmouth/robot/handmouthcontroller.cpp \
    drobot/widget/slider/slidergroup.cpp \
    drobot/widget/slider/slider.cpp \
    drobot/experiment/handmouth/widget/handmouthwidget.cpp

OTHER_FILES +=

FORMS += \
    drobot/widget/mainwindow.ui \
    drobot/experiment/tactileTest/widget/tactiletestmainwidget.ui \
    drobot/experiment/demo/widget/demowidget.ui \
    drobot/experiment/handmouth/widget/handmouthwidget.ui

unix|win32: LIBS += \
-lboost_filesystem \
-lboost_thread \
-lboost_system \
-lphidget21 \
-lopencv_core \
-lopencv_contrib \
-lopencv_imgproc \
-lopencv_highgui
