
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#################################################
#        Checking for Linux                     #
#################################################
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
     ADD_DEFINITIONS( -DLINUX )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

SET( PROJECT_NAME VisuoMotorLearning )
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
FIND_PACKAGE( Phidget REQUIRED)


#################################################
#        INCLUDE DIRECTORIES                    #
################################################
INCLUDE_DIRECTORIES( 
	${INCLUDE_DIRECTORIES}
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/drobot/include
    ${CMAKE_SOURCE_DIR}/src/drobot/utils
    ${CMAKE_BINARY_DIR}/src/drobot/utils
    ${CMAKE_SOURCE_DIR}/src/drobot/learning
    ${CMAKE_BINARY_DIR}/src/drobot/learning
    ${CMAKE_SOURCE_DIR}/src/drobot/actuation
    ${CMAKE_SOURCE_DIR}/src/drobot/vision
)


#################################################
#        LIBS                                   #
################################################
SET( LIBS
	${LIBS}
    ${CMAKE_BINARY_DIR}/src/drobot/utils/libDRobotUtils.so
    ${CMAKE_BINARY_DIR}/src/drobot/learning/libDRobotLearning.so
    ${CMAKE_BINARY_DIR}/src/drobot/actuation/libDRobotActuation.so
    ${CMAKE_BINARY_DIR}/src/drobot/vision/libDRobotVision.so
)

MESSAGE(STATUS "Actuation INCLUDE DIRS: " ${INCLUDE_DIRECTORIES})
MESSAGE(STATUS "Actuation LIBS: " ${LIBS})


################################################
#   All component sources must be named here   #
################################################
SET( PROJECT_SRCS
  VisuoMotorLearning.cpp
)

ADD_EXECUTABLE( ${PROJECT_NAME} ${PROJECT_SRCS} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${LIBS} )



# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES COMPILER_FLAGS CXX_FLAGS )
# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX d )
# TARGET_LINK_LIBRARIES( ${COMP_NAME} ${COMP_NAME}Test )

