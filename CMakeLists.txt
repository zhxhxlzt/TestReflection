cmake_minimum_required(VERSION 3.10)

project(TestReflection)

add_subdirectory(Reflection)
add_subdirectory(Engine)
add_subdirectory(Main)

target_include_directories(Engine PUBLIC Reflection ThirdParty/vulkan ThirdParty/python/Include)
target_include_directories(Main PUBLIC Engine)

set(Dll_Path ${CMAKE_SOURCE_DIR}/ThirdParty/python)
set(PATH_ENV "PATH=${Dll_Path};%PATH%")
set_property(TARGET Main PROPERTY VS_DEBUGGER_ENVIRONMENT "${PATH_ENV}")