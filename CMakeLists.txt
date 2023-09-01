cmake_minimum_required(VERSION 3.10)
project(AlgorytmStrassena VERSION 0.1.0 LANGUAGES CXX)

find_package(Boost 1.83)
include_directories(${Boost_INCLUDE_DIR})

add_library(randomInputData src/randomInputData.cpp)
target_link_directories(randomInputData PUBLIC inc/)
target_link_libraries(randomInputData LINK_PUBLIC ${Boost_LIBRARIES})

add_library(maxSubarrayClass src/maxSubarray.cpp)
target_link_directories(maxSubarrayClass PUBLIC inc/)
target_link_libraries(maxSubarrayClass LINK_PUBLIC randomInputData)

add_library(arrayClass src/arrayClass.cpp)
target_link_directories(arrayClass PUBLIC inc/)

add_executable(strassen src/main.cpp)
target_link_directories(strassen PUBLIC inc/)
target_link_libraries(strassen LINK_PUBLIC maxSubarrayClass arrayClass)