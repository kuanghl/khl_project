# Vagrant 的安装和使用

* [Vagrant 的安装和使用](#vagrant-%E7%9A%84%E5%AE%89%E8%A3%85%E5%92%8C%E4%BD%BF%E7%94%A8)
* [安装 Vagrant](#%E5%AE%89%E8%A3%85-vagrant)
* [Vagrant 基本操作](#vagrant-%E5%9F%BA%E6%9C%AC%E6%93%8D%E4%BD%9C)
  * [基本命令](#%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
    * [创建虚拟机](#%E5%88%9B%E5%BB%BA%E8%99%9A%E6%8B%9F%E6%9C%BA)
    * [启动虚拟机](#%E5%90%AF%E5%8A%A8%E8%99%9A%E6%8B%9F%E6%9C%BA)
    * [连接虚拟机](#%E8%BF%9E%E6%8E%A5%E8%99%9A%E6%8B%9F%E6%9C%BA)
    * [关闭虚拟机](#%E5%85%B3%E9%97%AD%E8%99%9A%E6%8B%9F%E6%9C%BA)
    * [销毁虚拟机](#%E9%94%80%E6%AF%81%E8%99%9A%E6%8B%9F%E6%9C%BA)
  * [高级命令](#%E9%AB%98%E7%BA%A7%E5%91%BD%E4%BB%A4)
    * [查看虚拟机box文件](#%E6%9F%A5%E7%9C%8B%E8%99%9A%E6%8B%9F%E6%9C%BAbox%E6%96%87%E4%BB%B6)
    * [查看虚拟机box列表](#%E6%9F%A5%E7%9C%8B%E8%99%9A%E6%8B%9F%E6%9C%BAbox%E5%88%97%E8%A1%A8)
    * [删除虚拟机 box](#%E5%88%A0%E9%99%A4%E8%99%9A%E6%8B%9F%E6%9C%BA-box)
    * [查看已下载的虚拟机box](#%E6%9F%A5%E7%9C%8B%E5%B7%B2%E4%B8%8B%E8%BD%BD%E7%9A%84%E8%99%9A%E6%8B%9F%E6%9C%BAbox)
    * [打包虚拟机 box](#%E6%89%93%E5%8C%85%E8%99%9A%E6%8B%9F%E6%9C%BA-box)
  * [配置选项](#%E9%85%8D%E7%BD%AE%E9%80%89%E9%A1%B9)
    * [端口映射转发](#%E7%AB%AF%E5%8F%A3%E6%98%A0%E5%B0%84%E8%BD%AC%E5%8F%91)
    * [共享挂载目录](#%E5%85%B1%E4%BA%AB%E6%8C%82%E8%BD%BD%E7%9B%AE%E5%BD%95)
    * [provision](#provision)
    * [网络设置](#%E7%BD%91%E7%BB%9C%E8%AE%BE%E7%BD%AE)
    * [虚拟机提供商](#%E8%99%9A%E6%8B%9F%E6%9C%BA%E6%8F%90%E4%BE%9B%E5%95%86)
    * [配置结果示例](#%E9%85%8D%E7%BD%AE%E7%BB%93%E6%9E%9C%E7%A4%BA%E4%BE%8B)
* [命令行汇总](#%E5%91%BD%E4%BB%A4%E8%A1%8C%E6%B1%87%E6%80%BB)
* [参考资料](#%E5%8F%82%E8%80%83%E8%B5%84%E6%96%99)

# 概述

`Vagrant`是为所有人设计的，作为创建虚拟环境的最简单快捷的方式。`Vagrant`是一款用于在单个工作流程中构建和管理虚拟机环境的工具。 凭借易于使用的**工作流程**和专注于**自动化**，`Vagrant`降低了开发环境设置时间，提高了产品开发效率。

`Vagrant`提供易于配置，可重复使用的便携式工作环境，构建于业界标准技术之上，并由单一一致的工作流程控制，帮助您最大限度地提高您和团队的生产力和灵活性。

为了达到它的效率，`vagrant` 站在巨人的肩膀上。计算机配置在`VirtualBox`，`VMware`，`AWS`或[任何其他提供商](https://www.vagrantup.com/docs/providers/)之上 。然后使用行业标准 [配置工具](https://www.vagrantup.com/docs/provisioning/) （如`shell`，`Chef`或`Puppet`）可以自动在虚拟机上安装和配置软件。

`vagrant` 工具就是一个用命令行和脚本的方式，帮你创建虚拟机和安装虚拟机里面的软件的一个工具。并且它支持把安装好的环境进行打包成`*.box`，然后在其他机器上再通过`vagrant`很方便的添加到机器上。 

## 优点

+ 适合所有人，创建虚拟机最简单快捷
+ 专注于**工作流程**和专注于**自动化**
+ 降低了开发环境设置时间，提高了产品开发效率。提高团队的生产力和灵活性
+ 易于配置，可重复使用的便携式工作环境

安装 Vagrant
===

下载安装文件：https://www.vagrantup.com/downloads.html

选择适合电脑的版本，安装完成后重启电脑。重启后使用命令`vagrant version`检测安装

```sh
$ vagrant version
```

Vagrant 基本操作
===
## 基本命令

```sh
$ vagrant list-commands
# 以下是所有可用的Vagrant命令和简要的列表

box             # 管理box：安装，拆卸等
cap             # 检查和执行能力
destroy         # 停止并删除虚拟机器的所有痕迹
docker-exec     # 附加到已经运行的docker容器
docker-logs     # 输出来自Docker容器的日志
docker-run      # 在容器的上下文中运行一次性命令
global-status   # 输出此用户的虚拟机环境的状态
halt            # 停止虚拟机
help            # 显示子命令的帮助
init            # 通过创建一个Vagrantfile来初始化一个新的Vagrant环境
list-commands   # 输出所有可用的Vagrant子命令，甚至是非主要的子命令
login           # 登录HashiCorp的Vagrant Cloud
package         # 将一个虚拟机包装到一个盒子里
plugin          # 管理插件：安装，卸载，更新等
port            # 显示有关访客端口映射的信息
powershell      # 通过PowerShell远程连接到机器
provider        # 显示此环境的提供者，VirtualBox，VMware，AWS
provision       # 重新执行上次命令以继续从上次失败的位置继续运行
push            # 会将此环境中的代码部署到配置的目标
rdp             # 通过RDP连接到机器
reload          # 重新启动vagrant机器，加载新的Vagrantfile配置
resume          # 恢复暂停的 vagrant machine
rsync           # 同步rsync同步文件夹到远程机器
rsync-auto      # 在文件更改时自动同步rsync同步文件夹
snapshot        # 管理快照：保存，恢复等。
ssh             # 通过SSH连接到机器
ssh-config      # 输出OpenSSH有效配置以连接到机器
status          # 输出虚拟机的状态
suspend         # 挂机
up              # 启动并provisions虚拟机环境
validate        # 验证Vagrantfile
version         # 打印当前和最新的Vagrant版本
```

### 创建虚拟机

---

- **创建或初始化一个虚拟机环境，和`git`创建仓库有些类似**

  ```shell
  $ cd /box/work/mybox
  $ vagrant init ubuntu/trusty64
  ```

  执行上面的`init`命令后其实就是在是在当前目录下创建了一个`Vagrantfile`的文件。打开这个文件看看，里面有当前虚拟机的名称和一些注释掉的配置。

  `Vagrant`还会在`Vagrantfile`所在同级目录下创建一个`.vagrant`隐藏文件夹，该文件夹包含了在本地运行虚拟机的一些信息。如果使用了代码库管理（比如`Git`），这个`.vagrant`文件夹应该被`ignore`掉。同时这个目录还存在一个私钥`private_key`


- **如果已经有一个现有的`box`，那可以这样操作**

  ```shell
  $ vagrant box add my-box-file.box  --name mybox
  ```

  上面的命令是在当前目录里有一个`my-box-file.box`的文件，添加到当前环境中，它的名称叫`mybox`

  ```shell
  $ vagrant box add --name mybox http://pan.baidu.com/AsFS24D/my-box-file.box
  ```

  添加一个box在远程服务器上，程序会自动到这个地址下载。然后添加这个box到虚拟机上名称为`mybox`


- **创建一个远程现有的`box`** 

  ```shell
  $ vagrant init mybox https://boxes.company.com/my-project.box
  ```

  上面的`mybox`是虚拟机名称，后面的网址是远程的虚拟机文件


### 启动虚拟机

---

**启动虚拟机 `vagrant up`就可以启动当前虚拟机了**，此时`vagrant`会检查本地是否有`ubuntu/trusty64`这个虚拟机的`trusty`的`ubuntu`版本（`Ubuntu Server 14.04 LTS (Trusty Tahr) daily builds`），如果没有就会从官网https://atlas.hashicorp.com来下载`ubuntu/trusty64`这个`box`，这个过程的速度看网络好坏。

```shell
$ vagrant up
Bringing machine 'default' up with 'virtualbox' provider...
==> default: Box 'ubuntu/trusty64' could not be found. Attempting to find and install...
    default: Box Provider: virtualbox
    default: Box Version: >= 0
==> default: Loading metadata for box 'ubuntu/trusty64'
    default: URL: https://vagrantcloud.com/ubuntu/trusty64
==> default: Adding box 'ubuntu/trusty64' (v20180409.0.0) for provider: virtualbox
    default: Downloading: https://vagrantcloud.com/ubuntu/boxes/trusty64/versions/20180409.0.0/providers/virtualbox.box
    default: Download redirected to host: cloud-images.ubuntu.com
    default: Progress: 0% (Rate: 15769/s, Estimated time remaining: 10:00:35)
```

从上面的日志可以看到，程序会先去找`'ubuntu/trusty64'`没有找到，于是就去匹配`vagrant`虚拟镜像配置
`URL: https://vagrantcloud.com/ubuntu/trusty64`，它会配置虚拟机的名称和使用的虚拟机软件。<br/>下载`vagrant`的`box`文件： https://vagrantcloud.com/ubuntu/boxes/trusty64/versions/20180409.0.0/providers/virtualbox.box

```shell
Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/trusty64"
  config.vm.box_version = "20180409.0.0"
end

1 provider for this version.
virtualbox Externally hosted (cloud-images.ubuntu.com)
```

云镜像仓库：` cloud-images.ubuntu.com`<br/>上面的网址都可以打开看看，你就明白了`Vagrant`是如何去下载、匹配文件的。<br/>`vagrant up`这个命令会默认使用`Virtualbox`，如果需要使用其他的虚拟机产品可以设置`vagrant up --provider hyperv` 这里的`hyperv`是一个虚拟机产品，如：`VMware`、`Virtualbox`

### 连接虚拟机

---


- **`ssh`连到虚拟机**，`vagrant ssh`就可以直接连接到当前虚拟机。

  如果当前目录没有`Vagrantfile`就无法进行连接，这是有两种办法，一种是进入到虚拟机目录 `/box/work/mybox`(存在`Vagrantfile`文件的目录)
  另一种则是：

  ```shell
  $ vagrant.exe global-status
  id       name    provider   state   directory
  ---------------------------------------------------------------------------------------
  ccbaaf6  default virtualbox running /box/work/mybox

  The above shows information about all known Vagrant environments
  on this machine. This data is cached and may not be completely
  up-to-date. To interact with any of the machines, you can go to
  that directory and run Vagrant, or you can use the ID directly
  with Vagrant commands from any directory. For example:
  "vagrant destroy 1a2b3c4d"
  ```

  找到当前启动虚拟机的信息，然后用`vagrant ssh ID`连入

  ```shell
  $ vagrant ssh ccbaaf6
  ```

  **此时`vagrant`将使用默认的用户`vagrant`以及预设的`SSH`公钥密钥键值对直接登录虚拟机。**


### 关闭虚拟机

---

- **关闭虚拟机 `vagrant halt`**

  关闭正在运行的虚拟机，当你的工作目录不在虚拟机目录下 ` vagrant.exe halt ID`


### 销毁虚拟机

---

- **删除销毁虚拟机 `vagrant destroy`**

  **该操作只会删除虚拟机，不会删除虚拟机对应的`box`**

高级命令
---

### 查看虚拟机`box`文件

---

**添加和查看当前机器上安装或下载的`box`**，在当前用户`Administrator`目录`C:\Users\Administrator\.vagrant.d\boxes\`

```shell
$ cd ~/.vagrant.d/boxes
```


### 查看虚拟机`box`列表

---

**列举出本地所有下载好的`box`文件信息**

```shell
$ vagrant box list
ubuntu/xenial64 (virtualbox, 20180410.0.0)
```


### 删除虚拟机 `box`

---

**删除本地的`box`信息** `vagrant box remove box-name`

```shell
$ vagrant box remove box-name
```

### 查看已下载的虚拟机`box`

---

**查看正在运行的虚拟机** `vagrant global-status`

```shell
$ vagrant global-status
```

### 打包虚拟机 `box`

---

打包`box`可以让之前安装好的环境重复使用，比如将自己机器的工作环境打包成一个`box`，以后去其他公司或者网络封闭的场所时，把这个打包好的`box`直接添加到新机器上直接就可以使用了。而不需要重复安装一些软件，这样避免了错误也省去了大量的时间精力，毕竟安装软件是一些苦力活，对网络的也有要求。

```shell
$ vagrant halt
# 这里的mybox是虚拟机的名称，在 Vagrantfile 有指定虚拟机的情况下可以这样使用
$ vagrant package --base mybox
```

> 这样就创建了一个打包，打包完成后可以拷贝到其他地方使用。注意在打包之前要关闭虚拟机。

如果当前打包的目录是在`Vagrantfile`所在目录(这样当前命令就直接指向了当前配置对应的虚拟机)，那就可以直接打包

```shell
$ vagrant halt
$ vagrant package
```


配置选项
---

### 端口映射转发
---

- **端口映射转发**，多用于在宿主主机或外部主机访问虚拟机不能访问的情况，解决方法如下，在`Vagrantfile`中加入配置：

  ```shell
  Vagrant.configure("2") do |config|
    config.vm.network "forwarded_port", guest: 8080, host: 8888
  end
  ```

  在默认情况下，`Vagrant`所创建的`Virtualbox`虚拟机使用的是`NAT`网络类型，即外界是不能直接访问你的虚拟机的，就连宿主（装`Virtualbox`软件的这台机器）机器也访问不了。此时，如果你在虚拟机中启动的一个`Tomcat`来部署网站的测试环境，而又想外界能够访问的话，你需要使用端口转发。

  通过上面的配置后，宿主主机的`8888`端口转发到了虚拟机的`8080`端口，这样你便可以通过在宿主主机上访问 http://localhost:8888 来访问虚拟机的`Tomcat`了。对于`Virtualbox`来说，只有`NAT`类型的网络类型支持端口转发，这也是为什么`Vagrant`创建的`Virtualbox`虚拟机默认都有一个支持`NAT`的虚拟网卡，原因就是要能够支持`Vagrant`级别的端口转发。另外，`Vagrant`在第一次尝试连接虚拟机时使用的也是`NAT`。




### 共享挂载目录
---

**共享挂载目录到虚拟机上**，在`Vagrantfile`中加入配置：

```shell
Vagrant.configure("2") do |config|
  config.vm.synced_folder "images/", "/home/files/images"
end
```

上面的配置是将当前`Vagrantfile`所在目录下的`images`挂载在虚拟机`/home/files/images`上



### `provision` 
---

- `provision` 规定虚拟机运行一段特定的 **命令或脚本**。简单地说，`provision`即通过使用某些工具自动地、批量地为机器安装软件以及配置系统，它省去了人工安装和配置系统时的重复性和易错性，当然还享受了计算机与生俱来的速度。Vagrant提供多种方式对虚拟机进行`provision`，包括`Shell`、`Chef`、`Puppet`和`Ansible`等。以`Shell`为例，既可以通过直接在`Vagrantfile`中编写`Shell`脚本的方式，也可以通过引用外部Shell文件的方式。

  ```ruby
  Vagrant.configure("2") do |config|
    config.vm.provision "shell", inline: "echo hello"
  end

  # 多行命令
  config.vm.provision "shell", inline: <<-SHELL
       apt-get update
       apt-get install -y apache2
  SHELL
  ```

  上面的配置是系统在执行`vagrant provision`的时候就会输出 `hello`

  ```ruby
  Vagrant.configure("2") do |config|
    config.vm.provision "shell", path: "script.sh"
  end
  ```

  > 上面的配置引用外部脚本 ` "script.sh"`

    

- 下面介绍下  **`ansible` 批量自动化任务**

  > ansible是新出现的自动化运维工具，基于Python开发，集合了众多运维工具（puppet、cfengine、chef、func、fabric）的优点，实现了批量系统配置、批量程序部署、批量运行命令等功能。
  >
  > ansible是基于模块工作的，本身没有批量部署的能力。真正具有批量部署的是ansible所运行的模块，ansible只是提供一种框架。主要包括：
  >
  > (1)、连接插件connection plugins：负责和被监控端实现通信；<br/>(2)、host inventory：指定操作的主机，是一个配置文件里面定义监控的主机；<br/>(3)、各种模块核心模块、command模块、自定义模块；<br/>(4)、借助于插件完成记录日志邮件等功能；<br/>(5)、playbook：剧本执行多个任务时，非必需可以让节；
  >
  > ansible 使用指南：<http://www.ansible.com.cn/index.html><br/>
  > ansible 文档：<https://yq.aliyun.com/articles/86760?t=t1>

  ​

  在使用`ansible`批量自动化任务时，有两种方式：<br/>
    （1）在宿主主机机器上安装`ansible`<br/>
    （2）采用`ansible local`的方式，即在虚拟机自身上安装`ansible`<br/>
    对于第（1）种方法，我们需要保证宿主主机机器上已经安装了`ansible`，然后进行配置：

  ```ruby
    Vagrant.configure("2") do |config|

    	# Run Ansible from the Vagrant Host
    	config.vm.provision "ansible" do |ansible|
    		ansible.playbook = "playbook.yml"
    	end
    end
  ```

  在使用第（2）种方法时，`Vagrant`会首先检查box中是否已经安装了`ansible`，如果没有，则会自动安装到虚拟机上，然后再运行`provision`：

  ```ruby
    Vagrant.configure("2") do |config|
    	# Run Ansible from the Vagrant VM
    	config.vm.provision "ansible_local" do |ansible|
    		ansible.playbook = "playbook.yml"
    	end
    end
  ```

  > 当我们多次执行`vagrant up`启动虚拟机时，`provison`并不会每次都执行，只有在这三种情况下provision才会运行：
  >
  > 首次执行`vagrant up`<br/>执行`vagrant provision`<br/>执行`vagrant reload --provision`

  ​

  当然，你也可以在`Vagrantfile`中配置成每次执行`vagrant up`时都运行`provision`：

  ```ruby
  Vagrant.configure("2") do |config|
  	config.vm.provision "shell", inline: "echo hello",
  	run: "always"
  end
  ```




### 网络设置
---

- 配置私有固定`ip`网络，**可以在宿主主机直接通过`ip`访问到虚拟机的任何资源**

  ```shell
  Vagrant.configure("2") do |config|
    config.vm.network "private_network", ip: "192.168.33.77"
  end
  ```

- 配置动态`ip`使用`DHCP`的方式动态分配`ip`

  ```shell
  Vagrant.configure("2") do |config|
    config.vm.network "private_network", type: "dhcp"
  end
  ```

- 配置共有的固定`ip`网络

  ```shell
  Vagrant.configure("2") do |config|
    config.vm.network "public_network", ip: "192.168.1.15"
  end
  ```




### 虚拟机提供商

---

配置虚拟机主机源`Provider`

不同的`Provider`有不同的特性，也存在不同的配置方式。以`Virtualbox`为例，`Vagrant`默认会给虚拟机指定一个不具备可读性的名字，比如`mybox_default_1523517449396_15013`，我们可以对此进行配置予以更改：

```shell
config.vm.provider "virtualbox" do |v|
  v.name = "mybox"
end
```
`Provider`的特定配置也可以覆盖`Vagrant`原来的配置：

```shell
Vagrant.configure("2") do |config|
  config.vm.box = "precise64"

  config.vm.provider "vmware_fusion" do |v, override|
    override.vm.box = "precise64_fusion"
  end
end
```



### 配置结果示例

---

  通过上面的一些基本配置，可以看到结果成效：

  ```shell
  $ vagrant.exe up
  Bringing machine 'default' up with 'virtualbox' provider...
  ==> default: Checking if box 'ubuntu/trusty64' is up to date...
  #==> default: Setting the name of the VM: mybox
  ==> default: Clearing any previously set forwarded ports...
  ==> default: Clearing any previously set network interfaces...
  ==> default: Preparing network interfaces based on configuration...
      default: Adapter 1: nat
  ==> default: Forwarding ports...
      #default: 8080 (guest) => 8888 (host) (adapter 1)
      default: 22 (guest) => 2222 (host) (adapter 1)
  ==> default: Booting VM...
  ==> default: Waiting for machine to boot. This may take a few minutes...
      default: SSH address: 127.0.0.1:2222
      default: SSH username: vagrant
      default: SSH auth method: private key
      default: Warning: Connection reset. Retrying...
      default: Warning: Connection aborted. Retrying...
      default: Warning: Remote connection disconnect. Retrying...
  ==> default: Machine booted and ready!
  ==> default: Checking for guest additions in VM...
      default: The guest additions on this VM do not match the installed version of
      default: VirtualBox! In most cases this is fine, but in rare cases it can
      default: prevent things such as shared folders from working properly. If you see
      default: shared folder errors, please make sure the guest additions within the
      default: virtual machine match the version of VirtualBox you have installed on
      default: your host and reload your VM.
      default:
      default: Guest Additions Version: 4.3.36
      default: VirtualBox Version: 5.1
  ==> default: Mounting shared folders...
      #default: /vagrant => D:/box/work/mybox
      #default: /home/files/images => D:/box/work/mybox/images
  ==> default: Machine already provisioned. Run `vagrant provision` or use the `--provision`
  ==> default: flag to force provisioning. Provisioners marked to run always will still run.
  ==> default: Running provisioner: shell...
      default: Running: inline script
      #default: hello wellcome my world!
  ```

  > 注释部分就是自定义配置的内容，已经生效。



# 命令行汇总

```shell
$ vagrant init ubuntu/trusty64              # 创建或初始化一个虚拟机环境
$ vagrant box add my-box-file.box  --name mybox # 在当前目录里有一个my-box-file.box的文件，添加到当前环境中，它的名称叫mybox
$ vagrant box add --name mybox http://pan.baidu.com/AsFS24D/my-box-file.box  # 添加一个box在远程服务器上
$ vagrant init mybox https://boxes.company.com/my-project.box   # 添加远程的虚拟机文件
$ vagrant up				# 启动虚拟机
$ vagrant global-status 	 # 查看所有虚拟机状态
$ vagrant ssh ccbaaf6        # ssh 连接虚拟机，通过上面状态查询的id
$ vagrant halt				# 关闭虚拟机
$ vagrant halt [id]			# 关闭指定id虚拟机
$ vagrant destroy			# 删除销毁虚拟机
$ vagrant box list			# 列举已安装的虚拟机
$ vagrant box remove box-name    # 删除虚拟机box-name
$ vagrant package				# 打包虚拟机
$ vagrant package --base mybox	 # 打包虚拟机
```



# 参考资料

http://www.cnblogs.com/davenkin/p/vagrant-ansible-gocd.html