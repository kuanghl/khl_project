# docker swarm 集群的应用

* [docker swarm 集群的应用](#docker-swarm-%E9%9B%86%E7%BE%A4%E7%9A%84%E5%BA%94%E7%94%A8)
* [在集群模式下运行Docker引擎](#%E5%9C%A8%E9%9B%86%E7%BE%A4%E6%A8%A1%E5%BC%8F%E4%B8%8B%E8%BF%90%E8%A1%8Cdocker%E5%BC%95%E6%93%8E)
  * [配置通知地址](#%E9%85%8D%E7%BD%AE%E9%80%9A%E7%9F%A5%E5%9C%B0%E5%9D%80)
  * [查看加入命令或更新加入令牌](#%E6%9F%A5%E7%9C%8B%E5%8A%A0%E5%85%A5%E5%91%BD%E4%BB%A4%E6%88%96%E6%9B%B4%E6%96%B0%E5%8A%A0%E5%85%A5%E4%BB%A4%E7%89%8C)
* [将节点加入集群](#%E5%B0%86%E8%8A%82%E7%82%B9%E5%8A%A0%E5%85%A5%E9%9B%86%E7%BE%A4)
  * [作为工作节点加入](#%E4%BD%9C%E4%B8%BA%E5%B7%A5%E4%BD%9C%E8%8A%82%E7%82%B9%E5%8A%A0%E5%85%A5)
  * [作为管理节点加入](#%E4%BD%9C%E4%B8%BA%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9%E5%8A%A0%E5%85%A5)
* [管理群中的节点](#%E7%AE%A1%E7%90%86%E7%BE%A4%E4%B8%AD%E7%9A%84%E8%8A%82%E7%82%B9)
  * [列出节点](#%E5%88%97%E5%87%BA%E8%8A%82%E7%82%B9)
  * [检查单个节点](#%E6%A3%80%E6%9F%A5%E5%8D%95%E4%B8%AA%E8%8A%82%E7%82%B9)
  * [更新节点](#%E6%9B%B4%E6%96%B0%E8%8A%82%E7%82%B9)
    * [更改节点可用性](#%E6%9B%B4%E6%94%B9%E8%8A%82%E7%82%B9%E5%8F%AF%E7%94%A8%E6%80%A7)
    * [添加或删除标签元数据](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E6%A0%87%E7%AD%BE%E5%85%83%E6%95%B0%E6%8D%AE)
    * [升级或降级节点](#%E5%8D%87%E7%BA%A7%E6%88%96%E9%99%8D%E7%BA%A7%E8%8A%82%E7%82%B9)
  * [在集群节点上安装插件](#%E5%9C%A8%E9%9B%86%E7%BE%A4%E8%8A%82%E7%82%B9%E4%B8%8A%E5%AE%89%E8%A3%85%E6%8F%92%E4%BB%B6)
  * [离开集群](#%E7%A6%BB%E5%BC%80%E9%9B%86%E7%BE%A4)
* [将服务部署到集群](#%E5%B0%86%E6%9C%8D%E5%8A%A1%E9%83%A8%E7%BD%B2%E5%88%B0%E9%9B%86%E7%BE%A4)
  * [创建一个服务](#%E5%88%9B%E5%BB%BA%E4%B8%80%E4%B8%AA%E6%9C%8D%E5%8A%A1)
    * [使用私人注册表中的镜像创建服务](#%E4%BD%BF%E7%94%A8%E7%A7%81%E4%BA%BA%E6%B3%A8%E5%86%8C%E8%A1%A8%E4%B8%AD%E7%9A%84%E9%95%9C%E5%83%8F%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
  * [更新服务](#%E6%9B%B4%E6%96%B0%E6%9C%8D%E5%8A%A1)
  * [删除服务](#%E5%88%A0%E9%99%A4%E6%9C%8D%E5%8A%A1)
  * [服务配置细节](#%E6%9C%8D%E5%8A%A1%E9%85%8D%E7%BD%AE%E7%BB%86%E8%8A%82)
    * [配置运行时环境](#%E9%85%8D%E7%BD%AE%E8%BF%90%E8%A1%8C%E6%97%B6%E7%8E%AF%E5%A2%83)
    * [更新已有服务](#%E6%9B%B4%E6%96%B0%E5%B7%B2%E6%9C%89%E6%9C%8D%E5%8A%A1)
    * [指定服务使用的镜像版本](#%E6%8C%87%E5%AE%9A%E6%9C%8D%E5%8A%A1%E4%BD%BF%E7%94%A8%E7%9A%84%E9%95%9C%E5%83%8F%E7%89%88%E6%9C%AC)
    * [更新服务的镜像](#%E6%9B%B4%E6%96%B0%E6%9C%8D%E5%8A%A1%E7%9A%84%E9%95%9C%E5%83%8F)
      * [如果管理器成功解析标签](#%E5%A6%82%E6%9E%9C%E7%AE%A1%E7%90%86%E5%99%A8%E6%88%90%E5%8A%9F%E8%A7%A3%E6%9E%90%E6%A0%87%E7%AD%BE)
      * [如果管理器无法解析标签](#%E5%A6%82%E6%9E%9C%E7%AE%A1%E7%90%86%E5%99%A8%E6%97%A0%E6%B3%95%E8%A7%A3%E6%9E%90%E6%A0%87%E7%AD%BE)
  * [发布端口](#%E5%8F%91%E5%B8%83%E7%AB%AF%E5%8F%A3)
    * [使用路由网格发布服务的端口](#%E4%BD%BF%E7%94%A8%E8%B7%AF%E7%94%B1%E7%BD%91%E6%A0%BC%E5%8F%91%E5%B8%83%E6%9C%8D%E5%8A%A1%E7%9A%84%E7%AB%AF%E5%8F%A3)
      * [示例：在10个节点群上运行三任务Nginx服务](#%E7%A4%BA%E4%BE%8B%E5%9C%A810%E4%B8%AA%E8%8A%82%E7%82%B9%E7%BE%A4%E4%B8%8A%E8%BF%90%E8%A1%8C%E4%B8%89%E4%BB%BB%E5%8A%A1nginx%E6%9C%8D%E5%8A%A1)
    * [直接在集群节点上发布服务的端口](#%E7%9B%B4%E6%8E%A5%E5%9C%A8%E9%9B%86%E7%BE%A4%E8%8A%82%E7%82%B9%E4%B8%8A%E5%8F%91%E5%B8%83%E6%9C%8D%E5%8A%A1%E7%9A%84%E7%AB%AF%E5%8F%A3)
      * [示例：nginx在每个集群节点上运行Web服务](#%E7%A4%BA%E4%BE%8Bnginx%E5%9C%A8%E6%AF%8F%E4%B8%AA%E9%9B%86%E7%BE%A4%E8%8A%82%E7%82%B9%E4%B8%8A%E8%BF%90%E8%A1%8Cweb%E6%9C%8D%E5%8A%A1)
  * [将服务连接到覆盖网络](#%E5%B0%86%E6%9C%8D%E5%8A%A1%E8%BF%9E%E6%8E%A5%E5%88%B0%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C)
  * [授予对secret的服务访问权限](#%E6%8E%88%E4%BA%88%E5%AF%B9secret%E7%9A%84%E6%9C%8D%E5%8A%A1%E8%AE%BF%E9%97%AE%E6%9D%83%E9%99%90)
  * [自定义服务的隔离模式](#%E8%87%AA%E5%AE%9A%E4%B9%89%E6%9C%8D%E5%8A%A1%E7%9A%84%E9%9A%94%E7%A6%BB%E6%A8%A1%E5%BC%8F)
  * [控制服务分布](#%E6%8E%A7%E5%88%B6%E6%9C%8D%E5%8A%A1%E5%88%86%E5%B8%83)
    * [副本服务或全局服务](#%E5%89%AF%E6%9C%AC%E6%9C%8D%E5%8A%A1%E6%88%96%E5%85%A8%E5%B1%80%E6%9C%8D%E5%8A%A1)
    * [为服务预留内存或CPU](#%E4%B8%BA%E6%9C%8D%E5%8A%A1%E9%A2%84%E7%95%99%E5%86%85%E5%AD%98%E6%88%96cpu)
    * [内存异常（OOME）](#%E5%86%85%E5%AD%98%E5%BC%82%E5%B8%B8oome)
    * [分布约束](#%E5%88%86%E5%B8%83%E7%BA%A6%E6%9D%9F)
    * [分布偏好设置](#%E5%88%86%E5%B8%83%E5%81%8F%E5%A5%BD%E8%AE%BE%E7%BD%AE)
  * [配置服务的更新行为](#%E9%85%8D%E7%BD%AE%E6%9C%8D%E5%8A%A1%E7%9A%84%E6%9B%B4%E6%96%B0%E8%A1%8C%E4%B8%BA)
  * [回滚服务](#%E5%9B%9E%E6%BB%9A%E6%9C%8D%E5%8A%A1)
  * [更新失败，自动回滚](#%E6%9B%B4%E6%96%B0%E5%A4%B1%E8%B4%A5%E8%87%AA%E5%8A%A8%E5%9B%9E%E6%BB%9A)
  * [服务访问卷或挂载](#%E6%9C%8D%E5%8A%A1%E8%AE%BF%E9%97%AE%E5%8D%B7%E6%88%96%E6%8C%82%E8%BD%BD)
    * [数据卷](#%E6%95%B0%E6%8D%AE%E5%8D%B7)
    * [绑定挂载](#%E7%BB%91%E5%AE%9A%E6%8C%82%E8%BD%BD)
  * [使用模板创建服务](#%E4%BD%BF%E7%94%A8%E6%A8%A1%E6%9D%BF%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
    * [模板示例](#%E6%A8%A1%E6%9D%BF%E7%A4%BA%E4%BE%8B)
* [docker config 基本命令](#docker-config-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9)
    * [示例](#%E7%A4%BA%E4%BE%8B)
  * [inspect 查看](#inspect-%E6%9F%A5%E7%9C%8B)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-1)
    * [示例](#%E7%A4%BA%E4%BE%8B-1)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4)
* [使用 config 存储数据](#%E4%BD%BF%E7%94%A8-config-%E5%AD%98%E5%82%A8%E6%95%B0%E6%8D%AE)
  * [如何管理 config](#%E5%A6%82%E4%BD%95%E7%AE%A1%E7%90%86-config)
  * [实例演示](#%E5%AE%9E%E4%BE%8B%E6%BC%94%E7%A4%BA)
    * [开始使用 config](#%E5%BC%80%E5%A7%8B%E4%BD%BF%E7%94%A8-config)
    * [在 Windows 中使用 config](#%E5%9C%A8-windows-%E4%B8%AD%E4%BD%BF%E7%94%A8-config)
    * [使用配置与Nginx服务](#%E4%BD%BF%E7%94%A8%E9%85%8D%E7%BD%AE%E4%B8%8Enginx%E6%9C%8D%E5%8A%A1)
      * [生成站点证书](#%E7%94%9F%E6%88%90%E7%AB%99%E7%82%B9%E8%AF%81%E4%B9%A6)
      * [配置NGINX容器](#%E9%85%8D%E7%BD%AEnginx%E5%AE%B9%E5%99%A8)
      * [旋转配置](#%E6%97%8B%E8%BD%AC%E9%85%8D%E7%BD%AE)
* [docker secret 基本命令](#docker-secret-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-2)
    * [示例](#%E7%A4%BA%E4%BE%8B-2)
      * [创建secret](#%E5%88%9B%E5%BB%BAsecret)
      * [用文件创建secret](#%E7%94%A8%E6%96%87%E4%BB%B6%E5%88%9B%E5%BB%BAsecret)
      * [用标签创建secret](#%E7%94%A8%E6%A0%87%E7%AD%BE%E5%88%9B%E5%BB%BAsecret)
  * [inspect 查看](#inspect-%E6%9F%A5%E7%9C%8B-1)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-1)
    * [过滤](#%E8%BF%87%E6%BB%A4)
    * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-1)
* [管理 secret 敏感数据](#%E7%AE%A1%E7%90%86-secret-%E6%95%8F%E6%84%9F%E6%95%B0%E6%8D%AE)
  * [如何管理 secret](#%E5%A6%82%E4%BD%95%E7%AE%A1%E7%90%86-secret)
  * [实例演示](#%E5%AE%9E%E4%BE%8B%E6%BC%94%E7%A4%BA-1)
    * [开始使用 secret](#%E5%BC%80%E5%A7%8B%E4%BD%BF%E7%94%A8-secret)
    * [使用 secret 的 WordPress 服务](#%E4%BD%BF%E7%94%A8-secret-%E7%9A%84-wordpress-%E6%9C%8D%E5%8A%A1)
    * [轮转秘密](#%E8%BD%AE%E8%BD%AC%E7%A7%98%E5%AF%86)
    * [绑定 secret 到镜像中](#%E7%BB%91%E5%AE%9A-secret-%E5%88%B0%E9%95%9C%E5%83%8F%E4%B8%AD)
      * [在compose中使用秘密](#%E5%9C%A8compose%E4%B8%AD%E4%BD%BF%E7%94%A8%E7%A7%98%E5%AF%86)
* [锁定集群保护数据](#%E9%94%81%E5%AE%9A%E9%9B%86%E7%BE%A4%E4%BF%9D%E6%8A%A4%E6%95%B0%E6%8D%AE)
  * [使用自动锁定初始化集群](#%E4%BD%BF%E7%94%A8%E8%87%AA%E5%8A%A8%E9%94%81%E5%AE%9A%E5%88%9D%E5%A7%8B%E5%8C%96%E9%9B%86%E7%BE%A4)
  * [在集群上启用或禁用自动锁定](#%E5%9C%A8%E9%9B%86%E7%BE%A4%E4%B8%8A%E5%90%AF%E7%94%A8%E6%88%96%E7%A6%81%E7%94%A8%E8%87%AA%E5%8A%A8%E9%94%81%E5%AE%9A)
  * [解锁集群](#%E8%A7%A3%E9%94%81%E9%9B%86%E7%BE%A4)
  * [查看运行的集群的解锁密钥](#%E6%9F%A5%E7%9C%8B%E8%BF%90%E8%A1%8C%E7%9A%84%E9%9B%86%E7%BE%A4%E7%9A%84%E8%A7%A3%E9%94%81%E5%AF%86%E9%92%A5)
  * [转变解锁秘钥](#%E8%BD%AC%E5%8F%98%E8%A7%A3%E9%94%81%E7%A7%98%E9%92%A5)
* [集群管理指南](#%E9%9B%86%E7%BE%A4%E7%AE%A1%E7%90%86%E6%8C%87%E5%8D%97)
  * [操作集群的管理节点](#%E6%93%8D%E4%BD%9C%E9%9B%86%E7%BE%A4%E7%9A%84%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9)
    * [维持管理人员的法定人数](#%E7%BB%B4%E6%8C%81%E7%AE%A1%E7%90%86%E4%BA%BA%E5%91%98%E7%9A%84%E6%B3%95%E5%AE%9A%E4%BA%BA%E6%95%B0)
  * [配置管理器通过静态IP进行通知](#%E9%85%8D%E7%BD%AE%E7%AE%A1%E7%90%86%E5%99%A8%E9%80%9A%E8%BF%87%E9%9D%99%E6%80%81ip%E8%BF%9B%E8%A1%8C%E9%80%9A%E7%9F%A5)
  * [添加管理器节点以实现容错](#%E6%B7%BB%E5%8A%A0%E7%AE%A1%E7%90%86%E5%99%A8%E8%8A%82%E7%82%B9%E4%BB%A5%E5%AE%9E%E7%8E%B0%E5%AE%B9%E9%94%99)
    * [分配管理节点](#%E5%88%86%E9%85%8D%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9)
    * [仅限的管理节点](#%E4%BB%85%E9%99%90%E7%9A%84%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9)
  * [添加工作节点以实现负载平衡](#%E6%B7%BB%E5%8A%A0%E5%B7%A5%E4%BD%9C%E8%8A%82%E7%82%B9%E4%BB%A5%E5%AE%9E%E7%8E%B0%E8%B4%9F%E8%BD%BD%E5%B9%B3%E8%A1%A1)
  * [监测集群健康](#%E7%9B%91%E6%B5%8B%E9%9B%86%E7%BE%A4%E5%81%A5%E5%BA%B7)
  * [排除管理节点故障](#%E6%8E%92%E9%99%A4%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9%E6%95%85%E9%9A%9C)
  * [强制删除节点](#%E5%BC%BA%E5%88%B6%E5%88%A0%E9%99%A4%E8%8A%82%E7%82%B9)
  * [备份集群](#%E5%A4%87%E4%BB%BD%E9%9B%86%E7%BE%A4)
  * [从灾难中恢复集群](#%E4%BB%8E%E7%81%BE%E9%9A%BE%E4%B8%AD%E6%81%A2%E5%A4%8D%E9%9B%86%E7%BE%A4)
    * [从备份中恢复](#%E4%BB%8E%E5%A4%87%E4%BB%BD%E4%B8%AD%E6%81%A2%E5%A4%8D)
    * [从失去法定人数恢复](#%E4%BB%8E%E5%A4%B1%E5%8E%BB%E6%B3%95%E5%AE%9A%E4%BA%BA%E6%95%B0%E6%81%A2%E5%A4%8D)
  * [强制集群重新平衡](#%E5%BC%BA%E5%88%B6%E9%9B%86%E7%BE%A4%E9%87%8D%E6%96%B0%E5%B9%B3%E8%A1%A1)
* [集群模式中的共识机制](#%E9%9B%86%E7%BE%A4%E6%A8%A1%E5%BC%8F%E4%B8%AD%E7%9A%84%E5%85%B1%E8%AF%86%E6%9C%BA%E5%88%B6)

上面介绍过集群的创建和应用，这里详细介绍集群的原理和流程，以及需要注意的问题。

# 在集群模式下运行Docker引擎

当首次安装并开始使用Docker Engine时，集群模式默认处于禁用状态。当启用集群模式时，将使用通过`docker service`命令管理的服务概念。 

当在本地计算机上以集群模式运行引擎时，可以根据自己创建的镜像或其他可用镜像来创建和测试服务。在生产环境中，集群模式提供具有**集群管理功能**的**容错平台**，以保持服务正常运行。 

当运行命令**创建集群**时，Docker引擎开始以**集群模式运行**。运行[`docker swarm init`](https://docs.docker.com/engine/reference/commandline/swarm_init/) 以在**当前节点**上**创建单节点集群**。引擎的工作流程如下：

- 将当前节点切换到集群模式。
- 创建一个名为`default`的集群。
- 指定**当前节点**作为该群的**领导者管理者节点**。
- 用机器**主机名**命名节点。
- 配置管理器在**端口2377**上监听活动网络接口。
- 将**当前节点设置为`Active`可用性**，这意味着它可以从调度程序**接收任务**。
- 为参与集群的引擎**启动**一个**内部分布式数据存储**，以维护集群及其上运行的所有服务的一致**视图**。
- 默认情况下，为集群生成一个**自签名的根CA**。
- 默认情况下，为worker和manager节点**生成令牌**以加入集群。
- 创建一个**覆盖网络`ingress`**，网络命名为发布集群外部的服务端口。

输出用于`docker swarm init`提供将新工作节点加入集群时使用的连接命令：

```sh
$ docker swarm init
Swarm initialized: current node (dxn1zf6l61qsb1josjja83ngz) is now a manager.
To add a worker to this swarm, run the following command:

    docker swarm join \
    --token SWMTKN-1-49nj1cmql0jkz5s954yi3oex3nedyz0fb0xx14ie39trti4wxv-8vxv8rssmk743ojnwacrr2e7c \
    192.168.99.100:2377

To add a manager to this swarm, run 'docker swarm join-token manager' and follow the instructions.
```

## 配置通知地址

管理器节点使用**通知地址**允许集群中的**其他节点访问Swarmkit API并覆盖网络**。集群中的**其他节点**必须能够在其**广播**地址上**访问管理器节点**。

如果**未指定**通知地址，则Docker将**检查**系统是否具有**单个IP地址**。如果存在单个IP地址，默认情况下Docker使用侦听端口`2377`的IP地址 。如果系统有**多个IP**地址，则必须**指定确切**的`--advertise-addr`以启用管理员间通信和覆盖网络：

```sh
$ docker swarm init --advertise-addr <MANAGER-IP>
```

如果**其他节点**到达**第一个管理器节点**的地址与管理员认为的**地址不同**，那么还必须指定`--advertise-addr`。例如，在跨越不同区域的云设置中，主机具有用于在该区域内访问的**内部地址**以及用于从该区域外访问的**外部地址**。在这种情况下，使用`--advertise-addr`指定外部地址，以便节点可以将信息传播到随后连接到节点的其他节点。

## 查看加入命令或更新加入令牌

节点需要一个**secret的令牌**来加入群。工作节点的标记与管理器节点的标记不同。节点在加入群时只使用**连接**令牌。在节点已经加入集群之后**旋转连接令牌**不会影响节点的集群**成员资格**。令牌轮转可确保任何**尝试加入**集群的**新节点**都不能使用**旧令牌**。

要检索包含工作节点的连接令牌的连接命令，请运行：

```sh
$ docker swarm join-token worker
To add a worker to this swarm, run the following command:

    docker swarm join \
    --token SWMTKN-1-49nj1cmql0jkz5s954yi3oex3nedyz0fb0xx14ie39trti4wxv-8vxv8rssmk743ojnwacrr2e7c \
    192.168.99.100:2377

This node joined a swarm as a worker.
```

要查看管理器节点的连接命令和令牌，请运行：

```sh
$ docker swarm join-token manager

To add a worker to this swarm, run the following command:

    docker swarm join \
    --token SWMTKN-1-59egwe8qangbzbqb3ryawxzk3jn97ifahlsrw01yar60pmkr90-bdjfnkcflhooyafetgjod97sz \
    192.168.99.100:2377
```

通过`--quiet`选项只打印令牌：

```sh
$ docker swarm join-token --quiet worker

SWMTKN-1-49nj1cmql0jkz5s954yi3oex3nedyz0fb0xx14ie39trti4wxv-8vxv8rssmk743ojnwacrr2e7c
```

**加入令牌时要小心，因为它们是加入集群所必需的秘钥**。特别是将一个检查secret到版本控制是一个不好的做法，因为它允许任何有权访问应用**程序源代码**的人员向集群添加新节点。**管理令牌特别敏感**，因为它们允许新的管理节点加入并获得**整个集群的控制权**。

建议在以下情况下**轮换联合令牌**：

- 如果令牌偶然签入版本控制系统，**群聊或意外打印到日志**中。
- 如果怀疑某个节点已**受到攻击**。
- 如果你想保证**没有新的节点可以加入**群。

此外，对包括集群加入令牌在内的任何secret实施**定期轮换**计划是最佳做法。我们建议您至少**每6个月**轮换一次令牌。

运行`swarm join-token --rotate`使**旧的令牌失效并生成新的令牌**。指定是否要旋转`worker`或`manager` 节点的标记：

```sh
# docker swarm join-token  --rotate manager
$ docker swarm join-token  --rotate worker
To add a worker to this swarm, run the following command:

    docker swarm join \
    --token SWMTKN-1-2kscvs0zuymrsc9t0ocyy1rdns9dhaodvpl639j2bqx55uptag-ebmn5u927reawo27s3azntd44 \
    192.168.99.100:2377
```

# 将节点加入集群

当第一次创建swarm时，将Docker Engine（引擎）开启swarm模式。要充分利用集群模式，可以向集群添加节点：

- **添加工作节点会增加容量**。将服务部署到集群时，引擎会调度可用节点上的任务，无论它们是工作节点还是管理节点。当将工作节点添加到集群中时，可以增加集群的**规模**以处理任务，而不会影响管理节点的**一致性**。
- **管理节点增加了容错能力**。Manager节点为集群执行**编排和集群管理**功能。在管理节点中，**单个管理领导节点**执行编排任务。如果一个管理节点**出现故障**，其余的管理者节点会**选举一个新的领导者**并**恢复**协调和**维护**集群状态。默认情况下，**管理节点也运行任务**。

在将节点添加到集群之前，必须在主机上安装Docker Engine 1.12或更高版本。

Docker引擎根据提供给`docker swarm join`命令的**连接令牌**加入集群。该节点仅在**连接时**使用该令牌。如果**随后**旋转该标记，则**不会影响现有**的集群节点。请参考以[集群模式运行Docker Engine](https://docs.docker.com/engine/swarm/swarm-mode/#view-the-join-command-or-update-a-swarm-join-token)。

## 作为工作节点加入

要查看包含工作节点的连接令牌的连接命令，请在管理节点上运行以下命令：

```sh
$ docker swarm join-token worker
To add a worker to this swarm, run the following command:

    docker swarm join \
    --token SWMTKN-1-49nj1cmql0jkz5s954yi3oex3nedyz0fb0xx14ie39trti4wxv-8vxv8rssmk743ojnwacrr2e7c \
    192.168.99.100:2377
```

在`worker`节点上的输出运行命令加入集群：

```sh
$ docker swarm join \
  --token SWMTKN-1-49nj1cmql0jkz5s954yi3oex3nedyz0fb0xx14ie39trti4wxv-8vxv8rssmk743ojnwacrr2e7c \
  192.168.99.100:2377

This node joined a swarm as a worker.
```

`docker swarm join`命令执行以下操作：

- 将当前节点上的Docker引擎**切换到集群**模式。
- 向管理节点**申请TLS证书**。
- 用机器**主机名命名节点**
- 基于集群**令牌**将当前节点**加入**管理节点监听地址上的集群。
- 将**当前节点设置为`Active`可用性**，这意味着它可以从调度程序**接收任务**。
- 将`ingress`覆盖网络**扩展**到**当前节点**。

## 作为管理节点加入


当运行`docker swarm join`并传递管理器令牌时，Docker引擎将**切换到集群模式**，与工作节点相同。管理节点也参与Raft共识。新的节点应该是`Reachable`，但现有的经理仍然是集群`Leader`。

Docker为每个集群推荐**三个或五个**管理节点来实现**高可用性**。由于群模式管理节点使用Raft共享数据，因此**必须有奇数个管理器**。只要**超过一半**的管理节点的法定数量**可用**，集群可以继续运行。

有关集群管理员和管理集群的更多详细信息，请参阅 [管理和维护一群Docker引擎](https://docs.docker.com/engine/swarm/admin_guide/)。

要查看包含**管理节点**的连接令牌的连接命令，请在管理器节点上运行以下命令：

```sh
$ docker swarm join-token manager
To add a manager to this swarm, run the following command:

    docker swarm join \
    --token SWMTKN-1-61ztec5kyafptydic6jfc1i33t37flcl4nuipzcusor96k7kby-5vy9t8u35tuqm7vh67lrz9xp6 \
    192.168.99.100:2377
```

在**准**管理节点的输出的运行命令以加入集群：

```sh
$ docker swarm join \
  --token SWMTKN-1-61ztec5kyafptydic6jfc1i33t37flcl4nuipzcusor96k7kby-5vy9t8u35tuqm7vh67lrz9xp6 \
  192.168.99.100:2377

This node joined a swarm as a manager.
```

# 管理群中的节点

节点的管理作为集群管理生命周期的一部分，需要掌握：列出群中的节点、检查单个节点、更新节点、离开集群。

## 列出节点
`docker node ls`从管理节点查看集群中的节点列表：

```sh
$ docker node ls
ID                            HOSTNAME            STATUS              AVAILABILITY        MANAGER STATUS      ENGINE VERSION
4ukl6wl714uljl43m51zji80f *   manager1            Ready               Active              Leader              18.03.1-ce
rp87bhtw4qmtg9i3k4o53b4xi     worker1             Ready               Active                                  18.03.1-ce
occde76c7oiv93zhds0x8ij5u     worker2             Ready               Active                                  18.03.1-ce
```

`AVAILABILITY`列显示调度程序是否可以将任务分配给节点：

- `Active` 意味着调度程序**可以**将任务分配给节点。
- `Pause` 意味着调度程序**不会**将新任务分配给节点，但**现有任务仍在运行**。
- `Drain`意味着调度程序**不会**将新任务分配给节点。调度程序**关闭所有现有任务**并在可用节点上调度它们。

`MANAGER STATUS`列显示节点参与Raft共识：

- `没有值`表示不参与集群管理的**工作节点**。
- `Leader` 意味着节点是为集群进行所有集群管理和编排决策的主要**管理节点**。
- `Reachable`意味着该节点是**参与Raft共识**法定人数的**管理节点**。如果**领导者节点变得不可用，该节点有资格被选为新领导者**。
- `Unavailable`意味着节点是一个**不能与其他管理沟通**的管理。如果管理节点变得不可用，则应该将新管理节点加入到集群中，或者将**工作节点提升为管理节点**。

有关集群管理的更多信息，请参阅[集群管理指南](https://docs.docker.com/engine/swarm/admin_guide/)。

## 检查单个节点

可以在管理节点上运行`docker node inspect <NODE-ID>`以查看单个节点的详细信息。输出默认为JSON格式，但可以传递该`--pretty`标记以便以可读格式打印结果。例如：

```sh
$ docker service inspect --pretty helloworld

ID:             qkexf88msvohybd6pico0t4g0
Name:           helloworld
Service Mode:   Replicated
 Replicas:      1
Placement:
UpdateConfig:
 Parallelism:   1
 On failure:    pause
 Monitoring Period: 5s
 Max failure ratio: 0
 Update order:      stop-first
RollbackConfig:
 Parallelism:   1
 On failure:    pause
 Monitoring Period: 5s
 Max failure ratio: 0
 Rollback order:    stop-first
ContainerSpec:
 Image:         alpine:latest@sha256:7df6db5aa61ae9480f52f0b3a06a140ab98d427f86d8d5de0bedab9b8df6b1c0
 Args:          ping baidu.com
Resources:
Endpoint Mode:  vip
```

## 更新节点

可以修改节点属性，如下所示：

- [更改节点可用性](https://docs.docker.com/engine/swarm/manage-nodes/#change-node-availability)
- [添加或删除标签元数据](https://docs.docker.com/engine/swarm/manage-nodes/#add-or-remove-label-metadata)
- [更改节点角色](https://docs.docker.com/engine/swarm/manage-nodes/#promote-or-demote-a-node)

### 更改节点可用性
---
更改节点可用性：

- `drain`  耗尽**管理器节点**，以便**仅**执行**集群管理**任务并且**不**可用于**任务分配**。
- `drain`  排空一个**节点**，这样你就可以把它**拿下来进行维护**。
- `pause`  暂停一个节点，以便它**不**能接**收新的任务**。
- `active` 恢复**不可用或暂停**的节点可用状态。

例如，要将管理节点更改为`Drain`可用性：

```sh
$ docker node update --availability drain manager-1
node-1
```

### 添加或删除标签元数据
---
节点标签提供了一种灵活的**组织节点方法**。也可以在服务**约束**中使用节点标签。创建服务时应用约束，以**限制**调度程序为服务分配任务的节点。

`docker node update --label-add`在管理节点上运行以将标签元数据添加到节点。`--label-add`选项支持`<key>`或`<key>=<value>` 。为要添加的每个节点标签传递一次`--label-add`选项：

```sh
$ docker node update --label-add foo --label-add bar=baz node-1
node-1
```

使用docker节点更新设置的标签仅适用于**集群内的节点**。不要将它们与[dockerd的docker](https://docs.docker.com/engine/userguide/labels-custom-metadata/#daemon-labels)守护进程标签 [混淆](https://docs.docker.com/engine/userguide/labels-custom-metadata/#daemon-labels)。因此，可以使用节点标签将**关键任务限制为满足特定要求的节点**。例如，仅在需要运行特殊工作负载的机器上进行调度，例如符合[PCI-SS合规性的机器](https://www.pcisecuritystandards.org/)。受影响的工作节点无法损拖累这类特殊工作负载，因为它被约束，且无法更改节点标签。

然而，**引擎标签**仍然很有用，因为一些不影响容器安全编排的功能可能更好地分散方式设置。例如，引擎可以有一个标签来表明它具有某种类型的磁盘设备，这可能与安全性无关。这些标签更容易被swarm协调器“信任”。

### 升级或降级节点
---
可以将工作节点提升为经理角色。**当管理节点变得不可用或者想让管理节点进行维护**时，这非常有用。同样，可以将管理节点降级为辅助角色。

> **注意**：无论提升或降级节点的理由如何，都必须始终维护集群中的管理节点的法定人数。

要提升一个节点或一组节点，请在管理器节点运行`docker node promote`：

```sh
$ docker node promote node-3 node-2
Node node-3 promoted to a manager in the swarm.
Node node-2 promoted to a manager in the swarm.
```

要降级一个节点或一组节点，请从管理器节点运行`docker node demote`：

```sh
$ docker node demote node-3 node-2

Manager node-3 demoted in the swarm.
Manager node-2 demoted in the swarm.
```

`docker node promote`和`docker node demote`是为了方便的命令 `docker node update --role manager`和`docker node update --role worker` 。

## 在集群节点上安装插件

> **仅限Edge**：此选项仅在Docker CE Edge版本中可用。请参阅[Docker CE Edge](https://docs.docker.com/edge/)。

如果swarm服务依赖于一个或多个 [插件](https://docs.docker.com/engine/extend/plugin_api/)，则这些插件需要在可能部署服务的每个节点上可用。可以在每个节点上**手动安装插件或编写安装脚本**。在Docker 17.07及更高版本中，也可以使用Docker API以类似于**全局服务的方式部署插件**，只需指定一个`PluginSpec`而不是 `ContainerSpec`。

> **注意**：目前没有办法使用Docker CLI或Docker Compose将插件部署到swarm。另外，从私有存储库安装插件是不可能的。

[`PluginSpec`](https://docs.docker.com/engine/extend/plugin_api/#json-specification) 是由插件开发人员定义的。要将插件添加到所有Docker节点，请使用[`service/create`](https://docs.docker.com/engine/api/v1.31/#operation/ServiceCreate)API，并传递在`TaskTemplate`中定义的`PluginSpec` JSON 。

## 离开集群

在节点上运行命令`docker swarm leave`将其从集群中删除。

```sh
$ docker swarm leave
Node left the swarm.
```

当一个节点离开集群时，Docker引擎**停止以集群模式**运行。Orchestrator不再将任务安排到节点。

如果节点是**管理节点**，则会收到有关维护**法定人数**的警告。要覆盖警告，请传递`--force`选项。如果**最后一个管理器节点离开**集群，则集群变得**不可用**，要求您采取灾难恢复措施。

有关维护仲裁和灾难恢复的信息，请参阅 [Swarm管理指南](https://docs.docker.com/engine/swarm/admin_guide/)。

节点离开集群后，可以在管理器节点上运行命令`docker node rm`以从节点列表中删除该节点。例如：

```sh
$ docker node rm node-2
```

# 将服务部署到集群

Swarm服务使用**声明性**模型，这意味着您可以定义所需的**服务状态**，并依靠Docker来维护此状态。状态包括诸如（但不限于）的信息：

- 服务容器应该运行的镜像名称和标记
- 有多少个容器参与服务
- 是否有任何端口暴露给集群外的客户
- 当Docker启动时服务是否应该自动启动
- 服务重新启动时发生的特定行为（例如是否使用滚动重启）
- 服务可以运行的节点的特性（例如资源约束和布局偏好）

## 创建一个服务

要创建**没有额外配置的单副本服务**，只需提供镜像名称即可。命令启动一个带有**随机生成名称**并且**没有发布端口**的Nginx服务。

```sh
$ docker service create nginx
```

该服务安排在可用节点上。要确认服务已成功创建并启动，请使用以下`docker service ls`命令：

```sh
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE                                                                                             PORTS
a3iixnklxuem        quizzical_lamarr    replicated          1/1                 docker.io/library/nginx@sha256:41ad9967ea448d7c2b203c699b429abe1ed5af331cd92533900c6d77490e0268
```

创建的服务并不总是立即运行。如果服务的镜像不可用，如果没有节点满足您为服务配置的要求或其他原因，服务可能处于**挂起状态**。

要为服务提供名称，请使用以下`--name`选项：

```sh
$ docker service create --name my_web nginx
```

就像使用独立容器一样，可以通过在镜像名称后面添加它来指定服务容器应该**运行的命令**。此示例启动一个名为`helloworld`使用`alpine`镜像并运行以下命令的服务`ping docker.com`：

```sh
$ docker service create --name helloworld alpine ping docker.com
```

也可以指定要使用的服务的镜像标签。这个例子修改了前一个使用`alpine:3.6`标签：

```sh
$ docker service create --name helloworld alpine:3.6 ping docker.com
```

### 使用私人注册表中的镜像创建服务
---
如果镜像在需要登录的私人注册表中可用，请在登录后使用 `--with-registry-auth`选项。如果镜像存储在`registry.example.com`私有注册表中，请使用类似以下的命令：

```sh
$ docker login registry.example.com

$ docker service  create \
  --with-registry-auth \
  --name my_service \
  registry.example.com/acme/my_image:latest
```

这使用加密的WAL日志将**登录令牌**从本地客户端**传递到部署服务的集群节点**。有了这些信息，这些节点就能够登录到注册表并提取镜像。

## 更新服务

可以使用`docker service update`命令更改现有服务 。当**更新服务时**，Docker会**停止**容器并使用新配置**重启**它们。

由于Nginx是一个Web服务，如果将端口80发布到集群外的客户端，它会更好。可以在创建服务时使用`-p`或`--publish`选项来指定。**更新**现有服务时，选项是`--publish-add`。还有一个`--publish-rm`选项可以**删除**以前发布的端口。

假设`my_web`来自上一节的服务仍然存在，请使用以下命令将更新为发布端口80。

```sh
$ docker service update --publish-add 80 my_web
```

要验证它是否有效，请使用`docker service ls`：

```sh
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE                                                                                             PORTS
4nhxl7oxw5vz        my_web              replicated          1/1                 docker.io/library/nginx@sha256:41ad9967ea448d7c2b203c699b429abe1ed5af331cd92533900c6d77490e0268   *:0->80/tcp
```

可以更新有关现有服务的几乎每个配置详细信息，包括其运行的镜像名称和标记。请参阅 [创建后更新服务的镜像](https://docs.docker.com/engine/swarm/services/#update-a-services-image-after-creation)。

## 删除服务

要删除服务，请使用`docker service remove`命令。可以通过ID或名称来删除服务，如`docker service ls` 命令的输出中所示。以下命令将删除该`my_web`服务。

```sh
$ docker service rm my_web
$ docker service rm 4nhxl7oxw5vz
$ docker service rm 4nhxl7oxw5vz my_web2
```

## 服务配置细节

以下各节提供有关服务配置的详细信息。在几乎所有可以在服务创建时定义配置的情况下，也可以用类似的方式更新现有服务的配置。

### 配置运行时环境
---
可以在**容器中为运行时环境**配置以下选项：

- 使用`--env`选项的**环境变量**
- 使用`--workdir`选项的容器内的**工作目录**
- 使用`--user`选项的**用户名或UID**

以下服务的容器的环境变量`$MYVAR` 设置为`myvalue`，在`/tmp/`目录运行，并以`my_user`用户身份运行 。

```sh
$ docker service create --name helloworld \
  --env MYVAR=myvalue \
  --workdir /tmp \
  --user my_user \
  alpine ping docker.com
```

### 更新已有服务
---
更新现有服务运行的命令，可以使用`--args`选项。下面的示例更新一个已调用的现有服务`helloworld`，以便它运行命令`ping docker.com`而不是之前运行的任何命令：

```sh
$ docker service update --args "ping docker.com" helloworld
```

### 指定服务使用的镜像版本
---
当**创建**服务时**未指定**要使用的**镜像版本**的任何详细信息时，该服务将**使用`latest`标签**的版本。可以**强制**服务以几种不同的方式**使用特定**版本的镜像，具体取决于您想要的结果。

镜像版本可以用几种不同的方式：

- 如果指定了一个标签，那么管理器（或Docker客户端，如果使用 [内容信任](https://docs.docker.com/engine/swarm/services/#image_resolution_with_trust)）将该**标签解析为摘要**。当在工作节点上接收到创建容器任务的请求时，工作节点只会看到**摘要，而不是标签**。

  ```sh
  $ docker service create --name="myservice" ubuntu:16.04
  ```

  一些标签代表迭代的版本，例如`ubuntu:16.04`。像这样的标签几乎总是会随着时间的推移逐渐成为稳定的版本， **建议尽可能使用这种固定版本的标签**。

  其他类型的标签（如`latest`或`nightly`）可能经常会解析为新的版本，具体取决于镜像作者更新标签的频率。**建议不要使用经常更新的标签**来运行服务，以防止**使用不同镜像版本**的不同服务副本任务。

- 如果**完全不指定版本**，则按照惯例，镜像的`latest`标记将被解析为摘要。创建服务任务时，工作人员使用此摘要中的镜像。因此，以下两个命令是相同的：

  ```sh
  $ docker service create --name="myservice" ubuntu
  $ docker service create --name="myservice" ubuntu:latest
  ```

- 如果**直接指定版本和摘要**，则在创建服务任务时始终**使用**镜像的**确切**版本。

  ```sh
  $ docker service create \
      --name="myservice" \
      ubuntu:16.04@sha256:35bc48a1ca97c3971611dc4662d08d131869daa692acb281c7e9e052924e38b1
  ```

当创建服务时，镜像的标记将被解析为标记在创建服务时指向的**特定版本摘要**。服务的工作节点永远使用**特定版本**的摘要，除非服务被更新。如果使用经常更改的标签（例如`latest`），则此功能尤其重要，因为它可**确保**所有服务任务使用**相同版本的镜像**。

> **注意**：如果启用了[内容信任](https://docs.docker.com/engine/security/trust/content_trust/)，客户端实际上会在联系swarm管理器之前将镜像的标签解析为摘要，以验证镜像是否已签名。因此，如果使用内容信任，swarm管理器会收到预先解决的请求。在这种情况下，如果客户端无法将镜像解析为摘要，则请求失败。

如果**管理器无法将标签解析为摘要，则每个工作节点负责将标签解析为摘要**，并且**不同节点可以使用不同版本的镜像**。如果发生这种情况，会输出下面的警告，用占位符代替真实信息。

```sh
unable to pin image <IMAGE-NAME> to digest: <REASON>
```

要**查看镜像的当前摘要**，请执行命令 `docker inspect <IMAGE>:<TAG>`并查找`RepoDigests`行。以下是`ubuntu:latest`此内容写入时的当前摘要。为了清晰起见，输出被截断。

```sh
$ docker inspect ubuntu:latest
"RepoDigests": [
    "ubuntu@sha256:35bc48a1ca97c3971611dc4662d08d131869daa692acb281c7e9e052924e38b1"
],
```

创建服务之后，除非明确`docker service update`使用`--image`选项运行，否则其**镜像不会更新** 。其他更新操作（如扩展服务，添加或删除网络或卷，重命名服务或任何其他类型的更新操作）不会更新服务的镜像。

### 更新服务的镜像
---
每个标签代表一个摘要，类似于Git哈希。一些标签，如 `latest`更新通常指向一个新的摘要。比如`ubuntu:16.04`，代表一个已发布的软件版本，并且预计不会更新以经常指向新的摘要。在Docker 1.13及更高版本中，当创建服务时，它将被限制为使用镜像的**特定摘要创建任务**，直到**使用**`service update` `--image`选项更新服务为止。如果使用较**旧版本的Docker Engine，则必须删除并重新创建**服务以更新其镜像。

当`service update`使用`--image`选项运行时，swarm管理器会查询Docker Hub或您的私人Docker注册中心以获取**标签记当前指向的摘要**并**更新服务任务**使用新摘要。

> **注意**：如果使用[内容信任](https://docs.docker.com/engine/swarm/services/#image_resolution_with_trust)，Docker客户端解析镜像，swarm管理器接收镜像和摘要，而不是标签。

通常，**管理节点可以将标签解析为新的摘要和服务**更新，**重新部署每个任务以使用新镜像**。如果管理器无法解决标签或发生其他问题，将会发生以下情况：

#### 如果管理器成功解析标签

如果swarm manager可以将image标签解析为摘要，它会**指示工作节点重新部署任务并使用新摘要中的镜像**。

- 如果工作人员在摘要中**缓存**了镜像，则会使用缓存的镜像。
- 如果不是，它会尝试从Docker Hub或私有注册表中**提取**镜像。
  - 如果**成功**，则使用新镜像**部署相关任务**。
  - 如果工作节点**无法拉取**镜像，则服务**无法**在工作人员节点上**部署**。Docker**再次尝试**部署任务，可能**在不同**的工作节点上。

#### 如果管理器无法解析标签

如果swarm manager无法将镜像解析为摘要，则全部不会丢失：

- 管理员指示工作节点**使用该标签**处的镜像**重新**部署任务。
- 如果工作人员**拥有**解析为标记的**本地缓存镜像**，则它会**使用该镜像**。
- 如果工作人员**没有解析**为标签的本地高速缓存镜像，则工作人员会尝试连接到Docker Hub或私有注册表以在该标签处**拉取镜像**。
  - 如果这**成功**了，工作人员将**使用该镜像**。
  - 如果**失败**，该任务将**无法部署**，并且管理员**再次尝试**部署该任务，可能位于**不同**的工作节点上。

## 发布端口

在创建集群服务时，可以通过两种方式将服务的端口发布到集群外的主机：

- [可以依靠路由网格](https://docs.docker.com/engine/swarm/services/#publish-a%20services-ports-using-the-routing-mesh)。当发布服务端口时，无论在节点上运行的服务是否有任务，集群都可以**在每个节点上的目标端口上访问该服务**。这并不复杂，是许多类型服务都是这种方式。
- [可以直接在](https://docs.docker.com/engine/swarm/services/#publish-a-services-ports-directly-on-the-swarm-node) 运行服务[的集群节点上发布服务任务的端口](https://docs.docker.com/engine/swarm/services/#publish-a-services-ports-directly-on-the-swarm-node)。此功能在Docker 1.13和更高版本中可用。这**绕过了路由网格**，并提供了最大的灵活性，包括**开发自己的路由框架**的能力。但是，有责任跟踪每个任务的运行位置，并将请求路由到任务，并在各个节点之间进行负载平衡。

### 使用路由网格发布服务的端口
---
要从外部向群发布服务的端口，请使用 `--publish <PUBLISHED-PORT>:<SERVICE-PORT>`选项。集群使服务可以在**每个集群节点**的发布端口**上**访问。如果外部主机连接到任何集群节点上的该端口，则路由网格会将其**路由到任务**。外部主机不需要知道**服务任务的IP地址**或内部使用**端口**就可以与服务交互。当用户或进程连接到服务时，任何运行服务任务的工作节点都可能会响应。有关集群服务网络的更多详细信息，请参阅 [管理集群服务网络](https://docs.docker.com/engine/swarm/networking/)。

#### 示例：在10个节点群上运行三任务Nginx服务

假设有一个10节点的集群，并且部署了一个在10节点集群上运行三个任务的Nginx服务：

```sh
$ docker service create \
	--name my_web \
	--replicas 3 \
	--publish published=8080,target=80 \
nginx
```

三个任务在最多三个节点上运行。不需要知道哪些节点正在运行任务; 在10个节点中的**任何**节点上连接到8080端口都可以将连接到三个`nginx`任务之一。你可以使用测试`curl`。以下示例假定这`localhost`是集群节点之一。如果情况并非如此，或者`localhost`无法解析到主机上的IP地址，请使用主机的IP地址或可解析的主机名称。

HTML输出被截断：

```sh
$ curl localhost:8080

<!DOCTYPE html>
<html>
<head>
<title>Welcome to nginx!</title>
...truncated...
</html>
```

后续连接可能会**路由**到同一个集群节点或不同的节点。

### 直接在集群节点上发布服务的端口
---
如果需要根据**应用程序状态**做出路由决策，或者需要**完全控制将请求路由到服务任务**的流程，则使用路由网格可能不是应用程序的正确选择。要直接在**正在运行的节点上**发布服务端口，请使用标 志 `--publish` 选项`mode=host`。

> **注意：**如果使用`mode = host`直接在集群节点上发布服务的端口，并设置`published = <PORT>`，则会创建隐式限制，只能在**给定集群节点上为服务运行一个任务**。可以通过指定发布而不使用端口定义来解决此问题，这会导致Docker为每个任务**分配一个随机**端口。
>
> 另外，如果使用`mode = host`，并且在`docker service create`上不使用`--mode = global`选项，则**很难知道哪些节点正在运行**服务以将工作路由到它们。

#### 示例：`nginx`在每个集群节点上运行Web服务

[nginx](https://hub.docker.com/_/nginx/)是一个开源的反向代理，负载均衡器，HTTP缓存和一个Web服务器。如果使用路由网格将nginx作为服务运行，则连接到任何swarm节点上的nginx端口将显示（有效）运行该服务**的随机集群节点**的网页。

以下示例在集群中的每个节点上运行nginx作为服务，并在每个集群节点上本地公开nginx端口。

```sh
$ docker service create \
  --mode global \
  --publish mode=host,target=80,published=8080 \
  --name=nginx \
  nginx:latest
```

可以在每个集群节点的端口8080上访问nginx服务器。如果向集群添加节点，则会启动一个nginx任务。不能在任何绑定到端口8080的集群节点上启动另一个服务或容器。

> **注意**：这是一个极端的例子。为多层服务创建应用程序层路由框架非常复杂，超出了本主题的范围。

## 将服务连接到覆盖网络

可以使用覆盖网络连接群中的一个或多个服务。

首先，使用`docker network create` 带有`--driver overlay`选项的命令在**管理器节点**上创建覆盖网络。

```sh
$ docker network create --driver overlay my-network
```

在集群模式下创建覆盖网络后，**所有管理节点都可以访问网络**。可以创建新服务并传递该`--network`选项以将**服务附加到覆盖网络**：

```sh
$ docker service create \
  --replicas 3 \
  --network my-network \
  --name my-web \
  nginx
```

集群扩展`my-network`到运行服务的每个节点。

还可以使用`--network-add`选项**将现有服务连接到覆盖网络** 。

```sh
$ docker service update --network-add my-network my-web
```

要**断开**正在运行的服务与网络的连接，请使用`--network-rm`选项。

```sh
$ docker service update --network-rm my-network my-web
```

有关覆盖网络和服务发现的更多信息，请参阅 [将服务附加到覆盖网络](https://docs.docker.com/engine/swarm/networking/)和 [Docker集群模式覆盖网络安全模型](https://docs.docker.com/engine/userguide/networking/overlay-security-model/)。

## 授予对secret的服务访问权限


要创建一个访问Docker管理的secret的服务，请使用`--secret` 选项。有关更多信息，请参阅 [管理Docker服务的敏感字符串（secret）](https://docs.docker.com/engine/swarm/secrets/)

## 自定义服务的隔离模式


Docker 17.12 CE和更高版本允许指定集群服务的隔离模式。**设置仅适用于Windows主机，Linux主机将忽略此设置。**隔离模式可以是以下之一：

- `default`：使用由`-exec-opt`选项或`exec-opts`阵列所配置的默认隔离模式为Docker主机配置`daemon.json`。如果守护进程未指定隔离技术，`process`则它是Windows Server `hyperv`的默认设置，并且是Windows 10的默认（且唯一）选择。

- `process`：将服务任务作为主机上的单独进程运行。

  > **注意**：`process`隔离模式仅在Windows Server上受支持。Windows 10仅支持`hyperv`隔离模式。

- `hyperv`：将服务任务作为独立的`hyperv`任务运行。这增加了开销但提供了更多的隔离。

可以在使用该`--isolation`选项创建或更新新服务时指定隔离模式。

## 控制服务分布


Swarm服务为提供了几种不同的方式来**控制不同节点上服务的规模和位置**。

- 可以指定服务是否需要运行**特定数量的副本**，还是应该在每个工作节点上**全局运行**。请参阅 [复制或全局服务](https://docs.docker.com/engine/swarm/services/#replicated-or-global-services)。

- 可以配置服务的 [CPU或内存要求](https://docs.docker.com/engine/swarm/services/#reserve-memory-or-cpus-for-a-service)，并且服务**仅在满足**这些要求的节点上运行。

- [分布约束](https://docs.docker.com/engine/swarm/services/#placement-constraints)使可以将服务配置为**仅在具有特定（任意）元数据**集的节点上运行，并且如果适当的节点**不存在**，则会**导致部署失败**。例如，可以指定服务只应在任意标签`pci_compliant`设置为的节点上运行 `true`。

- [“分布位置”偏好设置](https://docs.docker.com/engine/swarm/services/#placement-preferences)允许每个节点应用一系列值的**任意标签**，并使用**算法**将服务的任务分散到这些节点上。目前，唯一支持的算法是`spread`尝试将它们**均匀**地分布。例如，如果`rack`使用值为1-10的标签为每个节点添加标签，则指定一个位置偏好设置`rack`，然后`rack`在采用其他**放置约束**后，服务任务尽可能均匀地分布在**具有标签**的所有节点上，放置偏好以及其他节点**特定**的限制。

  与约束不同，分布选项是**尽力而为**的，并且如果**没有节点能够满足偏好**，则服务**不会失败**部署。如果指定服务的分布选项，那么当集群管理决定哪些节点应该运行服务任务时，与该选项匹配的节点**排名较高**。其他因素（如服务的高可用性）还会考虑将哪些节点安排为运行服务任务。例如，如果有`N`个节点具有标签（以及其他一些节点），并且服务配置为运行`N + 1`个副本，则会在尚未拥有该服务的节点上调度`+1`有一个，不管该节点是否有`rack`标签。

### 副本服务或全局服务
---
Swarm模式有两种类型的服务：副本和全局。对于副本服务，指定swarm管理器调度到可用节点的**副本任务数**。对于全局服务，调度程序在**每个可用节点上放置一个任务**，以满足服务的 [分布约束](https://docs.docker.com/engine/swarm/services/#placement-constraints)和 [资源需求](https://docs.docker.com/engine/swarm/services/#reserve-cpu-or-memory-for-a-service)。

可以使用`--mode`选项来控制服务的类型。如果未指定模式，则服务默认为`replicated`。对于**副本服务**，可以指定要使用`--replicas`选项开始的**副本任务数**。例如，要使用3个副本任务启动复制的nginx服务：

```sh
$ docker service create \
  --name my_web \
  --replicas 3 \
  nginx
```

要在每个可用节点上启动**全局服务**，请传递`--mode global`给 `docker service create`。每当**新节点变为可用**时，调度程序就将全局服务的任务**放置在新节点**上。例如，要开始在群中**每个节点**上运行`alpine`的服务：

```sh
$ docker service create \
  --name myservice \
  --mode global \
  alpine top
```

通过服务约束，可以在调度程序将服务部署到节点之前设置节点的条件。可以根据**节点属性**和**元数据**或**引擎元数据**将约束应用于服务。

### 为服务预留内存或CPU
---
要为服务保留给定数量的**内存或CPU**数量，请使用 `--reserve-memory`或`--reserve-cpu`选项。如果**没有**可用的节点能够满足要求（例如，如果请求4个CPU并且群中没有节点具有4个CPU），则服务保持**挂起**状态，**直到有合适**的节点可用于运行其任务。

### 内存异常（OOME）
---
如果服务尝试使用比swarm节点**更多的内存**，则可能会遇到**内存异常**（OOME），并且容器或Docker守护进程可能会被**内核OOM杀手所杀**。要防止发生这种情况，请确保应用程序在具有**足够内存**的主机上运行，并且请参阅 [了解耗尽内存的风险](https://docs.docker.com/engine/admin/resource_constraints/#understand-the-risks-of-running-out-of-memory)。

Swarm服务允许使用资源约束，分布选项和标签来确保将服务部署到适当的集群节点。

### 分布约束
---
**使用布局约束来控制服务可以分配给的节点**。在以下示例中，服务仅在[标签](https://docs.docker.com/engine/swarm/engine/swarm/manage-nodes/#add-or-remove-label-metadata) `region`设置为的节点上运行 `east`。如果**没有适当标签**的节点可用，则**部署失败**。`--constraint`选项使用相等运算符（`==`或`!=`）。对于**副本服务，有可能所有服务在同一节点上运行，或者每个节点只运行一个副本，或者某些节点不运行任何副本**。对于**全局服务，服务在满足布局约束和任何[资源需求的](https://docs.docker.com/engine/swarm/services/#reserve-cpu-or-memory-for-a-service)每个节点上**运行 。

```sh
$ docker service create \
  --name my-nginx \
  --replicas 5 \
  --constraint region==east \
  nginx
```

也可以`constraint`在`docker-compose.yml` 文件中使用服务级别。

如果指定了多个分布位置约束，则服务**只会部署到满足**它们的节点上。以下示例限制服务在所有`region`设置为`east`并且`type`未设置为的节点上运行`devel`：

```sh
$ docker service create \
  --name my-nginx \
  --global \
  --constraint region==east \
  --constraint type!=devel \
  nginx
```

还可以将布局约束与布局偏好和CPU/内存约束结合使用。小心不要使用不可能实现的设置。

### 分布偏好设置
---
尽管[分布约束](https://docs.docker.com/engine/swarm/services/#placement-constraints)限制了服务可以运行的节点，但**分布偏好**尝试以算法的方式将服务放置在**适当偏好的节点**上（目前只能**均匀分布**）。例如，如果每个节点分配一个`rack`标签，则可以设置一个放置选项，以便按照`rack`值通过标签均匀分布服务。这样，如果丢失了`rack`，该服务仍在其他`rack`上的节点上运行。

分布偏好设置没有严格执行。如果没有节点具有选项中指定的标签，则会像部署首选项那样部署该服务。

> 注意：**全局服务会忽略分布位置偏好设置**。

以下示例设置了一个选项，以根据`datacenter`标签的值在节点之间分布部署。如果有一些节点`datacenter=us-east`和其他节点有 `datacenter=us-west`，则服务在两组节点间**尽可能均匀**地部署。

```sh
$ docker service create \
  --replicas 9 \
  --name redis_2 \
  --placement-pref 'spread=node.labels.datacenter' \
  redis:3.0.6
```

> **缺少标签或空标签**<br/>缺少用于传播的标签的节点仍然接收任务分配。作为一个组，这些节点接收任何与由特定标签值标识的其他组等比例的任务。从某种意义上说，一个缺失的标签与附加了一个空值的标签相同。如果服务**只**应在标签用于扩展偏好的节点上运行，则偏好应与约束组合。

可以指定**多个分布偏好设置**，并按照遇到的顺序处理它们。以下示例使用多个分布位置选项设置服务。任务首先在各个`datacenter `上传播，然后在`rack`上传播（如各个标签所示）：

```sh
$ docker service create \
  --replicas 9 \
  --name redis_2 \
  --placement-pref 'spread=node.labels.datacenter' \
  --placement-pref 'spread=node.labels.rack' \
  redis:3.0.6
```

还可以将**分布选项与分布约束或CPU/内存约束**结合使用。小心不要使用不可能实现的设置。

此图说明了分布展示位置偏好的工作原理

![放置偏好示例](https://docs.docker.com/engine/swarm/images/placement_prefs.png)

在`docker service update`更新服务时，`--placement-pref-add` 在所有现有展示位置偏好设置之后追加新的展示位置偏好设置。 `--placement-pref-rm`删除与参数匹配的现有展示位置偏好设置。

## 配置服务的更新行为

在创建服务时，可以指定**滚动更新**行为，以便在运行时集群应如何将更改应用于`docker service update`服务。也可以将这些选项指定为更新的一部分，作为`docker service update`参数 。

`--update-delay`选项配置**更新服务任务或多组任务之间的时间延迟**。可以将时间描述为`T`，秒数`Ts`，分钟数`Tm`或小时数的组合`Th`。因此`10m30s`表示延迟10分30秒。

默认情况下，调度程序**一次更新1个**任务。可以通过 `--update-parallelism`选项来配置调度程序**同时**更新的**最大**服务任务数。

当对单个任务的更新返回状态时`RUNNING`，调度程序通过**继续**执行另一个任务来继续更新，直到更新**所有**任务。如果在任务更新期间的任何时间`FAILED`，调度程序会暂停更新。可以使用`docker service create`或`docker service update`的 `--update-failure-action` 选项来控制行为。

在下面的示例服务中，调度程序一次**最多应用2个副本**。当更新的任务返回`RUNNING`或者时`FAILED`，调度程序在**停止*下一个任务更新之前等待10秒钟：

```sh
$ docker service create \
  --replicas 10 \
  --name my_web \
  --update-delay 10s \
  --update-parallelism 2 \
  --update-failure-action continue \
  alpine
```

`--update-max-failure-ratio`选项控制在更新之前更新的整个过程中可能失败的部分任务可能失败。例如，使用`--update-max-failure-ratio 0.1 --update-failure-action`暂停，**10％的任务更新失败后，更新将暂停**。

如果任务未启动，或者在`--update-monitor`选项指定的**监视时间段内停止**运行，则认为单个任务**更新失败**。`--update-monitor`的默认值为`30秒`，这意味着任务在其开始后的**前30秒内**失败，将计入服务**更新失败阈值**，并且**在此之后的失败将不计入**。

## 回滚服务

如果`docker service update`更新版本的服务没有按预期运行，可以使用`--rollback`选项手动回滚到服务的先前版本。这会将服务恢复到最近`docker service update`命令之前的配置 。

其他选项可以结合使用`--rollback`。 例如， `--update-delay 0s`在任务之间没有延迟地执行回滚：

```sh
$ docker service update \
  --rollback \
  --update-delay 0s
  my_web
```

在Docker 17.04及更高版本中，如果服务更新未能部署，可以将服务配置为**自动回滚**。与新的自动回滚功能相关，在Docker 17.04及更高版本中，如果守护程序运行Docker 17.04或更高版本，**手动回滚**将在服务器端而不是客户端进行处理。允许**手动启动的回滚**来遵守新的回滚参数。客户端是版本感知的，所以它仍然使用旧的守护进程的方法。

最后，在Docker 17.04及更高版本中，`--rollback`不能与其他选项一起使用`docker service update`。

## 更新失败，自动回滚

可以通过以下方式来配置服务：如果对服务的**更新**导致**重新部署**失败，则服务可以**自动回滚**到以前的配置。这有助于保护服务**可用性**。可以在创建或更新服务时设置以下一个或多个选项。如果您未设置值，则使用默认值。

| 选项                           | 默认    | 描述                                                         |
| ------------------------------ | ------- | ------------------------------------------------------------ |
| `--rollback-delay`             | `0s`    | 在**回滚下一个任务**之前回滚任务之后要**等待的时间**。`0`在第一个回滚任务部署完成后**立即回滚**第二个任务的方法值。 |
| `--rollback-failure-action`    | `pause` | 当任务无法回滚时，无论是要`pause`还是`continue`试图**回滚其他**任务。 |
| `--rollback-max-failure-ratio` | `0`     | 在回滚期间**容忍的故障**率，指定为介于0和1之间的浮点数。例如，给定5个任务，故障率`.2`会容忍一个任务无法回滚。值`0`没有故障被容忍，而值`1`装置的任何数量的故障容忍。 |
| `--rollback-monitor`           | `5s`    | 每个任务回滚之后的**持续时间监视失败**。如果任务在**此时间段过去之前停止**，则认为**回滚失败**。 |
| `--rollback-parallelism`       | `1`     | **并行回滚的最大任务数**。默认情况下，一次回滚一个任务。一个值将`0`导致所有任务并行回滚。 |

以下示例将配置`redis`服务`docker service update`在部署失败时自动回滚。**两个任务**可以**并行**回滚。任务在回滚后**监视20秒**，以确保它们不会退出，并且**最大失败率为20％**是可以接受的。默认值用于`--rollback-delay`和`--rollback-failure-action`。

```sh
$ docker service create --name=my_redis \
                        --replicas=5 \
                        --rollback-parallelism=2 \
                        --rollback-monitor=20s \
                        --rollback-max-failure-ratio=.2 \
                        redis:latest
```

## 服务访问`卷或挂载`

为了获得**最佳性能和可移植性**，应避免将**重要数据直接写入容器的可写层**，而应使用**数据卷或绑定挂载**。这一原则也适用于服务。

可以为集群中的服务创建两种类型的挂载，`volume`挂载或 `bind`挂载。无论使用哪种类型的挂载，在创建服务时使用选项`--mount`进行配置 ，或者 在更新现有服务时使用`--mount-add`或 `--mount-rm`选项进行配置。如果未指定类型，则默认值为`volume`。

### 数据卷
---
数据卷`volume`是**独立于容器**而存在的存储。集群服务下的数据卷的**生命周期与容器下的相似**。卷超过任务和服务，因此必须**单独管理**它们的删除。卷可以在**部署服务之前**创建，或者如果在某个特定主机上不存在任何特定主机时，它们将根据服务上的卷规范**自动创建**。

要将现有数据卷用于服务，请使用以下`--mount`选项：

```sh
$ docker service create \
  --mount src=<VOLUME-NAME>,dst=<CONTAINER-PATH> \
  --name myservice \
  <IMAGE>
```

如果`<VOLUME-NAME>`任务安排到特定主机时，具有相同的卷不存在，则会创建一个。默认的`volume`驱动程序是`local`。要按需创建模式下使用不同的卷驱动程序，请使用以下`--mount`选项**指定驱动程序**及其选项：

```sh
$ docker service create \
  --mount type=volume,src=<VOLUME-NAME>,dst=<CONTAINER-PATH>,volume-driver=<DRIVER>,volume-opt=<KEY0>=<VALUE0>,volume-opt=<KEY1>=<VALUE1>
  --name myservice \
  <IMAGE>
```

### 绑定挂载
---
绑定挂载是调度程序为任务部署容器的主机的文件系统路径。Docker将路径安装到容器中。文件系统路径必须在swarm为任务初始化容器之前存在。

以下示例显示了绑定挂载语法：

- 要挂载读写绑定：

  ```sh
  $ docker service create \
    --mount type=bind,src=<HOST-PATH>,dst=<CONTAINER-PATH> \
    --name myservice \
    <IMAGE>
  ```

- 要挂载一个只读绑定：

  ```sh
  $ docker service create \
    --mount type=bind,src=<HOST-PATH>,dst=<CONTAINER-PATH>,readonly \
    --name myservice \
    <IMAGE>
  ```

> **重要提示**：绑定挂载可能很有用，但它们也可能导致问题。在大多数情况下，建议构建应用程序，以便不需要从主机安装路径。主要风险包括以下几点：
>
> - 如果将主机路径绑定到服务的容器中，则**路径必须存在于每个集群节点上**。Docker群模式调度程序可以在满足资源可用性要求的任何机器上调度容器，并满足指定的所有约束和分布偏好。
> - 如果Docker群模式调度程序变得不健康或无法访问，Docker群模式调度程序可能会随时**重新安排**正在运行的服务容器。
> - 主机绑定挂载是**不可移植**的。当使用绑定挂载时，不保证应用程序在开发中的运行方式与生产中的相同。

## 使用模板创建服务

可以使用`service create`Go的[文本/模板](http://golang.org/pkg/text/template/) 软件包提供的语法来为某些选项使用[模板](http://golang.org/pkg/text/template/)。

支持以下选项：

- `--hostname`
- `--mount`
- `--env`

Go模板的有效占位符是：

| 占位符            | 描述     |
| ----------------- | -------- |
| `.Service.ID`     | 服务ID   |
| `.Service.Name`   | 服务名称 |
| `.Service.Labels` | 服务标签 |
| `.Node.ID`        | 节点ID   |
| `.Task.Name`      | 任务名称 |
| `.Task.Slot`      | 任务槽   |

### 模板示例
---
本示例根据服务的名称和容器运行节点的ID来设置创建的容器的模板：

```sh
$ docker service create --name hosttempl \
                        --hostname="{{.Node.ID}}-{{.Service.Name}}"\
                         busybox top
```

要查看使用模板的结果，请使用`docker service ps`和 `docker inspect`命令。

```sh
$ docker service ps va8ew30grofhjoychbr6iot8c
ID            NAME         IMAGE                                                                                   NODE          DESIRED STATE  CURRENT STATE               ERROR  PORTS
wo41w8hg8qan  hosttempl.1  busybox:latest@sha256:29f5d56d12684887bdfa50dcd29fc31eea4aaf4ad3bec43daf19026a7ce69912  2e7a8a9c4da2  Running        Running about a minute ago
$ docker inspect --format="{{.Config.Hostname}}" hosttempl.1.wo41w8hg8qanxwjwsg4kxpprj
```

# docker config 基本命令

```sh
$ docker config -h
Usage:  docker config COMMAND

管理 docker 配置

Commands:
  create      # 从文件或STDIN创建配置
  inspect     # 显示一个或多个配置的详细信息
  ls          # 配置列表
  rm          # 删除一个或多个配置
```
## create 创建

从文件或STDIN创建配置

### 命令参数选项

---

| 选项，简写          | 默认 | 描述     |
| ------------------- | ---- | -------- |
| `--label , -l`      |      | 配置标签 |
| `--template-driver` |      | 模板驱动 |

### 示例

---

```sh
# docker config create [OPTIONS] CONFIG file|-

# 创建一个my-config 的配置文件
$ echo "This is a config" | docker config create my-config -
```

## inspect 查看

显示一个或多个配置的详细信息

 ### 命令参数选项

---

| 选项，简写      | 默认 | 描述                       |
| --------------- | ---- | -------------------------- |
| `--format , -f` |      | 使用给定的Go模板格式化输出 |
| `--pretty`      |      | 以人性化的格式打印信息     |

### 示例

---

```sh
$ docker config inspect my-config
[
    {
        "ID": "te2r2q67yipn0o5tesavytn3n",
        "Version": {
            "Index": 2971
        },
        "CreatedAt": "2018-05-10T09:26:46.485305805Z",
        "UpdatedAt": "2018-05-10T09:26:46.485305805Z",
        "Spec": {
            "Name": "my-config",
            "Labels": {},
            "Data": "VGhpcyBpcyBhIGNvbmZpZwo="
        }
    }
]
```

## ls 列表

查看配置文件列表

```sh
$ docker config ls
ID                          NAME                CREATED             UPDATED
te2r2q67yipn0o5tesavytn3n   my-config           30 seconds ago      30 seconds ago
```

## rm 删除

删除一个或多个配置

 ```sh
$ docker config rm my-config
 ```

# 使用 config 存储数据

Docker 17.06引入了swarm服务配置，它允许在服务镜像外部或运行容器中存储**非敏感信息**，例如**配置文件**。这允许保持镜像尽可能**通用**，而无需将**配置文件绑定到容器或使用环境变量**。

Config以类似于[secret的](https://docs.docker.com/engine/swarm/secrets/)方式运行，不同之处在于它们没有在`rest`时加密，并且不使用RAM和磁盘直接安装到**容器**的文件系统中。**随时可以从服务添加或删除**配置，并且服务可以**共享配置**。甚至可以将配置与环境变量或标签结合使用，以获得最大的灵活性。配置值可以是通用字符串或二进制内容（最大可达`500 kb`）。

> **注意**：Docker**配置仅适用于集群**服务，而**不适用于独立容器**。要使用此功能，请考虑将容器作为1级服务运行。

**Windows支持**

Docker 17.06和更高版本包括对Windows容器配置的支持。在实现中存在差异的地方，它们在下面的例子中被调用。牢记以下显着差异：

- 自定义目标的配置文件不直接绑定到Windows容器中，因为Windows不支持非目录文件绑定挂载。相反，容器的配置都被装入 `C:\ProgramData\Docker\internal\configs`容器内的（应用程序不应该依赖的实现细节）。符号链接用于指向容器内配置的所需目标。默认目标是`C:\ProgramData\Docker\configs`。
- 创建使用Windows容器的服务时，配置不支持指定UID，GID和模式的选项。配置目前只能由具有`system`容器访问权限的管理员和用户访问。

## 如何管理 config

当配置添加到swarm中时，Docker会通过**相互TLS连接**将**配置发送到swarm管理器**。配置存储在**加密的Raft日志**中。整个Raft日志被**复制**到其他管理器中，确保配置的**高可用性**保证与其他群管理数据相同。

当授予新创建或正在运行的服务对配置的访问权时，**配置将作为文件装载**到容器中。容器中安装点在Linux容器中的位置默认为`/<config-name>`。在Windows容器中，配置都被装入`C:\ProgramData\Docker\configs`，**软链接被创建到所需的位置**，默认为 `C:\<config-name>`。

可以使用**数字ID或用户或组**的名称来设置**所有权（`uid`和`gid`）或配置**。还可以指定**文件权限（`mode`）**。对于Windows容器，这些设置将被忽略。

- 如果未设置，则配置由**用户拥有**，并且运行容器命令（通常`root`）以及该用户的默认组（通常也是`root`）。
- 如果未设置，则配置具有**全局可读的权限**（模式`0444`），除非在容器中设置了`umask` ，在这种情况下，该模式受该`umask`值影响。

可以**随时更新*服务以授予其访问其他配置或**撤销**对给定配置的**访问权限**。

如果节点是群管理器，或者它**正在运行已被授权**访问配置的服务任务，则节点只能访问配置。当容器**任务停止**运行时，共享给它的配置将从该**容器的内存中文件系统卸载**，并从**节点的内存中清除**。

如果节点在运行可访问配置的任务容器时**失去与集群的连接**，则**任务容器仍可访问其配置**，但在节点重新连接到集群之前**无法接收更新**。<br/>可以**随时添加或检查**单个配置，或列出所有配置。**无法删除正在运行的服务正在使用的配置**。请参阅[旋转配置，](https://docs.docker.com/engine/swarm/configs/#example-rotate-a-config)以便在**不中断正在运行**的服务的情况下**移除**配置。

要更容易地**更新或回滚**配置，请考虑在配置名称中**添加版本号或日期**。通过控制给定容器内配置的**挂载点**，这变得更容易。

要更新堆栈，请更改compose文件，然后重新运行`docker stack deploy -c <new-compose-file> <stack-name>`。如果在该文件中使用新的配置，服务将开始使用它们。请记住，**配置是不可变的**，所以无法更改现有服务的文件。相反，**创建一个新配置**以使用不同的文件。<br/>可以运行`docker stack rm`以**停止应用程序并取下堆栈**。这将删除`docker stack deploy`使用相同堆栈名称创建的任何**配置**。这将删除**所有**配置，包括那些未被服务引用的配置以及在`docker service update --config-rm`之后剩下的配置。

## 实例演示

### 开始使用 config

---

这个简单的例子显示了配置如何在几个命令中工作。

1. 添加一个配置到Docker。`docker config create`命令读取标准输入，因为最后一个参数表示要读取配置文件的文件被设置为`-`。

   ```sh
   $ echo "This is a config" | docker config create my-config -
   ```

2. 创建一个`redis`服务并授予它对配置的访问权限。默认情况下，容器可以访问配置`/my-config`，但可以使用该`target`选项自定义容器上的文件名。

   ```sh
   $ docker service create --name redis --config my-config redis:alpine
   ```

3. 验证任务是否正在运行，没有问题`docker service ps`。如果一切正常，输出结果如下所示：

   ```sh
   $ docker service ps redis
   ID                  NAME                IMAGE               NODE                DESIRED STATE       CURRENT STATE            ERROR               PORTS
   xdhqto5td9jk        redis.1             redis:latest        manager1            Running             Running 55 seconds ago 
   ```

4. `docker ps`获取`redis`服务任务容器的标识，以便可以使用`docker container exec`它连接到容器并读取config数据文件的内容，该数据文件默认为全部可读，并且具有与config的名称相同的名称。下面的第一条命令说明了如何找到容器ID，第二个和第三个命令使用shell完成来自动执行此操作。

   ```sh
   $ docker ps --filter name=redis -q
   5cb1c2348a59
   
   # ssh 连接到manager1
   $ docker-machine.exe ssh manager1
   $ docker container exec $(docker ps --filter name=redis -q) ls -l /my-config
   -r--r--r--    1 root     root            12 Jun  5 20:49 my-config                                                     
   $ docker container exec $(docker ps --filter name=redis -q) cat /my-config
   This is a config
   ```

5. 尝试删除配置。删除失败，因为`redis`服务**正在运行**并可以访问配置。

   ```sh
   $ docker config ls
   ID                          NAME                CREATED             UPDATED
   fzwcfuqjkvo5foqu7ts7ls578   hello               31 minutes ago      31 minutes ago
   
   $ docker config rm my-config
   Error response from daemon: rpc error: code = 3 desc = config 'my-config' is
   in use by the following service: redis
   ```

6. `redis`通过更新服务，从正在运行的服务中删除对配置的访问。

   ```sh
   $ docker service update --config-rm my-config redis
   ```

7. 重复步骤3和4，验证该服务不再有权访问配置。容器ID不同，因为该 `service update`命令重新部署服务。

   ```sh
   $ docker container exec -it $(docker ps --filter name=redis -q) cat /my-config
   cat: can't open '/my-config': No such file or directory
   ```

8. 停止并删除服务，并从Docker中删除配置。

   ```sh
   $ docker service rm redis
   $ docker config rm my-config
   ```

### 在 Windows 中使用 config

---

这是一个非常简单的示例，它显示了如何使用Microsoft Windows Server 2016上的Docker 17.06 EE或Windows上的Docker 17.06 CE上运行的Microsoft IIS服务的配置。它将网页存储在配置中。

此示例假定您已安装PowerShell。

1. 将以下内容保存到一个新文件中`index.html`。

   ```html
   <html>
     <head><title>Hello Docker</title></head>
     <body>
       <p>Hello Docker! You have deployed a HTML page.</p>
     </body>
   </html>
   ```

2. 如果还没有加入集群，请初始化或加入集群。

   ```sh
   $ docker swarm init
   ```

3. 将`index.html`文件保存为名为`homepage`的集群配置。

   ```sh
   $ docker config create homepage index.html
   ```

4. 创建一个IIS服务并授予它对`homepage`配置的访问权限。

   ```sh
   $ docker service create \
       --name my-iis \
       --publish published=8000,target=8000 \
       --config src=homepage,target="\inetpub\wwwroot\index.html" \
       microsoft/iis:nanoserver
   ```

5. 访问IIS服务`http://localhost:8000/`。它应该从第一步开始提供HTML内容。

   ```sh
   $ docker service ps my-iis
   $ docker-machine ip manager1
   
   $ curl http://$(docker-machine ip manager1):8080
   ```

6. 删除服务和配置。

   ```sh
   $ docker service rm my-iis
   $ docker config rm homepage
   ```

### 使用配置与Nginx服务

---

这个例子分为两部分。 [第一部分](https://docs.docker.com/engine/swarm/configs/#generate-the-site-certificate)是关于生成站点证书，并不直接涉及Docker配置，但是它建立[了第二部分](https://docs.docker.com/engine/swarm/configs/#configure-the-nginx-container)的基础，在存储和使用站点证书作为一系列secret，并将Nginx配置作为配置使用。该示例显示如何在配置上设置选项，例如容器中的目标位置和文件权限（`mode`）。

#### 生成站点证书

为您的站点生成根CA和TLS证书和密钥。对于生产站点，您可能希望使用服务`Let’s Encrypt`来生成TLS证书和密钥，但此示例使用命令行工具。这一步有点复杂，但仅仅是一个设置步骤，以便您可以将某些内容存储为Dockersecret。如果你想跳过这些子步骤，您可以[使用我们的加密](https://letsencrypt.org/getting-started/)生成网站密钥和证书，命名文件`site.key`和 `site.crt`，然后跳到 [配置Nginx的容器](https://docs.docker.com/engine/swarm/configs/#configure-the-nginx-container)。

1. 生成一个根密钥。

   ```sh
   $ openssl genrsa -out "root-ca.key" 4096
   ```

2. 使用根密钥生成CSR。

   ```sh
   $ openssl req \
             -new -key "root-ca.key" \
             -out "root-ca.csr" \
             -sha256
             #-subj '/C=CN/ST=SC/L=GZ/O=org/OU=unit/CN=docker/emailAddress=docker@docker.io'
   ```

3. 配置根CA。编辑一个名为的新文件`root-ca.cnf`并将以下内容粘贴到其中。这限制了根CA只签署叶证书而不是中间CA。

   ```properties
   [root_ca]
   basicConstraints = critical,CA:TRUE,pathlen:1
   keyUsage = critical, nonRepudiation, cRLSign, keyCertSign
   subjectKeyIdentifier=hash
   ```

4. 签署证书。

   ```sh
   $ openssl x509 -req -days 3650 -in "root-ca.csr" \
                  -signkey "root-ca.key" -sha256 -out "root-ca.crt" \
                  -extfile "root-ca.cnf" -extensions \
                  root_ca
   ```

5. 生成站点密钥。

   ```sh
   $ openssl genrsa -out "site.key" 4096
   ```

6. 生成站点证书并使用站点密钥对其进行签名。

   ```sh
   $ openssl req -new -key "site.key" -out "site.csr" -sha256
   ```

7. 配置站点证书。编辑一个名为的新文件`site.cnf`并将以下内容粘贴到其中。这限制了站点证书，因此它只能用于对服务器进行身份验证，并且不能用于签名证书。

   ```sh
   [server]
   authorityKeyIdentifier=keyid,issuer
   basicConstraints = critical,CA:FALSE
   extendedKeyUsage=serverAuth
   keyUsage = critical, digitalSignature, keyEncipherment
   subjectAltName = DNS:localhost, IP:192.168.99.106
   subjectKeyIdentifier=hash
   ```

8. 签署网站证书。

   ```sh
   $ openssl x509 -req -days 750 -in "site.csr" -sha256 \
       -CA "root-ca.crt" -CAkey "root-ca.key" -CAcreateserial \
       -out "site.crt" -extfile "site.cnf" -extensions server
   ```

9. 在`site.csr`和`site.cnf`文件不需要由Nginx的服务，但你需要他们，如果你想生成一个新的站点证书。保护`root-ca.key`文件。

#### 配置NGINX容器

1. 生成一个非常基本的Nginx配置，通过HTTPS提供静态文件。TLS证书和密钥作为Dockersecret存储，以便它们可以轻松旋转。

   在当前目录中，`site.conf`使用以下内容创建一个新文件：

   ```nginx
   server {
       listen                443 ssl;
       server_name           192.168.99.106;
       ssl_certificate       /run/secrets/site.crt;
       ssl_certificate_key   /run/secrets/site.key;
   
       location / {
           root   /usr/share/nginx/html;
           index  index.html index.htm;
       }
   }
   ```

2. 创建两个secret，代表密钥和证书。只要小于500 KB，您就可以将任何文件存储为secret文件。这使您可以将密钥和证书与使用它们的服务分离。在这些示例中，secret名称和文件名是相同的。

   ```sh
   $ docker secret create site.key site.key
   $ docker secret create site.crt site.crt
   ```

3. 将`site.conf`文件保存在Docker配置中。第一个参数是配置的名称，第二个参数是要从中读取的文件。

   ```sh
   $ docker config create site.conf site.conf
   ```

   列出配置：

   ```sh
   $ docker config ls
   ID                          NAME                CREATED             UPDATED
   4ory233120ccg7biwvy11gl5z   site.conf           4 seconds ago       4 seconds ago
   ```

4. 创建一个运行Nginx并可以访问两个secret和配置的服务。将模式设置为`0440`使文件只能由其所有者和该所有者的组读取，而不是所有人。

   ```sh
   $ docker service create \
        --name nginx \
        --secret site.key \
        --secret site.crt \
        --config source=site.conf,target=/etc/nginx/conf.d/site.conf,mode=0440 \
        --publish published=3000,target=443 \
        nginx:latest \
        sh -c "exec nginx -g 'daemon off;'"
   ```

   在正在运行的容器中，现在存在以下三个文件：

   - `/run/secrets/site.key`
   - `/run/secrets/site.crt`
   - `/etc/nginx/conf.d/site.conf`

5. 验证Nginx服务正在运行。

   ```sh
   $ docker service ls
   ID            NAME   MODE        REPLICAS  IMAGE
   zeskcec62q24  nginx  replicated  1/1       nginx:latest
   
   $ docker service ps nginx
   NAME                  IMAGE         NODE  DESIRED STATE  CURRENT STATE          ERROR  PORTS
   nginx.1.9ls3yo9ugcls  nginx:latest  moby  Running        Running 3 minutes ago
   ```

6. 验证服务是否可操作：您可以访问Nginx服务器，并且正在使用正确的TLS证书。

   ```sh
   $ curl --cacert root-ca.crt https:// 192.168.99.106:3000
   
   $ openssl s_client -connect  192.168.99.106:3000 -CAfile root-ca.crt
   ```

7. 除非你打算继续下一个例子，否则在运行这个例子之后，通过删除`nginx`服务和存储的secret和配置来清理。

   ```sh
   $ docker service rm nginx
   $ docker secret rm site.crt site.key
   $ docker config rm site.conf
   ```

现在配置了一个Nginx服务，其配置与其镜像分离。您可以使用完全相同的镜像运行多个站点，但可以单独配置，而无需构建自定义镜像。

#### 旋转配置

要旋转配置，你首先保存一个与当前正在使用的名称不同的新配置。然后重新部署服务，删除旧配置并在容器中的相同安装点添加新配置。此示例通过旋转`site.conf` 配置文件构建在前一个示例上。

1. 在`site.conf`本地编辑文件。添加`index.php`到该`index`行，并保存该文件。

   ```nginx
   server {
       listen                443 ssl;
       server_name           localhost;
       ssl_certificate       /run/secrets/site.crt;
       ssl_certificate_key   /run/secrets/site.key;
   
       location / {
           root   /usr/share/nginx/html;
           index  index.html index.htm index.php;
       }
   }
   ```

2. 使用新的`site.conf`叫做的新建一个Docker配置`site-v2.conf`。

   ```sh
   $ docker config create site-v2.conf site.conf
   ```

3. 更新`nginx`服务以使用新配置而不是旧配置。

   ```sh
   $ docker service update \
     --config-rm site.conf \
     --config-add source=site-v2.conf,target=/etc/nginx/conf.d/site.conf,mode=0440 \
     nginx
   ```

4. 验证`nginx`服务是否完全重新部署，使用 `docker service ls nginx`。当它是，你可以删除旧的`site.conf` 配置。

   ```sh
   $ docker config rm site.conf
   ```

5. 为了清理，你可以删除`nginx`服务，以及secret和配置。

   ```sh
   $ docker service rm nginx
   $ docker secret rm site.crt site.key
   $ docker config rm site-v2.conf
   ```

现在已经更新了`nginx`服务的配置，而无需重新构建其镜像。

# docker secret 基本命令

```sh
$ docker secret -h
Usage:  docker secret COMMAND

管理敏感数据

Commands:
  create      # 创建secret
  inspect     # 显示secret
  ls          # secret列表
  rm          # 删除secret
```

## create 创建

使用标准输入或secret内容的文件创建一个secret。

### 命令参数选项

---

| 选项，简写          | 默认 | 描述                                                         |
| ------------------- | ---- | ------------------------------------------------------------ |
| `--driver , -d`     |      | [API 1.37+](https://docs.docker.com/engine/api/v1.37/) secret驱动程序 |
| `--label , -l`      |      | secret标签                                                   |
| `--template-driver` |      | 模板驱动                                                     |

 ### 示例

---

#### 创建secret

```sh
$ echo <secret> | docker secret create my_secret -
onakdyv307se2tl7nl20anokv

$ docker secret ls
ID                          NAME                CREATED             UPDATED
onakdyv307se2tl7nl20anokv   my_secret           6 seconds ago       6 seconds ago
```

#### 用文件创建secret

```sh
$ docker secret create my_secret ./secret.json
dg426haahpi5ezmkkj5kyl3sn

$ docker secret ls
ID                          NAME                CREATED             UPDATED
dg426haahpi5ezmkkj5kyl3sn   my_secret           7 seconds ago       7 seconds ago
```

#### 用标签创建secret

```sh
$ docker secret create --label env=dev \
                       --label rev=20170324 \
                       my_secret ./secret.json
eo7jnzguqgtpdah3cm5srfb97

$ docker secret inspect my_secret
```

## inspect 查看

查看指定的secret。该命令必须在管理器节点上运行。默认情况下，这会将所有结果呈现在JSON数组中。如果指定了格式，则将为每个结果执行给定的模板。Go的[文本/模板](http://golang.org/pkg/text/template/)包描述了格式的所有细节。

```sh
$ docker secret inspect my_secret3
[
    {
        "ID": "xpo8llaj0j6wvqgmt6kmenbl6",
        "Version": {
            "Index": 19132
        },
        "CreatedAt": "2018-05-11T09:51:17.127938107Z",
        "UpdatedAt": "2018-05-11T09:51:17.127938107Z",
        "Spec": {
            "Name": "my_secret3",
            "Labels": {
                "env": "dev",
                "rev": "20170324"
            }
        }
    }
]
```

## ls 列表

### 过滤

---

过滤选项（`-f`或`--filter`）格式是一`key=value`对。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- id（secretID）
- label（`label=<key>`或`label=<key>=<value>`）
- name（名字）

```sh
# 匹配一个secret的id
$ docker secret ls -f "id=6697bflskwj1998km1gnnjr38"
# 带有project标签的secret与其值进行匹配
$ docker secret ls --filter label=project
# 匹配project具有project=test值的标签
$ docker service ls --filter label=project=test
# 包含前缀的名称相匹配test
$ docker secret ls --filter name=test_secret
```

### 格式化输出

---

格式化选项（`--format`）可以使用Go模板打印secret输出。下面列出了Go模板的有效占位符：

| 占位符       | 描述                                                         |
| ------------ | ------------------------------------------------------------ |
| `.ID`        | secretID                                                     |
| `.Name`      | secret名称                                                   |
| `.CreatedAt` | secret被创建的时间                                           |
| `.UpdatedAt` | secret更新的时间                                             |
| `.Labels`    | 分配给secret的所有标签                                       |
| `.Label`     | 这个secret的特定标签的价值。例如`{{.Label "secret.ssh.key"}}` |

当使用该`--format`选项时，`secret ls`命令将完全按照模板声明输出数据，或者在使用该 `table`指令时也会包含列标题。

以下示例使用不带标题的模板，并输出 由冒号分隔的所有镜像`ID`和`Name`条目：

```sh
$ docker secret ls --format "{{.ID}}: {{.Name}}"
```

要以表格格式列出所有secret名称和创建日期，可以使用：  

```sh
$ docker secret ls --format "table {{.ID}}\t{{.Name}}\t{{.CreatedAt}}"
```

## rm 删除

从群中删除指定的secret。该命令必须在管理器节点上运行。

```sh
$ docker secret rm secret.json
```

# 管理 secret 敏感数据

就Docker Swarm服务而言，**secret**是一组数据，如密码，SSH私钥，SSL证书或另一部分数据，这些数据**不应通过网络传输**或在Dockerfile或应用程序中**未加密存储源代码**。在Docker 1.13及更高版本中，可以使用Docker **secret**来集中管理这些数据，并将其安全地传输给需要访问的那些容器。在运输过程中**密码被加密**，并在Docker群中休息。给定的**secret**只能被那些被**授予明确访问权限**的服务访问，并且只有在这些服务任务**正在运行**时才能访问。

可以使用secret来管理容器在运行时需要的任何敏感数据，但不想将它存储在镜像或源代码管理中，下面的情况适合：

- 用户名和密码
- TLS证书和密钥
- SSH密钥
- 其他重要数据，如数据库或内部服务器的名称
- 通用字符串或二进制内容（最大为500 kb）

> **注意**：Dockersecret**仅适用于集群**服务，而**不适用于独立容器**。要使用此功能，请考虑**将容器作为服务**运行。有状态的容器通常可以在不更改容器代码的情况下以1个实例运行。

另一个使用secret的用例是在容器和一组证书之间提供一个**抽象层**。考虑一个场景，可以为应用程序分别开发，测试和生产环境。这些环境中的每一个都可以拥有不同的凭证，并以相同的secret名称存储在开发，测试和生产群中。容器只需要知道在所有三种环境中运行的secret的名称。

还可以使用secret来管理**非敏感数据**，例如配置文件。但是，Docker 17.06和更高版本支持使用[configs](https://docs.docker.com/engine/swarm/configs/) 来存储非敏感数据。配置直接安装到容器的**文件系统**中，而不使用RAM磁盘。

## 如何管理 secret

当为swarm添加secret时，Docker会通过相互**TLS连接**将密钥发送给swarm管理器。secret存储在**加密的Raft日志**中。**整个Raft日志被复制**到其他管理节点中，确保与其他群管理数据相同的高可用性保证。

> **警告**：Raft数据在Docker 1.13和更高版本中被**加密**。如果任何Swarm管理者运行早期版本，并且其中一位经理成为群组的管理者，则secret将在节点的Raft日志中**未加密存储**。在添加任何secret之前，**将所有管理器节点更新到Docker 1.13或更高版本**，以**防止将secret写入纯文本**的Raft日志。

当授予新创建或正在运行的服务对secret的访问权限时，解密的secret将被装入容器中的**内存中文件**系统。容器中安装点的位置默认为 `/run/secrets/<secret_name>`在Linux容器或 `C:\ProgramData\Docker\secrets`Windows容器中。可以在Docker 17.06和更高版本中指定自定义位置。

可以更新服务，授权其访问其他secret或**随时撤销对指定secret的访问权限**。

如果节点是群管理器或者它正在运行已**被授权访问secret的服务**任务，那么节点**只能访问（加密的）secret**。当容器任务停止运行时，共享给它的*解密secret**将从该容器的内存中文件系统**卸载**，并从节点的内存**刷新*。<br/>如果节点在运行可访问secret的任务容器时失去与集群的连接，则任务容器仍可访问其secret，但在节点重新连接集群之前无法接收更新。

可以随时**添加或检查**个人secret，或列出所有secret。**无法删除正在运行**的服务正在使用的secret。请参阅[旋转secret](https://docs.docker.com/engine/swarm/secrets/#example-rotate-a-secret)以在不中断正在运行的服务的情况下移除secret。<br/>要更容易地更新或回滚secret，请考虑在secret名称中添加**版本号或日期**。通过控制给定容器内**secret的安装点**的能力使这变得更容易。

## 实例演示

### 开始使用 secret

---

这个简单的例子展示了secret如何在几个命令中工作。对于真实世界的例子，继续到 [中级例子：使用Nginx服务的secret](https://docs.docker.com/engine/swarm/secrets/#intermediate-example-use-secrets-with-a-nginx-service)。

1. 给Docker添加一个secret。`docker secret create`命令读取标准输入，因为最后一个参数表示要读取密钥的文件设置为`-`。

   ```sh
   $ printf "This is a secret" | docker secret create my_secret_data -
   ```

2. 创建一个`redis`服务并授予它访问secret的权限。默认情况下，容器可以访问secret`/run/secrets/<secret_name>`，但可以使用`target`选项自定义容器上的文件名。

   ```sh
   $ docker service  create --name redis --secret my_secret_data redis:alpine
   ```

3. 验证任务是否正在运行，没有问题`docker service ps`。如果一切正常，输出结果如下所示：

   ```sh
   $ docker service ps redis
   ID            NAME     IMAGE         NODE              DESIRED STATE  CURRENT STATE          ERROR  PORTS
   bkna6bpn8r1a  redis.1  redis:alpine  ip-172-31-46-109  Running        Running 8 seconds ago  
   ```

   如果出现错误，并且任务失败并反复重新启动，则会看到如下所示的内容：

   ```sh
   $ docker service ps redis
   NAME                      IMAGE         NODE  DESIRED STATE  CURRENT STATE          ERROR                      PORTS
   redis.1.siftice35gla      redis:alpine  moby  Running        Running 4 seconds ago                             
    \_ redis.1.whum5b7gu13e  redis:alpine  moby  Shutdown       Failed 20 seconds ago      "task: non-zero exit (1)"  
    \_ redis.1.2s6yorvd9zow  redis:alpine  moby  Shutdown       Failed 56 seconds ago      "task: non-zero exit (1)"  
    \_ redis.1.ulfzrcyaf6pg  redis:alpine  moby  Shutdown       Failed about a minute ago  "task: non-zero exit (1)"  
    \_ redis.1.wrny5v4xyps6  redis:alpine  moby  Shutdown       Failed 2 minutes ago       "task: non-zero exit (1)"
   ```

4. 获取`redis`使用的服务任务容器的ID `docker ps`，以便您可以使用`docker container exec`连接到容器并读取secret数据文件的内容，该内容默认为全部可读，并且与secret的名称相同。下面的第一条命令说明了如何找到容器ID，第二个和第三个命令使用shell完成来自动执行此操作。

   ```sh
   $ docker-machine ssh manager1
   
   $ docker ps --filter name=redis -q
   5cb1c2348a59
   
   $ docker container exec $(docker ps --filter name=redis -q) ls -l /run/secrets
   total 4
   -r--r--r--    1 root     root            17 Dec 13 22:48 my_secret_data
   
   $ docker container exec $(docker ps --filter name=redis -q) cat /run/secrets/my_secret_data
   This is a secret
   ```

5. 如果提交容器，secret**不可**用。

   ```sh
   $ docker commit $(docker ps --filter name=redis -q) committed_redis
   
   $ docker run --rm -it committed_redis cat /run/secrets/my_secret_data
   cat: can't open '/run/secrets/my_secret_data': No such file or directory
   ```

6. 尝试删除secret。删除失败，因为该`redis`服务正在运行并可以访问该secret。

   ```sh
   $ docker secret ls
   ID                          NAME                CREATED             UPDATED
   wwwrxza8sxy025bas86593fqs   my_secret_data      4 hours ago         4 hours ago
   
   $ docker secret rm my_secret_data
   Error response from daemon: rpc error: code = 3 desc = secret
   'my_secret_data' is in use by the following service: redis
   ```

7. `redis`通过更新服务，从正在运行的服务中移除对secret的访问权限。

   ```
   $ docker service update --secret-rm my_secret_data redis
   ```

8. 重复步骤3和4，验证该服务不再有权访问该secret。容器ID不同，因为该 `service update`命令重新部署服务。

   ```sh
   $ docker container exec -it $(docker ps --filter name=redis -q) cat /run/secrets/my_secret_data
   
   cat: can't open '/run/secrets/my_secret_data': No such file or directory
   ```

9. 停止并删除服务，并从Docker中删除密钥。

   ```sh
   $ docker service rm redis
   $ docker secret rm my_secret_data
   ```

### 使用 secret 的 WordPress 服务

---

使用自定义root密码创建单节点MySQL服务，将凭证添加为secret，并创建使用这些凭证连接到MySQL的单节点WordPress服务。在 [下面的例子](https://docs.docker.com/engine/swarm/secrets/#example-rotate-a-secret)建立在这一个，并告诉如何旋转MySQL的密码和更新服务，使WordPress的服务仍然可以连接到MySQL。

此示例说明了一些使用Docker secret的技巧，以**避免将敏感凭证保存在镜像中或直接在命令行上**传递。

> **注意**：为简单起见，此示例使用单引擎群，并使用单节点MySQL服务，因为单个MySQL服务器实例无法通过简单地使用复制服务来扩展，并且设置MySQL集群超出了本示例的范围。<br/>另外，更改MySQL密码并不像更改磁盘上的文件那么简单。必须使用查询或`mysqladmin`命令来更改MySQL中的密码。

1. 为MySQL生成一个**随机的字母**数字密码，并`mysql_password`使用该`docker secret create` 命令将其作为Docker secret存储。要使密码更短或更长，请调整`openssl`命令的最后一个参数。这只是创建相对随secret码的一种方式。如果选择可以使用其他命令来生成密码。

   > **注意**：**创建secret后，无法更新它。只能删除并重新创建它**，并且无法删除服务正在使用的secret。但是，可以使用**授予或撤销正在运行的服务**对secret的访问权限`docker service update`。如果需要更新密码的功能，请考虑在密码名称中添加一个版本组件，以便稍后添加新版本，更新服务以使用它，然后删除旧版本。

   最后一个参数设置为`-`，表示输入是从标准输入读取的。运行下面命令后将返回的值不是密码，而是密码的ID。

   ```sh
   $ openssl rand -base64 20 | docker secret create mysql_password -
   l1vinzevzhj4goakjap5ya409
   ```

   为MySQL `root`用户生成第二个secret。这个secret不会与稍后创建的WordPress服务共享。它只需要引导`mysql`服务。

   ```sh
   $ openssl rand -base64 20 | docker secret create mysql_root_password -
   ```

   列出由Docker管理的secret`docker secret ls`：

   ```sh
   $ docker secret ls
   ID                          NAME                  CREATED             UPDATED
   l1vinzevzhj4goakjap5ya409   mysql_password        41 seconds ago      41 seconds ago
   yvsczlx9votfw3l0nz5rlidig   mysql_root_password   12 seconds ago      12 seconds ago
   ```

   secret存储在加密的Raft日志中。

2. 创建用于MySQL和WordPress服务之间通信的用户定义覆盖网络。不需要将MySQL服务公开给任何外部主机或容器。

   ```sh
   $ docker network create -d overlay mysql_net
   ```

3. 创建MySQL服务，MySQL服务具有以下特征：

   - 由于**副本比例设置为`1`**，所以只有一个MySQL任务运行。

   - **只能**由`mysql_net`网络上的其他容器访问。

   - 使用**卷`mydata`存储MySQL数据**，以便在重新启动`mysql`服务时**保持不变**。

   - secret分别安装在`tmpfs`文件系统的`/run/secrets/mysql_password`和`/run/secrets/mysql_root_password`。它们从不公开为环境变量，如果运行`docker commit`命令，它们也**不会被提交到镜像**。`mysql_password`密码是非特权WordPress容器连接到MySQL所使用的密码。

   - 将环境变量`MYSQL_PASSWORD_FILE`和`MYSQL_ROOT_PASSWORD_FILE`设置为指向`/run/secrets/mysql_password`和`/run/secrets/mysql_root_password`。**第一次初始化系统数据库时，`mysql`镜像从这些文件中读取密码字符串**。之后，**密码存储在`MySQL`系统数据库**自身中。

   - 设置环境变量`MYSQL_USER`和`MYSQL_DATABASE`。当容器启动时，会创建一个名为`wordpress`的新数据库，并且`wordpress`用户**仅对此数据库**拥有完全权限。该用户**不能创建或删除**数据库或**更改MySQL配置**。

     ```sh
     $ docker service create \
          --name mysql \
          --replicas 1 \
          --network mysql_net \
          --mount type=volume,source=mydata,destination=/var/lib/mysql \
          --secret source=mysql_root_password,target=mysql_root_password \
          --secret source=mysql_password,target=mysql_password \
          -e MYSQL_ROOT_PASSWORD_FILE="/run/secrets/mysql_root_password" \
          -e MYSQL_PASSWORD_FILE="/run/secrets/mysql_password" \
          -e MYSQL_USER="wordpress" \
          -e MYSQL_DATABASE="wordpress" \
          mysql:latest
     ```

4. 验证`mysql`容器是否正在使用该`docker service ls`命令运行。

   ```sh
   $ docker service ls
   ID            NAME   MODE        REPLICAS  IMAGE
   wvnh0siktqr3  mysql  replicated  1/1       mysql:latest
   ```

   此时，可以实际撤消`mysql`服务对密码`mysql_password`和`mysql_root_password`secret的访问权限， 因为密码已保存在MySQL系统数据库中。现在不要这样做，因为我们稍后使用它们来方便旋转MySQL密码。

5. 现在MySQL已经建立，创建一个连接到MySQL服务的WordPress服务。WordPress服务具有以下特点：

   - 由于**副本设置为`1`**，所以只有一个WordPress任务运行。由于将WordPress会话数据存储在容器文件系统上的限制，因此负载均衡WordPress作为练习留给读者。
   - 在主机的**端口30000**上显示WordPress，以便可以从**外部主机访问**它。如果没有在主机的端口80上运行Web服务器，则可以公开端口80。
   - 连接到`mysql_net`网络，以便它**可以与`mysql`容器通信 **，并在所有集群节点上**发布端口80到端口30000**。
   - **有权**访问`mysql_password`密码，但在容器中指定不同的目标文件名称。WordPress容器使用安装点`/run/secrets/wp_db_password`。还通过将模式设置为，指定secret不是群组或外界可读的 `0400`。
   - 将环境变量设置`WORDPRESS_DB_PASSWORD_FILE`为安装密钥的文件路径。WordPress服务从该文件**读取MySQL密码**字符串并将其**添加到`wp-config.php` 配置**文件中。
   - 使用用户名`wordpress`和密码连接到MySQL容器，`/run/secrets/wp_db_password`并创建`wordpress` 数据库（如果它尚不存在）。
   - 将其数据（如主题和插件）存储在一个名为`wpdata` 的卷中，以便在重新启动服务时保持这些文件。

   ```sh
   $ docker service create \
        --name wordpress \
        --replicas 1 \
        --network mysql_net \
        --publish published=30000,target=80 \
        --mount type=volume,source=wpdata,destination=/var/www/html \
        --secret source=mysql_password,target=wp_db_password,mode=0400 \
        -e WORDPRESS_DB_USER="wordpress" \
        -e WORDPRESS_DB_PASSWORD_FILE="/run/secrets/wp_db_password" \
        -e WORDPRESS_DB_HOST="mysql:3306" \
        -e WORDPRESS_DB_NAME="wordpress" \
        wordpress:latest
   ```

6. 验证服务正在使用`docker service ls`和 `docker service ps`命令运行。

   ```sh
   $ docker service ls
   ID            NAME       MODE        REPLICAS  IMAGE
   wvnh0siktqr3  mysql      replicated  1/1       mysql:latest
   nzt5xzae4n62  wordpress  replicated  1/1       wordpress:latest
   ```

   ```sh
   $ docker service ps wordpress
   ID            NAME         IMAGE             NODE  DESIRED STATE  CURRENT STATE           ERROR  PORTS
   aukx6hgs9gwc  wordpress.1  wordpress:latest  moby  Running        Running 52 seconds ago   
   ```

   此时，实际上**可以撤消**WordPress服务对`mysql_password `secret 的**访问权限**，因为WordPress已将secret**复制到其配置文件中`wp-config.php`**。现在不要这样做，因为我们稍后会使用它来方便旋转MySQL密码。

7. 从任何swarm节点访问`http://localhost:30000/` 并使用基于Web的向导设置WordPress。所有这些设置都存储在MySQL wordpress数据库中。WordPress自动为WordPress用户生成密码，这与WordPress用于访问MySQL的密码完全不同。安全地存储此密码，例如在密码管理器中。旋转秘密后，您需要它登录WordPress。

### 轮转秘密

---

这个例子建立在前一个例子上。在这种情况下，使用新的MySQL密码**创建新密码**，更新`mysql`和`wordpress`使用它的服务，然后**删除旧密码**。

> **注意**：更改MySQL数据库的密码涉及运行额外的查询或命令，而不是仅仅更改单个环境变量或文件，因为如果数据库尚不存在，镜像只设置MySQL密码，并且MySQL存储默认情况下，MySQL数据库中的密码。轮换密码或其他秘密可能涉及Docker之外的其他步骤。

1. 创建新密码并将其存储为一个名为secret的密码`mysql_password_v2`。

   ```sh
   $ openssl rand -base64 20 | docker secret create mysql_password_v2 -
   ```

2. 更新MySQL服务，使其能够访问旧的和新的秘密。请记住，您无法更新或重命名密钥，但可以撤销秘密并使用新的目标文件名授予对其的访问权限。

   ```sh
   $ docker service update \
        --secret-rm mysql_password mysql
   
   $ docker service update \
        --secret-add source=mysql_password,target=old_mysql_password \
        --secret-add source=mysql_password_v2,target=mysql_password \
        mysql
   ```

   更新服务会导致它重新启动，并且当MySQL服务第二次重新启动时，它将访问旧密钥 `/run/secrets/old_mysql_password`和新密钥`/run/secrets/mysql_password`。

   尽管MySQL服务现在可以访问旧的和新的机密，但WordPress用户的MySQL密码尚未更改。

   > **注意**：这个例子不会旋转MySQL `root`密码。

3. 现在，`wordpress`使用`mysqladmin`CLI 更改用户 的MySQL密码。该命令从`/run/secrets`文件中读取旧密码和新密码，但不在命令行上公开它们或将它们保存在shell历史记录中。

   继续下一步，因为WordPress失去了连接MySQL的能力。首先，找到`mysql`容器任务的ID 。

   ```sh
   $ docker ps --filter name=mysql -q
   c7705cf6176f
   ```

   在下面的命令中替换ID，或者使用第二个使用shell扩展的变量在一个步骤中完成。

   ```sh
   $ docker container exec <CONTAINER_ID> \
       bash -c 'mysqladmin --user=wordpress --password="$(< /run/secrets/old_mysql_password)" password "$(< /run/secrets/mysql_password)"'
   ```

   **或者**：

   ```sh
   $ docker container exec $(docker ps --filter name=mysql -q) \
       bash -c 'mysqladmin --user=wordpress --password="$(< /run/secrets/old_mysql_password)" password "$(< /run/secrets/mysql_password)"'
   ```

4. 更新`wordpress`服务以使用新密码，保留目标路径`/run/secrets/wp_db_secret`并保持文件权限 `0400`。这会触发WordPress服务的滚动重新启动，并使用新的秘密。

   ```sh
   $ docker service update \
        --secret-rm mysql_password \
        --secret-add source=mysql_password_v2,target=wp_db_password,mode=0400 \
        wordpress    
   ```

5. 通过再次浏览任何swarm节点上的`http://localhost:30000/`来验证WordPress是否工作正常。使用上一个任务中通过WordPress向导时的WordPress用户名和密码。

6. 撤消对MySQL服务的旧密钥的访问权限，并从Docker中删除旧密钥。

   ```sh
   $ docker service update \
        --secret-rm mysql_password \
        mysql
   
   $ docker secret rm mysql_password
   ```

7. 如果您想再次尝试，或只是运行的所有的这些例子中要贯穿其中清理后，使用这些命令删除WordPress的服务，MySQL容器中，`mydata`并且`wpdata`体积和泊坞窗的秘密。

   ```sh
   $ docker service rm wordpress mysql
   $ docker volume rm mydata wpdata
   $ docker secret rm mysql_password_v2 mysql_root_password
   ```

### 绑定 secret 到镜像中

---

如果开发的容器可以**作为服务**进行部署，并且需要**敏感数据（如凭证）作为环境变量**，那么可以考虑调整镜像以充分利用`secret`。一种方法是确保**在创建容器时传递给镜像的每个参数也可以从文件中**读取。

当你启动一个WordPress容器时，通过将它们**设置为环境变量来提供它所需的参数**。WordPress镜像已经更新，因此包含WordPress重要数据的环境变量（如`WORDPRESS_DB_PASSWORD`变量）也可以从文件（`WORDPRESS_DB_PASSWORD_FILE`）中读取它们的值。这种策略可确保**向后兼容**性得到保留，同时允许容器从Docker管理的`secret`中**读取**信息，而**不是直接传递**。

> **注意**：`secret`不会直接设置环境变量。这是一个有意的决定，因为环境变量可能会无意中泄漏到容器之间（例如，如果使用的话`--link`）。

#### 在compose中使用秘密

```yaml
version: '3.1'

services:
   db:
     image: mysql:latest
     volumes:
       - db_data:/var/lib/mysql
     environment:
       MYSQL_ROOT_PASSWORD_FILE: /run/secrets/db_root_password
       MYSQL_DATABASE: wordpress
       MYSQL_USER: wordpress
       MYSQL_PASSWORD_FILE: /run/secrets/db_password
     secrets:
       - db_root_password
       - db_password

   wordpress:
     depends_on:
       - db
     image: wordpress:latest
     ports:
       - "8000:80"
     environment:
       WORDPRESS_DB_HOST: db:3306
       WORDPRESS_DB_USER: wordpress
       WORDPRESS_DB_PASSWORD_FILE: /run/secrets/db_password
     secrets:
       - db_password


secrets:
   db_password:
     file: db_password.txt
   db_root_password:
     file: db_root_password.txt

volumes:
    db_data:
```

使用compose文件中的两个秘密创建一个简单的WordPress网站。关键字`secrets:`定义了两个秘密`db_password:`和 `db_root_password:`。

部署时，Docker会创建这两个秘密，并使用撰写文件中指定的文件中的内容填充它们。数据库服务使用两个秘密，并且wordpress使用一个。Docker会在服务下安装一个`/run/secrets/<secret_name>`文件。这些文件永远**不会保存在磁盘**中，而是**在内存**中进行管理。

每个服务**使用环境变量**来指定服务应该在哪里**查找秘密**数据。

# 锁定集群保护数据

在Docker 1.13及更高版本中，**集群管理器使用的Raft日志默认在磁盘上加密**。这种**静态加密**可以保护服务配置和数据免受攻击者的攻击，而**攻击者可以访问加密的Raft日志**。此功能推出的原因之一是支持新的[Docker机密](https://docs.docker.com/engine/swarm/secrets/)功能。

当Docker重新启动时，用于加密集群节点间通信的**TLS密钥以及用于加密和解密磁盘上的Raft日志的密钥**都会加载到每个管理器节点的内存中。Docker 1.13引入了**保护**相互TLS加密密钥和用于加密和解密Raft日志的密钥的功能，允许拥有这些密钥的所有权并要求**手动解锁**管理人员。该功能称为**自动锁定**。

当Docker重新启动时，您必须 先使用Docker在集群锁定时生成的 **密钥加密密钥**[解锁集群](https://docs.docker.com/engine/swarm/swarm_manager_locking/#unlock-a-swarm)。可以随时旋转此密钥加密密钥。

> **注意**：当新节点加入集群时，不需要解锁集群，因为密钥通过**相互TLS传播给新节点**。

## 使用自动锁定初始化集群

当初始化新的集群时，可以使用`--autolock`选项在Docker重新启动时启用集群管理器节点的自动锁定。

```sh
$ docker swarm init --autolock --advertise-addr 192.168.99.100
Swarm initialized: current node (7xxf1fyz3k0bl9c5rq155spyn) is now a manager.

To add a worker to this swarm, run the following command:

    docker swarm join --token SWMTKN-1-1abr6ndwyjilkevl4xzpxsvjs2m0tuny8osh9vnlos12suqjoa-8cyid630up9wmuumhunomiq93 192.168.99.100:2377

To add a manager to this swarm, run 'docker swarm join-token manager' and follow the instructions.

To unlock a swarm manager after it restarts, run the `docker swarm unlock`
command and provide the following key:

    SWMKEY-1-iNpw2d8sAR0clxNucH6+JT6sNW/NKyiVao9xsP2jO6g

Please remember to store this key in a password manager, since without it you
will not be able to restart the manager.
```

**将密钥存放在安全的地方，例如密码管理器**。

当Docker重新启动时，需要 [解锁集群](https://docs.docker.com/engine/swarm/swarm_manager_locking/#unlock-a-swarm)。尝试启动或重新启动服务时，锁定群会导致类似以下的错误：

```sh
$ sudo service docker restart

$ docker service ls
Error response from daemon: Swarm is encrypted and needs to be unlocked before it can be used. Use "docker swarm unlock" to unlock it.

$ docker swarm unlock
SWMKEY-1-iNpw2d8sAR0clxNucH6+JT6sNW/NKyiVao9xsP2jO6g
```

## 在集群上启用或禁用自动锁定

要在现有集群上启用自动锁定，请将`autolock`选项设置为`true`。

```sh
$ docker swarm update --autolock=true

Swarm updated.
To unlock a swarm manager after it restarts, run the `docker swarm unlock`
command and provide the following key:

    SWMKEY-1-+MrE8NgAyKj5r3NcR4FiQMdgu+7W72urH0EZeSmP/0Y

Please remember to store this key in a password manager, since without it you
will not be able to restart the manager.
```

要禁用自动锁定，请设置`--autolock`为`false`。用于读取和写入Raft日志的相互TLS密钥和加密密钥未加密存储在磁盘上。在**未加密**的情况下存储加密密钥的风险与不需要解锁每个管理器而重新启动集群的方便性之间存在折衷。

```sh
$ docker swarm update --autolock=false
```

在禁用自动锁定功能后，如果管理器在配置为**使用旧密钥**进行锁定时发生故障，请将**解锁密钥保留一小段时间**。

## 解锁集群

要解锁已锁定的群组，请使用`docker swarm unlock`。

```sh
$ docker swarm unlock
Please enter unlock key:
```

输入在锁定群组或旋转钥匙时生成并显示在命令输出中的加密密钥，并且集群解锁。

## 查看运行的集群的解锁密钥

考虑一下你的团队按预期运行的情况，然后管理节点变得不可用。排除故障并使物理节点重新联机，但需要**解锁管理器**，方法是提供解锁密钥以读取加密凭证和Raft日志。

如果自从节点离开集群后密钥**没有转变**，并且集群中有法定的功能管理器节点，则可以使用`docker swarm unlock-key`没有任何参数的方式查看当前的解锁密钥。

```sh
$ docker swarm unlock-key
To unlock a swarm manager after it restarts, run the `docker swarm unlock`
command and provide the following key:

    SWMKEY-1-ubaYsVMAc50QnKA0RWOOxOFkzye9Bp9U29Vz9LiQR0M

Please remember to store this key in a password manager, since without it you
will not be able to restart the manager.
```

如果在群组节点变得不可用并且没有前一个密钥的记录后旋转密钥，则可能需要**强制管理节点离开集群**并将其作为**新管理加入**群组。

## 转变解锁秘钥

应该定期轮换锁定群的解锁钥匙。

```sh
$ docker swarm unlock-key --rotate
Successfully rotated manager unlock key.

To unlock a swarm manager after it restarts, run the `docker swarm unlock`
command and provide the following key:

    SWMKEY-1-siPoOxp1rO+YZC4XC2aUkJoI+6AMb4Wg+DhK2EGW5AQ

Please remember to store this key in a password manager, since without it you
will not be able to restart the manager.
```

> **警告**：旋转解锁钥匙时，请将旧钥匙的记录保留几分钟，以便在管理节点拿到新秘钥之前，如果管理故障失灵，旧钥匙仍可能被解锁。

# 集群管理指南

当运行一群Docker引擎时，**管理节点**是管理集群和存储集群状态的关键组件。了解管理节点的一些关键特性以正确部署和维护集群非常重要。 

 ## 操作集群的管理节点

Swarm管理节点使用[Raft一致性算法](https://docs.docker.com/engine/swarm/raft/)来管理集群状态。你只需要理解Raft的一些一般概念就可以管理一个集群。

**管理器节点的数量没有限制**，但建议不要超过 70 个。决定要实现多少个管理节点是**性能和容错之间的折衷**。将管理器节点添加到集群使集群**更容错**。但是，其他管理器节点会**降低写入性能**，因为更多节点必须确认提议来**更新集群状态**。这意味着**更多的网络往返流量**。

Raft要求大多数管理者（也称为法定人数）同意对集群提出更新，例如节点添加或删除。成员资格操作受到与状态复制相同的限制。

### 维持管理人员的法定人数

---

如果集群失去了**管理节点的法定人数**，集群就**无法执行**管理任务。如果你的集群拥有多个管理节点，则总是有两个以上的经理。为了维持法定人数，大多数管理节点必须可用。建议使用**奇数**的管理者，因为下一个偶数不会使选举容易保留。例如，无论您是3或4位经理，仍然只能失去1位经理并维持法定人数。如果你有5或6个经理，你仍然只能失去两个。

即使集群**失去了**管理节点的**法定**节点数，现有**工作节点**上的集群任务也会**继续运行**。但是，不能添加，更新或删除集群节点，并且无法启动，停止，移动或更新新的或现有的任务。

如果确实失去了管理人员的法定人数，请参阅[恢复失败](https://docs.docker.com/engine/swarm/admin_guide/#recovering-from-losing-the-quorum)故障排除步骤的法定人数。

## 配置管理器通过静态IP进行通知

启动swarm时，必须指定`--advertise-addr`选项将地址通知给swarm中的其他管理节点。有关更多信息，请参阅[以集群模式运行Docker引擎](https://docs.docker.com/engine/swarm/swarm-mode/#configure-the-advertise-address)。由于管理节点旨在成为基础架构的**稳定组件**，因此应该使用广播地址的**固定IP**地址来防止集群在重新启动计算机时**变得不稳定**。

如果整个集群**重新启动**并且每个管理节点随后都**获得新的IP**地址，则任何节点都**无法联系**现有的管理员。因此，当节点尝试以**旧IP地址相互联系**时，**集群被挂起**。工作节点的动态IP地址正常。

## 添加管理器节点以实现容错

应该维护集群中的**数个管理**以支持管理**节点故障**。拥有**奇数个管理器**可确保在**网络分区**期间，如果网络分为**两组**，则法定数量仍可用于处理**请求**的**可能性较高**。如果遇到两个以上的网络分区，则不保证达到法定人数。

| 集群大小 | 最多故障数 | 容错  |
| -------- | ---------- | ----- |
| 1        | 1          | 0     |
| 2        | 2          | 0     |
| **3**    | 2          | **1** |
| 4        | 3          | 1     |
| **5**    | 3          | **2** |
| 6        | 4          | 2     |
| **7**    | 4          | **3** |
| 8        | 5          | 3     |
| **9**    | 5          | **4** |

例如，在一个有**5个节点**的集群*中*，如果失去*3个节点*，则没有法定人数。因此，在恢复其中一个不可用的管理节点或使用灾难恢复命令恢复集群之前，无法添加或删除节点。请参阅[从灾难中恢复](https://docs.docker.com/engine/swarm/admin_guide/#recover-from-disaster)。

虽然可以将集群缩放到**单个管理器节点**，但不可能降级最后一个管理器节点。这可以确保您保持对集群的**访问权限**，并且集群仍然可以处理请求。缩小到单个管理员是**不安全的操作**，不建议。如果最后一个节点在降级操作期间意外离开集群，则集群将变得不可用，直到重新启动节点或使用`--force-new-cluster`重新启动为止 。

可以管理`docker swarm`和`docker node` 子系统的集群成员资格。 有关如何添加工作节点并将工作节点提升为管理者的更多信息，请参阅向群[添加节点](https://docs.docker.com/engine/swarm/join-nodes/)。

### 分配管理节点

---

除了维护奇数个管理器节点之外，布置管理器时还要注意数据中心的**拓扑结构**。为了获得最佳的容错性，可以在**至少3个可用区中分配管理器节点**，以支持整套机器或常见维护方案的故障。如果在任何区域出现故障，集群应维持管理器节点的法定数量以处理请求并重新平衡工作负载。

| Swarm管理器节点 | 重新分区（在3个可用区域） |
| --------------- | ------------------------- |
| 3               | 1-1-1                     |
| 5               | 2-2-1                     |
| 7               | 3-2-2                     |
| 9               | 3-3-3                     |

### 仅限的管理节点

---

默认情况下，**管理节点也可以作为工作节点**。这意味着调度程序可以将任务分配给管理器节点。对于为管理人员分配任务的小型和非关键集群，只要使用*cpu*和*内存***资源约束**来安排服务，则风险相对较低。<br/>但是，由于管理节点使用Raft一致性算法以一致的方式复制数据，因此它们对**资源匮乏很敏感**。你应该**隔离**集群中的管理节点，使其**免受可能阻碍集群心跳或管理者选举**等集群操作的过程。

为了避免干扰管理器节点操作，可以使**管理器节点不再作为工作节点**使用：

```sh
$ docker node update --availability drain <NODE>
```

当排空节点时，调度程序将节点上运行的任何任务**重新分配**给群中的其他可用工作节点。它也**阻止**调度器将任务分配给节点。

## 添加工作节点以实现负载平衡

[为集群添加节点以](https://docs.docker.com/engine/swarm/join-nodes/)平衡集群的负载。只要工作节点与服务要求相匹配，复制服务任务就会随着时间的推移**尽可能均匀**地分布在整个集群中。将服务**限制为仅在特定类型**的节点（例如具有特定数量的CPU或内存量的节点）上运行时，请记住，不符合这些要求的工作节点无法运行这些任务。

## 监测集群健康

可以通过`/nodes`HTTP端点以JSON格式查询Docker `nodes` API 来监控管理器节点的健康状况。 有关更多信息，请参阅 [节点API文档](https://docs.docker.com/engine/api/v1.25/#tag/Node)。

运行命令`docker node inspect <id-node>`查询节点。例如，查询作为管理器的节点的可达性：

```sh
$ docker node inspect manager1 --format "{{ .ManagerStatus.Reachability }}"
reachable
```

要将节点的状态查询为接受任务的工作人员，请执行以下操作：

```sh
$ docker node inspect manager1 --format "{{ .Status.State }}"
ready
```

从这些命令中，我们可以看到，`manager1`它既 `reachable`是管理者又`ready`是工人。

`unreachable`健康状态意味着这个特定的管理器节点是从其他经理节点**无法访问**。在这种情况下，需要采取措施**恢复无法访问的管理节点**：

- **重新启动守护进程**并查看管理器是否回到可访问状态。
- **重新启动机器**。
- 如果既不重新启动也不重新启动，则应**添加另一个管理器节点或将工作人员提升为管理器节点**。还需要从使用`docker node demote <NODE>`和设置的管理器中干净地**删除失败**的节点`docker node rm <id-node>`。

或者，还可以从管理器节点获得集群运行状况的概述，其中包括`docker node ls`：

```sh
$ docker node ls
ID                           HOSTNAME  MEMBERSHIP  STATUS  AVAILABILITY  MANAGER STATUS
1mhtdwhvsgr3c26xxbnzdc3yp    node05    Accepted    Ready   Active
516pacagkqp2xc3fk9t1dhjor    node02    Accepted    Ready   Active        Reachable
9ifojw8of78kkusuc4a6c23fx *  node01    Accepted    Ready   Active        Leader
ax11wdpwrrb6db3mfjydscgk7    node04    Accepted    Ready   Active
bb1nrq2cswhtbg4mrsqnlx1ck    node03    Accepted    Ready   Active        Reachable
```

## 排除管理节点故障

**不应该通过`raft`**从另一个节点**复制**目录来**重启**管理器节点。**数据目录对于节点ID是唯一的**，一个节点只能使用一次节点ID加入群。**节点ID空间应该是全局唯一**的。

重新加入管理节点到集群中：

1. 要将节点**降级**为工作人员，请运行`docker node demote <NODE>`。
2. 要从群中**删除**节点，请运行`docker node rm <NODE>`。
3. 使用新的状态将节点**重新加入**到群中`docker swarm join`。

有关将经理节点[加入](https://docs.docker.com/engine/swarm/join-nodes/)群的更多信息，请参阅将 [群节点加入群](https://docs.docker.com/engine/swarm/join-nodes/)。

## 强制删除节点

在大多数情况下，应该关闭一个节点，然后使用`docker node rm`命令将其从**集群中删除**。如果某个节点变得**无法访问，无响应或受损**，则可以通过传递`--force`选项强制删除该节点而不关闭该节点。例如，如果`node9`变得受到影响：

```sh
$ docker node rm node9
Error response from daemon: rpc error: code = 9 desc = node node9 is not down and can't be removed

$ docker node rm --force node9
Node node9 removed from swarm
```

在强制删除管理器节点之前，必须先将其降级为辅助角色。如果您降级或删除经理，请确保您总是有奇数个经理节点。

## 备份集群

Docker管理器节点将swarm状态和管理器日志存储在 `/var/lib/docker/swarm/`目录中。在1.13及更高版本中，这些数据包括用于加密Raft日志的密钥。没有这些，你不能恢复群。

可以使用任何管理器备份群。使用以下步骤。

1. 如果集群启用了**自动锁定**功能，则需要**解锁密钥**才能从**备份中恢复集群**。必要时解锁钥匙并将其存放在安全的地方。如果不确定，请阅读 [锁定集群以保护其加密密钥](https://docs.docker.com/engine/swarm/swarm_manager_locking/)。

2. 在**备份数据之前在Manager上停止Docker**，以便在备份过程中**不会更改任何数据**。可以在**管理器运行时进行备份（“热”备份）**，但**不建议**这样做，并且在恢复时不易预测结果。当管理器关闭时，其他节点继续生成不属于此备份的集群数据。

   > **注意**：**务必保持集群经理的法定人数**。在经理关闭期间，如果更多节点丢失，则集群更容易丢失法定人数。你所经营的经理人数是一种**权衡**。如果经常关闭管理员进行备份，请考虑**运行5个管理节点集群**，以便在备份运行时丢失额外的管理器，而**不会中断服务**。

3. 备份整个`/var/lib/docker/swarm`目录。

4. 重新启动管理器。

要恢复，请参阅[从备份恢复](https://docs.docker.com/engine/swarm/admin_guide/#restore-from-a-backup)。

## 从灾难中恢复集群

### 从备份中恢复

---

按备份群组中的说明 [备份群组后](https://docs.docker.com/engine/swarm/admin_guide/#back-up-the-swarm)，使用以下步骤将数据恢复到新群组。

1. 在目标主机上**关闭**已恢复集群的Docker。

2. **删除**`/var/lib/docker/swarm`新集群上目录的内容。

3. `/var/lib/docker/swarm`使用**备份的内容还原**目录。

   > **注意**：新节点对旧磁盘存储使用相同的加密密钥。目前无法更改磁盘上的存储加密密钥。
   >
   > 在启用了自动锁定的集群中，解锁密钥也与旧集群相同，并且需要解锁密钥才能恢复集群。

4. 在新节点上启动Docker，必要时解锁群。使用以下命令重新初始化集群，以便此节点**不会尝试连接到属于旧集群**的节点，并且可能不再存在。

   ```sh
   $ docker swarm init --force-new-cluster
   ```

5. **验证集群的状态是否符合预期**。这可能包括特定于应用程序的测试或仅检查输出 `docker service ls`以确保所有预期的服务都存在。

6. 如果**使用自动锁定**，请 [旋转解锁键](https://docs.docker.com/engine/swarm/swarm_manager_locking/#rotate-the-unlock-key)。

7. 添加**管理员和工作者**节点，使新集群达到运营能力。

8. 在**新集群上恢复先前的备份**方案。

### 从失去法定人数恢复

---

Swarm对**故障具有恢复**能力，并且集群可以从任何数量的临时节点故障（机器重启或重启时崩溃）或其他瞬时错误中恢复。但是，如果集群**失去法定节点数量**，集群**无法自动恢复**。现有工作节点上的任务继续运行，但管理任务不可行，包括扩展或更新服务以及加入或从集群中删除节点。**恢复的最佳方法是将丢失的管理器节点重新联机**。如果这是不可能的，继续阅读一些恢复集群的选项。

在一群**`N`管理人员**中，管理节点的法定节点（大多数）必须始终可用。例如，在一个拥有5名管理人员的集群中，至少有3人必须开展业务并相互沟通。换句话说，集群可以**容忍`(N-1)/2`永远的失败**，**超过这个失败的集群管理请求不能被处理**。这些类型的故障包括**数据损坏或硬件故障**。

如果你失去了管理节点的法定数量，你不能管理集群。如果失去了法定节点数量，并且尝试对集群执行任何管理操作，则会发生错误：

```sh
Error response from daemon: rpc error: code = 4 desc = context deadline exceeded
```

从丢失法定数量中恢复的最佳方法是将**故障节点重新联机**。如果你不能这样做，从这个状态恢复的唯一方法就是使用`--force-new-cluster`来自**管理节点**的操作。这将**除去**命令运行的管理器**以外的所有管理器**。达到法定节点数量是因为现在只有一名管理。促使节点成为管理者，直到你拥有理想的管理者数量。

```sh
# From the node to recover
$ docker swarm init --force-new-cluster --advertise-addr node01:2377
```

当使用`docker swarm init` `--force-new-cluster` 选项运行命令时，运行该命令的Docker Engine成为**能够管理和运行服务的单节点群的管理器节点**。**管理节点拥有**关于服务和任务的所有**先前信息**，工作者节点仍然是集群的一部分，并且**服务仍在运行**。**需要添加或重新添加**管理节点以实现以前的任务分配，并确保拥有**足够的管理节点**来维护高可用性并防止丢失法定节点数量。

## 强制集群重新平衡

一般来说，不需要强迫集群重新平衡任务。当向集群中添加新节点或在某段时间不可用后节点重新连接集群时，**集群不会自动将工作负荷分配给闲置节点**。这是一个设计决定。如果集群为了平衡而**周期性地将任务转移**到不同节点，那么使用这些任务的客户端将会**中断**。我们的目标是避免为了整个集群的平衡而**中断运行服务**。当新任务启动时，或者当运行任务的节点变得**不可用**时，这些任务将被**分配给不太繁忙**的节点。目标是最终平衡，对最终用户造成的影响最小。

在Docker 1.13及更高版本中，可以使用 `docker service update` `--force`或 `-f`选项来**强制**服务在可用的工作节点上**重新分配**其任务。这会导致服务任务**重启**。客户端应用程序可能会中断。如果已配置它，服务将**使用[滚动更新](https://docs.docker.com/engine/swarm/swarm-tutorial/rolling-update/)**。

如果使用较早的版本，并且希望在工作人员之间达到均衡的负载，并且**不介意中断正在运行的任务**，则可以通过**临时伸缩服务**来强制集群重新平衡。使用 `docker service inspect --pretty <servicename>`看服务的**配置比例**。在使用时`docker service scale`，具有最少任务数量的节点将用于接收新的工作负载。集群中可能有多个负载不足的节点。可能需要通过几次适度增量扩展服务，以实现所有节点间的平衡。

当**负载达到满意度时，可以将服务缩减至原始比例**。可以使用`docker service ps`来评估**跨节点的服务当前状况**。

# 集群模式中的共识机制

当Docker引擎以群模式运行时，管理器节点实施 [Raft一致性算法](http://thesecretlivesofdata.com/raft/)来管理全局集群状态。

为什么**docker 集群模式**是使用一个共识算法，以**确保那些负责管理和调度任务集群中的所有节点的经理，都存储相同一致的状态**。

在整个集群中具有相同的一致性状态意味着如果发生故障，任何Manager节点都可以提取任务并将服务**恢复到稳定**状态。例如，如果负责在集群中调度任务的**负责人经理**意外死亡，则任何其他经理都可以执行调度任务并重新平衡任务以匹配期望的状态。

**使用共识算法在分布式系统中复制日志的系统需要特别小心。它们通过要求大多数节点同意值来确保集群状态在出现故障时保持一致**。

Raft容忍**`(N-1)/2`失败**，并且需要**大多数`(N/2)+1`成员**或法定 成员的会员才能就集群提出的价值**达成一致**。这意味着在一个由5个管理员组成的集群中，如果有3个节点不可用，系统将无法处理更多的请求来安排额外的任务。现有任务保持运行，但如果管理员设置不健全，则调度程序无法重新平衡任务以应对失败。

集群模式中实现共识算法意味着它具有分布式系统固有的特性：

- 容错系统中的值**达成一致**。（参考[FLP不可能性定理](http://the-paper-trail.org/blog/a-brief-tour-of-flp-impossibility/) 和[Raft共识算法论文](https://www.usenix.org/system/files/conference/atc14/atc14-paper-ongaro.pdf)）
- 通过领导人选举过程**相互排斥**
- **集群成员**管理
- **全局一致的对象排序**和CAS（比较和交换）基元