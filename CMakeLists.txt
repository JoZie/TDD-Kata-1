 cmake_minimum_required(VERSION 3.0)

 set (CAMAKE_CXX_STANDARD 14)
 set (CAMAKE_CXX_STANDARD_REQUIRED ON)

 project(cmake_test)

 # Prepare "Catch" library for other executables
 set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
 add_library(Catch INTERFACE)
 target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

 # Make test executable
 set(TEST_SOURCES main.cpp
                  StringCalculator.cpp)
 add_executable(tests ${TEST_SOURCES})
 target_link_libraries(tests Catch)
