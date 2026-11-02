cmake_minimum_required(VERSION 3.1.0)

project(main CXX)

find_package(OpenCV REQUIRED) 

add_executable(main main.cpp)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

target_include_directories(main PRIVATE ${OpenCV_INCLUDE_DIRS})

target_link_libraries(main PRIVATE ${OpenCV_LIBS})