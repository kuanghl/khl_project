# Docker Compose 入门与实践

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



`Docker Compose`是一个用Docker定义和运行复杂应用程序、运行多容器的工具。使用Compose可以在单个文件(使用`Compose`可以使用`YAML`文件来配置应用程序的服务)中定义一个多容器应用程序，然后将应用程序放在一个单独的命令中，该命令将完成所有需要完成的操作以使其运行。

使用Docker容器的应用程序通常由多个容器组成。使用`Docker Compose`，不需要编写`shell`脚本来启动容器。所有容器都使用服务在配置文件中定义，然后使用`docker-compose`脚本启动，停止和重新启动应用程序以及该应用程序中的所有服务以及该服务中的所有容器。

# 概述

`compose`适用于所有环境：生产、演示、开发、测试以及`CI`工作流程。可以了解有关常见使用案例中的更多信息。<br/>
使用`Compose`基本上是一个三步过程：
- 用一个定义你的应用程序的环境，`Dockerfile`这样它就可以在任何地方运行。
- 定义组成应用的服务，`docker-compose.yml` 以便它们可以在独立的环境中一起运行。
- 运行`docker-compose up`和编写启动并运行整个应用程序。


通常`docker-compose.yml`文件内容都像这样：

```yaml
version: '3'
services:
  web:
    build: .
    ports:
    - "5000:5000"
    volumes:
    - .:/code
    - logvolume01:/var/log
    links:
    - redis
  redis:
    image: redis
volumes:
  logvolume01: {}
```



## 作用

`Compose`具有管理应用程序整个生命周期：
- 启动，停止和重建服务
- 查看正在运行的服务的状态
- 流式传输运行服务的日志输出
- 在服务上运行一次性命令



## 内容

