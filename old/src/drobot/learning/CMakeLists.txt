

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


#ADD_DEFINITIONS(-DQT_PLUGIN)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)
#ADD_DEFINITIONS(-DQT_SHARED) 

#QT4_WRAP_CPP(
#    MOC_SRCS 
#    DRobotTimePlotter/DRobotTimePlotter.h
#    DRobotImageDisplay/DRobotImageDisplay.h
#)

#QT4_WRAP_UI(
#    UI_HDRS 
#	DRobotPlotter.ui
#)

#QT4_ADD_RESOURCES(
#    QT_RCCS
#   DRobotPlotter.qrc
#)

SET(
	SRCS
	DRobotPopulationCoding/DRobotPopulationCoding.cpp
	DRobotPerceptron/DRobotPerceptron.cpp
)

      
ADD_LIBRARY( DRobotLearning SHARED ${SRCS} ${UI_HDRS} ${MOC_SRCS})

TARGET_LINK_LIBRARIES( DRobotLearning ${LIBS} )

ADD_SUBDIRECTORY( DRobotPopulationCoding )
ADD_SUBDIRECTORY( DRobotPerceptron )

