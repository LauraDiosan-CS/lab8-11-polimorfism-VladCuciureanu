cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(pharmacy VERSION 0.0.1 LANGUAGES CXX)

include(GNUInstallDirs)

add_executable(pharmacy)

file(GLOB src_files
  "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

target_sources(pharmacy
  PRIVATE
  ${src_files}
  )

target_include_directories(pharmacy PRIVATE "${CMAKE_SOURCE_DIR}/include/pharmacy")

target_compile_features(pharmacy
  PUBLIC   cxx_std_17)
