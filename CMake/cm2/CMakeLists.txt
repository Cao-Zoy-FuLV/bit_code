# 设置CMake最低版本要求
cmake_minimum_required(VERSION 3.18)

# 定义项目名称
project(sssb VERSION 1.2.3 LANGUAGES C CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 添加构建目标
add_executable(CM1 main.cpp
        testIncuilude/t1.h)
# 设置输出目录到上级
#set_target_properties(目标名 PROPERTIES 属性名 属性值)
#set_target_properties(CM1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../")

#包含子目录cmake
include(testIncuilude/t1.cmake)

# 集成单元测试

# 启用测试
include(CTest)
# 添加测试用例
add_test(
        NAME test2
        COMMAND CM1
)

#本地二进制可执行程序到本地
include(GNUInstallDirs)#自定义安装路径 GNUInstallDirs为标准安装路径
#         安装可执行程序
install(TARGETS CM1)


#开启打包功能 & 打包二进制可执行程序

# 设置 CPack 生成器
set(CPACK_GENERATOR "ZIP;TGZ;7Z")  # Windows 下常用 ZIP 或 NSIS  Linux 下常用 TGZ TZ  跨平台: 7Z

# 包含 CPack 模块（必须放在所有 install 指令之后）
include(CPack)
# cpack 默认收集install 对应的目标，然后会把收集到的目标 打包在压缩包里

