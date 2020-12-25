cmake_minimum_required(VERSION 3.10)

set(MODULE Main)

file(GLOB header_files *.h)
source_group("Header Files" FILES ${header_files})

file(GLOB cpp_files *.cpp)
add_executable(${MODULE} ${cpp_files} ${header_files})


list(APPEND EXTRA_LIBS Reflection Engine)
target_link_libraries(${MODULE} PUBLIC ${EXTRA_LIBS})

target_include_directories(${MODULE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set(REGISTER_PY_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/../Reflection/CollectMetaFunc.py)

add_custom_command(
    TARGET ${MODULE} PRE_BUILD 
    COMMAND python "${REGISTER_PY_SCRIPT}" "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/MainRegisterFunc.cpp"
    )
