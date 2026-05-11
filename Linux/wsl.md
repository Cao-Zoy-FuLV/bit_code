# Windows 子系统  WSL (Windows Subsystem for Linux) 学习指南

## 目录

- [常用命令](#命令)
- [WSL2 备份与还原](#wsl2-备份与还原)
- [重装系统后恢复 WSL2](#重装系统后恢复-wsl2)
- [Docker Desktop 配置](#docker-desktop-配置)

---

## 命令

### 1. 查看当前 WSL 版本

```bash
wsl -l
```

### 2. 查看 WSL 详细信息

```bash
wsl --version
```

输出示例：

```
WSL 版本: 2.6.3.0
内核版本: 6.6.87.2-1
WSLg 版本: 1.0.71
MSRDC 版本: 1.2.6353
Direct3D 版本: 1.611.1-81528511
DXCore 版本: 10.0.26100.1-240331-1435.ge-release
Windows: 10.0.19045.6466
```

### 3. 查看运行中的子系统

```bash
wsl -l --running
```

### 4. 查看所有子系统及其状态

```bash
wsl -l -v
```

### 5. 运行子系统

#### 查看微软官方支持的所有可在线安装的Linux发行版

```bash

#wsl --list --online
# 简写版
wsl -l -o
```

#### 安装指定Linux发行版

```bash
#wsl --install -d <发行版名称> 
#默认安装Ubuntu发行版
wsl --install 
```

```powershell

wsl --distribution  <分发版名称>
# 或简写为
wsl -d <分发版名称>
```

### 6. 停止子系统

```
# 停止特定的子系统
wsl --terminate <分发版名称>
# 或简写为
wsl -t <分发版名称>
```

```bash
# 停止所有运行的子系统 docker 也会停止
wsl --shutdown
```

### 7. 启动默认子系统

```bash
wsl
```

```powershell
# 启动WSL并直接进入指定目录，支持Windows路径和Linux路径
wsl --cd /home
wsl --cd D:\code
# 设置默认发行版，后续直接执行wsl命令默认进入该系统
wsl --set-default <分发版名称>
# 【高危操作】注销并删除指定发行版，该系统内所有数据会被彻底删除且无法恢复！
wsl --unregister <发行版名称>
```

### 8. 其他指令

#### 更新WSL内核版本，遇到兼容性问题优先执行

```bash
wsl --update
```

#### 回滚到上一个WSL内核版本，更新后出问题时使用

```bash
wsl --update --rollback
```

#### 挂载Windows物理磁盘/U盘/移动硬盘到WSL

```
wsl --mount <磁盘路径>
```

#### 查看所有wsl命令的帮助文档，记不住命令时一键查询

```bash
wsl --help
```

---

## WSL2 备份与还原

### 备份子系统

**重要提示**：备份前需要先停止子系统

```bash
# 1. 先停止子系统
wsl --shutdown
```

```
# 2. 导出备份为 tar 文件
# wsl --export <分发版名称> <导出位置>
# 示例
wsl --import  Ubuntu-26 F:\WSL\Ubuntu-26.tar
```

### 卸载子系统

```powershell
wsl --unregister <分发版名称>
```

### 还原子系统

#### wsl --import <分发版名称> <安装位置> <文件名> [选项]

```bash
# 示例
wsl --import  Ubuntu-26 F:\WSL  F:\WSL\Ubuntu-26.tar
```

**注意**：还原后的子系统默认会以 root 权限登录，需要修改为默认用户权限（见下方说明）

### 修改默认用户权限

还原后子系统会变为 root 权限，需要以下步骤改回普通用户：

#### 方法一：通过 wsl.conf 配置文件

切换至 root 权限进行修改

```bash
sudo su
```

备份并修改配置文件

```bash
# 备份配置文件
cp /etc/wsl.conf /etc/wsl.conf.bk

# 编辑配置文件
nano /etc/wsl.conf
```

在 `/etc/wsl.conf` 增加以下内容：

```ini
[user]
default = 你的用户名
```

6. 在 PowerShell 中重启 WSL

```powershell
# 停止 WSL
wsl --shutdown

# 重新启动
wsl -d Ubuntu
```

#### 方法二：通过 ubuntu.exe 命令（推荐）

```powershell
ubuntu.exe config --default-user 用户名
```

其中 `用户名` 是你原有 WSL Ubuntu 的用户名称。


---

## 重装系统后恢复 WSL2

如果你重置了系统盘（C 盘），但旧版 WSL2 已经迁移到其他盘，可以按以下步骤恢复。

### 恢复步骤

1. **重新安装 WSL2**
    - 按照网上的 WSL2 安装教程重新安装
    - **重要**：安装的 Ubuntu 版本要和旧版的 Ubuntu 版本一致

2. **迁移新安装的 WSL2**
    - 安装成功后，WSL2 默认安装在 C 盘
    - 按照上面的"WSL2 迁移到其他盘"步骤，将新安装的 WSL2 迁移到其他盘

3. **替换虚拟磁盘文件**
    - 迁移成功后，删除新版的 `ext4.vhdx` 文件
    - 拷贝旧版的 `ext4.vhdx` 文件到相同位置

4. **启动 WSL2**
    - 启动后即可恢复旧版 WSL2

### ⚠️ 重要注意事项

**一定要把新版的 `ext4.vhdx` 删除，不能用旧版的去直接替换新版的 `ext4.vhdx`**

错误做法：直接用旧版文件覆盖新版文件（这样替换后启动 WSL2 会发现还是新版的 Ubuntu）

正确做法：

1. 先删除新版的 `ext4.vhdx`
2. 再拷贝旧版的 `ext4.vhdx` 到该位置

---

## Docker Desktop 配置

Docker 是容器化技术，用于支持创建和使用 Linux® 容器（LXC 技术）。在 Windows 上安装 Docker Desktop 需要基于 Linux 环境，提供了两个选项：**WSL** 与 **Hyper-V**。

### WSL2 运行 Docker 的资源配置

当使用 WSL2 运行 Docker 时，需要在用户目录下创建配置文件来限制资源使用。

#### 配置步骤

1. 在用户目录（如：`C:\Users\你的用户名`）下创建文件 `.wslconfig`

2. 编辑 `.wslconfig` 文件，添加以下内容：

```ini
[wsl2]
processors = 4
memory = 8GB
swap = 8GB
localhostForwarding = true
```

#### 配置参数说明

| 参数                    | 说明                                         | 默认值                  |
|-----------------------|--------------------------------------------|----------------------|
| `processors`          | 使用的 CPU 核心数量                               | 与 Windows 系统使用的核心数相同 |
| `memory`              | 最大使用内存                                     | 无限制                  |
| `swap`                | Swap 空间大小                                  | 自动                   |
| `localhostForwarding` | 是否允许从主机通过 localhost:port 连接 WSL2 VM 中绑定的端口 | true                 |

#### 示例配置

```ini
[wsl2]
# 限制使用 4 个 CPU 核心
processors = 4

# 限制最大使用 8GB 内存
memory = 8GB

# 设置 8GB swap 空间
swap = 8GB

# 启用本地端口转发
localhostForwarding = true
```

3. 重启 WSL2 使配置生效

```powershell
wsl --shutdown
```

### Hyper-V 运行 Docker 的资源配置

当使用 Hyper-V 运行 Docker 时：

1. 在 Docker Desktop 设置中**不勾选** "Use the WSL 2 based engine"
2. 进入 **Resources → Advanced** 页面
3. 直接修改 CPU、内存等资源限制

---

## 参考资料

- WSL 官方文档：https://docs.microsoft.com/windows/wsl/
- Docker Desktop 文档：https://docs.docker.com/desktop/

---

*最后更新：2026-05-10*
*本文档适用于 WSL2 用户学习和参考*
