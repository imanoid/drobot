

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


#ADD_DEFINITIONS(-DQT_PLUGIN)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED) 

SET(MOC_SRCS "")
SET(UI_HDRS "")

QT4_WRAP_CPP(
    MOC_SRCS 
    DRobotTimePlotter.h
)

QT4_WRAP_UI(
    UI_HDRS 
#	DRobotPlotter.ui
)

QT4_ADD_RESOURCES(
    QT_RCCS
#   DRobotPlotter.qrc
)

SET(
	SRCS
	DRobotTimePlotter.cpp
	DRobotTimePlotterTest.cpp
)

#ADD_LIBRARY( 
#    drobot.DRobotPlotter
#    SHARED
#    ${SRCS}
#    ${UI_HDRS}
#    ${MOC_SRCS}    
#    ${QT_RCCS}     
#)
      
#TARGET_LINK_LIBRARIES(
#    drobot.DRobotPlotter
#    ${LIBS}
#)


ADD_EXECUTABLE( DRobotTimePlotterTest ${SRCS} ${UI_HDRS} ${MOC_SRCS})

TARGET_LINK_LIBRARIES(
    DRobotTimePlotterTest
    ${LIBS}
)


#INSTALL(
#  TARGETS drobot.DRobotPlotter
#  LIBRARY DESTINATION ${INSTALL_PLUGIN_DIR}
#  COMPONENT plugins
#)