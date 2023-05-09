* [docker 常用命令](#docker-%E5%B8%B8%E7%94%A8%E5%91%BD%E4%BB%A4)
  * [docker VM](#docker-vm)
  * [docker 测试](#docker-%E6%B5%8B%E8%AF%95)
  * [docker 容器](#docker-%E5%AE%B9%E5%99%A8)
  * [docker 服务](#docker-%E6%9C%8D%E5%8A%A1)
  * [docker 集群](#docker-%E9%9B%86%E7%BE%A4)
  * [docker networks](#docker-networks)
  * [docker  volumes](#docker--volumes)
  * [docker compose](#docker-compose)
* [dockerfile 参考](#dockerfile-%E5%8F%82%E8%80%83)

# docker 常用命令

```shell
# image
# 建立一个镜像
$ docker image build --rm=true .
# 安装镜像
$ docker image pull ${IMAGE}
#已安装镜像的列表
$ docker image ls
# 已安装镜像列表（详细列表）
$ docker image ls --no-trunc
# 删除镜像
$ docker image rm ${IMAGE_ID}
# 删除未使用的镜像
$ docker image prune
# 删除所有镜像
$ docker image rm $(docker image ls -aq)
$ docker image rm -f $(docker image ls -a | grep alpine | awk '{ print $3 }')
$ docker image rm -f $(docker images | grep "<none>" | awk '{ print $3 }')

#container
# 运行一个容器
$ docker container run
# 正在运行的容器列表
$ docker container ls
# 所有容器的列表
$ docker container ls -a
# 停止一个容器
$ docker container stop ${CID}
# 停止所有运行的容器
$ docker container stop $(docker container ls -q)
# 列出状态为1的所有退出的容器
$ docker container ls -a --filter "exited=1"
# 取出一个容器
$ docker container rm ${CID}
# 通过正则表达式删除容器
$ docker container ls -a | grep wildfly | awk '{print $1}' | xargs docker container rm -f
# 删除所有已退出的容器
$ docker container rm -f $(docker container ls -a | grep Exit | awk '{ print $1 }')
# 删除所有容器
$ docker container rm $(docker container ls -aq)
# 查找容器的IP地址
$ docker container inspect --format '{{ .NetworkSettings.IPAddress }}' ${CID}
# 附加到一个容器
$ docker container attach ${CID}
# 进入一个容器，打开一个shell
$ docker container exec -it ${CID} bash
# 通过正则表达式获取镜像的容器标识
$ docker container ls | grep wildfly | awk '{print $1}'
```





## docker VM

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



## docker 测试

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
docker container ls					# 查看正在运行的容器
docker container ls --all					# 查看所有容器
docker container ls -aq						# 查看未运行的容器
docker-machine restart default				# 重启虚拟机

$ docker-machine ssh default 				# ssh 连接到default这台虚拟机
```



## docker 容器

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
docker login             			# 登录
docker tag <image> username/repository:tag  # 标签<image>用于上传到仓库
docker push username/repository:tag            # 上传标记的镜像到仓库
docker run username/repository:tag                   # 从仓库运行镜像，本地没有会先拉取镜像
docker push registry/username/repository:tag 
docker run registry/username/repository:tag

docker-machine ssh default                             # ssh 链接到虚拟机 default
docker-machine ip                             # 查看虚拟机ip地址
```



## docker 服务

```shell
docker stack ls                                      # 程序和堆列表
docker stack deploy -c <compose-yml-file> <appname>  # 部署compose.yml文件到堆
docker service ls                                      # 显示所有在运行的服务程序
docker service ps <service>                  		 # 显示所有程序服务的任务
docker inspect <task or container>                    # 检查任务或容器
docker container ls -q                                # 显示容器 IDs
docker stack rm <appname>                             # 关闭或删除容器程序
docker swarm leave --force                             # 强制关闭节点集群
docker swarm init --advertise-addr eth1               # 启动集群、暴露某个ip地址
```



## docker 集群

```shell
docker-machine create --driver virtualbox myvm1 	# 创建虚拟机 myvm1 (Mac, Win7, Linux)
docker-machine create -d hyperv --hyperv-virtual-switch "myswitch" myvm1 # Win10 下创建虚拟机
docker-machine env myvm1                		 # 查看myvm1节点基本信息
docker-machine ssh myvm1 "docker node ls"         # 查看myvm1集群节点信息
docker-machine ssh myvm1 "docker node inspect <node ID>"        # 检查节点
docker-machine ssh myvm1 "docker swarm join-token -q worker"   # 查看加入集群的token
docker-machine ssh myvm1							# ssh 链接到 VM; 退出输入 "exit" 结束
docker node ls								# 查看集群中的节点（登录到管理器时）
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

## docker networks

```sh
$ docker network -h
管理网络
Usage:  docker network COMMAND

命令：
  connect     # 将容器连接到网络
  create      # 创建一个网络
  disconnect  # 从网络断开容器
  inspect     # 在一个或多个网络上显示详细信息
  ls          # 列出网络
  prune       # 删除所有未使用的网络
  rm          # 删除一个或多个网络
-----------------------------------------------------------------

$ docker network ls
Options:
  -f, --filter filter   #提供过滤器值 (e.g. 'driver=bridge')
      --format string   #使用Go模板的漂亮打印网络
      --no-trunc        #不要截断输出
  -q, --quiet           #只显示网络ID
  
$ docker network ls --filter 'driver=host'		# 使用filter过滤查看
$ docker network ls --filter 'driver=host'
$ docker network ls --filter scope=swarm
# 查看自定义网络
$ docker network ls -f type=custom
$ docker network ls -f type=builtin

# 格式化输出
$ docker network ls --format "{{.Name}} \t {{.Driver}} \t {{.IPv6}} \t {{.Internal}} \t
# 长id
$ docker network ls --filter 'driver=host' -q
# 短 id
$ docker network ls --filter 'driver=host' -q --no-trunc
-----------------------------------------------------------------
$ docker network create -h
Usage:  docker network create [OPTIONS] NETWORK

创建一个网络

Options:
      --attachable           # 启用手动容器附件
      --aux-address map      # 使用的辅助IPv4或IPv6地址网络驱动程序（默认 map[])
      --config-from string   # 复制配置的网络
      --config-only          # 创建仅配置网络
  -d, --driver string        # Driver管理网络 (default "bridge")
      --gateway strings      # 主站子网的IPv4或IPv6网关
      --ingress              # 创建群组路由 - 网状集群网络
      --internal             # 限制对网络的外部访问
      --ip-range strings     # 从子网范围分配容器ip
      --ipam-driver string   # IP地址管理驱动程序 (default "default")
      --ipam-opt map         # 设置IPAM驱动程序特定选项 (default map[])
      --ipv6                 # 启用IPv6网络
      --label list           # 在网络上设置元数据
  -o, --opt map              # 设置驱动程序特定的选项 (default map[])
      --scope string         # 控制网络的范围
      --subnet strings       # 以CIDR格式表示的子网串网段

# 创建网络，默认桥接网络
$ docker network create my-default-bri-net
# 创建桥接网络
$ docker network create -d bridge my-bridge-net
$ docker network create -d host my-host-net
# 创建覆盖型网络
$ docker network create -d overlay my-overlay-net
# 创建mac网络
$ docker network create -d macvlan my-mac-net

$ docker run -itd --network=mynet busybox		# 将busybox容器添加到mynet网络
$ docker network create --driver=bridge --subnet=192.168.0.0/18 my-bri-0  #使用--subnet选项指定子网值
# 指定--gateway --ip-range和--aux-address 选项
$ docker network create \
  --driver=bridge \
  --subnet=172.28.0.0/16 \
  --ip-range=172.28.5.0/24 \
  --gateway=172.28.5.254 \
  br0
# 两个/25 子网掩码
$ docker network create -d overlay \
  --subnet=192.168.1.0/25 \
  --subnet=192.170.2.0/25 \
  --gateway=192.168.1.100 \
  --gateway=192.170.2.100 \
  --aux-address="my-router=192.168.1.5" --aux-address="my-switch=192.168.1.6" \
  --aux-address="my-printer=192.170.1.5" --aux-address="my-nas=192.170.1.6" \
  my-multihost-network
#使用-o或--opt选项在发布端口时指定IP地址绑定
$ docker network create \
    -o "com.docker.network.bridge.host_binding_ipv4"="172.19.0.1" \
    simple-network
# 网络内部模式
$ docker network create --internal -d overlay my-overlay-inte-net
# 网络ingress模式
$ docker network create -d overlay \
  --subnet=10.11.0.0/16 \
  --ingress \
  --opt com.docker.network.driver.mtu=9216 \
  --opt encrypted=true \
  my-ingress-network
-----------------------------------------------------------------
$ docker network connect [options] network container
Options:
      --alias strings           # 为容器添加网络范围的别名
      --ip string               # IPv4地址 (e.g., 172.30.100.104)
      --ip6 string              # IPv6地址 (e.g., 2001:db8::33)
      --link list               # 将链接添加到其他容器
      --link-local-ip strings   # 为容器添加链接本地地址
      
# 使用id 
$ docker network connect 61b951b60b24 91efc6379be0
# 使用name
$ docker network connect my-bridge-net suspicious_kepler
# 使用docker run --network=<network-name>选项启动容器并立即将其连接到网络
$ docker run -it --network=my-bridge-net helloworld-jdk-9:latest
$ docker run -itd --network=multi-host-network busybox
# 连接网络使用固定IP
$ docker network inspect my-bri-0 --format={{.IPAM.Config}}
[{192.168.0.0/18   map[]}]
$ docker network connect --ip 192.168.5.122 my-bri-0 suspicious_kepler
# 使用--link选项将另一个容器与首选别名链接起来
$ docker network connect --link silly_curie:my_container my-bridge suspicious_kepler
# 连接网络时创建网络别名
$ docker network connect --alias db --alias mysql multi-host-network container2
$ docker network connect --alias linux_os --alias ubuntu ps upbeat_ptolemy
# 区间网络
$ docker network create --subnet 172.20.0.0/16 --ip-range 172.20.240.0/20 multi-host-network

# 断开容器网络连接
$ docker network disconnect -f my-bridge-net friendly_jepsen
# 或者用id
$ docker network disconnect -f 568e61b512d0 c7fd77e7f301

$ docker network inspect my-mac-net		# 检查
$ docker network prune				# 删除未用
$ docker network prune --force --filter until=5m # 超过5分钟前创建的网络
```



## docker  volumes

```sh
$ docker volume create -h
--driver , -d	#默认值：local，指定卷驱动程序名称
--label		    #设置卷的元数据
--name		    #指定卷名称
--opt , -o		#设置驱动程序特定选项


$ docker volume create my-vol			# 创建卷
$ docker volume create hello			# 创建一个卷，然后配置容器以使用它
$ docker run -d -v hello:/world busybox ls /world
# 驱动程序特定的选项
$ docker volume create --driver fake \
    --opt tardis=blue \
    --opt timey=wimey \
    foo
# 创建一个名为foo的tmpfs卷，其大小为100兆字节，uid为1000
$ docker volume create --driver local \
    --opt type=tmpfs \
    --opt device=tmpfs \
    --opt o=size=100m,uid=1000 \
    foo
# type=btrfs 
$ docker volume create --driver local \
    --opt type=btrfs \
    --opt device=/dev/sda2 \
    foo
# 使用nfs从192.168.1.1开始以rw模式挂载/path/to/dir
$ docker volume create --driver local \
    --opt type=nfs \
    --opt o=addr=192.168.1.1,rw \
    --opt device=:/path/to/dir \
    foo
    

$ docker volume ls -f dangling=true			# 过滤器上没有任何容器引用的所有匹配卷
$ docker volume ls -f driver=local			# 匹配使用该local驱动程序创建的卷
# 标签过滤器
$ docker volume create the-doctor --label is-timelord=yes
$ docker volume create daleks --label is-timelord=no
$ docker volume ls --filter label=is-timelord
$ docker volume ls --filter label=is-timelord=yes
$ docker volume ls --filter label=is-timelord=yes --filter label=is-timelord=no
$ docker volume ls -f name=rose 			# 匹配所有包含该rose字符串的名称的卷

# 使用--format选项时，volume ls命令将按照模板声明输出数据
$ docker volume ls --format "{{.Name}}: {{.Driver}}"
$ docker volume ls --format "table {{.Name}}: {{.Driver}}"

# 检查
$ docker volume inspect my-vol				
$ docker volume inspect --format '{{ .Mountpoint }}' my-vol
$ docker volume inspect foo --format='{{json .Options}}'
$ docker volume inspect foo --format '{{json .Options}}'


$ docker volume rm hello e425b890f45			# 删除多个
$ docker volume rm -f hello e425b890f45			# 强制删除

$ docker volume prune				# 剪裁
$ docker volume prune -f			# 强制删除，不提示输入
$ docker volume prune -f --filter driver=local		## 过滤裁剪
```



## docker compose

```shell
$ docker-compose -h
使用Docker定义和运行多容器应用程序

Usage:
  docker-compose [-f <arg>...] [options] [COMMAND] [ARGS...]
  docker-compose -h|--help

Options:
  -f, --file FILE             指定一个备用的compose file
                              (默认: docker-compose.yml)
  -p, --project-name NAME     指定一个替代项目名称
                              (默认: 目录名称)
  --verbose                   显示更多输出
  --log-level LEVEL           设置日志级别 (DEBUG, INFO, WARNING, ERROR, CRITICAL)
  --no-ansi                   不要打印ANSI控制字符
  -v, --version               打印版本并退出
  -H, --host HOST             用于连接到的HOST守护程序套接字

  --tls                       使用TLS;--tlsverify
  --tlscacert CA_PATH         仅由此CA签署的信任证书
  --tlscert CLIENT_CERT_PATH  证书文件的路径
  --tlskey TLS_KEY_PATH       密钥文件的路径
  --tlsverify                 使用TLS并验证远程
  --skip-hostname-check       不要检查守护进程的主机名
                              在客户端证书中指定的名称
  --project-directory PATH    指定一个备用工作目录
                              (默认: Compose file的路径)
  --compatibility             如果设置，Compose将尝试转换部署
                              将v3文件中的密钥添加到其非Swarm等效项

Commands:
  build              构建或重建服务
  bundle             从Compose文件中生成一个Docker bundle
  config             验证并查看Compose file
  create             创建服务
  down               停止并移除容器，网络，镜像和卷
  events             接收来自容器的实时事件
  exec               在正在运行的容器中执行命令 
  images             镜像列表
  kill               杀死容器
  logs               查看容器的日志输出
  pause              暂停服务
  port               打印端口绑定的公共端口
  ps                 容器列表
  pull               拉取服务镜像
  push               推送服务镜像
  restart            重启服务
  rm                 移除停止的容器
  run                运行一次性命令
  scale              设置服务的容器数量
  start              开始服务
  stop               停止服务
  top                显示正在运行的进程
  unpause            暂停服务
  up                 创建并启动容器 
```



```shell
# 安装 docker-compose
$ sudo curl -L https://github.com/docker/compose/releases/download/1.21.0/docker-compose-$(uname -s)-$(uname -m) -o /usr/local/bin/docker-compose
# 授权
$ sudo chmod +x /usr/local/bin/docker-compose
$ docker-compose migrate-to-labels				# 升级compose
$ docker container rm -f -v myapp_web_1 myapp_db_1   # 删除容器
$ docker-compose up							# 启动应用
$ docker-compose up -d					# 后台模式启动应用
$ docker-compose stop					# 停止应用
$ docker-compose down					# 卸载应用
$ docker-compose ps						# 查看应用状态
$ docker-compose run web env			# 查看应用服务环境变量
$ docker-compose down --volumes			# 卸载应用并删除data数据
```



# dockerfile 参考

```dockerfile
#########################################################################################
## $ docker image rm -f $(docker image ls -a | grep "<none>" | awk '{ print $3 }')
## $ docker build --build-arg VERSION=latest -t docker_file:test . --no-cache
## $ docker build --build-arg VERSION=latest --build-arg BUILD_TIME=2018 -t docker_file:test . --no-cache
## $ docker inspect docker_file:test
## $ winpty docker run -it docker_file:test
## $ docker image ls -q 
## $ docker image ls -a 
##########################################################################################




#######################################################################
############################## 第一阶段构建 ############################
#######################################################################


#--------------------------------------------------------------
# 定义构建阶段、版本参数
#--------------------------------------------------------------
# 定义ARG参数变量，有默认值。
# 或者利用构建命令进行设置外部值 --build-arg VERSION=<value>
#
# 有资格在FROM 之前能出现的指令，只有ARG指令
# ARG 指令定义在FROM之前，就是提供给FROM使用的。
# 可以把FROM看成一个容器，FROM开始后表示一个构建阶段，在阶段中的属于一个独立容器，而在FROM之前的数据将在当前这个容器外面
# 在FROM使用后（容器内部）它的值就会无效，因为此时在构建阶段中，无法获取构建阶段前（容器外部）的参数数据（可以理解成一种数据隔离或者游离）
# 但是，如果在第二个阶段中再次使用当前构建阶段之前的参数，还是一样有效。因为第二阶段又是从新开始构建，和第一阶段处于同一种隔离环境
#--------------------------------------------------------------
ARG VERSION=latest
ARG BUILD_TIME=20101010


#--------------------------------------------------------------
# 申明构建阶段
#--------------------------------------------------------------
# 使用构建阶段之前的变量
# 重命名阶段构建 [as ubuntu_os] 为后续构建阶段中，可以通过别名访问到之前构建阶段的文件数据  
#--------------------------------------------------------------
FROM ubuntu:$VERSION as ubuntu_os
# 申明构建阶段  firstBuild
#FROM redis:v2.3 as firstBuild
#FROM redis@digest as firstBuild


#--------------------------------------------------------------
# 镜像作者设置（废弃）
#--------------------------------------------------------------
# 生成镜像作者的字段，可以用LABEL也能达到效果
#
# 执行$ docker inspect docker_file:test 
# 可以看到："Author": "hoojo@github.com",
#--------------------------------------------------------------
MAINTAINER hoojo@github.com
#LABEL maintainer="hoojo@home.org.au"


#--------------------------------------------------------------
# 重新设置参数值
#--------------------------------------------------------------
# 由于在构建阶段外部声明的参数，在构建阶段内部无法访问
# 此时需要进行重新赋值
# 或者利用构建命令进行设置外部值 --build-arg build_time=<value>
# $ docker build --build-arg CODE_VERSION=latest --build-arg VERSION=2.5 -t docker_file:latest .
# 如果ARG指令具有默认值，并且在构建时没有值传递，那么构建器将使用默认值
# 如果在构建时重新绑定值，将覆盖默认值
#--------------------------------------------------------------
ARG VERSION=latest-version
# 无默认值，构建时传递参数数据，相当于 --build-arg build_time=<value>
ARG BUILD_TIME



#--------------------------------------------------------------
# RUN 执行cmd/shell命令
#--------------------------------------------------------------
# 每个RUN行创建一个新的图层，推荐使用单行模式
#
# 运行shell模式：默认情况下/bin/sh -c在Linux或cmd /S /C Windows 上运行
# 可以指定特定的 cmd/shell 的执行软件，指定版本的shell命令中，参数需要引号
#
# RUN指令缓存在下一次构建期间不会自动失效。类似指令的缓存 RUN apt-get dist-upgrade -y将在下一次构建时重用。
# 例如，RUN指令缓存可以通过使用--no-cache 标志来使其失效docker build --no-cache
#--------------------------------------------------------------
# 输出使用变量参数
RUN echo $VERSION > tmp_file
RUN echo build time: $BUILD_TIME, version: ${VERSION}
RUN echo HOME: $HOME
# 指定特定的 cmd/shell 的执行软件，参数需要引号
RUN sh -c 'echo sh_HOME: $HOME'
RUN /bin/bash -c "echo bin/bash_HOME: $HOME"

# cmd 形式命令：创建一个目录
RUN mkdir .tmp
# cmd shell 向指定目录文件写入内容
RUN echo "docker cmd run, home: $HOME, version: ${VERSION} " > .tmp/test.txt
# 执行bash的shell
RUN bash -c 'echo "docker cmd run" > .tmp/test2.txt'



#--------------------------------------------------------------
# RUN 运行exec形式
#--------------------------------------------------------------
# 每个RUN行创建一个新的图层，推荐使用单行模式
#
# 运行exec形式相当于：exec bash.exe -c echo hello $VERSION
# exec 模式数组必须是双引号
# exec 模式不会执行变量替换操作
# exec 模式中传入指定shell，会执行变量替换操作
#
# RUN指令缓存在下一次构建期间不会自动失效。类似指令的缓存 RUN apt-get dist-upgrade -y将在下一次构建时重用。
# 例如，RUN指令缓存可以通过使用--no-cache 标志来使其失效docker build --no-cache
#--------------------------------------------------------------
#RUN [ 'echo', 'HOME: $HOME' ]
# 不会变量替换
RUN [ "echo", "VERSION: ${VERSION}" ]
# 会变量替换，指定 bash shell
RUN [ "bash", "-c", "echo bash hello $VERSION" ]
RUN ["/bin/bash", "-c", "echo bin bash hello $VERSION"]
# 指定 sh 的shell
RUN [ "sh", "-c", "echo $HOME" ]


#--------------------------------------------------------------
# RUN 执行cmd/shell命令————多行模式
#--------------------------------------------------------------
# 每个RUN行创建一个新的图层，推荐使用单行模式
# apt-get update在RUN声明中单独使用会导致缓存问题，并导致后续apt-get install指令失败
#
# 缓存破坏模式：RUN apt-get update && apt-get install -y
# 这种方式可确保的Dockerfile安装最新的软件包版本；
#
# 版本固定模式：指定软件包版本来实现缓存清除
# 版本固定强制构建查找特定版本，而不管缓存中的内容。该模式还可以减少由于所需软件包的意外更改而导致的故障。
#--------------------------------------------------------------
RUN ["ls", "/var/lib/apt/lists"]
# 确保的Dockerfile安装最新的软件包版本
# bash=4.4 为固定版本
#RUN apt-get update && apt-get install -y \
#	curl \
#	bash=4.* \
#	busybox	

#RUN apt-get update && apt-get install -y \
#	curl 



#--------------------------------------------------------------
# CMD 预期命令——镜像运行时命令
#--------------------------------------------------------------
# CMD在构建时不执行任何操作，但指定镜像的预期命令。
# 也就是说在构建阶段设置镜像在运行时触发的指令
#
# 可以使用CMD指令来运行镜像中包含的软件，以及任何参数
#
# CMD 语法和 RUN 雷同
# Dockerfile只能有一条CMD指令。如果列出多个CMD 则只有最后一个CMD会生效。
#
# 此方式建议少用：
# CMD的主要目的是为执行容器提供默认值。
# 这些默认值可以包含可执行文件，也可以省略可执行文件，在这种情况下，还必须指定一条ENTRYPOINT 指令。
#
# CMD 大多数情况下是提供一个可交互式shell 与 服务进行交互处理
# CMD 执行特定的 shell 需要具体的目录位置路径
#
# 不要混淆RUN使用CMD。RUN实际上运行一个命令并提交结果; CMD在构建时不执行任何操作，但指定镜像的预期命令
#
# exec模式：需要传递JSON数组参数，这意味着必须在单词周围使用双引号。需要指定脚本执行的shell
# ENTRYPOINT 传参模式：也是JSON格式，只不过不需要指定脚本执行的shell	
# shell模式：直接运行shell脚本
#--------------------------------------------------------------


#--------------------------------------------------------------
# CMD：exec 形式
#--------------------------------------------------------------
# exec模式：需要传递JSON数组参数，这意味着必须在单词周围使用双引号。需要指定脚本执行的shell
# exec 形式不会执行变量替换
# exec方式并直接执行一个shell格式时命令，它是在执行环境变量扩展的shell，而不是docker。
#--------------------------------------------------------------
# CMD ["bash", "-c", "echo hi~"]
# 基于服务的镜像 CMD 用法，假定当前镜像是基于curl、python 的镜像服务，就提供下面的CMD 入口比较合适
#CMD ["curl"]
#CMD ["python"]
#
# exec 不会执行变量替换
CMD [ "echo", "home path: $HOME" ]
# 直接执行命令行，输出内容；会执行变量替换
CMD ["sh", "-c", "echo hello ubuntu:16.04 os, home path: $HOME"]
# 显示帮助
CMD ["bash", "--help"]
# 如果 没有shell 的情况下运行你的程序，设置shell的位置
CMD ["/bin/myshell/run", "--help"]
# 执行命令：winpty docker run -it docker_file:test
# 镜像运行后，可以进行交互操作
CMD ["bash"]


#--------------------------------------------------------------
# CMD：shell模式
#--------------------------------------------------------------
# shell模式：直接运行shell脚本
# shell 模式默认是运行在  /bin/sh -c 
#
# 执行命令：winpty docker run -it docker_file:test
# 直接交互：$ winpty docker run -it docker_file:test sh echo Halloween
#--------------------------------------------------------------
# 直接运行命令
CMD echo "This is a test." | wc -
CMD ls
# 指定特定的 cmd/shell 的执行软件，参数需要引号；支持参数替换
CMD sh -c 'echo sh_HOME: $HOME'
CMD /bin/bash -c "echo bin/bash_HOME: $HOME"
# 镜像运行后，可以进行上面的命令输入交互操作
CMD bash


#--------------------------------------------------------------
# ENTRYPOINT：exec 模式
#--------------------------------------------------------------
# ENTRYPOINT 为容器的入口点，相当于main函数	
#
# ENTRYPOINT exec 模式：也是JSON格式，只不过不需要指定脚本执行的shell
# exec 模式是设置固定的默认命令和参数，要修改默认值可以用CMD
# 覆盖ENTRYPOINT 在build时设置--entrypoint
#--------------------------------------------------------------
# ENTRYPOINT 设置入口/命令
#ENTRYPOINT ["bash", "-c", "echo hello ubuntu:16.04 os"]

# 修改默认值参数
#ENTRYPOINT ["bash", "-c"]
#CMD ["echo hello ubuntu:16.04 os"]

# 修改默认值，查看最终命令：$ winpty docker exec -it [cid] ps aux
#ENTRYPOINT ["top", "-b"]
#CMD ["-c"]



#--------------------------------------------------------------
# ENTRYPOINT：shell 模式
#--------------------------------------------------------------
# ENTRYPOINT shell 模式：直接运行命令行的方式，相当于运行在： /bin/sh -c
# 将忽略任何CMD或docker run命令行参数
#--------------------------------------------------------------
#ENTRYPOINT exec top -b


#--------------------------------------------------------------
# CMD & ENTRYPOINT： 传参模式，主要模式
#--------------------------------------------------------------
# Dockerfile应至少指定一个CMD或ENTRYPOINT命令
# 在使用容器作为可执行文件时应该定义ENTRYPOINT 
# CMD应该用作为ENTRYPOINT命令定义默认参数或在容器中执行
# 在使用替代参数运行容器时CMD将被覆盖
#
# CMD的主要目的是为执行容器提供默认值	
#
# ENTRYPOINT 传参模式：也是JSON格式，只不过不需要指定脚本执行的shell
# ENTRYPOINT 一般位于最末端的行，否则会处于不可预期的错误
#--------------------------------------------------------------
# ENTRYPOINT 准备参数
#CMD ["-c", "echo hello ubuntu:16.04 os"]
# ENTRYPOINT 设置入口/命令
#ENTRYPOINT ["bash"]

# 固定执行一段脚本
#COPY scripts.sh ./
#RUN chmod +x ./scripts.sh
#ENTRYPOINT ["./scripts.sh"]

# 固定执行一段脚本，可接受交互参数
COPY docker-entrypoint.sh ./
RUN chmod +x ./docker-entrypoint.sh
ENTRYPOINT ["./docker-entrypoint.sh"]
CMD "bash"




#######################################################################
############################## 第二阶段构建 ############################
#######################################################################


#--------------------------------------------------------------
# ARG参数复用：阶段外
#--------------------------------------------------------------
# 利用第一阶段的参数进行构建
# 第一阶段外部声明的变量，在第一部结束后外部声明的变量可以复用
#--------------------------------------------------------------
FROM alpine:${VERSION} as alpine_build


#--------------------------------------------------------------
# ARG参数复用：阶段内
#--------------------------------------------------------------
# 第一阶段内部声明的参数不能在第二阶段内部复用：需要重新声明
# 如果不通过ARG声明，这里会取不到值
#
# 构建阶段内部ARG作用域仅限于当前构建阶段使用
# 就算通过 --bind-arg 从运行命令外部覆盖也需要再次声明
#--------------------------------------------------------------
ARG VERSION
ARG BUILD_TIME
# 如果不通过上面的ARG声明，这里会取不到值
RUN echo build time: $BUILD_TIME, version: ${VERSION}



#--------------------------------------------------------------
# 标签：多行模式
#--------------------------------------------------------------
# 标签用于记录一些描述的信息
#
# 空格必须被转义，需要用双引号将其包围
# 在Docker 1.10之前，单行标签和多行标签会影响图层数量
#
# 如果标签已经存在但使用不同的值，则最近应用的值将覆盖任何先前设置的值。
#--------------------------------------------------------------
LABEL com.example.version="0.0.1-beta"
LABEL vendor="ACME Incorporated"
LABEL com.example.release-date="2015-02-12"
LABEL com.example.version.is-production=""


#--------------------------------------------------------------
# 标签单行：模式
#--------------------------------------------------------------
# vender 数据被覆盖
# 查看标签：$ docker inspect
#--------------------------------------------------------------
LABEL com.cnblogs.hoojo.project="docker" \
		com.cnblogs.hoojo.author="hoojo" \
		com.cnblogs.hoojo.createdate="2018-04-22" \
		vendor="Overwrite ACME Incorporated"
		
		

#--------------------------------------------------------------
# 环境变量——多行模式
#--------------------------------------------------------------
# ENV的优先级要高于ARG
# ENV值始终保留在构建的镜像中
#
# 每个ENV行创建一个新的图层，所以要减少多行环境变量设置
# 在未来的图层中取消设置环境变量，它仍然会保留在此图层中
#--------------------------------------------------------------
ENV BUILD_TIME 20190818
ENV PG_MAJOR 9.3
ENV PG_VERSION 9.3.4
#RUN curl -SL http://example.com/postgres-$PG_VERSION.tar.xz | tar -xJC /usr/src/postgress && …
ENV PATH /usr/local/postgres-$PG_MAJOR/bin:$PATH


#--------------------------------------------------------------
# 解决问题：
# 每个ENV行创建一个新的图层，所以要减少多行环境变量设置
# 在未来的图层中取消设置环境变量，它仍然会保留在此图层中
#--------------------------------------------------------------
# 在单个图层中设置，使用和取消设置所有变量
# 把所有的命令放到一个shell脚本中，让RUN命令运行这个shell脚本
#--------------------------------------------------------------
# 设置环境变量，使用完毕后，立即删除取消 
RUN export ADMIN_USER="mark" \
    && echo $ADMIN_USER > ./mark \
    && unset ADMIN_USER



#--------------------------------------------------------------
# 环境变量——单行模式
#--------------------------------------------------------------
# 每个ENV行创建一个新的图层，所以要减少多行环境变量设置
#--------------------------------------------------------------
ENV PJ_VERSION=1.2 PJ_NAME=DOCKER_FILES



#--------------------------------------------------------------
# 工作目录
#--------------------------------------------------------------
# 始终使用绝对路径 WORKDIR
# 为Dockerfile中的任何RUN，CMD， ENTRYPOINT，COPY和ADD指令设置工作目录
#
# WORKDIR指令可以在Dockerfile中多次使用。如果提供了相对路径，它将相对于前一条WORKDIR指令的路径 
# WORKDIR指令可以解析先前使用的 ENV环境变量，且必须显示地设置的环境变量
#--------------------------------------------------------------
# 可以在当前目录中切换
WORKDIR /a
WORKDIR b
WORKDIR c
# 输出 /a/b/c
RUN pwd 
# 使用的 ENV环境变量
WORKDIR /$PJ_NAME
# 输出 /DOCKER_FILES
RUN pwd
# 从新定义工作目录
WORKDIR /workspace



#--------------------------------------------------------------
# VOLUME：公共存储挂载
#--------------------------------------------------------------
# 用于公开数据存储区域，或由docker容器创建的文件/文件夹、可变和用户可维护部分
#
# 可以是JSON数组或纯字符串与多个参数
#
# 注意事项：
# - 基于Windows的容器上的卷：1. 一个不存在的或空的目录；2.除了 C: 盘
# - 更改Dockerfile内的卷：如果任何构建步骤在声明后更改了卷内的数据，则这些更改将被丢弃。
# - JSON格式：JSON数组，必须用双引号
# - 主机目录在容器运行时声明：不能在Dockerfile中挂载一个主机目录，必须在创建或运行容器时指定挂载点
#--------------------------------------------------------------

# JSON 数组格式
VOLUME ["/var/log/"]
VOLUME ["/var/log/", "/var/data"]
# 字符串形式
VOLUME "/var/log/" "/var/data"



#--------------------------------------------------------------
# User：设置用户
#--------------------------------------------------------------
# 如果服务可以在没有权限的情况下运行，则使 USER更改为非root用户。
# /etc/passwd /etc/group
# 首先创建用户和组：
#		RUN groupadd -r my_user_group && useradd --no-log-init -r -g my_user_group user_guest
# Debian/Ubuntu adduser包不支持该--no-log-init
# --no-log-init 可以解决日志体积庞大的空字符占位符
# 
# USER指令设置的用户和组在运行镜像时以及在Dockerfile中执行任何RUN、CMD和ENTRYPOINT指令时使用
#--------------------------------------------------------------
# 添加系统用户和组
RUN groupadd -r my_user_group && useradd --no-log-init -r -g my_user_group user_guest
# 通过 cat /etc/passwd 和 /etc/group 查看gid/uid
# USER user:group
USER user_guest:my_user_group 
# USER gid:uid
USER 999:999

RUN mkdir /tmp/mydata



#--------------------------------------------------------------
# ADD：添加文件到容器中
#--------------------------------------------------------------
# - ADD [--chown=<user>:<group>] <src>... <dest>
# - ADD [--chown=<user>:<group>] ["<src>",... "<dest>"]
# user -> /etc/passwd
# group -> /etc/group
#
# 支持映射，设置gid/uid后，文件的操作权将被限制
# ADD --chown=55:mygroup files* /somedir/
# ADD --chown=bin files* /somedir/
# ADD --chown=1 files* /somedir/
# ADD --chown=10:11 files* /somedir/
#
# docker build的第一步是将上下文目录（和子目录）发送到docker守护进程。
# 当发出一个docker build命令时，当前的命令中的构建目录被称为“构建上下文”
#
# 当前工作目录是：/d/docker/dockerfile_sample
# 这里的 . 指向 当前工作目录：$ docker build --build-arg VERSION=latest -t docker_file:test . --no-cache
# 所以 最终的构建上下文目录是： /d/docker/dockerfile_sample   
#
# 当前工作目录是：/d/docker/
# 这里的  dockerfile_sample/tmp 指 当前构建目录：
#		 $ docker build --no-cache --build-arg VERSION=latest -t docker_file:test -f dockerfile_sample/Dockerfile dockerfile_sample/tmp
# 所以 最终的构建上下文目录是：/d/docker/dockerfile_sample/tmp
#
# 支持将本地的tar提取和远程URL数据添加到容器
# 由于镜像大小很重要，因此ADD强烈建议不要使用从远程URL获取软件包; 
# 你应该使用curl或wget代替。这样，可以删除解压缩后不再需要的文件，并且不必在镜像中添加其他图层
#
# 文件匹配支持 *, ? [] 表达式和转义字符
# ? 匹配一个字符
# * 匹配多个字符
#--------------------------------------------------------------
# 会促使镜像体积庞大，不推荐
#ADD http://example.com/big.tar.xz /usr/src/things/
#RUN tar -xJf /usr/src/things/big.tar.xz -C /usr/src/things
#RUN make -C /usr/src/things all

# 替代上面的操作，使用完可以删除下载文件，进行瘦身
#RUN mkdir -p /usr/src/things \
#    && curl -SL http://example.com/big.tar.xz \
#    | tar -xJC /usr/src/things \
#    && make -C /usr/src/things all

# 在本地生成准备文件操作
#cmd.exe mkdir -p ./tmp/ \
#	&& cd ./tmp \
#	&& echo "add home file" > home.txt \
#	&& echo "add docker file" > docker.txt \
#	&& echo "add array file" > arr[0].txt \
#	&& echo "add relativeDir" > relative_dir.txt \
#	&& echo "add absoluteDir" > absolute_dir.txt \
#	&& ls \
#	&& pwd 

RUN ls .

# 模糊匹配和转义操作： 文件匹配支持 *, ? [] 表达式和转义字符
#--------------------------------------------------------------
# 匹配到ho 开头的文件或目录
ADD tmp/ho*.txt mydir/ 
# 匹配到dock开头，.txt后缀结尾的文件
ADD tmp/dock??.txt mydir/  
# 匹配到arr[0] 带中括号的文件
ADD tmp/arr[[]0].txt mydir/ 
RUN ls mydir/

# 相对绝对路径操作：
#--------------------------------------------------------------
# 相对路径：添加文件 relative_dir.txt 到 `WORKDIR`/relativeDir/ 目录下
ADD tmp/relative_dir.txt relativeDir/          
# 绝对路径：添加文件 absolute_dir.txt 到 /absoluteDir/ 目录下
ADD tmp/absolute_dir.txt /absoluteDir/
RUN ls /absoluteDir/
RUN	ls .

# 规则-1：src 必须在当前构建的上下文中；下面的提示 禁止 构建上下文之外的路径
#ADD ../docker-compose.yml mydir/
# 规则-2：src是URL并且dest不以尾部斜线结尾，则从URL下载文件内容将被复制到dest(文件)中
#ADD http://example.com/big.tar.xz downloads
# 规则-3：<src>是一个URL并且<dest>以结尾的斜线结尾，那么文件名将从url中推断出来，并将该文件下载到该URL<dest>/<filename>。
# 将创建该文件downloads/big.tar.xz
#ADD http://example.com/big.tar.xz downloads/
# 规则-4：<src>是目录，则复制目录的全部内容，包括文件系统元数据。目录本身不被复制，只是它的内容
#ADD http://example.com/bigdir downloads/
# 规则-5：<src>是以可识别的压缩格式（identity，gzip，bzip2、xz）的本地 tar归档文件，则将其解压缩为目录(前提是该文件必须是压缩文件，不以后缀为准)
# 远程 URL的资源不被解压缩
ADD tmp/big.rar downloads.rar
# 规则-6：<src>指定了多个资源（直接或由于使用通配符），则<dest>必须是目录，并且必须以斜线结尾/
ADD tmp/* mydir/
# 规则-7：<dest>不以尾部斜线结尾，则将其视为常规文件，<src>并将写入内容到<dest>
ADD tmp/big.rar big_file
# 规则-7：<dest>不存在，则会在其路径中创建所有缺少的目录
ADD tmp/big.rar new_dir/



#--------------------------------------------------------------
# COPY：复制本地文件到容器中
#--------------------------------------------------------------
# COPY 仅支持将本地文件复制到容器中
# COPY 是优选的，这是因为它比ADD更透明
# COPY 每一步都有缓存，当文件被更改缓存失效
# 
# 可以选择COPY接受一个选项--from=<name|index>，
# 该选项可用于将源位置设置为之前的构建阶段（使用创建的FROM .. AS <name>），这将用于代替用户发送的构建上下文。
# 该选项还接受为以FROM指令开始的所有先前构建阶段分配的数字索引。
# 如果无法找到具有指定名称的构建阶段，则尝试使用具有相同名称的镜像。
#
# 其他方面和ADD 一致！！！
#--------------------------------------------------------------
# 使用阶段重命名————从ubuntu_os构建阶段中复制文件数据
# 指定名称的构建阶段，则尝试使用具有相同名称的镜像
# COPY --from=ubuntu_os .tmp/test.txt .
# COPY 其他操作可以参考ADD
COPY tmp/big.rar new_dir/



#--------------------------------------------------------------
# 暴露容器内部的端口
#--------------------------------------------------------------
# 端口有两种模式：tcp/udp，默认为：tcp端口
#
# docker network 进行网络链接容器时，促使容器和容器之间通信，可以不暴露端口到外部
# 例如：使用两个容器之间redis/mysql，可以不需要暴露端口。若提供外部应用访问才需要暴露端口。
#
# 可以一行暴露一个端口，也可以多个端口一起暴露
# 暴露端口后可以通过 docker run -p 命令进行映射绑定才能访问
# 			docker run -p 80:80/tcp -p 80:80/udp
#--------------------------------------------------------------
EXPOSE 8090/tcp
EXPOSE 8070/udp
# 同时暴露2个接口
EXPOSE 7777 8888



#--------------------------------------------------------------
# Docker在构建子镜像之前执行ONBUILD命令：
#--------------------------------------------------------------
# ONBUILD在从当前镜像派生的任何子镜像中执行，
# 把这个ONBUILD命令看作父Dockerfile给子Dockerfile的一条指令
#
# ONBUILD指令在镜像被用作另一个构建的基础时，在镜像上添加将在稍后执行的触发指令。
# 触发器将在下游构建的上下文中执行，就像它已经在下游 Dockerfile的FROM指令之后立即插入一样。
# ONBUILD对于将从给定镜像的基础上构建其他镜像非常有用
#
# ONBUILD 建立的镜像应该得到一个单独的标签，例如： ruby:1.9-onbuild或ruby:2.0-onbuild
# 以便于区分父镜像是否有onbuild操作
#
# 
# 以下是它的工作原理：
# 	1. 当遇到一条ONBUILD指令时，构建器会为正在构建的镜像的元数据添加一个触发器。该指令不会影响当前的构建。
#	2. 在构建结束时，所有触发器的列表都存储在镜像清单中关键字ONBUILD下。可以用docker inspect命令检查。
#	3. 稍后可以使用FROM指令将镜像用作新版本的基础镜像 。作为处理FROM指令的一部分，
#		下游构建器查找ONBUILD触发器，并按照它们注册顺序执行它们。
#		如果任何触发器失败，FROM指令将中止，从而导致构建失败。如果所有触发器都成功，
#		则FROM指令完成并且构建将像往常一样继续。
#	4. 触发器在执行后从最终镜像中清除。不会存在超大子镜像的情况
#--------------------------------------------------------------
#ONBUILD ADD *.sh ./sh/
#ONBUILD ADD . /app/src
#ONBUILD RUN /usr/local/bin/python-build --dir /app/src



#--------------------------------------------------------------
# 检查容器的健康状况
#--------------------------------------------------------------
# 通过在容器中运行一个命令来检查容器的健康状况
#
# - HEALTHCHECK [OPTIONS] CMD command （通过在容器中运行一个命令来检查容器的健康状况）
# - HEALTHCHECK NONE （禁用从基础镜像继承的任何健康检查）
#
# 可以显示的选项CMD是：
# 	- --interval=DURATION（运行间隔，默认值：30s）
# 	- --timeout=DURATION（超时时间，默认值：30s）
# 	- --start-period=DURATION（启动期限，默认值：0s）
# 	- --retries=N（重试次数，默认值：3）
#
# 检查返回值是：
#	- 0：成功 - 容器健康并且可以使用
#	- 1：不健康 - 容器工作不正常
#	- 2：保留 - 不要使用此退出代码

# Dockerfile中只能有一条HEALTHCHECK指令。如果列出多个，则只有最后一个HEALTHCHECK会生效
# 当容器的健康状况发生变化时，将使用新状态生成一个health_status事件:可以监控 docker events 命令
#--------------------------------------------------------------
HEALTHCHECK --interval=5m --timeout=3s \
  CMD curl -f http://localhost/ || exit 1
  
#HEALTHCHECK CMD /bin/check-running  
#HEALTHCHECK CMD ["bash", "-c", "/bin/check-erroring"]



#--------------------------------------------------------------
# SHELL 命令
#--------------------------------------------------------------
# SHELL指令允许覆盖用于shell命令形式的默认shell
# SHELL指令可以多次出现。每条SHELL指令都会覆盖所有先前的SHELL指令，并影响所有后续指令
#
# - Linux上的默认shell是["/bin/sh", "-c"]，在Windows上是["cmd", "/S", "/C"]。
# - SHELL指令必须以JSON格式写入Dockerfile中
#--------------------------------------------------------------
SHELL ["sh", "-c"]
RUN echo 'sh shell cmd'
# 如果后面不出现shell，那么随后的指令都会用sh 去运行

# 指定 bash，随后指令都以 bash
SHELL ["bash", "-c"]
RUN echo 'bash shell cmd'



# 输出变量: cmd echo 'hello alpine_build $VERSION'
RUN echo 'hello alpine_build $VERSION'
# 运行cmd命令，查看文件内容
CMD ["sh", "-c", "cat test.txt"]
CMD bash
```



**scripts.sh**

```sh
#!/bin/bash
echo "hello"
```



**docker-entrypoint.sh**

```shell
#!/usr/bin/env bash
set -Eeuo pipefail

# first arg is `-f` or `--some-option`
# or there are no args
if [ "$#" -eq 0 ] [ "${1#-}" != "$1" ]; then
	
	# docker run bash -c 'echo hi'
	# $ winpty docker run -it docker_file:test -c 'echo hi docker'	

	exec bash "$@"
fi

exec "$@"
```

