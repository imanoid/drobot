
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#################################################
#        Checking for Linux                     #
#################################################
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
     ADD_DEFINITIONS( -DLINUX )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

SET( PROJECT_NAME DRobotVision )
PROJECT ( ${PROJECT_NAME} )

#################################################
#        GLOBAL SET COMMANDS                    #
#################################################
#IF (${CMAKE_BUILD_TYPE} STREQUAL "Release")
#    SET(CMAKE_VERBOSE_MAKEFILE OFF)
#ELSEIF (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
#    SET(CMAKE_VERBOSE_MAKEFILE ON)
#ENDIF (${CMAKE_BUILD_TYPE} STREQUAL "Release")

SET(CMAKE_MODULE_PATH
    ${CMAKE_SOURCE_DIR}/modules
)


#################################################
#        REQUIRED PACKAGES                      #
#################################################

#FIND_PACKAGE( OpenCV REQUIRED )
#FIND_PACKAGE( Boost COMPONENTS thread system filesystem REQUIRED)


#################################################
#        INCLUDE DIRECTORIES                    #
################################################
INCLUDE_DIRECTORIES( 
	${INCLUDE_DIRECTORIES}
#    ${OpenCV_INCLUDE_DIRS}
#    ${Boost_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/drobot/utils
    ${CMAKE_BINARY_DIR}/src/drobot/utils
#    ${MVBLUEFOX_INCLUDE_DIR}
#    ${CMAKE_SOURCE_DIR}/src/roboy/datastructures
#    ${CMAKE_SOURCE_DIR}/src/roboy/utils
)


#################################################
#        LIBS                                   #
################################################
SET( LIBS
	${LIBS}
    ${CMAKE_BINARY_DIR}/src/drobot/utils/libDRobotUtils.so
)

MESSAGE(STATUS "VISION INCLUDE DIRS: " ${INCLUDE_DIRECTORIES})
MESSAGE(STATUS "VISION LIBS: " ${LIBS})


################################################
#   All component sources must be named here   #
################################################
SET( PROJECT_SRCS
  capture/DRobotCapture.cpp
  capture/DRobotDC1394Device.cpp
  DRobotVision.cpp
  DRobotVisionTest.cpp
)

ADD_LIBRARY( ${PROJECT_NAME} SHARED ${PROJECT_SRCS} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${LIBS} )

ADD_EXECUTABLE( ${PROJECT_NAME}Test ${PROJECT_SRCS} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME}Test ${LIBS} )


# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES COMPILER_FLAGS CXX_FLAGS )
# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX d )
# TARGET_LINK_LIBRARIES( ${COMP_NAME} ${COMP_NAME}Test )

