# docker swarm 入门与实践 

* [docker swarm 入门与实践](#docker-swarm-%E5%85%A5%E9%97%A8%E4%B8%8E%E5%AE%9E%E8%B7%B5)
* [集群模式概述](#%E9%9B%86%E7%BE%A4%E6%A8%A1%E5%BC%8F%E6%A6%82%E8%BF%B0)
  * [集群特点](#%E9%9B%86%E7%BE%A4%E7%89%B9%E7%82%B9)
* [群模式关键概念](#%E7%BE%A4%E6%A8%A1%E5%BC%8F%E5%85%B3%E9%94%AE%E6%A6%82%E5%BF%B5)
  * [什么是集群？](#%E4%BB%80%E4%B9%88%E6%98%AF%E9%9B%86%E7%BE%A4)
  * [节点](#%E8%8A%82%E7%82%B9)
  * [服务和任务](#%E6%9C%8D%E5%8A%A1%E5%92%8C%E4%BB%BB%E5%8A%A1)
  * [负载均衡](#%E8%B4%9F%E8%BD%BD%E5%9D%87%E8%A1%A1)
* [docker swarm 基本命令](#docker-swarm-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [ca 证书](#ca-%E8%AF%81%E4%B9%A6)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9)
    * [\-\-rotate](#--rotate)
    * [\-\-detach](#--detach)
    * [示例](#%E7%A4%BA%E4%BE%8B)
      * [生成证书](#%E7%94%9F%E6%88%90%E8%AF%81%E4%B9%A6)
      * [轮转证书](#%E8%BD%AE%E8%BD%AC%E8%AF%81%E4%B9%A6)
  * [init 初始化](#init-%E5%88%9D%E5%A7%8B%E5%8C%96)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-1)
      * [\-\-autolock](#--autolock)
      * [\-\-cert\-expiry](#--cert-expiry)
      * [\-\-dispatcher\-heartbeat](#--dispatcher-heartbeat)
      * [\-\-external\-ca](#--external-ca)
      * [\-\-force\-new\-cluster](#--force-new-cluster)
      * [\-\-listen\-addr](#--listen-addr)
      * [\-\-advertise\-addr](#--advertise-addr)
      * [\-\-data\-path\-addr](#--data-path-addr)
      * [\-\-task\-history\-limit](#--task-history-limit)
      * [\-\-max\-snapshots](#--max-snapshots)
      * [\-\-snapshot\-interval](#--snapshot-interval)
      * [\-\-availability](#--availability)
    * [示例](#%E7%A4%BA%E4%BE%8B-1)
      * [创建集群](#%E5%88%9B%E5%BB%BA%E9%9B%86%E7%BE%A4)
  * [join 加入](#join-%E5%8A%A0%E5%85%A5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-2)
    * [\-\-listen\-addr value](#--listen-addr-value)
    * [\-\-advertise\-addr value](#--advertise-addr-value)
    * [\-\-data\-path\-addr](#--data-path-addr-1)
    * [\-\-token string](#--token-string)
    * [\-\-availability](#--availability-1)
    * [示例](#%E7%A4%BA%E4%BE%8B-2)
      * [加入管理节点](#%E5%8A%A0%E5%85%A5%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9)
      * [加入工作节点](#%E5%8A%A0%E5%85%A5%E5%B7%A5%E4%BD%9C%E8%8A%82%E7%82%B9)
  * [join\-token 令牌](#join-token-%E4%BB%A4%E7%89%8C)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-3)
    * [示例](#%E7%A4%BA%E4%BE%8B-3)
      * [获取加入工作节点的token](#%E8%8E%B7%E5%8F%96%E5%8A%A0%E5%85%A5%E5%B7%A5%E4%BD%9C%E8%8A%82%E7%82%B9%E7%9A%84token)
      * [获取加入管理节点的token](#%E8%8E%B7%E5%8F%96%E5%8A%A0%E5%85%A5%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9%E7%9A%84token)
      * [查看token](#%E6%9F%A5%E7%9C%8Btoken)
      * [轮转](#%E8%BD%AE%E8%BD%AC)
  * [leave 离开](#leave-%E7%A6%BB%E5%BC%80)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-4)
    * [示例](#%E7%A4%BA%E4%BE%8B-4)
  * [unlock 解锁](#unlock-%E8%A7%A3%E9%94%81)
  * [unlock\-key 解锁秘钥](#unlock-key-%E8%A7%A3%E9%94%81%E7%A7%98%E9%92%A5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-5)
    * [示例](#%E7%A4%BA%E4%BE%8B-5)
  * [update 更新](#update-%E6%9B%B4%E6%96%B0)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-6)
    * [示例](#%E7%A4%BA%E4%BE%8B-6)
* [docker node 基本命令](#docker-node-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [demote 降级](#demote-%E9%99%8D%E7%BA%A7)
  * [promote 升级](#promote-%E5%8D%87%E7%BA%A7)
  * [inspect 检查](#inspect-%E6%A3%80%E6%9F%A5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-7)
    * [示例](#%E7%A4%BA%E4%BE%8B-7)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-8)
    * [示例](#%E7%A4%BA%E4%BE%8B-8)
      * [查看节点](#%E6%9F%A5%E7%9C%8B%E8%8A%82%E7%82%B9)
      * [过滤](#%E8%BF%87%E6%BB%A4)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96)
  * [ps 查看任务](#ps-%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-9)
    * [示例](#%E7%A4%BA%E4%BE%8B-9)
      * [查看任务](#%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1)
      * [过滤](#%E8%BF%87%E6%BB%A4-1)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-10)
    * [示例](#%E7%A4%BA%E4%BE%8B-10)
      * [删除停止节点](#%E5%88%A0%E9%99%A4%E5%81%9C%E6%AD%A2%E8%8A%82%E7%82%B9)
      * [删除运行节点](#%E5%88%A0%E9%99%A4%E8%BF%90%E8%A1%8C%E8%8A%82%E7%82%B9)
      * [强行删除不可访问的节点](#%E5%BC%BA%E8%A1%8C%E5%88%A0%E9%99%A4%E4%B8%8D%E5%8F%AF%E8%AE%BF%E9%97%AE%E7%9A%84%E8%8A%82%E7%82%B9)
  * [update 更新](#update-%E6%9B%B4%E6%96%B0-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-11)
    * [示例](#%E7%A4%BA%E4%BE%8B-11)
* [docker service 基本命令](#docker-service-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-12)
    * [示例](#%E7%A4%BA%E4%BE%8B-12)
      * [创建服务](#%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
      * [使用私人注册表中的镜像创建服务](#%E4%BD%BF%E7%94%A8%E7%A7%81%E4%BA%BA%E6%B3%A8%E5%86%8C%E8%A1%A8%E4%B8%AD%E7%9A%84%E9%95%9C%E5%83%8F%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
      * [创建5个副本任务的服务](#%E5%88%9B%E5%BB%BA5%E4%B8%AA%E5%89%AF%E6%9C%AC%E4%BB%BB%E5%8A%A1%E7%9A%84%E6%9C%8D%E5%8A%A1)
      * [创建私密服务](#%E5%88%9B%E5%BB%BA%E7%A7%81%E5%AF%86%E6%9C%8D%E5%8A%A1)
      * [使用滚动更新策略创建服务](#%E4%BD%BF%E7%94%A8%E6%BB%9A%E5%8A%A8%E6%9B%B4%E6%96%B0%E7%AD%96%E7%95%A5%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
      * [设置环境变量](#%E8%AE%BE%E7%BD%AE%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
      * [创建具有特定主机名的服务](#%E5%88%9B%E5%BB%BA%E5%85%B7%E6%9C%89%E7%89%B9%E5%AE%9A%E4%B8%BB%E6%9C%BA%E5%90%8D%E7%9A%84%E6%9C%8D%E5%8A%A1)
      * [在服务上设置元数据](#%E5%9C%A8%E6%9C%8D%E5%8A%A1%E4%B8%8A%E8%AE%BE%E7%BD%AE%E5%85%83%E6%95%B0%E6%8D%AE)
      * [添加挂载，卷或内存文件系统](#%E6%B7%BB%E5%8A%A0%E6%8C%82%E8%BD%BD%E5%8D%B7%E6%88%96%E5%86%85%E5%AD%98%E6%96%87%E4%BB%B6%E7%B3%BB%E7%BB%9F)
        * [<strong>挂载传播</strong>](#%E6%8C%82%E8%BD%BD%E4%BC%A0%E6%92%AD)
        * [<strong>命名卷的选项</strong>](#%E5%91%BD%E5%90%8D%E5%8D%B7%E7%9A%84%E9%80%89%E9%A1%B9)
        * [<strong>TMPFS的选项</strong>](#tmpfs%E7%9A%84%E9%80%89%E9%A1%B9)
        * [<strong>\-\-MOUNT和\-\-VOLUME的区别</strong>](#--mount%E5%92%8C--volume%E7%9A%84%E5%8C%BA%E5%88%AB)
        * [使用命名卷创建服务](#%E4%BD%BF%E7%94%A8%E5%91%BD%E5%90%8D%E5%8D%B7%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
        * [使用匿名卷创建服务](#%E4%BD%BF%E7%94%A8%E5%8C%BF%E5%90%8D%E5%8D%B7%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
        * [使用绑定挂载主机目录创建服务](#%E4%BD%BF%E7%94%A8%E7%BB%91%E5%AE%9A%E6%8C%82%E8%BD%BD%E4%B8%BB%E6%9C%BA%E7%9B%AE%E5%BD%95%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
      * [设置服务模式](#%E8%AE%BE%E7%BD%AE%E6%9C%8D%E5%8A%A1%E6%A8%A1%E5%BC%8F)
      * [指定服务约束](#%E6%8C%87%E5%AE%9A%E6%9C%8D%E5%8A%A1%E7%BA%A6%E6%9D%9F)
      * [指定服务分布选项](#%E6%8C%87%E5%AE%9A%E6%9C%8D%E5%8A%A1%E5%88%86%E5%B8%83%E9%80%89%E9%A1%B9)
      * [将服务附加到现有网络](#%E5%B0%86%E6%9C%8D%E5%8A%A1%E9%99%84%E5%8A%A0%E5%88%B0%E7%8E%B0%E6%9C%89%E7%BD%91%E7%BB%9C)
      * [在群外发布服务端口](#%E5%9C%A8%E7%BE%A4%E5%A4%96%E5%8F%91%E5%B8%83%E6%9C%8D%E5%8A%A1%E7%AB%AF%E5%8F%A3)
      * [提供托管服务帐户的凭证规格（仅限Windows）](#%E6%8F%90%E4%BE%9B%E6%89%98%E7%AE%A1%E6%9C%8D%E5%8A%A1%E5%B8%90%E6%88%B7%E7%9A%84%E5%87%AD%E8%AF%81%E8%A7%84%E6%A0%BC%E4%BB%85%E9%99%90windows)
      * [使用模板创建服务](#%E4%BD%BF%E7%94%A8%E6%A8%A1%E6%9D%BF%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1)
      * [指定隔离模式（Windows）](#%E6%8C%87%E5%AE%9A%E9%9A%94%E7%A6%BB%E6%A8%A1%E5%BC%8Fwindows)
      * [创建请求通用资源的服务](#%E5%88%9B%E5%BB%BA%E8%AF%B7%E6%B1%82%E9%80%9A%E7%94%A8%E8%B5%84%E6%BA%90%E7%9A%84%E6%9C%8D%E5%8A%A1)
  * [inspect 检查](#inspect-%E6%A3%80%E6%9F%A5-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-13)
    * [示例](#%E7%A4%BA%E4%BE%8B-13)
      * [按名称或ID检查服务](#%E6%8C%89%E5%90%8D%E7%A7%B0%E6%88%96id%E6%A3%80%E6%9F%A5%E6%9C%8D%E5%8A%A1)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-1)
  * [logs 日志](#logs-%E6%97%A5%E5%BF%97)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-14)
    * [示例](#%E7%A4%BA%E4%BE%8B-14)
      * [查看日志](#%E6%9F%A5%E7%9C%8B%E6%97%A5%E5%BF%97)
      * [跟踪日志](#%E8%B7%9F%E8%B8%AA%E6%97%A5%E5%BF%97)
      * [查看指定行数](#%E6%9F%A5%E7%9C%8B%E6%8C%87%E5%AE%9A%E8%A1%8C%E6%95%B0)
      * [时间戳](#%E6%97%B6%E9%97%B4%E6%88%B3)
      * [额外详细信息](#%E9%A2%9D%E5%A4%96%E8%AF%A6%E7%BB%86%E4%BF%A1%E6%81%AF)
      * [日期过滤](#%E6%97%A5%E6%9C%9F%E8%BF%87%E6%BB%A4)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-15)
    * [示例](#%E7%A4%BA%E4%BE%8B-15)
      * [查看](#%E6%9F%A5%E7%9C%8B)
      * [过滤](#%E8%BF%87%E6%BB%A4-2)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-2)
  * [ps 任务列表](#ps-%E4%BB%BB%E5%8A%A1%E5%88%97%E8%A1%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-16)
    * [示例](#%E7%A4%BA%E4%BE%8B-16)
      * [查看任务](#%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1-1)
      * [过滤](#%E8%BF%87%E6%BB%A4-3)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-3)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-1)
  * [rollback 回滚](#rollback-%E5%9B%9E%E6%BB%9A)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-17)
    * [示例](#%E7%A4%BA%E4%BE%8B-17)
  * [scale 副本比例](#scale-%E5%89%AF%E6%9C%AC%E6%AF%94%E4%BE%8B)
    * [示例](#%E7%A4%BA%E4%BE%8B-18)
      * [扩展单个服务](#%E6%89%A9%E5%B1%95%E5%8D%95%E4%B8%AA%E6%9C%8D%E5%8A%A1)
      * [扩展多个服务](#%E6%89%A9%E5%B1%95%E5%A4%9A%E4%B8%AA%E6%9C%8D%E5%8A%A1)
  * [update 更新](#update-%E6%9B%B4%E6%96%B0-2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-18)
    * [示例](#%E7%A4%BA%E4%BE%8B-19)
      * [更新服务](#%E6%9B%B4%E6%96%B0%E6%9C%8D%E5%8A%A1)
      * [在不更改参数的情况下执行滚动重启](#%E5%9C%A8%E4%B8%8D%E6%9B%B4%E6%94%B9%E5%8F%82%E6%95%B0%E7%9A%84%E6%83%85%E5%86%B5%E4%B8%8B%E6%89%A7%E8%A1%8C%E6%BB%9A%E5%8A%A8%E9%87%8D%E5%90%AF)
      * [添加或删除挂载](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E6%8C%82%E8%BD%BD)
      * [添加或删除已发布的服务端口](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E5%B7%B2%E5%8F%91%E5%B8%83%E7%9A%84%E6%9C%8D%E5%8A%A1%E7%AB%AF%E5%8F%A3)
      * [添加或删除网络](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E7%BD%91%E7%BB%9C)
      * [回滚到服务的先前版本](#%E5%9B%9E%E6%BB%9A%E5%88%B0%E6%9C%8D%E5%8A%A1%E7%9A%84%E5%85%88%E5%89%8D%E7%89%88%E6%9C%AC)
      * [添加或删除秘密](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E7%A7%98%E5%AF%86)
* [docker stack 基本命令](#docker-stack-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [deploy 部署](#deploy-%E9%83%A8%E7%BD%B2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-19)
    * [示例](#%E7%A4%BA%E4%BE%8B-20)
      * [Compose 文件](#compose-%E6%96%87%E4%BB%B6)
      * [DAB文件](#dab%E6%96%87%E4%BB%B6)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-20)
    * [示例](#%E7%A4%BA%E4%BE%8B-21)
      * [查看](#%E6%9F%A5%E7%9C%8B-1)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-4)
  * [ps 查看任务](#ps-%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-21)
    * [示例](#%E7%A4%BA%E4%BE%8B-22)
      * [查看](#%E6%9F%A5%E7%9C%8B-2)
      * [过滤](#%E8%BF%87%E6%BB%A4-4)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-5)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-2)
  * [services 查看服务](#services-%E6%9F%A5%E7%9C%8B%E6%9C%8D%E5%8A%A1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-22)
    * [示例](#%E7%A4%BA%E4%BE%8B-23)
      * [查看](#%E6%9F%A5%E7%9C%8B-3)
      * [过滤](#%E8%BF%87%E6%BB%A4-5)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-6)
* [开始使用集群](#%E5%BC%80%E5%A7%8B%E4%BD%BF%E7%94%A8%E9%9B%86%E7%BE%A4)
  * [创建集群](#%E5%88%9B%E5%BB%BA%E9%9B%86%E7%BE%A4-1)
  * [向集群添加节点](#%E5%90%91%E9%9B%86%E7%BE%A4%E6%B7%BB%E5%8A%A0%E8%8A%82%E7%82%B9)
  * [在集群上部署服务](#%E5%9C%A8%E9%9B%86%E7%BE%A4%E4%B8%8A%E9%83%A8%E7%BD%B2%E6%9C%8D%E5%8A%A1)
  * [检查集群上的服务](#%E6%A3%80%E6%9F%A5%E9%9B%86%E7%BE%A4%E4%B8%8A%E7%9A%84%E6%9C%8D%E5%8A%A1)
  * [扩展集群中的服务](#%E6%89%A9%E5%B1%95%E9%9B%86%E7%BE%A4%E4%B8%AD%E7%9A%84%E6%9C%8D%E5%8A%A1)
  * [删除在群上运行的服务](#%E5%88%A0%E9%99%A4%E5%9C%A8%E7%BE%A4%E4%B8%8A%E8%BF%90%E8%A1%8C%E7%9A%84%E6%9C%8D%E5%8A%A1)
  * [滚动更新应用于服务](#%E6%BB%9A%E5%8A%A8%E6%9B%B4%E6%96%B0%E5%BA%94%E7%94%A8%E4%BA%8E%E6%9C%8D%E5%8A%A1)
  * [排除集群上的节点](#%E6%8E%92%E9%99%A4%E9%9B%86%E7%BE%A4%E4%B8%8A%E7%9A%84%E8%8A%82%E7%82%B9)
  * [使用集群路由网络](#%E4%BD%BF%E7%94%A8%E9%9B%86%E7%BE%A4%E8%B7%AF%E7%94%B1%E7%BD%91%E7%BB%9C)
    * [发布服务的端口](#%E5%8F%91%E5%B8%83%E6%9C%8D%E5%8A%A1%E7%9A%84%E7%AB%AF%E5%8F%A3)
    * [发布TCP或UDP端口](#%E5%8F%91%E5%B8%83tcp%E6%88%96udp%E7%AB%AF%E5%8F%A3)
      * [仅限TCP](#%E4%BB%85%E9%99%90tcp)
      * [TCP和UDP](#tcp%E5%92%8Cudp)
      * [仅限UDP](#%E4%BB%85%E9%99%90udp)
    * [绕过路由网格](#%E7%BB%95%E8%BF%87%E8%B7%AF%E7%94%B1%E7%BD%91%E6%A0%BC)
    * [配置外部负载平衡器](#%E9%85%8D%E7%BD%AE%E5%A4%96%E9%83%A8%E8%B4%9F%E8%BD%BD%E5%B9%B3%E8%A1%A1%E5%99%A8)
      * [使用路由网格](#%E4%BD%BF%E7%94%A8%E8%B7%AF%E7%94%B1%E7%BD%91%E6%A0%BC)
      * [没有路由网格](#%E6%B2%A1%E6%9C%89%E8%B7%AF%E7%94%B1%E7%BD%91%E6%A0%BC)
* [集群的用途](#%E9%9B%86%E7%BE%A4%E7%9A%84%E7%94%A8%E9%80%94)
  * [节点的用途](#%E8%8A%82%E7%82%B9%E7%9A%84%E7%94%A8%E9%80%94)
    * [管理节点](#%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9)
    * [工作节点](#%E5%B7%A5%E4%BD%9C%E8%8A%82%E7%82%B9)
    * [更改角色](#%E6%9B%B4%E6%94%B9%E8%A7%92%E8%89%B2)
  * [服务的用途](#%E6%9C%8D%E5%8A%A1%E7%9A%84%E7%94%A8%E9%80%94)
    * [服务、任务和容器](#%E6%9C%8D%E5%8A%A1%E4%BB%BB%E5%8A%A1%E5%92%8C%E5%AE%B9%E5%99%A8)
    * [任务和调度](#%E4%BB%BB%E5%8A%A1%E5%92%8C%E8%B0%83%E5%BA%A6)
      * [待定服务](#%E5%BE%85%E5%AE%9A%E6%9C%8D%E5%8A%A1)
    * [副本服务和全局服务](#%E5%89%AF%E6%9C%AC%E6%9C%8D%E5%8A%A1%E5%92%8C%E5%85%A8%E5%B1%80%E6%9C%8D%E5%8A%A1)
  * [使用公钥基础设施（PKI）管理集群安全](#%E4%BD%BF%E7%94%A8%E5%85%AC%E9%92%A5%E5%9F%BA%E7%A1%80%E8%AE%BE%E6%96%BDpki%E7%AE%A1%E7%90%86%E9%9B%86%E7%BE%A4%E5%AE%89%E5%85%A8)
    * [轮换CA证书](#%E8%BD%AE%E6%8D%A2ca%E8%AF%81%E4%B9%A6)
  * [集群任务状态](#%E9%9B%86%E7%BE%A4%E4%BB%BB%E5%8A%A1%E7%8A%B6%E6%80%81)
    * [查看任务状态](#%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1%E7%8A%B6%E6%80%81)

# 集群模式概述

当前版本的Docker包括*swarm模式，*用于本地管理称为集群的Docker引擎*集群*。使用Docker CLI创建集群，将应用程序服务部署到集群，并管理群体行为。

如果你之前使用的是Docker版本`1.12.0`，则可以使用[独立集群](https://docs.docker.com/swarm/)，但我们建议进行更新。

## 集群特点

- **与Docker Engine集成的集群管理：** 使用Docker Engine CLI创建一群Docker引擎，可以在其中部署应用程序服务。不需要额外的编排软件来创建或管理群。
- **分散式设计：** Docker Engine在部署时不需要处理节点角色之间的差异，而是在运行时处理任何专业化。你可以使用Docker Engine部署这两种节点，管理员和工作人员。这意味着你可以从单个磁盘镜像构建整个集群。
- **声明式服务模型：** Docker Engine使用声明式方法让你在应用程序堆栈中定义各种服务的所需状态。例如，你可能会描述一个由带有消息队列服务和数据库后端的Web前端服务组成的应用程序。
- **伸缩：** 对于每个服务，你可以声明要运行的任务数量。当你向上或向下缩放时，swarm管理器会通过添加或删除任务来自动调整以保持所需的状态。
- **期望的状态协调：** swarm manager节点持续监视集群状态，并协调实际状态与表达期望状态之间的任何差异。例如，如果你设置了一个服务来运行容器的10个副本以及承载其中两个副本崩溃的工作计算机，则该管理器会创建两个新副本来替换发生崩溃的副本。swarm manager将新副本分配给正在运行且可用的工作人员。
- **多主机联网：** 你可以为你的服务指定覆盖网络。swarm管理器在初始化或更新应用程序时自动为覆盖网络上的容器分配地址。
- **服务发现：** Swarm管理器节点为swarm中的每个服务分配一个唯一的DNS名称并负载平衡正在运行的容器。你可以通过集群中嵌入的DNS服务器查询集群中运行的每个容器。
- **负载平衡：** 你可以将服务的端口暴露给外部负载平衡器。在集群内部，你可以指定如何在节点之间分发服务容器。
- **默认情况下为安全：** 群中的每个节点都强制进行TLS相互认证和加密，以保护其自身与所有其他节点之间的通信。你可以选择使用自定义根证书或来自自定义根CA的证书。
- **滚动更新：** 在推出时，你可以逐步将服务更新应用于节点。swarm管理器允许你控制服务部署到不同节点集之间的延迟。如果出现任何问题，你可以将任务回滚到以前版本的服务。

# 群模式关键概念

## 什么是集群？

嵌入在Docker Engine中的集群管理和编排功能是使用[swarmkit构建的](https://github.com/docker/swarmkit/)。Swarmkit是一个独立的项目，它实现了Docker的编排层，并直接在Docker中使用。

一个集群由多个Docker主机组成，这些主机以**集群模式**运行并充当管理 者（管理成员和委派）和工作 者（运行 [集群服务](https://docs.docker.com/engine/swarm/key-concepts/#services-and-tasks)）。给定的Docker主机可以是管理员、工作者或执行这两种角色。当你创建服务时，可以定义最佳状态（副本数量，可用的网络和存储资源，将服务暴露给外界等等）。Docker的工作是维持这个理想的状态。例如，如果工作节点变得不可用，Docker会在其他节点上调度该节点的任务。一个**任务** 是运行的容器集群服务的一部分，并通过集群管理节点管理，而不是一个独立的容器。

集群服务相对于独立容器的主要优势之一是**可以修改服务的配置**，包括连接的**网络和卷**，而**无需手动重新启动**服务。**Docker将更新配置，停止使用过时配置的服务任务，并创建与所需配置相匹配的新服务**。

当Docker以集群模式运行时，仍然可以在参与集群的任何Docker主机以及集群服务上运行独立容器。独立容器和集群服务之间的一个**主要区别**是，只有集群管理员可以管理集群，而独立容器可以在任何守护进程上启动。Docker守护进程可以作为管理者，工作者或两者参与群体。

与使用[Docker Compose](https://docs.docker.com/compose/)定义和运行容器的方式相同，你可以定义并运行swarm [堆栈](https://docs.docker.com/get-started/part5/)服务。

## 节点

一个**节点**是docker引擎参与集群的一个实例。你也可以将其视为Docker节点。你可以在单台物理计算机或云服务器上运行一个或多个节点，但生产群部署通常包括分布在多台物理机和云计算机上的Docker节点。

要将你的应用程序部署到集群，你需要向**管理节点**提交服务定义 。管理节点将称为[任务](https://docs.docker.com/engine/swarm/key-concepts/#services-and-tasks)的工作单元分派 给工作节点。

Manager节点还执行维护群体所需状态所需的编排和集群管理功能。管理节点选择一位领导者来执行编排任务。

**工作者节点**接收并执行从管理器节点分派的任务。默认情况下，管理器节点也可以将服务作为工作节点运行，但你可以将它们配置为独占运行管理器任务，并且是纯管理器节点。代理在每个工作节点上运行并报告分配给它的任务。工作节点通知管理节点其分配任务的当前状态，以便管理人员可以维护每个工作人员所需的状态。

## 服务和任务

一个**服务**是任务的定义，管理或工作节点上执行。它是群体系统的中心结构，也是群体与用户互动的主要根源。

在创建服务时，你可以指定要使用哪个容器镜像以及要在正在运行的容器中执行哪些命令。

在**复制服务**模型中，swarm管理器根据你在所需状态中设置的比例在节点之间分配特定数量的副本任务。

对于**全局服务**，集群为集群中每个可用节点上的服务运行一个任务。

**任务**携带docker容器和在容器内部运行的命令。它是群体的原子调度单位。管理器节点根据服务规模中设置的副本数量将任务分配给工作节点。一旦任务分配给节点，它就不能移动到另一个节点。它只能在分配的节点上运行或失败。

## 负载均衡

swarm管理器使用**入口负载平衡**来公开要在集群外部提供的服务。swarm manager可以自动为服务分配一个**PublishedPort，**或者你可以为该服务配置一个PublishedPort。你可以指定任何未使用的端口。如果你不指定端口，那么swarm管理器将为该服务分配一个30000-32767范围内的端口。

外部组件（如云负载平衡器）可以访问集群中任何节点的PublishedPort上的服务，而不管该节点当前是否正在运行该服务的任务。集群路由中的**所有节点都会连接到正在运行的任务实例**。

Swarm模式有一个**内部DNS组件**，可自动为集群中的每个服务分配一个DNS条目。swarm管理器使用**内部负载平衡**根据服务的**DNS名称在集群内的服务之间分配请求**。

# docker swarm 基本命令

```sh
$ docker swarm -h
Usage:  docker swarm COMMAND

集群管理

Commands:
  ca          # 显示并轮着 CA 根证书
  init        # 初始化集群
  join        # 加入群体作为节点或管理
  join-token  # 管理连接令牌
  leave       # 离开集群
  unlock      # 解锁集群
  unlock-key  # 管理解锁密钥
  update      # 更新集群
```



## ca 证书

查看或轮转当前**集群CA证书**。该命令必须以**管理节点**为目标。

 

### 命令参数选项

---

| 选项，简写      | 默认        | 描述                                                      |
| --------------- | ----------- | --------------------------------------------------------- |
| `--ca-cert`     |             | 用于新集群的PEM格式的根CA证书的路径                       |
| `--ca-key`      |             | 用于新集群的PEM格式化根CA密钥的路径                       |
| `--cert-expiry` | `2160h0m0s` | 节点证书的有效期（ns \| us \| ms \| s \| m \| h）         |
| `--detach , -d` |             | 立即退出，而不是等待根旋转结束                            |
| `--external-ca` |             | 一个或多个证书签名端点的规范格式                          |
| `--quiet , -q`  |             | 控制进度输出                                              |
| `--rotate`      |             | 旋转集群CA - 如果未提供证书或密钥，则会生成新的证书或密钥 |

### `--rotate`

如果一个或多个**集群管理节点遭到入侵，建议使用根CA轮换**，以便这些管理节点**不能再连接到集群中的任何其他节点**或受其信任。或者，可以使用**根CA旋转来将集群CA控制权授予外部CA**，或从**外部CA获取控制权**。

`--rotate`选项不需要任何参数进行轮换，但可以选择**指定证书和密钥**，或者**证书和外部CA URL**，并且将使用这些参数代替自动生成的证书/密钥对。

由于根CA密钥应该保密，如果提供，通过CLI或API查看集群任何信息时都不可见。直到**所有注册节点**都旋转了他们的TLS证书后，根CA轮换才能完成。如果旋转**没有在合理的时间**内完成，请尝试运行`docker node ls --format '{{.ID}} {{.Hostname}} {{.Status}} {{.TLSStatus}}'`以查看是否有节点关闭或无法旋转TLS证书。

```sh
$ docker node ls --format '{{.ID}} {{.Hostname}} {{.Status}} {{.TLSStatus}}'
888gi7byqi5p7wtd2yv1z465i default Ready Ready
jx49db999birkx3myeorh9qvg my-vm-node-1 Ready Ready
```

### `--detach`

启动根CA旋转，但**不要等待完成或显示旋转的进度**。也就是**后台运行**模式！

### 示例

---

#### 生成证书

运行`docker swarm ca`没有任何选项的命令，以PEM格式查看当前的根CA证书。 

```sh
$ docker swarm ca
-----BEGIN CERTIFICATE-----
MIIBazCCARCgAwIBAgIUItJPmJ9DupeZ5VuoTjAV9mc/1/IwCgYIKoZIzj0EAwIw
EzERMA8GA1UEAxMIc3dhcm0tY2EwHhcNMTgwNTAxMTAyMjAwWhcNMzgwNDI2MTAy
MjAwWjATMREwDwYDVQQDEwhzd2FybS1jYTBZMBMGByqGSM49AgEGCCqGSM49AwEH
A0IABFzfcww26FTn48sBKJ28+U0/d0tAdSZ2MO70brm2fUhx8k6xxAZimDyY0rd3
sowuFJV76BnlojpH9s0r7xamd1qjQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNVHRMB
Af8EBTADAQH/MB0GA1UdDgQWBBSCih3fQ/zm/2ctt6PcynAACVkxpTAKBggqhkjO
PQQDAgNJADBGAiEA+6v6LGFkoJNIftNag3AigbQA3acDYZ/TbtXuMZAgF08CIQCb
CVjyhJCYGgNONh1c/RzztCXuYguJwWOjNxAx/n+aLA==
-----END CERTIFICATE-----
```



#### 轮转证书

传递`--rotate`选项（以及可选的 `--ca-cert`，连同一个`--ca-key`或 `--external-ca`参数选项），以便轮转当前集群根CA.

```sh
$ docker swarm ca --rotate
desired root digest:
  rotated TLS certificates:
  rotated CA certificates:
desired root digest: sha256:5ba0eaf2ea13378c8ebdf1ae4270f0b613157edd22ce4787f394b4ffd371ddc9
desired root digest: sha256:0e9754f56f57148cdb74730a0ff2da7a6194393c5a244baa744349ddd2b12a76
-----BEGIN CERTIFICATE-----
MIIBazCCARCgAwIBAgIUREpgWF1pBhouuU69P2t5tBnzb/cwCgYIKoZIzj0EAwIw
EzERMA8GA1UEAxMIc3dhcm0tY2EwHhcNMTgwNTA3MDI1ODAwWhcNMzgwNTAyMDI1
ODAwWjATMREwDwYDVQQDEwhzd2FybS1jYTBZMBMGByqGSM49AgEGCCqGSM49AwEH
A0IABCOKEBJDMyRwd6r2dBiMR+hL5PKyXZcD0OwyzqnqGbgHDkS7mNCOmASurVrI
glhfMVFqMsaOvmYX/0rKjePtdXijQjBAMA4GA1UdDwEB/wQEAwIBBjAPBgNVHRMB
Af8EBTADAQH/MB0GA1UdDgQWBBRDdoQTNQbma1hZy3OF3JYdvGlQ5DAKBggqhkjO
PQQDAgNJADBGAiEAyDRC8tOaNqxmaADcNXlj8JqGHFgyMJbDRq+ORCtaIk0CIQDR
er3hEhPf6PRvToBfD7Scy49EpBVkB9OCcNJqENg26g==
-----END CERTIFICATE-----
```

## init 初始化

初始化一个群 。该命令定位的docker引擎成为新创建的单节点集群中的管理节点。 

### 命令参数选项

---

| 选项，简写               | 默认           | 描述                                                         |
| ------------------------ | -------------- | ------------------------------------------------------------ |
| `--advertise-addr`       |                | 广播通知地址（格式：<ip \| interface> [：port]）             |
| `--autolock`             |                | 启用管理器自动锁定（需要解锁密钥才能启动停止的管理器）       |
| `--availability`         | `active`       | 节点的可用性（ “active”\|”pause”\|”drain” ——“活动”\|“暂停”\|“漏”） |
| `--cert-expiry`          | `2160h0m0s`    | 节点证书的有效期（ns \| us \| ms \| s \| m \| h）            |
| `--data-path-addr`       |                | 用于数据路径传输的地址或接口（格式：<ip \| interface>）      |
| `--dispatcher-heartbeat` | `5s`           | 调度心跳周期（ns \| us \| ms \| s \| m \| h）                |
| `--external-ca`          |                | 一个或多个证书签名端点的格式规范                             |
| `--force-new-cluster`    |                | 强制从当前状态创建一个新的群集                               |
| `--listen-addr`          | `0.0.0.0:2377` | 监听地址（格式：<ip \| interface> [：port]）                 |
| `--max-snapshots`        |                | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 要保留的额外Raft快照的数量 |
| `--snapshot-interval`    | `10000`        | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) Raft快照之间的日志条目数 |
| `--task-history-limit`   | `5`            | 任务历史保留限制                                             |

#### `--autolock`

该选项可以使用加密密钥**自动锁定管理节点**。所有管理节点存储的私钥和数据将受到输出中打印的加密密钥的保护，如果没有它，将**无法访问**。因此，为了在重新启动后激活管理器，存储此密钥非常重要。密钥可以传递给`docker swarm unlock`重新激活管理器。自动锁定可以通过运行`docker swarm update --autolock=false`禁用 。在禁用它之后，加密密钥不再需要启动管理器，并且它将在没有用户干预的情况下自行启动。

#### `--cert-expiry`

该选项设置节点证书的**有效期**。

#### `--dispatcher-heartbeat`

该选项设置节点被告知使用的频率作为**报告健康状况**的时间段。

#### `--external-ca`

此选项设置群体使用**外部CA颁发节点**证书。该值采取的形式`protocol=X,url=Y`。值`protocol`指定应使用什么协议将签名请求发送到外部CA. 目前，唯一支持的值是`cfssl`。该URL指定了应该提交签名请求的端点。

#### `--force-new-cluster`

此选项强制作为单个节点管理器重新启动时丢失的管理的一部分的现有节点**不丢失数据**。

#### `--listen-addr`

该节点在此地址上侦听加入集群管理节点数据。默认是在0.0.0.0:2377上进行监听。也可以指定一个网络接口来侦听该接口的地址; 例如`--listen-addr eth0:2377`。

指定端口是可选的。如果该值为IP地址或接口名称，则将使用**默认端口2377**。

#### `--advertise-addr`

该选项指定将**通知给集群的其他成员进行API访问和覆盖网络的地址**。如果未指定，Docker将检查系统是否具有**单个IP地址**，并将该IP地址与侦听端口一起使用（请参阅参考资料`--listen-addr`）。如果系统有多个IP地址，则`--advertise-addr`必须指定该地址， 以便为管理间通信和覆盖网络选择正确的地址。

也可以指定一个网络接口来通告该接口的地址; 例如`--advertise-addr eth0:2377`。

指定端口是可选的。如果该值为IP地址或接口名称，则将使用默认端口2377。

#### `--data-path-addr`

此选项指定**全局范围网络驱动程序**将发布到其他节点的地址，以便到达在此节点上运行的容器。然后使用此参数可以将容器的**数据流量与集群的管理流量分开**。如果未指定，Docker将使用与**广播地址相同的IP地址或接口**。

#### `--task-history-limit`

此选项设置**任务历史保留**限制。

#### `--max-snapshots`

除了当前的**Raft快照**之外，该选项还设置要保留的旧Raft快照的数量。默认情况下，**不保留旧的快照**。该选项可用于**调试**，或用于存储swarm状态的旧快照以实现**灾难恢复**。

#### `--snapshot-interval`

该选项指定在**Raft快照之间允许的日志条目数量**。将其设置为**更高的数字将会减少快照次数**。快照缩小了Raft日志，并允许更高效地将状态转移给新管理节点。但是，经常拍摄快照会带来**性能**成本。

#### `--availability`

该选项指定**节点加入主设备时节点的可用性**。可能的可用性值`active`，`pause`或`drain`。

这个选项在某些情况下很有用。例如，集群可能希望具有**专用管理节点**，这些节点**不用作工作节点**。这可以通过传递`--availability=drain`来实现`docker swarm init`。

### 示例

---

#### 创建集群

```sh
$ docker swarm init --advertise-addr 192.168.99.121
Swarm initialized: current node (bvz81updecsj6wjz393c09vti) is now a manager.
To add a worker to this swarm, run the following command:

    docker swarm join \
    --token SWMTKN-1-3pu6hszjas19xyp7ghgosyx9k8atbfcr8p2is99znpy26u2lkl-1awxwuwd3z9j1z3puu7rcgdbx \
    172.17.0.2:2377

To add a manager to this swarm, run 'docker swarm join-token manager' and follow the instructions.
```

`docker swarm init`生成两个随机令牌，一个工作节点令牌和一个关键节点令牌。当新节点加入到群中时，该节点将根据传递给[集群加入](https://docs.docker.com/engine/reference/commandline/swarm_join/)的令牌作为工作节点或管理节点[加入](https://docs.docker.com/engine/reference/commandline/swarm_join/)。

创建集群后，可以使用[集群连接令牌](https://docs.docker.com/engine/reference/commandline/swarm_join_token/)显示或旋转该 [令牌](https://docs.docker.com/engine/reference/commandline/swarm_join_token/)。

## join 加入

将一个节点加入集群中。根据使用`--token`选项传递的令牌，该节点将作为管理节点或工作节点加入。如果传递管理令牌，则该节点将作为管理节点加入。如果传递工作令牌，则该节点将作为工作节点加入。

### 命令参数选项

---

| 选项，简写         | 默认           | 描述                                                         |
| ------------------ | -------------- | ------------------------------------------------------------ |
| `--advertise-addr` |                | 通知地址（格式：<ip \| interface> [：port]）                 |
| `--availability`   | `active`       | 节点的可用性（“活动”\|“暂停”\|“漏”— “active”\|”pause”\|”drain” ） |
| `--data-path-addr` |                | 用于数据路径传输的地址或接口（格式：<ip \| interface>）      |
| `--listen-addr`    | `0.0.0.0:2377` | 监听地址（格式：<ip \| interface> [：port]）                 |
| `--token`          |                | 进入集群的令牌                                               |

### `--listen-addr value`

如果该节点是管理，它将监听此地址上的入站群管理器流量。默认是在0.0.0.0:2377上进行监听。也可以指定一个网络接口来侦听该接口的地址; 例如`--listen-addr eth0:2377`。

指定端口是可选的。如果该值为裸IP地址或接口名称，则将使用默认端口2377。

加入现有群体时，此选项通常不是必需的。

### `--advertise-addr value`

此选项指定将通告给集群的其他成员进行API访问的地址。如果未指定，Docker将检查系统是否具有单个IP地址，并将该IP地址与侦听端口一起使用（请参阅参考资料 `--listen-addr`）。如果系统有多个IP地址，则`--advertise-addr` 必须指定该地址，以便为管理间通信和覆盖网络选择正确的地址。

也可以指定一个网络接口来通告该接口的地址; 例如`--advertise-addr eth0:2377`。

指定端口是可选的。如果该值为裸IP地址或接口名称，则将使用默认端口2377。

加入现有群体时，此选项通常不是必需的。如果你通过负载平衡器加入新节点，则应使用此选项来确保节点通告其IP地址，而不是负载平衡器的IP地址。

### `--data-path-addr`

此选项指定全局范围网络驱动程序将发布到其他节点的地址，以便到达在此节点上运行的容器。然后使用此参数可以将容器的数据流量与集群的管理流量分开。如果未指定，Docker将使用与广告地址相同的IP地址或接口。

### `--token string`

节点加入群体所需的秘密值

### `--availability`

该选项指定节点加入主设备时节点的可用性。可能的可用性值`active`，`pause`或`drain`。

这个选项在某些情况下很有用。例如，集群可能希望具有专用管理器节点，这些节点不用作工作者节点。这可以通过传递`--availability=drain`来实现`docker swarm join`。

 ### 示例

---

#### 加入管理节点

下面的示例演示了如何使用管理器令牌来加入管理节点。

```sh
$ docker swarm join --token SWMTKN-1-3pu6hszjas19xyp7ghgosyx9k8atbfcr8p2is99znpy26u2lkl-7p73s1dx5in4tatdymyhg9hu2 192.168.99.121:2377
This node joined a swarm as a manager.
$ docker node ls
ID                           HOSTNAME  STATUS  AVAILABILITY  MANAGER STATUS
dkp8vy1dq1kxleu9g4u78tlag *  manager2  Ready   Active        Reachable
dvfxp4zseq4s0rih1selh0d20    manager1  Ready   Active        Leader
```

一个集群最多只能有**3-7个管理节点**，因为大多数管理节点必须可以使集群发挥作用。不打算参与此管理法定人数的节点应该以工作节点身份加入。管理员应该是具有**静态IP地址的稳定主机**。

#### 加入工作节点

下面的示例演示如何使用工作者令牌来加入工作节点。

```sh
$ docker swarm join --token SWMTKN-1-3pu6hszjas19xyp7ghgosyx9k8atbfcr8p2is99znpy26u2lkl-1awxwuwd3z9j1z3puu7rcgdbx 192.168.99.121:2377
This node joined a swarm as a worker.
$ docker node ls
ID                           HOSTNAME  STATUS  AVAILABILITY  MANAGER STATUS
7ln70fl22uw2dvjn2ft53m3q5    worker2   Ready   Active
dkp8vy1dq1kxleu9g4u78tlag    worker1   Ready   Active        Reachable
dvfxp4zseq4s0rih1selh0d20 *  manager1  Ready   Active        Leader
```

## join-token 令牌

管理加入令牌

### 命令参数选项

---

```sh
$ docker swarm join-token -h
Usage:  docker swarm join-token [OPTIONS] (worker|manager)

管理加入令牌

Options:
  -q, --quiet    # 只显示标记
      --rotate   # 轮转连接令牌
```



### 示例

---

#### 获取加入工作节点的token
```sh
$ docker swarm join-token worker
To add a worker to this swarm, run the following command:

    docker swarm join --token SWMTKN-1-0d3bbbyzap5snxrtfdlabfjkaeateg39qzcurj9xgtdnmu7r06-9ry3p245yzfpoyx8qekpanre3 192.168.99.100:2377
```

#### 获取加入管理节点的token
```sh
$ docker swarm join-token manager
To add a manager to this swarm, run the following command:

    docker swarm join --token SWMTKN-1-0d3bbbyzap5snxrtfdlabfjkaeateg39qzcurj9xgtdnmu7r06-9qz1lxu17zx9ztajfza6hyv1z 192.168.99.100:2377
```

#### 查看token
```sh
$ docker swarm join-token manager -q
SWMTKN-1-0d3bbbyzap5snxrtfdlabfjkaeateg39qzcurj9xgtdnmu7r06-9qz1lxu17zx9ztajfza6hyv1z
```

#### 轮转
```sh
$ docker swarm join-token manager -q --rotate
SWMTKN-1-0d3bbbyzap5snxrtfdlabfjkaeateg39qzcurj9xgtdnmu7r06-d7cbnxkkru5p9wh3qxzfrcuwe    
```

## leave 离开

当在工作节点上运行此命令时，该工作节点离开集群。

可以使用`--force`管理器上的选项将其从群中删除。但是，这不会重新配置群体以确保有足够的管理节点维护群体中的法定人数。从群体中删除管理的安全方法是将其**降级为工作节点**，然后指定离开法定人数而不使用`--force`。仅在管理节点离开后不再使用集群的情况下使用，例如在单节点群中。

### 命令参数选项

---

| 选项，简写     | 默认 | 描述                         |
| -------------- | ---- | ---------------------------- |
| `--force , -f` |      | 强制此节点离开群集，忽略警告 |

### 示例

---

从管理节点查看集群节点：

```sh
$ docker node ls
ID                           HOSTNAME  STATUS  AVAILABILITY  MANAGER STATUS
7ln70fl22uw2dvjn2ft53m3q5    worker2   Ready   Active
dkp8vy1dq1kxleu9g4u78tlag    worker1   Ready   Active
dvfxp4zseq4s0rih1selh0d20 *  manager1  Ready   Active        Leader
```

要删除`worker2`，请从其`worker2`节点上执行以下命令：

```sh
$ docker swarm leave
Node left the default swarm.
```

该节点仍将出现在节点列表中，并标记为`down`。它不再影响群体操作，但是一长串`down`节点可能会混淆节点列表。要从列表中删除非活动节点，请使用该[`node rm`](https://docs.docker.com/engine/reference/commandline/node_rm/) 命令。

## unlock 解锁

使用用户提供的解锁密钥**解锁锁定的管理节点**。如果**自动锁定**设置处于打开状态，则在Docker守护程序重新启动后，必须使用此命令**重新激活**管理节点。解锁键在自动锁定启用时打印，也可从`docker swarm unlock-key`命令中使用。 

```sh
$ docker swarm unlock
Please enter unlock key:
```

## unlock-key 解锁秘钥

管理解锁密钥

 ### 命令参数选项

---

| 选项，简写     | 默认 | 描述       |
| -------------- | ---- | ---------- |
| `--quiet , -q` |      | 只显示令牌 |
| `--rotate`     |      | 旋转解锁键 |

### 示例

---

```sh
$ docker swarm unlock-key
To unlock a swarm manager after it restarts, run the `docker swarm unlock`
command and provide the following key:

    SWMKEY-1-ubaYsVMAc50QnKA0RWOOxOFkzye9Bp9U29Vz9LiQR0M

Please remember to store this key in a password manager, since without it you
will not be able to restart the manager.
```

## update 更新

用新的参数值更新群。该命令必须以**管理节点**为目标。

 ### 命令参数选项

---

| 名字，简写               | 默认        | 描述                                                         |
| ------------------------ | ----------- | ------------------------------------------------------------ |
| `--autolock`             |             | 更改管理自动锁定设置（true \| false）                        |
| `--cert-expiry`          | `2160h0m0s` | 节点证书的有效期（ns \| us \| ms \| s \| m \| h）            |
| `--dispatcher-heartbeat` | `5s`        | 调度心跳周期（ns \| us \| ms \| s \| m \| h）                |
| `--external-ca`          |             | 一个或多个证书签名端点的规范格式                             |
| `--max-snapshots`        |             | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 要保留的额外Raft快照的数量 |
| `--snapshot-interval`    | `10000`     | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) Raft快照之间的日志条目数 |
| `--task-history-limit`   | `5`         | 任务历史保留限制                                             |

### 示例

---

```sh
$ docker swarm update --cert-expiry 720h
# 自动锁定集群
$ docker swarm update --autolock=false
$ docker swarm update --autolock=true
```

# docker node 基本命令

```sh
$ docker node -h
Usage:  docker node COMMAND

管理集群节点

Commands:
  demote      # 从集群中的管理节点中降级一个或多个节点
  inspect     # 在一个或多个节点上显示详细信息
  ls          # 集群节点列表
  promote     # 将一个或多个节点提升为群中的管理节点
  ps          # 列出在一个或多个节点上运行的任务，默认为当前节点
  rm          # 从群中删除一个或多个节点
  update      # 更新节点

```

## demote 降级

降级现有管理节点，使其不再是管理角色。

 ```sh
$ docker node demote my-vm-node-1
 ```

## promote 升级

将节点提升为管理。

 ```sh
$ docker node promote my-vm-node-1
 ```
## inspect 检查

返回有关节点的信息。默认情况下，该命令将所有结果呈现在JSON数组中。可以指定一个替代格式来为每个结果执行给定的模板。Go的 [文本/模板](http://golang.org/pkg/text/template/)包描述了格式的所有细节。

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                       |
| --------------- | ---- | -------------------------- |
| `--format , -f` |      | 使用给定的Go模板格式化输出 |
| `--pretty`      |      | 以人性化的格式打印信息     |

### 示例

---

```sh
$ docker node inspect swarm-manager
$ docker node inspect --format '{{ .ManagerStatus.Leader }}' node-1
$ docker node inspect --pretty node-1
```

## ls 列表

列出Docker Swarm管理知道的所有节点。你可以使用`-f`或`--filter`选项进行过滤。有关可用过滤器选项的更多信息，请参阅[过滤](https://docs.docker.com/engine/reference/commandline/node_ls/#filtering)部分。

 ### 命令参数选项

---

| 名字，简写      | 默认 | 描述                     |
| --------------- | ---- | ------------------------ |
| `--filter , -f` |      | 根据提供的条件过滤输出   |
| `--format`      |      | 使用Go模板的漂亮打印节点 |
| `--quiet , -q`  |      | 只显示ID                 |

### 示例

---

#### 查看节点

```sh
$ docker node ls
ID                           HOSTNAME        STATUS  AVAILABILITY  MANAGER STATUS
1bcef6utixb0l0ca7gxuivsj0    swarm-worker2   Ready   Active
38ciaotwjuritcdtn9npbnkuz    swarm-worker1   Ready   Active
e216jshn25ckzbvmwlnh5jr3g *  swarm-manager1  Ready   Active        Leader
```

> **注意**：在上面的示例输出中，有一个隐藏列`.Self`，指示该节点是否与当前docker守护进程相同。 `*`（例如，`e216jshn25ckzbvmwlnh5jr3g *`）表示这个节点是当前的docker守护进程。

#### 过滤

过滤选项（`-f`或`--filter`）格式为“key = value”。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- [id](https://docs.docker.com/engine/reference/commandline/node_ls/#id)
- [label](https://docs.docker.com/engine/reference/commandline/node_ls/#label)
- [membership](https://docs.docker.com/engine/reference/commandline/node_ls/#membership)
- [name](https://docs.docker.com/engine/reference/commandline/node_ls/#name)
- [role](https://docs.docker.com/engine/reference/commandline/node_ls/#role)

```sh
$ docker node ls -f id=1
# 标签与节点进行匹配
$ docker node ls -f "label=foo"
# membership过滤器相匹配的基础上一个存在的节点membership和一个值 accepted或pending。
$ docker node ls -f "membership=accepted"
# 将名称等于swarm-master字符串的节点进行匹配
$ docker node ls -f name=swarm-manager1
# 过滤器相匹配的基础上一个存在的节点role和一个值worker或manager
$ docker node ls -f "role=manager"
```

#### 格式化

格式化选项（`--format`）使用Go模板漂亮地打印节点输出。下面列出了Go模板的有效占位符：

| 占位符           | 描述                                                         |
| ---------------- | ------------------------------------------------------------ |
| `.ID`            | 节点ID                                                       |
| `.Self`          | 守护进程的节点（`true/false`，`true`表示该节点与当前的docker守护进程相同） |
| `.Hostname`      | 节点主机名                                                   |
| `.Status`        | 节点状态                                                     |
| `.Availability`  | 节点可用性（“活动”，“暂停”或“漏” -- “active”, “pause”, or “drain” ） |
| `.ManagerStatus` | 节点的管理器状态                                             |
| `.TLSStatus`     | 节点的TLS状态（“准备就绪”或“需要轮换”具有由旧CA签署的TLS证书） |
| `.EngineVersion` | 引擎版本                                                     |

使用该`--format`选项时，该`node ls`命令将按照模板声明输出数据，或者在使用该 `table`指令时也包含列标题。

下面的示例使用的模板没有报头，并输出 `ID`，`Hostname`和`TLS Status`通过对所有节点冒号分隔的条目：

```sh
$ docker node ls --format "{{.ID}}: {{.Hostname}} {{.TLSStatus}}"
e216jshn25ckzbvmwlnh5jr3g: swarm-manager1 Ready
35o6tiywb700jesrt3dmllaza: swarm-worker1 Needs Rotation  
$ docker node ls --format "table {{.ID}}: {{.Hostname}} {{.TLSStatus}}"
```

## ps 查看任务

列出Docker 发现的节点上的所有任务。可以使用`-f`或`--filter`选项进行过滤。有关可用过滤器选项的更多信息，请参阅[过滤](https://docs.docker.com/engine/reference/commandline/node_ps/#filtering)部分。

 ### 命令参数选项

---

| 选项，简写      | 默认 | 描述                     |
| --------------- | ---- | ------------------------ |
| `--filter , -f` |      | 根据提供的条件过滤输出   |
| `--format`      |      | 使用Go模板的漂亮打印任务 |
| `--no-resolve`  |      | 不要将ID映射到名称       |
| `--no-trunc`    |      | 不要截断输出             |
| `--quiet , -q`  |      | 只显示任务ID             |

### 示例

---

#### 查看任务

```sh
$ docker node ps swarm-manager1
NAME                                IMAGE        NODE            DESIRED STATE  CURRENT STATE
redis.1.7q92v0nr1hcgts2amcjyqg3pq   redis:3.0.6  swarm-manager1  Running        Running 5 hours
```

#### 过滤

过滤选项（`-f`或`--filter`）格式为“key = value”。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- [name](https://docs.docker.com/engine/reference/commandline/node_ps/#name)
- [id](https://docs.docker.com/engine/reference/commandline/node_ps/#id)
- [label](https://docs.docker.com/engine/reference/commandline/node_ps/#label)
- [desired-state](https://docs.docker.com/engine/reference/commandline/node_ps/#desired-state)

```sh
# 任务名称的全部或部分匹配
$ docker node ps -f name=redis swarm-manager1
# 过滤器匹配任务的ID
$ docker node ps -f id=bg8c07zzg87di2mufeq51a2qp swarm-manager1
# 标签匹配
$ docker node ps -f "label=usage"
# 该desired-state过滤器可以取值running，shutdown，或accepted。
$ docker node ps -f desired-state=running node1
```

## rm 删除

从管理器节点运行时，从群中删除指定的节点。

### 命令参数选项

---

| 选项，简写     | 默认 | 描述                   |
| -------------- | ---- | ---------------------- |
| `--force , -f` |      | 强制从群中删除一个节点 |

### 示例

---

#### 删除停止节点

```sh
$ docker node rm swarm-node-02
Node swarm-node-02 removed from swarm
```

#### 删除运行节点

从群中删除指定的节点，但只有当节点处于停机状态时才会这样。如果**尝试删除活动节点，将收到错误消息**：

```sh
$ docker node rm swarm-node-03
Error response from daemon: rpc error: code = 9 desc = node swarm-node-03 is not
down and can't be removed

$ docker node rm swarm-node-03 -f
```

#### 强行删除不可访问的节点

如果**失去对工作节点的访问权限或需要将其关闭**，因为它已被破坏或行为不如预期，则可以使用`--force`选项。这可能会导致*暂时错误或中断**，具体取决于节点上正在运行的任务的类型。

```sh
$ docker node rm --force swarm-node-03
Node swarm-node-03 removed from swarm
```

管理员节点**必须先降级到工作节点**（使用`docker node demote`），然后才能将其从集群中删除。

## update 更新

更新有关节点的元数据，例如其可用性，标签或角色。

### 命令参数选项

---

| 选项，简写       | 默认 | 描述                                 |
| ---------------- | ---- | ------------------------------------ |
| `--availability` |      | 节点的可用性（“活动”\|“暂停”\|“漏”） |
| `--label-add`    |      | 添加或更新节点标签（key = value）    |
| `--label-rm`     |      | 删除节点标签（如果存在）             |
| `--role`         |      | 节点的角色（“worker”\|“manager”）    |

### 示例

---

使用节点标签将元数据添加到swarm节点。你可以将节点标签指定为具有空值的键：

```sh
$ docker node update --label-add foo worker1
```

要将多个标签添加到节点，请`--label-add`为每个标签传递选项：

```sh
$ docker node update --label-add foo --label-add bar worker1
```

在[创建服务时](https://docs.docker.com/engine/reference/commandline/service_create/)，可以将节点标签用作约束。约束限制调度程序为服务部署任务的节点。

例如，要添加`type`标签以标识调度程序应该部署消息队列服务任务的节点：

```sh
$ docker node update --label-add type=queue worker1
```

为节点设置的标签`docker node update`仅适用于群内的节点实体。

# docker service 基本命令

```sh
$ docker service -h
Usage:  docker service COMMAND

服务管理

Commands:
  create      # 创建一个新服务
  inspect     # 检查服务查看详细信息
  logs        # 获取服务或任务的日志
  ls          # 服务列表
  ps          # 列出一项或多项服务的任务
  rm          # 删除一项或多项服务
  rollback    # 将更改还原为服务的配置
  scale       # 扩展一个或多个复制服务
  update      # 更新服务
```

## create 创建

按照指定的参数描述创建服务。必须在管理节点上运行此命令。

### 命令参数选项

---

| 选项，简写                     | 默认         | 描述                                                         |
| ------------------------------ | ------------ | ------------------------------------------------------------ |
| `--config`                     |              | [API 1.30+](https://docs.docker.com/engine/api/v1.30/) 指定配置以暴露给服务 |
| `--constraint`                 |              | 约束                                                         |
| `--container-label`            |              | 容器标签                                                     |
| `--credential-spec`            |              | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 托管服务帐户的凭证规范（仅限Windows） |
| `--detach , -d`                |              | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 立即退出，而不是等待服务收敛 |
| `--dns`                        |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 设置自定义DNS服务器 |
| `--dns-option`                 |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 设置DNS选项 |
| `--dns-search`                 |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 设置自定义DNS搜索域 |
| `--endpoint-mode`              | `vip`        | 端点模式（vip或dnsrr）                                       |
| `--entrypoint`                 |              | 覆盖图像的默认入口点                                         |
| `--env , -e`                   |              | 设置环境变量                                                 |
| `--env-file`                   |              | 读入环境变量文件                                             |
| `--generic-resource`           |              | 用户定义的资源                                               |
| `--group`                      |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 为容器设置一个或多个补充用户组 |
| `--health-cmd`                 |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 运行以检查运行状况的命令 |
| `--health-interval`            |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 运行检查之间的时间（ms \| s \| m \| h） |
| `--health-retries`             |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 需要报告不健康的连续失败 |
| `--health-start-period`        |              | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 在重新计数到不稳定（ms \| s \| m \| h）之前，容器要初始化的起始周期 |
| `--health-timeout`             |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 允许一次检查运行的最大时间（ms \| s \| m \| h） |
| `--host`                       |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 设置一个或多个自定义主机到IP映射（主机：IP） |
| `--hostname`                   |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 容器主机名 |
| `--isolation`                  |              | [API 1.35+](https://docs.docker.com/engine/api/v1.35/) 服务容器隔离模式 |
| `--label , -l`                 |              | 服务标签                                                     |
| `--limit-cpu`                  |              | 限制CPU                                                      |
| `--limit-memory`               |              | 限制内存                                                     |
| `--log-driver`                 |              | 记录驱动程序的服务                                           |
| `--log-opt`                    |              | 记录驱动程序选项                                             |
| `--mode`                       | `replicated` | 服务模式（复制或全局）                                       |
| `--mount`                      |              | 将文件系统挂载附加到服务                                     |
| `--name`                       |              | 服务名称                                                     |
| `--network`                    |              | 网络附件                                                     |
| `--no-healthcheck`             |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 禁用任何容器指定的HEALTHCHECK |
| `--no-resolve-image`           |              | [API 1.30+](https://docs.docker.com/engine/api/v1.30/) 不要查询注册表以解析图像摘要和支持的平台 |
| `--placement-pref`             |              | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 添加分布位置偏好设置 |
| `--publish , -p`               |              | 将端口发布为节点端口                                         |
| `--quiet , -q`                 |              | 抑制进度输出                                                 |
| `--read-only`                  |              | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 将容器的根文件系统挂载为只读 |
| `--replicas`                   |              | 任务数量                                                     |
| `--reserve-cpu`                |              | 预留CPU                                                      |
| `--reserve-memory`             |              | 保留内存                                                     |
| `--restart-condition`          |              | 满足条件时重新启动（“none”\|“on-failure”\|“any”）（默认为“any”） |
| `--restart-delay`              |              | 重启尝试之间的延迟（ns \| us \| ms \| s \| m \| h）（默认5秒） |
| `--restart-max-attempts`       |              | 放弃前的最大重启次数                                         |
| `--restart-window`             |              | 用于评估重新启动策略的窗口（ns \| us \| ms \| s \| m \| h）  |
| `--rollback-delay`             |              | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 任务回滚之间的延迟（ns \| us \| ms \| s \| m \| h）（默认为0） |
| `--rollback-failure-action`    |              | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 回滚失败的操作（“暂停”\|“继续”）（默认“暂停”） |
| `--rollback-max-failure-ratio` |              | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 在回滚期间容忍的失败率（默认0） |
| `--rollback-monitor`           |              | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 每个任务回滚之后监视失败的持续时间（ns \| us \| ms \| s \| m \| h）（默认5秒） |
| `--rollback-order`             |              | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 回滚顺序（“start-first”\|“stop-first”）（默认为“stop-first”） |
| `--rollback-parallelism`       | `1`          | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 同时回滚的最大任务数量（0一次全部回滚） |
| `--secret`                     |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 指定泄露给服务的秘密 |
| `--stop-grace-period`          |              | 强制杀死一个容器之前等待的时间（ns \| us \| ms \| s \| m \| h）（默认10秒） |
| `--stop-signal`                |              | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 停止容器的信号 |
| `--tty , -t`                   |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 分配伪TTY |
| `--update-delay`               |              | 更新之间的延迟（ns \| us \| ms \| s \| m \| h）（默认为0）   |
| `--update-failure-action`      |              | 更新失败的操作（“暂停”\|“继续”\|“回滚”）（默认“暂停”）       |
| `--update-max-failure-ratio`   |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 更新期间[允许的](https://docs.docker.com/engine/api/v1.25/)失败率（默认值为0） |
| `--update-monitor`             |              | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 每次任务更新后监视失败的持续时间（ns \| us \| ms \| s \| m \| h）（默认5秒） |
| `--update-order`               |              | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 更新顺序（“start-first”\|“stop-first”）（默认为“stop-first”） |
| `--update-parallelism`         | `1`          | 同时更新的最大任务数（0个一次全部更新）                      |
| `--user , -u`                  |              | 用户名或UID（格式：<name \| uid> [：<group \| gid>]）        |
| `--with-registry-auth`         |              | 向注册代理发送注册表认证详细信息                             |
| `--workdir , -w`               |              | 容器内的工作目录                                             |

### 示例

---

#### 创建服务

---

```sh
$ docker service create --name redis redis:3.0.6
dmu1ept4cxcfe8k8lhtux3ro3

$ docker service create --mode global --name redis2 redis:3.0.6
a8q9dasaafudfs8q8w32udass

$ docker service ls
ID            NAME    MODE        REPLICAS  IMAGE
dmu1ept4cxcf  redis   replicated  1/1       redis:3.0.6
a8q9dasaafud  redis2  global      1/1       redis:3.0.6
```

#### 使用私人注册表中的镜像创建服务

---

如果镜像在需要登录的私人注册表中可用，请在登录后使用该 `--with-registry-auth`选项`docker service create`。如果镜像存储在`registry.example.com`哪个私有注册表中，请使用类似以下的命令：

```sh
$ docker login registry.example.com
$ winpty docker login -u xxx registry.cn-hangzhou.aliyuncs.com
$ docker login --username=xxx -p xxxx registry.cn-hangzhou.aliyuncs.com

$ docker service  create \
  --with-registry-auth \
  --name my_service \
  registry.cn-hangzhou.aliyuncs.com/acme/my_image:latest
```

这使用加密的WAL日志将登录令牌从本地客户端传递到部署服务的集群节点。有了这些信息，这些节点就能够登录到注册表并提取镜像。

#### 创建5个副本任务的服务

---

使用`--replicas`选项设置复制服务的副本任务数量。以下命令`redis`使用`5`副本任务创建服务：

```sh
$ docker service create --name redis --replicas=5 redis:latest
4cdgfyky7ozwh3htjfw0d12qv
```

以上命令为服务设置了**所需**的任务数量。即使该命令立即返回，但服务的实际伸缩可能需要一些时间。`REPLICAS`列显示服务的**实际**和**期望**数量的副本任务。

在以下示例中，所需的状态是 `5`副本，但当前的`RUNNING`任务数是`3`：

```sh
$ docker service ls
ID            NAME   MODE        REPLICAS  IMAGE
4cdgfyky7ozw  redis  replicated  3/5       redis:3.0.7
```

一旦创建了所有任务并且`RUNNING`**实际的任务数量等于所需的数量**：

```sh
$ docker service ls
ID            NAME   MODE        REPLICAS  IMAGE
4cdgfyky7ozw  redis  replicated  5/5       redis:3.0.7
```

#### 创建私密服务

---

使用`--secret`选项可以让容器访问 [私密](https://docs.docker.com/engine/reference/commandline/secret_create/)。

创建一个指定私密的服务：

```sh
$ docker service create --name redis --secret secret.json redis:latest
4cdgfyky7ozwh3htjfw0d12qv
```

创建一个指定秘密、目标、用户/组ID和模式的服务：

```sh
$ docker service create --name redis \
    --secret source=ssh-key,target=ssh \
    --secret source=app-key,target=app,uid=1000,gid=1001,mode=0400 \
    redis:latest

4cdgfyky7ozwh3htjfw0d12qv
```

授予服务访问多个秘密，使用多个`--secret`选项。

秘密位于`/run/secrets`容器中。如果未指定目标，则秘密的名称将用作容器中的内存文件。如果指定了目标，那将是文件名。在上面的例子中，将创建两个文件：`/run/secrets/ssh`以及 `/run/secrets/app`指定的每个秘密目标。

#### 使用滚动更新策略创建服务

---

```sh
$ docker service create \
  --replicas 10 \
  --name redis \
  --update-delay 10s \
  --update-parallelism 2 \
  redis:latest
```

当运行[服务更新时](https://docs.docker.com/engine/reference/commandline/service_update/)，调度程序一次最多更新2个任务，并在`10s`更新之间更新。有关更多信息，请参阅[滚动更新教程](https://docs.docker.com/engine/swarm/swarm-tutorial/rolling-update/)。

#### 设置环境变量

---

这为服务中的所有任务设置了一个环境变量。例如：

```sh
$ docker service create \
  --name redis_2 \
  --replicas 5 \
  --env MYVAR=foo \
  redis:latest
```

要指定多个环境变量，请指定多个`--env`选项，每个选项都有一个单独的键 - 值对。

```sh
$ docker service create \
  --name redis_2 \
  --replicas 5 \
  --env MYVAR=foo \
  --env MYVAR2=bar \
  redis:latest
```

查看环境变量

```sh
$ docker service inspect redis_2 --format "{{json .Spec.TaskTemplate.ContainerSpec.Env}}"
["MYVAR=foo","MYVAR2=bar"]
```

#### 创建具有特定主机名的服务

---

此选项将docker服务容器主机名设置为特定的字符串。例如：

```sh
$ docker service create --name redis --hostname myredis redis:latest
```

#### 在服务上设置元数据

---

标签是`key=value`将元数据应用于服务的一对。用两个标签标记服务：

```sh
$ docker service create \
  --name redis_2 \
  --label com.example.foo="bar"
  --label bar=baz \
  redis:latest
```

#### 添加挂载，卷或内存文件系统

---

Docker支持三种不同的挂载方式，它们允许容器在主机操作系统或内存文件系统上读取或写入文件或目录。这些类型是**数据卷**（通常简称为卷），**绑定挂载**和**tmpfs**。

**绑定挂载**使可被挂载在容器内的主机上的文件或目录。绑定挂载可以是**只读的或读写**的。例如，容器可能通过主机的绑定挂载来**共享主机的DNS信息**，`/etc/resolv.conf`或者容器可能会将日志写入其主机的`/var/log/myContainerLogs`目录。如果使用绑定挂载并且主机和容器具有不同的权限，访问控制或其他此类详细信息，则会遇到**可移植性**问题。

**卷是一种机制**，用于将容器所需的持久性数据与用于创建容器的镜像和主机分离。命名卷由Docker创建和管理，即使当前没有容器正在使用它，命名卷仍然存在。命名卷中的数据可以在容器和主机之间共享，也可以在多个容器之间共享。Docker使用*卷驱动*来创建，管理和安装卷。你可以使用Docker命令备份或恢复卷。

**tmpfs**在容器内安装tmpfs以获取易失性数据。

考虑一下你的镜像启动一个轻量级web服务器的情况。你可以将该镜像用作基础镜像，复制网站的HTML文件并将其打包到另一个镜像中。每次你的网站更改时，你都需要更新新镜像并重新部署为你的网站提供服务的所有容器。更好的解决方案是将网站存储在每个Web服务器容器启动时附加的命名卷中。要更新网站，只需更新指定的卷。

下表介绍了适用于服务中绑定安装和命名卷的选项：

| 选项                                | 是否必须             | 描述                                                         |
| ----------------------------------- | -------------------- | ------------------------------------------------------------ |
| **types**                           |                      | mount的类型可以是`volume`，`bind`或`tmpfs`。如果没有指定类型，则默认为`volume`。<br/>`volume`：将[托管卷](https://docs.docker.com/engine/reference/commandline/volume_create/) 装入容器。<br/>`bind`：将主机上的目录或文件绑定到容器中。<br/>`tmpfs`：在容器中安装一个tmpfs |
| **src** or **source**               | `type=bind`<br/>必须 | `type = volume`：`src`是指定卷名称的可选方式（例如，`src = my-volume`）。如果指定的**卷不存在，则会自动创建**。如果未指定`src，`则会为该卷指定一个**随机名称**，该名称在**主机上保证是唯一**的，但可能**不是群集范围内唯一**的。随机命名的卷与其容器具有相同的生命周期，并在**容器被销毁时销毁**（这是在` service update `时，或者扩展或重新平衡服务时）<br/>`type = bind`：`src`是必需的，并指定要绑定挂载的文件或目录的绝对路径（例如，`src = / path / on / host /`）。如果文件或目录不存在，则会产生错误。<br/>`type = tmpfs`：`src`不受支持。 |
| **dst** /**destination**/**target** | 是                   | 装入容器内的路径，例如`/some/path/in/container/`。如果路径**不存在**于容器的文件系统中，则引擎会在挂载卷或绑定挂载之前在指定位置**创建**一个目录。 |
| **readonly** or **ro**              |                      | 除非在安装挂载或卷时提供`只读`选项，否则引擎将挂接和卷默认设置为`读写`。<br/> `true`或`1`或没有值：只读。<br/>`false`或`0`：读写。 |
| **consistency** **一致性**          |                      | 挂载的一致性要求<br/>`default`：相当于`consistent`。<br/>`consistent`：完全一致。容器运行时和主机始终保持相同的安装视图。<br/>`cached`：主机的装载视图是权威的。在主机上进行的更新在容器内可见之前可能会有延迟。<br/>`delegated`：容器运行时的挂载视图是权威的。在容器中进行的更新在主机上可见之前可能会有延迟。 |

##### **挂载传播**

挂载传播是指在给定的绑定挂载或命名卷中创建的**挂载**是否可以**传播到该挂载的副本**。考虑一个挂载点`/mnt`，它也被挂载`/tmp`。该状态设置控制是否启用挂载`/tmp/a`也可用`/mnt/a`。每个传播设置都有一个**递归对应点**。在递归的情况下，考虑它`/tmp/a`也被挂载为`/foo`。传播设置控制是否`/mnt/a`和/或`/tmp/a`将存在。

`bind-propagation`选项默认`rprivate`为绑定挂载和卷挂载，并且**只能为绑定挂载**进行配置。换句话说，**命名卷不支持绑定传播**。

- **shared**：原始挂载的子安装会**暴露给副本**挂载，并且副挂载的子挂载也会传播到原始挂载。
- **slave**：类似于共享挂载，但仅限于**一个方向**。如果原始挂载存在一个子挂载，则副本挂载可以看到它。但是，如果副本挂载公开了子挂载，则原始挂载无法看到它。
- **private**：挂载是私有的。其中的子挂载不会暴露给副本挂载，并且副挂载的子挂载不会暴露给原始挂载。
- **rshared**：与共享相同，但传播也扩展到嵌套在任何原始或副本挂载点内的挂载点。
- **rslave**：与之相同`slave`，但传播也扩展到嵌套在任何原始或副本挂载点内的挂载点。
- **rprivate**：默认。与之相同`private`，这意味着原始或副本挂载点内的任何位置都不会以任何方向传播。

有关绑定传播的更多信息，请参阅[共享子树](https://www.kernel.org/doc/Documentation/filesystems/sharedsubtree.txt)的 [Linux内核文档](https://www.kernel.org/doc/Documentation/filesystems/sharedsubtree.txt)。

##### **命名卷的选项**

以下选项只能用于命名卷（`type=volume`）：

| 选项              | 描述                                                         |
| ----------------- | ------------------------------------------------------------ |
| **volume-driver** | 用于卷的卷驱动程序**插件的名称**。如果该卷不存在，则默认为 **local**，以使用本地卷驱动程序创建卷。 |
| **volume-label**  | 创建时应用于卷的一个或多个自定义元数据（“标签”）。<br/>例如， `volume-label = mylabel = hello-world，my-other-label = hello-mars`。<br/>有关标签的更多信息，请参阅 [应用自定义元数据](https://docs.docker.com/engine/userguide/labels-custom-metadata/)。 |
| **volume-nocopy** | 默认情况下，如果您将空卷附加到容器，并且文件或目录已经存在于容器中的安装路径（`dst`）中，则引擎会将这些文件和目录**复制到卷中**，以便主机访问它们。设置`volume-nocopy`以**禁止**将文件从容器的文件系统复制到卷并挂载空卷。 <br/>值是可选的：  <br/> `true` or `1`： 如果您不提供值，则为默认值。禁用复制。<br/> `false` or `0：` 启用复制 |
| **volume-opt**    | 特定于给定卷驱动程序的**选项，将在创建卷时传递给驱动程序**。选项以逗号分隔的键/值对列表形式提供，例如， `volume-opt = some-option = some-value，volume-opt = some-other-option = some-other-value`。<br/>有关给定驱动程序的可用选项，请参阅该驱动程序的文档。 |

##### **TMPFS的选项**

以下选项只能用于`tmpfs mounts`（`type=tmpfs`）;

| 选项           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| **tmpfs-size** | tmpfs的大小，以字节为单位。Linux中默认无限制。               |
| **tmpfs-mode** | tmpfs的八进制文件模式。（例如`“700”`或`“0700”）`。在Linux中默认为`“1777”`。 |

##### **`--MOUNT`和`--VOLUME`的区别**

`--mount`选项支持`docker run`的`-v` 或`--volume`的大多数选项，有一些重要的例外情况：

- `--mount`选项允许你为**每个卷**指定卷驱动程序和卷驱动程序选项，而无需预先创建卷。相反`docker run`允许你使用`--volume-driver`选项来指定由**所有**卷共享的**单个**卷驱动程序。
- `--mount`选项允许你在卷创建之前指定卷的**自定义元数据**（“标签”）。
- 在使用`--mount` `type=bind`时，主机路径必须引用主机上的**现有* *路径。路径将**不会为你创建**，如果路径不存在，服务将**失败**并显示错误。
- `--mount`选项**不允许**你重新标记用于标记的卷`Z`或`z`选项`selinux`。

##### 使用命名卷创建服务

以下示例创建使用命名卷的服务：

```sh
$ docker service create \
  --name my-service \
  --replicas 3 \
  --mount type=volume,source=my-volume,destination=/path/in/container,volume-label="color=red",volume-label="shape=round" \
  nginx:alpine
```

对于服务的每个副本，引擎都会从部署任务的默认（“本地”）卷驱动程序中请求一个名为“my-volume”的卷。如果卷不存在，引擎将创建一个新卷并应用“color”和“shape”标签。

当任务开始时，卷被安装在`/path/in/container/`容器内部。

请注意，默认（“本地”）卷是本地作用域卷驱动程序。这意味着根据部署任务的位置，该任务可以获得名为“my-volume” 的 *新*卷，或与同一服务的其他任务共享相同的“我的卷”。如果容器内运行的软件不是用来处理写入同一位置的并发进程的，则写入单个共享卷的多个容器可能会导致数据损坏。还要考虑到容器可以由Swarm协调器重新调度并部署在不同的节点上。

##### 使用匿名卷创建服务

以下命令使用`/path/in/container`中的匿名卷创建一个具有三个副本的服务：

```sh
$ docker service create \
  --name my-service \
  --replicas 3 \
  --mount type=volume,destination=/path/in/container \
  nginx:alpine
```

在此示例中，没有为卷指定`source`名称（匿名），因此会为每个任务创建一个新卷。这可以确保每个任务都获得自己的卷，并且不会在任务之间共享卷。完成使用任务后，匿名卷将被删除。

##### 使用绑定挂载主机目录创建服务

以下示例`/path/in/container`在支持该服务的容器中绑定一个主机目录：

```sh
$ docker service create \
  --name my-service \
  --mount type=bind,source=/path/on/host,destination=/path/in/container \
  nginx:alpine
```

#### 设置服务模式

---

服务模式确定是**复制**(replicated)服务还是**全局** (global) 服务。复制服务按指定**运行多个任务**，而全局服务在群中的**每个活动节点上运行**。

以下命令创建一个全局服务：

```sh
$ docker service create \
 --name redis_2 \
 --mode global \
 redis:latest
```

#### 指定服务约束

---

可以通过定义**约束表达式**来限制可以**调度任务的节点集合**。多个约束找到满足每个表达式的节点（AND匹配）。约束可以与节点或Docker引擎标签匹配，如下所示：

| 节点属性        | matches            | 示例                                            |
| --------------- | ------------------ | ----------------------------------------------- |
| `node.id`       | 节点ID             | `node.id == 2ivku8v2gvtg4`                      |
| `node.hostname` | 节点主机名         | `node.hostname != node-2`                       |
| `node.role`     | 节点角色           | `node.role == manager`                          |
| `node.labels`   | 用户定义的节点标签 | `node.labels.security == high`                  |
| `engine.labels` | Docker引擎的标签   | `engine.labels.operatingsystem == ubuntu 14.04` |

`engine.labels`适用于Docker Engine标签，例如操作系统、驱动程序等。集群管理员通过使用[`docker node update`](https://docs.docker.com/engine/reference/commandline/node_update/)命令添加`node.labels`用于操作。

例如，以下限制对节点类型标签等于队列的节点执行`redis`服务的任务：

```sh
$ docker service create \
  --name redis_2 \
  --constraint 'node.labels.type == queue' \
  redis:latest
```

#### 指定服务分布选项

---

你可以设置服务，将任务**均匀分配**到不同类别的节点上。在一组数据中心或可用区域上平衡分布任务，下面的例子说明了这一点：

```sh
$ docker service create \
  --replicas 9 \
  --name redis_2 \
  --placement-pref 'spread=node.labels.datacenter' \
  redis:latest
```

这使用带有扩展策略（当前唯一支持的策略）的`--placement-pref`来将**任务均匀分布在`datacenter`节点标签**的值上。在这个例子中，我们假设每个节点都附有一个`datacenter`节点标签。如果群体中的节点之间存在三个不同的标签值，则三分之一的任务将被放置在与每个值相关的节点上。即使有更多的节点具有一个值而不是另一个值，情况也是如此。例如，请考虑以下一组节点：

- 三个节点 `node.labels.datacenter=east`
- 两个节点 `node.labels.datacenter=south`
- 一个节点 `node.labels.datacenter=west`

由于我们正在使用`datacenter`标签的值，并且服务有9个副本，因此每个**数据中心将有3个副本**。有三个节点与该值相关联`east`，因此每个节点将获得为该值保留的三个副本中的一个。有两个节点的值 `south`，这个值的三个副本将在它们之间分配，一个接收两个副本，另一个接收一个副本。最后，`west` 有一个节点将获得所有三个副本保留`west`。

如果某个类别中的节点（例如那些节点 `node.labels.datacenter=south`）由于约束或资源限制而无法处理其公平份额的任务，则可能会将其他任务**分配给其他节点**。

布局首选项支持**引擎标签和节点标签**。上面的示例使用节点标签，因为标签是以引用的 `node.labels.datacenter`。要分布引擎标签的值，请使用 `--placement-pref spread=engine.labels.<labelname>`。

可以向服务添加**多个分布位置**偏好设置。这建立了偏好的层次结构，因此任务首先被划分为一个类别，然后进一步划分为其他类别。这可能有用的一个例子是在数据中心之间公平地分配任务，然后将每个数据中心内的任务分成多个架构。要添加多个分布位置选项，请`--placement-pref`多次指定选项。**顺序非常重要，布置选项将按进行排定决策时的顺序应用**。

以下示例使用多个分布位置选项设置服务。任务首先在各个数据中心上传播，然后在架构上传播（如各个标签所示）：

```sh
$ docker service create \
  --replicas 9 \
  --name redis_2 \
  --placement-pref 'spread=node.labels.datacenter' \
  --placement-pref 'spread=node.labels.rack' \
  redis:latest
```

`docker service update`在更新服务时，`--placement-pref-add` 在所有现有分布位置偏好设置之后追加新的分布位置偏好设置。 `--placement-pref-rm`删除与参数匹配的现有分布位置偏好设置。

#### 将服务附加到现有网络

---

可以使用**覆盖网络连接集群中的一个或多个服务**。首先，在管理器节点上`docker network create`创建一个覆盖网络命令：

```sh
$ docker network create --driver overlay my-network
etjpu59cykrptrgw0z0hk5snf
```

**在集群模式下创建覆盖网络后，所有管理节点都可以访问网络**。当创建服务并通过`--network`选项将**服务附加到覆盖网络**时：

```sh
$ docker service create \
  --replicas 3 \
  --network my-network \
  --name my-web \
  nginx

716thylsndqma81j6kkkb5aus
```

群体将我的网络扩展到运行服务的每个节点。使用[服务发现](https://docs.docker.com/engine/swarm/networking/#use-swarm-mode-service-discovery)功能，相同网络上的容器可以互相访问 。

`--network`允许指定别名和驱动程序选项列表的长格式语法：
`--network name=my-network,alias=web1,driver-opt=field1=value1`

#### 在群外发布服务端口

---

可以使用`--publish` 或 `-p`选项发布服务端口，使其在**集群外部可访问**。`--publish`选项可以采用两种不同类型的参数。短语法版本是下面的，并且允许指定由**冒号分隔**的已发布端口和目标端口。

```sh
$ docker service create --name my_web --replicas 3 --publish 8080:80 nginx
$ docker service create \
  --replicas 3 \
  --network my-network \
  --name my-web \
  --publish 8080:80 \
  nginx
```

长语法版本更容易阅读，并允许指定更多的选项。长格式是首选，使用短格式时**不能指定服务的模式**。以下是对上述相同服务使用长格式的示例：

```sh
$ docker service create --name my_web --replicas 3 --publish published=8080,target=80 nginx
```

可以指定的选项有：

| 选项           | 简短的语法                 | 长的语法                                                  | 描述                                                         |
| -------------- | -------------------------- | --------------------------------------------------------- | ------------------------------------------------------------ |
| 发布和目标端口 | `--publish 8080:80`        | `--publish published=8080,target=80`                      | 容器中的目标端口以及使用路由网格（`ingress`）或主机级网络将其映射到节点上的端口。本表稍后将提供更多选项。键值语法是首选，因为它有点自我记录。 |
| 模式           | 无法使用简短语法进行设置。 | `--publish published = 8080，target = 80，mode = host`    | 用于绑定端口的模式，无论是`ingress`还是`host`。默认为`ingress` 以使用路由网格。 |
| 协议           | `-p 8080：80 / tcp`        | `--publish published = 8080，target = 80，protocol = tcp` | 要使用的协议，`tcp`，`udp`或`sctp`。默认为 `tcp`。要为两种协议绑定端口，请指定`-p`或 `--publish`标志两次。 |

当使用`ingress`模式发布服务端口时，**集群路由网格使服务可以在每个节点上的已发布端口上访问**，而不管该节点上是否存在运行该服务的任务。如果使用`host`模式，**端口仅绑定在运行服务的节点上**，并且节点上的给定端口**只能绑定一次**。只能使用长语法设置发布模式。有关更多信息，请参阅 [使用群模式路由网格](https://docs.docker.com/engine/swarm/ingress/)。

#### 提供托管服务帐户的凭证规格（仅限Windows）

---

此选项仅用于使用Windows容器的服务。在 `--credential-spec`必须在格式`file://<filename>`或`registry://<value-name>`。

使用`file://<filename>`格式时，引用的文件必须存在于`CredentialSpecs`docker数据目录的子目录中，该目录默认为`C:\ProgramData\Docker\`在Windows上。例如，指定`file://spec.json`加载`C:\ProgramData\Docker\CredentialSpecs\spec.json`。

使用该`registry://<value-name>`格式时，将从守护进程主机上的Windows注册表中读取凭据规范。指定的注册表值必须位于：

```
HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Virtualization\Containers\CredentialSpecs
```

#### 使用模板创建服务

---

可以使用`service create`Go的[文本/模板](http://golang.org/pkg/text/template/)软件包提供的语法来为某些选项使用[模板](http://golang.org/pkg/text/template/)。

受支持的选项如下：

- `--hostname`
- `--mount`
- `--env`

下面列出了Go模板的有效占位符：

| 占位符            | 描述       |
| ----------------- | ---------- |
| `.Service.ID`     | 服务ID     |
| `.Service.Name `  | 服务名称   |
| `.Service.Labels` | 服务标签   |
| `.Node.ID`        | 节点ID     |
| `.Node.Hostname`  | 节点主机名 |
| `.Task.ID`        | 任务ID     |
| ` .Task.Name `    | 任务名称   |
| `.Task.Slot`      | 任务槽     |

在本例中，我们将根据服务的名称，节点的ID和主机名称来设置创建的容器的模板。

```sh
$ docker service create \
	--name hosttempl \
	--hostname "{{.Node.Hostname}}-{{.Node.ID}}-{{.Service.Name}}" \
	busybox top

va8ew30grofhjoychbr6iot8c

$ docker service ps va8ew30grofhjoychbr6iot8c
ID            NAME         IMAGE                                                                                   NODE          DESIRED STATE  CURRENT STATE               ERROR  PORTS
wo41w8hg8qan  hosttempl.1  busybox:latest@sha256:29f5d56d12684887bdfa50dcd29fc31eea4aaf4ad3bec43daf19026a7ce69912  2e7a8a9c4da2  Running        Running about a minute ago

$ docker inspect --format="{{.Config.Hostname}}" 2e7a8a9c4da2-wo41w8hg8qanxwjwsg4kxpprj-hosttempl
x3ti0erg11rjpg64m75kej2mz-hosttempl
```

#### 指定隔离模式（Windows）

---

默认情况下，Windows节点上计划任务使用为此特定节点配置的默认隔离模式运行。要**强制使用特定的隔离模式**，可以使用以下`--isolation`选项：

```sh
$ docker service create --name myservice --isolation=process microsoft/nanoserver
```

Windows上支持的隔离模式是：

- `default`：使用运行任务的节点上指定的默认设置
- `process`：使用进程隔离（仅限Windows服务器）
- `hyperv`：使用Hyper-V隔离

#### 创建请求通用资源的服务

---

可以通过使用`--generic-resource`选项来缩小任务可以登陆的节点种类 （如果节点通告这些资源）：

```sh
$ docker service create \
	--name cuda \
	--generic-resource "NVIDIA-GPU=2" \
	--generic-resource "SSD=1" \
	nvidia/cuda
```

## inspect 检查

检查指定的服务。该命令必须在**管理节点**运行。默认情况下，这会将所有结果呈现在JSON数组中。如果指定了格式，则将为每个结果执行给定的模板。Go的[文本/模板](http://golang.org/pkg/text/template/)包描述了格式的所有细节。

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                       |
| --------------- | ---- | -------------------------- |
| `--format , -f` |      | 使用给定的Go模板格式化输出 |
| `--pretty`      |      | 以人性化的格式打印信息     |

### 示例

---

#### 按名称或ID检查服务

可以通过其*名称*或*ID*检查服务。例如，给定以下服务;

```sh
$ docker service ls
ID            NAME   MODE        REPLICAS  IMAGE
dmu1ept4cxcf  redis  replicated  3/3       redis:3.0.6
```

这两种`docker service inspect redis`，而`docker service inspect dmu1ept4cxcf` 产生相同的结果：

```sh
$ docker service inspect redis
$ docker service inspect dmu1ept4cxcf
```

#### 格式化

你可以使用以下`--pretty`选项以可读格式而不是默认JSON输出打印检查输出：

```sh
$ docker service inspect --pretty hosttempl

ID:             sb010fl6e11of0w7o7kqrqhhe
Name:           hosttempl
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
 Image:         busybox:latest@sha256:58ac43b2cc92c687a32c8be6278e50a063579655fe3090125dcb2af0ff9e1a64
 Args:          top
Resources:
Endpoint Mode:  vip
```

也可以使用`--format pretty`相同的效果。

`--format`选项可用于获取有关服务的特定信息。例如，以下命令输出“redis”服务的副本数量。

```sh
$ docker service inspect --format='{{.Spec.Mode.Replicated.Replicas}}' redis
10
```

## logs 日志

查询服务或任务日志信息

### 命令参数选项

---

```sh
$ docker service logs -h
Usage:  docker service logs [OPTIONS] SERVICE|TASK
获取服务或任务的日志

Options:
      --details        # 信息显示提供给日志的额外详细信息
  -f, --follow         # 跟踪日志输出
      --no-resolve     # 不要将ID映射到输出中的名称
      --no-task-ids    # 不在输出中包含任务ID
      --no-trunc       # 不要截断输出
      --raw            # 不要整齐地格式化日志
      --since string   # 显示自日期时间戳以后的日志 (e.g.
                       2013-01-02T13:23:37) or relative (e.g. 42m for 42
                       minutes)
      --tail string    # 日志末尾显示的行数
                       (default "all")
  -t, --timestamps     # 显示时间戳
```



### 示例

---

#### 查看日志

`docker service logs`命令批量**检索执行时**存在的日志。`docker service logs`命令可以与**服务的名称或ID**一起使用，也可以与任务的标识一起使用。如果服务已通过，它将显示服务中**所有容器的日志**。如果任务通过，它将只显示来自该特定任务的日志。

```sh
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
3wgt1b35g4ar        helloworld          replicated          1/1                 alpine:latest
sb010fl6e11o        hosttempl           replicated          1/1                 busybox:latest
s9eh0d2666wu        my-web              replicated          3/3                 nginx:latest        *:8080->80/tcp

$ docker service logs my-web
$ docker service logs s9eh0d2666wu
my-web.2.k027kb6dsgwz@my-vm-node-1    | 10.255.0.2 - - [08/May/2018:07:25:26 +0000] "GET / HTTP/1.1" 200 612 "-" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36" "-"
```

> **注意**：此命令仅适用于使用`json-file`或`journald`日志记录驱动程序启动的服务。

有关选择和配置记录驱动程序的更多信息，请参阅 [配置记录驱动程序](https://docs.docker.com/engine/admin/logging/overview/)。

#### 跟踪日志

`docker service logs --follow`命令将继续流式传输来自服务`STDOUT`和服务的新输出`STDERR`。

```sh
$ docker service logs my-web --follow
```

#### 查看指定行数

传递一个负数或一个非整数`--tail`是无效的，`all`在这种情况下值被设置为。

```sh
$ docker service logs my-web --tail 2
my-web.2.k027kb6dsgwz@my-vm-node-1    | 10.255.0.2 - - [08/May/2018:07:25:26 +0000] "GET /favicon.ico HTTP/1.1" 404 572 "http://192.168.99.100:8080/" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36" "-"
my-web.2.k027kb6dsgwz@my-vm-node-1    | 2018/05/08 07:25:26 [error] 5#5: *1 open() "/usr/share/nginx/html/favicon.ico" failed (2: No such file or directory), client: 10.255.0.2, server: localhost, request: "GET /favicon.ico HTTP/1.1", host: "192.168.99.100:8080", referrer: "http://192.168.99.100:8080/"
```

#### 时间戳

`docker service logs --timestamps`命令将增加一个[RFC3339Nano时间戳](https://golang.org/pkg/time/#pkg-constants) ，例如`2014-09-16T06:17:46.000000000Z`，每个日志记录。为确保时间戳对齐，必要时，时间戳的纳秒部分将填充零。

```sh
$ docker service logs my-web --tail 2 --timestamps
2018-05-08T07:25:26.919177543Z my-web.2.k027kb6dsgwz@my-vm-node-1    | 10.255.0.2 - - [08/May/2018:07:25:26 +0000] "GET /favicon.ico HTTP/1.1" 404 572 "http://192.168.99.100:8080/" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36" "-"
```

#### 额外详细信息

`docker service logs --details`命令将添加额外的属性，例如`--log-opt`创建服务时提供的环境变量和标签。

```sh
$ docker service logs --details my-web
my-web.2.k027kb6dsgwz@my-vm-node-1    |  10.255.0.2 - - [08/May/2018:07:25:26 +0000] "GET / HTTP/1.1" 200 612 "-" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36" "-"
```

#### 日期过滤

`--since`选项仅显示给定日期后生成的服务日志。如果这个应用运行时间过长，比如3天，那么指定日志的开始时间是非常有必要的。可以使用--since，让容器日志只输出指定日期之后的时间。这个时间可以是RFC 3339时间，也可以是UNIX timestamp，你可以结合使用 `--since`选择具有的一种或两种`--follow`或`--tail`选项。例如： 

```sh
# 日期 时间
$ docker service logs --details my-web --since "2018-05-08"
# 毫秒
$ docker service logs --details my-web --since "1441018800"
```

## ls 列表

在以管理员身份运行时列出服务正在集群中运行。

 ### 命令参数选项

---

| 选项，简写      | 默认 | 描述                     |
| --------------- | ---- | ------------------------ |
| `--filter , -f` |      | 根据提供的条件过滤输出   |
| `--format`      |      | 使用Go模板的漂亮打印服务 |
| `--quiet , -q`  |      | 只显示ID                 |

### 示例

---

#### 查看

在管理节点上执行：

```sh
$ docker service ls
ID            NAME      MODE        REPLICAS    IMAGE
c8wgl7q4ndfd  frontend  replicated  5/5         nginx:alpine
dmu1ept4cxcf  redis     replicated  3/3         redis:3.0.6
iwe3278osahj  mongo     global      7/7         mongo:3.3
```

`REPLICAS`列显示服务的*实际*任务数和*所需*任务数。

#### 过滤

过滤选项（`-f`或`--filter`）格式为“key = value”。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- [id](https://docs.docker.com/engine/reference/commandline/service_ls/#id)
- [label](https://docs.docker.com/engine/reference/commandline/service_ls/#label)
- [mode](https://docs.docker.com/engine/reference/commandline/service_ls/#mode)
- [name](https://docs.docker.com/engine/reference/commandline/service_ls/#name)

```sh
# 匹配服务的ID的全部或部分
$ docker service ls -f "id=0bcjw"
# 使用project标签匹配所有服务
$ docker service ls --filter label=project
# 匹配project具有project-a值的服务
$ docker service ls --filter label=project=project-a
# 匹配global服务
$ docker service ls --filter mode=global
# 匹配包含名称的服务redis
$ docker service ls --filter name=redis
```

#### 格式化

格式化选项（`--format`）使用Go模板漂亮地打印服务输出。下面列出了Go模板的有效占位符：

| 占位符      | 描述                   |
| ----------- | ---------------------- |
| `.ID`       | 服务ID                 |
| `.Name`     | 服务名称               |
| `.Mode`     | 服务模式（复制，全局） |
| `.Replicas` | 服务副本               |
| `.Image`    | 服务形象               |
| `.Ports`    | 服务端口以入口模式发布 |

使用`--format`选项时，`service ls`命令将按照模板声明输出数据，或者在使用该 `table`指令时也包含列标题。

下面的示例使用的模板没有报头，并输出 `ID`，`Mode`以及`Replicas`通过所有服务冒号分隔的条目：

```sh
$ docker service ls --format "table {{.ID}}: {{.Mode}} {{.Replicas}}"
$ docker service ls --format "{{.ID}}: {{.Mode}} {{.Replicas}}"
0zmvwuiu3vue: replicated 10/10
fm6uf97exkul: global 5/5
```

## ps 任务列表

列出作为指定服务的一部分运行的任务。该命令必须以管理器节点为目标运行。

 ### 命令参数选项

---

| 选项，简写      | 默认 | 描述                     |
| --------------- | ---- | ------------------------ |
| `--filter , -f` |      | 根据提供的条件过滤输出   |
| `--format`      |      | 使用Go模板的漂亮打印任务 |
| `--no-resolve`  |      | 不要将ID映射到名称       |
| `--no-trunc`    |      | 不要截断输出             |
| `--quiet , -q`  |      | 只显示任务ID             |

### 示例

---

#### 查看任务

以下命令显示了作为`redis`服务一部分的所有任务：

```sh
$ docker service ps redis
ID             NAME      IMAGE        NODE      DESIRED STATE  CURRENT STATE          ERROR  PORTS
0qihejybwf1x   redis.1   redis:3.0.5  manager1  Running        Running 8 seconds
bk658fpbex0d   redis.2   redis:3.0.5  worker2   Running        Running 9 seconds
```

除了**运行**任务外，输出还显示任务**历史记录**。例如，在更新服务使用`redis:3.0.6`镜像之后，输出可能如下所示：

```sh
$ docker service ps redis

ID            NAME         IMAGE        NODE      DESIRED STATE  CURRENT STATE                   ERROR  PORTS
50qe8lfnxaxk  redis.1      redis:3.0.6  manager1  Running        Running 6 seconds ago
ky2re9oz86r9   \_ redis.1  redis:3.0.5  manager1  Shutdown       Shutdown 8 seconds ago
3s46te2nzl4i  redis.2      redis:3.0.6  worker2   Running        Running less than a second ago
nvjljf7rmor4   \_ redis.2  redis:3.0.6  worker2   Shutdown       Rejected 23 seconds ago        "No such image: redis@sha256:6…"
vtiuz2fpc0yb   \_ redis.2  redis:3.0.5  worker2   Shutdown       Shutdown 1 second ago
```

任务历史记录中的项目数由`--task-history-limit`初始化群时设置的选项决定 。你可以使用该[`docker swarm update`](https://docs.docker.com/engine/reference/commandline/swarm_update/)命令更改任务历史保留限制 。 

#### 过滤

过滤选项（`-f`或`--filter`）格式是一`key=value`对。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）。多个过滤器选项被组合为一个`OR`过滤器。例如，`-f name=redis.1 -f name=redis.7`返回两者`redis.1`和`redis.7`任务。

目前支持的过滤器是：

- [id](https://docs.docker.com/engine/reference/commandline/service_ps/#id)
- [name](https://docs.docker.com/engine/reference/commandline/service_ps/#name)
- [node](https://docs.docker.com/engine/reference/commandline/service_ps/#node)
- [desired-state](https://docs.docker.com/engine/reference/commandline/service_ps/#desired-state)

```sh
# 全部或任务的ID的前缀匹配
$ docker service ps -f "id=8" redis
# 任务名称相匹配
$ docker service ps -f "name=redis.1" redis
# 节点名或节点ID相匹配
$ docker service ps -f "node=manager1" redis
#期望的状态 desired-state过滤器可以取值running，shutdown，或accepted
$ docker service ps -f "desired-state=running" redis
```

#### 格式化

格式化选项（`--format`）可以很好地打印使用Go模板输出的任务。下面列出了Go模板的有效占位符：

| 占位符          | 描述                                                  |
| --------------- | ----------------------------------------------------- |
| `.ID`           | 任务ID                                                |
| `.Name`         | 任务名称                                              |
| `.Image`        | 任务图像                                              |
| `.Node`         | 节点ID                                                |
| `.DesiredState` | 任务的理想状态（`running`，`shutdown`，或`accepted`） |
| `.CurrentState` | 任务的当前状态                                        |
| `.Error`        | 错误                                                  |
| `.Ports`        | 任务发布的端口                                        |

使用该`--format`选项时，该`service ps`命令将按照模板声明输出数据，或者在使用该 `table`指令时也包含列标题。

以下示例使用不带标题的模板，并输出 由冒号分隔的所有任务`Name`和`Image`条目：

```sh
$ docker service ps --format "{{.Name}}: {{.Image}}" redis
```

## rm 删除

从集群中删除指定的服务。该命令必须在管理器节点运行。

```sh
$ docker service rm redis
redis
$ docker service rm redis redis2
```

> **警告**：与`docker rm`删除正在运行的服务之前不同，该命令不要求确认。

 ## rollback 回滚

将指定的服务从集群中回滚到其以前的版本。该命令必须以管理节点为目标运行。

 ### 命令参数选项

---

| 选项，简写      | 默认 | 描述                                                         |
| --------------- | ---- | ------------------------------------------------------------ |
| `--detach , -d` |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 立即退出，而不是等待服务 |
| `--quiet , -q`  |      | 抑制进度输出                                                 |

### 示例

---

使用`docker service rollback`命令可以回滚到服务的先前版本。执行此命令后，服务将恢复为最新`docker service update` 命令之前的配置。

以下示例使用单个副本创建服务，更新服务以使用三个副本，然后将服务回滚到具有一个副本的以前版本。

使用单个副本创建服务：

```sh
$ docker service create --name my-service -p 8080:80 nginx:alpine
```

确认服务正在运行一个副本：

```sh
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
xbw728mf6q0d        my-service          replicated          1/1                 nginx:alpine        *:8080->80/tcp
```

更新服务以使用三个副本：

```sh
$ docker service update --replicas=3 my-service
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
xbw728mf6q0d        my-service          replicated          3/3                 nginx:alpine        *:8080->80/tcp
```

现在将服务回滚到其以前的版本，并确认它再次运行单个副本：

```sh
$ docker service rollback my-service
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
xbw728mf6q0d        my-service          replicated          1/1                 nginx:alpine        *:8080->
```

## scale 副本比例

使用scale命令可以将一个或多个复制服务**向上或向下**缩放到所需数量的副本。此命令**不能应用于全局模式**的服务。该命令将立即返回，但服务的实际缩放可能需要一些时间。要停止服务的所有副本，同时保持群中的服务处于活动状态，可以将比例设置为0。

### 示例

---

#### 扩展单个服务

以下命令将`redis`服务缩放为50个任务。

```sh
$ docker service scale redis=50
frontend scaled to 50
```

以下命令尝试将全局服务扩展为10个任务并返回错误。

```sh
$ docker service create --mode global --name my_redis redis
jh7jpnjhfk5ohxefig1wacvxi

$ docker service scale my_redis=10
my_redis: scale can only be used with replicated mode
```

之后直接运行`docker service ls`，查看实际的副本数量。

```sh
$ docker service ls --filter name=my_redis
ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
jh7jpnjhfk5o        my_redis            global              2/2                 redis:latest
```

也可以使用该[`docker service update`](https://docs.docker.com/engine/reference/commandline/service_update/) 命令来缩放服务。以下命令是等效的：

```sh
$ docker service scale my_redis2=50
$ docker service update --replicas=50 my_redis2
```

#### 扩展多个服务

`docker service scale`命令允许一次为**多个服务**设置所需数量的任务。以下示例缩放后端和前端服务：

```sh
$ docker service scale backend=3 frontend=5
backend scaled to 3
frontend scaled to 5

$ docker service ls
ID            NAME      MODE        REPLICAS  IMAGE
3pr5mlvu3fh9  frontend  replicated  5/5       nginx:alpine
74nzcxxjv6fq  backend   replicated  3/3       redis:3.0.6
```

## update 更新

按照指定的参数描述更新服务。该命令必须在管理器节点运行。参数与[`docker service create`](https://docs.docker.com/engine/reference/commandline/service_create/)。相同。请参阅那里的描述以获取更多信息。

通常，更新服务只会**导致服务的任务被替换为新服务**，如果对服务的更改需要重新创建任务才能生效。例如，只更改`--update-parallelism`设置不会重新创建任务，因为单个任务不受此设置的影响。但是`--force`选项将导致任务被重新创建。这可以用来执行滚动重启，而不会对服务参数进行任何更改。

### 命令参数选项

---

| 选项，简写                     | 默认 | 描述                                                         |
| ------------------------------ | ---- | ------------------------------------------------------------ |
| `--args`                       |      | 服务命令参数                                                 |
| `--config-add`                 |      | [API 1.30+](https://docs.docker.com/engine/api/v1.30/) 添加或更新服务上的配置文件 |
| `--config-rm`                  |      | [API 1.30+](https://docs.docker.com/engine/api/v1.30/) 删除配置文件 |
| `--constraint-add`             |      | 添加或更新展示位置约束                                       |
| `--constraint-rm`              |      | 删除约束                                                     |
| `--container-label-add`        |      | 添加或更新容器标签                                           |
| `--container-label-rm`         |      | 用钥匙取出容器标签                                           |
| `--credential-spec`            |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 托管服务帐户的凭证规范（仅限Windows） |
| `--detach , -d`                |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 立即退出，而不是等待服务收敛 |
| `--dns-add`                    |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 添加或更新自定义DNS服务器 |
| `--dns-option-add`             |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 添加或更新DNS选项 |
| `--dns-option-rm`              |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 删除DNS选项 |
| `--dns-rm`                     |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 删除自定义的DNS服务器 |
| `--dns-search-add`             |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 添加或更新自定义DNS搜索域 |
| `--dns-search-rm`              |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 删除DNS搜索域 |
| `--endpoint-mode`              |      | 端点模式（vip或dnsrr）                                       |
| `--entrypoint`                 |      | 覆盖图像的默认入口点                                         |
| `--env-add`                    |      | 添加或更新环境变量                                           |
| `--env-rm`                     |      | 删除一个环境变量                                             |
| `--force`                      |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 强制更新，即使没有更改需要它 |
| `--generic-resource-add`       |      | 添加通用资源                                                 |
| `--generic-resource-rm`        |      | 删除通用资源                                                 |
| `--group-add`                  |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 向容器添加一个附加的补充用户组 |
| `--group-rm`                   |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 从容器中删除先前添加的补充用户组 |
| `--health-cmd`                 |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 运行以检查运行状况的命令 |
| `--health-interval`            |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 运行检查之间的时间（ms \| s \| m \| h） |
| `--health-retries`             |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 需要报告不健康的连续失败 |
| `--health-start-period`        |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 在重新计数到不稳定（ms \| s \| m \| h）之前，容器要初始化的起始周期 |
| `--health-timeout`             |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 允许一次检查运行的最大时间（ms \| s \| m \| h） |
| `--host-add`                   |      | [API 1.32+](https://docs.docker.com/engine/api/v1.32/) 添加自定义的主机到IP映射（主机：IP） |
| `--host-rm`                    |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 删除自定义的主机到IP映射（主机：IP） |
| `--hostname`                   |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 容器主机名 |
| `--image`                      |      | 服务图片标签                                                 |
| `--isolation`                  |      | [API 1.35+](https://docs.docker.com/engine/api/v1.35/) 服务容器隔离模式 |
| `--label-add`                  |      | 添加或更新服务标签                                           |
| `--label-rm`                   |      | 用钥匙去除标签                                               |
| `--limit-cpu`                  |      | 限制CPU                                                      |
| `--limit-memory`               |      | 限制记忆                                                     |
| `--log-driver`                 |      | 记录驱动程序的服务                                           |
| `--log-opt`                    |      | 记录驱动程序选项                                             |
| `--mount-add`                  |      | 添加或更新服务上的装载                                       |
| `--mount-rm`                   |      | 通过目标路径移除一个安装                                     |
| `--network-add`                |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 添加网络 |
| `--network-rm`                 |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 删除网络 |
| `--no-healthcheck`             |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 禁用任何容器指定的HEALTHCHECK |
| `--no-resolve-image`           |      | [API 1.30+](https://docs.docker.com/engine/api/v1.30/) 不要查询注册表以解析图像摘要和支持的平台 |
| `--placement-pref-add`         |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 添加展示位置偏好设置 |
| `--placement-pref-rm`          |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 移除展示位置偏好设置 |
| `--publish-add`                |      | 添加或更新已发布的端口                                       |
| `--publish-rm`                 |      | 通过目标端口删除发布的端口                                   |
| `--quiet , -q`                 |      | 抑制进度输出                                                 |
| `--read-only`                  |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 将容器的根文件系统挂载为只读 |
| `--replicas`                   |      | 任务数量                                                     |
| `--reserve-cpu`                |      | 预留CPU                                                      |
| `--reserve-memory`             |      | 保留内存                                                     |
| `--restart-condition`          |      | 条件满足时重新启动（“none”\|“on-failure”\|“any”）            |
| `--restart-delay`              |      | 重启尝试之间的延迟（ns \| us \| ms \| s \| m \| h）          |
| `--restart-max-attempts`       |      | 放弃前的最大重启次数                                         |
| `--restart-window`             |      | 用于评估重新启动策略的窗口（ns \| us \| ms \| s \| m \| h）  |
| `--rollback`                   |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 回滚到先前的规范 |
| `--rollback-delay`             |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 任务回滚之间的延迟（ns \| us \| ms \| s \| m \| h） |
| `--rollback-failure-action`    |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 回滚失败的操作（“暂停”\|“继续”） |
| `--rollback-max-failure-ratio` |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 在回滚期间容忍的故障率 |
| `--rollback-monitor`           |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 每次任务回滚以监视失败的持续时间（ns \| us \| ms \| s \| m \| h） |
| `--rollback-order`             |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 回滚顺序（“start-first”\|“stop-first”） |
| `--rollback-parallelism`       |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 同时回滚的最大任务数量（0一次全部回滚） |
| `--secret-add`                 |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 添加或更新服务上的秘密 |
| `--secret-rm`                  |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 删除秘密 |
| `--stop-grace-period`          |      | 强制杀死一个容器之前的等待时间（ns \| us \| ms \| s \| m \| h） |
| `--stop-signal`                |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 停止容器的信号 |
| `--tty , -t`                   |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 分配伪TTY |
| `--update-delay`               |      | 更新之间的延迟（ns \| us \| ms \| s \| m \| h）              |
| `--update-failure-action`      |      | 更新失败的操作（“暂停”\|“继续”\|“回滚”）                     |
| `--update-max-failure-ratio`   |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 在更新期间容忍的失败率 |
| `--update-monitor`             |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 每次任务更新后监视失败的持续时间（ns \| us \| ms \| s \| m \| h） |
| `--update-order`               |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 更新顺序（“start-first”\|“stop-first”） |
| `--update-parallelism`         |      | 同时更新的最大任务数（0个一次全部更新）                      |
| `--user , -u`                  |      | 用户名或UID（格式：<name \| uid> [：<group \| gid>]）        |
| `--with-registry-auth`         |      | 向注册代理发送注册表认证详细信息                             |
| `--workdir , -w`               |      | 容器内的工作目录                                             |

### 示例

---

#### 更新服务

```sh
$ docker service update --limit-cpu 2 redis
```

#### 在不更改参数的情况下执行滚动重启

```sh
$ docker service update --force --update-parallelism 1 --update-delay 30s redis
```

在这个例子中，`--force`选项导致服务的任务**被关闭并被新的替换**，即使其他参数通常都不会导致这种情况发生。`--update-parallelism 1`设置确保一次只替换一个任务（这是默认行为）。 `--update-delay 30s`设置在任务之间引入了30秒的延迟，以便滚动重启逐渐发生。

#### 添加或删除挂载

使用`--mount-add`或`--mount-rm`选项添加或删除服务的绑定挂载或卷。

以下示例创建一个将`test-data`卷 挂载到的服务`/somewhere`。下一步更新服务以将`other-volume` 卷挂接到`/somewhere-else`卷，最后一步卸载`/somewhere`挂载点，从而有效地移除`test-data`卷。每个命令都会返回服务名称。

- `--mount-add`选项与`service create`时的`--mount`选项具有相同的参数。
- `--mount-rm`选项采用`target`安装路径。

```sh
$ docker service create \
    --name=myservice \
    --mount \
      type=volume,source=test-data,target=/somewhere \
    nginx:alpine \
    myservice

$ docker service update \
    --mount-add \
      type=volume,source=other-volume,target=/somewhere-else \
    myservice

$ docker service update --mount-rm /somewhere myservice
myservice
```

#### 添加或删除已发布的服务端口

使用`--publish-add`或`--publish-rm`选项添加或删除服务的已发布端口。以下示例将已发布的服务端口添加到现有服务。

```sh
$ docker service update \
  --publish-add published=8080,target=80 \
  myservice
```

#### 添加或删除网络

使用`--network-add`或`--network-rm`选项为服务添加或删除网络。以下示例将新的别名添加到已连接到网络my-network的现有服务：

```sh
$ docker service update \
  --network-rm my-network \
  --network-add name=my-network,alias=web1 \
  myservice
```

#### 回滚到服务的先前版本

使用`--rollback`选项可以回滚到服务的先前版本。这会将服务恢复到最新`docker service update`命令之前的配置。以下示例将服务的副本数从4更新为5，然后回滚到以前的配置。

```sh
$ docker service update --replicas=5 web

$ docker service ls
ID            NAME  MODE        REPLICAS  IMAGE
80bvrzp6vxf3  web   replicated  0/5       nginx:alpine
```

回滚`web`服务...

```sh
# docker service rollback web
$ docker service update --rollback web

$ docker service ls
ID            NAME  MODE        REPLICAS  IMAGE
80bvrzp6vxf3  web   replicated  0/4       nginx:alpine
```

其他选项也可以结合使用`--rollback`，例如，`--update-delay 0s`执行任务之间没有延迟的回滚：

```sh
$ docker service update \
  --rollback \
  --update-delay 0s
  web
```

服务也可以设置为在**更新失败时自动回滚到以前的版本**。要设置自动回滚服务，请使用`--update-failure-action=rollback`。如果成功更新失败的部分任务超过了给定的值，将会触发回滚`--update-max-failure-ratio`。

回滚操作的速率，并行性和其他参数由通过以下选项传递的值确定：

- `--rollback-delay`
- `--rollback-failure-action`
- `--rollback-max-failure-ratio`
- `--rollback-monitor`
- `--rollback-parallelism`

例如，设置的服务`--update-parallelism 1 --rollback-parallelism 3` 将在正常更新期间一次更新一个任务，但在回滚期间，一次会执行3个任务。这些回滚参数在自动回滚和使用手动启动的回滚期间都受到`--rollback`。

#### 添加或删除秘密

使用`--secret-add`或`--secret-rm`选项添加或删除服务的秘密。

以下示例添加一个名为`ssh-2`并删除的秘密`ssh-1`：

```sh
$ docker service update \
    --secret-add source=ssh-2,target=ssh-2 \
    --secret-rm ssh-1 \
    myservice
```

# docker stack 基本命令

```sh
$ docker stack -h
Usage:  docker stack COMMAND
管理堆栈(编排服务)

Commands:
  deploy      # 部署新的堆栈或更新现有的堆栈
  ls          # 列表
  ps          # 列出堆栈中的任务
  rm          # 删除一个或多个堆栈
  services    # 列出堆栈中的服务

```

## deploy 部署

从swarm上的文件`compose`或`dab`文件创建并更新堆栈。该命令必须在管理器节点运行。

### 命令参数选项

---

| 名字，简写             | 默认     | 描述                                                         |
| ---------------------- | -------- | ------------------------------------------------------------ |
| `--bundle-file`        |          | [实验（守护进程）](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)Swarm 路径到分布式应用程序捆绑文件 |
| `--compose-file , -c`  |          | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 编排文件的路径 |
| `--prune`              |          | [API 1.27+](https://docs.docker.com/engine/api/v1.27/)不再被引用的Swarm Prune服务 |
| `--resolve-image`      | `always` | [API 1.30+](https://docs.docker.com/engine/api/v1.30/)Swarm 查询注册表以解析图像摘要和支持的平台（“always”\|“changed”\|“never”） |
| `--with-registry-auth` |          | Swarm 向Swarm代理发送注册表认证详细信息                      |
| `--kubeconfig`         |          | [实验（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes配置文件 |
| `--namespace`          |          | [实验性（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes命名空间使用 |

### 示例

#### Compose 文件

`deploy`命令支持组合文件版本`3.0`及更高版本。

```sh
$ docker stack deploy --compose-file docker-compose.yml vossibility 
```

编排文件也可以作为标准输入提供`--compose-file -`：

```sh
$ cat docker-compose.yml | docker stack deploy --compose-file - vossibility
```

如果配置在多个Compose文件之间拆分，例如基本配置和特定于环境的覆盖，则可以提供多个 `--compose-file`选项。

```sh
$ docker stack deploy --compose-file docker-compose.yml -f docker-compose.prod.yml vossibility
```

可以验证服务是否已正确创建：

```sh
$ docker service ls
ID                  NAME                     MODE                REPLICAS            IMAGE                             PORTS
3wgt1b35g4ar        helloworld               replicated          1/1                 alpine:latest
0vgdp4mzmveo        vossibility_redis        replicated          0/1                 redis:latest                      *:6379->6379/tcp
q79efoduj9xj        vossibility_visualizer   replicated          0/1                 dockersamples/visualizer:stable   *:8080->8080/tcp
4zi5nds8n1zt        vossibility_web          replicated          5/5                 hoojo/test:my_hello_world         *:80->80/tcp
```

#### DAB文件

```sh
$ docker stack deploy --bundle-file vossibility-stack.dab vossibility
```

可以验证服务是否已正确创建：

```sh
$ docker service ls
```

## ls 列表

列出堆栈编排服务列表。

### 命令参数选项

---

| 名字，简写     | 默认 | 描述                                                         |
| -------------- | ---- | ------------------------------------------------------------ |
| `--format`     |      | 漂亮的打印堆栈使用Go模板                                     |
| `--kubeconfig` |      | [实验（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes配置文件 |
| `--namespace`  |      | [实验性（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes命名空间使用 |

 ### 示例

---

#### 查看

以下命令显示所有堆栈和一些附加信息：

```sh
$ docker stack ls
ID                 SERVICES
vossibility-stack  6
myapp              2
```

#### 格式化

格式化选项（`--format`）使用Go模板漂亮地打印堆栈。下面列出了Go模板的有效占位符：

| 占位符      | 描述     |
| ----------- | -------- |
| `.Name`     | 堆栈名称 |
| `.Services` | 服务数量 |

使用该`--format`选项时，`stack ls`命令可以完全按照模板声明输出数据，或者在使用该 `table`指令时也包含列标题。

以下示例使用不带标题的模板，并输出 由冒号分隔的所有堆栈`Name`和`Services`条目：

```sh
$ docker stack ls --format "{{.Name}}: {{.Services}}"
web-server: 1
web-cache: 4
```

## ps 查看任务

列出作为指定堆栈的一部分运行的任务。该命令必须在管理器节点运行。

### 命令参数选项

---

| 名字，简写      | 默认 | 描述                                                         |
| --------------- | ---- | ------------------------------------------------------------ |
| `--filter , -f` |      | 基于提供的条件的Swarm Filter输出                             |
| `--format`      |      | 使用Go模板的漂亮打印任务                                     |
| `--no-resolve`  |      | 不要将ID映射到名称                                           |
| `--no-trunc`    |      | 不要截断输出                                                 |
| `--quiet , -q`  |      | 只显示任务ID                                                 |
| `--kubeconfig`  |      | [实验（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes配置文件 |
| `--namespace`   |      | [实验性（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes命名空间使用 |

 ### 示例

---

#### 查看

以下命令显示了作为`voting`堆栈一部分的所有任务：

```sh
$ docker stack ps voting
ID                  NAME                  IMAGE                                          NODE   DESIRED STATE  CURRENT STATE          ERROR  PORTS
xim5bcqtgk1b        voting_worker.1       dockersamples/examplevotingapp_worker:latest   node2  Running        Running 2 minutes ago
q7yik0ks1in6        voting_result.1       dockersamples/examplevotingapp_result:before   node1  Running        Running 2 minutes ago

# 不要将ID映射到名称
$ docker stack ps --no-resolve voting
# 不要截断输出
$ docker stack ps --no-trunc voting
# 只显示任务ID
$ docker stack ps -q voting
$ docker inspect $(docker stack ps -q voting)
```

#### 过滤

过滤选项（`-f`或`--filter`）格式是一`key=value`对。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）。多个过滤器选项被组合为一个`OR`过滤器。例如，`-f name=redis.1 -f name=redis.7`返回两者`redis.1`和`redis.7`任务。

目前支持的过滤器是：

- [id](https://docs.docker.com/engine/reference/commandline/stack_ps/#id)
- [name](https://docs.docker.com/engine/reference/commandline/stack_ps/#name)
- [node](https://docs.docker.com/engine/reference/commandline/stack_ps/#node)
- [desired-state](https://docs.docker.com/engine/reference/commandline/stack_ps/#desired-state)

```sh
# 任务的ID的前缀匹配
$ docker stack ps -f "id=t" voting
# 任务名称相匹配
$ docker stack ps -f "name=voting_redis" voting
# 节点名或节点ID相匹配
$ docker stack ps -f "node=node1" voting
# 状态过来，可以取值running，shutdown，或accepted
$ docker stack ps -f "desired-state=running" voting
```

#### 格式化

格式化选项（`--format`）可以很好地打印使用Go模板输出的任务。下面列出了Go模板的有效占位符：

| 占位符          | 描述                                                  |
| --------------- | ----------------------------------------------------- |
| `.ID`           | 任务ID                                                |
| `.Name`         | 任务名称                                              |
| `.Image`        | 任务图像                                              |
| `.Node`         | 节点ID                                                |
| `.DesiredState` | 任务的理想状态（`running`，`shutdown`，或`accepted`） |
| `.CurrentState` | 任务的当前状态                                        |
| `.Error`        | 错误                                                  |
| `.Ports`        | 任务发布的端口                                        |

使用该`--format`选项时，该`stack ps`命令将按照模板声明输出数据，或者在使用该 `table`指令时也包含列标题。

以下示例使用不带标题的模板，并输出 由冒号分隔的所有任务`Name`和`Image`条目：

```sh
$ docker stack ps --format "{{.Name}}: {{.Image}}" voting
```

## rm 删除

从群中删除堆栈，与堆栈相关的服务，网络和机密将被删除。该命令必须在管理器节点运行。

这将删除名称的堆栈`myapp`。与堆栈相关的服务、网络和机密将被删除。

```sh
$ docker stack rm myapp
$ docker stack rm myapp vossibility
```

## services 查看服务

列出作为指定堆栈的一部分运行的服务。该命令必须在管理器节点运行。

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                                                         |
| --------------- | ---- | ------------------------------------------------------------ |
| `--filter , -f` |      | 基于提供的条件的Swarm Filter输出                             |
| `--format`      |      | 使用Go模板的漂亮打印服务                                     |
| `--quiet , -q`  |      | 只显示ID                                                     |
| `--kubeconfig`  |      | [实验（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes配置文件 |
| `--namespace`   |      | [实验性（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes命名空间使用 |

### 示例

---

#### 查看

以下命令显示`myapp`堆栈中的所有服务：

```sh
$ docker stack services myapp
ID            NAME            REPLICAS  IMAGE                                                                          COMMAND
7be5ei6sqeye  myapp_web       1/1       nginx
```

#### 过滤

过滤选项（`-f`或`--filter`）格式是一`key=value`对。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）。多个过滤器选项被组合为一个`OR`过滤器。

以下命令显示`web`和`db`服务：

```sh
$ docker stack services --filter name=myapp_web --filter name=myapp_db myapp

ID            NAME            REPLICAS  IMAGE                                                                          COMMAND
7be5ei6sqeye  myapp_web       1/1       nginx@sha256:23f809e7fd5952e7d5be065b4d3643fbbceccd349d537b62a123ef2201bc886f
dn7m7nhhfb9y  myapp_db        1/1       mysql@sha256:a9a5b559f8821fe73d58c3606c812d1c044868d42c63817fa5125fd9d8b7b539
```

目前支持的过滤器是：

- id / ID (`--filter id=7be5ei6sqeye`, or `--filter ID=7be5ei6sqeye`)
- name (`--filter name=myapp_web`)
- label (`--filter label=key=value`)

#### 格式化

（`--format`）使用Go模板漂亮地打印服务输出。下面列出了Go模板的有效占位符：

| 占位符      | 描述                   |
| ----------- | ---------------------- |
| `.ID`       | 服务ID                 |
| `.Name`     | 服务名称               |
| `.Mode`     | 服务模式（复制，全局） |
| `.Replicas` | 服务副本               |
| `.Image`    | 服务形象               |

使用该`--format`选项时，该`stack services`命令将按照模板声明输出数据，或者在使用该 `table`指令时也包含列标题。

下面的示例使用的模板没有报头，并输出 `ID`，`Mode`以及`Replicas`通过所有服务冒号分隔的条目：

```sh
$ docker stack services --format "{{.ID}}: {{.Mode}} {{.Replicas}}"
0zmvwuiu3vue: replicated 10/10
fm6uf97exkul: global 5/5
```

# 开始使用集群

本章节将介绍Docker Engine Swarm模式的功能。 并将完成以下操作：

- 以集群模式初始化Docker引擎集群
- 向群体添加节点
- 将应用服务部署到群中
- 管理集群

本章节使用在终端窗口的命令行上输入的Docker Engine CLI命令。同时需要掌握`docker-machine`命令。

## 创建集群

当首次安装并开始使用Docker Engine时，集群模式默认处于禁用状态。当启用集群模式时，将使用通过`docker service`命令管理的服务概念。 

当在本地计算机上以集群模式运行引擎时，可以根据自己创建的镜像或其他可用镜像来创建和测试服务。在生产环境中，集群模式提供具有**集群管理功能**的**容错平台**，以保持服务正常运行。 

当运行命令**创建集群**时，Docker引擎开始以**集群模式运行**。运行[`docker swarm init`](https://docs.docker.com/engine/reference/commandline/swarm_init/) 以在**当前节点**上**创建单节点集群**。引擎的工作流程如下：

- 将当前节点切换到集群模式。
- 创建一个名为`default`的集群。
- 指定**当前节点**作为该群的**领导者管理者节点**。
- 用机器**主机名**命名节点。
- 配置管理器在**端口2377**上监听活动网络接口。
- 将**当前节点设置为`Active`可用性**，这意味着它可以从调度程序**接收任务**。
- 为参与群体的引擎**启动**一个**内部分布式数据存储**，以维护集群及其上运行的所有服务的一致**视图**。
- 默认情况下，为群体生成一个**自签名的根CA**。
- 默认情况下，为worker和manager节点**生成令牌**以加入集群。
- 创建一个**覆盖网络`ingress`**，该网络命名为发布群体外部的服务端口。

在创建集群之前，确保Docker Engine守护进程在主机上启动。

1、创建机器，分别创建一个管理节点`manager1`，两个工作节点 `worker1` 和 `worker2`

```sh
$ docker-machine create --driver virtualbox manager1
$ docker-machine create --driver virtualbox worker1
$ docker-machine create --driver virtualbox worker2
```

2、配置本地shell默认链接到的机器`manager1`

```sh
$ docker-machine env manager1
eval $("docker-machine.exe" env manager1)
```

3、打开终端并将ssh链接到要运行管理节点`manager1`的机器中

```sh
$ docker-machine ssh manager1
```

4、输出`docker swarm init`用于提供将新工作节点加入集群时使用的连接命令。运行以下命令来创建一个新的集群：

```sh
$ docker swarm init --advertise-addr <MANAGER-IP>
```

> **注意**：如果使用Docker for Mac或Docker for Windows测试单节点集群，只需运行`docker swarm init`不带任何参数。`--advertise-addr`在这种情况下不需要指定。

以下命令在`manager1` 机器上创建一个swarm ：

```sh
$ docker swarm init --advertise-addr $(docker-machine ip manager1)
Swarm initialized: current node (4ukl6wl714uljl43m51zji80f) is now a manager.

To add a worker to this swarm, run the following command:

    docker swarm join --token SWMTKN-1-2ldbs2xa31qzzojby6cylvw0fw681z7sipvbt4qi27clmjfnut-58r3fwrqac9eoogbigink6zmo 192.168.99.106:2377

To add a manager to this swarm, run 'docker swarm join-token manager' and follow the instructions.
```

`--advertise-addr`选项配置管理节点将其地址发布为`$(docker-machine ip manager1)` `192.168.99.106`集群中的其他节点必须能够访问IP地址的管理节点。

输出包括将新节点加入集群的命令。根据`--token` 的值，节点将作为管理或工人的角色加入。

5、运行`docker info`以查看集群的当前状态： 

```sh
$ docker info
Containers: 0
 Running: 0
 Paused: 0
 Stopped: 0
Images: 0
Server Version: 18.03.1-ce
....
Swarm: active
 NodeID: 4ukl6wl714uljl43m51zji80f
 Is Manager: true
 ClusterID: oroeydyv47rzyea9v3k9zpee5
 Managers: 1
 Nodes: 1
...
```

6、运行该`docker node ls`命令查看有关节点的信息：

```sh
$ docker node ls

ID                           HOSTNAME  STATUS  AVAILABILITY  MANAGER STATUS
dxn1zf6l61qsb1josjja83ngz *  manager1  Ready   Active        Leader
```

在`*`旁边的节点ID表明当前连接此节点上。Docker Engine swarm模式会自动为机器主机名称命名节点。

## 向集群添加节点

一旦你[创建了一个](https://docs.docker.com/engine/swarm/swarm-tutorial/create-swarm/)带有管理节点[的集群](https://docs.docker.com/engine/swarm/swarm-tutorial/create-swarm/)，你就可以添加工作节点了。

1. 打开终端并将ssh放入要运行工作节点`worker1`的机器中。

   ```sh
   $ docker-machine ssh worker1
   ```

2. 运行[创建群组](https://docs.docker.com/engine/swarm/swarm-tutorial/create-swarm/)教程步骤中的`docker swarm init`输出 产生的命令，以创建一个加入到现有集群的工作节点：

   ```sh
   $ docker swarm join --token SWMTKN-1-2ldbs2xa31qzzojby6cylvw0fw681z7sipvbt4qi27clmjfnut-58r3fwrqac9eoogbigink6zmo 192.168.99.106:2377
   
   This node joined a swarm as a worker.
   ```

   如果没有之前`swarm init`输出的命令，则可以在管理节点上运行以下命令来查看加入工作节点的连接命令：

   ```sh
   $ docker swarm join-token worker
   To add a worker to this swarm, run the following command:
   
   docker swarm join --token SWMTKN-1-2ldbs2xa31qzzojby6cylvw0fw681z7sipvbt4qi27clmjfnut-58r3fwrqac9eoogbigink6zmo 192.168.99.106:2377
   ```

3. 打开终端并将ssh放入要运行第二个工作节点`worker2`的机器中。如同第一步的操作方式。

4. 运行“ [创建群组](https://docs.docker.com/engine/swarm/swarm-tutorial/create-swarm/)教程”步骤中的`docker swarm init`输出所 生成的命令，以创建加入到现有集群的第二个工作节点：

   ```sh
   $ docker swarm join --token SWMTKN-1-2ldbs2xa31qzzojby6cylvw0fw681z7sipvbt4qi27clmjfnut-58r3fwrqac9eoogbigink6zmo 192.168.99.106:2377
   
   This node joined a swarm as a worker.
   ```

5. 打开一个终端并将ssh连入管理节点`manager1`运行的机器中，然后运行`docker node ls`命令以查看工作节点：

   ```sh
   $ docker node ls
   ID                            HOSTNAME            STATUS              AVAILABILITY        MANAGER STATUS      ENGINE VERSION
   4ukl6wl714uljl43m51zji80f *   manager1            Ready               Active              Leader              18.03.1-ce
   rp87bhtw4qmtg9i3k4o53b4xi     worker1             Ready               Active                                  18.03.1-ce
   occde76c7oiv93zhds0x8ij5u     worker2             Ready               Active                                  18.03.1-ce
   ```

   `MANAGER`列标识集群中的管理节点。此列中的空状态，`worker1`并将`worker2`它们标识为工作节点。集群管理命令`docker node ls`只能在管理节点上运行。

## 在集群上部署服务

[创建](https://docs.docker.com/engine/swarm/swarm-tutorial/create-swarm/)完群后，可以将服务部署到集群中。

1. 打开终端并将ssh连接到运行管理节点`manager1`的机器中。

2. 运行以下命令：

   ```sh
   $ docker service create --replicas 1 --name helloworld alpine ping baidu.com
   qkexf88msvohybd6pico0t4g0
   ```

   - `docker service create` 命令创建服务。
   - `--name`选项服务命名`helloworld`。
   - `--replicas`选项指定了正在运行的实例的所需副本比例。
   - 参数`alpine ping baidu.com`将服务定义为执行命令的Alpine Linux容器`ping baidu.com`。

3. 运行`docker service ls`以查看正在运行的服务的列表：

   ```sh
   $ docker service ls
   ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
   qkexf88msvoh        helloworld          replicated          1/1                 alpine:latest
   ```

## 检查集群上的服务

当为集群[部署服务时](https://docs.docker.com/engine/swarm/swarm-tutorial/deploy-service/)，可以使用Docker CLI查看集群中运行的服务的详细信息。

1. 如果还没有，请打开一个终端并将ssh连接到运行管理节点`manager1`的机器中。

2. 运行`docker service inspect --pretty <SERVICE-ID>`改变阅读的排版格式显示有关服务的详细信息。<br/>查看`helloworld`服务的详细信息

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

   > **提示**：要以json格式返回服务详细信息，请运行没有`--pretty`选项的相同命令。

   ```sh
   $ docker service inspect helloworld
   ```

3. 运行`docker service ps <SERVICE-ID>`以查看哪些节点正在运行该服务：

   ```sh
   $ docker service ps helloworld
   ID                  NAME                IMAGE               NODE                DESIRED STATE       CURRENT STATE            ERROR               PORTS
   xe2d3sypfvk1        helloworld.1        alpine:latest       manager1            Running             Running 56 seconds ago
   ```

   在这种情况下，服务的一个实例`helloworld`正在`manager1`节点上运行 。可能会看到服务在你的管理节点上运行。默认情况下，群中的**管理节点可以像工作节点**一样执行任务。

   集群也显示`DESIRED STATE`和`CURRENT STATE`服务任务的状态，以便可以根据服务定义查看任务是否正在运行。

4. 在**运行任务的节点**上运行`docker ps`以查看有关任务容器的详细信息。

   > **提示**：如果`helloworld`正在管理节点以外的节点上运行，则必须ssh到该节点。

   ```sh
   $ docker ps
   $ docker container ps
   CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
   89dad2b7f9e8        alpine:latest       "ping baidu.com"    10 minutes ago      Up 10 minutes                           helloworld.1.xe2d3sypfvk1eb4nj2pcydfg3
   ```

## 扩展集群中的服务

为集群[部署了服务](https://docs.docker.com/engine/swarm/swarm-tutorial/deploy-service/)，就可以使用Docker CLI来扩展服务中的容器数量。在服务中运行的容器被称为**任务**。

1. 如果你还没有，请打开一个终端并将ssh连接到运行管理节点`manager1`的机器中。

2. 运行以下命令以更改在集群中运行的服务的所需副本数量：

   ```sh
   $ docker service scale <SERVICE-ID>=<NUMBER-OF-TASKS>
   ```

   例如：

   ```sh
   $ docker service scale helloworld=5
   helloworld scaled to 5
   ```

3. 运行`docker service ps <SERVICE-ID>`以查看更新的任务列表：

   ```sh
   $ docker service ps helloworld
   ID                  NAME                IMAGE               NODE                DESIRED STATE       CURRENT STATE            ERROR               PORTS
   xe2d3sypfvk1        helloworld.1        alpine:latest       manager1            Running             Running 25 minutes ago
   c0ypn9qbvmv9        helloworld.2        alpine:latest       manager1            Running             Running 21 seconds ago
   im86a8kz2mk7        helloworld.3        alpine:latest       worker1             Running             Running 10 seconds ago
   o7cz9ogiees9        helloworld.4        alpine:latest       worker1             Running             Running 10 seconds ago
   gb7gsxcd9im4        helloworld.5        alpine:latest       worker2             Running             Running 20 seconds ago
   ```

   可以看到swarm创建了4个新任务，以扩展到总共5个运行的Alpine Linux实例。任务分布在群体的三个节点之间。2个正运行在`manager1`节点上。

4. 运行`docker ps`以查看在连接的节点上运行的容器。以下示例显示了正在运行的`manager1`任务：

   ```sh
   $ docker ps
   CONTAINER ID        IMAGE               COMMAND             CREATED              STATUS              PORTS               NAMES
   89dad2b7f9e8        alpine:latest       "ping baidu.com"    25 minutes ago       Up 26 minutes                           helloworld.1.xe2d3sypfvk1eb4nj2pcydfg3
   ```

   如果想查看在其他节点上运行的容器，请将ssh连到这些节点并运行`docker ps`命令。

## 删除在群上运行的服务

1. 如果还没有连接到`manager1`，请打开一个终端并将ssh连入运行管理节点`manager1`的机器中。

2. 运行`docker service rm helloworld`删除`helloworld`服务。

   ```sh
   $ docker service rm helloworld
   helloworld
   ```

3. 运行`docker service inspect <SERVICE-ID>`以验证`swarm manager`是否删除了该服务。CLI会返回一条消息，指出找不到该服务：

   ```sh
   $ docker service inspect helloworld
   []
   Error: no such service: helloworld
   ```

4. 即使服务不再存在，任务容器也**需要几秒钟**才能清理。可以`docker ps`在节点上使用以验证任务何时被删除。

   ```sh
   $ docker ps
      CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS  
   ```

## 滚动更新应用于服务

部署基于`Redis 3.0.6`容器镜像的服务。然后，使用滚动更新升级服务以使用`Redis 3.0.7`容器镜像。

1. 如果还没有连接到`manager1`，请打开一个终端并将ssh连入运行管理节点`manager1`的机器中。

2. 将`Redis 3.0.6`部署到集群，并配置`10秒更新延迟`的集群：

   ```sh
   $ docker service create \
     --replicas 3 \
     --name redis \
     --update-delay 10s \
     redis:3.0.6
   
   0u6a4s31ybk7yw2wyvtikmu50
   ```

   可以在服务部署时配置滚动更新策略。

   `--update-delay`选项配置更新**服务任务或多组任务**之间的时间延迟。可以将时间描述为`T`，秒数`Ts`，分钟数`Tm`或小时数的组合`Th`。因此 `10m30s`表示延迟10分30秒。

   默认情况下，调度程序一次更新1个任务。可以通过 `--update-parallelism`选项来配置**调度程序同时更新的最大服务任务数**。

   默认情况下，当对单个任务的更新返回`RUNNING`状态时，调度程序调度另一个任务进行更新，直到更新所有任务。如果在更新期间任何时候任务返回`FAILED`，则调度程序会**暂停更新**。你可以使用`docker service create`或`docker service update`的`--update-failure-action`选项来**控制行为**。

3. 检查`redis`服务：

   ```sh
   $ docker service inspect --pretty redis
   ID:             o09gf2h621oebip3jmdoi59dj
   Name:           redis
   Service Mode:   Replicated
    Replicas:      3
   Placement:
   UpdateConfig:
    Parallelism:   1
    Delay:         10s
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
    Image:         redis:3.0.6@sha256:6a692a76c2081888b589e26e6ec835743119fe453d67ecf03df7de5b73d69842
   Resources:
   Endpoint Mode:  vip
   ```

4. 现在可以更新`redis`容器镜像了。swarm manager根据`UpdateConfig`策略将更新应用于节点：

   ```sh
   $ docker service update --image redis:3.0.7 redis
   redis
   ```

   默认情况下，调度程序申请滚动更新流程，如下所示：

   - 停止第一项任务。
   - 为已停止的任务计划更新。
   - 启动更新任务的容器。
   - 如果任务更新返回`RUNNING`，请等待指定的延迟时间，然后开始下一个任务。
   - 如果在更新过程中的任何时间任务返回`FAILED`，暂停更新。

5. 运行`docker service inspect --pretty redis`以查看所需状态下的新镜像：

   ```sh
   $ docker service inspect --pretty redis
   ```

   如果**更新由于失败而暂停**，则 `service inspect`会显示错误信息的输出：

   ```sh
   $ docker service inspect --pretty redis
   
   ID:             0u6a4s31ybk7yw2wyvtikmu50
   Name:           redis
   ...snip...
   Update status:
    State:      paused
    Started:    11 seconds ago
    Message:    update paused due to failure or early termination of task 9p7ith557h8ndf0ui9s0q951b
   ...snip...
   ```

   **重新启动暂停或失败的更新**，运行`docker service update <SERVICE-ID>`。例如：

   ```sh
   $ docker service update redis
   ```

   为避免重复某些更新失败，可能需要通过`docker service update`传递选项来**重新配置**服务。

6. 运行`docker service ps <SERVICE-ID>`观看滚动更新：

   ```sh
   $ docker service ps redis
   ID                  NAME                IMAGE               NODE                DESIRED STATE       CURRENT STATE            ERROR               PORTS
   xwjuzdyl5nqa        redis.1             redis:3.0.7         manager1            Running             Running 3 minutes ago
   vt2n7wxpwetx         \_ redis.1         redis:3.0.6         manager1            Shutdown            Shutdown 4 minutes ago
   f8jw76ejag2s        redis.2             redis:3.0.7         worker2             Running             Running 4 minutes ago
   qo2quotexnfe         \_ redis.2         redis:3.0.6         worker2             Shutdown            Shutdown 5 minutes ago
   rnl9zxey9bcv        redis.3             redis:3.0.7         worker1             Running             Running 5 minutes ago
   qmaoadbmvdjh         \_ redis.3         redis:3.0.6         worker1             Shutdown            Shutdown 6 minutes ago
   ```

## 排除集群上的节点

在前几个步骤中，所有节点都在`ACTIVE` 可用状态下运行。swarm manager 可以将任务分配给任何`ACTIVE`节点，所以到现在为止所有节点都可以接收任务。

有时，例如计划的维护时间，需要将节点设置为`DRAIN` 可用性。**`DRAIN`可用性阻止节点从群管理器接收新任务**。这也意味着管理节点可以停止在节点上运行的任务，并在具有`ACTIVE`可用性的节点上启动副本任务。

> **重要提示**：将节点设置为`DRAIN`不会从该节点**删除独立容器**，例如使用`docker run`，`docker-compose up`或Docker Engine API创建的容器。节点的状态（包括`DRAIN`）仅影响节点调度集群服务工作**负载**的能力。

1. 如果还没有连接到`manager1`，请打开一个终端并将ssh连入运行管理节点`manager1`的机器中。

2. 验证所有节点是否可用。

   ```sh
   $ docker node ls
   ID                            HOSTNAME            STATUS              AVAILABILITY        MANAGER STATUS      ENGINE VERSION
   4ukl6wl714uljl43m51zji80f *   manager1            Ready               Active              Leader              18.03.1-ce
   rp87bhtw4qmtg9i3k4o53b4xi     worker1             Ready               Active                                  18.03.1-ce
   occde76c7oiv93zhds0x8ij5u     worker2             Ready               Active                                  18.03.1-ce
   ```

3. 如果还没有运行[滚动更新](https://docs.docker.com/engine/swarm/swarm-tutorial/rolling-update/)教程中的`redis`服务，请立即启动它：

   ```sh
   $ docker service create --replicas 3 --name redis --update-delay 10s redis:3.0.7
   c5uo6kdmzpon37mgj9mwglcfw
   ```

4. 运行`docker service ps redis`以查看swarm manager 如何将任务分配给不同的节点：

   ```sh
   $ docker service ps redis
   ID                  NAME                IMAGE               NODE                DESIRED STATE       CURRENT STATE             ERROR               PORTS
   xwjuzdyl5nqa        redis.1             redis:3.0.7         manager1            Running             Running 14 minutes ago
   vt2n7wxpwetx         \_ redis.1         redis:3.0.6         manager1            Shutdown            Shutdown 14 minutes ago
   f8jw76ejag2s        redis.2             redis:3.0.7         worker2             Running             Running 15 minutes ago
   qo2quotexnfe         \_ redis.2         redis:3.0.6         worker2             Shutdown            Shutdown 15 minutes ago
   rnl9zxey9bcv        redis.3             redis:3.0.7         worker1             Running             Running 16 minutes ago
   qmaoadbmvdjh         \_ redis.3         redis:3.0.6         worker1             Shutdown            Shutdown 16 minutes ago
   ```

   在这种情况下，`swarm manager`将一个任务**分配给每个节点**。可能会看到环境中的节点之间的任务分布不同。

5. 运行`docker node update --availability drain <NODE-ID>`以**排除**具有**分配**给它的任务的节点：

   ```sh
   $ docker node update --availability drain worker1
   worker1
   ```

6. 检查节点的可用性：

   ```sh
   $ docker node inspect worker1 --pretty
   ID:                     rp87bhtw4qmtg9i3k4o53b4xi
   Hostname:               worker1
   Joined at:              2018-05-08 14:55:47.339693284 +0000 utc
   Status:
    State:                 Ready
    Availability:          Drain
    Address:               192.168.99.107
   ```

   可以看到排除的节点`worker1`的`AVAILABILITY`为`Drain`。

7. 运行`docker service ps redis`以查看swarm管理如何更新服务的任务分配`redis`：

   ```sh
   $ docker service ps redis
   ID                  NAME                IMAGE               NODE                DESIRED STATE       CURRENT STATE          ERROR               PORTS
   xwjuzdyl5nqa        redis.1             redis:3.0.7         manager1            Running             Running 3 hours ago
   vt2n7wxpwetx         \_ redis.1         redis:3.0.6         manager1            Shutdown            Shutdown 3 hours ago
   f8jw76ejag2s        redis.2             redis:3.0.7         worker2             Running             Running 3 hours ago
   qo2quotexnfe         \_ redis.2         redis:3.0.6         worker2             Shutdown            Shutdown 3 hours ago
   5l1570g8t3gn        redis.3             redis:3.0.7         manager1            Running             Running 3 hours ago
   rnl9zxey9bcv         \_ redis.3         redis:3.0.7         worker1             Shutdown            Shutdown 3 hours ago
   qmaoadbmvdjh         \_ redis.3         redis:3.0.6         worker1             Shutdown            Shutdown 3 hours ago
   ```
   swarm管理节点通过在具有`Drain`可用性的节点上**结束任务**并在具有**可用性**的节点上**创建新任务**来维护期望的状态`Active` 。 

8. 运行 `docker node update --availability active <NODE-ID>`将`Drain`排除的节点返回到活动状态：

   ```sh
   $ docker node update --availability active worker1
   ```

9. 检查节点以查看更新的状态：

   ```sh
   $ docker node inspect --pretty worker1
   ID:                     rp87bhtw4qmtg9i3k4o53b4xi
   Hostname:               worker1
   Joined at:              2018-05-08 14:55:47.339693284 +0000 utc
   Status:
    State:                 Ready
    Availability:          Active
    Address:               192.168.99.107
   ```

   当节点重新设置为`Active`可用时，以下情况它可以接收新的任务：

   - 在服务**更新**期间**扩大**规模比例
   - 在**滚动更新**期间
   - 当你**设置**另一个节点的**`Drain`可用性**
   - 当一个任务在另一个活动节点上**失败**时
   - 当新任务创建分配时

## 使用集群路由网络

Docker Engine集群模式可以轻松发布服务端口，使其可以用于集群外部的资源。所有节点都参与入口**路由网格**。路由网格使集群中的**每个节点**都可以接受集群中**运行**的任何**服务**的**已发布端口**的连接，即使节点上**没有**运行任何**任务**。路由网格将所有**传入请求**路由到**可用节点**上的**已发布端口**以**激活**容器。

要使用集群中的 **ingress **网络，在启用集群模式之前，需要在集群节点之间打开以下端口：

- 端口`7946`TCP/UDP用于容器网络发现。
- 端口`4789`UDP用于容器入口网络。

还必须打开集群节点与需要访问端口的任何外部资源（如外部负载平衡器）之间的发布端口。

### 发布服务的端口

---

创建服务时，使用`--publish`选项**发布端口**。`target` 用于指定**容器内**的端口，并`published`用于指定**绑定到路由网格上的端口**。如果没有`published` 端口，则为每个服务任务绑定一个**随机的高编号**端口。需要检查任务以确定端口。

```sh
$ docker service create \
  --name <SERVICE-NAME> \
  --publish published=<PUBLISHED-PORT>,target=<CONTAINER-PORT> \
  <IMAGE>
```

> **注意**：语法的**旧形式**是冒号分隔的字符串，其中发布的端口是第一个，目标端口是第二个，例如 `-p 8080:80`。新的语法是首选，因为它更易于阅读并且更灵活。

`<PUBLISHED-PORT>`是群体提供服务的端口。如果省略它，则绑定一个**随机**的高编号端口。`<CONTAINER-PORT>`是**容器监听的端口**，参数是**必需的**。

例如，以下命令将nginx容器中的端口80发布到集群中的任何节点的8080端口：

```sh
$ docker service create \
  --name my-web \
  --publish published=8080,target=80 \
  --replicas 2 \
  nginx
```

当访问任何节点上的端口8080时，Docker会**将请求路由到_活动_容器**。在集群节点本身，端口8080可能实际上**并未被绑定**，但路由网格知道如何路由数据流量并防止发生任何端口冲突。

路由网格在**发布的端口**上侦听分配给该节点的**任何IP地址**。对于外部可路由的IP地址，该端口可在**主机外部**使用。对于所有其他IP地址，访问只能在**主机内**使用。

![服务入口镜像](https://docs.docker.com/engine/swarm/images/ingress-routing-mesh.png)

可以使用以下命令发布现有服务的端口：

```sh
$ docker service update \
  --publish-add published=<PUBLISHED-PORT>,target=<CONTAINER-PORT> \
  <SERVICE>
```

可以使用`docker service inspect`查看服务的发布端口。例如：

```sh
$ docker service inspect --format="{{json .Endpoint.Spec.Ports}}" my-web

[{"Protocol":"tcp","TargetPort":80,"PublishedPort":8080}]
```

从容器输出显示`<CONTAINER-PORT>`（标记为`TargetPort`）和 `<PUBLISHED-PORT>`（标记`PublishedPort`），其中节点监听的服务请求。

### 发布`TCP`或`UDP`端口

---

默认情况下，当发布端口时，它是一个TCP端口。可以专门发布一个UDP端口，而不是或者除了TCP端口之外。当同时发布TCP和UDP端口时，如果省略协议选项配置，则该端口将作为TCP端口发布。如果使用较长的语法（推荐用于Docker 1.13或更高版本），请将`protocol`设置为`tcp`或`udp`。

#### 仅限TCP

**长语法：**

```sh
$ docker service create --name dns-cache \
  --publish published=53,target=53 \
  dns-cache
```

**简短语法：**

```sh
$ docker service create --name dns-cache \
  -p 53:53 \
  dns-cache
```

#### TCP和UDP

**长语法：**

```sh
$ docker service create --name dns-cache \
  --publish published=53,target=53 \
  --publish published=53,target=53,protocol=udp \
  dns-cache
```

**简短语法：**

```sh
$ docker service create --name dns-cache \
  -p 53:53 \
  -p 53:53/udp \
  dns-cache
```

#### 仅限UDP

**长语法：**

```sh
$ docker service create --name dns-cache \
  --publish published=53,target=53,protocol=udp \
  dns-cache
```

**简短语法：**

```sh
$ docker service create --name dns-cache \
  -p 53:53/udp \
  dns-cache
```

### 绕过路由网格

---

可以**绕过**路由网格，以便在访问**特定**节点上的绑定**端口**时，**始终**访问在该节点上运行的服务的实例。这被称为**`host`模式**。有几件事要记住。

- 如果访问**未运行**服务任务的节点，则该服务**不会侦听**该端口。有可能没有任何东西在倾听，或者是一个完全不同的应用程序正在倾听。
- 如果希望在**每个节点**上**运行多个**服务任务（例如当有5个节点但运行10个副本时），则**无法**指定**静态**目标端口。要么允许Docker分配一个**随机**的高编号端口（通过离开 `target`），要么确保只有**一个服务实例**在给定节点上运行，使用**全局服务而不是复制服务**，或者使用**分布约束**。

要绕过路由网格，**必须使用长期`--publish`服务并设置`mode`为`host`**。如果省略`mode`或将其设置为`ingress`，则使用路由网格。以下命令创建**全局服务使用 `host`模式并绕过路由网格**。

```sh
$ docker service create --name dns-cache \
  --publish published=53,target=53,protocol=udp,mode=host \
  --mode global \
  dns-cache
```

### 配置外部负载平衡器

---

可以为集群服务配置**外部负载平衡器**，可以与路由网格结合使用，也可以根本不使用路由网格。

#### 使用路由网格

可以**配置外部负载平衡器以将请求路由到集群服务**。例如，可以配置[HAProxy](http://www.haproxy.org/)以平衡对发布到端口8080的nginx服务的请求。

![带有外部负载平衡器镜像的入口](https://docs.docker.com/engine/swarm/images/ingress-lb.png)

在这种情况下，端口8080必须在负载平衡器和群中的节点之间打开。集群节点可以**驻留在代理服务器**可访问的专用网络上，但这不是**公共**可访问的。

可以配置负载均衡器来平衡集群中每个节点之间的请求，即使节点上没有任何计划任务。例如，可以在以下位置使用HAProxy配置`/etc/haproxy/haproxy.cfg`：

```properties
global
        log /dev/log    local0
        log /dev/log    local1 notice
...snip...

# Configure HAProxy to listen on port 80
frontend http_front
   bind *:80
   stats uri /haproxy?stats
   default_backend http_back

# Configure HAProxy to route requests to swarm nodes on port 8080
backend http_back
   balance roundrobin
   server node1 192.168.99.100:8080 check
   server node2 192.168.99.101:8080 check
   server node3 192.168.99.102:8080 check
```

当在端口80上访问HAProxy负载平衡器时，它会将请求**转发**给集群中的节点。**集群路由**将请求路由到活动任务。如果由于某种原因，集群调度程序将**任务分派**到不同的节点，则无需重新配置负载均衡器。

可以配置**任何类型的负载均衡器**以将请求路由到集群节点。要了解有关HAProxy的更多信息，请参阅[HAProxy文档](https://cbonte.github.io/haproxy-dconv/)。

#### 没有路由网格

要使用不带路由网格的外部负载平衡器，请将其**设置`--endpoint-mode` 为`dnsrr`默认值`vip`**。在这种情况下，没有一个虚拟IP。相反，Docker会为**服务设置DNS映射**，以便**服务名称的DNS查询**返回一个**IP地址**列表，并且**客户端直接连接**到其中的一个。负责向负载均衡器提供IP地址和端口列表。请参阅 [配置服务发现](https://docs.docker.com/engine/swarm/networking/#configure-service-discovery)。

# 集群的用途

下面简单的讲解节点是如何工作的，以及管理节点、工作节点在集群中的用途。以及如果更改节点角色类型。

## 节点的用途

Docker Engine 1.12引入了swarm模式，使可以创建一个或多个名为swarm的Docker引擎集群。集群由一个或多个节点组成：运行Docker Engine 1.12或更高版本的集群模式的物理或虚拟机器。

有两种类型的节点：[**管理节点**](https://docs.docker.com/engine/swarm/how-swarm-mode-works/nodes/#manager-nodes) 和 [**工作节点**](https://docs.docker.com/engine/swarm/how-swarm-mode-works/nodes/#worker-nodes)。

![群模式集群](https://docs.docker.com/engine/swarm/images/swarm-diagram.png)

如果你尚未阅读 [群体模式概述](https://docs.docker.com/engine/swarm/)和 [关键概念](https://docs.docker.com/engine/swarm/key-concepts/)。

### 管理节点

---

Manager节点处理集群管理任务：

- 维护集群状态
- 调度服务
- 提供集群模式[HTTP API端点](https://docs.docker.com/engine/api/)

使用[Raft](https://raft.github.io/raft.pdf)实施，管理人员可以保持整个集群及其上运行的所有服务的**一致内部状态**。出于测试目的，可以使用单个管理器运行集群。如果单管理器群中的管理器出现**故障**，服务将**继续**运行，但需要创建一个**新集群**才进行**恢复**。

为了利用群模式的**容错**功能，Docker建议根据组织的**高可用性**要求实施**奇数**个节点。当你有多个管理器时，你可以在没有停机时间的情况下从管理器节点的**故障中恢复**。

- **三个**管理节点集群容忍**一个**管理节点的最大故障。

- **五个**管理节点集群最多可同时瘫痪**两个**管理节点。

- **`N`个**管理节点集群容忍最多损失 **`(N-1)/2`**管理节点。

- Docker推荐一个集群最多有**70**管理节点。

  > **重要提示**：添加更多管理节点并不意味着可扩展性或更高的性能。一般来说，情况正好相反。

### 工作节点

---

工作节点也是Docker Engine的实例，其唯一目的是**执行容器**。工作节点**不参与Raft分布式**状态，进行**调度决策**或**提供**集群模式**HTTP API**。

可以创建一个管理节点集群，但不能有一个没有**至少一个管理节点**的工作节点。**默认情况下，所有管理节点都是工作节点**。在单个管理节点集群中，可以像运行命令一样运行`docker service create`，并且调度程序将所有任务放在本地引擎上。

要**阻止**调度程序将任务放置到**多节点**群中的**管理节点**上，请将管理节点的**可用性设置为`Drain`**。调度程序**正常地停止**`Drain`模式中节点上的**任务**，并调度`Active`节点上的任务 。调度程序**不会**将**新任务**分配给具有**`Drain` 可用性的节点**。

请参阅[`docker node update`](https://docs.docker.com/engine/reference/commandline/node_update/) 命令行参考以了解如何更改节点可用性。

### 更改角色

---

可以通过运行`docker node promote`将工作节点**提升为管理员**。例如，当管理器节点离线进行维护时，可能需要升级工作节点。请参阅[节点升级](https://docs.docker.com/engine/reference/commandline/node_promote/)。

也可以将管理器节点**降级为工作节点**。请参阅 [节点降级](https://docs.docker.com/engine/reference/commandline/node_demote/)。

## 服务的用途

要在Docker Engine处于**集群模式**时**部署**应用程序**镜像**，请**创建**一个**服务**。在某些更大的应用程序中，服务通常是**微服务的镜像**。服务实例对象可能包括HTTP服务器、数据库或希望在分布式环境中运行的任何其他类型的可执行程序。

当创建服务时，可以指定要使用哪个**容器镜像**以及要在**正在运行**的容器中执行哪些命令。还可以**定义服务**的选项，包括：

- 群体在群体外提供服务的**端口**
- 服务的**覆盖网络**连接到群中的其他**服务**
- **CPU和内存**限制和保留
- **滚动更新**政策
- 要在群中运行的镜像**副本的数量**

### 服务、任务和容器

---

将服务部署到集群时，集群管理节点接受服务定义作为服务的所需状态。然后它将集群中的节点上的服务作为一个或多个**副本任务**进行调度。这些任务在群中的**节点上**彼此**独立运行**。

例如，假设你想要在HTTP侦听器的三个实例之间进行负载平衡。下图显示了具有三个副本的HTTP侦听器服务。监听的三个**实例**中的每一个都是集群中的一个**任务**。

![服务图](https://docs.docker.com/engine/swarm/images/services-diagram.png)

**容器是一个孤立**的过程。在群模式模式中，每个**任务**只调用一个**容器**。**任务**类似于**调度程序**放置**容器的“插槽”**。一旦容器处于**活动**状态，调度程序就会识别出**任务处于运行状态**。如果容器未通过**健康检查或终止**，则**任务将终止**。

### 任务和调度

---

**任务**是**群体中的调度的原子单位**。当通过创建或更新服务来声明所需的服务状态时，协调器通过**调度任务**来实现所需的状态。例如，可以定义一个服务，指示协调器 始终保持运行HTTP侦听器的三个实例。协调者通过创建三个任务来做出响应。每个**任务**都是**调度程序**通过产生**容器**来填充的**插槽**。**容器是任务的实例化**对象。如果HTTP监听器任务随后**失败**其运行状况检查或**崩溃**，则协调器会**创建**一个**新的副本任务**，以生成一个**新的容器**。

任务是一个**单向**机制。它通过一系列状态单调进行：分配，准备，运行等。如果任务失败，则协调员**删除任务及其容器**，然后**创建一个新任务**以根据服务指定的期望状态进行**替换**。

Docker集群模式的基础逻辑是通用**调度器和协调器**。服务和任务抽象本身并不知道它们实现的容器。假设你可以实现其他类型的任务，例如虚拟机任务或非集装箱化的任务。调度程序和协调器对于任务的类型是不可知的。但是，当前版本的Docker仅支持容器任务。

下图显示了swarm模式如何接受服务**创建请求**并为工作节点**调度任务**。

![服务流程](https://docs.docker.com/engine/swarm/images/service-lifecycle.png)

#### 待定服务

服务可以被配置为使得集群中当前**没有节点可以运行任务**。在这种情况下，服务保持在**`pending`状态**。以下是一些服务可能保持在`pending`状态的几个情况：

> **注意**：如果唯一目的是**阻止部署**服务，请将服务**扩展为0**而不是尝试将其配置为`pending`保留在服务中。

- 如果**所有节点**都处于**暂停或耗尽**状态，并且创建了一个服务，它将处于**挂起**状态，**直到某个节点可用**。实际上，第一个可用的节点可以完成所有的任务，因此在生产环境中这不是一件好事。
- 可以为服务**保留**特定数量的**内存**。如果集群中**没有节点具有所需的内存量**，则该服务将**保持挂起状态**，*直到有可用节点运行其任务*。如果指定了一个**非常大的值**（例如500 GB），则该任务将**永远保持等待状态**，除非确实有一个可以满足它的节点。
- 可以对服务实施**布局约束**，并且在给定**时间约束**可能无法得到遵守。

此行为说明任务的要求和配置与群体的当前状态不紧密相关。作为群体的管理员，声明群体的期望状态，并且管理节点与群体中的工作节点一起工作以创建该状态。不需要管理集群上的任务。

### 副本服务和全局服务

---

有两种类型的服务部署，复制（副本）和全局。

对于复制服务，可以指定要运行的**相同任务的数量**。例如，决定部署一个具有三个副本的HTTP服务，每个副本服务于相同的内容。

**全局服务是在每个节点上运行一项任务的服务**。**没有**预先**指定**的**任务数量**。每次将节点添加到swarm中时，编排器都将**创建**一个任务，并且调度程序将该任务**分配给新节点**。*全局服务的优秀案例是监控或代理*，希望在集群中的每个节点上运行的防病毒扫描程序或其他类型的容器。

下图显示了黄色的副本服务和灰色的全局服务。

![全球与复制服务](https://docs.docker.com/engine/swarm/images/replicated-vs-global.png)

## 使用公钥基础设施（PKI）管理集群安全

Docker中内置的集群模式**公钥基础结构（PKI）系统**使**安全部署**容器编排系统变得非常简单。集群中的节点使用**传输层**安全性（TLS）来验证，**授权和加密**与集群中其他节点的通信。

当通过运行`docker swarm init`创建swarm时，Docker**将自己指定为管理节点**。默认情况下，管理节点会**生成**一个新的**根证书颁发机构（CA）和一个密钥对**，用于**保护与加入**该群体的其他节点的通信。也可以使用[docker swarm init](https://docs.docker.com/engine/reference/commandline/swarm_init/)命令的`--external-ca`选项 来指定自己的**外部生成的根CA**证书。

当其他节点加入集群时，**管理节点还会生成两个令牌**：一个**工作人员令牌**和一个**管理员令牌**。每个令牌都**包含**根CA证书的**摘要和*随机*生成的秘钥**。当节点加入集群时，加入节点使用**摘要**来**验证来**自远程管理器的根CA证书。远程管理员使用该秘钥来**确保**加入节点是**批准**的节点。

每当新节点**加入**集群时，管理员都会向节点**发出证书**。证书包含一个**随机**生成的**节点ID**，用于标识证书**公用名称**（CN）下的**节点*以及*组织单位**（OU）下的角色。**节点ID**用作当前群中节点生存期的**密码安全节点标识**。

下图说明了管理节点和工作节点如何使用最少的TLS 1.2来加密通信。

![tls图](https://docs.docker.com/engine/swarm/images/tls.png)

下面的示例显示了来自工作节点的证书的信息：

```yaml
Certificate:
    Data:
        Version: 3 (0x2)
        Serial Number:
            3b:1c:06:91:73:fb:16:ff:69:c3:f7:a2:fe:96:c1:73:e2:80:97:3b
        Signature Algorithm: ecdsa-with-SHA256
        Issuer: CN=swarm-ca
        Validity
            Not Before: Aug 30 02:39:00 2016 GMT
            Not After : Nov 28 03:39:00 2016 GMT
        Subject: O=ec2adilxf4ngv7ev8fwsi61i7, OU=swarm-worker, CN=dw02poa4vqvzxi5c10gm4pq2g
...snip...
```

默认情况下，集群中的每个节点**每三个月更新一次证书**。可以通过运行该`docker swarm update --cert-expiry <TIME PERIOD>`命令来**配置间隔**。最小旋转值是**1小时**。有关详细信息，请参阅 [Docker群更新](https://docs.docker.com/engine/reference/commandline/swarm_update/) CLI参考。

### 轮换CA证书

---

如果**集群CA密钥或管理器节点受到损害**，可以**轮换集群根CA**，以便任何节点都**不再信任由旧的**根CA签署的证书。

运行`docker swarm ca --rotate`以生成新的CA证书和密钥。你可以传递`--ca-cert`和`--external-ca`选项来指定根证书，并使用集群外部的根CA。或者可以通过`--ca-cert`和`--ca-key`选项来指定希望群体使用的**确切证书和密钥**。

当发出这个`docker swarm ca --rotate`命令时，下面的事情**按顺序**发生：

1. Docker生成一个**交叉签名**证书。这意味着**新**的根CA证书的版本是使用**旧**的根CA证书签署的。此交叉签名证书用作所有**新节点**证书的**中间证书**。这确保仍然**信任旧根CA的节点仍然可以验证由新CA签名**的证书。

2. 在Docker 17.06及更高版本中，Docker还告诉所有节点立即**更新**TLS证书。此过程可能需要几分钟时间，具体取决于群中节点的数量。

   > **注意**：如果你的swarm具有不同Docker版本的节点，会有以下两种情况：
   >
   > - 只有作为领导者运行**且**运行Docker 17.06或更高版本的管理员告诉节点更新他们的TLS证书。
   > - 只有运行Docker 17.06或更高版本的节点才遵守此指令。
   >
   > 对于最可预测的行为，确保所有swarm节点都在运行Docker 17.06或更高版本。

3. 在群中的每个节点都有**新的CA签名的新TLS证书**后，Docker会**忘记旧**的CA证书和密钥材料，并告诉所有节点**只信任**新的CA证书。这也会导致集群的**加入**令牌发生**变化**。以前的**联合令牌**不再有效。

从这一点开始，所有发布的新节点证书都将使用新的根CA进行签名，并且不包含任何中间件。

## 集群任务状态

Docker允许创建**可以启动任务**的服务。服务是对所需状态的描述、任务完成工作。按以下顺序在群组节点上安排工作：

1. 使用`docker service create`或UCP Web UI或CLI **创建服务**。
2. 请求**发送**到Docker**管理**节点。
3. Docker管理节点**安排服务**在**特定节点**上**运行**。
4. 每项**服务**都可以**启动多项**任务。
5. 每个任务都有一个生命周期，如：`NEW`，`PENDING`和`COMPLETE`状态。

**任务是一次运行完成的执行单元**。当一个任务**停止**时，**它不会再执行**，但是**新的任务**可能会**取代**它。

**任务会通过状态遍历推进，直至完成或失败。任务在`NEW`状态中初始化。任务通过一些遍历状态前进，其状态不会倒退**。举例来说，任务也永远不会从去 `COMPLETE`到`RUNNING`。

任务按以下顺序遍历状态：

| 任务状态    | 描述                                                         |
| ----------- | ------------------------------------------------------------ |
| `NEW`       | 该任务已**初始化**。                                         |
| `PENDING`   | 该任务的资源**已分配**。                                     |
| `ASSIGNED`  | Docker将任务**分配给节点**。                                 |
| `ACCEPTED`  | 该任务被工作节点**接受**。如果工作节点**拒绝**任务，状态将更改为`REJECTED`。 |
| `PREPARING` | Docker正在**准备任务**。                                     |
| `STARTING`  | Docker正在**开始**这项任务。                                 |
| `RUNNING`   | 任务**正在执行**。                                           |
| `COMPLETE`  | 该任务**退出**时没有错误代码。                               |
| `FAILED`    | 任务**退出**并显示错误代码。                                 |
| `SHUTDOWN`  | Docker要求**关闭**该任务。                                   |
| `REJECTED`  | 工作者节点**拒绝**了该任务。                                 |
| `ORPHANED`  | 该节点**停机**时间太长。                                     |
| `REMOVE`    | 该任务不是终端，但关联的服务已**删除**或缩小。               |

### 查看任务状态

---

运行`docker service ps <service-name>`获取任务的状态。**`CURRENT STATE`字段显示任务的状态**以及它在那里的时间。

```sh
$ docker service ps webserver
ID                  NAME                IMAGE               NODE                DESIRED STATE       CURRENT STATE            ERROR                              PORTS
owsz0yp6z375        webserver.1         nginx               UbuntuVM            Running             Running 44 seconds ago
j91iahr8s74p         \_ webserver.1     nginx               UbuntuVM            Shutdown            Failed 50 seconds ago    "No such container: webserver.…"
7dyaszg13mw2         \_ webserver.1     nginx               UbuntuVM            Shutdown            Failed 5 hours ago       "No such container: webserver.…"
```