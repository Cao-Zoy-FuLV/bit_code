# 设置CMake最低版本要求
cmake_minimum_required(VERSION 3.18)

# 定义项目名称
project(sssb)


# 添加构建目标
add_executable(CM1 main.cpp)
# 设置输出目录到上级
#set_target_properties(目标名 PROPERTIES 属性名 属性值)
set_target_properties(CM1 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "../")

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
include(CPack)
# cpack 默认收集install 对应的目标，然后会把收集到的目标 打包在压缩包里