cmake_minimum_required(VERSION 3.9)

project(cpp-linkedlist-benchmarks)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
#set(BENCHMARK_ENABLE_LTO True)
#set(GOOGLETEST_PATH googletest)

add_executable(bench benchmark.cpp)

add_subdirectory(depend/benchmark)

target_link_libraries(bench benchmark)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic" )

include(CheckIPOSupported)
check_ipo_supported(RESULT result OUTPUT output)
if(result)
  message(STATUS "Enabled IPO/LTO")
  set_property(TARGET bench PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
  message(WARNING "IPO/LTO is not supported: ${output}")
endif()


