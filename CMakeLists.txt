cmake_minimum_required(VERSION 3.10)

project(TestReflection)

add_subdirectory(Reflection)
add_subdirectory(Engine)
add_subdirectory(Main)

target_include_directories(Engine PUBLIC Reflection)
target_include_directories(Main PUBLIC Engine)