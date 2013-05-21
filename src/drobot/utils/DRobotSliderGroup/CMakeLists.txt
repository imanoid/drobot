

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}../
)


#ADD_DEFINITIONS(-DQT_PLUGIN)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED) 

SET(MOC_SRCS "")
SET(UI_HDRS "")


QT4_WRAP_CPP(
    MOC_SRCS 
  DRobotSlider.h
  DRobotSliderGroup.h
)

QT4_WRAP_UI(
    UI_HDRS 
#	DRobotSliderGroup.ui
)

QT4_ADD_RESOURCES(
    QT_RCCS
#   DRobotSliderGroup.qrc
)

SET(
	SRCS
	../DRobotFileSystem/DRobotFileSystem.cpp
	DRobotSlider.cpp
	DRobotSliderGroup.cpp
	DRobotSliderGroupTest.cpp
)

#ADD_LIBRARY( 
#    drobot.DRobotSliderGroup
#    SHARED
#    ${SRCS}
#    ${UI_HDRS}
#    ${MOC_SRCS}    
#    ${QT_RCCS}     
#)


MESSAGE(STATUS "SRCS: " ${SRCS})
MESSAGE(STATUS "UI: " ${UI_HDRS})
MESSAGE(STATUS "MOC: " ${MOC_SRCS})

ADD_EXECUTABLE( DRobotSliderGroupTest ${SRCS} ${UI_HDRS} ${MOC_SRCS})

TARGET_LINK_LIBRARIES(
    DRobotSliderGroupTest
    ${LIBS}
)

