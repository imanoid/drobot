

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


#ADD_DEFINITIONS(-DQT_PLUGIN)
#ADD_DEFINITIONS(-DQT_NO_DEBUG)
ADD_DEFINITIONS(-DQT_SHARED)

QT4_WRAP_CPP(
	MOC_SRCS
	DRobotColorRangeSelector/DRobotColorRangeSelector.h
	DRobotImageDisplay/DRobotImageDisplay.h
	DRobotSliderGroup/DRobotSlider.h
	DRobotSliderGroup/DRobotSliderGroup.h
	DRobotTimePlotter/DRobotTimePlotter.h
)

QT4_WRAP_UI(
    UI_HDRS 
    DRobotColorRangeSelector/DRobotColorRangeSelector.ui
#	DRobotPlotter.ui
)

QT4_ADD_RESOURCES(
    QT_RCCS
#   DRobotPlotter.qrc
)

SET(
	SRCS
	DRobotFileSystem/DRobotFileSystem.cpp
	DRobotDataLogger/DRobotDataLogger.cpp
	DRobotTimePlotter/DRobotTimePlotter.cpp
	DRobotImageDisplay/DRobotImageDisplay.cpp
	DRobotColorRangeSelector/DRobotColorRangeSelector.cpp
	DRobotSliderGroup/DRobotSlider.cpp
	DRobotSliderGroup/DRobotSliderGroup.cpp

	rs232/rs232.cpp
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


ADD_LIBRARY( DRobotUtils SHARED ${SRCS} ${UI_HDRS} ${MOC_SRCS})

TARGET_LINK_LIBRARIES(
    DRobotUtils
    ${LIBS}
)

ADD_SUBDIRECTORY( DRobotFileSystem )
ADD_SUBDIRECTORY( DRobotDataLogger )
ADD_SUBDIRECTORY( DRobotTimePlotter )
ADD_SUBDIRECTORY( DRobotImageDisplay )
ADD_SUBDIRECTORY( DRobotColorRangeSelector )
ADD_SUBDIRECTORY( DRobotSliderGroup )
ADD_SUBDIRECTORY( rs232 )

#INSTALL(
#  TARGETS drobot.DRobotPlotter
#  LIBRARY DESTINATION ${INSTALL_PLUGIN_DIR}
#  COMPONENT plugins
#)
