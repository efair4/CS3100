cmake_minimum_required (VERSION 3.0)
project (Assign5)

if (CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "-std=c++11 -lpthread -O3 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(assign5
	main.cpp
	ComputePiDigit.hpp
  ComputePiDigit.cpp
  Queue.hpp
	Queue.cpp
	UnorderedMap.hpp
	UnorderedMap.cpp
)

