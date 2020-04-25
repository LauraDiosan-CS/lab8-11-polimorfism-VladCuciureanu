cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(pharmacy VERSION 0.0.1 LANGUAGES CXX)

include(GNUInstallDirs)

add_executable(run_tests)

file(GLOB src_files
  "${CMAKE_SOURCE_DIR}/src/Domain/*.cpp"
  "${CMAKE_SOURCE_DIR}/src/Repository/*.cpp"
)

target_sources(run_tests
  PRIVATE
  Tests.cpp
  ${src_files}
  )

  target_include_directories(run_tests
  PRIVATE
  "${CMAKE_SOURCE_DIR}/include/pharmacy/Domain"
  "${CMAKE_SOURCE_DIR}/include/pharmacy/Repository"
  )

target_compile_features(run_tests
  PUBLIC   cxx_std_17)
