file(GLOB SRC_FILES *.cpp)
include_directories(${CMAKE_SOURCE_DIR}/src)
add_executable(pharmacy ${SRC_FILES})