#complie api
#author: Jerry Chau






cmake_minimum_required(VERSION 2.8)
SET(PROJECT_ROOT_PATH ${CMAKE_SOURCE_DIR})
SET(LIBRARY_OUTPUT_PATH "${PROJECT_ROOT_PATH}/lib" )
#include header file


SET(API_PATH "${PROJECT_ROOT_PATH}/api")
SET(API_INCLUDE_DIR "${PROJECT_ROOT_PATH}/api/include")

MESSAGE("================CONFIG API INCLUDE DIRECOTRY BEGIN==============")
MESSAGE("api include directory is ${API_INCLUDE_DIR}")
FILE(GLOB _ALL_FILES ${API_INCLUDE_DIR} ${API_INCLUDE_DIR}/*)
FOREACH(_FILE ${_ALL_FILES})
    IF(IS_DIRECTORY ${_FILE})
        #MESSAGE(${_FILE})
        INCLUDE_DIRECTORIES(${_FILE})
    ENDIF()
ENDFOREACH()


MESSAGE("===============CONGIG API INCLUDE DIRECOTRY END ================")



#MESSAGE("begin match lib cpp")
#FILE(GLOB _LIB_CPP_DIRS  RELATIVE ${API_PATH} ${API_PATH}/*)
#LIST(REMOVE_ITEM _LIB_CPP_DIRS ${API_PATH}/include/*)
#FOREACH(_DIR ${_LIB_CPP_DIRS})
#    IF(IS_DIRECTORY ${_DIR} AND NOT ("${API_PATH}/include" STREQUAL ${_DIR} OR ${API_PATH} STREQUAL ${_DIR}))
#        MESSAGE("will generate lib ${_DIR}")
#        AUX_SOURCE_DIRECTORY(${_DIR} ${_DIR}_SOURCE_LIST)
#        STRING(REGEX MATCH "^\(.*/\)?\([^/]*\)" SET(_LIB_NAME "\\2") ${_DIR})
#        MESSAGE("lib name : ${_LIB_NAME}")
#        #ADD_LIBRARY(lib  SHARED ${${_DIR}_SOURCE_LIST})
#    ENDIF()
#ENDFOREACH()
#MESSAGE("end match lib cpp")


MESSAGE("====================BENGIN MATCH LIB==============================")
FILE(GLOB _LIB_CPP_DIRS RELATIVE ${API_PATH} ${API_PATH}/*)
FOREACH(_DIR ${_LIB_CPP_DIRS})
    IF(IS_DIRECTORY ${API_PATH}/${_DIR} AND NOT ("include" STREQUAL ${_DIR}))
        MESSAGE("Will generate lib ${_DIR}") 
        AUX_SOURCE_DIRECTORY(${API_PATH}/${_DIR} ${_DIR}_SOURCE_LIST)
        MESSAGE("lib use: ${${_DIR}_SOURCE_LIST}")
        ADD_LIBRARY(${_DIR} SHARED  ${${_DIR}_SOURCE_LIST})
    ENDIF()
ENDFOREACH()
MESSAGE("====================END MATCH LIB==================================")






