

INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)


SET(
	SRCS
	DRobotFileSystem.cpp
	DRobotFileSystemTest.cpp
)



ADD_EXECUTABLE( DRobotFileSystemTest ${SRCS} )

TARGET_LINK_LIBRARIES(
    DRobotFileSystemTest
    ${LIBS}
)

