# docker machine 

* [docker machine](#docker-machine)
* [概述](#%E6%A6%82%E8%BF%B0)
  * [什么是 Docker Machine](#%E4%BB%80%E4%B9%88%E6%98%AF-docker-machine)
  * [为什么要使用 Docker Machine](#%E4%B8%BA%E4%BB%80%E4%B9%88%E8%A6%81%E4%BD%BF%E7%94%A8-docker-machine)
  * [Docker Engine和Docker Machine有什么区别？](#docker-engine%E5%92%8Cdocker-machine%E6%9C%89%E4%BB%80%E4%B9%88%E5%8C%BA%E5%88%AB)
* [创建虚拟机](#%E5%88%9B%E5%BB%BA%E8%99%9A%E6%8B%9F%E6%9C%BA)
  * [安装](#%E5%AE%89%E8%A3%85)
  * [终端命令窗口](#%E7%BB%88%E7%AB%AF%E5%91%BD%E4%BB%A4%E7%AA%97%E5%8F%A3)
  * [查看机器](#%E6%9F%A5%E7%9C%8B%E6%9C%BA%E5%99%A8)
  * [创建VM](#%E5%88%9B%E5%BB%BAvm)
  * [查看环境变量](#%E6%9F%A5%E7%9C%8B%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
  * [配置shell 连接的机器](#%E9%85%8D%E7%BD%AEshell-%E8%BF%9E%E6%8E%A5%E7%9A%84%E6%9C%BA%E5%99%A8)
* [操作虚拟机](#%E6%93%8D%E4%BD%9C%E8%99%9A%E6%8B%9F%E6%9C%BA)
  * [获取主机IP地址](#%E8%8E%B7%E5%8F%96%E4%B8%BB%E6%9C%BAip%E5%9C%B0%E5%9D%80)
  * [运行应用](#%E8%BF%90%E8%A1%8C%E5%BA%94%E7%94%A8)
  * [启动和停止虚拟机](#%E5%90%AF%E5%8A%A8%E5%92%8C%E5%81%9C%E6%AD%A2%E8%99%9A%E6%8B%9F%E6%9C%BA)
  * [不带指定机器名称操作shell](#%E4%B8%8D%E5%B8%A6%E6%8C%87%E5%AE%9A%E6%9C%BA%E5%99%A8%E5%90%8D%E7%A7%B0%E6%93%8D%E4%BD%9Cshell)
  * [配置环境变量与指定机器交互](#%E9%85%8D%E7%BD%AE%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F%E4%B8%8E%E6%8C%87%E5%AE%9A%E6%9C%BA%E5%99%A8%E4%BA%A4%E4%BA%92)
    * [查看环境变量](#%E6%9F%A5%E7%9C%8B%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F-1)
    * [取消环境变量](#%E5%8F%96%E6%B6%88%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
  * [机器启动时默认配置环境变量](#%E6%9C%BA%E5%99%A8%E5%90%AF%E5%8A%A8%E6%97%B6%E9%BB%98%E8%AE%A4%E9%85%8D%E7%BD%AE%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
* [Machine 命令行](#machine-%E5%91%BD%E4%BB%A4%E8%A1%8C)
  * [active 活动](#active-%E6%B4%BB%E5%8A%A8)
  * [config 配置](#config-%E9%85%8D%E7%BD%AE)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA)
  * [env 环境变量](#env-%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
  * [inspect 检查](#inspect-%E6%A3%80%E6%9F%A5)
  * [ip 地址](#ip-%E5%9C%B0%E5%9D%80)
  * [kill 结束](#kill-%E7%BB%93%E6%9D%9F)
  * [ls 显示列表](#ls-%E6%98%BE%E7%A4%BA%E5%88%97%E8%A1%A8)
    * [timeout 超时](#timeout-%E8%B6%85%E6%97%B6)
    * [filter 过滤](#filter-%E8%BF%87%E6%BB%A4)
    * [format 格式化](#format-%E6%A0%BC%E5%BC%8F%E5%8C%96)
  * [mount 挂载](#mount-%E6%8C%82%E8%BD%BD)
  * [provision](#provision)
  * [regenerate\-certs 重生证书](#regenerate-certs-%E9%87%8D%E7%94%9F%E8%AF%81%E4%B9%A6)
  * [restart 重启](#restart-%E9%87%8D%E5%90%AF)
  * [rm 删除机器](#rm-%E5%88%A0%E9%99%A4%E6%9C%BA%E5%99%A8)
  * [scp 复制文件](#scp-%E5%A4%8D%E5%88%B6%E6%96%87%E4%BB%B6)
  * [ssh 远程连接](#ssh-%E8%BF%9C%E7%A8%8B%E8%BF%9E%E6%8E%A5)
  * [start 启动](#start-%E5%90%AF%E5%8A%A8)
  * [status 状态](#status-%E7%8A%B6%E6%80%81)
  * [stop 停止](#stop-%E5%81%9C%E6%AD%A2)
  * [upgrade 升级](#upgrade-%E5%8D%87%E7%BA%A7)
  * [tcp 网址](#tcp-%E7%BD%91%E5%9D%80)
* [命令行汇总](#%E5%91%BD%E4%BB%A4%E8%A1%8C%E6%B1%87%E6%80%BB)

# 概述

## 什么是 Docker Machine 

Docker Machine是一个工具，可让你在虚拟主机上安装Docker Engine并使用`docker-machine`命令管理主机。可以使用计算机在本地Mac或Windows，网络，数据中心或云提供商（如Azure，AWS或Digital Ocean）上创建Docker主机。

使用`docker-machine`命令，可以**启动，检查，停止并重新启动托管主机，升级Docker客户端和守护程序，并配置Docker客户端以与主机通信**。

将机器CLI指向正在运行的托管主机，可以直接在主机上运行`docker` 命令。例如，运行`docker-machine env default`指向所调用的`default`主机，按照提示说明完成 `env`设置，然后运行`docker ps`，`docker run hello-world`等等。

## 为什么要使用 Docker Machine

Docker Machine 使你能够在各种类型的Linux上配置多个远程Docker主机。此外，Machine允许在旧版Mac或Windows系统上运行Docker，如前一主题中所述。

Docker Machine有这两个广泛的用例。

- **一个较旧的桌面系统，并希望在Mac或Windows上运行Docker**

  ![Mac和Windows上的Docker机器](https://docs.docker.com/machine/img/machine-mac-win.png)

  如果您主要工作在不符合新版[Docker for Mac](https://docs.docker.com/docker-for-mac/)和[Docker for Windows](https://docs.docker.com/docker-for-windows/)应用程序要求的较旧的Mac或Windows笔记本电脑或台式机上，则您需要在本地运行Docker Machine运行Docker Engine。使用[Docker Toolbox](https://docs.docker.com/toolbox/overview/)安装程序在Mac或Windows上安装Docker Machine可以为本地虚拟机配置Docker Engine，使您能够连接它并运行`docker`命令。

- **想在远程系统上配置Docker主机**

![Docker机器用于配置多个系统](https://docs.docker.com/machine/img/provision-use-case.png)

Docker Engine在Linux系统上本地运行。如果你有一个Linux系统作为你的主系统，并且想运行`docker`命令，你需要做的就是下载并安装Docker Engine。但是，如果想要在网络上，云端或甚至本地配置多个Docker主机的有效方式，则需要Docker Machine。

无论主系统是Mac，Windows还是Linux，都可以在其上安装Docker Machine并使用`docker-machine`命令配置和管理大量Docker主机。它会自动创建主机，并安装Docker引擎，然后配置`docker`客户端。每个托管主机都是Docker主机和配置客户端的组合。

## Docker Engine和Docker Machine有什么区别？

当人们说**Docker**时，他们通常指的是**Docker Engine**，由Docker守护进程组成的客户端 - 服务器应用程序，指定与守护进程交互的接口的`REST API`以及与守护进程对话的命令行界面（CLI）客户端（通过`REST API`包装器）。docker引擎接受`docker`从CLI命令，例如 `docker run <image>`，`docker ps`可以列出运行容器，`docker image ls` 列出镜像等等。

![Docker引擎](https://docs.docker.com/machine/img/engine.png)

**Docker Machine**是一个供应和管理Docker化主机的工具（`Docker Engine`上的主机）。通常，在本地系统上安装Docker Machine。Docker Machine拥有自己的命令行客户端`docker-machine`和Docker Engine客户端`docker`。可以使用Machine在一个或多个虚拟系统上安装**Docker Engine**。这些虚拟系统可以是本地的（例如当使用Machine在Mac或Windows上的`VirtualBox`中安装和运行Docker引擎）或远程（如当使用Machine在云提供者上配置Docker主机时）。

![码头机](https://docs.docker.com/machine/img/machine.png)

# 创建虚拟机

`docker machine` 如何在本地虚拟机中创建、使用和管理`Docker`主机。

要运行`Docker`容器需要：

- 创建一个新的（或启动一个现有的）`Docker`虚拟机
- 将您的环境切换到新的`VM`
- 使用`docker`客户端创建，加载和管理容器

一旦你创建一台机器，你可以随时重复使用它。像任何`VirtualBox VM`一样，它在使用之间保持其配置。这里的示例显示了如何创建和启动计算机，运行`Docker`命令以及使用容器。

## 安装

下载Docker Machine二进制文件并将其解压到PATH 

如果在**Linux**上**运行**：

```sh
$ base=https://github.com/docker/machine/releases/download/v0.14.0 &&
  curl -L $base/docker-machine-$(uname -s)-$(uname -m) >/tmp/docker-machine &&
  sudo install /tmp/docker-machine /usr/local/bin/docker-machine
```

如果使用[Git BASH](https://git-for-windows.github.io/)运行**Windows**，请执行以下操作：

```sh
$ base=https://github.com/docker/machine/releases/download/v0.14.0 &&
  mkdir -p "$HOME/bin" &&
  curl -L $base/docker-machine-Windows-x86_64.exe > "$HOME/bin/docker-machine.exe" &&
  chmod +x "$HOME/bin/docker-machine.exe"
```

## 终端命令窗口

命令窗口可以是`Bash shell`、`xshell`、`powershell`，只要能运行`shell`即可。

如果你的机器没有安装`shell`，可以安装`Git bash`。`Linux`执行命令安装：

```shell
sudo curl -L https://raw.githubusercontent.com/docker/machine/v0.14.0/contrib/completion/bash/docker-machine.bash -o /etc/bash_completion.d/docker-machine
```



## 查看机器

使用`docker-machine ls`列出可用的机器，如果创建了机器会显示已有的机器。

```shell
$ docker-machine ls
NAME           ACTIVE   DRIVER       STATE     URL                         SWARM   DOCKER        ERRORS
default        -        virtualbox   Running   tcp://192.168.99.100:2376           v18.04.0-ce
my-vm-node-1   *        virtualbox   Running   tcp://192.168.99.101:2376           v18.04.0-ce
my-vm-node-2   -        virtualbox   Running   tcp://192.168.99.102:2376           v18.04.0-ce
my-vm-node-3   -        virtualbox   Running   tcp://192.168.99.103:2376           v18.04.0-ce
```

查看哪台机器处于**活动状态**（如果`DOCKER_HOST`环境变量指向该机器，则认为机器处于活动状态 ）

## 创建VM

运行该`docker-machine create`命令，将相应的驱动程序`virtualbox`传递给该 `--driver`标志并提供一个机器名称。如果这是您的第一台机器，请将其命名`default`为示例中所示。如果您已有“default”机器，请为此新机器选择另一个名称。

```shell
$ docker-machine create --driver virtualbox default
Running pre-create checks...
Creating machine...
(staging) Copying /Users/ripley/.docker/machine/cache/boot2docker.iso to /Users/ripley/.docker/machine/machines/default/boot2docker.iso...
(staging) Creating VirtualBox VM...
(staging) Creating SSH key...
(staging) Starting the VM...
(staging) Waiting for an IP...
Waiting for machine to be running, this may take a few minutes...
Machine is running, waiting for SSH to be available...
Detecting operating system of created instance...
Detecting the provisioner...
Provisioning with boot2docker...
Copying certs to the local machine directory...
Copying certs to the remote machine...
Setting Docker configuration on the remote daemon...
Checking connection to Docker...
Docker is up and running!
To see how to connect Docker to this machine, run: docker-machine env default
```

`--driver virtualbox` 表示虚拟机驱动提供商是**virtualbox**。该命令下载安装了`Docker`守护程序的轻量级`Linux`发行版（[boot2docker](https://github.com/boot2docker/boot2docker)），创建并启动运行`Docker`的`VirtualBox`虚拟机。



## 查看环境变量

`env | grep DOCKER` 查看环境变量配置，下面的可以看出`shell`品类中的机器是`my-vm-node-1`

```shell
$ env | grep DOCKER
DOCKER_MACHINE_NAME=my-vm-node-1
DOCKER_CERT_PATH=C:\Users\Administrator\.docker\machine\machines\my-vm-node-1
DOCKER_TLS_VERIFY=1
DOCKER_HOST=tcp://192.168.99.101:2376
DOCKER_TOOLBOX_INSTALL_PATH=E:\Docker Toolbox
```



## 配置`shell` 连接的机器

`docker-machine create` 命令输出中提示，您需要Docker与新机器通信，你可以用`docker-machine env`命令来设置。

```shell
$ docker-machine env default
export DOCKER_TLS_VERIFY="1"
export DOCKER_HOST="tcp://192.168.99.100:2376"
export DOCKER_CERT_PATH="C:\Users\Administrator\.docker\machine\machines\default"
export DOCKER_MACHINE_NAME="default"
export COMPOSE_CONVERT_WINDOWS_PATHS="true"
# Run this command to configure your shell:
# eval $("E:\Docker Toolbox\docker-machine.exe" env default)
```

通过运行环境变量后，会提示运行`shell`，运行完后`docker-machine`就可以一直保持和对应的机器进行链接通信了。随后查看命令链接的机器后，发现是`default`节点。

```shell
$ eval $("E:\Docker Toolbox\docker-machine.exe" env default)

$ env | grep DOCKER
DOCKER_MACHINE_NAME=default
DOCKER_CERT_PATH=C:\Users\Administrator\.docker\machine\machines\default
DOCKER_TLS_VERIFY=1
DOCKER_HOST=tcp://192.168.99.100:2376
DOCKER_TOOLBOX_INSTALL_PATH=E:\Docker Toolbox
```



如果是其他`shell`则需要指定下对应的终端命令软件。

**PowerShell:**

```shell
$ docker-machine.exe env --shell powershell dev
$Env:DOCKER_TLS_VERIFY = "1"
$Env:DOCKER_HOST = "tcp://192.168.99.101:2376"
$Env:DOCKER_CERT_PATH = "C:\Users\captain\.docker\machine\machines\dev"
$Env:DOCKER_MACHINE_NAME = "dev"
# Run this command to configure your shell:
# docker-machine.exe env --shell=powershell dev | Invoke-Expression
```

 `cmd.exe`:

```shell
$ docker-machine.exe env --shell cmd dev
set DOCKER_TLS_VERIFY=1
set DOCKER_HOST=tcp://192.168.99.101:2376
set DOCKER_CERT_PATH=C:\Users\captain\.docker\machine\machines\dev
set DOCKER_MACHINE_NAME=dev
# Run this command to configure your shell: copy and paste the above values into your command prompt
```

**注意**：如果您正在使用`fish`或`Powershell`、`cmd.exe`，则上述方法不能按所述方式工作。相反，看看[该`env`命令的文档](https://docs.docker.com/machine/reference/env/) ，以了解如何设置环境变量的`shell`。

这为Docker客户端读取的当前shell设置环境变量，它指定`TLS`设置。每次打开新`shell`或重新启动计算机时都需要执行此操作。（另请参阅如何 [在当前shell中取消设置环境变量](https://docs.docker.com/machine/get-started/#unset-environment-variables-in-the-current-shell)。）



# 操作虚拟机

## 获取主机IP地址

Docker主机的`IP`地址上提供了任何公开的端口，您可以使用以下`docker-machine ip`命令获得这些端口：

```shell
 $ docker-machine ip default
 192.168.99.100
```



## 运行应用

使用以下命令在容器中运行[Nginx](https://www.nginx.com/) Web服务器，`-d` 表示后台运行，`-p` 表示发布应用：

```shell
 $ docker run -d -p 8000:80 nginx
```

`nginx`下载安装运行完成后，通过当前虚拟机ip `docker-machine ip`访问 `8080`端口，可以看到`nginx`成功运行

```shell
$ curl $(docker-machine ip default):8000
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100   612  100   612    0     0    612      0  0:00:01 --:--:--  0:00:01  597k<!DOCTYPE html>
<html>
<head>
<title>Welcome to nginx!</title>
<style>
    body {
        width: 35em;
        margin: 0 auto;
        font-family: Tahoma, Verdana, Arial, sans-serif;
    }
</style>
</head>
<body>
<h1>Welcome to nginx!</h1>
<p>If you see this page, the nginx web server is successfully installed and
working. Further configuration is required.</p>

<p>For online documentation and support please refer to
<a href="http://nginx.org/">nginx.org</a>.<br/>
Commercial support is available at
<a href="http://nginx.com/">nginx.com</a>.</p>

<p><em>Thank you for using nginx.</em></p>
</body>
</html>
```

可以创建和管理、运行多个Docker的本地虚拟机，因为可以通过再次运行 `docker-machine create`创建新的虚拟机。所有创建的机器都出现在输出中`docker-machine ls`。



## 启动和停止虚拟机

如果需要启动或停止虚拟机，可以用停止命令`docker-machine stop` 启动虚拟机命令`docker-machine start`。

```shell
$ docker-machine stop default
$ docker-machine start default
```



## 不带指定机器名称操作`shell`

一些`docker-machine`命令的操作应该在名为`default`的机器（如果存在的话）上运行，如果没有指定机器名称的话。因为使用名为`default`的本地虚拟机是一种常见模式。

下面一些不带机器名称的命令操作，都会默认定位到`default`机器

```shell
$ docker-machine stop
Stopping "default"....
Machine "default" was stopped.

$ docker-machine start
Starting "default"...
(default) Waiting for an IP...
Machine "default" was started.
Started machines may have new IP addresses.  You may need to re-run the `docker-machine env` command.

$ eval $(docker-machine env)

$ docker-machine ip
192.168.99.100
```

还有其他命令也支持不带机器名进行操作

```shell
- `docker-machine config` 			# 机器配置
- `docker-machine env`				# 环境变量
- `docker-machine inspect`			# 检查
- `docker-machine ip`				# 机器 ip
- `docker-machine kill`				# 杀死机器
- `docker-machine provision`		# 重做固定的任务	
- `docker-machine regenerate-certs`  # 注册生成证书
- `docker-machine restart`			# 重启机器
- `docker-machine ssh`				# ssh 链接机器
- `docker-machine start`			# 启动
- `docker-machine status`			# 运行状态
- `docker-machine stop`				# 停止
- `docker-machine upgrade`			# 升级
- `docker-machine url`				# tcp url
```



## 配置环境变量与指定机器交互

有时候可能想要使用当前`shell`连接到不同的`Docker Engine`。在这种情况下，可以选择将当前shell的环境切换到不同的Docker引擎。

### 查看环境变量

运行`env|grep DOCKER`以检查是否设置了DOCKER环境变量。

```shell
$ env | grep DOCKER
DOCKER_MACHINE_NAME=default
DOCKER_CERT_PATH=C:\Users\Administrator\.docker\machine\machines\default
DOCKER_TLS_VERIFY=1
DOCKER_HOST=tcp://192.168.99.100:2376
DOCKER_TOOLBOX_INSTALL_PATH=E:\Docker Toolbox
```

通过上面的输出信息可以看到当前环境变量配置默认链接的机器是`default`

### 取消环境变量

---

- `unset`在以下`DOCKER`环境变量上运行该命令

  ```shell
  unset DOCKER_TLS_VERIFY
  unset DOCKER_CERT_PATH
  unset DOCKER_MACHINE_NAME
  unset DOCKER_HOST
  ```

- 或者，运行快捷命令`docker-machine env -u`以显示您需要运行的命令以取消设置所有DOCKER变量：

  ```shell
  $ docker-machine env -u
  unset DOCKER_TLS_VERIFY
  unset DOCKER_HOST
  unset DOCKER_CERT_PATH
  unset DOCKER_MACHINE_NAME
  # Run this command to configure your shell:
  # eval $("E:\Docker Toolbox\docker-machine.exe" env -u)
  ```

  最后再运行上面输出的最后一行命令 `eval $("E:\Docker Toolbox\docker-machine.exe" env -u)`就取消了环境变量设置。

  取消完成后，再次查看环境变量，发现环境变量已经都取消成功。

  ```shell
  $ env | grep DOCKER
  DOCKER_TOOLBOX_INSTALL_PATH=E:\Docker Toolbox
  ```

  **如果您在`Docker Cloud`上运行群集，则可以重新运行`export` 用于连接群集的命令。**

  

## 机器启动时默认配置环境变量

为确保在每个shell会话开始时自动配置Docker客户端，可以`eval $(docker-machine env default)`通过将其添加到`~/.bash_profile`文件或shell的等效配置文件中来嵌入shell 配置文件。但是，如果调用的计算机`default`未运行，则会失败 。您可以配置系统以`default` 自动启动机器。



# Machine 命令行

```shell
$ docker-machine -h
Usage: docker-machine.exe [OPTIONS] COMMAND [arg...]
创建和管理运行Docker的机器.

Options:
  --debug, -D                                                   启用调试模式
  --storage-path, -s "C:\Users\Administrator\.docker\machine"   配置存储路[$MACHINE_STORAGE_PATH]
  --tls-ca-cert                                                 CA远程验证[$MACHINE_TLS_CA_CERT]
  --tls-ca-key                                                生成证书的私钥[$MACHINE_TLS_CA_KEY]
  --tls-client-cert                                用于TLS的客户端证书[$MACHINE_TLS_CLIENT_CERT]
  --tls-client-key                                用于客户端TLS认证的私钥[$MACHINE_TLS_CLIENT_KEY]
  --github-api-token                            令牌用于请求Github API[$MACHINE_GITHUB_API_TOKEN]
  --native-ssh                                    使用本地（基于Go）的SSH实现[$MACHINE_NATIVE_SSH]
  --bugsnag-api-token                  用于崩溃报告的BugSnag API令牌[$MACHINE_BUGSNAG_API_TOKEN]
  --help, -h                                                    帮助
  --version, -v                                                 打印版本

Commands:
  active                打印哪台机器处于活动状态
  config                打印机器的连接配置
  create                创建一台机器
  env                   显示设置Docker客户端环境的命令
  inspect               检查检查有关机器的信息
  ip                    获取一台机器的IP地址
  kill                  杀死一台机器
  ls                    列出机器
  provision             准备重新调配现有机器
  regenerate-certs      重新生成证书为机器重新生成TLS证书
  restart               重新启动重新启动机器
  rm                    删除一台机器
  ssh                   使用SSH登录或在机器上运行命令.
  scp                   在机器之间复制文件
  mount                 使用SSHFS挂载或卸载机器上的目录.
  start                 开始启动一台机器
  status                获取机器的状态
  stop                  停止一台机器
  upgrade               将计算机升级到最新版本的Docker
  url                   获取一台机器的URL
  version               Show the Docker Machine version or a machine docker version
  help                  Shows a list of commands or help for one command
```



## active 活动

`docker-machine ls`查看哪台机器处于**活动状态**（如果`DOCKER_HOST`环境变量指向该机器，则认为机器处于活动状态 ）

```shell
$ docker-machine ls
NAME           ACTIVE   DRIVER       STATE     URL                         SWARM   DOCKER        ERRORS
default        *        virtualbox   Running   tcp://192.168.99.100:2376           v18.04.0-ce
my-vm-node-1   -        virtualbox   Running   tcp://192.168.99.101:2376           v18.04.0-ce
my-vm-node-2   -        virtualbox   Running   tcp://192.168.99.102:2376           v18.04.0-ce
my-vm-node-3   -        virtualbox   Running   tcp://192.168.99.103:2376           v18.04.0-ce
```

## config 配置

`docker-machine config`查看机器的配置信息

```shell
$ docker-machine config default
--tlsverify
--tlscacert="C:\\Users\\Administrator\\.docker\\machine\\machines\\default\\ca.pem"
--tlscert="C:\\Users\\Administrator\\.docker\\machine\\machines\\default\\cert.pem"
--tlskey="C:\\Users\\Administrator\\.docker\\machine\\machines\\default\\key.pem"
-H=tcp://192.168.99.100:2376
```

## create 创建

`docker-machine create`创建一台机器。需要该`--driver`标志来指示应在哪个提供商（`VirtualBox，DigitalOcean，AWS`等）上创建机器，以及用于指示所创建机器的名称的参数。

```shell
$ docker-machine create --driver virtualbox dev
```

创建虚拟机名称为 `dev`，提供商是 `virtualbox`

使用帮助指令会看到很多关于创建虚拟机的默认配置选项

```shell
$ docker-machine create -h
```

可以到一些标志也指定了它们与之关联的环境变量（位于该行的最左侧）。如果这些环境变量在`docker-machine create`被调用时被设置，`Docker Machine`将它们用作默认值。

`Docker Machine`仅在守护进程上设置配置参数，并且不会设置任何“依赖关系”。例如，如果指定创建的守护程序应该`btrfs`用作存储驱动程序，则仍必须确保安装了适当的依赖关系，已创建`BTRFS`文件系统等等。

以下是一个示例用法：

```shell
$ docker-machine create -d virtualbox \
    --engine-label foo=bar \
    --engine-label spam=eggs \
    --engine-storage-driver overlay \
    --engine-insecure-registry registry.myco.com \
    foobarmachine
```

这将创建一个在`Virtualbox`中本地运行的虚拟机，该虚拟机使用 `overlay`存储后端，在引擎上具有键值对`foo=bar`和`spam=eggs`标签，并允许从位于的不安全的仓库中进行**推送/拉取**`registry.myco.com`。您可以通过查看一下内容输出来验证大部分内容`docker info`：

```shell
$ eval $(docker-machine env foobarmachine)
$ docker info
Containers: 0
Images: 0
Storage Driver: overlay
...
Name: foobarmachine
...
Labels:
 foo=bar
 spam=eggs
 provider=virtualbox
```

支持的配置如下所示：

- `--engine-insecure-registry`：指定[不安全的注册表](https://docs.docker.com/engine/reference/commandline/cli/#insecure-registries)以允许创建引擎
- `--engine-registry-mirror`：指定要使用的[注册表镜像](https://docs.docker.com/registry/recipes/mirror/)
- `--engine-label`：为创建的引擎指定[标签](https://docs.docker.com/engine/userguide/labels-custom-metadata/#daemon-labels)
- `--engine-storage-driver`：指定要与引擎一起使用的[存储驱动程序](https://docs.docker.com/engine/reference/commandline/cli/#daemon-storage-driver-option)

除了直接支持的守护进程标志子集之外，Docker Machine还支持一个附加标志，`--engine-opt`可用于使用语法指定任意守护进程选项`--engine-opt flagname=value`。例如，要指定守护程序应该`8.8.8.8`用作所有容器的DNS服务器，并且始终使用`syslog` [日志驱动程序](https://docs.docker.com/engine/reference/run/#logging-drivers-log-driver)，则可以运行以下create命令：

```shell
$ docker-machine create -d virtualbox \
    --engine-opt dns=8.8.8.8 \
    --engine-opt log-driver=syslog \
    gdns
```

另外，Docker机器支持一个标志，`--engine-env`它可以用来指定任意环境变量，以便在语法引擎中设置`--engine-env name=value`。例如，要指定引擎应该`example.com`用作代理服务器，可以运行以下create命令：

```shell
$ docker-machine create -d virtualbox \
    --engine-env HTTP_PROXY=http://example.com:8080 \
    --engine-env HTTPS_PROXY=https://example.com:8080 \
    --engine-env NO_PROXY=example2.com \
    proxbox
```



## env 环境变量

设置环境变量以指示`docker`应该针对特定机器运行命令。

`docker-machine env machine_name`可以输出在`shell`中运行的环境变量。运行`docker-machine machine_name -u`可以取消设置环境变量`unset`。

```shell
$ env | grep DOCKER

$ eval "$(docker-machine env machine_name)"

$ env | grep DOCKER
DOCKER_HOST=tcp://192.168.99.101:2376
DOCKER_CERT_PATH=/Users/nathanleclaire/.docker/machines/.client
DOCKER_TLS_VERIFY=1
DOCKER_MACHINE_NAME=machine_name
$ # If you run a docker command, now it runs against that host.
$ eval "$(docker-machine env -u)"
$ env | grep DOCKER
$ # The environment variables have been unset.
```

代理模式配置

```shell
$ docker-machine env --no-proxy default
```



## inspect 检查

这个命令会将机器的详细配置信息以`JSON`的格式展示出来

```shell
$ docker-machine inspect default
{
    "ConfigVersion": 3,
    "Driver": {
        "IPAddress": "192.168.99.100",
        "MachineName": "default",
        "SSHUser": "docker",
        "SSHPort": 9112,
        "SSHKeyPath": "C:\\Users\\Administrator\\.docker\\machine\\machines\\default\\id_rsa",
        "StorePath": "C:\\Users\\Administrator\\.docker\\machine",
        "SwarmMaster": false,
        "SwarmHost": "tcp://0.0.0.0:3376",
        "SwarmDiscovery": "",
        "VBoxManager": {},
        "HostInterfaces": {},
        "CPU": 1,
        "Memory": 1024,
        "DiskSize": 20000,
		........
    },
	......
......	
```

**获取机器的IP地址和内存大小：** 大多数情况下，可以以相当直接的方式从`JSON`中查找对应的字段。

```shell
$ docker-machine inspect --format='{{.Driver.IPAddress}}' default
192.168.5.99

$ docker-machine inspect --format='{{.Driver.Memory}}' default
1024
```

**取消JSON格式化信息**，从详细信息中获取`Driver`的信息，没有格式化的返回原始数据模型。

```shell
# 无格式化返回json
$ docker-machine inspect --format='{{json .Driver}}' default
# 直接返回原始数据
$ docker-machine inspect --format='{{.Driver}}' default
map[CPU:1 IPAddress:192.168.99.100 VBoxManager:map[] Memory:1024 NoShare:false MachineName:default SSHKeyPath:C:\Users\Administrator\.docker\machine\machines\default\id_rsa SwarmDiscovery: HostOnlyPromiscMode:deny DNSProxy:true SwarmHost:tcp://0.0.0.0:3376 NatNicType:82540EM SSHPort:9112 Boot2DockerURL: StorePath:C:\Users\Administrator\.docker\machine UIType:headless SSHUser:docker HostInterfaces:map[] DiskSize:20000 NoVTXCheck:false HostOnlyCIDR:192.168.99.1/24 HostOnlyNicType:82540EM HostOnlyNoDHCP:false ShareFolder: SwarmMaster:false Boot2DockerImportVM: HostDNSResolver:false]
```

**格式化输出信息**，为了提高可读性，利用`prettyjson`进行格式化

```shell
$ docker-machine inspect --format='{{prettyjson .Driver}}' default
{
    "Boot2DockerImportVM": "",
    "Boot2DockerURL": "",
    "CPU": 1,
    "DNSProxy": true,
    "DiskSize": 20000,
    "HostDNSResolver": false,
    "HostInterfaces": {},
    "HostOnlyCIDR": "192.168.99.1/24",
    "HostOnlyNicType": "82540EM",
    "HostOnlyNoDHCP": false,
    "HostOnlyPromiscMode": "deny",
    "IPAddress": "192.168.99.100",
    "MachineName": "default",
    "Memory": 1024,
    "NatNicType": "82540EM",
    "NoShare": false,
    "NoVTXCheck": false,
    "SSHKeyPath": "C:\\Users\\Administrator\\.docker\\machine\\machines\\default\\id_rsa",
    "SSHPort": 9112,
    "SSHUser": "docker",
    "ShareFolder": "",
    "StorePath": "C:\\Users\\Administrator\\.docker\\machine",
    "SwarmDiscovery": "",
    "SwarmHost": "tcp://0.0.0.0:3376",
    "SwarmMaster": false,
    "UIType": "headless",
    "VBoxManager": {}
}
```

## ip 地址

`docker-machine ip dev dev2` 获取一台或多台机器IP地址

```shell
$ docker-machine ip dev
192.168.99.104

$ docker-machine ip dev dev2
192.168.99.104
192.168.99.105
```



## kill 结束

`docker-machine kill dev` 杀死机器 `dev`

```shell
$ docker-machine ls
NAME   ACTIVE   DRIVER       STATE     URL
dev    *        virtualbox   Running   tcp://192.168.99.104:2376

$ docker-machine kill dev
$ docker-machine ls
NAME   ACTIVE   DRIVER       STATE     URL
dev    *        virtualbox   Stopped
```



## ls 显示列表

`docker-machine ls`显示所有安装的机器

```shell
$ docker-machine ls
NAME   ACTIVE   DRIVER       STATE     URL
dev    *        virtualbox   Running   tcp://192.168.99.104:2376
```

### timeout 超时

---

`ls`命令尝试并行访问每个主机。如果在10秒内给定的主机没有应答，则该`ls`命令指出该主机处于 `Timeout`状态。在某些情况下（连接不良，负载过高或故障排除时），可能需要增加或减少此值。可以使用`-t`标志来达到此目的，**数值单位是秒**。

```shell
$ docker-machine ls -t 1
NAME           ACTIVE   DRIVER       STATE     URL   SWARM   DOCKER   ERRORS
default                 virtualbox   Timeout
my-vm-node-1            virtualbox   Timeout
my-vm-node-2            virtualbox   Timeout
my-vm-node-3            virtualbox   Timeout
```

如果1秒内没有显示出的机器就会显示`timeout`状态

### filter 过滤

---

过滤标志（`--filter`）格式是`key=value`键值对。如果有多个过滤器，则传递多个标志。例如：`--filter "foo=bar" --filter "bif=baz"`

目前支持的过滤器有：

- driver (设备名称、提供商)
- swarm (集群主机)
- state (`Running|Paused|Saved|Stopped|Stopping|Starting|Error`)
- name (机器名称，支持[golang风格的](https://github.com/google/re2/wiki/Syntax)正则表达式)
- label (机器创建的`--engine-label`选项，可以过滤`label=<key>[=<value>]`)

列举 名称` my- `开头的机器

```shell
$ docker-machine ls --filter name=my-*
NAME           ACTIVE   DRIVER       STATE     URL                         SWARM   DOCKER        ERRORS
my-vm-node-1   -        virtualbox   Running   tcp://192.168.99.101:2376           v18.04.0-ce
my-vm-node-2   -        virtualbox   Running   tcp://192.168.99.102:2376           v18.04.0-ce
my-vm-node-3   -        virtualbox   Running   tcp://192.168.99.103:2376           v18.04.0-ce
```

列举 提供商是 `virtualbox`， 状态是`Stopped` 的机器

```shell
$ docker-machine ls --filter driver=virtualbox --filter state=Stopped
```

列举时，用` label`进行过滤

```shell
$ docker-machine ls --filter label=com.class.app=foo1 --filter label=com.class.app=foo2
```

### format 格式化

---

在列举机器的时候，可以自定义格式化输出形式，格式化字段

| Placeholder    | Description                              |
| -------------- | ---------------------------------------- |
| .Name          | Machine name                             |
| .Active        | Is the machine active?                   |
| .ActiveHost    | Is the machine an active non-swarm host? |
| .ActiveSwarm   | Is the machine an active swarm master?   |
| .DriverName    | Driver name                              |
| .State         | Machine state (running, stopped...)      |
| .URL           | Machine URL                              |
| .Swarm         | Machine swarm name                       |
| .Error         | Machine errors                           |
| .DockerVersion | Docker Daemon version                    |
| .ResponseTime  | Time taken by the host to respond        |

**普通格式化输出**

```shell
$ docker-machine ls --format "{{.Name}}: {{.DriverName}}"
default: virtualbox
my-vm-node-1: virtualbox
my-vm-node-2: virtualbox
my-vm-node-3: virtualbox
```

**table 格式输出**

```shell
$ docker-machine ls --format "table {{.Name}} \t {{.DriverName}}"
NAME             DRIVER
default          virtualbox
my-vm-node-1     virtualbox
my-vm-node-2     virtualbox
my-vm-node-3     virtualbox
```



## mount 挂载

`docker-machine mount`将本地主机上的目录挂载到远程机器上

```shell
# 本地创建一个目录
$ mkdir foo
# 在远程dev主机上创建一个目录
$ docker-machine ssh dev mkdir foo
# 挂载目录，将当前目录 foo 挂载到远程主机 dev上的/home/docker/foo
$ docker-machine mount dev:/home/docker/foo foo
# 创建文件
$ touch foo/bar
# 查看远程主机的 foo
$ docker-machine ssh dev ls foo
```

要再次卸载挂载目录，可以使用与`-u`选项 。也可以直接调用`fuserunmount`（或`fusermount -u`）命令。

```shell
$ docker-machine mount -u dev:/home/docker/foo foo
$ rmdir foo
```



## provision

`docker-machine provision`在机器上重新运行配置。有时候在创建虚拟机的时候会发生错误或异常，或者是需要修改主机配置。在此过程出现错误异常故障后，经过修复后需要重新接着之前的命令运行可以运行这个命令。

用法是`docker-machine provision [name]`。可以指定多个名称

```shell
$ docker-machine provision foo bar

Copying certs to the local machine directory...
Copying certs to the remote machine...
Setting Docker configuration on the remote daemon...
```

机器重新运行配置过程将会执行如下操作：

1. 将实例上的主机名设置为机器的名称，例如`default`。
2. 如果Docker不存在，请安装Docker。
3. 生成一组证书（通常使用默认的自签名CA）并配置守护程序以接受通过TLS的连接。
4. 将生成的证书复制到服务器和本地配置目录。
5. 根据创建时指定的选项配置Docker引擎。
6. 如果适用，配置并激活Swarm。



## regenerate-certs 重生证书

`docker-machine regenerate-certs`重新生成TLS证书并使用新证书更新机器。

例如：

```shell
$ docker-machine regenerate-certs dev

Regenerate TLS machine certs?  Warning: this is irreversible. (y/n): y
Regenerating TLS certificates
```

如果您的证书已过期，则还需要使用以下`--client-certs`选项重新生成客户端证书：

```shell
$ docker-machine regenerate-certs --client-certs dev
Regenerate TLS machine certs?  Warning: this is irreversible. (y/n): y
Regenerating TLS certificates
Regenerating local certificates
...
```



## restart 重启

`docker-machine restart`重新启动机器。这通常相当于 `docker-machine stop; docker-machine start`。但是一些云驱动程序试图实现保持相同IP地址的巧妙重启。

```shell
$ docker-machine restart dev
Waiting for VM to start...
```



## rm 删除机器

`docker-machine rm`删除一台机器。这会删除本地引用文件，并在云提供商或虚拟化管理平台上将其删除。

`docker-machine rm baz` 删除一台机器，`docker-machine rm baz foo` 删除多台机器，直接删除 `-y`选项 `docker-machine rm -y foo`



## scp 复制文件

`docker-machine scp`将文件从本地主机复制到机器，从机器到机器或从机器到使用的本地主机`scp`。目录是`machinename:/path/to/files`， 在主机的情况下，不需要指定名称，只需指定路径。

```shell
$ cat foo.txt
cat: foo.txt: No such file or directory
# 查看远程主机的工作目录
$ docker-machine ssh dev pwd
/home/docker
# 在远程主机上创建文件
$ docker-machine ssh dev 'echo A file created remotely! >foo.txt'
# 将远程主机上的文件复制到本地 当前目录
$ docker-machine scp dev:/home/docker/foo.txt .
foo.txt                                                           100%   28     0.0KB/s   00:00
$ cat foo.txt
A file created remotely!
```

`-r ` 递归选项，用于复制目录结构的文件夹。`-d` 表示有大量的文件，通过增量复制，避免中途失败从新开始。

```shell
$ mkdir -p bar
$ touch bar/baz
$ docker-machine scp -r -d bar/ dev:/home/docker/bar/
$ docker-machine ssh dev ls bar
```



## ssh 远程连接

`docker-machine ssh`使用SSH登录或在计算机上运行命令。

要登录，只需运行`docker-machine ssh machine_name`：

```shell
$ docker-machine ssh dev
```

在远程主机上运行命令`docker-machine ssh dev free`，这种操作就像在本地操作一样：

```shell
$ docker-machine ssh dev free
$ docker-machine ssh dev "ls /home/"
$ docker-machine ssh dev "docker swarm init --advertise-addr 192.168.99.101"
```

如果端口冲突不能连接，可以进行端口映射访问，以下命令将端口8080从`default`机器转发到`localhost`主机上：

```shell
$ docker-machine ssh default -L 8080:localhost:8080
```

其他版本的ssh进行连接，可以设置默认的版本

```shell
$ docker-machine --native-ssh ssh dev
```



## start 启动

`docker-machine start`启动机器

```shell
$ docker-machine start dev
Starting VM...
```



## status 状态

`docker-machine status`查看机器运行状态

```shell
$ docker-machine status dev
Running
```



## stop 停止

`docker-machine stop`停止机器运行

```shell
$ docker-machine ls
NAME   ACTIVE   DRIVER       STATE     URL
dev    *        virtualbox   Running   tcp://192.168.99.104:2376

$ docker-machine stop dev

$ docker-machine ls
NAME   ACTIVE   DRIVER       STATE     URL
dev    *        virtualbox   Stopped
```



## upgrade 升级

将计算机升级到最新版本的Docker。如果机器使用`Ubuntu`作为底层操作系统，它会运行一个类似的命令`sudo apt-get upgrade docker-engine`，因为机器期望`Ubuntu`管理它使用这个软件包。又如，如果机器使用`boot2docker`作为其操作系统，则该命令会下载最新的`boot2docker` ISO并将机器的现有ISO替换为最新的。

```shell
$ docker-machine upgrade default

Stopping machine to do the upgrade...
Upgrading machine default...
Downloading latest boot2docker release to /home/username/.docker/machine/cache/boot2docker.iso...
Starting machine back up...
Waiting for VM to start...
```



## tcp 网址

```shell
$ docker-machine url dev
tcp://192.168.99.109:2376
```



# 命令行汇总

```shell
$ docker-machine ls						# 查看已安装的虚拟机
$ docker-machine create --driver virtualbox default	# 创建虚拟机 --driver virtualbox 表示虚拟机驱动提供商是virtualbox，default 表示虚拟机的名称
$ env | grep DOCKER						# 查看 环境变量
$ docker-machine env default  			# 查看指定机器环境变量
$ docker-machine env -u 				# 取消环境变量设置
$ eval $(docker-machine env default)	# 配置指定机器环境里的shell默认链接机器
$ docker-machine env --shell powershell dev  # 指定shell目录的终端工具
$ docker-machine ip default					# 获取指定机器地址
$ docker run -d -p 8000:80 nginx			# -d 表示后台运行，-p 表示发布应用
$ curl $(docker-machine ip default):8000		# 访问指定机器
$ docker-machine stop default				# 启动指定机器
$ docker-machine start default				# 停止 指定 机器

$ docker-machine scp dev:/home/docker/foo.txt .  #复制远程主机文件到本地
$ docker-machine rm baz				# 删除主机
$ docker-machine mount dev:/home/docker/foo foo		# 挂载目录

- `docker-machine config` 			# 机器配置
- `docker-machine env`				# 环境变量
- `docker-machine inspect`			# 检查
- `docker-machine ip`				# 机器 ip
- `docker-machine kill`				# 杀死机器
- `docker-machine provision`		# 重做固定的任务	
- `docker-machine regenerate-certs`  # 注册生成证书
- `docker-machine restart`			# 重启机器
- `docker-machine ssh`				# ssh 链接机器
- `docker-machine start`			# 启动
- `docker-machine status`			# 运行状态
- `docker-machine stop`				# 停止
- `docker-machine upgrade`			# 升级
- `docker-machine url`				# tcp url
```

