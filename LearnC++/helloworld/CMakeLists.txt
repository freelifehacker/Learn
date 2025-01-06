cmake_minimum_required(VERSION 3.13)
project(cpp_learning)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 为 Apple Silicon (arm64) 设置特定编译选项
if(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -arch arm64")
endif()

# 添加可执行文件
add_executable(main src/main.cpp) 