PROJECT(CollectTool)
cmake_minimum_required(VERSION 2.8)

SET(PROJECT_ROOT_PATH, "${CMAKE_SOURCE_DIR}")


#compile lib
MESSAGE("begin compile lib")           
add_subdirectory(api)



#compile bin
#add_subdirectory(app)


#compile unitTest
add_subdirectory(UnitTest)
