cmake_minimum_required(VERSION 3.2)
project(asm_parser)

add_executable(parser source/main.cpp)

if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	target_compile_options(parser PRIVATE /W4)
else()
	target_compile_options(parser PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
