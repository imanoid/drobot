

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
    DRobotColorRangeSelector.h
)

QT4_WRAP_UI(
    UI_HDRS 
	DRobotColorRangeSelector.ui
)

QT4_ADD_RESOURCES(
    QT_RCCS
#   DRobotImageDisplay.qrc
)

SET(
	SRCS
	DRobotColorRangeSelector.cpp
	DRobotColorRangeSelectorTest.cpp
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

ADD_EXECUTABLE( DRobotColorRangeSelectorTest ${SRCS} ${UI_HDRS} ${MOC_SRCS})

TARGET_LINK_LIBRARIES(
    DRobotColorRangeSelectorTest
    ${LIBS}
)

