#UnitTest cmakeList
#author:Jerry Chau



#PROJECT("UnitTest" CXX)
cmake_minimum_required(VERSION 2.8)
SET(PROJECT_ROOT_PATH ${CMAKE_SOURCE_DIR})
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_ROOT_PATH}/Unit")
#SET(LIBRARY_OUTPUT_PATH "${PROJECT_ROOT_PATH}/lib")
SET(API_PATH_HEADER "${PROJECT_ROOT_PATH}/api/include")
LINK_DIRECTORIES("${PROJECT_ROOT_PATH}/lib")
MESSAGE("root path: ${PROJECT_ROOT_PATH}")


MESSAGE("==============UNIT TEST BEGIN INCLUDE HEADER FILES=========================")

FILE(GLOB _API_HEADER_PATH  ${API_PATH_HEADER} ${API_PATH_HEADER}/*)
FOREACH(_HEADER_DIR ${_API_HEADER_PATH})
    IF(IS_DIRECTORY ${_HEADER_DIR})
        INCLUDE_DIRECTORIES(${_HEADER_DIR})
    ENDIF()
ENDFOREACH()

MESSAGE("===================UNIT TEST END INCLUDE HEADER FILES =====================")



MESSAGE("===============UNIT TEST CONFIGER BIN FILE BEGIN===========================")
AUX_SOURCE_DIRECTORY("${PROJECT_ROOT_PATH}/UnitTest/TestCmake" T1)
MESSAGE(${T1})
ADD_EXECUTABLE(demo ${T1})

MESSAGE("===============UNIT TEST CONFIG BIN FILE END ==============================")


MESSAGE("=================UNIT TEST LINK BEGIN======================================")
TARGET_LINK_LIBRARIES(demo log)

MESSAGE("=================UNIT TEST LINK END========================================")



