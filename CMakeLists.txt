cmake_minimum_required(VERSION 3.10)

project(TestReflection)

file(GLOB header_files *.h)
source_group("Header Files" FILES ${header_files})
file(GLOB cpp_files *.cpp)

add_executable(TestReflection ${cpp_files} ${header_files})
#add_custom_command(TARGET TestReflection PRE_BUILD

#command C:/python "${CMAKE_CURRENT_SOURCE_DIR}/CollectMetaFunc.py" "${CMAKE_CURRENT_SOURCE_DIR}/RegisterFunc.cpp"
#python ../CollectMetaFunc.py ../RegisterFunc.cpp
#)