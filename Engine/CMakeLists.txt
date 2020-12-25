cmake_minimum_required(VERSION 3.10)

file(GLOB header_files *.h)
source_group("Header Files" FILES ${header_files})
file(GLOB cpp_files *.cpp)

add_library(Engine ${cpp_files} ${header_files})
find_library(vulkanLib vulkan-1.lib ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/vulkan)
find_library(pythonLib python39_d.lib ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/python)
target_link_libraries(Engine Reflection ${vulkanLib} ${pythonLib})

set(REGISTER_PY_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/../Reflection/CollectMetaFunc.py)
set(REGISTER_FILE RegisterFunc.cpp)
add_custom_command(TARGET Engine PRE_BUILD COMMAND python "${REGISTER_PY_SCRIPT}" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/Engine${REGISTER_FILE}")


