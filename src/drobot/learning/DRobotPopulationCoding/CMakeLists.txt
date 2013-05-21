
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#################################################
#        Checking for Linux                     #
#################################################
IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
     ADD_DEFINITIONS( -DLINUX )
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")

SET( PROJECT_NAME DRobotPopulationCoding )
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



#################################################
#        INCLUDE DIRECTORIES                    #
################################################
INCLUDE_DIRECTORIES( 
	${INCLUDE_DIRECTORIES}
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/drobot/utils
    ${CMAKE_BINARY_DIR}/src/drobot/utils
)


#################################################
#        LIBS                                   #
################################################
SET( LIBS
	${LIBS}
    ${CMAKE_BINARY_DIR}/src/drobot/utils/libDRobotUtils.so
)


################################################
#   All component sources must be named here   #
################################################
SET( PROJECT_SRCS
  DRobotPopulationCoding.cpp
  DRobotPopulationCodingTest.cpp
)

ADD_LIBRARY( ${PROJECT_NAME} SHARED ${PROJECT_SRCS} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${LIBS} )

ADD_EXECUTABLE( ${PROJECT_NAME}Test ${PROJECT_SRCS} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME}Test ${LIBS} )


# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES COMPILER_FLAGS CXX_FLAGS )
# SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX d )
# TARGET_LINK_LIBRARIES( ${COMP_NAME} ${COMP_NAME}Test )

