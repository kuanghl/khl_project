# docker compose 服务编排

* [docker compose 服务编排](#docker-compose-%E6%9C%8D%E5%8A%A1%E7%BC%96%E6%8E%92)
* [compose 用例参考](#compose-%E7%94%A8%E4%BE%8B%E5%8F%82%E8%80%83)
* [compose 服务编排配置详解](#compose-%E6%9C%8D%E5%8A%A1%E7%BC%96%E6%8E%92%E9%85%8D%E7%BD%AE%E8%AF%A6%E8%A7%A3)
  * [build 构建](#build-%E6%9E%84%E5%BB%BA)
    * [context 上下文](#context-%E4%B8%8A%E4%B8%8B%E6%96%87)
    * [dockerfile](#dockerfile)
    * [args 参数](#args-%E5%8F%82%E6%95%B0)
    * [cache\_from 缓存](#cache_from-%E7%BC%93%E5%AD%98)
    * [lables 标签](#lables-%E6%A0%87%E7%AD%BE)
    * [shm\_size 分区大小](#shm_size-%E5%88%86%E5%8C%BA%E5%A4%A7%E5%B0%8F)
    * [target 目标](#target-%E7%9B%AE%E6%A0%87)
  * [cap\_add，cap\_drop 添加删除容器](#cap_addcap_drop-%E6%B7%BB%E5%8A%A0%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8)
  * [command 命令](#command-%E5%91%BD%E4%BB%A4)
  * [configs 配置](#configs-%E9%85%8D%E7%BD%AE)
    * [短语法](#%E7%9F%AD%E8%AF%AD%E6%B3%95)
    * [长语法](#%E9%95%BF%E8%AF%AD%E6%B3%95)
  * [cgroup\_parent 上级组](#cgroup_parent-%E4%B8%8A%E7%BA%A7%E7%BB%84)
  * [container\_name 容器名称](#container_name-%E5%AE%B9%E5%99%A8%E5%90%8D%E7%A7%B0)
  * [credential\_spec 凭据规范](#credential_spec-%E5%87%AD%E6%8D%AE%E8%A7%84%E8%8C%83)
  * [deploy 部署](#deploy-%E9%83%A8%E7%BD%B2)
    * [endpoint\_mode 端点模式](#endpoint_mode-%E7%AB%AF%E7%82%B9%E6%A8%A1%E5%BC%8F)
    * [labels 标签](#labels-%E6%A0%87%E7%AD%BE)
    * [mode 模式](#mode-%E6%A8%A1%E5%BC%8F)
    * [placement 分布位置](#placement-%E5%88%86%E5%B8%83%E4%BD%8D%E7%BD%AE)
    * [replicas 副本](#replicas-%E5%89%AF%E6%9C%AC)
    * [resources 资源](#resources-%E8%B5%84%E6%BA%90)
      * [Out Of Memory Exceptions 内存异常（OOME）](#out-of-memory-exceptions-%E5%86%85%E5%AD%98%E5%BC%82%E5%B8%B8oome)
    * [restart\_policy 重启策略](#restart_policy-%E9%87%8D%E5%90%AF%E7%AD%96%E7%95%A5)
    * [update\_config 更新配置](#update_config-%E6%9B%B4%E6%96%B0%E9%85%8D%E7%BD%AE)
  * [不支持 DOCKER STACK DEPLOY](#%E4%B8%8D%E6%94%AF%E6%8C%81-docker-stack-deploy)
  * [devices 设备](#devices-%E8%AE%BE%E5%A4%87)
  * [depends\_on 依赖](#depends_on-%E4%BE%9D%E8%B5%96)
  * [dns](#dns)
  * [dns\_search](#dns_search)
  * [tmpfs 临时文件系统](#tmpfs-%E4%B8%B4%E6%97%B6%E6%96%87%E4%BB%B6%E7%B3%BB%E7%BB%9F)
  * [entrypoint 入口点](#entrypoint-%E5%85%A5%E5%8F%A3%E7%82%B9)
  * [env\_file 环境变量文件](#env_file-%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F%E6%96%87%E4%BB%B6)
  * [environment 环境变量](#environment-%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
  * [expose 暴露](#expose-%E6%9A%B4%E9%9C%B2)
  * [external\_links 外部链接](#external_links-%E5%A4%96%E9%83%A8%E9%93%BE%E6%8E%A5)
  * [extra\_hosts 主机映射](#extra_hosts-%E4%B8%BB%E6%9C%BA%E6%98%A0%E5%B0%84)
  * [healthcheck 健康检查](#healthcheck-%E5%81%A5%E5%BA%B7%E6%A3%80%E6%9F%A5)
  * [image 镜像](#image-%E9%95%9C%E5%83%8F)
  * [isolation 隔离](#isolation-%E9%9A%94%E7%A6%BB)
  * [labels 标签](#labels-%E6%A0%87%E7%AD%BE-1)
  * [links 链接](#links-%E9%93%BE%E6%8E%A5)
  * [logging 日志](#logging-%E6%97%A5%E5%BF%97)
  * [network\_mode 网络模式](#network_mode-%E7%BD%91%E7%BB%9C%E6%A8%A1%E5%BC%8F)
  * [networks 网络](#networks-%E7%BD%91%E7%BB%9C)
    * [aliases 别名](#aliases-%E5%88%AB%E5%90%8D)
    * [IPV4\_ADDRESS，IPV6\_ADDRESS 静态地址](#ipv4_addressipv6_address-%E9%9D%99%E6%80%81%E5%9C%B0%E5%9D%80)
  * [pid](#pid)
  * [port 端口](#port-%E7%AB%AF%E5%8F%A3)
    * [短语法](#%E7%9F%AD%E8%AF%AD%E6%B3%95-1)
    * [长语法](#%E9%95%BF%E8%AF%AD%E6%B3%95-1)
  * [secrets  秘密](#secrets--%E7%A7%98%E5%AF%86)
    * [短语法](#%E7%9F%AD%E8%AF%AD%E6%B3%95-2)
    * [长语法](#%E9%95%BF%E8%AF%AD%E6%B3%95-2)
  * [security\_opt 安全](#security_opt-%E5%AE%89%E5%85%A8)
  * [stop\_grace\_period 退出等待时间](#stop_grace_period-%E9%80%80%E5%87%BA%E7%AD%89%E5%BE%85%E6%97%B6%E9%97%B4)
  * [stop\_signal 停止信号](#stop_signal-%E5%81%9C%E6%AD%A2%E4%BF%A1%E5%8F%B7)
  * [sysctls 内核参数](#sysctls-%E5%86%85%E6%A0%B8%E5%8F%82%E6%95%B0)
  * [ulimits](#ulimits)
  * [userns\_mode 用户命名空间](#userns_mode-%E7%94%A8%E6%88%B7%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4)
  * [volumes 卷](#volumes-%E5%8D%B7)
    * [短语法](#%E7%9F%AD%E8%AF%AD%E6%B3%95-3)
    * [长语法](#%E9%95%BF%E8%AF%AD%E6%B3%95-3)
    * [服务、集群和编排文件的卷](#%E6%9C%8D%E5%8A%A1%E9%9B%86%E7%BE%A4%E5%92%8C%E7%BC%96%E6%8E%92%E6%96%87%E4%BB%B6%E7%9A%84%E5%8D%B7)
  * [restart 重启策略](#restart-%E9%87%8D%E5%90%AF%E7%AD%96%E7%95%A5)
  * [domainname, hostname, ipc, mac\_address, privileged, read\_only, shm\_size, stdin\_open, tty, user, working\_dir](#domainname-hostname-ipc-mac_address-privileged-read_only-shm_size-stdin_open-tty-user-working_dir)
  * [指定持续时间](#%E6%8C%87%E5%AE%9A%E6%8C%81%E7%BB%AD%E6%97%B6%E9%97%B4)
  * [指定字节值](#%E6%8C%87%E5%AE%9A%E5%AD%97%E8%8A%82%E5%80%BC)
* [示例参考](#%E7%A4%BA%E4%BE%8B%E5%8F%82%E8%80%83)
  * [volumes 配置参考](#volumes-%E9%85%8D%E7%BD%AE%E5%8F%82%E8%80%83)
    * [driver](#driver)
    * [driver\_opts](#driver_opts)
    * [external](#external)
    * [labels](#labels)
    * [name](#name)
  * [networks 配置参考](#networks-%E9%85%8D%E7%BD%AE%E5%8F%82%E8%80%83)
    * [driver](#driver-1)
      * [bridge](#bridge)
      * [overlay](#overlay)
      * [host 或 none](#host-%E6%88%96-none)
    * [driver\_opts](#driver_opts-1)
    * [attachable](#attachable)
    * [enable\_ipv6](#enable_ipv6)
    * [ipam](#ipam)
    * [internal](#internal)
    * [labels](#labels-1)
    * [external](#external-1)
    * [name](#name-1)
  * [configs  配置参考](#configs--%E9%85%8D%E7%BD%AE%E5%8F%82%E8%80%83)
  * [secrets 配置参考](#secrets-%E9%85%8D%E7%BD%AE%E5%8F%82%E8%80%83)
  * [env 变量表达式](#env-%E5%8F%98%E9%87%8F%E8%A1%A8%E8%BE%BE%E5%BC%8F)
  * [扩展字段](#%E6%89%A9%E5%B1%95%E5%AD%97%E6%AE%B5)

# compose 用例参考
使用Compose堆栈文件来实现多容器应用程序，服务定义和集群模式。文件结构参考：

```yaml
version: "3"
services:

  redis:
    image: redis:alpine
    ports:
      - "6379"
    networks:
      - frontend
    deploy:
      replicas: 2
      update_config:
        parallelism: 2
        delay: 10s
      restart_policy:
        condition: on-failure

  db:
    image: postgres:9.4
    volumes:
      - db-data:/var/lib/postgresql/data
    networks:
      - backend
    deploy:
      placement:
        constraints: [node.role == manager]

  vote:
    image: dockersamples/examplevotingapp_vote:before
    ports:
      - 5000:80
    networks:
      - frontend
    depends_on:
      - redis
    deploy:
      replicas: 2
      update_config:
        parallelism: 2
      restart_policy:
        condition: on-failure

  result:
    image: dockersamples/examplevotingapp_result:before
    ports:
      - 5001:80
    networks:
      - backend
    depends_on:
      - db
    deploy:
      replicas: 1
      update_config:
        parallelism: 2
        delay: 10s
      restart_policy:
        condition: on-failure

  worker:
    image: dockersamples/examplevotingapp_worker
    networks:
      - frontend
      - backend
    deploy:
      mode: replicated
      replicas: 1
      labels: [APP=VOTING]
      restart_policy:
        condition: on-failure
        delay: 10s
        max_attempts: 3
        window: 120s
      placement:
        constraints: [node.role == manager]

  visualizer:
    image: dockersamples/visualizer:stable
    ports:
      - "8080:8080"
    stop_grace_period: 1m30s
    volumes:
      - "/var/run/docker.sock:/var/run/docker.sock"
    deploy:
      placement:
        constraints: [node.role == manager]

networks:
  frontend:
  backend:

volumes:
  db-data:
```



# compose 服务编排配置详解

`Compose`文件是一个定义[服务](https://docs.docker.com/compose/compose-file/#service-configuration-reference)、 [网络](https://docs.docker.com/compose/compose-file/#network-configuration-reference)和 [卷](https://docs.docker.com/compose/compose-file/#volume-configuration-reference)的[YAML](http://yaml.org/)文件 。`Compose`文件的默认路径是。`./docker-compose.yml`

> **提示**：可以对此文件使用 `.yml`或`.yaml`扩展名都支持。

服务定义包含应用于为该服务启动的每个容器的配置，就像命令行参数传递给 `docker container create`一样。同样，网络和卷的定义类似于 `docker network create`和`docker volume create`。

正如`docker container create`在`Dockerfile`指定选项，如`CMD`， `EXPOSE`，`VOLUME`，`ENV`，注意在默认情况下——你不需要再次指定它们`docker-compose.yml`。

你可以使用Bash类`${VARIABLE}`语法在配置值中使用环境变量 - 有关完整详细信息，请参阅 [变量替换](https://docs.docker.com/compose/compose-file/#variable-substitution)。

下面介绍服务定义所支持的所有配置选项的列表。需要创建好文件，文件目录结构如下：

```shell
D:\DOCKER\COMPOSE_SAMPLE
│  docker-compose.yml
│
└─sample
        app.py
        Dockerfile
        Dockerfile-alternate
        requirements.txt
```

`docker-compose.yml` 将是下面演示需要修改的文件，`sample` 目录存放应用程序的文件。



## `build` 构建

在构建时应用的配置选项。

`build`可以指定为构建上下文的路径，**`build`后面的字符串将指向构建程序的真实路径**，下面的代码build指向的路径是 当前`compose`文件所在目录下的`sample `目录。

```yaml
version: '3'
services:
  webapp:
    build: ./sample # 当前docker-compose.yml文件所在目录下的 sample目录
```

在 `docker-compose.yml`文件所在目录中执行命令 `docker-compose build`构建程序
```shell
$ docker-compose build
Building webapp
.....
```

或者，用`context`指定应用的路径，并且可以使用`dockerfile` 指定`Dockerfile` 文件名称和`args` 指定当前构建的参数数据，作为环境变量使用：

```yaml
version: '3'
services:
  webapp:
    build:
      context: ./sample  # 当前docker-compose.yml文件所在目录下的 sample目录
      dockerfile: Dockerfile-alternate # 备用的 dockerfile 文件名称
      args: # 构建参数
        buildno: 1 
```

如果指定`image` 和 `build`，那么文件中指定的`image: webapp:first`将是构建镜像名称：

```yaml
  webapp:
    image: webapp:first # 镜像名称
    build:
      context: ./sample     
```

随后可以运行命令`docker-compose config`检查 `docker-compose.yml`配置是否正确。

**这将产生一个名为`webapp`和`tag`标记为`first`的镜像，该镜像由目录`./sample`内容构建。**

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署编排堆栈服务时，](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。`docker stack`命令仅接受预先构建的镜像。



### `context` 上下文

---

可以是`Dockerfile`所在的目录的路径，也可以是`Git`仓库的`url`。

当`context`的值是相对路径时，它被解释为相对于`docker-compose.yam`文件的位置。这个目录也是推送到Docker守护进程的构建上下文。

```yaml
build:
  context: ./sample
```



### `dockerfile` 

---

备用`Dockerfile`。`compose`命令使用替代文件来构建，还必须指定构建路径 `build` 的值。

```yacas
 build:
      context: ./sample
      dockerfile: Dockerfile-alternate
```

在 `sample` 目录中必须有文件名称为 `Dockerfile-alternate`的`dockerfile`



### `args` 参数

---

添加构建参数，这些参数是仅在构建过程中可访问的环境变量。

首先，在`Dockerfile-alternate`中指定参数：

```dockerfile
ARG buildno
ARG author

RUN echo "Build number: $buildno"
RUN echo "Build author: $author"
```

然后指定`build`键下的参数。可以传递一个映射或一个列表：

```yaml
build:
  context: .
  args:
    buildno: 1
    author: hoojo
    
### 或者如下写法
build:
  context: .
  args:
    - buildno: 1
    - author: hoojo    
```

重新构建后会看到输出信息中出现我们定义输出的内容

```shell
$ docker-compose build

Step 6/9 : RUN echo "Build number: ${buildno}"
 ---> Running in 1611c23cbdb6
Build number: 1
Removing intermediate container 1611c23cbdb6
 ---> e2ea0d5585da
Step 7/9 : RUN echo "Build author: $author"
 ---> Running in fc12e0ee505b
Build author: hoojo
```

指定构建参数时可以省略该值，在这种情况下，构建时的值是运行环境中的值。

```yaml
args:
  - buildno
  - author
```

> **注**：YAML布尔值（`true`，`false`，`yes`，`no`，`on`，`off`）必须用引号括起来，以便解析器将它们解释为字符串。



### `cache_from` 缓存

---

引擎用于缓存解析的镜像列表。**在版本：3.2 可用**

```yaml
build:
  context: .
  cache_from:
    - redis:latest
    - hoojo/web_app:3.14
```



### `lables` 标签

---

使用[Docker标签](https://docs.docker.com/engine/userguide/labels-custom-metadata/)将元数据添加到生成的镜像中。可以使用数组或字典。建议使用反向DNS标记来防止标签与其他软件使用的标签冲突。**注意：**这个选项在v3.3中可用

```shell
build:
  context: .
  labels:
    com.example.description: "Accounting webapp"
    com.example.department: "Finance"
    com.example.label-with-empty-value: ""

build:
  context: .
  labels:
    - "com.example.description=Accounting webapp"
    - "com.example.department=Finance"
    - "com.example.label-with-empty-value"
```



### `shm_size` 分区大小

---

设置`/dev/shm`容器的分区大小。指定为表示字节数的整数值或表示[字节值](https://docs.docker.com/compose/compose-file/#specifying-byte-values)的字符串。**在3.5版本中可用**

```yaml
build:
  context: .
  shm_size: '2gb'


build:
  context: .
  shm_size: 10000000
```



### `target` 目标

---

根据构建阶段在`Dockerfile`中定义指定目标配置。**在3.4版本可用**

```yaml
  build:
    context: .
    target: prod # 在dockerfile中的prod 构建阶段
```



## `cap_add，cap_drop` 添加删除容器

添加或删除容器功能。请参阅`man 7 capabilities`完整列表。

```yaml
cap_add:
  - ALL

cap_drop:
  - NET_ADMIN
  - SYS_ADMIN
```

> **注意**：[在](https://docs.docker.com/engine/reference/commandline/stack_deploy/) 使用（版本3）Compose文件的[集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时，会忽略这些选项 。



## `command` 命令

启动后执行的命令，会覆盖默认命令。

```yaml
command: bundle exec thin -p 3000
```

该命令也可以是一个列表，方式类似于 [dockerfile](https://docs.docker.com/engine/reference/builder/#cmd)：

```yaml
command: ["bundle", "exec", "thin", "-p", "3000"]
```

在`docker-compose.yml`文件中加入配置`    command: echo "hello!"` ，执行启动后发现输出日志

```shell
$ docker-compose up
Creating network "composesample_default" with the default driver
Creating composesample_webapp_1 ... done
Attaching to composesample_webapp_1
webapp_1  | hello!
composesample_webapp_1 exited with code 0
```



## `configs` 配置

使用每项服务`configs` 配置为每个服务授予对配置的访问权限。支持两种不同的语法变体。

> **注意**：配置必须已经存在或 [在`configs`](https://docs.docker.com/compose/compose-file/#configs-configuration-reference) 此堆栈文件[的顶层](https://docs.docker.com/compose/compose-file/#configs-configuration-reference)[配置](https://docs.docker.com/compose/compose-file/#configs-configuration-reference)中[定义](https://docs.docker.com/compose/compose-file/#configs-configuration-reference)，否则堆栈部署失败。

### 短语法

短的语法体只能指定配置名称。这会授予容器对配置的访问权限并将其装载到容器中的`/<config_name>`处。源名称和目标装入点都设置为配置名称。

以下示例使用简短语法将`redis`服务访问权限授予`my_config`和`my_other_config`configs。值`my_config`被设置为文件的内容`./my_config.txt`，并被 `my_other_config`定义为外部资源，这意味着它已经在Docker中定义，可以通过运行该`docker config create` 命令或通过另一个堆栈部署。如果外部配置不存在，则堆叠部署失败并出现`config not found`错误。

> **注**：`config`定义仅在3.3版及更高版本的compose文件格式中受支持。

```yaml
version: "3.3"
services:
  redis:
    image: redis:latest
    deploy:
      replicas: 1
    configs:
      - my_config
      - my_other_config
configs:
  my_config:
    file: ./my_config.txt
  my_other_config:
    external: true
```

### 长语法

长的语法提供了更多的粒度，以便在服务的任务容器中如何配置。

- `source`：它在Docker中存在的配置名称。
- `target`：要在服务的任务容器中装载的文件的路径和名称。如果未指定，则默认为`/<source>`。
- `uid`以及`gid`：在服务的任务容器中拥有安装的配置文件的数字UID或GID。`0`如果未指定，则默认为在Linux上。Windows不支持。
- `mode`：在服务的任务容器中安装的文件的权限，以八进制表示法。例如，`0444` 代表世界可读的。默认是`0444`。配置文件无法写入，因为它们安装在临时文件系统中，所以如果设置了可写位，它将被忽略。可执行位可以被设置。如果你不熟悉UNIX文件权限模式，则可能会发现此 [权限计算器](http://permissions-calculator.org/) 很有用。

以下示例在容器中将`my_config`的名称设置为`redis_config`，将模式设置为`0440`（可读组），并将用户和组设置为`103`. `redis`服务无法访问`my_other_config`配置。

```yaml
version: "3.5"
services:
  redis:
    image: redis:latest
    deploy:
      replicas: 1
    configs:
      - source: my_config
        target: /redis_config
        uid: '103'
        gid: '103'
        mode: 0440
configs:
  my_config:
    file: ./my_config.txt
  my_other_config:
    external: true
```

你可以授予多个配置的服务访问权限，并且你可以混合使用长短语法。定义配置并不意味着授予服务访问权限。

## `cgroup_parent` 上级组

为容器指定一个可选的父cgroup。

```yaml
cgroup_parent: m-executor-abcd
```

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署堆栈时，](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。



## `container_name` 容器名称

指定一个自定义容器名称，而不是生成的默认名称。

```yaml
version: '3.5'
services:
  webapp:
    container_name: webapp_first
    image: webapp:first
```

由于Docker容器名称必须是唯一的，因此如果指定了自定义名称，则无法将服务扩展到1个容器之外。试图这样做会导致错误。

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署堆栈时，](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。

```shell
$ docker-compose.exe ps
    Name         Command     State    Ports
-------------------------------------------
webapp_first   echo hello!   Exit 0
```



## `credential_spec` 凭据规范

> **注意**：该选项已添加到v3.3中

为托管服务帐户配置凭据规范。此选项仅用于使用Windows容器的服务。在`credential_spec`必须在格式`file://<filename>`或`registry://<value-name>`。

使用时`file:`，引用的文件必须存在于`CredentialSpecs` docker数据目录的子目录中，该目录默认为`C:\ProgramData\Docker\` 在Windows上。以下示例从名为的文件加载凭证规范`C:\ProgramData\Docker\CredentialSpecs\my-credential-spec.json`：

```yaml
credential_spec:
  file: my-credential-spec.json
```

使用时`registry:`，将从守护进程主机上的Windows注册表中读取凭据规范。具有给定名称的注册表值必须位于：

```
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Virtualization\Containers\CredentialSpecs
```

以下示例从`my-credential-spec` 注册表中指定的值加载凭证规范：

```yaml
credential_spec:
  registry: my-credential-spec
```



## `deploy` 部署


> **仅限版本3。**

指定与服务的部署和运行相关的配置。这只在部署到使用`docker stack`部署的`swarm`时才会生效，并且被`docker-compose up`和`docker-compose run`忽略。

```yaml
version: '3'
services:
  redis:
    image: redis:alpine
    deploy:
      replicas: 6
      update_config:
        parallelism: 2
        delay: 10s
      restart_policy:
        condition: on-failure
```

### `endpoint_mode` 端点模式
---
为连接到群的外部客户端指定服务发现方法。

> **仅版本3.3。**

- `endpoint_mode: vip` - Docker为该服务分配一个虚拟IP（VIP），作为客户端到达网络服务的“前端”。Docker在客户端和可用的工作节点之间为服务路由请求，而客户端不知道有多少节点参与服务或其IP地址或端口。（这是默认设置。）
- `endpoint_mode: dnsrr` - DNS轮询（DNSRR）服务发现不使用单个虚拟IP。Docker为服务设置DNS条目，使得服务名称的DNS查询返回一个IP地址列表，并且客户端直接连接到其中的一个。如果你想使用自己的负载平衡器，或者混合Windows和Linux应用程序，则DNS轮询功能非常有用。

```yaml
version: "3.3"

services:
  wordpress:
    image: wordpress
    ports:
      - 8080:80
    networks:
      - overlay
    deploy:
      mode: replicated
      replicas: 2
      endpoint_mode: vip

  mysql:
    image: mysql
    volumes:
       - db-data:/var/lib/mysql/data
    networks:
       - overlay
    deploy:
      mode: replicated
      replicas: 2
      endpoint_mode: dnsrr

volumes:
  db-data:

networks:
  overlay:
```

这些选项`endpoint_mode`也可用作集群模式CLI命令[docker service create中的](https://docs.docker.com/engine/reference/commandline/service_create/)选项 。有关所有swarm相关`docker`命令的快速列表，请参阅[Swarm模式CLI命令](https://docs.docker.com/engine/swarm/#swarm-mode-key-concepts-and-tutorial)。

要了解有关集群模式下的服务发现和网络的更多信息，请参阅 在集群模式主题中[配置服务发现](https://docs.docker.com/engine/swarm/networking/#configure-service-discovery)。

### `labels` 标签
---
指定服务的标签。这些标签*仅*在服务上设置，*而不*在服务的任何容器上设置。

```yaml
version: "3"
services:
  web:
    image: web
    deploy:
      labels:
        com.example.description: "This label will appear on the web service"
```

要改为在容器上设置标签，请在以下位置使用`labels`，而并非在`deploy` 键下面：

```yaml
version: "3"
services:
  web:
    image: web
    labels:
      com.example.description: "This label will appear on all containers for the web service"
```

### `mode` 模式
---
全局唯一模式：`global`，还是副本多实例模式：`replicated`，若是副本模式就需要指定副本数量`replicas`。要么`global`（每个集群节点只有一个容器）或`replicated`（指定数量的容器）。默认是`replicated`。（要了解更多信息，请参阅[swarm](https://docs.docker.com/engine/swarm/)主题 中的[复制和全局服务](https://docs.docker.com/engine/swarm/how-swarm-mode-works/services/#replicated-and-global-services)。）

```yaml
version: '3'
services:
  worker:
    image: dockersamples/examplevotingapp_worker
    deploy:
      mode: global
```

### `placement` 分布位置
---
指定约束和偏好的位置。请参阅docker服务创建文档以获取语法和可用类型的[约束](https://docs.docker.com/engine/reference/commandline/service_create/#specify-service-constraints-constraint)和[首选项](https://docs.docker.com/engine/reference/commandline/service_create/#specify-service-placement-preferences-placement-pref)的完整说明。

```yaml
version: '3'
services:
  db:
    image: postgres
    deploy:
      placement:
        constraints:
          - node.role == manager
          - engine.labels.operatingsystem == ubuntu 14.04
        preferences:
          - spread: node.labels.zone
```

### `replicas` 副本
---
如果服务是`replicated`（这是默认设置），请指定在任何给定时间应该运行的容器数量。

```yaml
version: '3'
services:
  worker:
    image: dockersamples/examplevotingapp_worker   
    deploy:
      mode: replicated
      replicas: 6
```

### `resources` 资源
---
配置限制资源。

> **注意**：这取代了[旧的资源约束选项](https://docs.docker.com/compose/compose-file/compose-file-v2/#cpu-and-other-resources)在compose非集群模式文件之前版本3（ `cpu_shares`，`cpu_quota`，`cpuset`，`mem_limit`，`memswap_limit`，`mem_swappiness`）如在[升级版本2.x到3.x](https://docs.docker.com/compose/compose-file/compose-versioning/#upgrading)。

这些都是单一的值，类似于[docker服务创建的](https://docs.docker.com/engine/reference/commandline/service_create/)对应服务。

在这个通用示例中，`redis`服务限制使用不超过`50M`的内存和`0.50`（50％）可用处理时间（CPU），并且 保留`20M`了内存和`0.25`CPU时间（如同始终可用的那样）。

```yaml
version: '3'
services:
  redis:
    image: redis:alpine
    deploy:
      resources:
        limits:
          cpus: '0.50'
          memory: 50M
        reservations: # 保留资源，避免程序内存溢出
          cpus: '0.25'
          memory: 20M
```

下面的主题描述了设置集群中服务或容器资源约束的可用选项。

> 寻找在非群模式容器上设置资源的选项？
>
> 这里描述的选项特定于 `deploy`密钥和集群模式。如果要为非集群部署设置资源约束，请使用 [Compose文件格式版本2 CPU，内存和其他资源选项](https://docs.docker.com/compose/compose-file/compose-file-v2/#cpu-and-other-resources)。如果你还有其他问题，请参阅关于GitHub问题[docker /compose/4513](https://github.com/docker/compose/issues/4513)的讨论。



#### `Out Of Memory Exceptions` 内存异常（OOME）

如果服务或容器尝试使用比系统可用的内存更多的内存，则可能会遇到内存异常（`OOME`），并且容器或Docker守护程序可能会被内核OOM错误所杀。要防止发生这种情况，请确保应用程序在具有足够内存的主机上运行，并且请参阅[了解耗尽内存的风险](https://docs.docker.com/engine/admin/resource_constraints/#understand-the-risks-of-running-out-of-memory)。

### `restart_policy` 重启策略
---
配置是否以及如何在退出时重新启动容器。取代 [`restart`](https://docs.docker.com/compose/compose-file/compose-file-v2/#orig-resources)。

- `condition`：其中之一`none`，`on-failure`或`any`，默认：`any`。
- `delay`：在重启尝试之间等待多长时间，指定为 [持续时间](https://docs.docker.com/compose/compose-file/#specifying-durations)（默认值：0）。
- `max_attempts`：在放弃之前尝试重新启动容器多少次（默认：从不放弃）。如果重新启动在配置中没有成功`window`，则此尝试不计入配置`max_attempts`值。例如，如果`max_attempts`设置为“2”，并且第一次尝试重新启动失败，则可能会尝试重新启动两次以上。
- `window`：在决定重新启动是否成功之前等待多久，指定为[持续时间](https://docs.docker.com/compose/compose-file/#specifying-durations)（默认值：立即决定）。

```yaml
version: "3"
services:
  redis:
    image: redis:alpine
    deploy:
      restart_policy:
        condition: on-failure
        delay: 5s
        max_attempts: 3
        window: 120s
```

### `update_config` 更新配置
---
配置如何更新服务，用于配置滚动更新。

- `parallelism`：一次更新的容器数量。
- `delay`：在更新一组容器之间等待的时间。。
- `failure_action`：如果更新失败该怎么办。其中`continue`，`rollback`或`pause` ，默认：`pause`。
- `monitor`：每次任务更新后，监控是否失败的时间`(ns|us|ms|s|m|h)`（默认为0）。
- `max_failure_ratio`：在更新期间容忍的失败率。
- `order`：更新期间的操作顺序。其中一个`stop-first`（旧的任务在开始新任务之前停止），或`start-first`（新的任务首先启动，并且正在运行的任务短暂重叠）（默认`stop-first`）**注意**：仅在v3.4和更高版本中受支持。

> **注意**：`order`仅支持v3.4及更高版本的撰写文件格式。

```yaml
version: '3.4'
services:
  vote:
    image: dockersamples/examplevotingapp_vote:before
    depends_on:
      - redis
    deploy:
      replicas: 2
      update_config:
        parallelism: 2
        delay: 10s
        order: stop-first
```

## 不支持 `DOCKER STACK DEPLOY`

下面的子选项（支持`docker compose up`和`docker compose run`）是**不支持**的`docker stack deploy`或`deploy`关键字的。

- [build](https://docs.docker.com/compose/compose-file/#build)
- [cgroup_parent](https://docs.docker.com/compose/compose-file/#cgroup_parent)
- [container_name](https://docs.docker.com/compose/compose-file/#container_name)
- [devices](https://docs.docker.com/compose/compose-file/#devices)
- [tmpfs](https://docs.docker.com/compose/compose-file/#tmpfs)
- [external_links](https://docs.docker.com/compose/compose-file/#external_links)
- [links](https://docs.docker.com/compose/compose-file/#links)
- [network_mode](https://docs.docker.com/compose/compose-file/#network_mode)
- [restart](https://docs.docker.com/compose/compose-file/#restart)
- [security_opt](https://docs.docker.com/compose/compose-file/#security_opt)
- [stop_signal](https://docs.docker.com/compose/compose-file/#stop_signal)
- [sysctls](https://docs.docker.com/compose/compose-file/#sysctls)
- [userns_mode](https://docs.docker.com/compose/compose-file/#userns_mode)

> **提示**：请参阅关于[如何为服务，集群和docker-stack.yml文件配置卷](https://docs.docker.com/compose/compose-file/#volumes-for-services-swarms-and-stack-files)的部分。支持卷*，*但要与集群和服务一起使用，它们必须配置为命名卷或与限制为可访问必需卷的节点的服务相关联

## `devices` 设备

设备映射列表。使用方式和Docker客户端创建选项`--device`相同的格式。

```yaml
devices:
  - "/dev/ttyUSB0:/dev/ttyUSB0"
```

> **注意**：当使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时，[将](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。

## `depends_on` 依赖

服务之间的快速依赖关系，服务依赖关系导致以下行为：

- `docker-compose up`以**依赖的顺序**启动服务。在下面的例子中，`db`和`redis`在之前启动`web`。
- `docker-compose up SERVICE`自动包含`SERVICE`依赖关系。在下面的例子中，`docker-compose up web`创建并启动`db`和`redis`。

简单的例子：

```yaml
version: '3'
services:
  web:
    build: .
    depends_on:
      - db
      - redis
  redis:
    image: redis
  db:
    image: postgres
```

> 使用`depends_on`注意事项：
>
> - 在启动`web`之前，`depends_on`不会等待`db`和`redis`“准备就绪” - 只有在它们启动之前。如果需要等待服务准备就绪，请参阅[控制启动顺序](https://docs.docker.com/compose/startup-order/)以了解有关此问题的更多信息以及解决此问题的策略。
> - 第3版不再支持`condition`的形式`depends_on`。
> - 使用版本3编排文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)`depends_on`时，该选项将被忽略 。

## `dns`

自定义DNS服务器。可以是单个值或列表。

```yaml
dns: 8.8.8.8
dns:
  - 8.8.8.8
  - 9.9.9.9
```

## `dns_search`

自定义DNS搜索域。可以是单个值或列表。

```yaml
dns_search: example.com
dns_search:
  - dc1.example.com
  - dc2.example.com
```

## `tmpfs` 临时文件系统

在容器中装入一个**临时文件系统**。可以是单个值或列表。

```yaml
tmpfs: /run
tmpfs:
  - /run
  - /tmp
```

> **注意**：[在](https://docs.docker.com/engine/reference/commandline/stack_deploy/) 使用（版本3-3.5）compose文件的[集群模式下部署堆栈时，](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。

在**容器中**装入一个临时文件系统。`size`参数以字节为单位指定`tmpfs`挂载的大小，无限制默认。

```yaml
 - type: tmpfs
     target: /app
     tmpfs:
       size: 1000
```

## `entrypoint` 入口点

覆盖默认入口点。

```yaml
entrypoint: /code/entrypoint.sh
```

入口点也可以是一个列表，方式类似于 [dockerfile](https://docs.docker.com/engine/reference/builder/#entrypoint)：

```yaml
entrypoint:
    - php
    - -d
    - zend_extension=/usr/local/lib/php/extensions/no-debug-non-zts-20100525/xdebug.so
    - -d
    - memory_limit=-1
    - vendor/bin/phpunit
```

> **注意**：`entrypoint`使用 Dockerfile 的`ENTRYPOINT`指令设置**覆盖服务映像上**设置的任何默认入口点，并**清除映像**上的任何默认命令。这意味着如果Dockerfile中有 `CMD` 指令，则会**忽略**它。

## `env_file` 环境变量文件

从文件添加环境变量，可以是单个值或列表。<br/>如果已经指定了Compose文件`docker-compose -f FILE`，则路径 `env_file`相对于compose文件所在的目录。

`environment`部分中 声明的环境变量**会覆盖**`env_file` 的值， 即使这些值为空或未定义，也是如此。

```yaml
env_file: .env

env_file:
  - ./common.env
  - ./apps/web.env
  - /opt/secrets.env
```

compose 配置期望`env`文件中的每行都是`VAR=VAL`格式。以开头的行`#`被视为注释并被忽略，空行也被忽略。

```properties
# Set Rails/Rack environment
RACK_ENV=development
```

> **注意**：如果服务指定了[构建](https://docs.docker.com/compose/compose-file/#build)选项，则在构建期间，环境文件中定义的变量*不会*自动显示。使用[args](https://docs.docker.com/compose/compose-file/#args)子选项`build`来定义构建时环境变量。

**该值按`VAL`原样使用，根本不作任何修改**。例如，如果值被引号包围（如通常是shell变量的情况），则引用将包含在传递给Compose的值中。

请记住，**列表中文件的顺序在确定分配给多次显示的变量的值时非常重要**。对于文件`a.env`中指定的相同变量并在文件`b.env`中分配了不同的值，如果`b.env`列在下面（之后），则表示`b.env`中的值。例如，在`docker_compose.yml`中给出以下声明：

```yaml
services:
  some-service:
    env_file:
      - a.env
      - b.env
```

以下文件：

```yaml
# a.env
VAR=1
```

和

```yaml
# b.env
VAR=hello
```

`$VAR`是`hello`。

## `environment` 环境变量

添加环境变量，可以使用**数组或字典**。任何boolean值：`True、False、Yes`，需要用**引号括起来以确保它们不被YML解析器转换为True或False**。

只有一个环境变量会在计算机上运行时解析为它们的值，这对于主机特定的值可能会有所帮助。

```yaml
environment:
  RACK_ENV: development
  SHOW: 'true'
  SESSION_SECRET:

environment:
  - RACK_ENV=development
  - SHOW=true
  - SESSION_SECRET
```

> **注意**：如果服务指定了[build](https://docs.docker.com/compose/compose-file/#build)选项，`environment`则在构建过程中定义的变量**不会**自动显示。使用[args](https://docs.docker.com/compose/compose-file/#args)子选项`build`来定义构建时环境变量。

## `expose` 暴露

**公开端口**而不将它们发布到主机，它们只能**被链接服务访问**，**只能指定内部端口**。

```yaml
expose:
 - "3000"
 - "8000"
```

## `external_links` 外部链接

链接到`docker-compose.yml`之外甚至Compose之外的容器，尤其是提供**共享或公共服务**的容器。在指定容器名称和链接别名（`CONTAINER：ALIAS`）时，`external_links`遵循类似于旧版选项链接的语义。

```yaml
external_links:
 - redis_1
 - project_db_1:mysql
 - project_db_1:postgresql
```

> **笔记：** <br/>如果使用的是[第2版或更高版本的文件格式](https://docs.docker.com/compose/compose-file/compose-versioning/#version-2)，则外部创建的容器必须**连接到与链接到它们的服务相同的网络**。[links](https://docs.docker.com/compose/compose-file/compose-file-v2#links)是遗留选项。我们建议使用[networks](https://docs.docker.com/compose/compose-file/#networks)。
>
> 使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时忽略此选项。

## `extra_hosts` 主机映射

添加主机名映射。使用方法与docker客户端`--add-host`参数相同。

```yaml
extra_hosts:
 - "somehost:162.242.195.82"
 - "otherhost:50.31.209.229"
```

具有IP地址和主机名的条目在`/etc/hosts`该服务的内部容器中创建，例如：

```properties
162.242.195.82  somehost
50.31.209.229   otherhost
```

## `healthcheck` 健康检查

配置运行的检查以确定此服务的容器是否**健康**。查看[HEALTHCHECK Dockerfile指令](https://docs.docker.com/engine/reference/builder/#healthcheck)的文档以获取有关 [健康检查](https://docs.docker.com/engine/reference/builder/#healthcheck) 如何工作的详细信息。

```yaml
healthcheck:
  test: ["CMD", "curl", "-f", "http://localhost"]
  interval: 1m30s
  timeout: 10s
  retries: 3
  start_period: 40s
```

`interval`、`timeout`、`start_period`指定为[持续时间](https://docs.docker.com/compose/compose-file/#specifying-durations)。

> **注意**：`start_period`仅支持v3.4及更高版本的编排文件格式。

`test` 选项必须是字符串或列表。如果它是一个列表，第一项必须是`NONE`，`CMD`或`CMD-SHELL`。如果它是一个字符串，则相当于指定`CMD-SHELL`后跟该字符串。

```yaml
# Hit the local web app
test: ["CMD", "curl", "-f", "http://localhost"]

# As above, but wrapped in /bin/sh. Both forms below are equivalent.
test: ["CMD-SHELL", "curl -f http://localhost || exit 1"]
test: curl -f https://localhost || exit 1
```

要**禁用图像设置的任何默认健康检查**，可以使用`disable: true`。这相当于指定`test: ["NONE"]`。

```yaml
healthcheck:
  disable: true
```

## `image` 镜像

指定从图像中启动容器。可以是存储库/标签或部分图像ID。

```yaml
image: redis
image: ubuntu:14.04
image: tutum/influxdb
image: example-registry.com:4000/postgresql
image: a4bc65fd
```

如果图像不存在，Compose会尝试拉取操作，除非你还指定了[build](https://docs.docker.com/compose/compose-file/#build)，在这种情况下，它会使用指定的选项构建它，并使用指定的标记对其进行标记。

## `isolation` 隔离

指定容器的隔离技术。在Linux上，唯一支持的值是`default`。在Windows上，可接受的值是`default`，`process`并且`hyperv`。 有关详细信息，请参阅 [Docker Engine文档](https://docs.docker.com/engine/reference/commandline/run/#specify-isolation-technology-for-container---isolation)。

## `labels` 标签

使用[Docker标签](https://docs.docker.com/engine/userguide/labels-custom-metadata/)将元数据添加到容器。可以使用**数组或字典**。建议**使用反向DNS标记**来**防止**标签与其他软件使用的标签**冲突**。

```yaml
labels:
  com.example.description: "Accounting webapp"
  com.example.department: "Finance"
  com.example.label-with-empty-value: ""

labels:
  - "com.example.description=Accounting webapp"
  - "com.example.department=Finance"
  - "com.example.label-with-empty-value"
```

## `links` 链接

> **警告**：`--link`选项是Docker的**遗留功能**。它最终可能会被删除。除非绝对需要继续使用它，否则我们建议使用[用户定义的网络](https://docs.docker.com/engine/userguide/networking//#user-defined-networks) 来促进两个容器之间的通信而不是使用`--link`。用户定义的网络不支持的一个功能`--link`是在**容器之间共享环境变量**。但是，可以使用其他机制（如卷）以更受控制的方式在容器之间共享环境变量。

**链接到另一个服务中的容器**。既可以指定**服务名称**又可以指定**链接别名**（`SERVICE:ALIAS`），或者只指定**服务名称**。

```yaml
web:
  links:
   - db
   - db:database
   - redis
```

**链接服务的容器可以在与别名相同的主机名上访问，如果没有指定别名，则可以访问服务名称**。<br/>链接不需要启用服务进行通信，默认情况下，任何服务都可以**以服务的名称**到达任何其他服务。（另请参阅[link主题](https://docs.docker.com/compose/networking/#links)）<br/>链接与[depends_on](https://docs.docker.com/compose/compose-file/#depends_on)相同的方式表示服务之间的依赖关系 ，因此它们确定服务启动的顺序。

> **笔记**
>
> - 如果你定义了`link`和[网络](https://docs.docker.com/compose/compose-file/#networks)，那么它们之间的`link`必须**共享至少一个共同**的网络进行通信。
> - 使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时忽略此选项 。

## `logging` 日志

日志记录服务的配置。

```yaml
logging:
  driver: syslog
  options:
    syslog-address: "tcp://192.168.0.42:123"
```

该`driver` 名称指定服务容器的**日志记录驱动程序**，与`docker run `的`--log-driver`选项（[此处记录](https://docs.docker.com/engine/admin/logging/overview/)）一样。默认值是`json-file`。

```yaml
driver: "json-file"
driver: "syslog"
driver: "none"
```

> **注意**：只有驱动程序`json-file`和`journald`驱动程序可以直接从`docker-compose up`和`docker-compose logs`提供日志。使用任何其他驱动程序不会打印任何日志。

使用`options`指定日志记录驱动程序的日志记录选项，就像`docker run`的`--log-opt`选项一样。 日志记录选项是键值对。`syslog`选项的一个例子：

```yaml
driver: "syslog"
options:
  syslog-address: "tcp://192.168.0.42:123"
```

默认驱动程序[json-file](https://docs.docker.com/engine/admin/logging/overview/#json-file)具有**限制存储日志量**的选项。为此，请使用键值对来获得**最大存储大小和最大文件数量**：

```yaml
options:
  max-size: "200k"
  max-file: "10"
```

上面显示的示例将存储日志文件，直到它们达到`max-size` `200kB`，然后旋转它们。存储的单个日志文件的数量由`max-file`值指定。随着日志增长超出最大限制，**旧日志文件将被删除**以允许存储新日志。以下是`docker-compose.yml`限制日志存储的示例文件：

```yaml
services:
  some-service:
    image: some-service
    logging:
      driver: "json-file"
      options:
        max-size: "200k"
        max-file: "10"
```

> 可用的记录选项取决于你使用的记录驱动程序<br/>以上用于控制日志文件和大小的示例使用特定于[json-file驱动程序的](https://docs.docker.com/engine/admin/logging/overview/#json-file)选项。这些特定选项在其他日志记录驱动程序上不可用。有关支持的日志记录驱动及其选项的完整列表，请参阅 [日志驱动](https://docs.docker.com/engine/admin/logging/overview/)。

## `network_mode` 网络模式

网络模式，使用与docker客户端`--net`参数相同的值以及特殊形式`service:[service name]`。

```yaml
network_mode: "bridge"
network_mode: "host"
network_mode: "none"
network_mode: "service:[service name]"
network_mode: "container:[container name/id]"
```

> **笔记**
>
> - 使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时忽略此选项 。
> - `network_mode: "host"`不能与`link`混合使用。 

## `networks` 网络

加入网络，引用[顶级`networks`](https://docs.docker.com/compose/compose-file/#network-configuration-reference)下的条目 。

```yaml
services:
  some-service:
    networks:
     - some-network
     - other-network
```

### `aliases` 别名

---

网络上服务的别名（备用主机名）。同一网络上的其他容器可以使用**服务名称或别名**来连接到服务的容器。由于`aliases`是网络范围的，相同的服务可以在不同的网络上具有不同的别名。

> **注意**：网络范围的**别名可以由多个容器共享**，甚至可以由**多个服务共享**。如果是，那么名称解析的确切容器的名称就不能保证。

一般格式如下所示。

```yaml
services:
  some-service:
    networks:
      some-network:
        aliases:
         - alias1
         - alias3
      other-network:
        aliases:
         - alias2
```

在下面的例子中，提供了三种服务（`web`，`worker`，`db`），两个网络（`new`和`legacy`）。`db`服务可以访问在`new`网络上的主机名`db`或`database`以及旧数据库上的`db`或`mysql`。 

```yaml
version: '2'

services:
  web:
    build: ./web
    networks:
      - new

  worker:
    build: ./worker
    networks:
      - legacy

  db:
    image: mysql
    networks:
      new:
        aliases:
          - database
      legacy:
        aliases:
          - mysql

networks:
  new:
  legacy:
```

### `IPV4_ADDRESS，IPV6_ADDRESS` 静态地址

---

加入网络时，为此服务的容器指定一个**静态IP**地址。

[顶级网络部分中](https://docs.docker.com/compose/compose-file/#network-configuration-reference)的相应网络配置 必须具有`ipam`覆盖每个静态地址的具有子网配置的模块。如果需要IPv6寻址，则[`enable_ipv6`](https://docs.docker.com/compose/compose-file/#enableipv6)必须设置该选项，并且必须使用版本2.x Compose文件，例如下面的文件。

> **注意**：这些选项目前不在集群模式下工作。

一个例子：

```yaml
version: '2.1'

services:
  app:
    image: busybox
    command: ifconfig
    networks:
      app_net:
        ipv4_address: 172.16.238.10
        ipv6_address: 2001:3984:3989::10

networks:
  app_net:
    driver: bridge
    enable_ipv6: true
    ipam:
      driver: default
      config:
      -
        subnet: 172.16.238.0/24
      -
        subnet: 2001:3984:3989::/64
```

## `pid`

```
pid: "host"
```

将PID模式设置为主机PID模式。这将打开**容器与主机操作系统**之间的**共享PID地址空间**。使用此选项启动的容器**可以访问和操作裸机的名称空间中的其他容器**，反之亦然。

## `port` 端口

公开端口。

> **注意：**端口映射不兼容`network_mode: host`

### 短语法

---

既可以指定端口（`HOST:CONTAINER`），也可以指定容器端口（选择临时主机端口）。

> **注意**：以`HOST:CONTAINER`格式映射端口时，使用小于60的容器端口时可能会遇到错误结果，因为YAML将格式`xx:yy`中的数字解析为base-60值。出于这个原因，我们建议始终**明确指定端口映射为字符串**。

```yaml
ports:
 - "3000"
 - "3000-3005"
 - "8000:8000"
 - "9090-9091:8080-8081"
 - "49100:22"
 - "127.0.0.1:8001:8001"
 - "127.0.0.1:5000-5010:5000-5010"
 - "6060:6060/udp"
```

### 长语法

---

长格式语法允许配置不能以简短形式表示的附加字段。

- `target`：容器内的端口
- `published`：公开曝光的端口
- `protocol`：端口协议（`tcp`或`udp`）
- `mode`：`host`用于在每个节点上发布**主机端口**，或`ingress`用于**集群模式端口**进行负载平衡。

```yaml
ports:
  - target: 80
    published: 8080
    protocol: tcp
    mode: host
```

> **注意：**长语法在v3.2中是新的

## `secrets`  秘密

使用每个服务`secrets` 配置为每个服务授予对`secrets` 的访问权限。支持两种不同的语法变体。

> **注意**：秘密必须已经存在或在此堆栈文件的顶级秘密配置中定义，否则堆栈部署失败。

### 短语法

---

短语法变体只指定秘密名称。这允许容器访问该秘密并将其安装在`/run/secrets/<secret_name>` 容器内。**源名称和目标装入点均设置为秘密名称**。

以下示例使用简短语法来授予对`redis`服务`my_secret`和`my_other_secret`秘密的访问权限。 `my_secret`被设置为`./my_secret.txt`文件的内容，并被 `my_other_secret`定义为外部资源，这意味着它已经在Docker中定义，可以通过运行`docker secret create` 命令或通过另一个堆栈部署。如果外部机密不存在，则编排部署失败并出现`secret not found`错误。

```yaml
version: "3.1"
services:
  redis:
    image: redis:latest
    deploy:
      replicas: 1
    secrets:
      - my_secret
      - my_other_secret
secrets:
  my_secret:
    file: ./my_secret.txt
  my_other_secret:
    external: true
```

### 长语法

---

较长的语法提供了有关如何在服务的任务容器内创建秘密的更细粒度。

- `source`：它在Docker中存在的**秘密名称**。
- `target`：要加载到服务的任务容器中的`/run/secrets/`中的**文件的名称**。如果未指定，则默认为`source`。
- `uid`以及`gid`：`/run/secrets/`在服务的任务容器中拥有该文件的数字UID或GID 。如果未指定，两者都默认为`0`。
- `mode`：`/run/secrets/` 以八进制表示法将文件装载到服务的任务容器中的**权限**。例如，`0444` 代表世界可读的。Docker 1.13.1中的默认值是`0000`，但是`0444`在更新的版本中。由于秘密文件被安装在临时文件系统中，因此秘密文件无法写入，因此如果设置了可写位，它将被忽略。可执行位可以被设置。如果不熟悉UNIX文件权限模式，则可能会发现此 [权限计算器](http://permissions-calculator.org/) 很有用。

以下示例在容器中设置`my_secret`的名称`redis_secret`，将模式设置为`0440`（`group-readable`）并将用户和组设置为`103`。`redis`服务无法访问`my_other_secret` 秘密。

```yaml
version: "3.1"
services:
  redis:
    image: redis:latest
    deploy:
      replicas: 1
    secrets:
      - source: my_secret
        target: redis_secret
        uid: '103'
        gid: '103'
        mode: 0440
secrets:
  my_secret:
    file: ./my_secret.txt
  my_other_secret:
    external: true
```

可以授予服务对多个秘密的访问权限，可以混合使用长短语法。定义秘密并不意味着授予服务访问权限。

## `security_opt` 安全

覆盖每个容器的默认标签方案。

```yaml
security_opt:
  - label:user:USER
  - label:role:ROLE
```

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时，[将](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。

## `stop_grace_period` 退出等待时间 

指定在发送`SIGKILL`之前，如果试图停止一个容器（如果它没有处理`SIGTERM`）（或者使用`stop_signal`指定了任何停止信号），请等待多久：指定为持续时间。

```yaml
stop_grace_period: 1s
stop_grace_period: 1m30s
```

默认情况下，`stop`在发送`SIGKILL`之前等待容器退出10秒。

## `stop_signal` 停止信号

设置一个替代信号来停止容器。默认情况下`stop`使用`SIGTERM`。使用`stop_signal`原因 设置替代信号来`stop`代替发送该信号。

```yaml
stop_signal: SIGUSR1
```

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时，[将](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。

## `sysctls` 内核参数

在容器中设置的内核参数。可以使用数组或字典。

```yaml
sysctls:
  net.core.somaxconn: 1024
  net.ipv4.tcp_syncookies: 0

sysctls:
  - net.core.somaxconn=1024
  - net.ipv4.tcp_syncookies=0
```

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时，[将](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。

## `ulimits`

覆盖容器的默认限制。可以将单个限制指定为整数，也可以将`软限制`/`硬限制`指定为映射。

```yaml
ulimits:
  nproc: 65535
  nofile:
    soft: 20000
    hard: 40000
```

## `userns_mode` 用户命名空间

```
userns_mode: "host"
```

如果Docker守护程序配置了**用户命名空间**，则禁用此服务的用户命名空间。有关更多信息，请参阅[dockerd](https://docs.docker.com/engine/reference/commandline/dockerd/#disable-user-namespace-for-a-container)。

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署堆栈](https://docs.docker.com/engine/reference/commandline/stack_deploy/)时，[将](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。

## `volumes` 卷

挂载主机路径或命名卷，将其指定为服务的子选项。可以将主机路径作为**单个服务**定义的一部分进行挂载，并且无需在顶级`volumes`中定义它。但是，如果想**跨多个服务**重用卷，请在[顶级`volumes`中](https://docs.docker.com/compose/compose-file/#volume-configuration-reference)定义一个命名卷。将命名卷与[服务，集群和堆栈文件一起使用](https://docs.docker.com/compose/compose-file/#volumes-for-services-swarms-and-stack-files)。

> **注意**：顶级 [卷](https://docs.docker.com/compose/compose-file/#volume-configuration-reference) 定义了一个命名卷，并从每个服务的`volumes`列表中引用它。这取代`volumes_from`了早期版本的Compose文件格式。有关[卷](https://docs.docker.com/engine/admin/volumes/volumes/)的一般信息，请参阅[使用卷](https://docs.docker.com/engine/admin/volumes/volumes/)和[卷插件](https://docs.docker.com/engine/extend/plugins_volume/)。

此示例显示`web`服务正在使用的命名卷（`mydata`），以及为单个服务（`db`服务下的第一个`volumes`路径）定义的绑定挂载。该`db`服务还使用名为`dbdata`（`db`服务下的第二个`volumes`路径）的命名卷，但使用旧字符串格式定义它以装入命名卷。`volumes`如下所示，命名卷必须列在顶级配置下 。

```yaml
version: "3.2"
services:
  web:
    image: nginx:alpine
    volumes:
      - type: volume
        source: mydata
        target: /data
        volume:
          nocopy: true
      - type: bind
        source: ./static
        target: /opt/app/static

  db:
    image: postgres:latest
    volumes:
      - "/var/run/postgres/postgres.sock:/var/run/postgres/postgres.sock"
      - "dbdata:/var/lib/postgresql/data"

volumes:
  mydata:
  dbdata:
```

> **注意**：请参阅[使用卷](https://docs.docker.com/engine/admin/volumes/volumes/)和[卷插件](https://docs.docker.com/engine/extend/plugins_volume/)以获取卷的一般信息。

### 短语法

---

可以选择在主机（`HOST:CONTAINER`）或访问模式（`HOST:CONTAINER:ro`）上指定路径。可以在主机上挂载相对路径，该路径相对于正在使用的Compose配置文件的目录进行扩展。相对路径应始终以`.`或开头`..`。

```yaml
volumes:
  # Just specify a path and let the Engine create a volume
  - /var/lib/mysql

  # Specify an absolute path mapping
  - /opt/data:/var/lib/mysql

  # Path on the host, relative to the Compose file
  - ./cache:/tmp/cache

  # User-relative path
  - ~/configs:/etc/configs/:ro

  # Named volume
  - datavolume:/var/lib/mysql
```

### 长语法

---

长格式语法允许配置不能以简短形式表示的附加字段。

- `type`：挂载**类型**`volume`，`bind`或`tmpfs`

- `source`：**安装源**，主机上用于绑定安装的路径或[顶级`volumes`中](https://docs.docker.com/compose/compose-file/#volume-configuration-reference)定义的卷的名称 。不适用于`tmpfs`类型。

- `target`：卷挂载在**容器中的路径**

- `read_only`：选项将卷设置为**只读**

- `bind`：配置**额外**的绑定选项

  - `propagation`：用于绑定的**传播模式**

- `volume`：配置额外的卷选项

  - `nocopy`：创建卷时**禁止从容器复制**数据的选项

- `tmpfs`：配置额外的`tmpfs`选项

  - `size`：`tmpfs`的**大小**，以字节为单位

```yaml
version: "3.2"
services:
  web:
    image: nginx:alpine
    ports:
      - "80:80"
    volumes:
      - type: volume
        source: mydata
        target: /data
        volume:
          nocopy: true
      - type: bind
        source: ./static
        target: /opt/app/static

networks:
  webnet:

volumes:
  mydata:
```

> **注意**：长语法在v3.2中是新的

### 服务、集群和编排文件的卷

---

在使用服务、集群和`docker-stack.yml`文件时，请记住支持服务的任务（容器）可以部署在集群中的任何节点上，并且每次更新服务时都可能是不同的节点。

在**缺少指定源的命名卷**的情况下，Docker为支持服务的每个任务**创建**一个**匿名卷**。关联的容器被移除后，**匿名卷不会保留**。

如果希望数据**持久**保存，请使用可识别多主机的**命名卷和卷驱动**程序，以便**可以从任何节点访问**数据。或者，对该服务**设置约束**，以便将其任务部署在具有该卷的节点上。

作为示例，[Docker Labs中votingapp示例](https://github.com/docker/labs/blob/master/beginner/chapters/votingapp.md)的`docker-stack.yml`文件定义了一个名为`db`的服务，该服务运行`postgres`数据库。它被配置为一个命名卷来保存群体上的数据，并且被限制为**仅在管理`manager`节点**上运行。这是来自该文件的相关剪辑：

```yaml
version: "3"
services:
  db:
    image: postgres:9.4
    volumes:
      - db-data:/var/lib/postgresql/data
    networks:
      - backend
    deploy:
      placement:
        constraints: [node.role == manager]
```

## `restart` 重启策略

`no`是默认的重新启动策略，并且在任何情况下都不会重新启动容器。当`always`指定时，容器**总是重新启动**。`on-failure`如果退出代码指示的**故障错误**重启的容器。

```yaml
restart: "no"
restart: always
restart: on-failure
restart: unless-stopped
```

> **注意**：当 使用（版本3）Compose文件[在集群模式下部署堆栈时，](https://docs.docker.com/engine/reference/commandline/stack_deploy/)忽略此选项 。改用[restart_policy](https://docs.docker.com/compose/compose-file/#restart_policy)。

## `domainname, hostname, ipc, mac_address, privileged, read_only, shm_size, stdin_open, tty, user, working_dir`

其中每一个都是一个单一的价值，类似于它的 [docker 运行](https://docs.docker.com/engine/reference/run/)。

```yaml
user: postgresql
working_dir: /code

domainname: foo.com
hostname: foo
ipc: host
mac_address: 02:42:ac:11:65:43

privileged: true


read_only: true
shm_size: 64M
stdin_open: true
tty: true
```

## 指定持续时间

一些配置选项，如`interval`和`timeout`子选项 [`check`](https://docs.docker.com/compose/compose-file/#healthcheck)，接受一个持续时间为看起来像这样的格式的字符串：

```properties
2.5s
10s
1m30s
2h32m
5h34m56s
```

支持的单位是`us`，`ms`，`s`，`m`和`h`。

## 指定字节值

一些配置选项（如`shm_size`子选项）以 [`build`](https://docs.docker.com/compose/compose-file/#build)一种格式接受字节值作为字符串，格式如下所示：

```properties
2b
1024kb
2048k
300m
1gb
```

支持的单位是`b`，`k`，`m`和`g`，和它们的替代符号`kb`， `mb`和`gb`。目前不支持十进制值。

# 示例参考

## `volumes` 配置参考

尽管可以在文件上声明[卷](https://docs.docker.com/compose/compose-file/#volumes)作为服务声明的一部分，但本节允许创建`volumes_from`可以在多个服务中**重复使用**的命名卷（不依赖于该卷），并且可以使用docker命令行轻松检索和检查API。

以下是一个双服务设置的示例，其中数据库的数据目录与另一个服务共享为一个卷，以便可以定期进行备份：

```yaml
version: "3"

services:
  db:
    image: db
    volumes:
      - data-volume:/var/lib/db
  backup:
    image: backup-service
    volumes:
      - data-volume:/var/lib/backup/data

volumes:
  data-volume:
```

顶级`volumes`下的条目可以为空，在这种情况下，它使用引擎配置的**默认驱动程序**（在大多数情况下，这是 `local`驱动程序）。或者，你可以使用以下属性配置它：

### `driver`

---

指定应该为此卷使用哪个卷驱动程序。默认为Docker Engine配置使用的驱动程序`local`，在大多数情况下是这样 。如果驱动程序不可用，则`docker-compose up`尝试创建卷时，引擎会返回错误 。

```yaml
 driver: foobar
```

### `driver_opts`

---

指定一个选项列表作为传递给该卷的驱动程序的键值对。这些选项是依赖于驱动程序的 - 请查阅驱动程序的文档以获取更多信息。可选的。

```
 driver_opts:
   foo: "bar"
   baz: 1
```

### `external`

---

如果设置为`true`，则指定该卷已在compose之外创建。`docker-compose up`不会尝试创建它，并且如果它不存在会产生错误。`external`不能与其他卷配置（`driver`，`driver_opts`）一起使用。

在下面的例子中，`[projectname]_data` 服务编排不是试图创建一个被调用的卷，而是查找一个简单调用的现有卷，`data`并将其挂载到`db`服务的容器中。

```yaml
version: '2'

services:
  db:
    image: postgres
    volumes:
      - data:/var/lib/postgresql/data

volumes:
  data:
    external: true
```

> [external.name在3.4版文件格式是不推荐](https://docs.docker.com/compose/compose-file/compose-versioning/#version-34) 使用`name`来代替。

你还可以在Compose文件中单独指定用于引用它的名称来指定卷的名称：

```yaml
volumes:
  data:
    external:
      name: actual-name-of-volume
```

> **外部卷始终使用Docker堆栈部署来创建**<br/>如果使用[docker stack deploy](https://docs.docker.com/compose/compose-file/#deploy)以[swarm模式](https://docs.docker.com/engine/swarm/)启动应用程序 （而不是[docker组合](https://docs.docker.com/compose/reference/up/)），则**创建**不存在的外部卷。在集群模式下，当服务定义时会**自动创建**一个卷。由于服务任务在新节点上进行安排，因此 [swarmkit](https://github.com/docker/swarmkit/blob/master/README.md)会在本地节点上创建卷。要了解更多信息，请参阅 [moby / moby＃29976](https://github.com/moby/moby/issues/29976)。

### `labels`

---

使用[Docker标签](https://docs.docker.com/engine/userguide/labels-custom-metadata/)将元数据添加到容器 。你可以使用数组或字典。建议你使用反向DNS标记来防止你的标签与其他软件使用的标签冲突。

```yaml
labels:
  com.example.description: "Database volume"
  com.example.department: "IT/Ops"
  com.example.label-with-empty-value: ""

labels:
  - "com.example.description=Database volume"
  - "com.example.department=IT/Ops"
  - "com.example.label-with-empty-value"
```

### `name`

---

> [在3.4版文件格式中添加](https://docs.docker.com/compose/compose-file/compose-versioning/#version-34)

为此卷设置一个**自定义名称**。名称字段可用于引用包含**特殊字符的网络**。该名称按原样使用，**不会**与堆栈名称一起作用。

```yaml
version: '3.4'
volumes:
  data:
    name: my-app-data
```

它也可以与`external`结合使用：

```yaml
version: '3.4'
volumes:
  data:
    external: true
    name: my-app-data
```

## `networks` 配置参考

顶级`networks`配置下允许指定要创建的网络。

- 有关Compose使用Docker网络功能和所有网络驱动程序选项的完整说明，请参阅[网络指南](https://docs.docker.com/compose/networking/)。
- 对于[Docker Labs](https://github.com/docker/labs/blob/master/README.md) 关于网络的教程，从[设计可扩展的，便携式Docker容器网络开始](https://github.com/docker/labs/blob/master/networking/README.md)

### `driver`

---

指定网络应使用哪个驱动程序。默认驱动程序取决于使用的Docker引擎是如何配置的，但在大多数情况下，它位于单个主机`bridge`和集群多主机的`overlay`。

如果驱动程序不可用，Docker引擎会返回错误。

```yaml
driver: overlay
```

#### `bridge`

Docker默认在单个主机上使用`bridge`网络。有关如何使用桥接网络的示例，请参阅[Bridge联网](https://github.com/docker/labs/blob/master/networking/A2-bridge-networking.md)的Docker Labs教程。

#### `overlay`

`overlay`驱动程序在群中的多个节点上创建一个命名网络。

- 有关如何在集群模式下构建和使用具有服务的`overlay`网络的工作示例 ，请参阅Docker Labs关于[覆盖网络和服务发现的](https://github.com/docker/labs/blob/master/networking/A3-overlay-networking.md)教程 。
- 要深入了解它如何工作，请参阅[Overlay Driver Network Architecture](https://github.com/docker/labs/blob/master/networking/concepts/06-overlay-networks.md)上的网络概念实验。

#### `host` 或 `none`

使用`主机的网络堆栈`或`不使用网络`。等同于 `docker run --net=host`或`docker run --net=none`。仅在使用`docker stack`命令时使用 。如果使用`docker-compose`命令，请改为使用[network_mode](https://docs.docker.com/compose/compose-file/#network_mode)。

使用内置的网络，如语法`host`和`none`稍有不同。使用名称`host`或`none`（Docker已自动创建）定义外部网络，并使用Compose可以使用的**别名**（`hostnet`或`nonet`在这些示例中），然后**使用别名授予对该网络的服务访问权限**。

```yaml
services:
  web:
    ...
    networks:
      hostnet: {}

networks:
  hostnet:
    external: true
    name: host
```

```yaml
services:
  web:
    ...
    networks:
      nonet: {}

networks:
  nonet:
    external: true
    name: none
```

### `driver_opts`

---

指定一个选项列表作为键值对传递给**网络的驱动**程序。这些选项是依赖于驱动程序的。请查阅驱动程序的文档以获取更多信息。

```yaml
  driver_opts:
    foo: "bar"
    baz: 1
```

### `attachable`

---

> **注意**：仅支持v3.2及更高版本。

仅当`driver`设置为`overlay`时才能使用`attachable`。如果设置为`true`，则除服务外，独立容器可以连接到此网络。如果独立容器连接到覆盖网络，它可以与其他Docker守护程序也连接到覆盖网络的服务和独立容器进行通信。

```yaml
networks:
  mynet1:
    driver: overlay
    attachable: true
```

### `enable_ipv6`

---

在此网络上启用IPv6网络。

> **在Compose File版本3中不受支持**<br/>`enable_ipv6` 要求使用版本2 编排文件，因为此指令在集群模式下尚不受支持。

### `ipam`

---

指定自定义IPAM配置。这是一个包含多个属性的对象，每个属性都是可选的：

- `driver`：自定义IPAM驱动程序，而不是默认值。

- `config`：包含零个或多个配置块的列表，每个配置块都包含以下任何键

  - `subnet`：表示网段的CIDR格式的子网

一个完整的例子：

```yaml
ipam:
  driver: default
  config:
    - subnet: 172.28.0.0/16
```

> **注意**：其他IPAM配置，例如`gateway`，目前仅适用于版本2。

### `internal`

默认情况下，Docker还将**桥接网络连接到它以提供外部连接**。如果你想创建一个**外部隔离**的覆盖网络，你可以设置这个选项`true`。

### `labels`

使用[Docker标签](https://docs.docker.com/engine/userguide/labels-custom-metadata/)将元数据添加到容器 。你可以使用数组或字典。建议你使用**反向DNS标记**来防止标签与其他软件使用的标签冲突。

```
labels:
  com.example.description: "Financial transaction network"
  com.example.department: "Finance"
  com.example.label-with-empty-value: ""

labels:
  - "com.example.description=Financial transaction network"
  - "com.example.department=Finance"
  - "com.example.label-with-empty-value"
```

### `external`

如果设置为`true`，则指定此网络已在Compose之外创建。`docker-compose up`不会尝试创建它，并且如果它不存在会产生错误。`external`可以不与其它网络配置（结合使用`driver`，`driver_opts`，`ipam`，`internal`）。

在下面的例子中，`proxy`是通往外界的门户。`[projectname]_outside`Compose 并不试图创建一个叫做网络的组件，而是寻找一个简单称为`outside`的现有网络，并将`proxy`服务的容器连接到它。

```yaml
version: '2'

services:
  proxy:
    build: ./proxy
    networks:
      - outside
      - default
  app:
    build: ./app
    networks:
      - default

networks:
  outside:
    external: true
```

> [external.name在版本3.5文件格式是不推荐](https://docs.docker.com/compose/compose-file/compose-versioning/#version-35) 使用`name`来代替。

你还可以在Compose文件中单独指定用于引用它的名称来指定网络的名称：

```yaml
networks:
  outside:
    external:
      name: actual-name-of-network
```

### `name`

> [在3.5版本文件格式中](https://docs.docker.com/compose/compose-file/compose-versioning/#version-35)

为此网络设置一个自定义名称。名称字段可用于引用包含特殊字符的网络。该名称按原样使用，**不会**与堆栈名称一起作用。

```yaml
version: '3.5'
networks:
  network1:
    name: my-app-net
```

它也可以与`external`结合使用：

```yaml
version: '3.5'
networks:
  network1:
    external: true
    name: my-app-net
```
## `configs`  配置参考

顶层`configs`声明定义或引用 可以授予服务编排中的服务的[配置](https://docs.docker.com/engine/swarm/configs/)。配置的来源是`file`或者`external`。

- `file`：使用**指定路径的文件**内容创建配置文件。
- `external`：如果设置为`true`，则**指定的配置已经创建**。Docker不会尝试创建它，如果它不存在，`config not found`则会发生错误。
- `name`：Docker中配置**对象的名称**。该字段可用于引用包含**特殊字符**的配置。该名称按原样使用，**不会**与编排名称一起作用。以3.5版本文件格式引入。

在这个例子中，`my_first_config`被创建（ `<stack_name>_my_first_config)`当堆栈被部署，并且`my_second_config`已经存在于Docker中。

```yaml
configs:
  my_first_config:
    file: ./config_data
  my_second_config:
    external: true
```

外部配置的另一个变体是Docker中的**配置名称与服务中存在的名称**不同。以下示例修改前一个示例以使用调用的外部配置`redis_config`。

```yaml
configs:
  my_first_config:
    file: ./config_data
  my_second_config:
    external:
      name: redis_config
```

仍然需要将[访问权限授予](https://docs.docker.com/compose/compose-file/#configs)堆栈中的每个服务。

## `secrets` 配置参考

顶层`secrets`声明定义或引用可以授予此堆栈中的服务的[秘密](https://docs.docker.com/engine/swarm/secrets/)。秘密的来源是`file`或者`external`。

- `file`：秘密通过**指定路径中的文件内容**创建。
- `external`：如果设置为true，则指定秘密**已经创建**。Docker不会尝试创建它，如果它不存在，`secret not found`则会发生错误。
- `name`：Docker中的秘密**对象的名称**。该字段可用于引用包含特殊字符的秘密。该名称按原样使用，**不会**与堆栈名称一起作用。以3.5版本文件格式引入。

在这个例子中，`my_first_secret`被创建（ `<stack_name>_my_first_secret)`当堆栈被部署，并且`my_second_secret`已经存在于Docker中。

```yaml
secrets:
  my_first_secret:
    file: ./secret_data
  my_second_secret:
    external: true
```

外部机密的另一个变体是Docker中的秘密名称与服务中存在的名称不同。以下示例修改前一个使用调用的外部秘密`redis_secret`。

```yaml
secrets:
  my_first_secret:
    file: ./secret_data
  my_second_secret:
    external:
      name: redis_secret
```

你仍然需要[授予](https://docs.docker.com/compose/compose-file/#secrets)对堆栈中每个服务[的秘密访问权限](https://docs.docker.com/compose/compose-file/#secrets)。

## `env` 变量表达式

你的配置选项可以包含环境变量。Compose使用`docker-compose`运行的shell环境中的变量值。例如，假设shell包含`POSTGRES_VERSION=9.3`并且你提供了此配置：

```
db:
  image: "postgres:${POSTGRES_VERSION}"
```

当`docker-compose up`使用此配置运行时，Compose将`POSTGRES_VERSION`在`shell`中查找 **环境变量并替换其中的值**。对于此示例，在运行配置之前，Compose会解析`image`  `postgres:9.3`。

如果**未设置**环境变量，则Compose将**替换为空字符串**。在上例中，如果`POSTGRES_VERSION`未设置，则该`image`选项的值为`postgres:`。

你可以使用Compose自动查找的[`.env`文件](https://docs.docker.com/compose/env-file/)为环境变量设置默认值 。在`shell`环境中设置的值将覆盖`.env`文件中设置的值。

> **重要说明**：`.env`文件功能仅在使用`docker-compose up`命令时才起作用，并且不适用于`docker stack deploy`。

两者`$VARIABLE`和`${VARIABLE}`语法均受支持。此外，使用[2.1文件格式时](https://docs.docker.com/compose/compose-file/compose-versioning/#version-21)，可以使用典型的`shell`语法提供内联缺省值：

- 如果`VARIABLE`在环境中未设置或为空，`${VARIABLE：-default}` 为默认值。
- 只有在环境中未设置`VARIABLE`的情况下，`${VARIABLE-default}`才会为默认值。

同样，以下语法允许指定强制变量：

- 如果`VARIABLE`在环境中未设置或为空，`$ {VARIABLE：? err}`会退出，并显示包含`err`的错误消息。
- 如果`VARIABLE`在环境中未设置，则`${VARIABLE ? err}`会退出，并显示包含`err`的错误消息。

其他扩展的`shell`式功能，例如`${VARIABLE/foo/bar}`，不受支持。

当配置需要字面美元符号时，可以使用`$$`（双美元符号）。这也可以防止Compose插值，**因此`$$`允许引用不想由Compose处理的环境变量**。

```yaml
web:
  build: .
  command: "$$VAR_NOT_INTERPOLATED_BY_COMPOSE"
```

如果忘记并使用单个美元符号（`$`），Compose会将该值解释为环境变量并警告你：

`VAR_NOT_INTERPOLATED_BY_COMPOSE`未设置，替换空字符串。

## 扩展字段

> [在3.4版文件格式中添加](https://docs.docker.com/compose/compose-file/compose-versioning/#version-34)。

可以使用**扩展字段**重新使用配置片段。这些特殊字段可以是**任何格式**，只要它们位于Compose文件的**根目录下**，并且它们的名称以`x-`字符序列**开头**。

```yaml
version: '2.1'
x-custom:
  items:
    - a
    - b
  options:
    max-size: '12m'
  name: "custom"
```

这些字段的内容被Compose忽略，但它们可以使用[YAML锚定符](http://www.yaml.org/spec/1.2/spec.html#id2765878)插入到资源定义中。例如，如果希望多个服务使用相同的日志配置：

```yaml
logging:
  options:
    max-size: '12m'
    max-file: '5'
  driver: json-file
```

可以按如下方式编写你的compose文件：

```yaml
version: '2.1'
x-logging: &default-logging
  options:
    max-size: '12m'
    max-file: '5'
  driver: json-file

services:
  web:
    image: myapp/web:latest
    logging: *default-logging
  db:
    image: mysql:latest
    logging: *default-logging
```

也可以使用[YAML合并类型](http://yaml.org/type/merge.html)部分**覆盖**扩展字段中的值。例如：

```yaml
version: '2.1'
x-volumes: &default-volume
  driver: foobar-storage

services:
  web:
    image: myapp/web:latest
    volumes: ["vol1", "vol2", "vol3"]
volumes:
  vol1: *default-volume
  vol2:
    << : *default-volume
    name: volume02
  vol3:
    << : *default-volume
    driver: default # 覆盖自定义配置
    name: volume-local
```