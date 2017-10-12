cmake_minimum_required (VERSION 3.0)
project (Assign4)

if (CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++11 -g0 -O3")
endif()

add_executable(assign4
	main.cpp
	utilities.cpp
	utilities.hpp
)
