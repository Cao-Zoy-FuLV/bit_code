# CMake

## 1：安装

### 1.1：下载

[CMake 官方源代码下载地址：https://cmake.org/download/](https://cmake.org/download/)
<br> [CMake 官方英文 档地址：https://cmake.org/cmake/help/latest/index.html](https://cmake.org/cmake/help/latest/index.html)

### 1.2：便携版  没环境

win添加环境变量： cnm执行 set(CMAKE_PROGRAM_PATH "地址")

```shell
$env:Path += ";F:\CLion-2025.3.2.win\bin\cmake\win\x64\bin"
#F:/CLion-2025.3.2.win/bin/cmake/win/x64/bin
#C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin

````

[linux添加环境变量：https://www.cnblogs.com/yubo-guan/p/19163979#tid-6XRC3j](https://www.cnblogs.com/yubo-guan/p/19163979#tid-6XRC3j)

## 2：验证安装：

安装完成后，可通过以下命令验证 CMake 是否安装成功以及查看其版本。

##### 查看CMake版本

``` shell
cmake --version
```

```
cmake version 3.28.3
CMake suite maintained and supported by Kitware (kitware.com/cmake).
```

## 3：Cmake基础框架

#### CMakeLists.txt ↓

```cmake
# 1 设置能运行此工程的cmake的最低版本
cmake_minimum_required(VERSION 3.18)
# 2 设置项目名称
project(project)
# 3 添加构建目标
add_executable(main main.cpp)
```

CMake 给我们提供了cmake_minimum_required ，这个命令会在配置阶段（ cmake 命令执行
时）检查当前 CMake 版本

在 CMake 中，“目标（Target）” 代表了一个需要被生成的实体，如可执行文件、静态库/动态
库等，和Makefile里的目标是一个意思

## 4：运行cmake

### 生成构建系统

在源代码树包含的顶级CMakeLists.txt的目录—>源代码根目录 进行直接构建
运行成功后，会生成一个Makefile 文件，这个文件就是我们接下来要生成的可执行文件

```shell
cmake ..
```

**官方推荐**  源外构建 Makefile ——在build文件夹(包含CMakeCache.txt—>构建目录的根目录)
运行成功后，会生成一个Makefile 文件，这个文件就是我们接下来要生成的可执行文件

<br>指定源文件根目录，必须包含一个CMakeLists.txt文件
<br>-S 源码目录
<br>指定构建目录，构建生成的中间文件和目标文件的生成路径
<br>-B 构建目录

```shell
cmake  -S . -B build 
 ```

### 清理编译生成的文件

```shell
cmake --build build\ -t clean
 ```

### 编译&&链接

```shell
cmake --build  build\
#linux make
 ```

```shelll
#linux ./main
Debug\main.exe

```

### ctest 测试

-C <配置类型>—指定配置类型(Debug/Release)
<br>--test-dir <构建目录路径>

```shell
#linux make test
ctest --test-dir build   -C Debug
```

### 安装

Windows 下指定 Debug 配置 -v 显示详细信息 --prefix 指定安装目录

```shell
cmake --install build --config Debug   -v --prefix  .
```

### 打包

执行步骤

1. 设置临时安装目录
2. 执行cmake_install.cmake
3. 收集临时安装目录下的文件
4. 执行打包，拷贝压缩包到构建目录下

<br>-G <生成器> - 指定打包格式（ZIP, 7Z, TGZ, NSIS, DEB, RPM 等）
<br>-C <配置> - 指定构建配置（Debug/Release）
<br>-B <目录> - 指定输出目录
<br>-V - 详细输出

```shell
cpack  -C Debug -B ../Debug/cpack
#linux make package
```

### 脚本模式

脚本模式：cmake -P <脚本文件>
不会生成构建产物，也不会生成中间过程。

```shell
cmake -P 
```

### 常用命令

调用外部命令

    cmake -E <命令> <参数>

查看帮助

```shell 
cmake --help
```

## 5：常用的cmake

### [cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html)

顶层的CMakeLists.txt 文件中，用于指定 CMake 的最低版本要求。必须在project()之前调用。不推荐在函数中调用。

    cmake_minimum_required(VERSION 3.18)
    cmake_minimum_required(VERSION <min>[...<policy_max>] [FATAL_ERROR])

VERSION 关键字，表示后面跟的是版本号
<br>min表示最低版本号
<br>policy_max表示最高版本号
<br>不同 Linux 发行版（如 Ubuntu(3.22+)、CentOS(3.22+)、Fedora(3.28+) 等）的软件仓库中大部分都高与3.18

### [project](https://cmake.org/cmake/help/latest/command/project.html)

指定项目名字

      project(<PROJECT-NAME>）

完整形式

    project(<PROJECT-NAME>
            VERSION 项目版本号（如 1.0.0），
            LANGUAGES <语言>（如 C、CXX、Fortran、ASM 等）
            DESCRIPTION（可选） 项目描述信息（用于生成文档或包配置）。
            HOMEPAGE_URL（可选） 项目主页地址。
        )

### [ include](https://cmake.org/cmake/help/latest/command/include.html)

加载指定的脚本文件或者模块到当前CMakeLists执行上下文中并运行。

    include(<file|module>[OPTIONAL] [RESULT_VARIABLE <var>] [NO_POLICY_SCOPE])

打印当前正在执行的cmake 脚本的 全目录

    message(STATUS "CMAKE_CURRENT_LIST_DIR:" ${CMAKE_CURRENT_LIST_DIR})






















