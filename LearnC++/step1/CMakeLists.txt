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
add_executable(basic_demo src/basic_demo.cpp)
add_executable(advanced_basic_demo src/advanced_basic_demo.cpp)
add_executable(old_ptr src/old_ptr.cpp)
add_executable(smart_ptr src/smart_ptr.cpp) 