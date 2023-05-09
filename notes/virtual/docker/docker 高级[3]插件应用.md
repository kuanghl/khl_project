# docker plugin 应用

* [docker plugin 应用](#docker-plugin-%E5%BA%94%E7%94%A8)
* [docker plugin 基本命令](#docker-plugin-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA)
  * [install 安装](#install-%E5%AE%89%E8%A3%85)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9)
    * [示例](#%E7%A4%BA%E4%BE%8B)
  * [disable 禁用](#disable-%E7%A6%81%E7%94%A8)
  * [enable 启用](#enable-%E5%90%AF%E7%94%A8)
  * [inspect 查看](#inspect-%E6%9F%A5%E7%9C%8B)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8)
    * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96)
  * [push 推送](#push-%E6%8E%A8%E9%80%81)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4)
  * [set 设置](#set-%E8%AE%BE%E7%BD%AE)
    * [更改环境变量](#%E6%9B%B4%E6%94%B9%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
    * [更改安装源](#%E6%9B%B4%E6%94%B9%E5%AE%89%E8%A3%85%E6%BA%90)
    * [更改设备路径](#%E6%9B%B4%E6%94%B9%E8%AE%BE%E5%A4%87%E8%B7%AF%E5%BE%84)
    * [更改参数的来源](#%E6%9B%B4%E6%94%B9%E5%8F%82%E6%95%B0%E7%9A%84%E6%9D%A5%E6%BA%90)
  * [upgrade 升级](#upgrade-%E5%8D%87%E7%BA%A7)
* [管理插件](#%E7%AE%A1%E7%90%86%E6%8F%92%E4%BB%B6)
  * [安装和使用插件](#%E5%AE%89%E8%A3%85%E5%92%8C%E4%BD%BF%E7%94%A8%E6%8F%92%E4%BB%B6)
  * [开发插件](#%E5%BC%80%E5%8F%91%E6%8F%92%E4%BB%B6)
    * [ROOTFS目录](#rootfs%E7%9B%AE%E5%BD%95)
    * [CONFIG\.JSON文件](#configjson%E6%96%87%E4%BB%B6)
    * [创建插件](#%E5%88%9B%E5%BB%BA%E6%8F%92%E4%BB%B6)
    * [调试插件](#%E8%B0%83%E8%AF%95%E6%8F%92%E4%BB%B6)
      * [使用DOCKER\-RUNC获取LOGFILES和SHELL进入插件](#%E4%BD%BF%E7%94%A8docker-runc%E8%8E%B7%E5%8F%96logfiles%E5%92%8Cshell%E8%BF%9B%E5%85%A5%E6%8F%92%E4%BB%B6)
      * [使用CURL调试插件套接字问题。](#%E4%BD%BF%E7%94%A8curl%E8%B0%83%E8%AF%95%E6%8F%92%E4%BB%B6%E5%A5%97%E6%8E%A5%E5%AD%97%E9%97%AE%E9%A2%98)
* [授权访问插件](#%E6%8E%88%E6%9D%83%E8%AE%BF%E9%97%AE%E6%8F%92%E4%BB%B6)
  * [基本原则](#%E5%9F%BA%E6%9C%AC%E5%8E%9F%E5%88%99)
  * [默认的用户授权机制](#%E9%BB%98%E8%AE%A4%E7%9A%84%E7%94%A8%E6%88%B7%E6%8E%88%E6%9D%83%E6%9C%BA%E5%88%B6)
  * [基本架构](#%E5%9F%BA%E6%9C%AC%E6%9E%B6%E6%9E%84)
  * [Docker客户端流量](#docker%E5%AE%A2%E6%88%B7%E7%AB%AF%E6%B5%81%E9%87%8F)
    * [设置Docker守护进程](#%E8%AE%BE%E7%BD%AEdocker%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
    * [调用授权命令（允许）](#%E8%B0%83%E7%94%A8%E6%8E%88%E6%9D%83%E5%91%BD%E4%BB%A4%E5%85%81%E8%AE%B8)
    * [调用未授权的命令（拒绝）](#%E8%B0%83%E7%94%A8%E6%9C%AA%E6%8E%88%E6%9D%83%E7%9A%84%E5%91%BD%E4%BB%A4%E6%8B%92%E7%BB%9D)
    * [来自插件的错误](#%E6%9D%A5%E8%87%AA%E6%8F%92%E4%BB%B6%E7%9A%84%E9%94%99%E8%AF%AF)
  * [API架构和实现](#api%E6%9E%B6%E6%9E%84%E5%92%8C%E5%AE%9E%E7%8E%B0)
      * [/AUTHZPLUGIN\.AUTHZREQ](#authzpluginauthzreq)
      * [/AUTHZPLUGIN\.AUTHZRES](#authzpluginauthzres)
    * [请求授权](#%E8%AF%B7%E6%B1%82%E6%8E%88%E6%9D%83)
      * [守护进程 \- &gt;插件](#%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B---%E6%8F%92%E4%BB%B6)
      * [插件 \- &gt;守护进程](#%E6%8F%92%E4%BB%B6---%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
    * [响应授权](#%E5%93%8D%E5%BA%94%E6%8E%88%E6%9D%83)
      * [守护进程 \- &gt;插件](#%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B---%E6%8F%92%E4%BB%B6-1)
      * [插件 \- &gt;守护进程](#%E6%8F%92%E4%BB%B6---%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B-1)
* [docker 插件](#docker-%E6%8F%92%E4%BB%B6)
  * [什么插件](#%E4%BB%80%E4%B9%88%E6%8F%92%E4%BB%B6)
  * [插件发现](#%E6%8F%92%E4%BB%B6%E5%8F%91%E7%8E%B0)
    * [JSON规范](#json%E8%A7%84%E8%8C%83)
  * [插件生命周期](#%E6%8F%92%E4%BB%B6%E7%94%9F%E5%91%BD%E5%91%A8%E6%9C%9F)
  * [插件激活](#%E6%8F%92%E4%BB%B6%E6%BF%80%E6%B4%BB)
  * [Systemd套接字激活](#systemd%E5%A5%97%E6%8E%A5%E5%AD%97%E6%BF%80%E6%B4%BB)
  * [API设计](#api%E8%AE%BE%E8%AE%A1)
  * [握手API](#%E6%8F%A1%E6%89%8Bapi)
    * [/Plugin\.Activate](#pluginactivate)
  * [插件重试](#%E6%8F%92%E4%BB%B6%E9%87%8D%E8%AF%95)
  * [插件助手](#%E6%8F%92%E4%BB%B6%E5%8A%A9%E6%89%8B)

# docker plugin 基本命令

```sh
$ docker plugin -h
Usage:  docker plugin COMMAND
插件管理

Commands:
  create      # 从rootfs和配置创建一个插件。插件数据目录必须包含config.json和rootfs目录。
  disable     # 禁用插件
  enable      # 启用插件
  inspect     # 显示一个或多个插件的详细信息
  install     # 安装一个插件
  ls          # 插件列表
  push        # 将插件推送到注册表
  rm          # 删除一个或多个插件
  set         # 更改插件的设置
  upgrade     # 升级现有的插件
```

## create 创建

创建一个插件。在创建插件之前，请准备插件的根文件系统以及 [config.json](https://docs.docker.com/engine/extend/config/)。以下示例显示如何创建示例plugin：

```sh
$ ls -ls /home/pluginDir
total 4

4 -rw-r--r--  1 root root 431 Nov  7 01:40 config.json
0 drwxr-xr-x 19 root root 420 Nov  7 01:40 rootfs

$ docker plugin create plugin /home/pluginDir
# docker plugin create plugin /home/pluginDir --compress
plugin

$ docker plugin ls
ID                  NAME                TAG                 DESCRIPTION                  ENABLED
672d8144ec02        plugin              latest              A sample plugin for Docker   false
```

插件可以随后启用本地使用或推送到公共注册表。

## install 安装

安装并启用插件。Docker首先查找Docker主机上的插件。如果插件本地不存在，则插件将从注册表中提取。请注意，分发插件所需的最低注册表版本是2.3.0

 ### 命令参数选项

---

| 选项，简写                | 默认   | 描述                       |
| ------------------------- | ------ | -------------------------- |
| `--alias`                 |        | 插件的本地名称             |
| `--disable`               |        | 不要在安装时启用插件       |
| `--disable-content-trust` | `true` | 跳过图像验证               |
| `--grant-all-permissions` |        | 授予运行插件所需的所有权限 |

### 示例

---

下面的示例安装`vieus/sshfs`插件，并[设置](https://docs.docker.com/engine/reference/commandline/plugin_set/)它的 `DEBUG`环境变量`1`。要安装Docker Hub的插件并提示用户接受插件所需的权限列表，请设置插件的参数并启用插件。

```sh
$ docker plugin install vieux/sshfs DEBUG=1
```

## disable 禁用

禁用插件。插件必须先安装，然后才能禁用，请参阅[`docker plugin install`](https://docs.docker.com/engine/reference/commandline/plugin_install/)。一个有引用的插件（例如卷，网络）不能被禁用。

 ```sh
$ docker plugin disable vieux/sshfs
vieux/sshfs

$ docker plugin ls
 ```

## enable 启用

启用插件。插件必须先安装才能启用，请参阅[`docker plugin install`](https://docs.docker.com/engine/reference/commandline/plugin_install/)。

```sh
$ docker plugin ls
ID                  NAME                             TAG                 DESCRIPTION                ENABLED69553ca1d123        tiborvass/sample-volume-plugin   latest              A test plugin for Docker   false

$ docker plugin enable tiborvass/sample-volume-plugin
tiborvass/sample-volume-plugin

$ docker plugin ls
ID                  NAME                             TAG                 DESCRIPTION                ENABLED
69553ca1d123        tiborvass/sample-volume-plugin   latest              A test plugin for Docker   true
```

## inspect 查看

返回关于插件的信息。默认情况下，该命令将所有结果呈现在JSON数组中。

 ```sh
$ docker plugin inspect tiborvass/sample-volume-plugin:latest
$ docker plugin inspect -f '{{.Id}}' tiborvass/sample-volume-plugin:latest
 ```

## ls 列表

列出当前安装的所有插件。您可以使用该[`docker plugin install`](https://docs.docker.com/engine/reference/commandline/plugin_install/)命令安装插件。您也可以使用`-f`或`--filter`标志进行过滤。有关可用过滤器选项的更多信息，请参阅[过滤](https://docs.docker.com/engine/reference/commandline/plugin_ls/#filtering)部分。

 ```sh
$ docker plugin ls
ID                  NAME                             TAG                 DESCRIPTION                ENABLED
69553ca1d123        tiborvass/sample-volume-plugin   latest              A test plugin for Docker   true

# 过滤
$ docker plugin ls --filter enabled=true
 ```

### 格式化

格式化选项（`--format`）使用Go模板漂亮地打印插件输出。

下面列出了Go模板的有效占位符：

| 占位符             | 描述                      |
| ------------------ | ------------------------- |
| `.ID`              | 插件ID                    |
| `.Name`            | 插件名称                  |
| `.Description`     | 插件描述                  |
| `.Enabled`         | 是否启用插件              |
| `.PluginReference` | 用于从注册表中推/拉的参考 |

使用`--format`选项时，`plugin ls`命令将按照模板声明输出数据，或者在使用 `table`指令时也包含列标题。

下面的示例使用的模板没有报头，并输出 `ID`和`Name`通过对所有的插件冒号分隔的条目：

```sh
$ docker plugin ls --format "{{.ID}}: {{.Name}}"
```

## push 推送

使用`docker plugin create`插件创建插件并准备好发布之后，用于`docker plugin push`将图像分享到Docker Hub或自托管注册表。

 ```sh
$ docker plugin ls
ID                  NAME                  TAG                 DESCRIPTION                ENABLED
69553ca1d456        user/plugin           latest              A sample plugin for Docker false

$ docker plugin push user/plugin
$ docker plugin push user/plugin --disable-content-trust false	
 ```

## rm 删除

删除一个插件。如果插件已启用，则不能删除插件，必须[`docker plugin disable`](https://docs.docker.com/engine/reference/commandline/plugin_disable/)在删除插件之前禁用它（或使用--force，不推荐使用force，因为它可能会影响使用插件运行容器的功能）。

 ```sh
$ docker plugin disable tiborvass/sample-volume-plugin
tiborvass/sample-volume-plugin

$ docker plugin rm tiborvass/sample-volume-plugin:latest
tiborvass/sample-volume-plugin
 ```

## set 设置

更改插件的设置。该插件必须禁用。目前支持的设置是：`env变量`，`mount 的来源`，`设备路径`，`ARGS`。

### 更改环境变量

以下示例更改插件`DEBUG`上的 env变量`sample-volume-plugin`。

```sh
$ docker plugin inspect -f {{.Settings.Env}} tiborvass/sample-volume-plugin
[DEBUG=0]

$ docker plugin set tiborvass/sample-volume-plugin DEBUG=1

$ docker plugin inspect -f {{.Settings.Env}} tiborvass/sample-volume-plugin
[DEBUG=1]
```

### 更改安装源

以下示例更改插件`mymount`上的装载源`myplugin`。

```sh
$ docker plugin inspect -f '{{with $mount := index .Settings.Mounts 0}}{{$mount.Source}}{{end}}' myplugin
/foo

$ docker plugins set myplugin mymount.source=/bar

$ docker plugin inspect -f '{{with $mount := index .Settings.Mounts 0}}{{$mount.Source}}{{end}}' myplugin
/bar
```

> **注意：**因为`mymount`中只有`source`  可以设置，所以`docker plugins set mymount=/bar myplugin` 也可以。

### 更改设备路径

以下示例更改插件`mydevice`上设备的路径`myplugin`。

```sh
$ docker plugin inspect -f '{{with $device := index .Settings.Devices 0}}{{$device.Path}}{{end}}' myplugin
/dev/foo

$ docker plugins set myplugin mydevice.path=/dev/bar

$ docker plugin inspect -f '{{with $device := index .Settings.Devices 0}}{{$device.Path}}{{end}}' myplugin
/dev/bar
```

> **注**：由于只有`path`可设置在`mydevice`， `docker plugins set mydevice=/dev/bar myplugin`可以工作。

### 更改参数的来源

以下示例更改`myplugin`插件上参数的值。

```sh
$ docker plugin inspect -f '{{.Settings.Args}}' myplugin
["foo", "bar"]

$ docker plugins set myplugin myargs="foo bar baz"

$ docker plugin inspect -f '{{.Settings.Args}}' myplugin
["foo", "bar", "baz"]
```

## upgrade 升级

将现有插件升级到指定的远程插件映像。如果未指定远程，Docker将重新提取当前映像并使用更新后的版本。所有现有的插件引用将继续工作。运行升级之前，必须禁用该插件。

 ```sh
$ docker plugin install vieux/sshfs DEBUG=1
Plugin "vieux/sshfs:next" is requesting the following privileges:
 - network: [host]
 - device: [/dev/fuse]
 - capabilities: [CAP_SYS_ADMIN]
Do you grant the above permissions? [y/N] y
vieux/sshfs:next

$ docker volume create -d vieux/sshfs:next -o sshcmd=root@1.2.3.4:/tmp/shared -o password=XXX sshvolume
sshvolume

$ docker run -it -v sshvolume:/data alpine sh -c "touch /data/hello"

$ docker plugin disable -f vieux/sshfs:next
viex/sshfs:next

# Here docker volume ls doesn't show 'sshfsvolume', since the plugin is disabled
$ docker volume ls
DRIVER              VOLUME NAME

$ docker plugin upgrade vieux/sshfs:next vieux/sshfs:next
Plugin "vieux/sshfs:next" is requesting the following privileges:
 - network: [host]
 - device: [/dev/fuse]
 - capabilities: [CAP_SYS_ADMIN]
Do you grant the above permissions? [y/N] y
Upgrade plugin vieux/sshfs:next to vieux/sshfs:next

$ docker plugin enable vieux/sshfs:next
viex/sshfs:next

$ docker volume ls
DRIVER              VOLUME NAME
viuex/sshfs:next    sshvolume

$ docker run -it -v sshvolume:/data alpine sh -c "ls /data"
hello
 ```

# 管理插件

Docker Engine的插件系统允许使用Docker Engine安装、启动、停止和移除插件。

有关Docker Engine 1.12及更早版本中提供的传统插件系统的信息，请参阅[了解传统Docker引擎插件](https://docs.docker.com/engine/extend/legacy_plugins/)。

> **注意**：Windows守护程序目前不支持Docker Engine托管插件。

## 安装和使用插件

插件以Docker镜像的形式发布，可以托管在Docker Hub或私有注册表中。要安装插件，请使用`docker plugin install`从Docker Hub或私人注册表中提取插件的命令，并在必要时提示授予权限或功能，并启用插件。<br/>要检查已安装插件的状态，请使用`docker plugin ls`命令。成功启动的插件在输出中列为启用。

在安装插件之后，可以将其用作另一个Docker操作的选项，例如创建卷。在以下示例中，将安装`sshfs`插件，验证它是否已启用，并使用它来创建卷。

> **注意**：本示例仅用于说明目的。创建卷后，在检查卷时，远程主机的SSH密码将作为纯文本公开。应该在完成示例后立即删除卷。

1. 安装`sshfs`插件。

   ```sh
   $ docker plugin install vieux/sshfs
   Plugin "vieux/sshfs" is requesting the following privileges:
   - network: [host]
   - capabilities: [CAP_SYS_ADMIN]
   Do you grant the above permissions? [y/N] y
   
   vieux/sshfs
   ```

   插件请求2个权限：

   - 它需要访问`host`网络。
   - 它需要`CAP_SYS_ADMIN`能够让插件运行`mount`命令的功能。

2. 检查插件是否在输出中启用`docker plugin ls`。

   ```sh
   $ docker plugin ls
   ```

3. 使用插件创建一个卷。本示例将`/remote`主机上的目录`1.2.3.4`挂载到名为的卷中`sshvolume`。该卷现在可以安装到容器中。

   ```sh
   $ docker volume create \
     -d vieux/sshfs \
     --name sshvolume \
     -o sshcmd=user@192.168.99.100:/remote \
     #-o password=$(cat file_containing_password_for_remote_host)
   sshvolume
   ```

4. 确认卷已成功创建。

   ```sh
   $ docker volume ls
   DRIVER              NAME
   vieux/sshfs         sshvolume
   ```

5. 启动一个使用`sshvolume`卷的容器。

   ```sh
   $ docker run --rm -v sshvolume:/data busybox ls /data
   
   <content of /remote on machine 1.2.3.4>
   ```

6. 删除卷 `sshvolume`

   ```sh
   $ docker volume rm sshvolume
   sshvolume
   ```

   要禁用插件，请使用`docker plugin disable`命令。要完全删除它，请使用`docker plugin rm`命令。有关其他可用的命令和选项，请参阅 [命令行参考](https://docs.docker.com/engine/reference/commandline/)。

## 开发插件

### ROOTFS目录

---

`rootfs`目录代表插件的**根文件系统**。在这个例子中，它是从Dockerfile创建的：

> **注意：**`/run/docker/plugins`目录在插件的文件系统内部用于docker与插件进行通信。

```sh
$ git clone https://github.com/vieux/docker-volume-sshfs
$ cd docker-volume-sshfs
$ docker build -t rootfsimage .
$ id=$(docker create rootfsimage true) # id was cd851ce43a403 when the image was created
$ sudo mkdir -p myplugin/rootfs
$ sudo docker export "$id" | sudo tar -x -C myplugin/rootfs
$ docker rm -vf "$id"
$ docker rmi rootfsimage
```

### CONFIG.JSON文件

---

`config.json`文件描述了该插件。请参阅[插件配置参考](https://docs.docker.com/engine/extend/config/)。考虑下面的`config.json`文件。

```json
{
	"description": "sshFS plugin for Docker",
	"documentation": "https://docs.docker.com/engine/extend/plugins/",
	"entrypoint": ["/docker-volume-sshfs"],
	"network": {
		   "type": "host"
		   },
	"interface" : {
		   "types": ["docker.volumedriver/1.0"],
		   "socket": "sshfs.sock"
	},
	"linux": {
		"capabilities": ["CAP_SYS_ADMIN"]
	}
}
```

这个插件是一个`volume`驱动程序。它需要一个`host`网络和 `CAP_SYS_ADMIN`能力。它取决于`/docker-volume-sshfs` 入口点并使用`/run/docker/plugins/sshfs.sock`套接字与Docker引擎进行通信。这个插件没有运行时参数。

### 创建插件

---

通过运行`docker plugin create <plugin-name> ./path/to/plugin/data`插件数据包含插件配置文件`config.json`和`rootfs`子目录中的根文件系统，可以创建一个新的插件 。之后，该插件`<plugin-name>`将显示在`docker plugin ls`。可以使用插件将插件推送到远程注册表`docker plugin push <plugin-name>`。

### 调试插件

---

插件的`stdout`被重定向到`dockerd`日志。这些条目有一个 `plugin=<ID>`后缀。以下是docker `f52a3df433b9aceee436eaada0752f5797aab1de47e5485f1690a073b860ff62`守护程序日志中`pluginID` 及其相应日志条目的几个命令示例 。

```sh
# 安装插件
$ docker plugin install tiborvass/sample-volume-plugin
# 插件卷
$ docker volume create -d tiborvass/sample-volume-plugin samplevol
# 运行镜像，使用卷
$ docker run -v samplevol:/tmp busybox sh
```

 #### 使用`DOCKER-RUNC`获取`LOGFILES`和`SHELL`进入插件

默认的docker容器运行`docker-runc`时可用于调试插件。如果插件日志被重定向到文件，这特别有用。

```sh
$ docker-machine ssh manager1

$ sudo docker-runc --root /var/run/docker/plugins/runtime-root/moby-plugins list
ID                                                                 PID         STATUS      BUNDLE                                                                                                                                       CREATED                          OWNER
93f1e7dbfe11c938782c2993628c895cf28e2274072c4a346a6002446c949b25   15806       running     /run/docker/containerd/daemon/io.containerd.runtime.v1.linux/moby-plugins/93f1e7dbfe11c938782c2993628c895cf28e2274072c4a346a6002446c949b25   2018-02-08T21:40:08.621358213Z   root
9b4606d84e06b56df84fadf054a21374b247941c94ce405b0a261499d689d9c9   14992       running     /run/docker/containerd/daemon/io.containerd.runtime.v1.linux/moby-plugins/9b4606d84e06b56df84fadf054a21374b247941c94ce405b0a261499d689d9c9   2018-02-08T21:35:12.321325872Z   root
c5bb4b90941efcaccca999439ed06d6a6affdde7081bb34dc84126b57b3e793d   14984       running     /run/docker/containerd/daemon/io.containerd.runtime.v1.linux/moby-plugins/c5bb4b90941efcaccca999439ed06d6a6affdde7081bb34dc84126b57b3e793d   2018-02-08T21:35:12.321288966Z   root

$ sudo docker-runc --root /var/run/docker/plugins/runtime-root/moby-plugins exec 93f1e7dbfe11c938782c2993628c895cf28e2274072c4a346a6002446c949b25 cat /var/log/plugin.log
```

如果插件具有内置的shell，那么可以按照如下方式执行插件：

```sh
$ sudo docker-runc --root /var/run/docker/plugins/runtime-root/moby-plugins exec -t 93f1e7dbfe11c938782c2993628c895cf28e2274072c4a346a6002446c949b25 sh
```

#### 使用CURL调试插件套接字问题。

要验证docker守护程序与通信的插件API套接字是否响应，请使用curl。在本例中，我们将使用curl 7.47.0从docker主机到卷和网络插件进行API调用，以确保插件正在侦听所述套接字。对于正常运行的插件，这些基本命令应该可以工作。请注意，插件套接字在主机下可用`/var/run/docker/plugins/<pluginID>`

```sh
curl -H "Content-Type: application/json" -XPOST -d '{}' --unix-socket /var/run/docker/plugins/e8a37ba56fc879c991f7d7921901723c64df6b42b87e6a0b055771ecf8477a6d/plugin.sock http:/VolumeDriver.List

{"Mountpoint":"","Err":"","Volumes":[{"Name":"myvol1","Mountpoint":"/data/myvol1"},{"Name":"myvol2","Mountpoint":"/data/myvol2"}],"Volume":null}
```

```sh
curl -H "Content-Type: application/json" -XPOST -d '{}' --unix-socket /var/run/docker/plugins/45e00a7ce6185d6e365904c8bcf62eb724b1fe307e0d4e7ecc9f6c1eb7bcdb70/plugin.sock http:/NetworkDriver.GetCapabilities

{"Scope":"local"}
```

当使用curl 7.5或更高版本时，URL应该是表单的形式 `http://hostname/APICall`，其中`hostname`是安装插件的有效主机名，并且`APICall`是对插件API的调用。

例如， `http://localhost/VolumeDriver.List`

# 授权访问插件

本文档描述了Docker Engine中通常提供的Docker Engine插件。要查看由Docker Engine管理的插件的信息，请参阅[Docker Engine插件系统](https://docs.docker.com/engine/extend/)。

Docker的开箱即用授权模式是全部或没有。任何有权访问Docker守护程序的用户都可以运行任何Docker客户端命令。对于使用Docker的Engine API来调用守护进程的调用者也是如此。如果需要更大的访问控制权，可以创建授权插件并将其添加到Docker**守护程序配置中**。使用授权插件，Docker管理员可以配置**访问粒度策略**来管理对Docker守护进程的访问。

任何具有相应技能的人都可以开发授权插件。这些技能，最基本的是Docker的知识，对REST的理解以及良好的编程知识。本文档描述授权插件开发人员可用的体系结构，状态和方法信息。

## 基本原则

Docker的[插件基础架构](https://docs.docker.com/engine/extend/plugin_api/)可以通过使用**通用API**加载、删除与第三方组件进行通信来扩展Docker。访问授权子系统是使用这种机制构建的。

使用这个子系统，不需要重建Docker守护程序来添加授权插件。可以将插件添加到已安装的Docker守护程序。确实需要重新启动Docker守护程序才能添加新的插件。

**授权插件基于当前认证上下文和命令上下文来批准或拒绝对Docker守护进程的请求。认证上下文包含所有用户详细信息和认证方法。命令上下文包含所有相关的请求数据**。

授权插件必须遵循[Docker插件API中](https://docs.docker.com/engine/extend/plugin_api/)描述的规则。每个插件必须驻留在[插件发现](https://docs.docker.com/engine/extend/plugin_api/#plugin-discovery)部分描述的目录中 。

**注意**：平均授权和认证缩写分别是`AuthZ`和`AuthN`。

## 默认的用户授权机制

如果在[Docker守护进程中](https://docs.docker.com/engine/security/https/)启用了TLS ，则**默认的用户授权流程会从证书主体名称中提取用户详细**信息。即，`User`字段设置为客户端证书主题公用名称，并且`AuthenticationMethod`字段设置为`TLS`。

## 基本架构

您有责任将插件注册为Docker守护程序**启动**的一部分。可以安装多个插件并将它们链接在一起。这条链是**有序**的。对守护进程的每个请求都按顺序通过链。只有当**所有插件**授予对资源的访问权时，授予的访问权才能访问。

当通过CLI或通过引擎API向Docker守护进程发出HTTP请求时，身份验证子系统会将请求传递给已安装的身份验证插件。请求包含用户（调用者）和命令上下文。插件负责决定是允许还是拒绝请求。

下面的序列图描述了允许和拒绝授权流程：

![授权允许流量](https://docs.docker.com/engine/extend/images/authz_allow.png)

![授权拒绝流量](https://docs.docker.com/engine/extend/images/authz_deny.png)

发送给插件的每个请求都包括**经过身份验证**的**用户、HTTP头和请求/响应主体**。只有**用户名和使用的认证方法**被传递给插件。最重要的是，没有**用户凭证或令牌**传递。最后，**并非所有**的请求/响应主体都被发送到授权插件。只有那些请求/响应报文中**`Content-Type`或者是`text/*`或`application/json`**被发送。

对于**可能劫持**HTTP连接（`HTTP Upgrade`）的命令，例如`exec`，授权插件仅针对初始HTTP请求进行调用。一旦插件批准该命令，授权就不会应用于其余的流程。具体来说，流式传输数据不会传递给授权插件。对于返回分块HTTP响应的命令，比如`logs`和`events`，只有HTTP请求被发送到授权插件。

在请求/响应处理期间，一些授权流可能需要对Docker守护进程执行额外的查询。为了完成这样的流程，插件可以像守护用户一样调用守护进程API。要启用这些额外的查询，插件必须为管理员提供配置**正确的身份验证和安全策略**的方法。

## Docker客户端流量

要启用和配置授权插件，插件开发人员必须了解本节中详细介绍的Docker客户端交互。

### 设置Docker守护进程

使用`--authorization-plugin=PLUGIN_ID`格式中的专用命令行标志启用授权插件 。标志提供一个`PLUGIN_ID` 值。该值可以是插件的套接字或指定文件的路径。授权插件可以在不重新启动守护进程的情况下加载。请参阅[`dockerd`文档](https://docs.docker.com/engine/reference/commandline/dockerd/#configuration-reloading)以获取更多信息。

```sh
$ dockerd --authorization-plugin=plugin1 --authorization-plugin=plugin2,...
```

Docker的授权子系统支持多个`--authorization-plugin`参数。

### 调用授权命令（允许）

```sh
$ docker pull centos
...
f1b10cd84249: Pull complete
...
```

### 调用未授权的命令（拒绝）

```sh
$ docker pull centos
...
docker: Error response from daemon: authorization denied by plugin PLUGIN_NAME: volumes are not allowed.
```

### 来自插件的错误

```sh
$ docker pull centos
...
docker: Error response from daemon: plugin PLUGIN_NAME failed with error: AuthZPlugin.AuthZReq: Cannot connect to the Docker daemon. Is the docker daemon running on this host?.
```

## API架构和实现

除了Docker的标准插件注册方法外，每个插件都应该实现以下两种方法：

- `/AuthZPlugin.AuthZReq` 这个授权请求方法在Docker守护进程处理客户请求之前被调用。
- `/AuthZPlugin.AuthZRes` 在从Docker守护程序向客户端返回响应之前调用此授权响应方法。

#### /AUTHZPLUGIN.AUTHZREQ

**要求**：

```json
{
    "User":              "The user identification",
    "UserAuthNMethod":   "The authentication method used",
    "RequestMethod":     "The HTTP method",
    "RequestURI":        "The HTTP request URI",
    "RequestBody":       "Byte array containing the raw HTTP request body",
    "RequestHeader":     "Byte array containing the raw HTTP request header as a map[string][]string "
}
```

**回应**：

```json
{
    "Allow": "Determined whether the user is allowed or not",
    "Msg":   "The authorization message",
    "Err":   "The error message if things go wrong"
}
```

#### /AUTHZPLUGIN.AUTHZRES

**要求**：

```json
{
    "User":              "The user identification",
    "UserAuthNMethod":   "The authentication method used",
    "RequestMethod":     "The HTTP method",
    "RequestURI":        "The HTTP request URI",
    "RequestBody":       "Byte array containing the raw HTTP request body",
    "RequestHeader":     "Byte array containing the raw HTTP request header as a map[string][]string",
    "ResponseBody":      "Byte array containing the raw HTTP response body",
    "ResponseHeader":    "Byte array containing the raw HTTP response header as a map[string][]string",
    "ResponseStatusCode":"Response status code"
}
```

**回应**：

```json
{
   "Allow":              "Determined whether the user is allowed or not",
   "Msg":                "The authorization message",
   "Err":                "The error message if things go wrong"
}
```

### 请求授权

每个插件必须支持两种请求授权消息格式，一种从**守护进程到插件**，然后从**插件到守护进程**。下表详细列出了每封邮件的预期内容。

#### 守护进程 - >插件

| 名称                                    | 类型        | 描述                                                         |
| --------------------------------------- | ----------- | ------------------------------------------------------------ |
| User                                    | 串          | 用户标识                                                     |
| Authentication method <br/>身份验证方法 | 串          | 使用的验证方法                                               |
| Request method  请求方法                | 枚举        | HTTP方法（GET / DELETE / POST）                              |
| Request URI  请求URI                    | 串          | 包含API版本的HTTP请求URI（例如，v.1.17 / containers / json） |
| Request headers  请求头                 | map[string] | 请求标头作为键值对（不含授权标头）                           |
| Request body  请求正文                  | byte[]      | 原始请求主体                                                 |

#### 插件 - >守护进程

| 名称  | 类型 | 描述                                                         |
| ----- | ---- | ------------------------------------------------------------ |
| Allow | 布尔 | 指示请求是允许还是拒绝的布尔值                               |
| Msg   | 串   | 授权消息（如果访问被拒绝，将返回给客户端）                   |
| Err   | 串   | 错误信息（如果插件遇到错误，将返回给客户端。提供的字符串值可能会出现在日志中，因此不应包含机密信息） |

### 响应授权

该插件必须支持两种授权消息格式，一种从守护进程到插件，然后从插件到守护进程。下表详细列出了每封邮件的预期内容。

#### 守护进程 - >插件

| 名称         | 类型              | 描述                                                         |
| ------------ | ----------------- | ------------------------------------------------------------ |
| 用户         | 串                | 用户标识                                                     |
| 身份验证方法 | 串                | 使用的验证方法                                               |
| 请求方法     | 串                | HTTP方法（GET / DELETE / POST）                              |
| 请求URI      | 串                | 包含API版本的HTTP请求URI（例如，v.1.17 / containers / json） |
| 请求标头     | map[string]string | 请求标头作为键值对（不含授权标头）                           |
| 请求正文     | byte []           | 原始请求主体                                                 |
| 响应状态码   | INT               | 来自docker守护程序的状态码                                   |
| 响应标题     | map[string]string | 响应标题作为键值对                                           |
| 响应机构     | byte []           | 原始码头守护程序响应正文                                     |

#### 插件 - >守护进程

| 名称  | 类型 | 描述                                                         |
| ----- | ---- | ------------------------------------------------------------ |
| Allow | 布尔 | 指示响应是被允许还是被拒绝的布尔值                           |
| Msg   | 串   | 授权消息（如果访问被拒绝，将返回给客户端）                   |
| Err   | 串   | 错误信息（如果插件遇到错误，将返回给客户端。提供的字符串值可能会出现在日志中，因此不应包含机密信息） |

# docker 插件

Docker插件是**进程外扩展**，它为Docker引擎添加了功能。<br/>本文档描述了Docker Engine插件API。要查看由Docker Engine管理的插件的信息，请参阅[Docker Engine插件系统](https://docs.docker.com/engine/extend/)。<br/>本页面适用于想要开发自己的Docker插件的人员。如果你只是想了解或使用Docker插件，请看 [这里](https://docs.docker.com/engine/extend/legacy_plugins/)。

## 什么插件

插件是**与docker守护进程运行在相同或不同主机上的进程**，它通过将文件放置在[插件发现中](https://docs.docker.com/engine/extend/plugin_api/#plugin-discovery)描述的插件目录之一中的同一个docker主机上进行注册。<br/>插件具有可读的名称，它们是短小的字符串。例如，`flocker`或`weave`。<br/>插件可以在容器内部或外部运行。目前建议在**容器外部运行**它们。

## 插件发现

每当用户或容器尝试按名称使用插件时，Docker都会通过在插件目录中查找插件来发现插件。

有三种类型的文件可以放在插件目录中。

- `.sock` 文件是UNIX域**套接字**。
- `.spec`文件是包含**URL的文本文件**，例如`unix:///other.sock`或`tcp://localhost:8080`。
- `.json` 文件是包含插件的**完整json**规范的文本文件。

具有UNIX域套接字文件的插件必须在**相同的docker主机**上运行，而具有spec或json文件的插件可以在**不同的主机**上运行（如果指定了远程URL）。<br/>UNIX域套接字文件必须位于下`/run/docker/plugins`，而规范的文件可以在位于`/etc/docker/plugins`或`/usr/lib/docker/plugins`。

文件的名称（不包括扩展名）决定了插件名称。例如，`flocker`插件可能会在中创建一个UNIX套接字 `/run/docker/plugins/flocker.sock`。如果想将相互隔离的定义隔离起来，可以将每个插件定义到一个**单独的子目录中**。例如，可以在容器内创建`flocker`套接字`/run/docker/plugins/flocker/flocker.sock`并仅将其安装`/run/docker/plugins/flocker`在`flocker`容器内。Docker总是首先搜索unix套接字`/run/docker/plugins`。它检查规范或json文件`/etc/docker/plugins`，`/usr/lib/docker/plugins`如果套接字不存在。目录扫描只要找到具有给定名称的第一个插件定义就会停止。

### JSON规范

这是插件的JSON格式：

```json
{
  "Name": "plugin-example",
  "Addr": "https://example.com/docker/plugin",
  "TLSConfig": {
    "InsecureSkipVerify": false,
    "CAFile": "/usr/shared/docker/certs/example-ca.pem",
    "CertFile": "/usr/shared/docker/certs/example-cert.pem",
    "KeyFile": "/usr/shared/docker/certs/example-key.pem"
  }
}
```

`TLSConfig`字段是可选的，只有在配置存在时才会验证TLS。

## 插件生命周期

**插件应该在Docker之前启动，并在Docker之后停止**。例如，在为支持的平台打包插件时`systemd`，可以使用[`systemd`依赖关系](http://www.freedesktop.org/software/systemd/man/systemd.unit.html#Before=)来管理启动和关闭顺序。

升级插件时，应首**先停止Docker守护程序**，升级插件，然后**再次启动Docker**。

## 插件激活

当插件**首次被引用**时， 无论是由用户引用它的名称（例如 `docker run --volume-driver=foo`）还是已经配置为使用插件的容器，Docker都会在插件目录中查找指定的插件，并通过**握手来激活它**。请参阅下面的握手API。

在Docker守护程序启动时插件**不会**自动激活。相反，它们只在需要时才会**被懒惰地或按需地激活**。

## Systemd套接字激活

插件也可能被套接字激活`systemd`。官方的[插件助手](https://github.com/docker/go-plugins-helpers) 本地支持套接字激活。为了插件被套接字激活，它需要一个`service`文件和一个`socket`文件。

`service`文件（例如`/lib/systemd/system/your-plugin.service`）：

```properties
[Unit]
Description=Your plugin
Before=docker.service
After=network.target your-plugin.socket
Requires=your-plugin.socket docker.service

[Service]
ExecStart=/usr/lib/docker/your-plugin

[Install]
WantedBy=multi-user.target
```

`socket`文件（例如`/lib/systemd/system/your-plugin.socket`）：

```properties
[Unit]
Description=Your plugin

[Socket]
ListenStream=/run/docker/plugins/your-plugin.sock

[Install]
WantedBy=sockets.target
```

当Docker守护进程连接到它们正在监听的套接字（例如守护进程第一次使用它们或者其中一个插件意外关闭）时，这将允许插件实际启动。

## API设计

插件API是基于HTTP的RPC风格的JSON，非常像webhook。<br/>请求流**从**docker守护**到**插件。所以插件需要实现一个HTTP服务器并将其绑定到“插件发现”部分提到的UNIX套接字。<br/>所有请求都是HTTP `POST`请求。<br/>API通过一个Accept标头进行版本控制，标头目前始终设置为 `application/vnd.docker.plugins.v1+json`。

## 握手API

通过以下**“握手”**API调用来**激活**插件。

### /Plugin.Activate

**要求：**empty body

**响应：**

```json
{
    "Implements": ["VolumeDriver"]
}
```

响应此插件实现的Docker子系统列表。激活后，插件将从这个子系统发送事件。

可能的值是：

- [`authz`](https://docs.docker.com/engine/extend/plugins_authorization/)
- [`NetworkDriver`](https://docs.docker.com/engine/extend/plugins_network/)
- [`VolumeDriver`](https://docs.docker.com/engine/extend/plugins_volume/)

## 插件重试

尝试调用插件上的方法将重试指数回退长达30秒。当将插件封装为容器时，这可能会有所帮助，因为它使得插件容器在发生依赖于它们的任何用户容器失败之前有机会启动。

## 插件助手

为了简化插件开发，我们为`docker/go-plugins-helpers`[中](https://github.com/docker/go-plugins-helpers)Docker目前支持的各种插件提供了一个`sdk`。