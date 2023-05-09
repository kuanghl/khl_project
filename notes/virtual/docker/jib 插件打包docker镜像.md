# JIB 插件打包 docker 镜像

官方`github` 地址：https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#quickstart

`JIB` 是一个工具，可以为`Java`程序构建`docker`镜像，可以在`maven`和`Gradle`中以插件的方式使用，能在`maven`的配置文件`pom.xml`中完成 **镜像** 打包的配置，通过`maven`的命令就能将镜像拉取或推送到远程仓库。



# 优点

+ **高效** - **快速**发布、快速迭代也有的变更。Jib将应用程序分成多个镜像图层，从类中分离依赖项。现在不必等待`Docker`重建整个`Java`应用程序，只需重新发布修改的图层即可。
+ **可重现** - 使用相同内容重建容器镜像始终生成相同的镜像。切勿再次触发不必要的更新。
+ **Daemonless** - 减少CLI依赖性。从`Maven`或`Gradle`中构建`Docker`镜像，然后推送到配置的任何注册表。**不再编写Dockerfiles并调用docker build/push**。

# 工作原理

传统上，Java应用使用**应用程序JAR**构建为单个图像层，而Jib的构建策略将Java应用程序分为多个层(可以理解为多个增量的JAR)，以实现更细粒度的增量构建。更改代码时，只会重建更新的部分，而不是整个应用程序。默认情况下，这些图层位于[distroless](https://github.com/GoogleCloudPlatform/distroless)基本图像的顶部。

# 快速入门

## 构建镜像

使用命令构建镜像，前提是当前工程是maven项目，且目录应该有 maven 配置文件 `pom.xml` ，这个操作会将应用程序构建并推送到容器注册仓库中，如果仓库需要登录，还需要设置额外的登录配置信息。 

```shell
# image 参数为 镜像名称
$ mvn compile com.google.cloud.tools:jib-maven-plugin:0.9.8:build -Dimage=<MY IMAGE>
```

## 构建到`docker`守护进程

构建到 docker 守护进程应用程序命令：

```sh
$ mvn compile com.google.cloud.tools:jib-maven-plugin:0.9.8:dockerBuild
```



# 基本配置

在 `maven` 配置文件 `pom.xml` 中增加仓库配置， `image` 标签中的内容，决定推送的仓库位置，这里采用 阿里云的 `docker` 镜像仓库。

```xml
<build>
    <plugins>
        <plugin>
            <groupId>com.google.cloud.tools</groupId>
            <artifactId>jib-maven-plugin</artifactId>
            <version>0.9.8</version>
            <configuration>
                <to>
                    <image>registry.cn-hangzhou.aliyuncs.com/hoojo/fabric-chaincode-manager:0.1</image>
                </to>
            </configuration>
        </plugin>
    </plugins>
</build>
```



# 基本命令



## 构建容器镜像

为应用程序构建镜像

```shell
$ mvn compile jib:build
```

首次构建需要准备环境和一些依赖的配置、文件，所以会有点慢。后面速度会比第一次快很多！

## 将镜像构建到守护进程上
（指定的主机中的docker环境中），`Jib`还可以将镜像直接构建到`Docker`守护程序中。这将会使用`docker`命令行工具，并要求你的计算机中的`PATH`环境变量已经配置好可以使用`docker`命令行工具。  

  ```sh
  $ mvn compile jib:dockerBuild
  ```

  如果使用的是[`minikube`](https://github.com/kubernetes/minikube)远程Docker守护程序，请确保[设置正确的环境变量](https://github.com/kubernetes/minikube/blob/master/docs/reusing_the_docker_daemon.md)以指向远程守护程序： 

  ```sh
  # 这将配置你的环境变量，指向的 docker 守护进程主机
  $ eval $(minikube docker-env)
  $ mvn compile jib:dockerBuild
  ```

## 构建图像 `tarball`
可以使用命令将**镜像构建并保存到磁盘**，这会构建并将镜像保存到`target/jib-image.tar`，可以将其加载到`docker`中：

  ```sh
  $ mvn compile jib:buildTar
  ```

将镜像 `tar` 包加载到 docker 镜像中

```sh
$ docker load --input jib-image.tar

# docker import jib-image.tar masget/fabric-chaincode-manager:0.1
```

## 绑定生命周期

可以绑定`jib:build`到`Maven`生命周期，例如`package`，通过向`jib-maven-plugin`定义添加以下执行：  

  ```xml
  <plugin>
    <groupId>com.google.com.tools</groupId>
    <artifactId>jib-maven-plugin</artifactId>
    ...
    <executions>
      <execution>
        <phase>package</phase>
        <goals>
          <goal>build</goal>
        </goals>
      </execution>
    </executions>
  </plugin>
  ```

  然后，可以通过运行以下命令来构建容器映像：

  ```sh
  $ mvn package
  ```

## 导出到`Docker`上下文
利用docker构建镜像，Jib 还可以导出 `Docker`上下文，以便可以根据需要使用Docker进行构建。

  ```sh
  $ mvn compile jib:exportDockerContext
  ```

  默认情况下，Docker上下文将在`target/jib-docker-context`中创建。可以使用`targetDir`配置选项或`jibTargetDir`参数更改此目录：

  ```sh
  $ mvn compile jib:exportDockerContext -DjibTargetDir=my/docker/context/
  ```

  然后，可以使用Docker构建映像：

  ```sh
  $ docker build -t myimage my/docker/context/
  ```

## 设置超时时间
使用`jib.httpTimeout`系统属性为**镜像仓库**交互配置`HTTP`连接/读取超时，通过命令行以**毫秒**为单位进行配置（默认为`20000` 可以将其设置`0`为无限超时）： 

  ```sh
  $ mvn compile jib:build -Djib.httpTimeout=3000
  ```

# 扩展配置

扩展配置选项提供了用于自定义映像构建的其他选项。

## `configuration` 配置

具有以下配置属性标签

| 标签属性                  | 类型                                                         | 默认值                                                       | 描述                                                         |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `from`                    | [`from`](https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#from-object) | 查看 [`from`](https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#from-object) | 配置基础映像以构建应用程序。是当前构建镜像的运行环境基础。   |
| `to`                      | [`to`](https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#to-object) | 空，**必要**                                                 | 配置目标映像以构建应用程序。                                 |
| `container`               | [`container`](https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#container-object) | 查看`container`                                              | 配置从映像运行的容器。                                       |
| `useOnlyProjectCache`     | `boolean`                                                    | `false`                                                      | 如果设置为true，则Jib**不会**在不同的Gradle项目之间**共享缓存**。 |
| `allowInsecureRegistries` | `boolean`                                                    | `false`                                                      | 如果设置为true，则Jib会**忽略HTTPS证书错误**，并可能作为最后的手段回退到HTTP。强烈建议此参数设置`false`，因为HTTP通信未加密且网络上的其他人可见，并且不安全的HTTPS并不比普通HTTP好。[如果使用自签名证书访问注册表，则将证书添加到Java运行时的可信密钥](https://github.com/GoogleContainerTools/jib/tree/master/docs/self_sign_cert.md)可能是启用此选项的替代方法。 |

## `from` 配置
具有以下属性的对象：

| 标签属性     | 类型                                                         | 默认                     | 描述                                                         |
| ------------ | ------------------------------------------------------------ | ------------------------ | ------------------------------------------------------------ |
| `image`      | `String`                                                     | `gcr.io/distroless/java` | 基础图像的图像名称引用。                                     |
| `credHelper` | `String`                                                     | *没有*                   | 可以验证拉取基本映像的凭证帮助程序的后缀（在`docker-credential-`之后）。 |
| `auth`       | [`auth`](https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#auth-object) | *没有*                   | 直接指定凭证（替代`credHelper`）。                           |

## `to`配置
具有以下属性的对象： 

| 标签属性     | 类型                                                         | 默认   | 描述                                                         |
| ------------ | ------------------------------------------------------------ | ------ | ------------------------------------------------------------ |
| `image`      | `String`                                                     | *需要* | 目标图像的名称或仓库位置。也可以通过`-Dimage`命令行选项指定。 |
| `credHelper` | `String`                                                     | *没有* | 可以验证拉基本映像的凭证帮助程序的后缀（下面`docker-credential-`）。 |
| `auth`       | [`auth`](https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#auth-object) | *没有* | 直接指定凭证（替代`credHelper`）。                           |

## `auth`配置
具有以下属性的对象（请参阅[使用特定凭据](https://github.com/GoogleContainerTools/jib/tree/master/jib-maven-plugin#using-specific-credentials)）：

| 标签属性   | 类型     |
| ---------- | -------- |
| `username` | `String` |
| `password` | `String` |

## `container`配置
具有以下属性的对象：

| 标签属性              | 类型      | 默认     | 描述                                                         |
| --------------------- | --------- | -------- | ------------------------------------------------------------ |
| `jvmFlags`            | `List`    | *没有*   | 运行应用程序时传入`JVM`的其他标志。                          |
| `mainClass`           | `String`  | *推断*   | 从中启动应用程序的`main`函数入口类。                         |
| `args`                | `List`    | *没有*   | 使用运行应用程序的默认主方法参数。                           |
| `ports`               | `List`    | *没有*   | 容器在运行时公开的端口（类似于Docker的[EXPOSE](https://docs.docker.com/engine/reference/builder/#expose)指令）。 |
| `format`              | `String`  | `Docker` | 使用`OCI`建立一个[OCI容器图像](https://www.opencontainers.org/)。 |
| `useCurrentTimestamp` | `boolean` | `false`  | 默认情况下，Jib会擦除所有时间戳以保证可重复性。如果将此参数设置为`true`，则Jib会将图像的创建时间戳设置为构建时间，这会牺牲再现性，以便能够轻松判断图像的创建时间。 |

## 使用特定凭据

### `XML` 中配置

可以直接在`<auth>`参数中为`from/to` 镜像指定凭据。在下面的示例中，从`REGISTRY_USERNAME和REGISTRY_PASSWORD`环境变量中检索凭据。

```xml
<configuration>
  ...
  <from>
    <image>aws_account_id.dkr.ecr.region.amazonaws.com/my-base-image</image>
    <auth>
      <username>my_username</username>
      <password>my_password</password>
    </auth>
  </from>
  <to>
    <image>gcr.io/my-gcp-project/my-app</image>
    <auth>
      <username>${env.REGISTRY_USERNAME}</username>
      <password>${env.REGISTRY_PASSWORD}</password>
    </auth>
  </to>
  ...
</configuration>
```

### `shell` 中配置

可以使用以下系统属性通过命令行指定凭据

| 属性                       | 描述                     |
| -------------------------- | ------------------------ |
| `-Djib.from.auth.username` | 基本映像注册表的用户名。 |
| `-Djib.from.auth.password` | 基本映像注册表的密码。   |
| `-Djib.to.auth.username`   | 目标映像注册表的用户名。 |
| `-Djib.to.auth.password`   | 目标映像注册表的密码。   |

在命令行中使用凭证如下：

```sh
$ mvn compile jib:build -Djib.to.auth.username=user -Djib.to.auth.password=pass
```

### `maven` 中配置

注册表凭据可以添加到[Maven设置中](https://maven.apache.org/settings.html)。如果在任何指定的Docker凭据帮助程序中找不到凭据，则将使用这些凭据。

>  如果您正在考虑在Maven中提供凭据，我们强烈*建议您*使用[maven密码加密](https://maven.apache.org/guides/mini/guide-encryption.html)。

在 `maven` 的 `settings.xml` 文件中增加配置

```xml
<settings>
  ...
  <servers>
    ...
    <server>
      <id>MY_REGISTRY</id>
      <username>MY_USERNAME</username>
      <password>{MY_SECRET}</password>
    </server>
  </servers>
</settings>
```

这里的 `id` 中的 `MY_REGISTRY` 就是 镜像仓库的名称。

# 示例演示

以下的配置是 maven 的 `pom.xml` 中配置某个镜像的示例

```xml
<configuration>
    <!-- 依赖的基础镜像，这里会从 docker hub中拉取该镜像 -->
    <from>
        <image>openjdk:alpine</image>
    </from>
    <to>
        <!-- 当前镜像发布的位置 -->
        <image>localhost:5000/my-image:built-with-jib</image>
        <credHelper>osxkeychain</credHelper>
    </to>
    <!-- 当前镜像运行的容器配置，从镜像 构建 容器  -->
    <container>
        <!-- JVM 的基本配置 -->
        <jvmFlags>
            <jvmFlag>-Xms512m</jvmFlag>
            <jvmFlag>-Xdebug</jvmFlag>
            <jvmFlag>-Xmy:flag=jib-rules</jvmFlag>
        </jvmFlags>
        <!-- 启动容器后提供的main 函数对应的入口类  -->
        <mainClass>mypackage.MyApp</mainClass>
        <!-- main 函数类需要的参数 -->
        <args>
            <arg>some</arg>
            <arg>args</arg>
        </args>
        <!-- 容器运行后暴露的端口 -->
        <ports>
            <port>1000</port>
            <port>2000-2003/udp</port>
        </ports>
        <!-- 镜像构建容器的格式 -->
        <format>OCI</format>
    </container>
</configuration>
```

此图像的配置中：

- `form image` 是从`openjdk:alpine`（从`Docker Hub`拉出）的基础构建的
- `to image` 被推到仓库  `localhost:5000/my-image:built-with-jib`
- 运行函数和配置 `java -Xms512m -Xdebug -Xmy:flag=jib-rules -cp app/libs/*:app/resources:app/classes mypackage.MyApp some args`
- 暴露端口`1000`用于`tcp`（默认），端口`2000,2001,2002`和`2003`用于`udp`
- 构建为`OCI`格式