- [安装Compose](https://docs.docker.com/compose/install/)
- [入门](https://docs.docker.com/compose/gettingstarted/)
- [开始使用Django](https://docs.docker.com/compose/django/)
- [开始使用Rails](https://docs.docker.com/compose/rails/)
- [开始使用WordPress](https://docs.docker.com/compose/wordpress/)
- [经常问的问题](https://docs.docker.com/compose/faq/)
- [命令行参考](https://docs.docker.com/compose/reference/)
- [撰写文件参考](https://docs.docker.com/compose/compose-file/)



## 特点

`Compose`功能包括：

- [单个主机上有多个独立的环境](https://docs.docker.com/compose/overview/#Multiple-isolated-environments-on-a-single-host)
- [创建容器时保留卷数据](https://docs.docker.com/compose/overview/#preserve-volume-data-when-containers-are-created)
- [只重新创建已更改的容器](https://docs.docker.com/compose/overview/#only-recreate-containers-that-have-changed)
- [变量并在环境之间移动合成](https://docs.docker.com/compose/overview/#variables-and-moving-a-composition-between-environments)



### 单个主机上有多个独立的环境

---

使用`compose`项目来隔离项目彼此的环境。可以在多个不同的环境中使用此项目：

- 在开发主机上创建单个环境的多个副本，例如，当要为项目的每个功能分支运行稳定副本时
- 在CI服务器上，为防止构建互相干扰，可以将项目名称设置为唯一的构建编号
- 在共享主机或开发主机上，防止可能使用相同服务名称的不同项目相互干扰

默认项目名称是项目目录的名称。您可以使用[`-p`命令行选项](https://docs.docker.com/compose/reference/overview/)或 [`COMPOSE_PROJECT_NAME`环境变量](https://docs.docker.com/compose/reference/envvars/#compose-project-name)设置自定义项目名称 。



### 创建容器时保留卷数据

---

`compose`会保留服务使用的所有卷，当`docker-compose up` 运行时，如果它发现之前运行的容器，它会将旧容器中的内容复制到新容器中。此过程可确保在卷中创建的任何数据都不会丢失。

如果在`Windows`计算机上使用`docker-compose`，请参阅`环境变量`并根据特定需求调整必要的`环境变量`。



### 只重建已修改过的容器

---

`Compose`缓存用于创建容器的配置。当重新启动未更改的服务时，`Compose`会重新使用现有容器。使用现有的容器意味着可以快速更改环境。



### 变量在环境之间移动合成

---

`Compose`支持`yml`文件中的变量。可以使用这些变量为不同的环境或不同的用户定制编排服务。更多细节请参阅变量替换。您可以使用扩展字段或创建多个`Compose`文件来扩展`Compose`文件。



## 使用场景

`Compose`可用于许多不同的方式。下面概述了一些常见场景。

### 开发环境

---

在开发软件时，在独立环境中运行应用程序并与其交互的能力至关重要。`Compose`命令行工具可用于创建环境并与之交互。

在[`Compose`文件](https://docs.docker.com/compose/compose-file/)提供了一种记录和配置所有应用程序的服务依赖（数据库、队列、高速缓存、Web服务的API等等）。使用`Compose`命令行工具，可以使用单个命令（`docker-compose up`）为每个依赖项创建和启动一个或多个容器。

总之，这些功能为开发人员开始项目提供了一种便捷方式。`Compose`可以将多个服务配置文件缩减为一个机器可读的`Compose`文件和一些命令。



### 自动化测试环境

---

任何持续部署或持续集成过程的一个重要部分是自动化测试组件。自动化的端到端测试需要一个运行测试的环境。`Compose`提供了一种创建和销毁测试组件的独立测试环境的便捷方式。通过在[Compose文件中](https://docs.docker.com/compose/compose-file/)定义完整的环境，可以通过几条命令创建和销毁这些环境：

```
$ docker-compose up -d
$ ./run_tests
$ docker-compose down
```



### 单个主机部署

---

`Compose`传统上一直专注于开发和测试工作流程，但每次发布我们都在更多面向生产的功能方面取得进展。可以使用`Compose`部署到远程Docker引擎。Docker引擎可以是配备[Docker Machine](https://docs.docker.com/machine/overview/)或整个 [Docker Swarm](https://docs.docker.com/engine/swarm/)集群的单个实例 。



# 安装 `compose`

`Compose` 可以在`macOS`，`Windows`和64位`Linux`上运行。在安装 `compose` 之前，必须先安装 `docker engine`。因此，如果没有安装 `docker engine` 就先安装。正常情况下，安装了`docker` 这两个东西都会安装。

检查是否安装过 `compose`，在终端窗口运行命令行：

```shell
$ docker-compose --version
docker-compose version 1.20.1, build 5d8c71b2
```

出现以上表明已经安装过`compose`



## 安装

**win 7 用户安装 compose，先下载文件：**

https://github.com/docker/compose/releases/download/1.21.0/docker-compose-Windows-x86_64.exe

下载完成后直接安装运行。

Linux 用户安装，直接下载文件解压到指定目录，随后修改权限即可：

```shell
$ sudo curl -L https://github.com/docker/compose/releases/download/1.21.0/docker-compose-$(uname -s)-$(uname -m) -o /usr/local/bin/docker-compose
$ sudo chmod +x /usr/local/bin/docker-compose
```



## 升级

如果要从Compose 1.2或更低版本升级，请在升级Compose后删除或迁移现有容器。这是因为，从版本1.3开始，Compose使用Docker标签来跟踪容器，并且需要重新创建容器以添加标签。

如果Compose检测到没有标签创建的容器，它会拒绝运行，这样你就不会得到两套。如果您想继续使用现有的容器（例如，因为它们有要保留的数据卷），则可以使用Compose 1.5.x通过以下命令来迁移它们：

```shell
$ docker-compose migrate-to-labels
```

另外，如果你不担心保留它们，你可以删除它们

```shell
$ docker container rm -f -v myapp_web_1 myapp_db_1 ...
```



# 运用

构建一个在`Docker Compose`上运行的简单`Python Web`应用程序。该应用程序使用`Flask`框架并在`Redis`中维护一个计数器。

## 编写程序和依赖

1、创建一个目录存放程序

```shell
$ mkdir compose_example
$ cd compose_example
```

2、编写程序内容，新建一个 `app.py`，内容如下：

```python
import time

import redis
from flask import Flask


app = Flask(__name__)
cache = redis.Redis(host='redis', port=6379)


def get_hit_count():
    retries = 5
    while True:
        try:
            return cache.incr('hits')
        except redis.exceptions.ConnectionError as exc:
            if retries == 0:
                raise exc
            retries -= 1
            time.sleep(0.5)


@app.route('/')
def hello():
    count = get_hit_count()
    return 'Hello World! I have been seen {} times.\n'.format(count)

if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True)
```

在上面程序中，`redis`是应用程序网络上的`redis`容器的主机名。我们使用Redis的默认端口`6379`。

3、在项目目录中创建另一个文件`requirements.txt`，并将依赖的组件框架写入到文件中：

```
flask
redis
```



## 创建一个 dockerfile

编写一个`Dockerfile`来构建一个Docker镜像。该镜像包含`Python`应用程序需要的所有依赖项，包括`Python`本身。

在项目目录`/compose_example`中，创建一个名为`Dockerfile`并粘贴以下内容的文件：

```dockerfile
# 依赖的基础 python
FROM python:3.4-alpine
# 将当前目录代码添加到 code目录
ADD . /code
# 设置当前工作目录 为code
WORKDIR /code
# 运行pip 命令 安装依赖
RUN pip install -r requirements.txt
# 执行 python app.py
CMD ["python", "app.py"]
```

上面的文件内容告诉Docker：

- 从Python 3.4镜像开始构建一个镜像。
- 将当前目录添加`.`到`/code`镜像的路径中。
- 将工作目录设置为`/code`。
- 安装Python依赖项。
- 将容器的默认命令设置为`python app.py`。
  ​

## 定义服务

创建一个`docker-compose.yml` 文件放在项目目录`/compose_example`中，文件内容如下：

```yaml
version: '3'
services:
  web:
    build: .
    ports:
     - "5000:5000"
  redis:
    image: "redis:alpine"
```

这个撰写文件定义了两个服务：`web`和`redis`服务：

- 使用`Dockerfile`当前目录中构建的镜像。
- 将容器上的暴露端口`5000`转发到主机上的端口`5000`。我们使用`Flask Web`，服务器的默认端口`5000`。

该`redis`服务使用从Docker Hub注册表中提取的公共 [Redis](https://registry.hub.docker.com/_/redis/)镜像。



## 构建镜像和运行程序

1、从项目目录`/compose_example`中，运行启动应用程序`docker-compose up`

```shell
$ docker-compose up
Creating network "composeexample_default" with the default driver
Building web
Step 1/5 : FROM python:3.4-alpine
3.4-alpine: Pulling from library/python
Digest: sha256:989b6044c434ffadf4dbc116719d73e7e31f5ac0f75f59b7591aeb766c874e26
Status: Downloaded newer image for python:3.4-alpine
 ---> 6610ae9fa51a
Step 2/5 : ADD . /code
 ---> 260f5df5d413
Step 3/5 : WORKDIR /code
Removing intermediate container a9713061bce0
 ---> 0e45bc38d999
Step 4/5 : RUN pip install -r requirements.txt
 ---> Running in c093d42d0b6d
......
web_1    |  * Running on http://0.0.0.0:5000/ (Press CTRL+C to quit)
web_1    |  * Restarting with stat
web_1    |  * Debugger is active!
```

`compose`会拉取`redis`的镜像，为代码构建镜像，并启动定义的服务。在这种情况下，代码在构建时会复制到镜像中。

2、测试程序 http://192.168.99.100:5000/ ，如果是`win7` 电脑的情况，通过宿主主键访问 docker上的机器需要用 `machine` 机器的`ip`去访问。也可以直接到构建镜像的机器上运行curl访问

```shell
$ docker-machine ssh default
$ curl http://192.168.99.100:5000/
Hello World! I have been seen 1 times.
```

其他系统可以直接在机器上访问，也就是说你操作的docker构建程序的机器：http://localhost:5000 <br/>不知道 `machine`  ip地址的情况可以运行命令查看：`docker-machine ip default`

3、当我们重新请求 http://192.168.99.100:5000/ 发现里面的数据在累加

```shell
Hello World! I have been seen 3 times.
```

4、打开一个新的终端窗口，由于之前的窗口运行没有开启后台模式。输入命令`docker image ls`查看镜像列表

```shell
$ docker image ls
REPOSITORY                                      TAG                 IMAGE ID            CREATED             SIZE
composeexample_web                              latest              bc9f08679f4f        16 minutes ago      94.6MB
myhello                                         latest              75be173204aa        5 days ago          150MB
registry.cn-hangzhou.aliyuncs.com/hoo_jo/test   hello_world         75be173204aa        5 days ago          150MB
hoo_jo/test                                     hello_world         75be173204aa        5 days ago          150MB
hoojo/test                                      my_hello_world      75be173204aa        5 days ago          150MB
hello-world                                     latest              e38bc07ac18e        6 days ago          1.85kB
nginx                                           latest              b175e7467d66        7 days ago          109MB
redis                                           alpine              98bd7cfc43b8        3 weeks ago         27.8MB
python                                          2.7-slim            b16fde09c92c        3 weeks ago         139MB
python                                          3.4-alpine          6610ae9fa51a        3 weeks ago         83.6MB
```

上面有些是之前构建的镜像，可以看到依赖的 `python`、`redis`、`composeexample_web` 都在。

5、卸载删除应用程序运行命令 `docker-compose down` ，先进入到有 `docker-componse.yml`的目录下执行

```shell
$ cd docker/compose_example/
$ docker-compose down
Stopping composeexample_redis_1 ... done
Stopping composeexample_web_1   ... done
Removing composeexample_redis_1 ... done
Removing composeexample_web_1   ... done
Removing network composeexample_default
```

这样程序就被成功卸载删除并且停止

## 编辑 compose 文件挂载程序

从项目目录`/compose_example`中，修改 `docker-compose.yml` 文件添加挂载目录，挂载目录指向本地的程序工作目录。

```yaml
version: '3'
services:
  web:
    build: .
    ports:
     - "5000:5000"
    volumes:
     - .:/code
  redis:
    image: "redis:alpine"
```

新的`volumes`将主机上的项目目录（当前目录）挂载到容器内的`/code`目录中，允许即时修改代码，而无需重新构建发布镜像。

## 热部署应用程序

在项目目录`/compose_example`中执行构建启动命令`docker-compose up`

```shell
$ docker-compose up
Creating network "composeexample_default" with the default driver
Creating composeexample_web_1   ... done
Creating composeexample_redis_1 ... done
Attaching to composeexample_redis_1, composeexample_web_1
web_1    | python: can't open file 'app.py': [Errno 2] No such file or directory
```

运行后发现找不到程序，说目录或文件不存在。这个是由于我们的程序没有放在当前操作用户的目录下，如：`C:\Users` 或 `cd ~` 的目录。解决办法就是需要将当前工作目录的所在磁盘进行共享。让当前虚拟机能够访问到当前工作目录的磁盘。

> 共享当前工作目录到指定虚拟机，这里操作的虚拟机是 `default`。<br/>1、在桌面找到`Oracle VM VirtualBox`打开软件，在左侧找到虚拟机`default`，右键点击设置。弹出设置窗口后，选择`共享文件夹`，添加当前工作目录`D:\docker\compose_example`进行共享设置，共享目录名称为 `compose_example`。<br/>2、将刚才设置共享的目录`compose_example` 挂载到指定目录`/mnt/compose_example`上，命令行如下：
>
> ```shell
> $ docker-machine ssh default "sudo mkdir /mnt/compose_example"
> $ docker-machine ssh default "sudo chmod 755 /mnt/compose_example"
> $ docker-machine ssh default "sudo mount -t vboxsf compose_example /mnt/compose_example"
> ```

**再次修改 `docker-compose.yml`文件，修改挂载目录设置配置**，内容如下：

```yaml
version: '3'
services:
  web:
    build: .
    ports:
     - "5000:5000"
    volumes:
     - "/mnt/compose_example:/code" 
  redis:
    image: "redis:alpine"
```

这样再次启动`docker-compose up`后，容器内的`/code`目录中，允许即时修改代码，而无需重新构建发布镜像。通过访问请求 http://192.168.99.100:5000/ 发现里面的数据在累加

```shell
Hello World! I have been seen 3 times.
```

## 修改应用程序

由于应用程序代码现在使用`volumes`挂载到容器中，因此可以更改代码并立即查看效果，而无需重新构建镜像进行重启操作。

修改`app.py`文件内容，修改返回值的内容，修改后的内容如下

```python
return 'Hello World! OMG!! I have been seen {} times.\n'.format(count)
```

通过访问请求 http://192.168.99.100:5000/ 发现内容已经变化了

```
Hello World! OMG!! I have been seen 12 times.
```



## 其他命令

### 后台模式

---

如果想在后台运行服务，可以将`-d`标志（“分离或后台”模式）传递给`docker-compose up`

```shell
$ docker-compose up -d
composeexample_redis_1 is up-to-date
composeexample_web_1 is up-to-date
```

### 查看日志

---

在后台模式下可以查看日志 `docker-compose logs`

```shell
$ docker-compose logs
$ docker-compose logs redis
```

### 查看运行的服务

---

并用于`docker-compose ps`查看当前正在运行的内容：

```shell
$ docker-compose ps
         Name                       Command               State           Ports
----------------------------------------------------------------------------------------
composeexample_redis_1   docker-entrypoint.sh redis ...   Up      6379/tcp
composeexample_web_1     python app.py                    Up      0.0.0.0:5000->5000/tcp
```

### 运行一次性

---

`docker-compose run`命令允许为服务运行一次性命令。例如，查看哪些环境变量可用于`Web`服务：

```shell
$ docker-compose run web env
PATH=/usr/local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
HOSTNAME=22e8f668029c
LANG=C.UTF-8
GPG_KEY=97FC712E4C024BBEA48A61ED3A5CA953F73C700D
PYTHON_VERSION=3.4.8
PYTHON_PIP_VERSION=9.0.3
HOME=/root
```

### 停止服务

---

如果开始使用`docker-compose up -d`进行启动服务，在完成后停止服务操作如下：

```shell
$ docker-compose stop
Stopping composeexample_web_1   ...
Stopping composeexample_redis_1 ...
```

### 卸载应用

---

可以把所有东西都卸载下来，用`docker-compose down`命令完全移除容器。通过`--volumes`还可以删除`redis`容器使用的数据量：

```shell
$ docker-compose down --volumes
Removing composeexample_web_run_1 ... done
Removing composeexample_web_1     ... done
Removing composeexample_redis_1   ... done
Removing network composeexample_default
```



## 命令行汇总

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

# 在集群中使用 `compose`

Docker Compose和Docker Swarm 主要是实现完全集成，这意味着可以将一个Compose应用程序指向一个Swarm集群，并且只需像使用单个Docker主机一样的操作工作即可。

实际的集成范围取决于使用的Compose文件格式的版本：

* 如果使用版本1和`links` ，则应用程序可以正常工作，但Swarm会将**所有容器安排在一台主机上**，因为容器之间的链接**不适用**于使用**旧网络**系统的主机。
* 如果使用的是版本2，则应用程序应该无任何更改：
  - 受下述[限制的影响](https://docs.docker.com/compose/swarm/#limitations)，
  - 只要Swarm集群配置为使用[覆盖驱动程序](https://docs.docker.com/engine/userguide/networking/#an-overlay-network-with-docker-engine-swarm-mode)或支持多主机联网的自定义驱动程序即可。

阅读多主机网络入门，了解如何使用Docker Machine和覆盖驱动程序设置Swarm群集。运行后，将应用程序部署到该应用程序应该如此简单：

```sh
$ eval "$(docker-machine env --swarm <name of swarm master machine>)"
$ docker-compose up
```

## 限制

### 构建图像

---

Swarm可以像Docker实例一样从Dockerfile构建一个映像，但生成的映像只能存在于**单个节点**上，**不会分发**给其他节点。如果您想使用Compose将有问题的服务**扩展到多个节点**，请构建映像，将其推送到诸如Docker Hub的注册表，然后从`docker-compose.yml`中引用它：

```sh
# 构建镜像
$ docker build -t myusername/web .
# 推送到仓库
$ docker push myusername/web

$ cat docker-compose.yml
web:
  image: myusername/web

# 上线装载
$ docker-compose up -d
# 扩展副本
$ docker-compose scale web=3
```

### 多重依赖

---

如果一个服务具有**强制共同调度的类型的多个依赖**关系（请参阅[自动调度](https://docs.docker.com/compose/swarm/#automatic-scheduling)），则Swarm可能会**调度不同节点**上的依赖关系，从而无法安排依赖服务。例如，这里`foo`需要与`bar`和`baz`共同安排调度：

```yaml
version: "2"
services:
  foo:
    image: foo
    volumes_from: ["bar"]
    network_mode: "service:baz"
  bar:
    image: bar
  baz:
    image: baz
```

问题在于Swarm可能会首先在不同的节点上调度`bar`和`baz`（因为它们不依赖于其他节点），因此无法为`foo`选择合适的节点。

要解决此问题，请使用[手动调度](https://docs.docker.com/compose/swarm/#manual-scheduling)来确保所有三个服务都在**同一个节点上**结束：

```yaml
version: "2"
services:
  foo:
    image: foo
    volumes_from: ["bar"]
    network_mode: "service:baz"
    environment:
      - "constraint:node==node-1"
  bar:
    image: bar
    environment:
      - "constraint:node==node-1"
  baz:
    image: baz
    environment:
      - "constraint:node==node-1"
```

### 主机端口和重新创建容器

如果服务从主机映射端口（例如`80:8000`），那么`docker-compose up`在第一次运行之后，可能会遇到如下错误：

```
docker: Error response from daemon: unable to find a node that satisfies
container==6ab2dfe36615ae786ef3fc35d641a260e3ea9663d6e69c5b70ce0ca6cb373c02.
```

这种错误的常见原因是**容器在没有显式映射**的情况下具有一个卷（在其图像或compose文件中定义），因此为了保留其数据，Compose已指示Swarm安排新容器与旧容器相同的节点。这导致了**端口冲突**。

这个问题有两种可行的解决方法：

- **指定一个已命名**的卷，并使用一个卷驱动程序，该卷驱动程序能够将该卷挂载到容器中，而不管其预定的节点。

  如果服务仅使用命名卷，则Compose不会为Swarm提供任何特定的计划指示。

  ```yaml
  version: "2"
  
  services:
    web:
      build: .
      ports:
        - "80:8000"
      volumes:
        - web-logs:/var/log/web
  
  volumes:
    web-logs:
      driver: custom-volume-driver
  ```

- 在创建新容器之前**删除旧容器**。会**丢失**卷中的任何数据。

  ```sh
  $ docker-compose stop web
  $ docker-compose rm -f web
  $ docker-compose up web
  ```

## 调度容器

### 自动调度

---

某些配置选项会**导致容器在同一个Swarm节点上**自动调度，以确保它们正常工作。这些是：

- `network_mode: "service:..."`和`network_mode: "container:..."`（以及 `net: "container:..."`第一版文件格式）。
- `volumes_from`
- `links`

### 手动调度

---

Swarm提供了丰富的调度安排和亲和力提示，使您可以控制容器的分布位置。它们是通过容器**环境变量指定**的，因此可以使用Compose的`environment`选项来设置它们。

```yaml
# Schedule containers on a specific node
environment:
  - "constraint:node==node-1"

# Schedule containers on a node that has the 'storage' label set to 'ssd'
environment:
  - "constraint:storage==ssd"

# Schedule containers where the 'redis' image is already pulled
environment:
  - "affinity:image==redis"
```

# 环境变量

## 命令行环境变量

有几个环境变量可供配置`Docker Compose`命令行使用。以`DOCKER_`开头的变量与用于配置`docker`命令行客户端的变量相同。如果正在使用`docker-machine`，那么`eval "$(docker-machine env my-docker-vm)"`命令应该将它们设置为正确的值。（在本例中，`my-docker-vm`是创建的机器的名称）



### 基本的环境变量

---

### COMPOSE_PROJECT_NAME

设置项目名称，在启动时，此值将与服务名称一起预先添加到容器中。例如，如果你的项目名称为`myapp`，它包括两个服务`db`和`web`，然后compose分别启动名为`myapp_db_1`和`myapp_web_1`的容器。

设置是可选的，如果不设置此项，则`COMPOSE_PROJECT_NAME` 默认为项目目录的基本名称。另请参阅`-p`命令行选项。

### COMPOSE_FILE

指定compose文件的路径。如果未提供，则compose会在当前目录中查找名为`docker-compose.yml`的文件，然后依次查找每个父目录，直到找到该名称的文件。

此变量支持多个由路径分隔符分隔的Compose文件（在Linux和MacOS上，路径分隔符是`:`在Windows上`;`）。例如：`COMPOSE_FILE=docker-compose.yml:docker-compose.prod.yml`。路径分隔符也可以使用自定义`COMPOSE_PATH_SEPARATOR`。

### COMPOSE_API_VERSION

`Docker API`仅支持来自特定版本的客户端的请求。如果使用 `docker-compose`收到`client and server don't have same version`错误，可以通过设置此环境变量来解决此错误，设置版本值以匹配服务器版本。

设置此变量解决需要临时运行客户端和服务器版本之间不匹配的情况。例如如果您可以升级客户端，但需要等待升级服务器。

使用此变量和已知的不匹配的版本，会阻止某些Docker功能正常工作。功能失败将取决于Docker客户端和服务器版本。出于这个原因，使用此变量集运行仅用作解决方法，并且不受官方支持。

如果遇到使用此设置运行的问题，请通过**升级解决不匹配问题并删除此设置**，以查看通知是否解决了问题。

### DOCKER_HOST

设置`docker`守护进程的`URL `。与Docker客户端一样，默认为`unix:///var/run/docker.sock`。

### DOCKER_TLS_VERIFY

当设置为除空字符串之外的任何其他字符时，都将启用与`docker`守护程序`TLS`的通信。

### DOCKER_CERT_PATH

配置用于TLS验证的`ca.pem`，`cert.pem`以及`key.pem`文件的路径。默认为`~/.docker`。

### COMPOSE_HTTP_TIMEOUT

配置`docker`守护进程的请求在`compose`认为失败之前允许挂起的时间（以秒为单位）。默认为`60`秒。

### COMPOSE_TLS_VERSION

配置哪些`TLS`版本用于与docker守护进程的通信。默认为`TLSv1`。支持的值是：`TLSv1`, `TLSv1_1`, `TLSv1_2`。

### COMPOSE_CONVERT_WINDOWS_PATHS

在卷定义中启用从`Windows`风格到`unix`风格的路径转换。`docker`和`docker toolbox`的用户应该始终设置这个。默认值为0，支持的值：`true`或`1 `启用，`false`或`0 `禁用。

### COMPOSE_PATH_SEPARATOR

如果设置`COMPOSE_FILE`则使用此字符作为路径分隔符，来分隔环境变量的值。

### COMPOSE_FORCE_WINDOWS_HOST

如果设置了，则假定主机路径是`Windows`路径，则使用短语法的卷声明将被解析，即使`compose`正在基于`Unix`的系统上运行。支持的值：`true`或`1`启用，`false`或`0`禁用。

### COMPOSE_IGNORE_ORPHANS

如果设置，compose不会尝试检测孤立项目容器。支持的值：`true`或`1`启用，`false`或`0`禁用。

### COMPOSE_PARALLEL_LIMIT

设置compose可以并行执行的操作数量的限制。默认值是`64`，可能不会低于`2`。

### COMPOSE_INTERACTIVE_NO_CLI

如果设置，compose不会尝试使用`docker cli`进行交互式运行和执行操作。此选项在上述操作需要`cli`的窗口中不可用。支持：`true`或`1`启用，`false`或`0`禁用。



### 在文件中配置环境变量
---

compose支持在执行`docker-compose`命令（当前工作目录）的文件夹中，建立名为`.env`的环境配置文件中声明默认环境变量。

#### 基本语法规则

这些语法规则适用于`.env`文件：

- compose期望`.env`文件中的每一行都是`VAR=VAL`格式。
- 开头的行`#`被处理为注释并被忽略。
- 空白行被忽略。
- 没有特殊的引号处理。这意味着 **它们是VAL的一部分**。


#### compose 文件和命令行变量

在此定义的环境变量用于Compose文件中的[变量替换](https://docs.docker.com/compose/compose-file/#variable-substitution)，也可用于定义以下[CLI变量](https://docs.docker.com/compose/reference/envvars/)：

- `COMPOSE_API_VERSION`
- `COMPOSE_CONVERT_WINDOWS_PATHS`
- `COMPOSE_FILE`
- `COMPOSE_HTTP_TIMEOUT`
- `COMPOSE_TLS_VERSION`
- `COMPOSE_PROJECT_NAME`
- `DOCKER_CERT_PATH`
- `DOCKER_HOST`
- `DOCKER_TLS_VERIFY`

运行时环境中的值**始终会覆盖`.env`文件中定义的值**。同样，通过**命令行参数传递的值最优先**。

在`.env`文件中定义的环境变量在容器中不可见。要设置容器适用的环境变量，请遵循compose中的[主题环境变量](https://docs.docker.com/compose/environment-variables/)中的指导原则，该指南描述了如何将`shell`环境变量传递给容器，如何在compose文件中定义环境变量等。

## 在 compose 中使用环境变量

### 替换 Compose 文件中的环境变量

---

可以在shell中使用环境变量来填充Compose文件中的值：

```yaml
web:
  image: "webapp:${TAG}"
```

有关更多信息，请参阅撰写文件参考中的 [变量替换](https://docs.docker.com/compose/compose-file/#variable-substitution)部分。

### 在容器中设置环境变量

---

可以使用`environment`在服务的容器中设置环境变量，就像使用`docker run -e VARIABLE = VALUE ...`：

```yaml
web:
  environment:
    - DEBUG=1
```

### 将环境变量传递给容器

---

可以直接通过环境变量`environment`将shell中的环境变量传递给服务的容器，方法是不给它们赋值，就像`docker run -e VARIABLE ...`一样：

```yaml
web:
  environment:
    - DEBUG
```

所述的值`DEBUG`在容器变量是从值取为在其中撰写运行在壳中的相同变量。

### `env_file` 配置选项

---

可以使用[`env_file`选项](https://docs.docker.com/compose/compose-file/#envfile)将多个环境变量从**外部文件**传递到服务的容器，就像`docker run --env-file=FILE ...`：

```yaml
web:
  env_file:
    - web-variables.env
```

### 用`docker-compose run`设置环境变量

---

与之类似`docker run -e`，可以在一次性容器上设置环境变量`docker-compose run -e`：

```sh
$ docker-compose run -e DEBUG=1 web python console.py
```

你也可以通过从shell中传递一个变量，而不给它一个值：

```sh
$ docker-compose run -e DEBUG web python console.py
```

容器中`DEBUG`变量的值取自运行Compose的shell中相同变量的值。

### `.env` 文件

---

可以在以下[环境文件中](https://docs.docker.com/compose/env-file/) 为在Compose文件中引用的任何环境变量设置默认值，或者用于配置Compose `.env`：

```sh
$ cat .env
TAG=v1.5

$ cat docker-compose.yml
version: '3'
services:
  web:
    image: "webapp:${TAG}"
```

`docker-compose up`运行时，上面定义的`web`服务使用图像`webapp:v1.5`。可以使用[config命令](https://docs.docker.com/compose/reference/config/)验证此问题，该 [命令](https://docs.docker.com/compose/reference/config/)会将已解析的应用程序配置打印到终端：

```sh
$ docker-compose config

version: '3'
services:
  web:
    image: 'webapp:v1.5'
```

shell中的值**优先**于`.env`文件中指定的值。如果在shell中将`TAG`设置为不同的值，则`image`中的替换将使用该值：

```sh
$ export TAG=v2.0
$ docker-compose config

version: '3'
services:
  web:
    image: 'webapp:v2.0'
```

当您在多个文件中设置相同的环境变量时，以下是Compose用于选择要使用的值的优先级：

1. compose文件
2. 环境文件
3. Dockerfile
4. 变量未定义

在下面的例子中，我们在`Environment`文件和`Compose`文件上设置了相同的环境变量：

```sh
$ cat ./Docker/api/api.env
NODE_ENV=test

$ cat docker-compose.yml
version: '3'
services:
  api:
    image: 'node:6-alpine'
    env_file:
     - ./Docker/api/api.env
    environment:
     - NODE_ENV=production
```

运行容器时，在撰写文件中定义的环境变量优先。

```sh
$ docker-compose exec api node

> process.env.NODE_ENV
'production'
```

有任何`ARG`或`ENV`在设置`Dockerfile`只有当不存在用于多克撰写的条目评估板`environment`或`env_file`。

只有在`environment`或`env_file`没有Docker Compose 配置时，Dockerfile中的任何`ARG`或`ENV`设置才会被有使用的可能。

### 使用环境变量配置compose

---

有几个环境变量可供配置Docker Compose命令行行为。它们以[CLI环境变量](https://docs.docker.com/compose/reference/envvars/)开头`COMPOSE_`或`DOCKER_`记录在[CLI环境变量中](https://docs.docker.com/compose/reference/envvars/)。

### 由链接创建的环境变量

---

在[v1撰写文件中](https://docs.docker.com/compose/compose-file/#version-1)使用['links'选项](https://docs.docker.com/compose/compose-file/#links)时 ，会为每个链接创建环境变量。它们记录在[Link环境变量参考中](https://docs.docker.com/compose/link-env-deprecated/)。但是，这些变量已被弃用。改为使用链接别名作为主机名。

# compose 文件组合配置

Compose支持两种共享通用配置的方法：1、使用多个Compose文件扩展组合单个 Compose文件。2、通过`extends`字段扩展多个服务。

## 多个 `compose` 文件组合

使用多个Compose文件使您可以为**不同的环境**或**不同的工作流**自定义Compose应用程序。

### 理解多个 `compose`文件

---

默认情况下，Compose读取两个文件，一个是`docker-compose.yml`和一个可选的`docker-compose.override.yml`文件。按照惯例，`docker-compose.yml`包含您的**基本配置**。顾名思义，覆盖文件可以包含**现有服务**或**全新服务**的配置覆盖。

如果在两个文件中定义了服务，Compose将使用添加和覆盖配置中描述的规则**合并配置**。

要使用多个覆盖文件或具有不同名称的覆盖文件，可以使用`-f`选项指定文件列表。按照它们在命令行上指定的顺序组合文件。有关使用`-f`的更多信息，请参阅docker-compose命令参考。

在使用多个配置文件时，必须确保文件中的所有路径都与基础Compose文件（使用`-f`指定的**第一个Compose文件**）相关。这是**必需的**，因为覆盖文件不需要是有效的Compose文件。覆盖文件可以包含**小部分配置**。跟踪哪个服务片段与哪个路径相关是困难和混乱的，因此为了使路径更容易理解，所有路径必须**相对于基本文件**进行定义。

### 示例参考

---

有两个常见的用于多个compose文件的使用案例：更改不同环境下的Compose应用程序，以及针对Compose应用程序运行管理任务。 

#### 不同环境的 `compose` 应用

多文件的常见用例是为类似生产环境（可能是生产、分期或CI）更改开发compose应用程序。为了支持这些差异，你可以将你的Compose配置分成几个不同的文件：

从定义服务规范配置的**基础文件**开始。文件：**docker-compose.yml**

```yaml
web:
  image: example/my_web_app:latest
  links:
    - db
    - cache

db:
  image: postgres:latest

cache:
  image: redis:latest
```

在这个例子中，开发配置向主机公开了一些**端口**，将我们的代码作为一个**卷**装入，并**构建**Web图像。文件：**docker-compose.override.yml**

```yaml
web:
  build: .
  volumes:
    - '.:/code'
  ports:
    - 8883:80
  environment:
    DEBUG: 'true'

db:
  command: '-d'
  ports:
    - 5432:5432

cache:
  ports:
    - 6379:6379
```

当你运行`docker-compose up`它自动读取文件进行覆盖。

现在，在生产环境中使用此Compose应用程序将会很好。因此，创建另一个覆盖文件。文件：**docker-compose.prod.yml**

```yaml
web:
  ports:
    - 80:80
  environment:
    PRODUCTION: 'true'

cache:
  environment:
    TTL: '500'
```

用这个生产Compose文件进行部署可以运行

```sh
$ docker-compose -f docker-compose.yml -f docker-compose.prod.yml up -d
```

这将使用`docker-compose.yml`和`docker-compose.prod.yml`（但不包括开发配置`docker-compose.override.yml`）中的配置部署所有三个服务 。

#### 管理任务

另一个常见用例是针对Compose应用程序中的一个或多个服务运行`adhoc`或管理任务。这个例子演示了运行数据库备份。

从**docker-compose.yml开始**。

```yaml
web:
  image: example/my_web_app:latest
  links:
    - db
db:
  image: postgres:latest
```

在**docker-compose.admin.yml中**添加一个**新服务来运行数据库导出或备份**。

```yaml
dbadmin:
  build: database_admin/
  links:
    - db
```

开始正常的环境运行`docker-compose up -d`。要运行数据库备份，也要包含它`docker-compose.admin.yml`。

```sh
$ docker-compose -f docker-compose.yml -f docker-compose.admin.yml \
    run dbadmin db-backup
```

## 扩展服务

> **注意：**在以前的Compose文件格式中支持`extends`关键字，直到Compose文件版本2.1（请参阅v1中的扩展和第2版中的扩展），但**在Compose版本3.x中不受支持**。请参阅第3版的添加和删除键摘要以及有关如何升级的信息。请参阅[moby/moby#31101](moby/moby#31101)以关注在未来版本中添加对某种形式的扩展的支持的可能性。

Docker Compose的`extends`关键字可以在不同文件之间**共享通用**配置，甚至可以完全共享不同的项目。如果您有多个服务可以**重复使用**一组**通用配置**选项，则扩展服务很有用。使用`extends`你可以在一个地方**定义一套通用的服务**选项并从任何地方引用它。

请记住，`links`，`volumes_from`和`depends_on`永远**不会**在使用`extends`的服务之间共享。这些例外存在以**避免隐式依赖性**。您始终在本地定义`links`和`volumes_from`。这可以确保在读取当前文件时，服务之间的**依赖关系清晰可见**。在本地定义这些也确保对引用文件的更改**不会破坏**任何内容。

### 理解扩展配置

---

在`docker-compose.yml`定义任何服务时，可以声明正在扩展另一个服务，如下所示：

```yaml
web:
  extends:
    file: common-services.yml
    service: webapp
```

这指示Compose重新使用`common-services.yml`文件中`webapp`定义的服务的配置。假设`common-services.yml` 看起来像这样：

```yaml
webapp:
  build: .
  ports:
    - "8000:8000"
  volumes:
    - "/data"
```

在这种情况下，可以得到与使用与`web`直接定义的相同`build`，`ports`和`volumes`配置值编写`docker-compose.yml`完全相同的结果。

可以进一步在本地定义（或重新定义）配置 `docker-compose.yml`：

```yaml
web:
  extends:
    file: common-services.yml
    service: webapp
  environment:
    - DEBUG=1
  cpu_shares: 5

important_web:
  extends: web
  cpu_shares: 10
```

还可以编写其他服务并将`web`服务链接到它们：

```yaml
web:
  extends:
    file: common-services.yml
    service: webapp
  environment:
    - DEBUG=1
  cpu_shares: 5
  links:
    - db
db:
  image: postgres
```

### 示例参考

---

当有多个具有通用配置的服务时，扩展单个服务很有用。下面的例子是一个包含两个服务的Compose应用程序：一个`Web`应用程序和一个队列工作者。这两个服务使用**相同的代码库并共享许多配置**选项。

在**common.yml中**我们定义了通用配置：

```yaml
app:
  build: .
  environment:
    CONFIG_FILE_PATH: /code/config
    API_KEY: xxxyyy
  cpu_shares: 5
```

在**docker-compose.yml**中，我们定义了使用通用配置的具体服务：

```yaml
webapp:
  extends:
    file: common.yml
    service: app
  command: /code/run_web_app
  ports:
    - 8080:8080
  links:
    - queue
    - db

queue_worker:
  extends:
    file: common.yml
    service: app
  command: /code/run_worker
  links:
    - queue
```

### 添加和覆盖配置

---

将原始服务的复制配置**复制到本地服务器**。如果在原始服务和本地服务中都定义了配置选项，则本地值**将替换**或**扩展**原始值。

对于单值选项`image`，`command`或者`mem_limit`，新值替换旧值。

```yaml
# original service
command: python app.py

# local service
command: python otherapp.py

# result，被覆盖
command: python otherapp.py
```

> `build` & `image`在 `compose v1` 中 <br/>在构建和映像的情况下，如果使用Compose文件格式的版本1，则在本地服务中使用一个选项会导致Compose放弃在原始服务中定义的其他选项。<br/>例如，如果原始服务定义`image: webapp`并且本地服务定义，`build: .`那么生成的服务有一个 `build: .`和没有`image`选项。<br/>这是**因为`build`和`image`不能在版本1文件中一起使用**。

对于**多值的选项** `ports`，`expose`，`external_links`，`dns`， `dns_search`，和`tmpfs`，compose会将两组值进行组合连接：

```yaml
# original service
expose:
  - "3000"

# local service
expose:
  - "4000"
  - "5000"

# result，拼接一起
expose:
  - "3000"
  - "4000"
  - "5000"
```

在`environment`，`labels`，`volumes`，和`devices`的情况下，**优先使用本地**定义的值编写“合并”条目。对于`environment`和`labels`，**环境变量或标签名称**决定使用哪个值：

```yaml
# original service
environment:
  - FOO=original
  - BAR=original

# local service
environment:
  - BAR=local
  - BAZ=local

# result
environment:
  - FOO=original
  - BAR=local # 被合并
  - BAZ=local
```

`volumes`和`devices`的条目使用容器中的装载路径进行合并：

```yaml
# original service
volumes:
  - ./original:/foo
  - ./original:/bar

# local service
volumes:
  - ./local:/bar
  - ./local:/baz

# result
volumes:
  - ./original:/foo # 被合并
  - ./local:/bar
  - ./local:/baz
```

# compose 网络

> **提示**：只有在使用Compose文件格式的**版本2或更高版本**时，本文才适用。网络功能**不支持版本1**（传统）compose文件。

默认情况下，Compose会为应用程序设置一个网络。服务的每个容器**都加入默认网络**，并且该网络上的**其他容器都可以访问它们**，并且可以**通过与容器名称相同的主机名**来**发现**它们。

> **注意**：根据**项目名称**为应用程序的**网络**提供了一个名称，该名称基于**所在目录的名称**。可以使用`--project-name`标志或`COMPOSE_PROJECT_NAME`环境变量覆盖项目名称。

例如，假设应用程序位于一个名为`myapp`的目录中，并且`docker-compose.yml`如下所示：

```yaml
version: "3"
services:
  web:
    build: .
    ports:
      - "8000:8000"
  db:
    image: postgres
    ports:
      - "8001:5432"
```

运行时`docker-compose up`，会发生以下情况：

1. 被调用的网络`myapp_default`被创建。
2. 容器是使用`web`配置创建的。它以名字`web`加入网络`myapp_default` 。
3. 容器是使用`db`配置创建的。它以名字 `db`加入网络`myapp_default`。

> **在v2.1 +中，覆盖网络总是可以 attachable**<br/>从compose文件格式2.1开始，覆盖网络总是被创建可 `attachable`，并且这是**不可配置**的。这意味着**独立容器可以连接到覆盖网络**。<br/>在compose文件格式3.x中，可以选择将`attachable`属性设置为`false`。

每个容器现在可以查找主机名`web`或`db`，并获**取适当的容器的IP地址**。 例如，`web`应用程序代码可以连接到URL `postgres://db:5432`并开始使用Postgres数据库。

注意`HOST_PORT`和`CONTAINER_PORT`之间的区别很重要。在上面的例子中，对于`db`，`HOST_PORT`是`8001`，而容器端口是`5432`（postgres 默认值）。联网的服务到服务通信使用`CONTAINER_PORT`。**当`HOST_PORT`被定义时，该服务也可以在集群外访问**。

在`Web`容器中，连接到`db`的连接字符串看起来像`postgres://db:5432`，并且从主机连接字符串看起来像`postgres://{DOCKER_IP}:8001`。

## 更新容器

如果对服务进行配置更改并运行`docker-compose up`以更新它，则**旧容器将被删除**，并且新容器将以**不同的IP地址**加入网络，但**名称相同**。正在运行的容器可以**查找该名称**并连接到**新地址**，但**旧地址停止工作**。

如果有任何容器连接到旧容器，它们将关闭。检测这种情况是容器的责任，再次查找名称并重新连接。

## 链接

链接允许定义**额外的别名**，通过它可以**从另一个服务访问服务**。他们不需要**启用服务**进行通信。 默认情况下，任何服务都可以以该**服务的名称到达任何其他服务**。在以下示例中，可通过主机名`db`和数据库从`Web`访问`db`：

```yaml
version: "3"
services:

  web:
    build: .
    links:
      - "db:database"
  db:
    image: postgres
```

## 多主机网络

> **注意**：多主机网络仅在针对传统Swarm集群时才起作用。

在将Compose应用程序部署到Swarm集群时，可以使用**内置的`overlay`覆盖驱动**程序启用容器之间的多主机通信，而不必更改Compose文件或应用程序代码。

请参阅多主机网络入门以了解如何设置Swarm群集。群集**默认使用覆盖驱动程序**，但如果您愿意，可以明确指定它。请参阅下文了解如何执行此操作。

## 使用自定义网络

可以**使用顶级`networks`指定自己的网络**，而不只是使用默认的应用程序网络。这使你**可以创建更复杂的拓扑网络并指定[自定义网络驱动程序](https://docs.docker.com/engine/extend/plugins_network/)和选项。还可以使用它将服务连接到不受Compose管理的外部创建的网络**。

每个服务都可以使用**服务级** `networks`来指定要连接的网络，引用**顶级** `networks`下的条目的名称列表。

以下是定义两个自定义网络的示例compose文件。该`proxy`服务与`db`服务是隔离的，因为它们**不共享**网络。只能`app`与两者通话。

```yaml
version: "3"
services:

  proxy:
    build: ./proxy
    networks:
      - frontend
  app:
    build: ./app
    networks:
      - frontend
      - backend
  db:
    image: postgres
    networks:
      - backend

networks:
  frontend:
    # Use a custom driver
    driver: custom-driver-1
  backend:
    # Use a custom driver which takes special options
    driver: custom-driver-2
    driver_opts:
      foo: "1"
      bar: "2"
```

可以通过为每个连接的网络设置[ipv4_address和ipv6_address](https://docs.docker.com/compose/compose-file/#ipv4-address-ipv6-address)来为网络**配置静态IP**地址。

有关可用网络配置选项的完整详细信息，请参阅以下参考资料：

- [顶级`networks`](https://docs.docker.com/compose/compose-file/#network-configuration-reference)
- [服务级别`networks`](https://docs.docker.com/compose/compose-file/#networks)

## 配置默认网络

除了指定自己的网络外，还可以通过在名为`default`的`networks`下定义条目来更改应用程序范围的默认网络的设置：

```yaml
version: "3"
services:

  web:
    build: .
    ports:
      - "8000:8000"
  db:
    image: postgres

networks:
  default:
    # Use a custom driver
    driver: custom-driver-1
```

## 使用预先存在的网络

如果希望容器加入预先存在的网络，请使用以下[`external`选项](https://docs.docker.com/compose/compose-file/#network-configuration-reference)：

```
networks:
  default:
    external:
      name: my-pre-existing-network
```

与试图创建名为`[projectname] _default`的网络，compose查找名为`my-pre-existing-network`的网络，并将应用的容器连接到该网络。

# 在生产环境中使用compose

当在开发中使用Compose定义应用程序时，可以使用此定义在不同环境中运行应用程序，如CI、分期和生产。

部署应用程序的最简单方法是在单个服务器上运行它，这与运行开发环境的方式类似。如果要扩展应用程序，可以在Swarm集群上运行Compose应用程序。

### 修改compose文件进行生产

可能需要对应用配置进行更改，以便为生产做好准备。这些更改可能包括：

- **删除**应用程序代码的任何**绑定卷**，以便**代码保留在容器**内，**不能从外部更改**
- **绑定**到主机上的不同**端口**
- 以不同方式**设置环境变量**，例如，当您需要减少日志的详细程度或启用电子邮件发送时）
- 指定**重启策略**`restart: always`以**避免停机**
- 添加额外的服务，如日志聚合器

出于这个原因，考虑**定义一个额外的Compose文件**，比如说 `production.yml`，它指定了适合生产的配置。此配置文件只需包含想要从**原始compose文件中需要的更改**。额外的compose文件可以应用于`docker-compose.yml`原始文件以创建新配置。

一旦你有第二个配置文件，利用Compose使用它的 `-f`选项：

```sh
$ docker-compose -f docker-compose.yml -f production.yml up -d
```

有关更完整的示例，请参阅[使用多个撰写文件](https://docs.docker.com/compose/extends/#different-environments)。

### 部署更改

当更改应用程序代码时，请记住**重新构建图像**并**重新创建应用程序**的容器。要重新部署所调用的`web`服务 ，请使用：

```sh
$ docker-compose build web
$ docker-compose up --no-deps -d web
```

首先重建图像`web`，然后**停止，销毁，并重新创建** 刚才的`web`服务。`--no-deps`标志**防止compose 重新创建任何`web`依赖**的服务。

### 在单台服务器上运行Compose

通过适当设置`DOCKER_HOST`，`DOCKER_TLS_VERIFY`和`DOCKER_CERT_PATH`环境变量，可以使用Compose将应用程序**部署到远程Docker主机**。对于这样的任务，Docker Machine使得管理本地和远程Docker主机变得非常简单，即使不远程部署也是推荐的。

一旦你设置了你的环境变量，所有正常的`docker-compose` 命令都不需要进一步的配置。

### 在Swarm集群上运行Compose

Docker Swarm是一个Docker本地集群系统，它将同一个API公开为一个Docker主机，这意味着可以将Compose用于Swarm实例并在多个主机上运行应用程序。

# 控制服务启动顺序

可以使用`depends_on`选项来控制**服务启动的顺序**。compose始终以**依赖性顺序启动容器**，依赖性由`depends_on`，`links`，`volumes_from`，和`network_mode: "service:..."`。

但是，Compose不会等到容器**准备就绪**，直到它运行。

例如，等待数据库准备就绪的问题实际上只是分布式系统的一个更大问题的一个。在生产中，数据库可能随时无法使用。您的应用程序需要适应这些类型的故障。

要处理这个问题，请设计应用程序以尝试在**发生故障后重新建立与数据库的连接**。如果应用程序重试连接，它最终可以连接到数据库。

最好的解决方案是在你的应用程序代码中**执行检查**，无论是在启动时，还是因任何原因丢失连接。但是，如果您不需要此级别的恢复能力，则可以使用**包装脚本**解决该问题：

- 使用[wait-for](https://github.com/vishnubob/wait-for-it)， [dockerize](https://github.com/jwilder/dockerize)或sh兼容的 [等待工具](https://github.com/Eficode/wait-for)。这些包装脚本可以包含在应用程序的映像中，以轮询主机和端口，直到它接受TCP连接。

  例如，要使用`wait-for-it.sh`或`wait-for`包装服务的命令：

  ```yaml
  version: "2"
  services:
    web:
      build: .
      ports:
        - "80:8000"
      depends_on:
        - "db"
      command: ["./wait-for-it.sh", "db:5432", "--", "python", "app.py"]
    db:
      image: postgres
  ```

  > **提示**：第一个解决方案存在局限性。例如，它不会验证特定服务何时准备就绪。如果向命令添加更多参数，请使用`bash shift`带有循环的命令，如下例所示。

- 或者，编写自己的包装脚本以执行更多特定于应用程序的**运行状况检查**。例如，可能要等到Postgres完全准备好接受命令：

  ```sh
  #!/bin/bash
  # wait-for-postgres.sh
  
  set -e
  
  host="$1"
  shift
  cmd="$@"
  
  until PGPASSWORD=$POSTGRES_PASSWORD psql -h "$host" -U "postgres" -c '\q'; do
    >&2 echo "Postgres is unavailable - sleeping"
    sleep 1
  done
  
  >&2 echo "Postgres is up - executing command"
  exec $cmd
  ```

  可以像前面的示例一样将其用作包装脚本，方法是设置：

  ```sh
  command: ["./wait-for-postgres.sh", "db", "python", "app.py"]
  ```

# compose 命令行

通过`docker-compose --help`来查看compose命令行的帮助，会显示配置和命令行列表。可以使用`Docker Compose`二进制文件`docker-compose [-f <arg>...][options] [COMMAND][ARGS...]`在Docker容器中构建和管理多个服务。

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
  down               停止并移除容器，网络，图像和卷
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



## 选项 `-f` 用法

使用`-f`指定一个或多个`compose`文件名称和路径，使用`-f`标志来指定`Compose`配置文件的位置。

### 指定多个 compose 文件

---

可以提供多个`-f`来配置文件。当提供多个文件时，Compose将它们组合成单个配置。Compose按提供文件的顺序构建配置。随后的文件会覆盖并添加到他们的前置文件。以下是示例：

```shell
$ docker-compose -f docker-compose.yml -f docker-compose.admin.yml run backup_db
```

该`docker-compose.yml`文件可能会指定一项`webapp`服务。

```yaml
webapp:
  image: examples/web
  ports:
    - "8000:8000"
  volumes:
    - "/data"
```

如果`docker-compose.admin.yml`也指定了这个相同的服务，任何匹配的字段都会覆盖前一个文件。新的值添加到`webapp`服务配置。**也就是说相同的字段会进行覆盖，不同的就会进行组合。**

```yaml
webapp:
  build: .
  environment:
    - DEBUG=1
```

该`-f`选项是可选的。**如果不在命令行上提供此选项**，则Compose会遍历工作目录及其父目录，以查找文件`docker-compose.yml`和`docker-compose.override.yml`文件，至少提供`docker-compose.yml`文件。**如果两个文件都存在于相同的目录级别，则Compose会将这两个文件组合到一个配置中**。

`docker-compose.override.yml`文件中的配置将应用于`docker-compose.yml`文件中的值。

### 指定单个 compose 文件

---

可以使用`-f`标志来指定不在当前目录中的文件的路径，无论是从命令行还是通过在`shell`或环境文件中设置`compose_file`环境变量。

对于在命令行中使用`-f`选项的示例，假设正在运行`compose example`示例，并在名为`docker/compose_example`的目录中具有`docker-compose.yml`文件。可以使用像`docker-compose pull`这样的命令，通过使用`-f`标志从任何地方获取`cache`服务的`redis`镜像，如下所示：`docker-compose -f /d/docker/compose_example/docker-compose.yml pull redis`

```shell
$ cd ~
$ docker-compose -f /d/docker/compose_example/docker-compose.yml pull redis
Pulling redis (redis:alpine)...
alpine: Pulling from library/redis
Digest: sha256:e6e3a62b67b4e5c956b8814ac64ce3fe531c1093606f2a4fe5492921f6592388
Status: Image is up to date for redis:alpine
```



## 使用`-p`指定项目名称

每个配置都有一个项目名称。如果提供`-p`标志，则可以指定项目名称。如果未指定标志，则`compose`使用**当前目录**名称。项目名称会对应`COMPOSE_PROJECT_NAME`环境变量。

## 基本命令

### up 装载

---

```shell
Usage: up [options] [--scale SERVICE=NUM...] [SERVICE...]

Options:
    -d, --detach               分离模式：在后台运行容器，打印新的容器名称。
                               不兼容 --abort-on-container-exit.
    --no-color                 产生单色输出.
    --quiet-pull               拉出没有打印进度信息
    --no-deps                  不要启动链接的服务.
    --force-recreate           重新创建容器，即使它们的配置和图像没有改变                               
    --always-recreate-deps     重新创建相关容器.
                               不兼容 --no-recreate.
    --no-recreate              如果容器已经存在，则不要重新创建他们
                               不兼容 --force-recreate and -V.
    --no-build                 不要构建图像，即使它不存在.
    --no-start                 创建后不要启动服务.
    --build                    在启动容器之前构建图像.
    --abort-on-container-exit  如果有容器，则停止所有容器停止
                               不兼容 -d.
    -t, --timeout TIMEOUT      对容器使用此超时（以秒为单位）
                               当连接时或容器被关闭时已经运行。 （默认：10）
                               
    -V, --renew-anon-volumes   重新创建匿名卷而不是检索来自之前容器的数据.
    --remove-orphans           移除未定义服务的容器在compose文件.
    --exit-code-from SERVICE   返回所选服务的退出代码容器
                               不兼容 --abort-on-container-exit.
    --scale SERVICE=NUM        将服务扩展到num实例. 如果存在覆盖，compose文件中的“缩放”设置.
```

**构建，（重新）创建，启动并附加**到服务的容器。除非它们已经在运行，否则该命令还会**启动任何关联**的服务。

该`docker-compose up`命令**汇总每个容器日志的输出**（相当于运行`docker-compose logs -f`），当命令退出时，所有容器都停止。<br/>运行`docker-compose up -d` 将在**后台启动容器并使其运行**。

**支持随时更新即热部署**：如果服务的已经有容器，并且在创建容器后服务的配置或镜像已更改，则`docker-compose up`通过停止并重新创建容器（保留已装入的卷）来提取更改。要防止`compose`的更改，请使用该`--no-recreate` 标志。

如果您想强制Compose停止并重新创建所有容器，请使用该 `--force-recreate`标志。

如果进程遇到错误，则此命令的退出代码为`1`。
如果使用`SIGINT`（`ctrl`+ `C`）中断进程或者`SIGTERM`容器停止，并且退出代码为`0`。
如果`SIGINT`或`SIGTERM`在此关闭阶段再次发送，正在运行的容器将被终止，并且退出代码为`2`。



### down 卸载

------

停止容器并移除由`up`创建的容器，网络，卷和镜像。

默认情况下，唯一删除的内容是：

- 在compose文件中定义的服务容器
- 在compose文件中定义的`networks`部分
- 默认网络（如果使用的话）

定义为外部`external` 的网络和卷永远不会被删除。

```shell
$ docker-compose down
Removing composeexample_redis_run_1 ... done
Removing composeexample_web_run_1   ... done
Removing network composeexample_default
```



### build 构建

---

服务构建一次，然后名称默认为`project_service`。例如，`composetest_db`。如果Compose文件指定了 [镜像](https://docs.docker.com/compose/compose-file/#image)名称，则镜像将用该名称进行设置。

如果修复也有程序的`Dockerfile`或其构建目录的内容，请运行`docker-compose build`以重建它。

```shell
$ docker-compose build
Building web
Step 1/5 : FROM python:3.4-alpine
 ---> 6610ae9fa51a
Step 2/5 : ADD . /code
 ---> 598dbdff6939
Step 3/5 : WORKDIR /code
.......
```

### bundle 打包

---

从Compose文件生成分布式应用程序包（DAB）。

镜像必须存储摘要，需要与Docker注册表进行交互。如果未为所有镜像存储摘要，可以使用`docker-compose pull` 或`docker-compose push`，打包时自动推送镜像，通过`--push-images`。只有`build`指定选项的服务才会推送其镜像。

```shell
$ docker login -u xxx -p xxxx
WARNING! Using --password via the CLI is insecure. Use --password-stdin.
Login Succeeded

$ docker-compose.exe build web
Building web
Step 1/5 : FROM python:3.4-alpine
 ---> 6610ae9fa51a
Step 2/5 : ADD . /code
 ---> ead50f337cd7
Step 3/5 : WORKDIR /code
.....

$ docker-compose bundle --push-image -o ./compose.dab
Pushing web (hoojo/test:compose_example)...
The push refers to repository [docker.io/hoojo/test]
compose_example: digest: sha256:1adecad81d64505cba06d071487ef16485d3de18d134d4cdcb308f4f82769409 size: 1786
Unsupported key 'volumes' in services.web - ignoring
Wrote bundle to ./compose.dab
```

上面的三步完成后，可以看到最后一步将打包好的镜像上传到仓库，并在当前目录生成了一个`compose.dab`文件。这个文件是摘要文件数据。



### config 配置

---

验证并查看compose文件，一般可以通过此命令检查`docker-compose.yml`是否编写正确。并且能显示`docker-compose.yml`的内容。

错误的配置文件：

```shell
$ docker-compose config
The Compose file '.\docker-compose.yml' is invalid because:
Unsupported config option for services.web: 'image2'
```

正确的配置文件：

```shell
$ docker-compose config
services:
  redis:
    image: redis:alpine
  web:
    build:
      context: D:\docker\compose_example
    image: hoojo/test:compose_example
    ports:
    - 5000:5000/tcp
    volumes:
    - /code:/code:rw
version: '3.0'
```



### events 事件

---

监控项目应用程序容器的事件动态。使用该`--json`标志，每行打印一个json对象，格式为：

```shell
$ docker-compose.exe events --json
{"time": "2018-04-19T18:00:54.483975", "type": "container", "action": "create", "id": "510e7d26795531b6ed9aa4e7deaeb982338726d251f9d4864e242fb0a3c2bb54", "service": "web", "attributes": {"name": "composeexample_web_1", "image": "hoojo/test:compose_example"}}
{"time": "2018-04-19T18:00:54.493158", "type": "container", "action": "attach", "id": "510e7d26795531b6ed9aa4e7deaeb982338726d251f9d4864e242fb0a3c2bb54", "service": "web", "attributes": {"name": "composeexample_web_1", "image": "hoojo/test:compose_example"}}
{"time": "2018-04-19T18:00:54.920329", "type": "container", "action": "start", "id": "510e7d26795531b6ed9aa4e7deaeb982338726d251f9d4864e242fb0a3c2bb54", "service": "web", "attributes": {"name": "composeexample_web_1", "image": "hoojo/test:compose_example"}}
```

启动后控制台将处于监控模式，这时候可以再打开一个窗口执行 `docker-compose build `和`docker-compose up`就可以看到数据。



### exec 执行

---

这相当于`docker exec`。使用此子命令可以在服务中运行任意命令。命令默认分配一个TTY，所以可以使用一个命令`docker-compose exec web sh`来获得交互式提示。

```shell
$ docker-compose ps --services
web
redis

$ docker-compose exec web sh
the input device is not a TTY.  If you are using mintty, try prefixing the command with 'winpty'

$ winpty docker-compose exec web sh
```

由于用`Git bash`在安装的时候没有选择**Use MinTTY**，所以这里就到 `Power Shell`工具中进行操作。还有一个解决办法就是根据提示执行命令：`$ winpty docker-compose exec web sh`

```powershell
PS D:\docker\compose_example> docker-compose.exe exec web sh
/code # ls
Dockerfile          compose.dab         requirements.txt
app.py              docker-compose.yml
```

运行上面的命令后，就可以查看当前`web`镜像的工作命令数据。还能与远程镜像数据进行交互。



### kill 杀死

---

通过发送信号`SIGKILL`来强制停止运行容器。可以选择传递信号，例如：

```shell
$ docker-compose kill -s SIGINT
Killing composeexample_redis_1 ...
Killing composeexample_web_1   ... done
Killing composeexample_redis_1 ... done
```



### logs 日志

---

显示服务的日志输出

```shell
$ docker-compose ps --services
web
redis

$ docker-compose logs redis

$ docker-compose logs web
Attaching to composeexample_web_1
web_1    |  * Running on http://0.0.0.0:5000/ (Press CTRL+C to quit)
web_1    |  * Restarting with stat
web_1    |  * Debugger is active!
web_1    |  * Debugger PIN: 184-102-760
```



### pause 暂停

---

暂停运行服务的容器，可以解除暂停 `docker-compose unpause`

```shell
$ docker-compose ps --services
web
redis

$ docker-compose pause web
Pausing composeexample_web_1 ... done

$ docker-compose unpause web
Unpausing composeexample_web_1 ... done
```



### port 端口

---

打印用于端口绑定的公共端口。下面是部署的web应用的端口，从之前编辑的`docker-compose.yml`中的`services`可以看出此服务。

```shell
$ docker-compose ps --services
web
redis

$ docker-compose port web 5000
0.0.0.0:5000
```



### ps 容器列表

---

显示容器列表

```shell
$ docker-compose ps
         Name                       Command               State           Ports
----------------------------------------------------------------------------------------
composeexample_redis_1   docker-entrypoint.sh redis ...   Up      6379/tcp
composeexample_web_1     python app.py                    Up      0.0.0.0:5000->5000/tcp

$ docker-compose ps --services
web
redis
```



### pull 拉取

---

提取在`docker-compose.yml`或`docker-stack.yml `文件中定义的服务相关联的镜像，但不会基于这些镜像启动容器。

```yaml
version: '3'
services:
  web:
    image: hoojo/test:compose_example
    build: .
    ports:
     - "5000:5000"
    volumes:
     - "/code:/code"
  redis:
    image: "redis:alpine"
```

执行定义服务的拉取`docker-compose pull ServiceName`需要在`docker-compose.yml`文件的所在的目录中运行，则Docker会拉取关联的镜像。例如，要在我们的示例中调用`redis:alpine`配置为`redis`服务的镜像，可以运行`docker-compose pull redis`。

```shell
$ docker-compose pull redis
Pulling redis (redis:alpine)...
alpine: Pulling from library/redis
Digest: sha256:e6e3a62b67b4e5c956b8814ac64ce3fe531c1093606f2a4fe5492921f6592388
Status: Image is up to date for redis:alpine
```



### push 推送

---

将服务的镜像推送到它们各自的位置`registry/repository`

做出以下假设：

- 您正在推送您在本地创建的镜像
- 您可以访问构建密钥

```yaml
version: '3'
services:
  service1:
    build: .
    image: localhost:5000/web  # goes to local registry

  service2:
    build: .
    image: hoojo/my_image:first  # goes to youruser DockerHub registry
```

当程序被构建执行时，会自动`push`到远程服务器仓库中。

```shell
$ docker-compose push
Pushing web (hoojo/test:compose_example)...
The push refers to repository [docker.io/hoojo/test]
compose_example: digest: sha256:aa0aa4df76f3676765a44f47825aabf1b1b579e37836f7d3b6a866416f3ac18e size: 1787
```



### start 启动

---

启动一个服务的现有容器。

```shell
$ docker-compose start
```



### stop 停止

---

停止运行容器而不删除它们。可以用`docker-compose start`重新启动。

```shell
$ docker-compose stop
```



### restart 重启

---

重新启动所有停止和正在运行的服务。<br/>如果对`docker-compose.yml`配置进行了更改，则运行此命令后这些更改不会反映出来。<br/>例如，对环境变量（在构建容器后但在容器的命令执行之前添加）的更改在重新启动后不会更新。

```shell
$ docker-compose restart
Restarting composeexample_redis_1 ... done
Restarting composeexample_web_1   ... done
```



### run 运行

---

**针对服务运行一次性命令**。例如，以下命令启动该`web`服务并`bash`作为其命令运行。

```shell
$ docker-compose run web sh # 执行命令后进入交互模式，随后可以执行shell的基本命令行
ls
Dockerfile
app.py
compose.dab
docker-compose.yml
requirements.txt

```

使用命令`run`从具有由服务定义的配置的新容器中启动，包括卷，链接和其他详细信息。但有两个重要的区别。

首先，通过命令`run`将覆盖服务配置中定义的命令。例如，如果`web`服务配置是用`bash`启动的，那么`docker-compose run web python app.py`会用`python app.py`覆盖它。

第二个区别是该`docker-compose run`命令不会创建服务配置中指定的任何端口。这可以防止端口与已打开的端口发生冲突。如果您*确实想要*创建服务的端口并将其映射到主机，请指定`--service-ports`标志：

```shell
$ docker-compose run --service-ports web python app.py shell
 * Running on http://0.0.0.0:5000/ (Press CTRL+C to quit)
 * Restarting with stat
 * Debugger is active!
 * Debugger PIN: 184-102-760
```

或者，可以使用`--publish`或`-p`选项指定手动端口映射，就像在使用时一样`docker run`：

```shell
$ docker-compose run --publish 8080:80 -p 2022:22 -p 127.0.0.1:2021:21 web python app.py shell
```

如果启动一个配置了链接的服务，则该`run`命令首先检查链接服务是否正在运行，并在服务停止时启动服务。一旦所有链接的服务正在运行，`run`执行通过它传递的命令。例如运行：

```shell
$ docker-compose run db psql -h db -U docker
```

这将为链接的`db`容器打开一个交互式`PostgreSQL shell`。

如果您不希望`run`命令启动链接的容器，请使用`--no-deps`标志：

```shell
$ docker-compose run --no-deps web python app.py shell
```



### rm 删除

------

删除已停止的服务容器。

默认情况下，附加到容器的匿名卷不会被删除。你可以用这个覆盖它`-v`。要列出所有卷，请使用`docker volume ls`。<br/>任何不在卷中的数据都会丢失。<br/>在没有选项的情况下运行该命令也会删除由`docker-compose up`或创建的一次性容器`docker-compose run`：

```shell
$ docker-compose rm
Going to remove djangoquickstart_web_run_1
Are you sure? [yN] y
Removing djangoquickstart_web_run_1 ... done
```



### top 显示

---

显示正在运行的进程。

```shell
$ docker-compose top

composeexample_redis_1
PID      USER       COMMAND
------------------------------
7373   dockrema   redis-server

composeexample_web_run_4
PID    USER                COMMAND
------------------------------------------------
7071   root   python app.py shell
7121   root   /usr/local/bin/python app.py shell

composeexample_web_run_5
PID    USER                COMMAND
------------------------------------------------
7556   root   python app.py shell
7606   root   /usr/local/bin/python app.py shell
```
