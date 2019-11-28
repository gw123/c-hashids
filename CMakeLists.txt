project(hashids_test)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(RPOJECT_NAME hashids_test)

MESSAGE(STATUS "Now is UNIX-like OS's.")
SET(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/dist)
LINK_DIRECTORIES(/usr/local/lib)


SET(./src/demo.c)
#aux_source_directory(./src/test Test_LibUsb_Source)
ADD_EXECUTABLE(hashids_demo ${hashids_demo})
target_link_libraries(hashids_demo libhashids.so)

install(TARGETS hashids_demo RUNTIME DESTINATION bin)