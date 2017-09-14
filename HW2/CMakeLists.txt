cmake_minimum_required (VERSION 3.6.2)
project (HW2)

if (CMAKE_COMPILER_IS_GNUCXX)
	set(CMAKE_CXX_FLAGS "-std=c++11 -g0 -O3 -Wall -Wextra")
endif()

add_executable(HW2
	main.cpp
	compute-fib.hpp
	compute-fib.cpp
	compute-e.hpp
        compute-e.cpp
	compute-pi.hpp
        compute-pi.cpp
)

