cmake_minimum_required(VERSION 3.17)
project(cpp_learning_notes)

set(CMAKE_CXX_STANDARD 14)

set(INC_DIR /usr/local/include)
set(LINK_DIR /usr/local/lib)

include_directories(${INC_DIR})
link_directories(${LINK_DIR})
link_libraries(jsoncpp)

add_executable(cpp_learning_notes main.cpp)

target_link_libraries(cpp_learning_notes jsoncpp)
