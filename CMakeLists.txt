CMAKE_MINIMUM_REQUIRED (VERSION 2.6) 

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

SET(CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/modules
)

PROJECT( DRobot )
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb -fpermissive")
SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")

MESSAGE(STATUS " C LINK LIB FLAGS: " ${CMAKE_C_LINK_FLAGS})
MESSAGE(STATUS " SHARED LIB FLAGS: " ${CMAKE_SHARED_LIBRARY_LINK_C_FLAGS}) 
MESSAGE(STATUS " CMAKE FLAGS: " ${CMAKE_CXX_FLAGS})

MESSAGE (STATUS " C LINK LIB FLAGS: " ${QT_LIBRARIES})

#################################################
#        GLOBAL SET COMMANDS                    #
#################################################
#IF (${CMAKE_BUILD_TYPE} STREQUAL "Release")
#    SET(CMAKE_VERBOSE_MAKEFILE OFF)
#ELSEIF (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
#   SET(CMAKE_VERBOSE_MAKEFILE ON)
#ENDIF (${CMAKE_BUILD_TYPE} STREQUAL "Release")

#SET(CMAKE_MODULE_PATH
#    ${CMAKE_SOURCE_DIR}/modules
#)


FIND_PACKAGE ( Qt4 COMPONENTS QtCore QtGui QtXml QtSvg REQUIRED  )
FIND_PACKAGE ( Qwt REQUIRED )
FIND_PACKAGE ( OpenCV REQUIRED )
FIND_PACKAGE ( Boost COMPONENTS thread system filesystem REQUIRED )
FIND_PACKAGE ( Phidget REQUIRED )
FIND_PACKAGE ( Eigen REQUIRED )

#################################################
#        INCLUDE DIRECTORIES                    #
################################################
INCLUDE_DIRECTORIES(
    ${QT_INCLUDE_DIR}
    ${QT_QTGUI_INCLUDE_DIR}
    ${QT_QTCORE_INCLUDE_DIR}
    ${QT_QTXML_INCLUDE_DIR}
	${QWT_INCLUDE_DIR}    
    ${OpenCV_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
    ${PHIDGET_INCLUDE_DIRS}
    ${EIGEN_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src

)
    

#################################################
#        LIBRARIES                              #
################################################
SET( LIBS
  ${QT_QTCORE_LIBRARY}
  ${QT_QTGUI_LIBRARY}
  ${QT_QTXML_LIBRARY}
  ${QT_QTSVG_LIBRARY}
  ${QWT_LIBRARIES}
  ${OpenCV_LIBRARIES}
  ${Boost_LIBRARIES}
  ${PHIDGET_LIBRARY}
  
)


#################################################
#        BUILD SUBDIRECTORIES                   #
#################################################

ADD_SUBDIRECTORY( src/drobot/utils )
ADD_SUBDIRECTORY( src/drobot/actuation )
ADD_SUBDIRECTORY( src/drobot/vision )
ADD_SUBDIRECTORY( src/drobot/learning )

ADD_SUBDIRECTORY( src/drobot/experiments/VisuoMotorLearning )

