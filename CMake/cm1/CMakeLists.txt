# 设置CMake最低版本要求
cmake_minimum_required(VERSION 3.18)

# 定义项目名称
project(sssb)


# 添加构建目标
add_executable(CM1 main.cpp)


# 设置输出目录到上级
set_target_properties(CM1 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "../")
