
FIND_PATH(
	PHIDGET_INCLUDE_DIR
  phidget21.h
	/usr/include
  /usr/include/phidgets
)

FIND_LIBRARY(
  PHIDGET_LIBRARY
  NAMES phidget21
  PATHS
  /usr/lib
  /usr/local/lib
)
    

MESSAGE (STATUS "PHIDGETS INCLUDE DIR  " ${PHIDGET_INCLUDE_DIR})
MESSAGE (STATUS "PHIDGETS LIBRARY  " ${PHIDGET_LIBRARY})


IF (PHIDGET_INCLUDE_DIR AND PHIDGET_LIBRARY )
    SET(PHIDGET_FOUND TRUE)
    MESSAGE (STATUS "PHIDGET project found " ${PHIDGET_LIBRARIES})
ELSE ( PHIDGET_INCLUDE_DIR AND PHIDGET_LIBRARY )
    SET(PHIDGET_FOUND FALSE)
    IF(PHIDGET_FIND_REQUIRED)
        MESSAGE( FATAL_ERROR "PHIDGET project was not found!")
    ELSE (PHIDGET_FIND_REQUIRED)
        IF(NOT PHIDGET_FIND_QUIETLY)
            MESSAGE( STATUS "PHIDGET project was not found!")
        ENDIF(NOT PHIDGET_FIND_QUIETLY)
    ENDIF(PHIDGET_FIND_REQUIRED)
ENDIF ( PHIDGET_INCLUDE_DIR AND PHIDGET_LIBRARY )

MARK_AS_ADVANCED(
	PHIDGET_FOUND
	PHIDGET_INCLUDE_DIR
	PHIDGET_LIBRARY
) 

