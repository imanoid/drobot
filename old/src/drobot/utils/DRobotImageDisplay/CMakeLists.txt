

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIRS}
)

#ADD_DEFINITIONS(-DQT_PLUGIN)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED) 

SET(MOC_SRCS "")
SET(UI_HDRS "")


QT4_WRAP_CPP(
    MOC_SRCS 
    DRobotImageDisplay.h
)

QT4_WRAP_UI(
    UI_HDRS 
#	DRobotImageDisplay.ui
)

QT4_ADD_RESOURCES(
    QT_RCCS
#   DRobotImageDisplay.qrc
)

SET(
	SRCS
	DRobotImageDisplay.cpp
	DRobotImageDisplayTest.cpp
)

#ADD_LIBRARY( 
#    drobot.DRobotImageDisplay
#    SHARED
#    ${SRCS}
#    ${UI_HDRS}
#    ${MOC_SRCS}    
#    ${QT_RCCS}     
#)


MESSAGE(STATUS "SRCS: " ${SRCS})
MESSAGE(STATUS "UI: " ${UI_HDRS})
MESSAGE(STATUS "MOC: " ${MOC_SRCS})

ADD_EXECUTABLE( DRobotImageDisplayTest ${SRCS} ${UI_HDRS} ${MOC_SRCS})

TARGET_LINK_LIBRARIES(
    DRobotImageDisplayTest
    ${LIBS}
)

