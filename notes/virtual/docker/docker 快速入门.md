# docker 快速入门

* [docker 快速入门](#docker-%E5%BF%AB%E9%80%9F%E5%85%A5%E9%97%A8)
* [docker 概述](#docker-%E6%A6%82%E8%BF%B0)
  * [镜像和容器](#%E9%95%9C%E5%83%8F%E5%92%8C%E5%AE%B9%E5%99%A8)
  * [容器和虚拟机](#%E5%AE%B9%E5%99%A8%E5%92%8C%E8%99%9A%E6%8B%9F%E6%9C%BA)
* [docker 安装](#docker-%E5%AE%89%E8%A3%85)
  * [下载](#%E4%B8%8B%E8%BD%BD)
  * [安装](#%E5%AE%89%E8%A3%85)
  * [测试](#%E6%B5%8B%E8%AF%95)
  * [镜像加速](#%E9%95%9C%E5%83%8F%E5%8A%A0%E9%80%9F)
    * [<strong>Ubuntu系统加速</strong>](#ubuntu%E7%B3%BB%E7%BB%9F%E5%8A%A0%E9%80%9F)
    * [<strong>Win 7 如何配置镜像加速器</strong>](#win-7-%E5%A6%82%E4%BD%95%E9%85%8D%E7%BD%AE%E9%95%9C%E5%83%8F%E5%8A%A0%E9%80%9F%E5%99%A8)
  * [本节命令汇总](#%E6%9C%AC%E8%8A%82%E5%91%BD%E4%BB%A4%E6%B1%87%E6%80%BB)
* [docker 容器](#docker-%E5%AE%B9%E5%99%A8)
  * [基本命令](#%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
    * [运行hello world示例](#%E8%BF%90%E8%A1%8Chello-world%E7%A4%BA%E4%BE%8B)
    * [查看已经安装的镜像](#%E6%9F%A5%E7%9C%8B%E5%B7%B2%E7%BB%8F%E5%AE%89%E8%A3%85%E7%9A%84%E9%95%9C%E5%83%8F)
    * [查看镜像运行历史](#%E6%9F%A5%E7%9C%8B%E9%95%9C%E5%83%8F%E8%BF%90%E8%A1%8C%E5%8E%86%E5%8F%B2)
    * [查看运行过的容器信息](#%E6%9F%A5%E7%9C%8B%E8%BF%90%E8%A1%8C%E8%BF%87%E7%9A%84%E5%AE%B9%E5%99%A8%E4%BF%A1%E6%81%AF)
    * [查看运行过的容器ID信息](#%E6%9F%A5%E7%9C%8B%E8%BF%90%E8%A1%8C%E8%BF%87%E7%9A%84%E5%AE%B9%E5%99%A8id%E4%BF%A1%E6%81%AF)
  * [创建镜像容器](#%E5%88%9B%E5%BB%BA%E9%95%9C%E5%83%8F%E5%AE%B9%E5%99%A8)
    * [定义镜像容器的Dockerfile](#%E5%AE%9A%E4%B9%89%E9%95%9C%E5%83%8F%E5%AE%B9%E5%99%A8%E7%9A%84dockerfile)
    * [编写镜像中的程序](#%E7%BC%96%E5%86%99%E9%95%9C%E5%83%8F%E4%B8%AD%E7%9A%84%E7%A8%8B%E5%BA%8F)
    * [构建镜像程序](#%E6%9E%84%E5%BB%BA%E9%95%9C%E5%83%8F%E7%A8%8B%E5%BA%8F)
    * [查看已经安装的镜像程序](#%E6%9F%A5%E7%9C%8B%E5%B7%B2%E7%BB%8F%E5%AE%89%E8%A3%85%E7%9A%84%E9%95%9C%E5%83%8F%E7%A8%8B%E5%BA%8F)
    * [运行镜像程序](#%E8%BF%90%E8%A1%8C%E9%95%9C%E5%83%8F%E7%A8%8B%E5%BA%8F)
    * [查看ip地址](#%E6%9F%A5%E7%9C%8Bip%E5%9C%B0%E5%9D%80)
    * [测试镜像程序](#%E6%B5%8B%E8%AF%95%E9%95%9C%E5%83%8F%E7%A8%8B%E5%BA%8F)
    * [停止运行的镜像程序](#%E5%81%9C%E6%AD%A2%E8%BF%90%E8%A1%8C%E7%9A%84%E9%95%9C%E5%83%8F%E7%A8%8B%E5%BA%8F)
    * [重启容器程序](#%E9%87%8D%E5%90%AF%E5%AE%B9%E5%99%A8%E7%A8%8B%E5%BA%8F)
    * [删除容器](#%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8)
    * [在后台运行镜像程序](#%E5%9C%A8%E5%90%8E%E5%8F%B0%E8%BF%90%E8%A1%8C%E9%95%9C%E5%83%8F%E7%A8%8B%E5%BA%8F)
    * [交互式运行容器](#%E4%BA%A4%E4%BA%92%E5%BC%8F%E8%BF%90%E8%A1%8C%E5%AE%B9%E5%99%A8)
    * [后台独立容器模式](#%E5%90%8E%E5%8F%B0%E7%8B%AC%E7%AB%8B%E5%AE%B9%E5%99%A8%E6%A8%A1%E5%BC%8F)
    * [查看容器日志](#%E6%9F%A5%E7%9C%8B%E5%AE%B9%E5%99%A8%E6%97%A5%E5%BF%97)
    * [统计监控](#%E7%BB%9F%E8%AE%A1%E7%9B%91%E6%8E%A7)
  * [分享镜像](#%E5%88%86%E4%BA%AB%E9%95%9C%E5%83%8F)
    * [登陆docker 云端](#%E7%99%BB%E9%99%86docker-%E4%BA%91%E7%AB%AF)
    * [登出docker 云端](#%E7%99%BB%E5%87%BAdocker-%E4%BA%91%E7%AB%AF)
    * [建立标签](#%E5%BB%BA%E7%AB%8B%E6%A0%87%E7%AD%BE)
    * [提交镜像](#%E6%8F%90%E4%BA%A4%E9%95%9C%E5%83%8F)
  * [运行远程云端的镜像](#%E8%BF%90%E8%A1%8C%E8%BF%9C%E7%A8%8B%E4%BA%91%E7%AB%AF%E7%9A%84%E9%95%9C%E5%83%8F)
  * [本节命令汇总](#%E6%9C%AC%E8%8A%82%E5%91%BD%E4%BB%A4%E6%B1%87%E6%80%BB-1)
* [docker 服务](#docker-%E6%9C%8D%E5%8A%A1)
  * [配置 docker\-compose\.yml文件](#%E9%85%8D%E7%BD%AE-docker-composeyml%E6%96%87%E4%BB%B6)
  * [运行负载平衡应用程序](#%E8%BF%90%E8%A1%8C%E8%B4%9F%E8%BD%BD%E5%B9%B3%E8%A1%A1%E5%BA%94%E7%94%A8%E7%A8%8B%E5%BA%8F)
    * [启动集群](#%E5%90%AF%E5%8A%A8%E9%9B%86%E7%BE%A4)
    * [部署服务](#%E9%83%A8%E7%BD%B2%E6%9C%8D%E5%8A%A1)
    * [扩展服务](#%E6%89%A9%E5%B1%95%E6%9C%8D%E5%8A%A1)
    * [查看服务](#%E6%9F%A5%E7%9C%8B%E6%9C%8D%E5%8A%A1)
    * [查看服务详细](#%E6%9F%A5%E7%9C%8B%E6%9C%8D%E5%8A%A1%E8%AF%A6%E7%BB%86)
    * [查看服务日志](#%E6%9F%A5%E7%9C%8B%E6%9C%8D%E5%8A%A1%E6%97%A5%E5%BF%97)
    * [查看任务](#%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1)
  * [无缝更新应用程序](#%E6%97%A0%E7%BC%9D%E6%9B%B4%E6%96%B0%E5%BA%94%E7%94%A8%E7%A8%8B%E5%BA%8F)
  * [关闭服务和集群](#%E5%85%B3%E9%97%AD%E6%9C%8D%E5%8A%A1%E5%92%8C%E9%9B%86%E7%BE%A4)
  * [本节命令汇总](#%E6%9C%AC%E8%8A%82%E5%91%BD%E4%BB%A4%E6%B1%87%E6%80%BB-2)
* [docker 集群](#docker-%E9%9B%86%E7%BE%A4)
  * [创建集群](#%E5%88%9B%E5%BB%BA%E9%9B%86%E7%BE%A4)
    * [创建VM虚拟机](#%E5%88%9B%E5%BB%BAvm%E8%99%9A%E6%8B%9F%E6%9C%BA)
    * [查看虚拟机和ip地址](#%E6%9F%A5%E7%9C%8B%E8%99%9A%E6%8B%9F%E6%9C%BA%E5%92%8Cip%E5%9C%B0%E5%9D%80)
    * [初始化集群](#%E5%88%9D%E5%A7%8B%E5%8C%96%E9%9B%86%E7%BE%A4)
    * [添加集群节点](#%E6%B7%BB%E5%8A%A0%E9%9B%86%E7%BE%A4%E8%8A%82%E7%82%B9)
    * [查看机器节点信息](#%E6%9F%A5%E7%9C%8B%E6%9C%BA%E5%99%A8%E8%8A%82%E7%82%B9%E4%BF%A1%E6%81%AF)
    * [脱离集群](#%E8%84%B1%E7%A6%BB%E9%9B%86%E7%BE%A4)
  * [在集群上部署应用](#%E5%9C%A8%E9%9B%86%E7%BE%A4%E4%B8%8A%E9%83%A8%E7%BD%B2%E5%BA%94%E7%94%A8)
    * [配置shell](#%E9%85%8D%E7%BD%AEshell)
    * [编排部署应用](#%E7%BC%96%E6%8E%92%E9%83%A8%E7%BD%B2%E5%BA%94%E7%94%A8)
    * [访问集群应用](#%E8%AE%BF%E9%97%AE%E9%9B%86%E7%BE%A4%E5%BA%94%E7%94%A8)
    * [扩展集群应用](#%E6%89%A9%E5%B1%95%E9%9B%86%E7%BE%A4%E5%BA%94%E7%94%A8)
  * [清理和重启集群应用](#%E6%B8%85%E7%90%86%E5%92%8C%E9%87%8D%E5%90%AF%E9%9B%86%E7%BE%A4%E5%BA%94%E7%94%A8)
    * [暂停应用程序](#%E6%9A%82%E5%81%9C%E5%BA%94%E7%94%A8%E7%A8%8B%E5%BA%8F)
    * [堆栈和集群](#%E5%A0%86%E6%A0%88%E5%92%8C%E9%9B%86%E7%BE%A4)
    * [取消变量设置](#%E5%8F%96%E6%B6%88%E5%8F%98%E9%87%8F%E8%AE%BE%E7%BD%AE)
    * [重启docker 虚拟机](#%E9%87%8D%E5%90%AFdocker-%E8%99%9A%E6%8B%9F%E6%9C%BA)
  * [本节命令行汇总](#%E6%9C%AC%E8%8A%82%E5%91%BD%E4%BB%A4%E8%A1%8C%E6%B1%87%E6%80%BB)
* [docker 服务编排](#docker-%E6%9C%8D%E5%8A%A1%E7%BC%96%E6%8E%92)
  * [部署可视化工具服务](#%E9%83%A8%E7%BD%B2%E5%8F%AF%E8%A7%86%E5%8C%96%E5%B7%A5%E5%85%B7%E6%9C%8D%E5%8A%A1)
    * [编写 docker\-compose\.yml](#%E7%BC%96%E5%86%99-docker-composeyml)
    * [配置shell](#%E9%85%8D%E7%BD%AEshell-1)
    * [编排部署服务](#%E7%BC%96%E6%8E%92%E9%83%A8%E7%BD%B2%E6%9C%8D%E5%8A%A1)
    * [预览编排服务工具](#%E9%A2%84%E8%A7%88%E7%BC%96%E6%8E%92%E6%9C%8D%E5%8A%A1%E5%B7%A5%E5%85%B7)
  * [部署存储数据服务](#%E9%83%A8%E7%BD%B2%E5%AD%98%E5%82%A8%E6%95%B0%E6%8D%AE%E6%9C%8D%E5%8A%A1)
    * [编写 docker\-compose\.yml](#%E7%BC%96%E5%86%99-docker-composeyml-1)
    * [创建\./data目录](#%E5%88%9B%E5%BB%BAdata%E7%9B%AE%E5%BD%95)
    * [配置 shell](#%E9%85%8D%E7%BD%AE-shell)
    * [编排部署服务](#%E7%BC%96%E6%8E%92%E9%83%A8%E7%BD%B2%E6%9C%8D%E5%8A%A1-1)
    * [预览编排服务](#%E9%A2%84%E8%A7%88%E7%BC%96%E6%8E%92%E6%9C%8D%E5%8A%A1)
* [参考文档](#%E5%8F%82%E8%80%83%E6%96%87%E6%A1%A3)

本文的是Docker*入门教程* 教你如何：<br/>1. 设置Docker环境<br/>2. 构建一个镜像并将其作为一个容器运行<br/>3. 扩展应用程序以运行多个容器<br/>4. 在整个集群中分配应用程序<br/>5. 通过添加后端数据库来堆叠编排服务<br/>6. 将应用部署到生产

   ​

# docker 概述

docker是开发人员和系统管理员 使用容器**开发、部署和运行**应用程序的平台。使用Linux容器来部署应用程序称为*容器化*。容器并不是新的，但它们用于轻松部署应用程序。

容器化越来越受欢迎，容器的优点有：

- **灵活：** 即使是最复杂的应用程序也可以进行容器化。
- **轻量级：** 容器利用并共享主机内核。
- **可互换：** 您可以即时部署更新和升级。
- **便携式：** 您可以在本地构建，部署到云中并在任何地方运行。
- **可扩展性：** 您可以增加和自动分发容器副本。
- **可堆叠编排：** 您可以垂直堆叠编排服务并即时编排堆叠服务。




## 镜像和容器

通过运行镜像启动容器。一个**镜像**是一个可执行的包，其中包括运行应用程序代码所需的所有内容、运行时、库、环境变量和配置文件。

**容器**是镜像的运行时实例，当被执行时（即镜像的状态或者用户进程）在容器中变得可以监控查看。您可以使用该命令`docker ps`查看正在运行的镜像列表。



## 容器和虚拟机

一个**容器**中运行*原生* `Linux`和共享主机与其它容器的内核。它运行一个独立的进程，不占用任何其他可执行文件的内存，使其轻量化。

相比之下，**虚拟机**（`VM`）运行一个完整的“客户”操作系统，通过虚拟机管理程序*虚拟*访问主机资源。一般来说，虚拟机提供的环境比大多数应用程序需要的资源更多。




# docker 安装

docker版本众多，这里介绍`Windows`下如何下载安装。在`Win7`系统上，docker安装需要使用`docker toolbox`，而`Win10`则直接使用`docker CE`，还有企业版的 `docker EE`。



## 下载

`Win10 docker CE`下载地址：https://docs.docker.com/docker-for-windows/install/ <br/>`Win 7 Docker Toolbox` 下载地址：https://docs.docker.com/toolbox/overview/ <br/>

以上选择你的平台的下载链接即可下载



`docker toolbox` 是旧版系统使用的`docker`安装包，`toolbox`包含以下工具：

> 工具箱包括这些Docker工具：
>
> - `Docker Machine`用于运行`docker-machine`命令，用来操作虚拟机
> - `Docker Engine`用于运行`docker`命令
> - `Docker Compose`用于运行这些`docker-compose`命令
> - `Kitematic`，`Docker GUI`图形界面
> - 一个为`Docker`命令行环境预配置的shell
> - `Oracle VirtualBox`
> - `Git`
>
> 例如，您可以在[Toolbox Releases](https://github.com/docker/toolbox/releases)上找到各种版本的工具，或者使用`--version`终端中的标志运行它们`docker-compose --version`。

`docker toolbox`使用的`VM`是`VirtualBox`，而`Win 10` 系统的`docker`使用的`VM`则是`Hyper-V`



## 安装

安装很简单，直接下一步，其中有一个选项则是选择安装工具，如果你的电脑安装过`Git`和`VirtualBox`的可以不选这两个选项。其他的直接下一步完成即可。

找到docker安装目录，在目录下会有一个`start.sh`，使用`Git bash`运行这个脚本。双击脚本会执行启动docker程序操作，这个过程可能有点慢。

```shell
$ cd E:\Docker Toolbox
$ sh start.sh
```

当运行`start.sh`后会自动检查`boot2docker.iso`的最新版本，会提示下载最新的`boot2docker.iso`，这个时候程序自动回去`github`上进行下载。可以看到窗口日志

```shell
Running pre-create checks...
(manager) Default Boot2Docker ISO is out-of-date, downloading the latest release...
(manager) Latest release for github.com/boot2docker/boot2docker is v1.11.2
(manager) Downloading C:\Users\Administrator\.docker\machine\cache\boot2docker.iso from https://github.com/boot2docker/boot2docker/releases/download/v1.18.2/boot2docker.iso...
Error with pre-create check: "Get https://github-cloud.s3.amazonaws.com/releases/ 
...

The process cannot access the file because it is being used by another process.
(default)
Error with pre-create check: "read tcp 10.3.73.28:7668->52.216.225.248:443: wsarecv: An existing connection was forcibly closed by the remote host."
Looks like something went wrong in step ´Checking if machine default exists´... 
Press any key to cont   
```

如果下载完成后还是无法启动，可以手动下载`boot2docker.iso`，下载地址在错误日志中有，我这里的地址是：https://github.com/boot2docker/boot2docker/releases/download/v1.18.2/boot2docker.iso 这个地址来自于上面的日志，每个人可能版本号不一致。所以要以日志里的为准，然后去下载这个`boot2docker.iso`。下载完成后，将文件放置在`C:\Users\Administrator\.docker\machine\cache\`目录下，这个地址也是来自于上面的错误日志。

> 网上还说有另一种解决办法，就是将docker toolbox安装目录的`boot2docker.iso`复制到`C:\Users\Administrator\.docker\machine\cache\`目录下，然后**断掉网络**在运行`start.sh`脚本就不会去检查了。



将以上步骤完成后，再运行`start.sh`应该就可以成功启动了，启动后画面类似如下

```shell
Administrator@hoojo-pc MINGW64 /e/Docker Toolbox
$ sh start.sh
Starting "default"...
(default) Check network to re-create if needed...
(default) Windows might ask for the permission to configure a dhcp server. Sometimes, such confirmation window is minimized in the taskbar.
(default) Waiting for an IP...
Machine "default" was started.
Waiting for SSH to be available...
Detecting the provisioner...
Started machines may have new IP addresses. You may need to re-run the `docker-machine env` command.
Regenerate TLS machine certs?  Warning: this is irreversible. (y/n): Regenerating TLS certificates
Waiting for SSH to be available...
Detecting the provisioner...
Copying certs to the local machine directory...
Copying certs to the remote machine...
Setting Docker configuration on the remote daemon...


                        ##         .
                  ## ## ##        ==
               ## ## ## ## ##    ===
           /"""""""""""""""""\___/ ===
      ~~~ {~~ ~~~~ ~~~ ~~~~ ~~~ ~ /  ===- ~~~
           \______ o           __/
             \    \         __/
              \____\_______/

docker is configured to use the default machine with IP 192.168.99.100
For help getting started, check out the docs at https://docs.docker.com


Start interactive shell
```

看到上面的画面就启动成功了，下面可以开始命令行操作。<br/>docker is configured to use the default machine with IP 192.168.99.100<br/>这条信息就是docker虚拟机对应的`	ip`地址

> 当然，你也可以使用docker GUI界面图形的方式去启动docker。在安装完成后，可以双击桌面上的`a`图标，点击启动就可以启动docker了。启动后，如果你有docker云端账号，登陆上去还可以进行云端镜像管理操作。点击左下角的`Docker CLI`就可以开启命令行窗口。



## 测试

继续在上面的窗口输入命令行，或者打开电脑中的`dos`命令行窗口 `cmd`，或者是使用`powershell`、`git`、`xshell`都可以。这里使用`git bash`窗口进行操作。

输入命令行`docker --version`，查看版本

```shell
$ docker --version
Docker version 18.03.0-ce, build 0520e24302
```

看到以上版本信息说明docker安装正确，无问题。

输入命令行`docker version`，查看更多版本信息

```shell
$ docker version
Client:
 Version:       18.03.0-ce
 API version:   1.37
 Go version:    go1.9.4
 Git commit:    0520e24302
 Built: Fri Mar 23 08:31:36 2018
 OS/Arch:       windows/amd64
 Experimental:  false
 Orchestrator:  swarm

Server:
 Engine:
  Version:      18.04.0-ce
  API version:  1.37 (minimum version 1.12)
  Go version:   go1.9.4
  Git commit:   3d479c0
  Built:        Tue Apr 10 18:23:35 2018
  OS/Arch:      linux/amd64
  Experimental: false
```

输入命令行`docker info`，查看info信息

```shell
$ docker info
Containers: 0
 Running: 0
 Paused: 0
 Stopped: 0
Images: 0
Server Version: 18.04.0-ce
Storage Driver: aufs
 Root Dir: /mnt/sda1/var/lib/docker/aufs
 Backing Filesystem: extfs
 Dirs: 0
 Dirperm1 Supported: true
Logging Driver: json-file
Cgroup Driver: cgroupfs
Plugins:
 Volume: local
 Network: bridge host macvlan null overlay
 Log: awslogs fluentd gcplogs gelf journald json-file logentries splunk syslog
Swarm: inactive
Runtimes: runc
Default Runtime: runc
Init Binary: docker-init
containerd version: 773c489c9c1b21a6d78b5c538cd395416ec50f88
runc version: 4fc53a81fb7c994640722ac585fa9ca548971871
init version: 949e6fa
Security Options:
 seccomp
  Profile: default
Kernel Version: 4.9.93-boot2docker
Operating System: Boot2Docker 18.04.0-ce (TCL 8.2.1); HEAD : b8a34c0 - Wed Apr 11 17:00:55 UTC 2018
OSType: linux
Architecture: x86_64
CPUs: 1
Total Memory: 995.6MiB
Name: default
ID: XADN:VFBU:3C4G:D3YG:BZ5P:4ZX6:TP34:55MN:PM3J:KMEL:KLYA:4OUU
Docker Root Dir: /mnt/sda1/var/lib/docker
Debug Mode (client): false
Debug Mode (server): false
Registry: https://index.docker.io/v1/
Labels:
 provider=virtualbox
Experimental: false
Insecure Registries:
 127.0.0.0/8
Live Restore Enabled: false
```

介绍了一下docker的基本配置信息，包括重要的容器信息、镜像信息、存储目录等。

ssh链接到指定虚拟机，可以打开本地`vbox`软件，看看哪些虚拟机，然后利用`docker-machine ssh`去打开

```shell
$ docker-machine ssh default
```



## 镜像加速

### **Ubuntu系统加速**

------

```shell
sudo mkdir -p /etc/docker
sudo tee /etc/docker/daemon.json <<-'EOF'
{
  "registry-mirrors": ["https://8kzs1r91.mirror.aliyuncs.com"]
}
EOF
sudo systemctl daemon-reload
sudo systemctl restart docker
```



### **Win 7 如何配置镜像加速器**

------

针对安装了`Docker Toolbox`的用户，您可以参考以下配置步骤：
创建一台安装有Docker环境的`Linux`虚拟机，指定机器名称为`default`，同时配置Docker加速器地址。

```shell
$ docker-machine create --engine-registry-mirror=https://8kzs1r91.mirror.aliyuncs.com -d virtualbox default
```

对于已经安装创建过虚拟机的，可以先`docker-machine ssh default`链接到`default`虚拟机如下处理

```shell
$ sudo sed -i "s|EXTRA_ARGS='|EXTRA_ARGS='--registry-mirror=https://8kzs1r91.mirror.aliyuncs.com |g" /var/lib/boot2docker/profile

# 退出
$ exit
# 重启虚拟机
$ docker-machine restart default
```



查看机器的环境配置，并配置到本地，并通过Docker客户端访问Docker服务。

```shell
$ docker-machine env default
$ eval "$(docker-machine env default)"
$ docker info
```

针对安装了`Docker for Windows`的用户，您可以参考以下配置步骤：
在系统右下角托盘图标内右键菜单选择 `Settings`，打开配置窗口后左侧导航菜单选择 `Docker Daemon`。编辑窗口内的`JSON`串，填写加速器地址，如下所示：

```shell
{
  "registry-mirrors": ["https://8kzs1r91.mirror.aliyuncs.com"]
}
```

编辑完成，点击 `Apply` 保存按钮，等待Docker重启并应用配置的镜像加速器。



## 本节命令汇总

```shell
## List Docker CLI commands
docker
docker container --help

## 显示docker版本和信息
docker --version
docker version
docker info

## Execute Docker image 运行镜像
docker run hello-world

## List Docker images 查看所有镜像
docker image ls

## List Docker containers (running, all, all in quiet mode)
docker container ls							# 查看正在运行的容器
docker container ls --all					# 查看所有容器
docker container ls -aq						# 查看未运行的容器
docker-machine restart default				# 重启虚拟机

$ docker-machine ssh default 				# ssh 连接到default这台虚拟机
```



# docker 容器

## 基本命令

### 运行`hello world`示例

---

从`docker hub`上拉取`hello world`示例(https://hub.docker.com/r/library/hello-world/)并运行

```shell
$ docker run hello-world
Unable to find image 'hello-world:latest' locally
latest: Pulling from library/hello-world
9bb5a5d4561a: Pulling fs layer
9bb5a5d4561a: Verifying Checksum
9bb5a5d4561a: Download complete
9bb5a5d4561a: Pull complete
Digest: sha256:bbdaf0ed64b665f3061aeab15b946697dd00845161935d9238ed28e8cfc2581c
Status: Downloaded newer image for hello-world:latest

Hello from Docker!
This message shows that your installation appears to be working correctly.

省略其他。。。。。。
```

由于docker的`hello world`示例镜像在docker的官网，可能需要翻墙并且速度慢，这里可以使用国内阿里镜像，打开本地的刚才安装好的虚拟机`Oracle VM VirtualBox`，找到`default`。这时`default`已经在运行，直接右键点击**显示**即可，然后输入命令

```shell
$ cd /etc/docker
$ vi daemon.json
{
  "registry-mirrors": ["https://registry.docker-cn.com"]
}
```

> 在`daemon.json`中加入上面的配置即可加速

​

### 查看已经安装的镜像

---

输入命令行`docker images` 或者 `docker image ls`

```shell
$ docker image ls
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
hello-world         latest              e38bc07ac18e        37 hours ago        1.85kB
```
### 查看镜像运行历史

---

输入命令行查看镜像运行的历史情况

```shell
$ docker image history composesample_webapp
```

### 查看运行过的容器信息

---

输入命令行`docker container ls --all`，如果查看正在运行的镜像可以用`docker container ls`

```shell
$ docker container ls --all
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS                     PORTS               NAMES
ff46aa1e0dc6        hello-world         "/hello"            9 minutes ago       Exited (0) 9 minutes ago                       priceless_vaughan

```


### 查看运行过的容器`ID`信息

---

输入命令行`docker container ls -aq`

```shell
$ docker container ls -aq
ff46aa1e0dc6
```


## 创建镜像容器

从程序最底层构建`docker`容器，当我们运行`python`程序的时候，首先需要安装`python`的`sdk`库用来支撑程序的运行。这个时候你的环境在安装这些程序的时候会有各种差异导致版本冲突，并且在你安装好后也许和生产环境的版本不一致或者存在差异。

使用`docker`可以很好的解决上面描述的问题，`docker`可以很好的将一个可以移植的`python`环境当成一个镜像进行运行。你只需用构建一个可以运行`python`和你的`python`代码程序，以及包含其他依赖配置的镜像就可以让这个打包程序在所有存在`docker`的环境进行运行。



下面将演示如何构建自己机器上可以运行`python`的`docker`镜像

### 定义镜像容器的`Dockerfile`

---

`Dockerfile`定义容器内环境中做了些什么。在镜像环境中需要访问网络接口和磁盘驱动器等资源，这些资源与系统其余部分是隔离的，因此需要将端口映射到外部，并明确要将哪些文件“复制”到镜像环境。在完成这些之后，可以让构建 `Dockerfile`的应用程序在任何机器上都可以运行。

在目标位置`/d/docker/python_sample`创建`Dockerfile`文件，粘贴一下内容，命令如下：

```shell
$ mkdir docker
$ cd docker/
$ mkdir python_sample
$ cd python_sample/

$ vi Dockerfile
```

将下面的文本内容粘贴至 `Dockerfile`

```dockerfile
# Use an official Python runtime as a parent image
FROM python:2.7-slim
# Set the working directory to /app
WORKDIR /app
# Copy the current directory contents into the container at /app
ADD . /app
# Install any needed packages specified in requirements.txt
RUN pip install --trusted-host pypi.python.org -r requirements.txt
# Make port 80 available to the world outside this container
EXPOSE 80
# Define environment variable
ENV NAME World
# Run app.py when the container launches
CMD ["python", "app.py"]
```

> 上面的文件是docker镜像需要的文件内容和依赖，其中有`requirements.txt`、`app.py`，其他的是配置信息。从上面的注释可以看到：
>
> 利用官方的`Python`作为父镜像<br/>设置工作目录为 `/app`<br/>将当前目录下的内容复制到上面的 `app`目录中<br/>安装`requirements.txt`中指定的所有必需软件包<br/>提供对外端口：`80`<br/>定义系统变量<br/>执行命令行 `python app.py`来运行`app.py`python程序脚本<br/>



### 编写镜像中的程序

---

由于上面的 `Dockerfile`定义好了镜像的内容，这里需要对文件中的内容进行填充。

创建两个文件，`requirements.txt`、`app.py`将它们放在和`Dockerfile`同一个文件夹中。完成应用程序的编码部分，这个取决于你的镜像需要运行什么代码内容。当上述`Dockerfile`被内置到的镜像，`app.py`和 `requirements.txt`是因为存在`Dockerfile`文件的`ADD`命令中，而端口`80`是`app.py`是通过HTTP访问需要的，这个暴露端口需要使用`EXPOSE` 命令。而系统变量`ENV NAME World`则是`app.py`中需要访问的变量值。

还是在`Dockerfile`同一个文件夹中创建`requirements.txt`文件，添加当前python程序的依赖软件

```shell
$ vi requirements.txt
Flask
Redis
```

创建`app.py`文件，内容如下

```python
from flask import Flask
from redis import Redis, RedisError
import os
import socket

# Connect to Redis
redis = Redis(host="redis", db=0, socket_connect_timeout=2, socket_timeout=2)

app = Flask(__name__)

@app.route("/")
def hello():
    try:
        visits = redis.incr("counter")
    except RedisError:
        visits = "<i>cannot connect to Redis, counter disabled</i>"

    html = "<h3>Hello {name}!</h3>" \
           "<b>Hostname:</b> {hostname}<br/>" \
           "<b>Visits:</b> {visits}"
    return html.format(name=os.getenv("NAME", "world"), hostname=socket.gethostname(), visits=visits)

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=80)
```

从上面的代码可以看出程序依赖了`from flask import Flask`,`from redis import Redis`，并且访问了系统变量`os.getenv("NAME", "world")`，程序运行的端口是`app.run(host='0.0.0.0', port=80)`。这就是`requirements.txt` 和 `Dockerfile`文件内容的原因了。

现在我们看到`pip install -r requirements.txt`为Python安装`Flask`和`Redis`库，并且该应用程序输出环境变量`NAME`以及调用的输出`socket.gethostname()`。最后，因为`Redis`没有运行（因为我们只安装了Python的`Redis`库，而没有`Redis`），所以在这里会失败并发生错误异常消息。



### 构建镜像程序

---

通过上面的准备，现在可以构建应用的镜像程序工作，利用`docker build`来构建镜像，命令行如下：

```shell
$ docker build -t myhello .
Sending build context to Docker daemon  4.608kB
Step 1/7 : FROM python:2.7-slim
2.7-slim: Pulling from library/python
b0568b191983: Pulling fs layer
55a7da9473ae: Pulling fs layer
422d2e7f1272: Pulling fs layer
8fb86f1cff1c: Pulling fs layer
8fb86f1cff1c: Waiting
55a7da9473ae: Verifying Checksum
55a7da9473ae: Download complete
8fb86f1cff1c: Verifying Checksum
8fb86f1cff1c: Download complete
422d2e7f1272: Verifying Checksum
422d2e7f1272: Download complete
b0568b191983: Verifying Checksum
b0568b191983: Download complete
b0568b191983: Pull complete
55a7da9473ae: Pull complete
422d2e7f1272: Pull complete
8fb86f1cff1c: Pull complete
Digest: sha256:9e24a026a55ca1d9a7284db30ed846b7190a3d7f557edf493b454bff362ed64c
Status: Downloaded newer image for python:2.7-slim
.......
```

上面的命令行`docker build -t myhello .`是构建一个`myhello`的镜像，镜像的内容就是当前目录下的文件内容。上面的提示可以看到有7个步骤，后面的信息没有贴出来。



### 查看已经安装的镜像程序

---

```shell
$ docker image ls
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
myhello             latest              75be173204aa        9 minutes ago       150MB
hello-world         latest              e38bc07ac18e        38 hours ago        1.85kB
python              2.7-slim            b16fde09c92c        3 weeks ago         139MB
```



### 运行镜像程序

---

```shell
$ docker run -p 4000:80 myhello
 * Running on http://0.0.0.0:80/ (Press CTRL+C to quit)
```

上面的命令是将镜像程序发布出去，其中的80端口映射的4000端口上，通过docker关联的虚拟机的`ip`地址就可以访问到当前镜像应用。



### 查看`ip`地址

---

```shell
 $ docker-machine ip
 192.168.99.100
```



### 测试镜像程序

---

访问：http://192.168.99.100:4000/

```html
Hello World!
Hostname: 77e422fa3978
Visits: cannot connect to Redis, counter disabled
```

或者在虚拟机上运行命令行查看

```shell
$ curl http://localhost:4000

<h3>Hello World!</h3><b>Hostname:</b> 8fc990912a14<br/><b>Visits:</b> <i>cannot connect to Redis, counter disabled</i>
```



### 停止运行的镜像程序

---

利用`docker container ls`查看正在运行的镜像，利用`docker container stop [CONTAINER ID]`停止镜像

```shell
$ docker container ls
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS                  NAMES
77e422fa3978        myhello             "python app.py"     22 minutes ago      Up 22 minutes       0.0.0.0:4000->80/tcp   elated_ptolemy
```

```shell
# 停止匹配的
$ docker container stop "docker container ps | grep myhello | awk '{print $1}'"
# 停止所有的
$ docker container stop $(docker container ps -q)
# 只停止退出的容器：
$ docker container ps -a -f "exited=-1"
# 停止特定的
$ docker container stop 77e422fa3978
77e422fa3978
```



### 重启容器程序

---

格式是`-p hostPort:containerPort`。该选项将主机上的端口映射到容器中的端口。这允许我们访问主机上指定端口上的容器

```shell
docker container run -d -p 4000:80 --name myhello_container myhello
```



### 删除容器

---

通过id或名称删除特定容器：

```shell
$ docker container rm <CONTAINER_ID>
$ docker container rm <NAME>
```

删除符合正则表达式的容器

```shell
$ docker container ps -a | grep hello | awk '{print $1}' | xargs docker container rm
```

删除所有容器，没有任何标准

```shell
$ docker container rm $(docker container ps -aq)
```



### 在后台运行镜像程序

---

 `docker run -d`分离模式在后台运行应用程序，命令行如下

  ```shell
$ docker run -d -p 4000:80 myhello
# docker container run -d -p 4000:80 myhello
# docker container run -d -P --name myhello_container myhello
faf0d327cb8ba130fb69cd7719c8d2732ebe6f3f223e93afa68bc7b9e612b429
  ```

上面返回的一段id是容器运行的id，也可以通过命令`docker container ls`查看短id

  ```shell
$ docker container stop faf0d327cb8ba130fb69cd7719c8d2732ebe6f3f223e93afa68bc7b9e612b429
  ```



### 交互式运行容器

---

以交互模式运行apache容器。

```shell
$ docker container run -it apache
```



### 后台独立容器模式

---

以分离模式重新启动容器：

```shell
$ docker container run -d apache
254418caddb1e260e8489f872f51af4422bc4801d17746967d9777f565714600
```



### 查看容器日志

---

使用命令行：`docker container logs -f <ID | name> `可以查看容器运行的日志模式，适合在新窗口或者后天模式情况下运行。

```shell
$ docker container logs -f sad_ptolemy
 * Running on http://0.0.0.0:80/ (Press CTRL+C to quit)

```



### 统计监控

---

可以查看容器的资源(CPU、内存、网络、硬盘、进程ID)占用情况

```shell
$ docker container stats sad_ptolemy
$ docker stats
$ docker container stats --format "{{.Container}}: {{.CPUPerc}}"
```




## 分享镜像

分享镜像就是将个人的镜像推送到docker云端，这样大家都可以进行拉取共享使用。docker云端和`github`有些类似，在使用云端之前需要先注册，注册地址：[cloud.docker.com](https://cloud.docker.com/)。国内阿里镜像地址：https://dev.aliyun.com/

### 登陆docker 云端

---

利用命令行`docker login `进行登陆，其中`-u` 代表`username`，`-p` 是密码

```shell
$ docker login -p xxxx -u xxxx
WARNING! Using --password via the CLI is insecure. Use --password-stdin.
Login Succeeded

# 或者登陆其他仓库
$ sudo docker login --username=xxx -p xxxx registry.cn-hangzhou.aliyuncs.com
$ winpty docker login --username xxx registry.cn-hangzhou.aliyuncs.com
```


### 登出docker 云端

---

```shell
$ docker logout
```



### 建立标签

---

建立一个镜像的标签，方便于查看和管理

命令行`docker tag image username/repository:tag`，其中`image`代表镜像的名称、 `username`代表用户id、`repository`表示集合仓库名称、`tag`则是标签名称。若是第三方仓库则需要带仓库地址，同时`useranme`部分在阿里仓库中被称为**命名空间**，而且需要手动创建。示例如下：

```shell
# docker tag image username/repository:tag
# 为其他仓库打标签
# docker tag [ImageId] registry.cn-hangzhou.aliyuncs.com/username_namespace/repository:[tag]

$ docker tag myhello hoojo/test:my_hello_world

$ docker image ls
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
hoojo/test          my_hello_world      75be173204aa        About an hour ago   150MB
myhello             latest              75be173204aa        About an hour ago   150MB
hello-world         latest              e38bc07ac18e        39 hours ago        1.85kB
python              2.7-slim            b16fde09c92c        3 weeks ago         139MB
```

通过上面的命令发现多了一个镜像，就是刚才标签过的。注意看`REPOSITORY`，`TAG`

### 提交镜像

---

提交镜像到云端仓库。使用命令行`docker push`来进行推送，整个推送可能很慢，由于是国外的网站。若使用国内阿里镜像则需要在前面带上仓库地址`registry.cn-hangzhou.aliyuncs.com/hoojo/test:my_hello_world`

```shell
# 为其他仓库push
# docker push registry.cn-hangzhou.aliyuncs.com/hoojo/test:my_hello_world

$ docker push hoojo/test:my_hello_world
The push refers to repository [docker.io/hoojo/test]
0c5f092b929e: Preparing
9a6b4154e4ff: Preparing
b475497029b3: Preparing
d99e7ab4a34b: Preparing
332873801f89: Preparing
2ec65408eff0: Preparing
43efe85a991c: Preparing
```

推送完成后可以去`docker`云端看下有没有：https://cloud.docker.com/swarm/your-username/repository/list



## 运行远程云端的镜像

从现在开始，您可以使用`docker run`此命令在任何机器上使用并运行远程的应用程序：

```shell
docker run -p 4000:80 username/repository:tag

$ docker run -p 4000:80 hoojo/test:my_hello_world
 * Running on http://0.0.0.0:80/ (Press CTRL+C to quit)
```

这样就把云镜像端程序运行在本地了，如果本地没有当前需要的镜像程序，则`docker`会在远程拉取程序到本地进行运行。无论在哪里`docker run`执行，它都会将会下载`Python`以及所有依赖项从中拉出`requirements.txt`，然后运行镜像中的代码。它们都在一个整体小包中一起运行，你不需要在主机上安装任何东西来让`docker`运行它。



## 本节命令汇总

```shell
docker build -t friendlyhello .  # 使用此目录的Dockerfile创建镜像
docker run -p 4000:80 friendlyhello  # 运行“friendlyname”映射端口4000到80
docker run -d -p 4000:80 friendlyhello         # 同上，但处于分离模式
docker run --detach --publish 4000:80 --name webserver nginx
docker ps                               # 列出所有正在运行的容器
docker container ls                                # 列出所有正在运行的容器
docker container ls -a             	# 列出所有容器，即使那些没有运行的容器
docker container stop <hash>           # 停止指定的容器
docker container kill <hash>         # 强制关闭指定的容器
docker container rm <hash>        	# 从本机中移除指定的容器
docker container rm $(docker container ls -a -q)         # 删除所有容器
docker image ls -a                             # 列出此机器上的所有镜像
docker image rm <image id>            # 从本机中删除指定的镜像
docker image rm $(docker image ls -a -q)   # 从本机中删除所有镜像
docker images myhello                      # 通过仓库查看镜像
docker login             					# 登录
docker tag <image> username/repository:tag  # 标签<image>用于上传到仓库
docker push username/repository:tag            # 上传标记的镜像到仓库
docker run username/repository:tag                   # 从仓库运行镜像，本地没有会先拉取镜像
docker push registry/username/repository:tag 
docker run registry/username/repository:tag

docker-machine ssh default 					# ssh 链接到虚拟机 default
docker-machine ip 							# 查看虚拟机ip地址
```



# docker 服务

在分布式应用程序中，应用程序的不同部分被称为“服务”。例如，如果您想象一个视频共享网站，它可能包含一个用于将应用程序数据存储在数据库中的服务，一个用于在后台进行视频转码的服务用户上传的东西，前端的服务等等。服务会更改运行该软件的容器实例的数量，从而为流程中的服务分配更多计算资源，**这就相当于在一台机器上部署了一套服务的集群，提高了服务的并发和高性能**。

幸运的是，使用Docker平台定义，运行和扩展服务非常简单 - 只需编写一个`docker-compose.yml`文件即可。



## 配置 `docker-compose.yml`文件

`docker-compose.yml`文件是一个`YAML`文件，它定义了Docker容器在生产中的配置方式。

在任意目录位置创建文件`docker-compose.yml`，并粘贴如下内容

```shell
version: "3"
services:
  web:
    # replace username/repo:tag with your name and image details
    # pull image 拉取文件，这里对应远程仓库中的镜像
    image: hoojo/test:my_hello_world 
    deploy:
      replicas: 5
      resources:
        limits:
          cpus: "0.1"
          memory: 50M
      restart_policy:
        condition: on-failure
    ports:
      - "80:80"
    networks:
      - webnet
networks:
  webnet:
```

> 该`docker-compose.yml`文件告诉Docker执行以下操作：
>
> - 从注册表中拉出[我们在步骤2中上传的镜像](https://docs.docker.com/get-started/part2/)。
> - 运行该镜像的`5`个实例作为所调用的服务`web`，限制每个实例使用最多`10％`的`CPU`（跨所有核心）和`50MB`的`RAM`。
> - 如果一个失败，立即重启容器。
> - 将主机上的端口80映射到`web`端口80。
> - `web`通过称为负载平衡的网络指示容器共享端口80 `webnet`。（在内部，容器本身`web`在临时端口上发布到 80端口。）
> - `webnet`使用默认设置定义网络（这是一个负载平衡覆盖网络）。



## 运行负载平衡应用程序

### 启动集群

---

在使用`docker stack deploy`命令进行部署之前，首先运行如下命令

```shell
$ docker swarm init
Error response from daemon: could not choose an IP address to advertise since this system has multiple addresses on different interfaces (10.0.2.15 on eth0 and 192.168.99.100 on eth1) - specify one with --advertise-addr
```

出现以上问题后可以按照说明解决，解决方法如下

```shell
$ docker swarm init --advertise-addr eth1
# or
$ docker swarm init --advertise-addr 192.168.99.100
# or
$ docker swarm init --listen-addr 192.168.99.100:2377 --advertise-addr 192.168.99.100:2377
```



### 部署服务

---

现在正式部署镜像程序，将部署后的程序服务命名为：`run_hello`。创建网络`run_hello_webnet`，创建服务`run_hello_web`

```shell
$ docker stack deploy -c docker-compose.yml run_hello
Creating network run_hello_webnet
Creating service run_hello_web
```



### 扩展服务

---

将服务的副本扩展成指定数量

```shell
$ docker service scale run_hello_web=3
```



### 查看服务

---

我们在单个堆栈上将一个镜像程序部署在一个主机上运行`5`个实例的服务。查看服务列表：

```shell
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE                       PORTS
6vtacv7c9tq5        run_hello_web       replicated          5/5                 hoojo/test:my_hello_world   *:80->80/tcp
```

默认服务名称会在之前部署在堆栈`docker stack deploy -c docker-compose.yml run_hello`的时候的名称后面加上`web`，这里的服务名称应该是 `run_hello_web`。还列出了服务`ID`以及副本数，映射的名称和已公开端口。



### 查看服务详细

---

可以使用获得有关该服务的详细信息`docker service inspect run_hello_web`

```shell
$ docker service inspect run_hello_web
[
    {
        "ID": "36ij4xn4o4eoyde25zw86a9ty",
        "Version": {
            "Index": 14
        },
........
```



### 查看服务日志

---

可以使用`docker service logs -f run_hello_web`以下方式查看服务日志

```shell
$ docker service logs -f deploy_test_wordpress
deploy_test_wordpress.2.9y4wqd0sjm0k@default    | WordPress not found in /var/www/html - copying now...
deploy_test_wordpress.1.w38hwe65px6q@default    | WordPress not found in /var/www/html - copying now...
```



### 查看任务

---

在服务中运行的单个容器称为**任务**。任务的的`id`是一个定量增加的数据，这个定量取决于在文件`docker-compose.yml`配置的`replicas` 的数量。查看服务的任务：

```shell
$ docker service ps run_hello_web
ID                  NAME                IMAGE                       NODE                DESIRED STATE       CURRENT STATE           ERROR               PORTS
ksy1vbv0t4qf        run_hello_web.1     hoojo/test:my_hello_world   default             Running             Running 5 minutes ago
b38a3x3pjym5        run_hello_web.2     hoojo/test:my_hello_world   default             Running             Running 5 minutes ago
x8syohl5prfs        run_hello_web.3     hoojo/test:my_hello_world   default             Running             Running 5 minutes ago
z8k0wsfecw49        run_hello_web.4     hoojo/test:my_hello_world   default             Running             Running 5 minutes ago
ri68se61gfc2        run_hello_web.5     hoojo/test:my_hello_world   default             Running             Running 5 minutes ago
```



通过查看系统容器列表，也会显示所有的服务任务数据，这些任务无法被过滤

```shell
$ docker container ls -q
CONTAINER ID        IMAGE                       COMMAND             CREATED             STATUS              PORTS               NAMES
540ea1cf9981        hoojo/test:my_hello_world   "python app.py"     15 minutes ago      Up 15 minutes       80/tcp              run_hello_web.1.ksy1vbv0t4qf1g3mfd0x1xonu
1bed6aaa2541        hoojo/test:my_hello_world   "python app.py"     15 minutes ago      Up 15 minutes       80/tcp              run_hello_web.3.x8syohl5prfsyfpao6nf0xrge
97026758b279        hoojo/test:my_hello_world   "python app.py"     15 minutes ago      Up 15 minutes       80/tcp              run_hello_web.5.ri68se61gfc2fski787fdgz34
d30c0bc32ac8        hoojo/test:my_hello_world   "python app.py"     15 minutes ago      Up 15 minutes       80/tcp              run_hello_web.4.z8k0wsfecw49z9zodkbebeoum
354825ff501b        hoojo/test:my_hello_world   "python app.py"     15 minutes ago      Up 15 minutes       80/tcp              run_hello_web.2.b38a3x3pjym5k3w90qyyd2apz
```



直接访问IP地址：http://192.168.99.100 就可以看到镜像运行的结果

```shell
Hello World!
Hostname: 1bed6aaa2541
Visits: cannot connect to Redis, counter disabled
```

通过连续刷新`url`，会发现`hostname`发生变化，这里的`hostname`正是对应上面的`CONTAINER ID`，这就表明5个实例可以任意访问，负载均衡已发生作用。



## 无缝更新应用程序

当我们需要修改`docker-compose.yml`的配置信息，不需要先关闭集群、删除服务、杀死删除容器，只需用修改配置，然后重新部署发布`docker stack deploy`，这样大大的提高了效率、缩短了发布的间歇时间。

比如我们修改`docker-compose.yml`的副本`replicas `数量为`2`，然后重新发布

```shell
$ docker stack deploy -c docker-compose.yml run_hello
Updating service run_hello_web (id: 6vtacv7c9tq5b2m6i0fetan85)
```

上面的日志反馈是更新服务`run_hello_web`，通过目录查看服务容器`docker container ls -q`，会发现少了

```shell
$ docker container ls
CONTAINER ID        IMAGE                       COMMAND             CREATED             STATUS              PORTS               NAMES
540ea1cf9981        hoojo/test:my_hello_world   "python app.py"     29 minutes ago      Up 29 minutes       80/tcp              run_hello_web.1.ksy1vbv0t4qf1g3mfd0x1xonu
354825ff501b        hoojo/test:my_hello_world   "python app.py"     29 minutes ago      Up 29 minutes       80/tcp              run_hello_web.2.b38a3x3pjym5k3w90qyyd2apz

```



## 关闭服务和集群

删除发布在堆栈中的服务`docker stack rm`

```shell
$ docker stack rm run_hello
Removing service run_hello_web
Removing network run_hello_webnet
```

停掉集群

```shell
$ docker swarm leave --force
Node left the swarm.
```

用Docker轻松发布、开启并扩展您的应用程序非常简单。



## 本节命令汇总

```shell
docker stack ls                                      # 程序和堆列表
docker stack deploy -c <compose-yml-file> <appname>  # 部署compose.yml文件到堆
docker service ls                 					# 显示所有在运行的服务程序
docker service ps <service>                  		 # 显示所有程序服务的任务
docker inspect <task or container>                    # 检查任务或容器
docker container ls -q                                # 显示容器 IDs
docker stack rm <appname>                             # 关闭或删除容器程序
docker swarm leave --force      					# 强制关闭节点集群
docker swarm init --advertise-addr eth1               # 启动集群、暴露某个ip地址
```



# docker 集群

将应用程序部署到群集上，并在多台机器上运行它。多容器、多机应用程序通过连接多台机器到称为一个Docker**集群**。

Swarm是一组运行Docker并加入到集群中的机器。下面的Docker命令将由**群集管理器**在群集上执行。群体中的机器可以是物理的或虚拟的。加入群体后的机器被称为**节点**。

Swarm管理人员可以使用多种策略来运行容器，例如“最空节点” —— 它可以使用容器充分利用使用率最低的机器。它确保每台机器只获取指定容器的一个实例。指示集群管理器在`Compose`文件中使用这些策略。

集群管理器是集群中唯一可以执行命令的机器，或者授权其他机器作为**工作者**加入群体。工作者只是在那里提供能力，并没有权力告诉任何其他机器可以做什么和不可以做什么。

到目前为止，已经在本地机器上以单主机模式使用Docker。但是Docker也可以切换到**群集模式**，这就是使用群集的原因。立即启用群模式使当前的机器成为群管理器。从此，Docker将运行在您管理的群集上执行的命令，而不仅仅是在当前机器上执行。



## 创建集群

一个**集群**由多个节点组成，可以是物理机器或虚拟机器。基本概念很简单：运行`docker swarm init`以启用群模式，并使您的当前机器成为**集群管理器**，然后`docker swarm join`在其他机器上运行 ，让它们作为**工作节点**加入群体。我们使用虚拟机来快速创建一个双机集群。

### 创建`VM`虚拟机

---

现在使用`docker-machine`命令和`VirtualBox`驱动程序创建几个`VM `：

```shell
$ docker-machine create --driver virtualbox my-vm-node-1
$ docker-machine create --driver virtualbox my-vm-node-2
```

执行命令后可以看到成功创建虚拟机

```shell
$ docker-machine create --driver virtualbox my-vm-node-1
Running pre-create checks...
Creating machine...
(my-vm-node-1) Copying C:\Users\Administrator\.docker\machine\cache\boot2docker.iso to C:\Users\Administrator\.docker\machine\machines\my-vm-node-1\boot2docker.iso...
(my-vm-node-1) Creating VirtualBox VM...
(my-vm-node-1) Creating SSH key...
(my-vm-node-1) Starting the VM...
(my-vm-node-1) Check network to re-create if needed...
(my-vm-node-1) Waiting for an IP...
Waiting for machine to be running, this may take a few minutes...
Detecting operating system of created instance...
Waiting for SSH to be available...
Detecting the provisioner...
Provisioning with boot2docker...
Copying certs to the local machine directory...
Copying certs to the remote machine...
Setting Docker configuration on the remote daemon...
Checking connection to Docker...
Docker is up and running!
To see how to connect your Docker Client to the Docker Engine running on this virtual machine, run: E:\Docker Toolbox\docker-machine.exe env my-vm-node-1
```

接着创建虚拟机`my-vm-node-2`，创建完成后查看虚拟机`ip`地址



### 查看虚拟机和`ip`地址

---

现在创建了两个虚拟机，分别命名为`my-vm-node-1`和`my-vm-node-2`。现在要列出虚拟机并获取其IP地址。

使用此命令`docker-machine ls`列出机器并获取其IP地址

```shell
$ docker-machine ls
NAME           ACTIVE   DRIVER       STATE     URL                         SWARM   DOCKER        ERRORS
default        *        virtualbox   Running   tcp://192.168.99.100:2376           v18.04.0-ce
my-vm-node-1   -        virtualbox   Running   tcp://192.168.99.101:2376           v18.04.0-ce
my-vm-node-2   -        virtualbox   Running   tcp://192.168.99.102:2376           v18.04.0-ce
```



### 初始化集群

---

第一台机器作为**管理员（主节点）**，执行管理员命令并认证**工作节点**加入群体，第二台机器是**工作节点**。<br/>

可以使用`ssh`命令来发送命令行控制你的`VM ` `docker-machine ssh`。指示`my-vm-node-1`成为一名`swarm`管理者`docker swarm init`并查找如下输出：

```shell
$ docker-machine ssh my-vm-node-1 "docker swarm init --advertise-addr 192.168.99.101"
Swarm initialized: current node (1qdcis4nk664vc2zvw2xh2jdj) is now a manager.

To add a worker to this swarm, run the following command:

    docker swarm join --token SWMTKN-1-2tyylp5ch3ojkm9ereotwbs7n649v21hrq8mnqxfz00vnwg5zh-3ddke9ir33ubxhrx02yw9gxyd 192.168.99.101:2377

To add a manager to this swarm, run 'docker swarm join-token manager' and follow the instructions.
```

上面的提示说明当前节点已经成为管理者，并且在其他机器上使用命令可以让其加入到集群管理中。

> **端口2377和2376**
>
> 始终运行`docker swarm init`并`docker swarm join`使用端口2377（群管理端口），或根本没有端口，并让它采用默认值。<br/>`docker-machine ls` 命令可以查看端口2376和虚拟机的IP地址，即Docker守护程序端口。**请勿使用此端口，否则 [可能会遇到错误](https://forums.docker.com/t/docker-swarm-join-with-virtualbox-connection-error-13-bad-certificate/31392/2)。**



**无法使用SSH？**试试`--native-ssh`标志

如果由于某些原因，无法向`Swarm`管理节点发送命令，`Docker Machine` [可以让您使用自己系统的SSH](https://docs.docker.com/machine/reference/ssh/#different-types-of-ssh)。只需`--native-ssh` 在调用该`ssh`命令时指定标志：

```shell
$ docker-machine --native-ssh ssh my-vm-node-1 `指令`
```



### 添加集群节点

---

正如你所看到的，执行`docker swarm init`指令后会输出一个预配置的 `docker swarm join`命令，让你在任何你想添加的节点上运行。复制此命令，并将其发送给`my-vm-node-2`通过`docker-machine ssh`以`my-vm-node-2` 加入集群中作为工作者：

```shell
$ docker-machine ssh my-vm-node-2 "docker swarm join --token SWMTKN-1-2tyylp5ch3ojkm9ereotwbs7n649v21hrq8mnqxfz00vnwg5zh-3ddke9ir33ubxhrx02yw9gxyd 192.168.99.101:2377"
This node joined a swarm as a worker.
```

这样`my-vm-node-2`就成功加入了集群中。



### 查看机器节点信息

---

通过命令行`docker node ls`在集群管理节点中查看集群节点的信息

```shell
$ docker-machine ssh my-vm-node-1 "docker node ls"
ID                            HOSTNAME            STATUS              AVAILABILITY        MANAGER STATUS      ENGINE VERSION
1qdcis4nk664vc2zvw2xh2jdj *   my-vm-node-1        Ready               Active              Leader              18.04.0-ce
xbgzqgx0mpnxs2iyevih9id4x     my-vm-node-2        Ready               Active                                  18.04.0-ce
```

从上信息的**MANAGER STATUS**可以看出 `my-vm-node-1`就是管理节点



### 脱离集群

---

如果需要脱离集群环境，可以使用命令`docker swarm leave`在需要脱离环境的机器上运行指令

```shell
$ docker-machine ssh my-vm-node-2 "docker swarm leave"
```



## 在集群上部署应用

复杂的部分已经完成，现在只需要重复**创建容器镜像**部分章节的工作就可以部署应用了。当然，只有集群管理者`my-vm-node-1`采用全新执行 `docker`的命令，而工人节点只能工作。



### 配置`shell`

---

`docker-machine`为swarm管理者配置一个`shell`。到目前为止，一直在封装Docker命令`docker-machine ssh`来与`VM`虚拟机进行交互。另一个选择是运行`docker-machine env <machine>`来配置一个命令行，该命令将当前`shell`配置为与`VM`上的`Docker`守护程序进行通信。此方法对更好，因为它允许您使用本地`docker-compose.yml`文件**远程**部署应用程序，而无需将其复制到任何位置。

输入`docker-machine env my-vm-node-1`，然后复制粘贴并运行输出的最后一行提供的命令，以配置shell `my-vm-node-1`与swarm管理器进行通信。

配置shell的命令根据你是`Mac`，`Linux`还是`Windows`而有所不同，因此下面的示例进行演示：

```shell
$ docker-machine env my-vm-node-1
export DOCKER_TLS_VERIFY="1"
export DOCKER_HOST="tcp://192.168.99.101:2376"
export DOCKER_CERT_PATH="C:\Users\Administrator\.docker\machine\machines\my-vm-node-1"
export DOCKER_MACHINE_NAME="my-vm-node-1"
export COMPOSE_CONVERT_WINDOWS_PATHS="true"
# Run this command to configure your shell:
# eval $("E:\Docker Toolbox\docker-machine.exe" env my-vm-node-1)
```

复制最后一行命令配置`shell`，并运行

```shell
$ eval $("E:\Docker Toolbox\docker-machine.exe" env my-vm-node-1)
```

执行完成后，通过命令查看`my-vm-node-1`是否是活动的节点

```shell
$ docker-machine ls
NAME           ACTIVE   DRIVER       STATE     URL                         SWARM   DOCKER        ERRORS
default        -        virtualbox   Running   tcp://192.168.99.100:2376           v18.04.0-ce
my-vm-node-1   *        virtualbox   Running   tcp://192.168.99.101:2376           v18.04.0-ce
my-vm-node-2   -        virtualbox   Running   tcp://192.168.99.102:2376           v18.04.0-ce
```



### 编排部署应用

---

现在`my-vm-node-1`有了集群管理器的能力，通过使用第3部分**docker 服务**中使用的`docker stack deploy`命令在`my-vm-node-1`上部署应用程序`docker-compose.yml`。该命令可能需要几秒钟才能完成，部署需要一段时间才能完成。在群管理器上使用该命令`docker service ps <service_name>`来验证所有服务已被重新部署。

`my-vm-node-1`通过`docker-machine`的shell配置连接，并且仍然可以访问本地主机上的文件。确保你和前面一样在同一个目录中，其中包括[`docker-compose.yml`你在第3部分中创建](https://docs.docker.com/get-started/part3/#docker-composeyml)的 [文件](https://docs.docker.com/get-started/part3/#docker-composeyml)。

下面运行以下命令来部署应用程序到管理者节点`my-vm-node-1`

```shell
$ docker stack deploy -c docker-compose.yml node_hello
Creating network node_hello_webnet
Creating service node_hello_web
```

这样应用程序就轻松部署到了集群机器行。

> **注意**：如果您的镜像存储在私有云而不是`Docker Hub`中，则需要使用登录`docker login <your-registry>`，然后需要将该`--with-registry-auth`标志添加到上述命令。例如：
>
> ```shell
> $ docker login registry.example.com
> $ docker stack deploy --with-registry-auth -c docker-compose.yml node_hello
> ```
>
> 这使用加密的`WAL`日志将登录令牌从本地客户端传递到部署服务的群集节点。有了这些信息，这些节点就能够登录到注册表并提取远程镜像。

通过命令`docker stack ps`查看发布的程序在两个节点中的分布情况，由于我们发布的程序需要**5**个实例副本`replicas`。所以在发布程序后，docker会为我们在两个集群节点中发布总共副本数量`5`个。

```shell
$ docker stack ps node_hello
ID                  NAME                IMAGE                       NODE                DESIRED STATE       CURRENT STATE            ERROR               PORTS
ogpj3g1x91cp        node_hello_web.1    hoojo/test:my_hello_world   my-vm-node-2        Running             Running 11 minutes ago
nf693l7s6pqc        node_hello_web.2    hoojo/test:my_hello_world   my-vm-node-1        Running             Running 11 minutes ago
lvxvfi6ocp7e        node_hello_web.3    hoojo/test:my_hello_world   my-vm-node-2        Running             Running 43 seconds ago
6od67vw6hw49        node_hello_web.4    hoojo/test:my_hello_world   my-vm-node-1        Running             Running 42 seconds ago
3xiidbo0k3fk        node_hello_web.5    hoojo/test:my_hello_world   my-vm-node-1        Running             Running 42 seconds ago

```

>使用`docker-machine env`和`docker-machine ssh`连接到`VM`。如果采用了`docker-machine env`进行配置`shell`链接后，即可在随意使用命令操作指定的`VM`。
>
>- 要将`shell`设置为与其他机器交互`my-vm-node-2`，只需 `docker-machine env`在相同或不同的`shell`中重新运行，然后运行给定的命令指向`my-vm-node-2`。只有在当前`shell`中才有效。如果为未配置的`shell`或打开一个新的`shell`，则需要重新运行这些命令。使用`docker-machine ls`列出的机器，看看他们是在什么状态，获取`IP`地址，找出需要连接的节点进行链接即可。要了解更多信息，请参阅[Docker Machine入门主题](https://docs.docker.com/machine/get-started/#create-a-machine)。
>- 或者，您可以以Docker命令的形式打包 `docker-machine ssh <machine> "<command>"`，直接登录到`VM`，但不能立即访问本地主机上的文件。
>- 在`Mac`和`Linux`上，您可以使用`docker-machine scp <file> <machine>:~` 跨机器复制文件，但`Windows`用户需要像[Git Bash](https://git-for-windows.github.io/)这样的`Linux`终端模拟器才能工作。
>
>本教程演示既`docker-machine ssh`和 `docker-machine env`，因为它们可以在通过所有平台`docker-machine CLI`。



### 访问集群应用

---

您可以从**任一个**集群机器的IP地址访问应用程序`node_hello`。有五个容器`ID`进入随机循环，展示负载平衡。

创建的网络在它们之间共享并负载平衡。运行 `docker-machine ls`以获取虚拟机的`IP`地址，并在浏览器中访问其中的任何一个，然后刷新（或只是`curl`它们）。

```shell
docker@my-vm-node-2:~$ curl http://192.168.99.102
<h3>Hello World!</h3><b>Hostname:</b> b2f95756f081<br/><b>Visits:</b> <i>cannot connect to Redis, counter disabled</i>
```

或者打开浏览器窗口，输入地址：http://192.168.99.102 经过几次刷新可以看到`hostname`在切换。同样节点`192.168.99.101` 也可以访问。

>连接有问题？<br/>请记住，要使用群集中的入口网络，在启用群集模式之前，需要在群集节点之间打开以下端口：
>
>- 用于容器网络发现的端口`7946` `TCP / UDP`。
>- 端口`4789 UDP`，用于容器入口网络。



### 扩展集群应用

---

通过更改`docker-compose.yml`文件来更新集群应用程序。通过编辑程序原始代码更改应用程序行为，然后重新构建`build`并推送`push`新镜像。（要做到这一点，请按照之前用于[构建应用程序](https://docs.docker.com/get-started/part2/#build-the-app)和[发布镜像](https://docs.docker.com/get-started/part2/#publish-the-image)的相同步骤）。

无论哪种情况，只需`docker stack deploy`再次运行即可部署这些更改。

```shell
$ docker stack deploy -c docker-compose.yml node_hello
Updating service node_hello_web (id: 1llfh50y71z6vrfzkhk1wnelc)
```

可以使用`docker swarm join`命令将任何物理或虚拟机器加入此群集`my-vm-node-2`，并将节点添加到群集中。随后运行`docker stack deploy`，您的应用可以利用新集群节点资源。

```shell
$ docker-machine create --driver virtualbox my-vm-node-3
$ docker-machine ssh my-vm-node-3 "docker swarm join --token SWMTKN-1-2tyylp5ch3ojkm9ereotwbs7n649v21hrq8mnqxfz00vnwg5zh-3ddke9ir33ubxhrx02yw9gxyd 192.168.99.101:2377"
$ docker-machine ls
```

执行完上面的命令行后，直接通过：http://192.168.99.103/ 就可以访问之前部署过的程序资源。



## 清理和重启集群应用

### 暂停应用程序

---

如果只想暂时停止应用程序，同时**保留应用程序一部分创建的任何网络**，建议的方法是将服务**副本数量设置为0**。

```shell
$ docker service ls
$ docker service scale webapp_db=0 webapp_web=0
```

它显示输出：

```
webapp_db scaled to 0
webapp_web scaled to 0
Since --detach=false was not specified, tasks will be scaled in the background.
In a future release, --detach=false will become the default.
```

### 堆栈和集群

---

删除部署的堆栈程序 `docker stack rm`

```shell
$ docker stack rm node_hello
Removing service node_hello_web
Removing network node_hello_webnet
```

> **保留集群或删除它？**
>
> 在某个时候，如果你想要在工作节点`docker-machine ssh my-vm-node-2 "docker swarm leave"`和集群管理节点`docker-machine ssh my-vm-node-1 "docker swarm leave --force"`*上*工作，你可以移除这个群体 ，但是*你需要这个群体来完成第5部分，所以现在保留它*。



### 取消变量设置

---

取消设置`docker-machine shell`变量设置。可以`docker-machine`使用给定的命令取消当前`shell`中的环境变量。

命令是：

```shell
$ eval $(docker-machine env -u)
# 或者
$ eval $("E:\Docker Toolbox\docker-machine.exe" env my-vm-node-1 -u)
```

这会导致`docker-machine`创建的虚拟机与`shell`断开连接，并允许您继续在同一个`shell`中工作，现在使用本机`docker` 命令（例如，在`Docker for Mac`或`Docker for Windows`上）。要了解更多信息，请参阅[关于取消设置环境变量](https://docs.docker.com/machine/get-started/#unset-environment-variables-in-the-current-shell)的[机器主题](https://docs.docker.com/machine/get-started/#unset-environment-variables-in-the-current-shell)。



### 重启docker 虚拟机

---

如果关闭本地主机，Docker机器将停止运行。您可以通过运行`docker-machine ls`检查机器的状态。

```shell
$ docker-machine ls
NAME           ACTIVE   DRIVER       STATE     URL                         SWARM   DOCKER        ERRORS
default        -        virtualbox   Running   tcp://192.168.99.100:2376           v18.04.0-ce
my-vm-node-1   *        virtualbox   Running   tcp://192.168.99.101:2376           v18.04.0-ce
my-vm-node-2   -        virtualbox   Running   tcp://192.168.99.102:2376           v18.04.0-ce
my-vm-node-3   -        virtualbox   Running   tcp://192.168.99.103:2376           v18.04.0-ce
```

要重新启动已停止的计算机，请运行：

```shell
$ docker-machine start <machine-name>
# 重启
$ docker-machine restart <machine-name>
```

例如启动`node-3`

```shell
$ docker-machine restart my-vm-node-3
Restarting "my-vm-node-3"...
(my-vm-node-3) Check network to re-create if needed...
(my-vm-node-3) Windows might ask for the permission to configure a dhcp server. Sometimes, such confirmation window is minimized in the taskbar.
(my-vm-node-3) Waiting for an IP...
Waiting for SSH to be available...
Detecting the provisioner...
Restarted machines may have new IP addresses. You may need to re-run the `docker-machine env` command.
```



## 本节命令行汇总

```shell
docker-machine create --driver virtualbox myvm1 	# 创建虚拟机 myvm1 (Mac, Win7, Linux)
docker-machine create -d hyperv --hyperv-virtual-switch "myswitch" myvm1 # Win10 下创建虚拟机
docker-machine env myvm1                		 # 查看myvm1节点基本信息
docker-machine ssh myvm1 "docker node ls"         # 查看myvm1集群节点信息
docker-machine ssh myvm1 "docker node inspect <node ID>"        # 检查节点
docker-machine ssh myvm1 "docker swarm join-token -q worker"   # 查看加入集群的token
docker-machine ssh myvm1   							# ssh 链接到 VM; 退出输入 "exit" 结束
docker node ls                						# 查看集群中的节点（登录到管理器时）
docker-machine ssh myvm2 "docker swarm leave"  # 使 worker节点离开集群
docker-machine ssh myvm1 "docker swarm leave -f" # 主节点离开集群，并杀死集群
docker-machine ls 						# VMs 列表, 星号显示这个shell正在与哪个虚拟机通话
docker-machine start myvm1            	# 启动虚拟机，如果在没启动的情况下
docker-machine env myvm1      			# 显示myvm1的环境变量和命令
eval $(docker-machine env myvm1)         # 将 shell 链接到 myvm1
& "C:\Program Files\Docker\Docker\Resources\bin\docker-machine.exe" env myvm1 | Invoke-Expression   # windows 将 shell 链接到 myvm1
docker stack deploy -c <file> <app>  # 部署程序; 必须设置命令shell与管理器（myvm1）交互，使用本地compose文件
docker-machine scp docker-compose.yml myvm1:~ # 将文件复制到主节点的目录（仅当您使用的ssh连接到管理器并部署应用程序时才需要）
docker-machine ssh myvm1 "docker stack deploy -c <file> <app>"   # 使用ssh的部署应用程序（您必须首先将compose文件复制到myvm1）
eval $(docker-machine env -u)     						# 从虚拟机断开shell，使用本地docker
docker-machine stop $(docker-machine ls -q)               # 停止全部运行的虚拟机
docker-machine rm $(docker-machine ls -q) 				# 删除所有运行的虚拟机，包括磁盘上的
```



# docker 服务编排

分布式应用程序层次结构的顶部：**应用堆栈（服务编排）**。堆栈是一组相互关联的服务，它们可以共享依赖关系，并且可以进行协调和伸缩。单个堆栈能够定义和协调整个应用程序的功能（尽管非常复杂的应用程序可能需要使用多个堆栈）。

好消息是，从第3部分开始，在创建`Compose`文件并使用时，从技术上讲，已经在使用堆栈`docker stack deploy`。但是，这是在单个主机上运行的单个服务堆栈，通常不会发生在生产环境中。在这里，你可以把你学到的东西，使多个服务相互关联，并在多台机器上运行它们。



## 部署可视化工具服务

### 编写 `docker-compose.yml`

---

向`docker-compose.yml`文件添加服务很容易。首先，添加一个免费的可视化工具，看看如何编排容器。

打开`docker-compose.yml`并编辑文件中内容如下：

```yaml
version: "3"
services:
  web:
    # replace username/repo:tag with your name and image details
    image: hoojo/test:my_hello_world
    deploy:
      replicas: 5
      restart_policy:
        condition: on-failure
      resources:
        limits:
          cpus: "0.1"
          memory: 50M
    ports:
      - "80:80"
    networks:
      - webnet
  visualizer:
    image: dockersamples/visualizer:stable
    ports:
      - "8080:8080"
    volumes:
      - "/var/run/docker.sock:/var/run/docker.sock"
    deploy:
      placement:
      	# 节点权限是管理者，只有主节点才可以使用这个服务
        constraints: [node.role == manager]
    networks:
      - webnet
networks:
  webnet:
```

这里唯一的新添加的东西是对等服务`web`，也叫`visualizer`。需要注意两件新事物：一个`volumes`键，让可视化工具访问`Docker`的主机`socket`文件，以及一个`placement`关键字，确保此服务只运行在`swarm`管理节点上——而不是工作节点。这是因为这个容器[是由Docker创建的一个开源项目](https://github.com/ManoMarks/docker-swarm-visualizer)构建[的](https://github.com/ManoMarks/docker-swarm-visualizer)，在图表中显示运行在群集上的`docker`服务。



### 配置`shell` 

---

确保你的`shell`已经被配置与`my-vm-node-1`交互无问题。

- 运行`docker-machine ls`列出机器并确保已连接`my-vm-node-1`主节点，如旁边的*****所示。
- 如果需要，重新运行`docker-machine env my-vm-node-1`，然后运行给定的命令来配置shell。
  - `eval $("E:\Docker Toolbox\docker-machine.exe" env my-vm-node-1)`



### 编排部署服务

---

`docker stack deploy`在管理节点上重新运行该命令，并更新需要更新的任何服务：

```shell
$ docker stack deploy -c docker-compose.yml stack_node_hello
Creating network stack_node_hello_webnet
Creating service stack_node_hello_web
Creating service stack_node_hello_visualizer
```



### 预览编排服务工具
---

`visualizer`在端口`8080` 上运行的`Compose`文件中看到。通过运行获取机器中一个节点的`IP`地址`docker-machine ls`。转到`8080`端口的`IP`地址，您可以看到可视化器正在运行：http://192.168.99.101:8080/

如果未看到，请稍等片刻，有时候有点慢。

`visualizer`如你所期望的那样，单个副本在管理器上运行，并且5个实例`web`遍布整个集群。您可以运行`docker stack ps <stack>`以下内容来确认此可视化：

```shell
$ docker stack ps stack_node_hello
```

可视化器是一个独立的服务，可以在包含它的任何应用程序中运行。它不依赖于其他任何东西。现在让我们创建一个服务*不会*有依赖性：`Redis`的服务，提供访客计数器。



## 部署存储数据服务

再次通过相同的工作流程来添加用于存储应用程序数据的`Redis`数据库。

### 编写 `docker-compose.yml`
---

添加一个`Redis`服务，编写它的`docker-compose.yml`，这个文件内容如下：

```shell
version: "3"
services:
  web:
    # replace username/repo:tag with your name and image details
    image: hoojo/test:my_hello_world
    deploy:
      replicas: 5
      restart_policy:
        condition: on-failure
      resources:
        limits:
          cpus: "0.1"
          memory: 50M
    ports:
      - "80:80"
    networks:
      - webnet
  visualizer:
    image: dockersamples/visualizer:stable
    ports:
      - "8080:8080"
    volumes:
      - "/var/run/docker.sock:/var/run/docker.sock"
    deploy:
      placement:
        constraints: [node.role == manager]
    networks:
      - webnet
  redis:
    image: redis
    ports:
      - "6379:6379"
    volumes:
      - "/home/docker/data:/data"
    deploy:
      placement:
        constraints: [node.role == manager]
    command: redis-server --appendonly yes
    networks:
      - webnet
networks:
  webnet:
```

`redis`在`docker`库中有一个官方镜像，并被授予`redis`的简短镜像名称，所以`username/repo`在这里没有标记。Redis端口6379已经由Redis容器预先配置并暴露给主机，并且在我们的`Compose`文件中将它从主机暴露给外界，因此可以通过输入`IP`节点添加到`Redis`桌面管理器中并管理`Redis`实例。

最重要的是，`redis`规范中有几件事情使数据在这个堆栈的部署之间保持不变：

- `redis` 总是在管理器上运行，所以它总是使用相同的文件系统。
- `redis` 访问主机文件系统中的任意目录作为`/data`，这是`Redis`存储数据的地方。

这是在主机的物理文件系统中为`redis`数据创建“真相源”。否则，`redis`会将其数据存储在容器文件系统中的`/data`中，如果该容器曾经被重新部署过，则该数据将被清除。

这个真相的来源有两个组成部分：

- 放置在`Redis`服务上的放置约束，确保它始终使用相同的主机。
- 您创建的容器，允许容器`./data`（在主机上）访问（在`/data`Redis容器内）。容器来来去去时，存储在`./data`指定主机上的文件仍然存在，从而保持连续性。



### 创建`./data`目录

---

在主节点上创建`./data`目录，这个目录用于`redis`存储数据

```shell
$ docker-machine ssh my-vm-node-1 "mkdir ./data"
```



### 配置 `shell` 

---

确保你的`shell`已经被配置好与主机节点（管理节点）`my-vm-node-1`交互

- 运行`docker-machine ls`列出机器并确保您已连接`my-vm-node-1`，如有星号标记的节点。

- 如果需要，重新运行`docker-machine env my-vm-node-1`，然后运行给定的命令来配置shell。

  - 会提示运行命令：`eval $("E:\Docker Toolbox\docker-machine.exe" env my-vm-node-1)`

  ​

### 编排部署服务

---

`docker stack deploy`在管理节点上重新运行该命令，并删除重复或者占用端口的服务：

```shell
$ docker stack deploy -c docker-compose.yml redis_node_hello
Creating service redis_node_hello_redis
Updating service redis_node_hello_web (id: 6bozutve6xhwdfugdt0yvoage)
Updating service redis_node_hello_visualizer (id: yx9f0wnyp7yerkcys587cz92j)
```



### 预览编排服务

---

运行`docker service ls`以验证这三个服务是否按预期运行。

```shell
$ docker service ls
ID                  NAME                          MODE                REPLICAS            IMAGE                             PORTS
xmc12o1jw4dg        redis_node_hello_redis        replicated          1/1                 redis:latest                      *:6379->6379/tcp
yx9f0wnyp7ye        redis_node_hello_visualizer   replicated          1/1                 dockersamples/visualizer:stable   *:8080->8080/tcp
6bozutve6xhw        redis_node_hello_web          replicated          5/5                 hoojo/test:my_hello_world         *:80->80/tcp
```

运行命令`docker stack ps`查看服务运行状态

```shell
$ docker stack ps redis_node_hello
ID                  NAME                            IMAGE                             NODE                DESIRED STATE       CURRENT STATE            ERROR               PORTS
6oavwsueaeqm        redis_node_hello_redis.1        redis:latest                      my-vm-node-1        Running             Running 6 minutes ago
oouvfn08dn92        redis_node_hello_web.1          hoojo/test:my_hello_world         my-vm-node-3        Running             Running 10 minutes ago
tqnc6tva5z4f        redis_node_hello_visualizer.1   dockersamples/visualizer:stable   my-vm-node-1        Running             Running 11 minutes ago
osnzlz143q9j        redis_node_hello_web.2          hoojo/test:my_hello_world         my-vm-node-1        Running             Running 10 minutes ago
qc5xzi76en1h        redis_node_hello_web.3          hoojo/test:my_hello_world         my-vm-node-2        Running             Running 10 minutes ago
h8iikqblg993        redis_node_hello_web.4          hoojo/test:my_hello_world         my-vm-node-3        Running             Running 10 minutes ago
jtjpys25xwi8        redis_node_hello_web.5          hoojo/test:my_hello_world         my-vm-node-2        Running             Running 10 minutes ago
```

通过访问：http://192.168.99.101/ 后，发现网页上的 **Visits**会计数并累加变化。<br/>通过访问：http://192.168.99.102:8080/ 会看到 多了一个服务 `redis `也在上面运行。







# 参考文档

https://docs.docker.com/get-started/part2/

https://docs.docker.com/docker-for-windows/

http://www.fecshop.com/topic/591