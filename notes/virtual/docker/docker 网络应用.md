# docker 网络应用

* [docker 网络应用](#docker-%E7%BD%91%E7%BB%9C%E5%BA%94%E7%94%A8)
* [概述](#%E6%A6%82%E8%BF%B0)
  * [网络驱动](#%E7%BD%91%E7%BB%9C%E9%A9%B1%E5%8A%A8)
    * [总结](#%E6%80%BB%E7%BB%93)
  * [Docker EE 网络](#docker-ee-%E7%BD%91%E7%BB%9C)
* [docker network 基本命令](#docker-network-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4)
  * [ls 查看](#ls-%E6%9F%A5%E7%9C%8B)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9)
    * [示例](#%E7%A4%BA%E4%BE%8B)
      * [查看网络](#%E6%9F%A5%E7%9C%8B%E7%BD%91%E7%BB%9C)
      * [查看过滤](#%E6%9F%A5%E7%9C%8B%E8%BF%87%E6%BB%A4)
      * [查看格式化](#%E6%9F%A5%E7%9C%8B%E6%A0%BC%E5%BC%8F%E5%8C%96)
      * [其他](#%E5%85%B6%E4%BB%96)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-1)
    * [延伸阅读](#%E5%BB%B6%E4%BC%B8%E9%98%85%E8%AF%BB)
      * [覆盖网络限制](#%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C%E9%99%90%E5%88%B6)
    * [示例](#%E7%A4%BA%E4%BE%8B-1)
      * [创建网络](#%E5%88%9B%E5%BB%BA%E7%BD%91%E7%BB%9C)
      * [连接容器](#%E8%BF%9E%E6%8E%A5%E5%AE%B9%E5%99%A8)
      * [高级选项](#%E9%AB%98%E7%BA%A7%E9%80%89%E9%A1%B9)
      * [桥模式选项](#%E6%A1%A5%E6%A8%A1%E5%BC%8F%E9%80%89%E9%A1%B9)
      * [网络内部模式](#%E7%BD%91%E7%BB%9C%E5%86%85%E9%83%A8%E6%A8%A1%E5%BC%8F)
      * [网络ingress模式](#%E7%BD%91%E7%BB%9Cingress%E6%A8%A1%E5%BC%8F)
  * [connect 连接](#connect-%E8%BF%9E%E6%8E%A5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-2)
    * [示例](#%E7%A4%BA%E4%BE%8B-2)
      * [已运行的容器连接网络](#%E5%B7%B2%E8%BF%90%E8%A1%8C%E7%9A%84%E5%AE%B9%E5%99%A8%E8%BF%9E%E6%8E%A5%E7%BD%91%E7%BB%9C)
      * [启动容器时连接到网络](#%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8%E6%97%B6%E8%BF%9E%E6%8E%A5%E5%88%B0%E7%BD%91%E7%BB%9C)
      * [连接网络使用固定IP](#%E8%BF%9E%E6%8E%A5%E7%BD%91%E7%BB%9C%E4%BD%BF%E7%94%A8%E5%9B%BA%E5%AE%9Aip)
      * [使用旧版\-\-link选项](#%E4%BD%BF%E7%94%A8%E6%97%A7%E7%89%88--link%E9%80%89%E9%A1%B9)
      * [连接网络时创建网络别名](#%E8%BF%9E%E6%8E%A5%E7%BD%91%E7%BB%9C%E6%97%B6%E5%88%9B%E5%BB%BA%E7%BD%91%E7%BB%9C%E5%88%AB%E5%90%8D)
      * [区间网络](#%E5%8C%BA%E9%97%B4%E7%BD%91%E7%BB%9C)
  * [disconnect 断开](#disconnect-%E6%96%AD%E5%BC%80)
  * [inspect 检查](#inspect-%E6%A3%80%E6%9F%A5)
  * [prune 删除未用](#prune-%E5%88%A0%E9%99%A4%E6%9C%AA%E7%94%A8)
    * [删除过滤](#%E5%88%A0%E9%99%A4%E8%BF%87%E6%BB%A4)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4)
* [bridge 网络应用](#bridge-%E7%BD%91%E7%BB%9C%E5%BA%94%E7%94%A8)
  * [自定义网桥和默认网桥之间的差异](#%E8%87%AA%E5%AE%9A%E4%B9%89%E7%BD%91%E6%A1%A5%E5%92%8C%E9%BB%98%E8%AE%A4%E7%BD%91%E6%A1%A5%E4%B9%8B%E9%97%B4%E7%9A%84%E5%B7%AE%E5%BC%82)
  * [管理自定义网络](#%E7%AE%A1%E7%90%86%E8%87%AA%E5%AE%9A%E4%B9%89%E7%BD%91%E7%BB%9C)
  * [连接到网络](#%E8%BF%9E%E6%8E%A5%E5%88%B0%E7%BD%91%E7%BB%9C)
  * [断开连接网络](#%E6%96%AD%E5%BC%80%E8%BF%9E%E6%8E%A5%E7%BD%91%E7%BB%9C)
  * [使用IPv6](#%E4%BD%BF%E7%94%A8ipv6)
  * [启用从容器转发到外部网络](#%E5%90%AF%E7%94%A8%E4%BB%8E%E5%AE%B9%E5%99%A8%E8%BD%AC%E5%8F%91%E5%88%B0%E5%A4%96%E9%83%A8%E7%BD%91%E7%BB%9C)
  * [使用默认桥接网络](#%E4%BD%BF%E7%94%A8%E9%BB%98%E8%AE%A4%E6%A1%A5%E6%8E%A5%E7%BD%91%E7%BB%9C)
    * [将容器连接到默认网桥](#%E5%B0%86%E5%AE%B9%E5%99%A8%E8%BF%9E%E6%8E%A5%E5%88%B0%E9%BB%98%E8%AE%A4%E7%BD%91%E6%A1%A5)
    * [配置默认网桥](#%E9%85%8D%E7%BD%AE%E9%BB%98%E8%AE%A4%E7%BD%91%E6%A1%A5)
    * [将IPv6与默认网桥一起使用](#%E5%B0%86ipv6%E4%B8%8E%E9%BB%98%E8%AE%A4%E7%BD%91%E6%A1%A5%E4%B8%80%E8%B5%B7%E4%BD%BF%E7%94%A8)
  * [实例演示](#%E5%AE%9E%E4%BE%8B%E6%BC%94%E7%A4%BA)
    * [使用默认网络操作流程](#%E4%BD%BF%E7%94%A8%E9%BB%98%E8%AE%A4%E7%BD%91%E7%BB%9C%E6%93%8D%E4%BD%9C%E6%B5%81%E7%A8%8B)
      * [查看已有网络](#%E6%9F%A5%E7%9C%8B%E5%B7%B2%E6%9C%89%E7%BD%91%E7%BB%9C)
      * [启动容器连接到默认网络](#%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8%E8%BF%9E%E6%8E%A5%E5%88%B0%E9%BB%98%E8%AE%A4%E7%BD%91%E7%BB%9C)
      * [检查 bridge 网络](#%E6%A3%80%E6%9F%A5-bridge-%E7%BD%91%E7%BB%9C)
      * [交互查看容器IP](#%E4%BA%A4%E4%BA%92%E6%9F%A5%E7%9C%8B%E5%AE%B9%E5%99%A8ip)
      * [ping 测试网络](#ping-%E6%B5%8B%E8%AF%95%E7%BD%91%E7%BB%9C)
      * [离开交互窗口](#%E7%A6%BB%E5%BC%80%E4%BA%A4%E4%BA%92%E7%AA%97%E5%8F%A3)
      * [停止和删除容器](#%E5%81%9C%E6%AD%A2%E5%92%8C%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8)
    * [使用自定义网络操作流程](#%E4%BD%BF%E7%94%A8%E8%87%AA%E5%AE%9A%E4%B9%89%E7%BD%91%E7%BB%9C%E6%93%8D%E4%BD%9C%E6%B5%81%E7%A8%8B)
      * [创建自定义网络](#%E5%88%9B%E5%BB%BA%E8%87%AA%E5%AE%9A%E4%B9%89%E7%BD%91%E7%BB%9C)
      * [检查自定义网络](#%E6%A3%80%E6%9F%A5%E8%87%AA%E5%AE%9A%E4%B9%89%E7%BD%91%E7%BB%9C)
      * [启动容器连接到网络](#%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8%E8%BF%9E%E6%8E%A5%E5%88%B0%E7%BD%91%E7%BB%9C)
      * [ping 测试网络](#ping-%E6%B5%8B%E8%AF%95%E7%BD%91%E7%BB%9C-1)
      * [停止和删除容器](#%E5%81%9C%E6%AD%A2%E5%92%8C%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8-1)
* [host 网络应用](#host-%E7%BD%91%E7%BB%9C%E5%BA%94%E7%94%A8)
  * [使用主机网络进行联网](#%E4%BD%BF%E7%94%A8%E4%B8%BB%E6%9C%BA%E7%BD%91%E7%BB%9C%E8%BF%9B%E8%A1%8C%E8%81%94%E7%BD%91)
    * [创建和启动容器](#%E5%88%9B%E5%BB%BA%E5%92%8C%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8)
    * [访问程序](#%E8%AE%BF%E9%97%AE%E7%A8%8B%E5%BA%8F)
    * [检查网络](#%E6%A3%80%E6%9F%A5%E7%BD%91%E7%BB%9C)
    * [停止和删除容器](#%E5%81%9C%E6%AD%A2%E5%92%8C%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8-2)
* [overlay 网络应用](#overlay-%E7%BD%91%E7%BB%9C%E5%BA%94%E7%94%A8)
  * [默认和自定义overlay网络操作流程](#%E9%BB%98%E8%AE%A4%E5%92%8C%E8%87%AA%E5%AE%9A%E4%B9%89overlay%E7%BD%91%E7%BB%9C%E6%93%8D%E4%BD%9C%E6%B5%81%E7%A8%8B)
    * [创建overlay网络](#%E5%88%9B%E5%BB%BAoverlay%E7%BD%91%E7%BB%9C)
    * [加密overlay网络上的数据传输](#%E5%8A%A0%E5%AF%86overlay%E7%BD%91%E7%BB%9C%E4%B8%8A%E7%9A%84%E6%95%B0%E6%8D%AE%E4%BC%A0%E8%BE%93)
    * [自定义默认ingress网络](#%E8%87%AA%E5%AE%9A%E4%B9%89%E9%BB%98%E8%AE%A4ingress%E7%BD%91%E7%BB%9C)
      * [检查网络](#%E6%A3%80%E6%9F%A5%E7%BD%91%E7%BB%9C-1)
      * [删除网络](#%E5%88%A0%E9%99%A4%E7%BD%91%E7%BB%9C)
      * [创建网络](#%E5%88%9B%E5%BB%BA%E7%BD%91%E7%BB%9C-1)
      * [重启服务](#%E9%87%8D%E5%90%AF%E6%9C%8D%E5%8A%A1)
    * [自定义docker\_gwbridge界面](#%E8%87%AA%E5%AE%9A%E4%B9%89docker_gwbridge%E7%95%8C%E9%9D%A2)
  * [集群overlay网络的操作](#%E9%9B%86%E7%BE%A4overlay%E7%BD%91%E7%BB%9C%E7%9A%84%E6%93%8D%E4%BD%9C)
    * [在overlay网络上发布端口](#%E5%9C%A8overlay%E7%BD%91%E7%BB%9C%E4%B8%8A%E5%8F%91%E5%B8%83%E7%AB%AF%E5%8F%A3)
    * [绕过swarm服务的路由网格](#%E7%BB%95%E8%BF%87swarm%E6%9C%8D%E5%8A%A1%E7%9A%84%E8%B7%AF%E7%94%B1%E7%BD%91%E6%A0%BC)
    * [单独的控制和数据传输](#%E5%8D%95%E7%8B%AC%E7%9A%84%E6%8E%A7%E5%88%B6%E5%92%8C%E6%95%B0%E6%8D%AE%E4%BC%A0%E8%BE%93)
  * [overlay网络上的独立容器](#overlay%E7%BD%91%E7%BB%9C%E4%B8%8A%E7%9A%84%E7%8B%AC%E7%AB%8B%E5%AE%B9%E5%99%A8)
    * [将独立容器附加到overlay网络](#%E5%B0%86%E7%8B%AC%E7%AB%8B%E5%AE%B9%E5%99%A8%E9%99%84%E5%8A%A0%E5%88%B0overlay%E7%BD%91%E7%BB%9C)
    * [发布端口](#%E5%8F%91%E5%B8%83%E7%AB%AF%E5%8F%A3)
    * [容器发现](#%E5%AE%B9%E5%99%A8%E5%8F%91%E7%8E%B0)
  * [实例演示](#%E5%AE%9E%E4%BE%8B%E6%BC%94%E7%A4%BA-1)
    * [使用默认覆盖网络](#%E4%BD%BF%E7%94%A8%E9%BB%98%E8%AE%A4%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C)
      * [创建和加入集群](#%E5%88%9B%E5%BB%BA%E5%92%8C%E5%8A%A0%E5%85%A5%E9%9B%86%E7%BE%A4)
      * [创建网络和服务](#%E5%88%9B%E5%BB%BA%E7%BD%91%E7%BB%9C%E5%92%8C%E6%9C%8D%E5%8A%A1)
    * [使用自定义的覆盖网络](#%E4%BD%BF%E7%94%A8%E8%87%AA%E5%AE%9A%E4%B9%89%E7%9A%84%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C)
    * [在独立容器使用覆盖网络](#%E5%9C%A8%E7%8B%AC%E7%AB%8B%E5%AE%B9%E5%99%A8%E4%BD%BF%E7%94%A8%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C)
      * [创建集群](#%E5%88%9B%E5%BB%BA%E9%9B%86%E7%BE%A4)
      * [创建网络](#%E5%88%9B%E5%BB%BA%E7%BD%91%E7%BB%9C-2)
      * [启动容器](#%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8)
      * [查看网络](#%E6%9F%A5%E7%9C%8B%E7%BD%91%E7%BB%9C-1)
      * [启动容器](#%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8-1)
      * [查看网络](#%E6%9F%A5%E7%9C%8B%E7%BD%91%E7%BB%9C-2)
      * [测试网络](#%E6%B5%8B%E8%AF%95%E7%BD%91%E7%BB%9C)
      * [退出交互](#%E9%80%80%E5%87%BA%E4%BA%A4%E4%BA%92)
      * [删除容器和网络](#%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8%E5%92%8C%E7%BD%91%E7%BB%9C)
    * [在容器和集群服务之间进行通信](#%E5%9C%A8%E5%AE%B9%E5%99%A8%E5%92%8C%E9%9B%86%E7%BE%A4%E6%9C%8D%E5%8A%A1%E4%B9%8B%E9%97%B4%E8%BF%9B%E8%A1%8C%E9%80%9A%E4%BF%A1)
      * [查看网络](#%E6%9F%A5%E7%9C%8B%E7%BD%91%E7%BB%9C-3)
      * [启动容器](#%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8-2)
      * [检查网络](#%E6%A3%80%E6%9F%A5%E7%BD%91%E7%BB%9C-2)
      * [建立交互](#%E5%BB%BA%E7%AB%8B%E4%BA%A4%E4%BA%92)
      * [ping 测试](#ping-%E6%B5%8B%E8%AF%95)
      * [退出交互](#%E9%80%80%E5%87%BA%E4%BA%A4%E4%BA%92-1)
      * [删除容器](#%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8)
* [macvlan 网络应用](#macvlan-%E7%BD%91%E7%BB%9C%E5%BA%94%E7%94%A8)
  * [创建一个macvlan网络](#%E5%88%9B%E5%BB%BA%E4%B8%80%E4%B8%AAmacvlan%E7%BD%91%E7%BB%9C)
    * [桥接模式](#%E6%A1%A5%E6%8E%A5%E6%A8%A1%E5%BC%8F)
    * [802\.1q中继桥模式](#8021q%E4%B8%AD%E7%BB%A7%E6%A1%A5%E6%A8%A1%E5%BC%8F)
    * [使用ipvlan而不是macvlan](#%E4%BD%BF%E7%94%A8ipvlan%E8%80%8C%E4%B8%8D%E6%98%AFmacvlan)
  * [使用IPv6](#%E4%BD%BF%E7%94%A8ipv6-1)
  * [实例演示](#%E5%AE%9E%E4%BE%8B%E6%BC%94%E7%A4%BA-2)
    * [Bridge 桥接网络](#bridge-%E6%A1%A5%E6%8E%A5%E7%BD%91%E7%BB%9C)
    * [802\.1q中继桥接网络](#8021q%E4%B8%AD%E7%BB%A7%E6%A1%A5%E6%8E%A5%E7%BD%91%E7%BB%9C)
* [为容器禁用网络](#%E4%B8%BA%E5%AE%B9%E5%99%A8%E7%A6%81%E7%94%A8%E7%BD%91%E7%BB%9C)
* [可选配置](#%E5%8F%AF%E9%80%89%E9%85%8D%E7%BD%AE)
  * [启用IPv6](#%E5%90%AF%E7%94%A8ipv6)
  * [iptables](#iptables)
    * [在Docker的规则之前添加iptables策略](#%E5%9C%A8docker%E7%9A%84%E8%A7%84%E5%88%99%E4%B9%8B%E5%89%8D%E6%B7%BB%E5%8A%A0iptables%E7%AD%96%E7%95%A5)
      * [限制连接到Docker守护进程](#%E9%99%90%E5%88%B6%E8%BF%9E%E6%8E%A5%E5%88%B0docker%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
    * [防止Docker操纵iptables](#%E9%98%B2%E6%AD%A2docker%E6%93%8D%E7%BA%B5iptables)
  * [容器网络](#%E5%AE%B9%E5%99%A8%E7%BD%91%E7%BB%9C)
    * [发布的端口](#%E5%8F%91%E5%B8%83%E7%9A%84%E7%AB%AF%E5%8F%A3)
    * [IP地址和主机名](#ip%E5%9C%B0%E5%9D%80%E5%92%8C%E4%B8%BB%E6%9C%BA%E5%90%8D)
    * [DNS服务](#dns%E6%9C%8D%E5%8A%A1)
    * [代理](#%E4%BB%A3%E7%90%86)
  * [使用代理服务](#%E4%BD%BF%E7%94%A8%E4%BB%A3%E7%90%86%E6%9C%8D%E5%8A%A1)
    * [使用 Docker 客户端方式](#%E4%BD%BF%E7%94%A8-docker-%E5%AE%A2%E6%88%B7%E7%AB%AF%E6%96%B9%E5%BC%8F)
    * [使用 Docker 环境变量方式](#%E4%BD%BF%E7%94%A8-docker-%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F%E6%96%B9%E5%BC%8F)
* [传统网络](#%E4%BC%A0%E7%BB%9F%E7%BD%91%E7%BB%9C)
  * [传统容器连接](#%E4%BC%A0%E7%BB%9F%E5%AE%B9%E5%99%A8%E8%BF%9E%E6%8E%A5)
    * [使用网络端口映射容器连接](#%E4%BD%BF%E7%94%A8%E7%BD%91%E7%BB%9C%E7%AB%AF%E5%8F%A3%E6%98%A0%E5%B0%84%E5%AE%B9%E5%99%A8%E8%BF%9E%E6%8E%A5)
      * [自动端口映射](#%E8%87%AA%E5%8A%A8%E7%AB%AF%E5%8F%A3%E6%98%A0%E5%B0%84)
      * [固定端口映射](#%E5%9B%BA%E5%AE%9A%E7%AB%AF%E5%8F%A3%E6%98%A0%E5%B0%84)
      * [随机范围映射](#%E9%9A%8F%E6%9C%BA%E8%8C%83%E5%9B%B4%E6%98%A0%E5%B0%84)
      * [固定IP端口映射](#%E5%9B%BA%E5%AE%9Aip%E7%AB%AF%E5%8F%A3%E6%98%A0%E5%B0%84)
      * [动态端口映射](#%E5%8A%A8%E6%80%81%E7%AB%AF%E5%8F%A3%E6%98%A0%E5%B0%84)
      * [端口协议映射](#%E7%AB%AF%E5%8F%A3%E5%8D%8F%E8%AE%AE%E6%98%A0%E5%B0%84)
      * [查看映射端口](#%E6%9F%A5%E7%9C%8B%E6%98%A0%E5%B0%84%E7%AB%AF%E5%8F%A3)
    * [使用链接系统连接容器](#%E4%BD%BF%E7%94%A8%E9%93%BE%E6%8E%A5%E7%B3%BB%E7%BB%9F%E8%BF%9E%E6%8E%A5%E5%AE%B9%E5%99%A8)
    * [使用链接系统进行容器通信](#%E4%BD%BF%E7%94%A8%E9%93%BE%E6%8E%A5%E7%B3%BB%E7%BB%9F%E8%BF%9B%E8%A1%8C%E5%AE%B9%E5%99%A8%E9%80%9A%E4%BF%A1)
      * [环境变量](#%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
      * [有关Docker环境变量的重要说明](#%E6%9C%89%E5%85%B3docker%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F%E7%9A%84%E9%87%8D%E8%A6%81%E8%AF%B4%E6%98%8E)
      * [更新/etc/hosts文件](#%E6%9B%B4%E6%96%B0etchosts%E6%96%87%E4%BB%B6)
  * [多主机网络和独立集群](#%E5%A4%9A%E4%B8%BB%E6%9C%BA%E7%BD%91%E7%BB%9C%E5%92%8C%E7%8B%AC%E7%AB%8B%E9%9B%86%E7%BE%A4)
    * [独立集群](#%E7%8B%AC%E7%AB%8B%E9%9B%86%E7%BE%A4)
    * [使用外部键值存储覆盖网络](#%E4%BD%BF%E7%94%A8%E5%A4%96%E9%83%A8%E9%94%AE%E5%80%BC%E5%AD%98%E5%82%A8%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C)
      * [设置一个键值存储](#%E8%AE%BE%E7%BD%AE%E4%B8%80%E4%B8%AA%E9%94%AE%E5%80%BC%E5%AD%98%E5%82%A8)
      * [创建一个群集](#%E5%88%9B%E5%BB%BA%E4%B8%80%E4%B8%AA%E7%BE%A4%E9%9B%86)
      * [创建覆盖网络](#%E5%88%9B%E5%BB%BA%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C)
      * [在网络上运行应用程序](#%E5%9C%A8%E7%BD%91%E7%BB%9C%E4%B8%8A%E8%BF%90%E8%A1%8C%E5%BA%94%E7%94%A8%E7%A8%8B%E5%BA%8F)
      * [检查外部连接](#%E6%A3%80%E6%9F%A5%E5%A4%96%E9%83%A8%E8%BF%9E%E6%8E%A5)

# 概述

Docker容器和服务如此强大的原因之一是可以将它们连接在一起，或将它们连接到非Docker工作环境进行负载。Docker容器和服务甚至不需要知道它们是否部署在Docker上，或者它们的对等端是否也是Docker工作负载。无论Docker主机是运行Linux、Windows还是两者的组合，都可以使用Docker以平台无关的方式管理它们。


## 网络驱动

Docker的网络子系统是可插拔的，使用驱动程序。默认情况下存在几个驱动程序，并提供核心网络功能：

- `bridge`：默认的网络驱动程序。如果你不指定驱动程序，则这是你正在创建的网络类型。**当你的应用程序运行在需要通信的独立容器中时，通常会使用桥接网络。**请参阅 [桥接网络](https://docs.docker.com/network/bridge/)。
- `host`：对于独立容器，删除容器和Docker主机之间的网络隔离，并直接使用主机的网络。`host` 仅适用于Docker 17.06及更高版本的群集服务。请参阅 [使用主机网络](https://docs.docker.com/network/host/)。
- `overlay`：覆盖网络**将多个Docker守护进程连接在一起，并使群集服务能够相互通信**。你还可以使用覆盖网络来促进**swarm服务和独立容器之间的通信**，或者不同Docker守护进程上的两个独立容器之间的通信。这种策略消除了**在这些容器之间进行操作系统级路由**的需求。请参阅[覆盖网络](https://docs.docker.com/network/overlay/)。
- `macvlan`：Macvlan网络允许你为容器**分配MAC地址，使其显示为网络上的物理设备**。Docker守护进程通过**MAC地址将流量路由到容器**。使用`macvlan` 驱动程序有时是处理希望直接连接到物理网络的传统应用程序的最佳选择，而不是通过Docker主机的网络堆栈进行路由。请参阅 [Macvlan网络](https://docs.docker.com/network/macvlan/)。
- `none`：对于此容器，**禁用所有网络**。通常与自定义网络驱动程序一起使用。`none`不适用于群组服务。请参阅 [禁用容器联网](https://docs.docker.com/network/none/)。
- [Network plugins 网络插件](https://docs.docker.com/engine/extend/plugins_services/)：你可以在Docker上安装和使用第三方网络插件。这些插件可从 [Docker Store](https://store.docker.com/search?category=network&q=&type=plugin) 或第三方供应商处获得。

### 总结

- **用户定义的网桥**：需要多个容器在同一个Docker主机上进行通信。
- **主机网络**： 当网络堆栈不应该与Docker主机隔离时，但你希望隔离容器的其他方面。
- **覆盖网络**： 当需要运行在不同Docker主机上的容器进行通信，或者当多个应用程序使用群集服务一起工作。
- **Macvlan网络**： 最适合从虚拟机设置迁移或需要容器看起来像网络上的物理主机，每个物理主机都有一个唯一的MAC地址。
- **第三方网络插件**： 允许将Docker与专用网络堆栈集成。

## Docker EE 网络

以下两个功能只有在使用Docker EE和使用通用控制平面（UCP）管理Docker服务时才有可能：

- 该[HTTP路由网格](https://docs.docker.com/datacenter/ucp/2.2/guides/admin/configure/use-domain-names-to-access-services/) 可以让你分享多个服务之间的相同的网络IP地址和端口。根据客户端的要求，UCP使用主机名和端口的组合将流量路由到相应的服务。
- [会话粘性](https://docs.docker.com/datacenter/ucp/2.2/guides/user/services/use-domain-names-to-access-services/#sticky-sessions)允许你指定UCP用于将后续请求路由到相同服务任务的HTTP标头中的信息，用于需要有状态会话的应用程序。

# docker network 基本命令

```shell
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
```

## ls 查看


### 命令参数选项

---

```shell
Options:
  -f, --filter filter   #提供过滤器值 (e.g. 'driver=bridge')
      --format string   #使用Go模板的漂亮打印网络
      --no-trunc        #不要截断输出
  -q, --quiet           #只显示网络ID
```
### 示例

---

#### 查看网络

`docker network ls`查看网络列表，列举出已经存在的网络数据

```shell
$ docker network ls
NETWORK ID          NAME                                             DRIVER              SCOPE
0daf44c54e3b        bridge                                           bridge              local
99b53a220971        host                                             host                local
lzq7bs60xe53        ingress                                          overlay             swarm
56d47aac58e8        my-bri-0                                         bridge              local
b9997816c388        my-bridge-net                                    bridge              local
a1fcabf9c7b3        my-mac-net                                       macvlan             local
qqabvnny71wz        my-overlay-inte-net                              overlay             swarm
6ei164q3kk09        my-overlay-net                                   overlay             swarm
91efc6379be0        none                                             null                local
```

#### 查看过滤

使用`filter`过滤查看

```shell
$ docker network ls --filter 'driver=host'
NETWORK ID          NAME                DRIVER              SCOPE
99b53a220971        host                host                local
```

过滤选项（`-f`或`--filter`）格式是一`key=value`对。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）。多个过滤器选项被组合为一个`OR`过滤器。例如，`-f type=custom -f type=builtin`返回两者`custom`和`builtin`网络。

目前支持的过滤器是：

- driver
- id (network’s id)
- label (`label=<key>` or `label=<key>=<value>`)
- name (`network’s name`)
- scope (`swarm|global|local`)
- type (`custom|builtin`) `type`过滤器支持两个值; `builtin`显示预定义的网络（`bridge`，`none`，`host`），而`custom`显示用户定义的网络。

```shell
$ docker network ls --filter 'driver=host'
$ docker network ls --filter scope=swarm
# 查看自定义网络
$ docker network ls -f type=custom
$ docker network ls -f type=builtin
NETWORK ID          NAME                DRIVER              SCOPE
0daf44c54e3b        bridge              bridge              local
99b53a220971        host                host                local
91efc6379be0        none                null                local
```

#### 查看格式化

格式化输出列表

```shell
$ docker network ls --format "{{.Name}} \t {{.Driver}} \t {{.IPv6}} \t {{.Internal}} \t {{.Labels}}"
bridge   bridge          false   false
com.docker.network.bridge.name=my-bridge-opt-1   bridge          false   false
compose_sample_default   bridge          false   false   com.docker.compose.network=default,com.docker.compose.project=compose_sample
composeexample_default   bridge          false   false   com.docker.compose.network=default,com.docker.compose.project=composeexample
deploy_test_overlay      overlay         false   false   com.docker.stack.namespace=deploy_test
docker_gwbridge          bridge          false   false
host     host    false   false
```

模板占位符

| 占位符       | 描述                                                     |
| ------------ | -------------------------------------------------------- |
| `.ID`        | 网络ID                                                   |
| `.Name`      | 网络名字                                                 |
| `.Driver`    | 网络驱动                                                 |
| `.Scope`     | 网络范围（本地，全球）                                   |
| `.IPv6`      | 是否在网络上启用IPv6。                                   |
| `.Internal`  | 网络是否是内部的。                                       |
| `.Labels`    | 所有分配给网络的标签。                                   |
| `.Label`     | 此网络的特定标签的值。例如`{{.Label "project.version"}}` |
| `.CreatedAt` | 网络创建的时间                                           |

#### 其他

其他命令操作，显示完整`network id`：

```shell
$ docker network ls --filter 'driver=host' -q
99b53a220971

$ docker network ls --filter 'driver=host' -q --no-trunc
99b53a220971c01d6f4bf1cf9571d85f5cabd08f3e308cedaf96f4a0a18e0789
```

## create 创建

### 命令参数选项

---

```shell
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
```

### 延伸阅读

---

创建一个新的网络。`DRIVER`接受内置网络驱动程序的`bridge`或者`overlay`。如果已经安装了第三方或自己的自定义网络驱动程序，也可以指定`DRIVER`。如果不指定该 `--driver`选项，该命令将自动创建一个`bridge`网络。当安装`Docker Engine`时，它会自动创建一个`bridge`网络。该网络对应于`docker0`引擎传统依赖的桥梁。当`docker run`启动一个新的容器时， 它会自动连接到这个网桥。你无法删除此默认桥接网络，但可以使用`network create`命令创建新桥接网络。

```shell
$ docker network create -d bridge my-bridge-network
```

桥接网络是单个引擎安装中的隔离网络。如果你想创建一个跨多个运行引擎的多个Docker主机的网络，则必须创建一个`overlay`网络。与`bridge`网络不同，`overlay`覆盖网络在创建之前需要一些预先存在的条件。这些条件是：

- 访问键值存储。引擎支持`Consul`、`Etcd`和`ZooKeeper`（分布式存储）键值存储。
- 连接到键值存储的主机集群。
- 集群中每台主机上配置正确的引擎`daemon`。

`dockerd`支持`overlay`网络的选项是：

- `--cluster-store`
- `--cluster-store-opt`
- `--cluster-advertise`

要详细了解这些选项以及如何配置它们，请参阅[“ *多主机网络入门* ”](https://docs.docker.com/engine/userguide/networking/get-started-overlay)。

虽然不是必需的，但安装`Docker Swarm`来管理组成网络的集群是一个不错的主意。`Swarm`提供了复杂的发现和服务器管理工具，可以帮助你实施。

准备好`overlay`网络必须条件后，只需在集群中选择Docker主机并发出以下命令即可创建网络：

```shell
$ docker network create -d overlay my-multihost-network
```

网络名称**必须是唯一**的。Docker守护进程尝试识别命名冲突，但**不能保证**。避免名称冲突是用户的责任。

#### 覆盖网络限制

当你使用默认的基于VIP的端点模式创建网络时，你应该创建带有24个块（默认值）的覆盖网络，这会将你限制为256个IP地址。该建议解决了 [群集模式的限制](https://github.com/moby/moby/issues/30820)。如果你需要超过256个IP地址，请勿增加IP块大小。你可以通过`dnsrr`外部负载均衡器使用端点模式，也可以使用多个较小的覆盖网络。 有关不同端点模式的更多信息，请参阅 [配置服务发现](https://docs.docker.com/engine/swarm/networking/#configure-service-discovery)。

### 示例

---

#### 创建网络

下面利用命令简单的创建一些网络，其中`host`网络已经默认创建过了，就不能再重复创建。

网络类型固定常用的有：`bridge`、`host`、`overlay`、`macvlan`、自定义网络。

```shell
# 创建网络，默认桥接网络
$ docker network create my-default-bri-net

# 创建桥接网络
$ docker network create -d bridge my-bridge-net
b9997816c38807c37fb2f9f2cabcac1017ce21e05f925033fda0481e5ef35aca

$ docker network create -d host my-host-net
Error response from daemon: only one instance of "host" network is allowed

# 创建覆盖型网络
$ docker network create -d overlay my-overlay-net
6ei164q3kk099o4jcmj0lhtt8

# 创建mac网络
$ docker network create -d macvlan my-mac-net
a1fcabf9c7b362ea558b4669bbb71b5c0b65661be8140200f4d36f33e20c1680
```

#### 连接容器

当你启动容器时，请使用`--network`选项将其连接到网络。本例将`busybox`容器添加到`mynet`网络中：

```shell
$ docker network create -d bridge mynet
$ docker run -itd --network=mynet busybox
```

如果要将已经运行的容器添加到网络，请使用`docker network connect`命令。

你可以将多个容器连接到同一个网络。连接后，容器只能使用另一个容器的IP地址或名称进行通信。对于`overlay`支持多主机连接的网络或自定义插件，连接到相同多主机网络但从不同引擎启动的容器也可以通过这种方式进行通信。

你可以使用`docker network disconnect`命令从网络断开容器。

#### 高级选项

在创建网络时，Engine默认会为网络创建一个不重叠的子网。这个子网不是现有网络的细分。这目的纯粹是为了ip地址。可以覆盖此默认值并直接使用`--subnet`选项指定子网值。在 `bridge`网络上只能创建一个子网：

```shell
$ docker network create --driver=bridge --subnet=192.168.0.0/18 my-bri-0
56d47aac58e8b819cc3ad5637a5da1a3a252406594af354d03eed6ab966357f2
```

另外，还可以指定`--gateway` `--ip-range`和`--aux-address` 选项。

```shell
$ docker network create \
  --driver=bridge \
  --subnet=172.28.0.0/16 \
  --ip-range=172.28.5.0/24 \
  --gateway=172.28.5.254 \
  br0
```

如果你忽略该`--gateway`选项，引擎会从池内为你随机选择一个。对于`overlay`网络和支持它的网络驱动程序插件，你可以创建多个子网。本示例使用两个`/25` 子网掩码来演示，即在单个覆盖网络中没有超过256个IP。每个子网络有126个可用地址。

```shell
$ docker network create -d overlay \
  --subnet=192.168.1.0/25 \
  --subnet=192.170.2.0/25 \
  --gateway=192.168.1.100 \
  --gateway=192.170.2.100 \
  --aux-address="my-router=192.168.1.5" --aux-address="my-switch=192.168.1.6" \
  --aux-address="my-printer=192.170.1.5" --aux-address="my-nas=192.170.1.6" \
  my-multihost-network
```

确保你的子网不重叠。如果子网重叠，网络创建失败，引擎返回错误。

#### 桥模式选项

在创建自定义网络时，默认网络驱动程序（即`bridge`）具有可以传递的其他选项。以下是用于docker0桥的那些选项和等效的docker守护进程选项：

| 选项                                             | 等价        | 描述                        |
| ------------------------------------------------ | ----------- | --------------------------- |
| `com.docker.network.bridge.name`                 | -           | 创建Linux桥时要使用的桥名称 |
| `com.docker.network.bridge.enable_ip_masquerade` | `--ip-masq` | 启用IP伪装                  |
| `com.docker.network.bridge.enable_icc`           | `--icc`     | 启用或禁用容器间连接        |
| `com.docker.network.bridge.host_binding_ipv4`    | `--ip`      | 绑定容器端口时的默认IP      |
| `com.docker.network.driver.mtu`                  | `--mtu`     | 设置容器网络MTU             |

以下参数可以传递给`docker network create`任何网络驱动程序，同样也可以传递给它们的等价`docker daemon`。

| Argument     | 等价           | 描述                   |
| ------------ | -------------- | ---------------------- |
| `--gateway`  | -              | 主子网的IPv4或IPv6网关 |
| `--ip-range` | `--fixed-cidr` | 从一个范围分配IP       |
| `--internal` | -              | 限制对网络的外部访问   |
| `--ipv6`     | `--ipv6`       | 启用IPv6网络           |
| `--subnet`   | `--bip`        | 网络子网               |

例如，让我们使用`-o`或`--opt`选项在发布端口时指定IP地址绑定：

```shell
$ docker network create \
    -o "com.docker.network.bridge.host_binding_ipv4"="172.19.0.1" \
    simple-network
```

#### 网络内部模式

默认情况下，当你将容器连接到`overlay`网络时，Docker也会将桥接网络连接到它以提供外部连接。如果你想创建一个外部隔离的`overlay`网络，你可以指定该 `--internal`选项。

```shell
$ docker network create --internal -d overlay my-overlay-inte-net
```

#### 网络ingress模式

你可以创建将用于在群集中提供路由网格的网络。你通过在创建网络时指定`--ingress`来完成此操作。当时只能创建一个入口网络。只有在没有服务依赖它的情况下才能删除网络。除了`--attachable`选项之外，在创建入口网络时，创建覆盖网络时可用的任何选项也可用。

```shell
$ docker network create -d overlay \
  --subnet=10.11.0.0/16 \
  --ingress \
  --opt com.docker.network.driver.mtu=9216 \
  --opt encrypted=true \
  my-ingress-network
```

## connect 连接

### 命令参数选项

---

```shell
$ docker network connect [options] network container
Options:
      --alias strings           # 为容器添加网络范围的别名
      --ip string               # IPv4地址 (e.g., 172.30.100.104)
      --ip6 string              # IPv6地址 (e.g., 2001:db8::33)
      --link list               # 将链接添加到其他容器
      --link-local-ip strings   # 为容器添加链接本地地址
```

### 示例

---

将容器连接到网络。你可以按名称或ID连接容器。连接后，容器可以与同一网络中的其他容器进行通信。

#### 已运行的容器连接网络

```shell
# 运行一个镜像，没有会自动去下载
$ docker run -it busybox
$ docker network ls
$ docker container ls
# 使用id 
$ docker network connect 61b951b60b24 91efc6379be0
# 使用name
$ docker network connect my-bridge-net suspicious_kepler
```

#### 启动容器时连接到网络

可以使用`docker run --network=<network-name>`选项启动容器并立即将其连接到网络。

```shell
$ docker run -it --network=my-bridge-net helloworld-jdk-9:latest
$ docker run -itd --network=multi-host-network busybox
```

#### 连接网络使用固定IP

可以指定要分配给容器固定的IP地址。对于不同的网络，分配的IP网段跟网络有关，所以先查看网络的子网网段，再分配合法的IP。

```shell
$ docker network inspect my-bri-0
$ docker network inspect my-bri-0 --format={{.IPAM.Config}}
[{192.168.0.0/18   map[]}]

$ docker network connect --ip 192.168.5.122 my-bri-0 suspicious_kepler
```

#### 使用旧版`--link`选项

可以使用`--link`选项将另一个容器与首选别名链接起来

```shell
$ docker network connect --link silly_curie:my_container my-bridge suspicious_kepler
```

#### 连接网络时创建网络别名

`--alias` 选项可用于通过连接到的网络中的其他名称来解析容器。取别名方便查看链接的容器。

```shell
$ docker network connect --alias db --alias mysql multi-host-network container2
$ docker network connect --alias linux_os --alias ubuntu ps upbeat_ptolemy
```

通过调用命令`docker container inspect`查看配置中的NetWork的Aliases

```shell
$ docker container inspect upbeat_ptolemy
"Networks": {                
                "ps": {
                    "IPAMConfig": {},
                    "Links": null,
                    "Aliases": [
                        "linux_os",
                        "ubuntu",
                        "798c3d2e4643"
                    ],
                    "NetworkID": "eca59402fd5ab6e5c51aa0e94be275599f148199dfea681aae8c6c90c21f33be",
                    "EndpointID": "df84d4f02f7a1843ab3620cdae2c5826908ab7100f0918c49da47aee9b37e477",
                    "Gateway": "172.23.0.1",
                    "IPAddress": "172.23.0.3",
                    "IPPrefixLen": 16,
                    "IPv6Gateway": "",
                    "GlobalIPv6Address": "",
                    "GlobalIPv6PrefixLen": 0,
                    "MacAddress": "02:42:ac:17:00:03",
                    "DriverOpts": null
                }

```

#### 区间网络

你可以暂停、重新启动并停止连接到网络的容器。**容器运行时会连接到其配置的网络**。

如果设定过网络，则在**重新启动容器时重新应用**容器的IP地址。**如果IP地址不再可用，则容器无法启动**。确保IP地址可用的一种方法是`--ip-range`在创建网络时指定一个IP地址，并从该范围之外**选择静态IP**地址。这确保了当该容器不在网络上时，IP地址**不会被另一个容器占用**。

```shell
$ docker network create --subnet 172.20.0.0/16 --ip-range 172.20.240.0/20 multi-host-network
$ docker network connect --ip 172.20.128.2 multi-host-network container2
```

要验证容器已连接，请使用`docker network inspect`命令。从网络中删除容器用`docker network disconnect`。

在网络连接后，容器只能使用另一个容器的**IP地址或名称**进行通信。对于`overlay`支持多主机连接的网络或自定义插件，连接到相同多主机网络但从不同引擎启动的容器也可以通过这种方式进行通信。

你可以将容器连接到一个或多个网络。网络不需要是相同的类型。例如，你可以连接单个容器桥和覆盖网络。

## disconnect 断开

断开容器网络连接，容器必须运行才能将其与网络断开连接。<br/>选项 `-f`强制断开`docker network disconnect [OPTIONS] NETWORK CONTAINER`

```shell
$ docker network disconnect -f my-bridge-net friendly_jepsen
# 或者用id
$ docker network disconnect -f 568e61b512d0 c7fd77e7f301
```

## inspect 检查

显示一个或多个网络的详细信息，选项`-f` `format` 格式化输出，默认情况下，此命令将呈现JSON对象中的所有结果。

```shell
$ docker network inspect my-mac-net
[
    {
        "Name": "my-mac-net",
        "Id": "a1fcabf9c7b362ea558b4669bbb71b5c0b65661be8140200f4d36f33e20c1680",
        "Created": "2018-04-29T03:45:13.331146449Z",
        "Scope": "local",
        "Driver": "macvlan",
        "EnableIPv6": false,
        "IPAM": {
            "Driver": "default",
            "Options": {},
            "Config": [
                {
                    "Subnet": "172.22.0.0/16",
                    "Gateway": "172.22.0.1"
                }
            ]
        },
.......

$ docker network inspect my-mac-net -v -f={{.IPAM.Config}}
[{172.22.0.0/16  172.22.0.1 map[]}]
$ docker network inspect my-mac-net -v -f={{.Name}}
my-mac-net
```

## prune 删除未用

删除所有未使用的网络。未使用的网络是那些没有被任何容器引用的网络，选项支持 `--filter` 过滤，`--force , -f`强制删除。

```shell
$ docker network prune
WARNING! This will remove all networks not used by at least one container.
Are you sure you want to continue? [y/N] y
Deleted Networks:
my-overlay-net
```

### 删除过滤

过滤选项（`--filter`）格式为“key = value”。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- until （<timestamp>） - 只删除给定时间戳之前创建的网络
- label（`label=<key>`，`label=<key>=<value>`，`label!=<key>`，或`label!=<key>=<value>`） -仅删除与网络（或没有，如果`label!=...`被使用）指定的标签。

该`until`过滤器可以是Unix的时间戳，日期格式的时间戳，或持续时间字符串（例如，去`10m`，`1h30m`）计算相对于守护机器的时间。

该`label`过滤器接受两种格式：一个是`label=...`（`label=<key>`或`label=<key>=<value>`），它删除具有指定标签的网络。另一种格式是`label!=...`（`label!=<key>`或`label!=<key>=<value>`），它删除没有指定标签的网络。

以下内容将删除超过5分钟前创建的网络。请注意，系统网络（如`bridge`，`host`）`none`将永远不会被删除：

```shell
$ docker network prune --force --filter until=5m
```

## rm 删除

通过名称或标识符或ID删除一个或多个网络。要删除网络，必须首先断开与其连接的所有容器。

```shell
$ docker network rm my-network
$ docker network rm 3695c422697f my-network
```

# bridge 网络应用

就网络而言，桥接网络是一种链路层设备，用于转发网段之间的流量。网桥可以是在主机内核中运行的硬件设备或软件设备。

就Docker而言，桥接网络使用允许连接到同一桥网络的容器进行通信的软件桥，同时提供与未连接到该桥网络的容器的隔离。Docker桥接驱动程序自动在主机中安装规则，以便不同桥接网络上的容器不能直接相互通信。

桥接网络适用于在**同一个** Docker守护程序主机上运行的容器。对于在不同Docker守护进程主机上运行的容器之间的通信，你可以在操作系统级别管理路由，也可以使用[覆盖网络](https://docs.docker.com/network/overlay/)。

启动Docker时，会自动创建一个[默认桥接网络](https://docs.docker.com/network/bridge/#use-the-default-bridge-network)（也称为`bridge`），除非另行指定，否则新启动的容器将连接到该网络。你还可以创建用户定义的自定义网桥。**用户定义的网桥优于默认bridge 网络。**

## 自定义网桥和默认网桥之间的差异

- **用户定义的网桥提供更好的隔离和集装箱化应用程序之间的互操作性**。

  连接到同一个用户定义的网桥网络的容器会自动将**所有端口**相互暴露，并且**无法**连接到外部世界。这使得集装箱化的应用程序能够轻松地相互通信，而不会意外地打开对外部世界的访问。

  想象一下带有Web前端和数据库后端的应用程序。外部世界需要访问Web前端（可能在端口80上），但只有前端本身需要访问数据库主机和端口。使用用户定义的桥接器，只需要打开Web端口，并且数据库应用程序不需要打开任何端口，因为Web前端可以通过用户定义的桥接器访问它。

  如果你在默认桥接网络上运行相同的应用程序堆栈，则需要使用`-p`或`--publish` 每个选项打开Web端口和数据库端口。这意味着Docker主机需要通过其他方式阻止对数据库端口的访问。

- **用户定义的网桥提供容器之间的自动DNS解析**。

  默认网桥网络上的容器只能通过IP地址访问彼此，除非你使用该[`--link`选项](https://docs.docker.com/network/links/)，这被认为是遗留的。在用户定义的桥接网络上，容器可以通过名称或别名来解析对方。

  想象一下与前一点相同的应用程序，它具有Web前端和数据库后端。如果你打电话给你的容器`web`和`db`，Web容器可以在连接到数据库容器`db`，无论哪个码头工人托管应用程序堆栈上运行。

  如果你在默认桥接网络上运行相同的应用程序堆栈，则需要在容器之间手动创建链接（使用旧`--link` 选项）。这些链接需要在两个方向上创建，所以你可以看到，这需要两个以上需要通信的容器。或者，你可以操纵`/etc/hosts`容器中的文件，但这会产生难以调试的问题。

- **容器可以在运行中与用户定义的网络连接和分离**。

  在容器的生命周期中，你可以在运行中将其与用户定义的网络连接或断开连接。要从默认桥接网络中移除容器，你需要停止容器并使用不同的网络选项重新创建容器。

- **每个用户定义的网络都会创建一个可配置的网桥**。

  如果你的容器使用默认桥接网络，则可以对其进行配置，但所有容器都使用相同的设置，例如MTU和`iptables`规则。另外，配置默认桥接网络发生在Docker本身之外，并且需要重新启动Docker。

  用户定义的网桥是使用 `docker network create`创建和配置的。如果不同的应用程序组具有不同的网络要求，则可以在创建时分别配置每个用户定义的桥接器。

- **链接的容器在默认网桥共享环境变量上**。

  最初，在两个容器之间共享环境变量的唯一方式是使用[`--link`选项](https://docs.docker.com/network/links/)链接它们。这种类型的变量共享对于用户定义的网络是不可能的。但是，有共享环境变量的更好方式做法：

  - 多个容器可以使用Docker**卷来挂载**包含**共享信息的文件或目录**。
  - 多个容器可以一起使用`docker-compose`，组合文件可以定义**共享变量**。
  - 你可以使用**swarm服务**而不是独立容器，并利用共享[秘密](https://docs.docker.com/engine/swarm/secrets/)和 [配置](https://docs.docker.com/engine/swarm/configs/)。

连接到同一个用户定义的网桥网络的容器有效地将所有端口相互暴露。要使端口可以在不同容器网络上或非Docker主机上访问，必须使用`-p` `--publish`选项来**发布**该端口。

## 管理自定义网络

使用该`docker network create`命令创建用户定义的网桥。

```shell
$ docker network create my-net
```

你可以指定子网、IP地址范围、网关和其他选项。

使用该`docker network rm`命令删除用户定义的网桥。如果有容器连接到当前网络， 请先断开它们。

```shell
$ docker network disconnect my-net
$ docker network rm my-net
```

> **docker做了什么？**
>
> 当你创建或删除自定义的网桥或连接或断开自定义的网桥的容器时，Docker使用特定于操作系统的工具来管理底层网络基础设施（例如`iptables`，在Linux上添加或删除网桥设备或配置规则）。这些细节应该被视为实施细节。让Docker为你管理自定义网络。

## 连接到网络

当你创建一个新的容器时，你可以指定一个或多个`--network`选项。本例将一个`Nginx`容器连接到`my-net`网络。它还将容器中的端口80发布到Docker主机上的端口8080，以便外部客户端可以访问该端口。连接到`my-net` 网络的任何其他容器都可以访问`my-nginx`容器上的所有端口，反之亦然。

```shell
$ docker create --name my-nginx \
  --network my-net \
  --publish 8080:80 \
  nginx:latest
```

要将**正在运行的**容器连接到现有的自定义桥，请使用 `docker network connect`命令。以下命令将一个已经运行的`my-nginx`容器连接到一个已经存在的`my-net`网络上：

```shell
$ docker network connect my-net my-nginx
```

## 断开连接网络

要断开正在运行的容器与用户定义的桥的连接，请使用该`docker network disconnect`命令。以下命令将`my-nginx` 容器与`my-net`网络断开连接。

```shell
$ docker network disconnect my-net my-nginx
```

## 使用IPv6

如果你需要对Docker容器进行IPv6支持，则需要在创建任何IPv6网络或分配容器IPv6地址之前，在Docker守护程序上[启用该选项](https://docs.docker.com/config/daemon/ipv6/)并重新加载其配置。

在创建网络时，可以指定`--ipv6`启用IPv6 的选项。不能有选择地禁用默认`bridge`网络上的IPv6支持。

## 启用从容器转发到外部网络

默认情况下，来自连接到默认桥接网络的容器的数据**不会**转发到外部网络。要启用转发，你需要更改两个设置。这些不是Docker命令，它们影响Docker主机的内核。

1. 配置Linux内核以允许IP转发。

   ```shell
   $ sudo sysctl net.ipv4.conf.all.forwarding=1
   ```

2. 将策略的`iptables` `FORWARD`策略从更改`DROP`为 `ACCEPT`。

   ```shell
   $ sudo iptables -P FORWARD ACCEPT
   ```

这些设置在重新启动时不会持续存在，因此需要将它们添加到启动脚本中。

## 使用默认桥接网络

默认`bridge`网络被视为Docker的传统网络，不建议用于生产。配置它是一个手动操作，它有 [技术上的缺点](https://docs.docker.com/network/bridge/#differences-between-user-defined-bridges-and-the-default-bridge)。

### 将容器连接到默认网桥

如果没有使用`--network`指定网络，并且指定了网络驱动`--driver`程序，则默认情况下容器已连接到默认`bridge`网络。连接到默认`bridge`网络的容器可以进行通信，但只能通过**IP地址**进行通信，除非它们使用[旧`--link`选项](https://docs.docker.com/network/links/)进行链接。

### 配置默认网桥

要配置默认`bridge`网络，请在`daemon.json`中指定选项。这里有一个`daemon.json`指定了几个选项的例子。只指定需要自定义的设置。

```json
{
  "bip": "192.168.1.5/24",
  "fixed-cidr": "192.168.1.5/25",
  "fixed-cidr-v6": "2001:db8::/64",
  "mtu": 1500,
  "default-gateway": "10.20.1.1",
  "default-gateway-v6": "2001:db8:abcd::89",
  "dns": ["10.20.1.2","10.20.1.3"]
}
```

重新启动Docker以使更改生效。

### 将IPv6与默认网桥一起使用

如果将Docker配置为支持IPv6（请参阅[使用IPv6](https://docs.docker.com/network/bridge/#use-ipv6)），则默认桥接网络也会自动配置为IPv6。与用户定义的网桥不同，不能在默认网桥上选择性地禁用IPv6。

## 实例演示

介绍使用默认网络和自定义网络的操作流程。

### 使用默认网络操作流程

演示如何使用`bridge`自动为Docker设置默认网络。**这个网络不是生产系统的最佳选择**。在这个例子中，使用`alpine`在同一个Docker主机上启动两个不同的容器，并进行一些测试以了解它们如何相互通信。

#### 查看已有网络

---

打开一个终端窗口，列出当前的网络。如果从未在此Docker守护程序中添加网络或初始化集群，可能会看到不同的网络，但至少应该看到这些网络（网络ID将会不同）：

```
$ docker network ls

NETWORK ID          NAME                DRIVER              SCOPE
17e324f45964        bridge              bridge              local
6ed54d316334        host                host                local
7092879f2cc8        none                null                local
```

`bridge`列出了默认网络`host`以及`none`。后两者不是完全成熟的网络，而是用于启动直接连接到Docker守护进程主机的网络堆栈的容器，或者启动无网络设备的容器。**下面将两个容器连接到bridge网络。**

#### 启动容器连接到默认网络

---

启动两个`alpine`运行的容器`ash`，这是`alpine`的默认`shell`，而不是`bash`。该`-dit`选项意味着要**分离容器在后台进程运行、交互（有输入的能力），并有TTY（这样你就可以看到输入和输出）**。由于开始分离，因此不会立即连接到容器，只有容器的ID将被打印。由于没有指定任何 `--network`选项，因此容器将连接到默认`bridge`网络。

```shell
$ docker run -dit --name alpine1 alpine ash
$ docker run -dit --name alpine2 alpine ash
```

查看两个容器是否实际启动：

```shell
$ docker container ls
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
edcba3845c6d        alpine              "ash"               4 minutes ago       Up 4 minutes                            alpine2
393b2d700482        alpine              "ash"               4 minutes ago       Up 4 minutes                            alpine1   
```

#### 检查 `bridge` 网络

---

使用命令 `docker network inspect`检查`bridge`网络以查看连接到它的容器

```shell
$ docker network inspect bridge
[
    {
        "Name": "bridge",
        "Id": "0daf44c54e3b19be90991b600a9b296a058f07035eea892d063c256b398597a9",
        "Created": "2018-04-13T11:10:13.514907225Z",
        "Scope": "local",
        "Driver": "bridge",
        "EnableIPv6": false,
        "IPAM": {
            "Driver": "default",
            "Options": null,
            "Config": [
                {
                    "Subnet": "172.17.0.0/16",
                    "Gateway": "172.17.0.1"
                }
            ]
        },
..........
```

在上面`bridge`列出了有关网络的信息，包括Docker主机和`bridge` 网络之间网关的IP地址（`172.17.0.1`）。在`Containers`关键字下方，列出了每个连接的容器，以及有关其IP地址（`172.17.0.2`用于 `alpine1`和`172.17.0.4`用于`alpine2`）的信息。

#### 交互查看容器IP

---

容器在后台运行，使用该`docker attach` 命令连接到`alpine1`。

```shell
$ winpty docker attach alpine1
/ #
```

提示符更改为`#`指示你是`root`容器内的用户。使用该`ip addr show`命令显示网络接口`alpine1`的容器内容：

```shell
/ # ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN qlen 1
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
314893: eth0@if314894: <BROADCAST,MULTICAST,UP,LOWER_UP,M-DOWN> mtu 1500 qdisc noqueue state UP
    link/ether 02:42:ac:11:00:02 brd ff:ff:ff:ff:ff:ff
    inet 172.17.0.2/16 brd 172.17.255.255 scope global eth0
       valid_lft forever preferred_lft forever

```

第一个接口是回送设备，现在忽略它。请注意，第二个接口的IP地址与上一步中`alpine1`显示的地址相同`172.17.0.2`。

#### `ping` 测试网络

---

从`alpine1`内部，请确保你可以通过ping连接到互联网`github.com`。该`-c 2`选项将该命令限制为两次`ping` 尝试。

```shell
/ # ping -c 2 github.com
PING github.com (13.250.177.223): 56 data bytes

--- github.com ping statistics ---
2 packets transmitted, 0 packets received, 100% packet loss
```

现在尝试ping第二个容器。首先，通过IP地址ping它 `172.17.0.4`：

```shell
/ # ping -c 2 172.17.0.4
PING 172.17.0.4 (172.17.0.4): 56 data bytes
64 bytes from 172.17.0.4: seq=0 ttl=64 time=0.273 ms
64 bytes from 172.17.0.4: seq=1 ttl=64 time=0.167 ms

--- 172.17.0.4 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.167/0.220/0.273 ms
```

这成功了。接下来，尝试通过容器名称ping `alpine2`容器，这将失败。

```shell
# ping -c 2 alpine2
ping: bad address 'alpine2'
```

#### 离开交互窗口

---

通过使用快捷键` CTRL + p + q`（按住`CTRL`并键入`p`，然后键入`q`），从`alpine1`上离开而不停止它。

#### 停止和删除容器

---

停止并移除两个容器

```shell
$ docker container stop alpine1 alpine2
$ docker container rm alpine1 alpine2
```

请记住`bridge`建议不要将默认网络用于生产。

### 使用自定义网络操作流程

上面我们已经启动两个`alpine`容器，但将它们附加到我们已经创建的自定义网络`alpine-net`。这些容器根本没有连接到默认`bridge`网络。然后，我们启动第三个`alpine`连接到`bridge`网络但未连接到`alpine-net`的`alpine`容器，以及连接到两个网络的第四个`alpine`容器。

#### 创建自定义网络

---

创建`alpine-net`网络，不需要`--driver bridge`选项，因为它是默认选项，但此示例演示如何使用它：

```shell
$ docker network create --driver bridge alpine-net
```

#### 检查自定义网络

---

查看Docker的网络：

```shell
$ docker network ls

NETWORK ID          NAME                DRIVER              SCOPE
e9261a8c9a19        alpine-net          bridge              local
17e324f45964        bridge              bridge              local
6ed54d316334        host                host                local
7092879f2cc8        none                null                local
```

检查`alpine-net`网络。这会向你显示其IP地址以及未连接容器的事实：

```shell
$ docker network inspect alpine-net
[
    {
        "Name": "alpine-net",
        "Id": "41ace58315aeb691d17fc03a413982f8cef3dc42dea6b84394386251f883026e",
        "Created": "2018-04-30T08:59:41.893261299Z",
        "Scope": "local",
        "Driver": "bridge",
        "EnableIPv6": false,
        "IPAM": {
            "Driver": "default",
            "Options": {},
            "Config": [
                {
                    "Subnet": "172.20.0.0/16",
                    "Gateway": "172.20.0.1"
                }
            ]
        },
......
```

请注意，此网络的网关`172.17.0.1`与网关的默认网桥`172.17.0.1`相反。每个人的系统上的显示的IP地址可能不同。

#### 启动容器连接到网络

---

创建你的四个容器，注意`--network`选项。只能在`docker run`命令期间连接到一个网络，因此需要`docker network attach`以后再使用 `alpine4`以连接到`bridge` 网络。

```shell
$ docker run -dit --name alpine1 --network alpine-net alpine ash

$ docker run -dit --name alpine2 --network alpine-net alpine ash

$ docker run -dit --name alpine3 alpine ash

$ docker run -dit --name alpine4 --network alpine-net alpine ash

$ docker network connect bridge alpine4
```

验证所有容器正在运行：

```shell
$ docker container ls
```

再次检查`bridge`网络和`alpine-net`网络：

```shell
$ docker network inspect bridge
[
    {
        "Name": "bridge",
        "Id": "0daf44c54e3b19be90991b600a9b296a058f07035eea892d063c256b398597a9",
        "Created": "2018-04-13T11:10:13.514907225Z",
        "Scope": "local",
        "Driver": "bridge",
        "EnableIPv6": false,        
        .......
        "Containers": {
            "42c87d610c7a67bcd58169eee409b7926dafe7ce2c3d1cb1528fcbabd66bd9ca": {
                "Name": "alpine3",
                "EndpointID": "b2885f67057be4ae35295ba717469d3f61fdbf08c36fc63d7bb389de1abf8d4c",
                "MacAddress": "02:42:ac:11:00:02",
                "IPv4Address": "172.17.0.2/16",
                "IPv6Address": ""
            },
            "5823c64c03de771a49cd54d32db9bf21ca5cc0717ae8d2606ea4bd671e02581d": {
                "Name": "alpine4",
                "EndpointID": "bb5a4f51a2e998ab846faa4fb2d9bc94c7c72d741a6969f689b7f79d64f3026a",
                "MacAddress": "02:42:ac:11:00:04",
                "IPv4Address": "172.17.0.4/16",
                "IPv6Address": ""
            }
        },
.......
```

可以看到容器`alpine3`和`alpine4`连接到`bridge`网络。

```shell
$ docker network inspect alpine-net
[
    {
        "Name": "alpine-net",
        "Id": "41ace58315aeb691d17fc03a413982f8cef3dc42dea6b84394386251f883026e",
        "Created": "2018-04-30T08:59:41.893261299Z",
        "Scope": "local",
        "Driver": "bridge",
        .........
        "ConfigOnly": false,
        "Containers": {
            "10d71da42fb8b8bd2bff35dbc8d07642d7d928876ae162351f1431e72dd87809": {
                "Name": "alpine2",
                "EndpointID": "1a416739aeb09d37bdb108f11157e329e489827c1c2c7ad3f20a38ce7ae9cda5",
                "MacAddress": "02:42:ac:14:00:03",
                "IPv4Address": "172.20.0.3/16",
                "IPv6Address": ""
            },
            "2f7834e6f3463ae129e46ed9fc9e3bc0a74378e50dbaef6fcddec27e211fce9b": {
                "Name": "alpine1",
                "EndpointID": "307c9406a7cf66b28fe842d319a35db7f78601ab7fc797e415c2fd14612beedd",
                "MacAddress": "02:42:ac:14:00:02",
                "IPv4Address": "172.20.0.2/16",
                "IPv6Address": ""
            },
            "5823c64c03de771a49cd54d32db9bf21ca5cc0717ae8d2606ea4bd671e02581d": {
                "Name": "alpine4",
                "EndpointID": "291658e0ca310d5aa5a52cbed7d8322d2003b472b5211a23eb13d86810d67359",
                "MacAddress": "02:42:ac:14:00:04",
                "IPv4Address": "172.20.0.4/16",
                "IPv6Address": ""
            }
        },
        "Options": {},
        "Labels": {}
    }
]
```

容器`alpine1`，`alpine2`和`alpine4`连接到 `alpine-net`网络。

#### ping 测试网络

---

在用户定义的网络中`alpine-net`，容器不仅可以通过IP地址进行通信，还可以**将容器名称解析为IP地址**。这种能力被称为**自动服务发现**。让我们连接`alpine1`并测试一下。`alpine1`应该能够解析 `alpine2`和`alpine4`（和`alpine1`自身）IP地址。

```shell
$ docker container attach alpine1
/ # ping -c 2 alpine2
PING alpine2 (172.20.0.3): 56 data bytes
64 bytes from 172.20.0.3: seq=0 ttl=64 time=0.198 ms
64 bytes from 172.20.0.3: seq=1 ttl=64 time=0.101 ms

--- alpine2 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.101/0.149/0.198 ms
/ # ping -c 2 alpine4
PING alpine4 (172.20.0.4): 56 data bytes
64 bytes from 172.20.0.4: seq=0 ttl=64 time=0.111 ms
64 bytes from 172.20.0.4: seq=1 ttl=64 time=0.116 ms

--- alpine4 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.111/0.113/0.116 ms
/ # ping -c 2 alpine1
PING alpine1 (172.20.0.2): 56 data bytes
64 bytes from 172.20.0.2: seq=0 ttl=64 time=0.040 ms
64 bytes from 172.20.0.2: seq=1 ttl=64 time=0.086 ms

--- alpine1 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.040/0.063/0.086 ms
```

从`alpine1`，你根本无法连接`alpine3`，因为它不在`alpine-net`网络上。

```shell
/ # ping -c 2 alpine3
ping: bad address 'alpine3'
```

不仅如此，也无法通过其IP地址连接到来自`alpine1`的`alpine3`。回头看看桥接网络的`docker network inspect`输出，并找到`alpine3`的IP地址：`172.17.0.2`尝试ping它。

```shell
/ # ping -c 2 172.17.0.2
PING 172.17.0.2 (172.17.0.2): 56 data bytes

--- 172.17.0.2 ping statistics ---
2 packets transmitted, 0 packets received, 100% packet loss
```

从后台模式的`alpine1`利用快捷键快速离开，或者输入：`exit`。

`alpine4`是连接到默认`bridge`网络和`alpine-net`。它应该能够到达所有其他容器。但是，需要`alpine3`通过IP地址进行寻址访问。

```shell
$ winpty docker container attach alpine4
/ # ping -c 2 alpine1
PING alpine1 (172.20.0.2): 56 data bytes
64 bytes from 172.20.0.2: seq=0 ttl=64 time=0.171 ms
64 bytes from 172.20.0.2: seq=1 ttl=64 time=0.146 ms

--- alpine1 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.146/0.158/0.171 ms
/ # ping -c 2 alpine2
PING alpine2 (172.20.0.3): 56 data bytes
64 bytes from 172.20.0.3: seq=0 ttl=64 time=0.235 ms
64 bytes from 172.20.0.3: seq=1 ttl=64 time=0.117 ms

--- alpine2 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.117/0.176/0.235 ms
/ # ping -c 2 alpine3
ping: bad address 'alpine3'
/ # ping -c 2 alpine4
PING alpine4 (172.20.0.4): 56 data bytes
64 bytes from 172.20.0.4: seq=0 ttl=64 time=0.040 ms
64 bytes from 172.20.0.4: seq=1 ttl=64 time=0.071 ms

--- alpine4 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.040/0.055/0.071 ms
/ # ping -c 2 172.17.0.2
PING 172.17.0.2 (172.17.0.2): 56 data bytes
64 bytes from 172.17.0.2: seq=0 ttl=64 time=0.161 ms
64 bytes from 172.17.0.2: seq=1 ttl=64 time=0.100 ms

--- 172.17.0.2 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.100/0.130/0.161 ms
```

最后来测试下外网的访问，确保你的容器都可以通过ping来连接到互联网`github.com`。

```shell
$ docker container attach alpine3

/ # ping -c 2 github.com
PING github.com (13.250.177.223): 56 data bytes

--- github.com ping statistics ---
2 packets transmitted, 0 packets received, 100% packet loss

CTRL+p CTRL+q

$ docker container attach alpine1

# ping -c 2 github.com

PING google.com (172.217.3.174): 56 data bytes
64 bytes from 172.217.3.174: seq=0 ttl=41 time=9.606 ms
64 bytes from 172.217.3.174: seq=1 ttl=41 time=9.603 ms

--- github.com ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 9.603/9.604/9.606 ms

CTRL+p CTRL+q
```

#### 停止和删除容器

---

停止并删除所有容器和`alpine-net`网络。

```shell
$ docker container stop alpine1 alpine2 alpine3 alpine4

$ docker container rm alpine1 alpine2 alpine3 alpine4

$ docker network rm alpine-net
```

# host 网络应用

如果使用`host`网络驱动程序作为容器，则该容器的**网络堆栈不与Docker主机隔离**。例如，如果运行绑定到端口80的容器并使用`host`网络，则该**容器的应用程序将在主机IP地址的端口80上可用**。

你也可以使用一个`host`网络中的集群服务，通过将`--network host`传递给`docker container create`命令。在这种情况下，控制运输（管理集群和服务相关的运输）仍然通过覆盖网络发送，但各个群集服务容器使用Docker守护进程的主机网络和端口发送数据。这会产生一些额外的限制。例如，如果服务容器绑定到端口80，则只有一个服务容器可以在给定的群集节点上运行。

如果你的容器或服务**没有发布端口，则主机网络不起作用**。

## 使用主机网络进行联网

与Docker主机网络绑定的网络独立容器，不存在网络隔离问题。下面启动一个`nginx`容器，该容器直接绑定到Docker主机上的端口80，此过程要求端口80在Docker主机上可用。从网络的角度来看，这与隔离级别相同，就好像`nginx`进程直接在Docker主机上运行一样，而不是在容器中运行。但是，在其他所有方面，例如存储、进程名称空间和用户名称空间，`nginx`进程都与主机隔离。

### 创建和启动容器

---

创建并启动容器，使用后台分离模式。

```shell
$ docker run --rm -dit --network host --name my_nginx nginx
```

### 访问程序

---

通过浏览器或者`curl`访问`Nginx`：http://ip:80/

```shell
$ docker-machine.exe ip
192.168.99.100

$ curl http://192.168.99.100:80
```

### 检查网络

---

使用以下命令检查你的网络堆栈，首先连接到机器 `docker-machine ssh default`：

- 检查所有网络接口并验证没有创建新接口。

  ```shell
  $ ip addr show
  ```

- 使用该`netstat`命令验证哪个进程绑定到端口80 。你需要使用，`sudo`因为该进程由Docker守护程序用户拥有，否则你将无法查看其名称或PID。

  ```shell
  $ sudo netstat -tulpn | grep :80
  ```

### 停止和删除容器

---

停止和删除容器

```shell
$ docker container stop my_nginx
$ docker container rm my_nginx
```

# overlay 网络应用

`overlay`网络驱动程序会创建多个`docker worker` 节点守护主机之间的分布式网络。`overlay`网络位于（覆盖）主机特定网络之上，允许与其连接的容器（包括集群服务容器）安全地进行通信。Docker透明地处理每个数据包与正确的Docker守护进程主机和正确的目标容器之间的**路由**。

在初始化集群或将Docker主机加入现有集群时，将在该Docker主机上**创建两个新网络**：

- 覆盖网络`ingress`，用于处理与集群服务相关的控制和数据传输。当你创建集群服务并且不将其连接到自定义的覆盖网络时，它默认连接到网络`ingress` 。
- 桥接网络`docker_gwbridge`，它将单个Docker守护程序连接到集群中的其他守护程序。

你可以使用创建自定义`overlay`网络`docker network create`的方式来创建自定义`bridge`网络。**服务或容器一次可以连接到多个网络**。服务或容器只能通过它们各自连接的网络进行通信。

尽管你可以将swarm服务和独立容器连接到覆盖网络，但默认行为和配置方式是不同的。因此，本章节的其余部分分为适用于所有覆盖网络的操作，适用于集群服务网络的操作以及适用于独立容器使用的覆盖网络的操作。

## 默认和自定义overlay网络操作流程

### 创建`overlay`网络

---

> **必要条件**：
>
> - 使用`overlay`覆盖网络的Docker守护进程的防火墙规则
>
>   需要打开以下端口才能访问`overlay`覆盖网络上的每个Docker主机：
>
>   - TCP端口2377用于集群管理通信
>   - TCP和UDP端口7946用于节点之间的通信
>   - UDP端口4789用于`overlay`覆盖网络通信
>
> - 在创建`overlay`覆盖网络之前，需要将Docker守护程序初始化为集群管理器，`docker swarm init`或者将其加入到现有的群集中`docker swarm join`。两者都创建默认`overlay`覆盖网络，默认情况下集群服务会使用默认 `ingress`覆盖网络。即使从未计划使用群集服务，也需要这样做。之后，可以创建其他自定义的`overlay`覆盖网络。

要创建与集群服务一起使用的`overlay`覆盖网络，请使用类似以下的命令：

```shell
$ docker network create -d overlay my-overlay
```

要创建可以被 集群服务**或** 独立容器，用来运行在其他Docker守护程序上的独立容器通信的`overlay`覆盖网络，请添加`--attachable`选项：

```sh
$ docker network create -d overlay --attachable my-attachable-overlay
```

你可以指定IP地址范围，子网，网关和其他选项。

### 加密`overlay`网络上的数据传输

---

所有集群服务管理数据传输默认都是加密的，在GCM模式下使用 [AES算法](https://en.wikipedia.org/wiki/Galois/Counter_Mode)。集群管理节点每12小时转换一次用于加密数据的密钥。

要加密应用程序数据，请在创建`overlay`覆盖网络时添加`--opt encrypted`。这使得`vxlan`级别的IPSEC加密成为可能。这种加密技术会带来**不可忽视的性能损失**，因此应该在生产中使用该加密技术之前对其进行测试。

当启用`overlay`覆盖加密时，Docker会在**所有节点之间创建IPSEC隧道**，在这些节点上调度连接到`overlay`覆盖网络的服务的任务。这些通道在GCM模式下也使用AES算法，管理器节点每12小时自动转换一次密钥。

> **不要将Windows节点附加到加密的`overlay`网络。**
>
> Windows上不支持`overlay`覆盖网络加密。如果Windows节点尝试连接到加密的`overlay`覆盖网络，则检测不到错误，但节点无法通信。

**集群模式`overlay`网络和独立容器**

可以在两者上使用`overlay`覆盖网络功能，`--opt encrypted --attachable` 并将非托管容器连接到该网络：

```shell
$ docker network create --opt encrypted --driver overlay --attachable my-attachable-multi-host-network
```

### 自定义默认`ingress`网络

---

大多数用户从不需要配置`ingress`网络，但Docker 17.05和更高版本允许这样做。如果自动选择的子网与网络中已存在的子网冲突，或者需要自定义其他**低级网络**设置（如MTU），则此功能非常有用。

定制`ingress`网络涉及到删除和重新创建网络。这通常在集群中创建任何服务前完成。如果有现有的发布端口的服务，则需要先删除这些服务，然后才能删除`ingress`网络。

**在没有`ingress`网络存在的时候，不发布端口的现有服务可以继续运行，但没有负载平衡**。这会影响发布端口的服务，例如发布端口80的WordPress服务，它们将不能对外提供服务。

#### 检查网络

使用`ingress`检查网络`docker network inspect ingress`，并删除任何容器连接到它的服务。这些是发布端口的服务，例如发布端口80的WordPress服务。如果所有这些服务都未停止，则下一步将失败。

#### 删除网络

删除现有`ingress`网络：

```shell
$ docker network rm ingress
WARNING! Before removing the routing-mesh network, make sure all the nodes in your swarm run the same docker engine version. Otherwise, removal may not be effective and functionality of newly create ingress networks will be impaired.
Are you sure you want to continue? [y/N] y
ingress
```

#### 创建网络

使用该`--ingress`选项创建一个新的`overlay`覆盖网络，以及要设置的自定义选项。本示例将MTU设置为1200，将子网设置为`10.11.0.0/16`，并将网关设置为`10.11.0.2`。

```sh
$ docker network create \
  --driver overlay \
  --ingress \
  --subnet=10.11.0.0/16 \
  --gateway=10.11.0.2 \
  --opt com.docker.network.driver.mtu=1200 \
  my-ingress
```

> **注意**：可以将`ingress`网络命名为除了以外的其他`ingress` 名称，但只能有一个。尝试创建第二个会失败。

#### 重启服务

重新启动在第一步中停止的服务。让它连接到当前设置的`my-ingress`网络中。

### 自定义`docker_gwbridge`界面

`docker_gwbridge`是一个将`overlay`覆盖网络（包括`ingress`网络）连接到单独的Docker守护进程**物理网络的虚拟桥**。当初始化集群或将Docker主机加入集群时，Docker自动创建它，但它不是Docker设备，**它存在于Docker主机的内核中**。如果需要自定义其设置，则必须在将Docker主机加入集群之前或临时从集群中删除主机之后执行此操作。

1. 停止Docker。

   ```shell
   $ service docker stop
   ```

2. 删除现有的`docker_gwbridge`界面。

   ```shell
   $ sudo ip link set docker_gwbridge down
   $ sudo ip link del dev docker_gwbridge
   ```

3. 启动Docker。不要加入或初始化群体。

   ```shell
   $ service docker start
   ```

4. `docker_gwbridge`使用`docker network create`命令，使用自定义设置手动创建或重新创建网桥。本例使用子网`10.11.0.0/16`。

   ```shell
   $ docker network create \
   --subnet 10.11.0.0/16 \
   --opt com.docker.network.bridge.name=docker_gwbridge \
   --opt com.docker.network.bridge.enable_icc=false \
   --opt com.docker.network.bridge.enable_ip_masquerade=true \
   docker_gwbridge
   ```

5. 初始化或加入群。由于该桥已经存在，因此Docker不会使用自动设置来创建它。

   ```shell
   $ docker swarm init
   ```

## 集群`overlay`网络的操作

### 在`overlay`网络上发布端口

---

连接到同一`overlay`覆盖网络的群集服务可以有效地将所有端口暴露给对方。要使端口可以在服务之外访问，必须使用`docker service create`或是`docker service update`上的`-p`或`--publish`来**发布**该端口。支持传统的以冒号分隔的语法和较新的逗号分隔值语法。较长的语法是首选，因为它有点自我记录。

| 选项                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `-p 8080:80` or`-p published=8080,target=80`                 | 将服务上的TCP端口80映射到路由网格上的端口8080。              |
| `-p 8080:80/udp` or`-p published=8080,target=80,protocol=udp` | 将服务上的UDP端口80映射到路由网格上的端口8080。              |
| `-p 8080:80/tcp -p 8080:80/udp` or `-p published=8080,target=80,protocol=tcp -p published=8080,target=80,protocol=udp` | 将服务上的TCP端口80映射到路由网格上的TCP端口8080，并将该服务上的UDP端口80映射到例程网格上的UDP端口8080。 |

### 绕过`swarm`服务的路由网格

---

默认情况下，发布端口的集群服务使用路由网格来完成。当你连接到任何swarm节点上的已发布端口（无论是否运行给定服务）时，都会透明地将你重定向到正在运行该服务的工作节点。实际上，Docker充当群集服务的负载平衡器。使用路由网格的服务以**虚拟IP（VIP）模式运行**。即使在每个节点上运行的服务（通过`--global`选项）也使用路由网格。**使用路由网格时，不能保证固定Docker节点服务客户端请求**。

要绕过路由网格，你可以使用**DNS循环（DNSRR）模式**启动服务，方法是将`--endpoint-mode`选项设置为`dnsrr`。**必须在服务前运行自己的负载均衡器**。Docker主机上的服务名称的DNS查询会返回运行该服务的**节点的IP地址列表**。配置**负载均衡器使用此列表并平衡各节点间**的流量。

### 单独的控制和数据传输

---

默认情况下，尽管集群控制数据传输是**加密**的，但集群管理和应用程序之间的控制数据传输运行在同一个网络上。你可以将Docker配置为使用**单独的网络接口**来处理两种不同类型的传输数据。当你初始化或者加入集群时分别指定`--advertise-addr`和`--datapath-addr`。必须为加入群的每个节点执行这个操作。

## `overlay`网络上的独立容器

### 将独立容器附加到`overlay`网络

---

`ingress`网络是创造无`--attachable`选项，这意味着**只有集群服务**可以使用它，而不是独立的容器。你可以将独立容器连接到用`--attachable`选项创建的自定义`overlay`覆盖网络。这使运行在不同Docker守护进程上的独立容器能够进行通信，而无需在各个Docker守护进程主机上设置路由。

### 发布端口

| 选项值                          | 描述                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| `-p 8080:80`                    | 将容器中的TCP端口80映射到覆盖网络上的端口8080。              |
| `-p 8080:80/udp`                | 将容器中的UDP端口80映射到覆盖网络上的端口8080。              |
| `-p 8080:80/sctp`               | 将容器中的SCTP端口80映射到覆盖网络上的端口8080。             |
| `-p 8080:80/tcp -p 8080:80/udp` | 将容器中的TCP端口80映射到覆盖网络上的TCP端口8080，并将容器中的UDP端口80映射到覆盖网络上的UDP端口8080。 |

### 容器发现

对于大多数情况，你应该连接到服务名称，该服务名称是负载平衡的，并由支持服务的所有容器（“任务”）处理。要获取支持该服务的所有任务的列表，请执行DNS查找`tasks.<service-name>.`

## 实例演示

`overlay`网络涉及集群服务。这个演示包括四个不同的部分。可以在Linux，Windows或Mac上运行它们中的每一个，但对于最后两个，需要在别处运行的第二个Docker主机。

- [使用默认的覆盖网络](https://docs.docker.com/network/network-tutorial-overlay/#use-the-default-overlay-network)演示如何使用Docker在初始化或加入群时自动为你设置的默认覆盖网络。这个网络不是生产系统的最佳选择。
- [使用用户定义的覆盖网络](https://docs.docker.com/network/network-tutorial-overlay/#use-a-user-defined-overlay-network)显示如何创建和使用自己的自定义覆盖网络来连接服务。建议用于在生产中运行的服务。
- [为独立容器使用覆盖网络](https://docs.docker.com/network/network-tutorial-overlay/#use-an-overlay-network-for-standalone-containers) 显示了如何使用覆盖网络在不同Docker守护进程上的独立容器之间进行通信。
- [通过容器和群集服务](https://docs.docker.com/network/network-tutorial-overlay/#communicate-between-a-container-and-a-swarm-service) 之间的通信，使用可附加覆盖网络，在独立容器和群集服务之间建立通信。这在Docker 17.06和更高版本中受支持。

### 使用默认覆盖网络

---

首先需要三台物理或虚拟Docker主机，它们都可以相互通信，所有主机都在运行Docker 17.03或更高版本的新安装。假定这三台主机运行在同一个网络上，没有涉及防火墙。

这些主机将被称为`manager`，`worker-1`和`worker-2`。该 `manager`主机将作为既是**管理节点和工作节点**，这意味着它可以运行服务任务和管理集群。`worker-1`、`worker-2`只能作为处理工作任务使用。下面创建好三台主机作为后续操作环境：

```shell
$ docker-machine create manager --driver virtualbox
$ docker-machine create worker-1 --driver virtualbox
$ docker-machine create worker-1 --driver virtualbox
```

如果你没有三台主机，那么一个简单的解决方案就是在云提供商（例如Amazon EC2）上设置三台Ubuntu主机，所有这些主机都位于同一网络上，并允许该网络上所有主机的所有通信（使用诸如EC2安全组），然后按照[Ubuntu上Docker CE](https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/)的[安装说明进行操作](https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/)。

#### 创建和加入集群

---

在此过程结束时，所有三台Docker主机都将加入集群，并使用名为`ingress`覆盖网络连接在一起。

1、在`master`主机上初始化集群体。如果主机只有一个网络接口，则该`--advertise-addr`选项是可选的。

```shell
$ docker-machine ip
192.168.99.100

$ docker swarm init --advertise-addr=192.168.99.100
Swarm initialized: current node (q6g57ikahfehxon8s1np4iqgy) is now a manager.
To add a worker to this swarm, run the following command:
    docker swarm join --token SWMTKN-1-57vmgmqev6b4d5q6tf134j9p5avwr100pokne6lij2kxsiluo1-bbe3vly8mz06t17f3t43fs2yb 192.168.99.100:2377
To add a manager to this swarm, run 'docker swarm join-token manager' and follow the instructions.
```

记下打印的文本，因为这包含将用于加入`worker-1`和`worker-2`集群的数据和命令。**令牌是存储在密码管理器中**。

2、在`worker-1`主机上执行加入集群命令。如果主机只有一个网络接口，则该`--advertise-addr`选项是可选的。

```shell
$ docker swarm join --token <TOKEN> \
  --advertise-addr <IP-ADDRESS-OF-WORKER-1> \
  <IP-ADDRESS-OF-MANAGER>:2377

$ docker swarm join --token SWMTKN-1-57vmgmqev6b4d5q6tf134j9p5avwr100pokne6lij2kxsiluo1-bbe3vly8mz06t17f3t43fs2yb 192.168.99.100:2377
# 或者
$ docker swarm join --token SWMTKN-1-57vmgmqev6b4d5q6tf134j9p5avwr100pokne6lij2kxsiluo1-bbe3vly8mz06t17f3t43fs2yb --advertise-addr 192.168.99.101 192.168.99.100:2377
```

同上在`worker-2`上执行相似的命令，让它也加入到集群中。

3、在`manager`列出所有节点。该命令只能由管理员完成。

```shell
$ docker node ls
ID                            HOSTNAME            STATUS              AVAILABILITY        MANAGER STATUS      ENGINE VERSION
q6g57ikahfehxon8s1np4iqgy *   manager-node             Ready               Active              Leader              18.04.0-ce
hkkq8c6rdtwrbt69lubfofs9p    worker-1        Ready               Active                                  18.04.0-ce
4olz9iy9zwazqt41lsnnprxc8    worker-2        Ready               Active                                  18.04.0-ce
```

4、还可以使用`--filter`选项按角色进行过滤：

```shell
$ docker node ls --filter role=manager
ID                            HOSTNAME            STATUS              AVAILABILITY        MANAGER STATUS      ENGINE VERSION
q6g57ikahfehxon8s1np4iqgy *   manager-node             Ready               Active              Leader              18.04.0-ce

$ docker node ls --filter role=worker
ID                            HOSTNAME            STATUS              AVAILABILITY        MANAGER STATUS      ENGINE VERSION
hkkq8c6rdtwrbt69lubfofs9p     worker-1        Ready               Active                                  18.04.0-ce
4olz9iy9zwazqt41lsnnprxc8     worker-2        Ready               Active                                  18.04.0-ce
```

5、查看docker网络列表`manager`，`worker-1`以及`worker-2`，并注意每个节点现在都是`ingress`的覆盖网络和`docker_gwbridge`的网桥。此处仅显示列表：

```shell
$ docker network ls
NETWORK ID          NAME                DRIVER              SCOPE
67d06a5d229f        bridge              bridge              local
885abe3b2ff6        docker_gwbridge     bridge              local
99b53a220971        host                host                local
74nmcp6kzzan        ingress             overlay             swarm
```

`docker_gwbridge`将`ingress`网络连接到Docker主机的网络接口，以便数据流量可以流入和流出集群管理节点和工作节点。如果你创建集群服务并且未指定网络，则它们将连接到`ingress`网络。建议你为每个应用程序或一组可以一起工作的应用程序使用**单独的覆盖网络**。在下一个过程中，你将创建两个覆盖网络并将服务连接到每个覆盖网络。

#### 创建网络和服务

---

1、在`manager`节点上，创建一个新的覆盖网络称为`nginx-net`：

```shell
$ docker network create -d overlay nginx-net
```

你不需要在其他节点上创建覆盖网络，因为当其中一个节点开始运行需要它的服务任务时，它将自动创建。

2、在`manager`节点上面，创建一个5个副本的Nginx服务并连接`nginx-net`。该服务将向外界公布80端口。所有服务任务容器都可以相互通信而无需打开任何端口。

> **注意**：服务只能在管理节点上创建。

```shell
$ docker service create \
  --name my-nginx \
  --publish target=80,published=80 \
  --replicas=5 \
  --network nginx-net \
  nginx
```

默认的发布模式是`ingress`，当没有为`--publish`指定模式时，意味着如果浏览`manager`、`worker-1`或`worker-2`上的端口80。你会被连接到端口80上的5项服务任务之一，任务正在你当前浏览到的节点上运行。如果你想发布端口使用 `host`模式，你可以添加到`--publish` `mode=host`输出。但是，由于只有一个服务任务可以绑定给定节点上的给定端口，因此你也应该使用`--mode global`而不是`--replicas=5`这种情况。

3、运行`docker service ls`以监视服务启动的进度

```shell
$ docker service ls
ID                  NAME                MODE                REPLICAS            IMAGE               PORTS
ioqgplafut24        my-nginx            replicated          5/5                 nginx:latest        *:80->80/tcp
```

4、检查`master`网络`nginx-net`，`worker-1`和`worker-2`。不需要手动创建它`worker-1`， `worker-2`。因为Docker为你创建了它。输出将很长，但注意`Containers`和`Peers`部分。`Containers`列出了从该主机连接到覆盖网络的所有服务任务（或独立容器）。

```shell
$ docker network inspect nginx-net
[
    {
        "Name": "nginx-net",
        "Id": "t6c3jhweeel5hoslazx35wf2q",
        "Created": "2018-05-01T09:15:14.127442978Z",
        "Scope": "swarm",
        "Driver": "overlay",
        .......
        "Containers": {
            "3b5ba5312cfcd83f7d0ea147d3f90040d788284c1b0387d2ad2559b50a53d73d": {
                "Name": "my-nginx.4.tpwmc1z18db8167xpi8yirg4i",
                "EndpointID": "a4e7020d60dd86f1dbaba6df82ba64f5df3e06663caca6fcb68337e8058588e4",
                "MacAddress": "02:42:0a:00:00:08",
                "IPv4Address": "10.0.0.8/24",
                "IPv6Address": ""
            },
            "7d0c2829e567bf1b851222007ed887023eca767cd24a4e643c4abb4f5da82297": {
                "Name": "my-nginx.2.uuzb08nr6xcauk9wgla7or31y",
                "EndpointID": "c7c3080c02bf0f3d3256891666aeb98d31f34348a1627f004313e3ea85954868",
                "MacAddress": "02:42:0a:00:00:06",
                "IPv4Address": "10.0.0.6/24",
                "IPv6Address": ""
            }
        },
        .....
        "Peers": [
            {
                "Name": "b5173b86aeec",
                "IP": "192.168.99.100"
            },
            {
                "Name": "d4defda52944",
                "IP": "192.168.99.101"
            },
            {
                "Name": "2d5a64572154",
                "IP": "192.168.99.102"
            }
        ]
    }
]
```

5、从`manager`节点检查使用的服务`docker service inspect my-nginx` 并注意有关服务使用的端口和端点的信息。

6、创建一个新网络`nginx-net-2`，然后更新服务使用此网络，而不是`nginx-net`：

```shell
$ docker network create -d overlay nginx-net-2
$ docker service update \
  --network-add nginx-net-2 \
  --network-rm nginx-net \
  my-nginx
```

7、运行`docker service ls`以验证服务已更新并且所有任务已被重新部署。运行`docker network inspect nginx-net`以验证没有容器连接到它。运行相同的命令 `nginx-net-2`并注意所有服务任务容器都连接到它。

```shell
$ docker network inspect nginx-net --format={{.Containers}}
map[]

$ docker network inspect nginx-net-2 --format={{.Containers}}
map[0cf55d3b0e28d23f5942d5f947c2fc15924f6d3d4a41c8b2ab29f6553fec029a:{my-nginx.2.r7rovntac70dgix4k9lu8s3sf 698f027e843ed77aeb8bbc0667e7d5302151c6a6ae072da5ac253c068511ea2d 02:42:0a:00:01:09 10.0.1.9/24 } 8d9ef33c8e4da8c715131ccca2889e503bb065a4456af56f28bc103bdfda1870:{my-nginx.3.6pxltwv844nbqq7fqm9rwhl2l f4bcedc24e92c34419999815b74188549e533394fc4ea3a85a4d3888bed14904 02:42:0a:00:01:0a 10.0.1.10/24 }]
```

上面`nginx-net`网络没有链接任何容器，虽然网络在需要的时候自动创建，但不会自动删除。

> 注意**：覆盖网络根据需要，在集群工作节点上自动创建，它们也不会自动删除。

8、清理服务和网络。从`manager`节点上运行以下命令。管理节点将指导工作节点自动移除网络。

```shell
$ docker service rm my-nginx
$ docker network rm nginx-net nginx-net-2
```

### 使用自定义的覆盖网络

---

1、创建自定义的覆盖网络。

```shell
$ docker network create -d overlay my-overlay
```

2、在Docker主机上使用覆盖网络和发布端口80到8080的服务。

```shell
$ docker service create \
  --name my-nginx \
  --network my-overlay \
  --replicas 1 \
  --publish published=8080,target=80 \
  nginx:latest
```

3、查看`my-overlay`自定义网络，通过运行`docker network inspect my-overlay`并验证`my-nginx`服务任务是否已连接到该服务任务`Containers`。

```shell
$ docker network inspect my-overlay --format={{.Containers}}
map[59dbce61bef680ce97238c54046142d5e68787915ca2c0123260d8e228101a43:{my-nginx.1.cqyyc3xzs56dyjg9adhuwg1p2 d8f8a43dc40df419b9271dfff60fcd284fa83392a7a142c1c6e9ec22174f44fc 02:42:0a:00:00:06 10.0.0.6/24 }]
```

4、删除服务和网络。

```shell
$ docker service rm my-nginx && docker network rm my-overlay
```

### 在独立容器使用覆盖网络

---

本示例演示了DNS容器发现， 具体说明了如何使用覆盖网络在不同Docker守护进程上的独立容器之间进行通信。步骤是：

- 开始时`host1`，将节点初始化为集群（管理节点）。
- 在`host2`上，将节点加入集群（工作节点）。
- 在`host1`，创建一个可连接的覆盖网络（`test-net`）。
- 在`host1`上运行一个交互式`test-net`[alpine](https://hub.docker.com/_/alpine/)容器（`alpine1`）。
- 在上`host2`，运行一个互动的`test-net`，分离的[alpine](https://hub.docker.com/_/alpine/)容器（`alpine2`）。
- `host1`从一个会话中`alpine1` ping `alpine2`。

首先需要两个不同的Docker主机，它们可以相互通信。每台主机必须具有Docker 17.06或更高版本，并在两台Docker主机之间打开以下端口：

- TCP端口2377
- TCP和UDP端口7946
- UDP端口4789

一个简单的方法是设置两个虚拟机，每个虚拟机都安装并运行Docker。下面将我们集群中的两个节点称为`host1`和`host2`。

#### 创建集群

在`host1`上初始化群：

```shell
$ docker swarm init
Error response from daemon: could not choose an IP address to advertise since this system has multiple addresses on different interfaces (10.0.2.15 on eth0 and 192.168.99.100 on eth1) - specify one with --advertise-addr
```

如果出现提示，请使用`--advertise-addr` 指定与群中其他主机通信的接口的IP地址，例如AWS上的私有IP地址。

```shell
$ docker swarm init --advertise-addr  192.168.99.100
Swarm initialized: current node (888gi7byqi5p7wtd2yv1z465i) is now a manager.

To add a worker to this swarm, run the following command:
    docker swarm join --token SWMTKN-1-50ewgk565kwml1tighphq8r7u7vf78ssztfpy8tq1rhtjse79n-3ut3kbrc1l7czf2ndvrdg9i3l 192.168.99.100:2377

To add a manager to this swarm, run 'docker swarm join-token manager' and follow the instructions.
```

连接到`docker-machine ssh host2 `在 `host2`上面，按照上面的指示加入群：

```shell
# docker swarm join --token <your_token> <your_ip_address>:2377
$ docker-machine ssh host2 
$ docker swarm join --token SWMTKN-1-50ewgk565kwml1tighphq8r7u7vf78ssztfpy8tq1rhtjse79n-3ut3kbrc1l7czf2ndvrdg9i3l 192.168.99.100:2377
This node joined a swarm as a worker.
```

如果节点未能加入群，则`docker swarm join`命令超时。要解决需要运行`docker swarm leave --force`，在`host2`上验证你的网络和防火墙设置，然后再试一次。

#### 创建网络

在`host1`，创建一个可附加的覆盖网络称为`test-net`：

```shell
$ docker network create --driver=overlay --attachable test-net
uqsof8phj3ak0rq9k86zta6ht
```

> **注意**：返回的**网络ID** - 当你连接到**网络**时，你将再次看到它。

#### 启动容器

在`host1`上，启动一个交互式（`-it`）容器（`alpine1`），它连接到`test-net`：

```shell
$ docker run -it --name alpine1 --network test-net alpine
/ #
```

#### 查看网络

在`host2`，列出可用的网络， 注意`test-net`尚不存在：

```shell
$ docker network ls
NETWORK ID          NAME                DRIVER              SCOPE
ec299350b504        bridge              bridge              local
66e77d0d0e9a        docker_gwbridge     bridge              local
9f6ae26ccb82        host                host                local
omvdxqrda80z        ingress             overlay             swarm
b65c952a4b2b        none                null                local
```

#### 启动容器

在`host2`上，启动一个分离的（`-d`）和interactive（`-it`）容器（`alpine2`），它连接到`test-net`：

```shell
$ docker run -dit --name alpine2 --network test-net alpine
fb635f5ece59563e7b8b99556f816d24e6949a5f6a5b1fbd92ca244db17a4342
```

> DNS自动容器发现仅适用于**唯一的容器名称**。

#### 查看网络

在`host2`上验证`test-net`是否被创建，发现网络已被创建。

```shell
$  docker network ls
NETWORK ID          NAME                DRIVER              SCOPE
e50370495550        bridge              bridge              local
41858e9965fd        docker_gwbridge     bridge              local
4148ea059de0        host                host                local
ynu4c3182rby        ingress             overlay             swarm
e958feaac111        none                null                local
9xw0rjrttcn7        test-net            overlay             swarm

```

#### 测试网络

在`host1`上利用交互式终端`alpine1`内ping `alpine2`：

```
/ # ping -c 2 alpine2
PING alpine2 (10.0.0.5): 56 data bytes
64 bytes from 10.0.0.5: seq=0 ttl=64 time=0.444 ms
64 bytes from 10.0.0.5: seq=1 ttl=64 time=0.462 ms

--- alpine2 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.444/0.453/0.462 ms
/ # ping -c 2 alpine1
PING alpine1 (10.0.0.4): 56 data bytes
64 bytes from 10.0.0.4: seq=0 ttl=64 time=0.068 ms
64 bytes from 10.0.0.4: seq=1 ttl=64 time=0.112 ms

--- alpine1 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.068/0.090/0.112 ms
```

这两个容器与连接两台主机的覆盖网络进行通信。如果你在`host2`上运行另一个未分离的`alpine`容器，则可以从`host2 `ping `alpine1`（添加用于自动清除容器的`remove`选项）：：

```shell
$ docker run -it --rm --name alpine3 --network test-net alpine
/ # ping -c 2 alpine1
PING alpine1 (10.0.0.4): 56 data bytes
64 bytes from 10.0.0.4: seq=0 ttl=64 time=0.623 ms
64 bytes from 10.0.0.4: seq=1 ttl=64 time=0.620 ms

--- alpine1 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.620/0.621/0.623 ms
/ # ping -c 2 alpine2
PING alpine2 (10.0.0.5): 56 data bytes
64 bytes from 10.0.0.5: seq=0 ttl=64 time=0.128 ms
64 bytes from 10.0.0.5: seq=1 ttl=64 time=0.116 ms

--- alpine2 ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max = 0.116/0.122/0.128 ms
```

#### 退出交互

在`host1`上关闭`alpine1`会话（也会停止容器）：

```
/ # exit
```

#### 删除容器和网络

你必须独立停止并移除每个主机上的容器，因为Docker守护进程独立运行，并且这些是独立的容器。你只需要删除网络，因为当你停下 `alpine2`，`test-net`消失。

在`host2`停止`alpine2`，检查`test-net`被自动删除，然后删除`alpine2`：

```shell
$ docker container stop alpine2
$ docker network ls
$ docker container rm alpine2
```

在`host1`上删除`alpine1`和`test-net`：

```shell
$ docker container rm alpine1
$ docker network rm test-net
```

### 在容器和集群服务之间进行通信

下面将在同一个Docker主机上启动两个不同的`alpine`容器，并进行一些测试以了解它们如何相互通信。

#### 查看网络

打开一个终端窗口，列出当前的网络。如果你从未在此Docker守护程序中添加网络或初始化群集，可能会看到不同的网络，但你至少应该看到这些网络（网络ID将会不同）：

```sh
$ docker network ls
NETWORK ID          NAME                DRIVER              SCOPE
67d06a5d229f        bridge              bridge              local
885abe3b2ff6        docker_gwbridge     bridge              local
99b53a220971        host                host                local
ynu4c3182rby        ingress             overlay             swarm
```

列出了默认`bridge`、`host`以及`none`网络。后两者不是完全成熟的网络，而是用于启动直接连接到Docker守护进程主机的网络堆栈的容器，或者启动没有网络设备的容器。**下面将两个容器连接到bridge网络。**

#### 启动容器

启动两个运行`ash`的容器`alpine`，这是`alpine`的默认shell，而不是`bash`。该`-dit`选项意味着要首先分离容器在后台运行并可以互动（与输入到它的能力），并支持TTY（这样你就可以看到输入和输出）。由于使用后台分离模式，所以不会立即连接到容器进行交互，但容器的ID将被打印。由于没有指定任何 `--network`选项，因此容器将连接到默认`bridge`网络。

```sh
$ docker run -dit --name alpine1 alpine ash

$ docker run -dit --name alpine2 alpine ash
```

检查两个容器是否实际启动：

```shell
$ docker container ls
```

#### 检查网络

------

检查`bridge`网络以查看连接到它的容器

```shell
$ docker network inspect bridge
[
    {
        "Name": "bridge",
        "Id": "67d06a5d229f062814bf31dca1dac3b04cbba46bf9257180b4d75da1e1a351d1",
        "Created": "2018-05-01T06:54:55.989296768Z",
        "Scope": "local",
        "Driver": "bridge",
        ......
        "Containers": {
            "436fd58700af5394c0e0e9461bfb96da8b3bbc8f2c00930024ad822cff5f4f12": {
                "Name": "alpine1",
                "EndpointID": "5ccf4333f9844c22390a6d053c518e413573fcded063ae9ed236c21b02e9b43c",
                "MacAddress": "02:42:ac:11:00:02",
                "IPv4Address": "172.17.0.2/16",
                "IPv6Address": ""
            },
            "b4ae49d2e30413629ea722b265a72b2ff0f4c0992daa93dc414e4b4c61681bce": {
                "Name": "alpine2",
                "EndpointID": "3f4db09018431c429464af4c3bae9f950b0c817d9576759659fcb0ca39ad1e7f",
                "MacAddress": "02:42:ac:11:00:03",
                "IPv4Address": "172.17.0.3/16",
                "IPv6Address": ""
            }
        },
      ..... 
```

在上面列出了有关`bridge`网络的信息，包括Docker主机和`bridge` 网络之间网关的IP地址（`172.17.0.1`）。在`Containers`关键字下方，列出了每个连接的容器，以及有关其IP地址（`172.17.0.2`用于 `alpine1`和`172.17.0.3`用于`alpine2`）的信息。

#### 建立交互

容器在后台运行。使用该`docker attach` 命令连接到`alpine1`。

```sh
$ docker attach alpine1
/ #
```

提示符更改为`#`指示你是`root`容器内的用户。使用该`ip addr show`命令显示网络接口`alpine1`的容器内容：

```
# ip addr show
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN qlen 1
    link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    inet 127.0.0.1/8 scope host lo
       valid_lft forever preferred_lft forever
59: eth0@if60: <BROADCAST,MULTICAST,UP,LOWER_UP,M-DOWN> mtu 1500 qdisc noqueue state UP
    link/ether 02:42:ac:11:00:02 brd ff:ff:ff:ff:ff:ff
    inet 172.17.0.2/16 brd 172.17.255.255 scope global eth0
       valid_lft forever preferred_lft forever
```

第一个接口是回送设备，现在可以忽略它。第二个接口的IP地址与上一步中`172.17.0.2`显示的地址相同`alpine1`。

#### ping 测试

从内部`alpine1`，请确保你可以通过ping连接到互联网`github.com` 其中`-c 2`选项限制命令`ping` 两次尝试。

```sh
# ping -c 2 github.com
```

现在尝试ping第二个容器。首先通过IP地址 `172.17.0.3`ping它：

```sh
# ping -c 2 172.17.0.3
```

这成功了。接下来尝试通过容器名称ping `alpine2`容器，这将失败。

```sh
# ping -c 2 alpine2
ping: bad address 'alpine2'
```

#### 退出交互

退出交互模式`alpine2`使用快捷键`CTRL`+ `p` `CTRL`+ `q`（按住`CTRL`并键入`p`其后`q`），不需要停止它 。

#### 删除容器

停止并移除两个容器。

```sh
$ docker container stop alpine1 alpine2
$ docker container rm alpine1 alpine2
```

建议不要将默认网络`bridge`用于生产环境。

# macvlan 网络应用

一些应用程序，尤其是监视网络流量的传统应用程序，希望直接连接到物理网络。在这种情况下，你可以使用`macvlan`网络驱动程序为每个容器的**虚拟网络接口分配MAC地址**，使其看起来像是直接连接到物理网络的物理网络接口。在这种情况下，你需要指定Docker主机上的物理接口用于Macvlan，以及Macvlan的子网和网关。你甚至可以使用不同的物理网络接口来隔离Macvlan网络。记住以下几点：

- 由于IP地址耗尽或“VLAN传播”（这种情况下，你的网络中存在不适当的大量唯一MAC地址）非常容易导致网络意外损坏。
- 你的网络设备需要能够处理“混杂模式”，其中一个物理接口可以分配多个MAC地址。
- 如果你的应用程序可以使用桥接器（在单个Docker主机上）或覆盖层（跨多个Docker主机进行通信）工作，那么这些解决方案长期来看可能会更好。

## 创建一个macvlan网络

当创建Macvlan网络时，它可以处于网桥模式或802.1q主干网桥模式。

- 在网桥模式下，Macvlan流传输通过主机上的物理设备。
- 在802.1q中继网桥模式下，流量传输通过Docker在运行中创建的802.1q子接口。这使你可以更细粒度地控制路由和过滤。

### 桥接模式

---

要创建与给定物理网络接口桥接的Macvlan网络，请使用`docker network create` `--driver macvlan`命令。你还需要指定`parent`，这是流量在Docker主机上实际通过的接口。

```sh
$ docker network create -d macvlan \
  --subnet=172.16.86.0/24 \
  --gateway=172.16.86.1  \
  -o parent=eth0 pub_net
```

如果需要**排除**在Macvlan网络中使用的IP地址，例如当某个**给定的IP地址已被占用**时，请使用`--aux-addresses`：

```sh
$ docker network create -d macvlan  \
  --subnet=192.168.32.0/24  \
  --ip-range=192.168.32.128/25 \
  --gateway=192.168.32.254  \
  --aux-address="my-router=192.168.32.129" \
  -o parent=eth0 macnet32
```

### 802.1q中继桥模式

---

如果指定了`parent`包含点的接口名称，例如 Docker会将其解释为子接口`eth0`，并自动创建子接口 `eth0.50`。

```sh
$ docker network  create  -d macvlan \
    --subnet=192.168.50.0/24 \
    --gateway=192.168.50.1 \
    -o parent=eth0.50 macvlan50
```

### 使用ipvlan而不是macvlan

---

在上面的例子中，你仍然使用L3桥。你可以改为使用`ipvlan` ，并获得L2桥。指定`-o ipvlan_mode=l2`。

```shell
$ docker network create -d ipvlan \
    --subnet=192.168.210.0/24 \
    --subnet=192.168.212.0/24 \
    --gateway=192.168.210.254  \
    --gateway=192.168.212.254  \
     -o ipvlan_mode=l2 ipvlan210
```

## 使用IPv6

如果你已将[Docker守护程序配置为允许IPv6](https://docs.docker.com/config/daemon/ipv6/)，则可以使用`IPv4/IPv6` Macvlan网络。

```sh
$ docker network  create  -d macvlan \
    --subnet=192.168.216.0/24 --subnet=192.168.218.0/24 \
    --gateway=192.168.216.1  --gateway=192.168.218.1 \
    --subnet=2001:db8:abc8::/64 --gateway=2001:db8:abc8::10 \
     -o parent=eth0.218 \
     -o macvlan_mode=bridge macvlan216
```

## 实例演示

下面将连接`macvlan`网络的独立容器。在这种类型的网络中，Docker主机在其IP地址处接受多个MAC地址的请求，并将这些请求路由到适当的容器。

本实例目标是建立一个桥接`macvlan`网络并附加一个容器，然后建立一个802.1q干线`macvlan`网络并附上一个容器。

### Bridge 桥接网络

在简单网桥中，你的流量传输经过`eth0`Docker并使用其MAC地址将流量**路由**到你的容器。要将网络中的设备联网，你的容器看起来就是物理连接到网络上的。

1. 创建一个名为`my-macvlan-net`的`macvlan`网络。修改`subnet`，`gateway`和`parent`值。

   ```sh
   $ docker network create -d macvlan \
     --subnet=172.16.86.0/24 \
     --gateway=172.16.86.1 \
     -o parent=eth0 \
     my-macvlan-net
   ```

   你可以使用`docker network ls`和`docker network inspect pub_net` 命令来验证网络是否存在，并且是否是`macvlan`类型的网络。

2. 启动一个`alpine`容器并将其连接到`my-macvlan-net`网络。，`-dit`选项在后台启动容器，`--rm`选项意味着当它停止时该容器即被删除。

   ```shell
   $ docker run --rm -itd \
     --network my-macvlan-net \
     --name my-macvlan-alpine \
     alpine:latest \
     ash
   ```

3. 检查`my-macvlan-alpine`容器并注意`Networks`下面的`MacAddress`：

   ```shell
   $ docker container inspect my-macvlan-alpine
   "Networks": {
                   "my-macvlan-net": {
                       "IPAMConfig": null,
                       "Links": null,
                       "Aliases": [
                           "9452da0a5b60"
                       ],
                       "NetworkID": "37da5c24f76679918815a78c5dec126aef8cef1cf7611ff17af97b81ec64fe93",
                       "EndpointID": "65ae0afa6ef35c2bd9e9ea32367e2a4181b5f4142bc8546450fdce6a1573caf7",
                       "Gateway": "172.16.86.1",
                       "IPAddress": "172.16.86.2",
                       "IPPrefixLen": 24,
                       "IPv6Gateway": "",
                       "GlobalIPv6Address": "",
                       "GlobalIPv6PrefixLen": 0,
                       "MacAddress": "02:42:ac:10:56:02",
                       "DriverOpts": null
                   }
               }
   ```


4. 通过运行`docker exec`命令来了解容器查看到自己的网络接口。

   ```sh
   $ docker exec my-macvlan-alpine ip addr show eth0
   64: eth0@if3: <BROADCAST,MULTICAST,UP,LOWER_UP,M-DOWN> mtu 1500 qdisc noqueue state UP
       link/ether 02:42:ac:10:56:02 brd ff:ff:ff:ff:ff:ff
       inet 172.16.86.2/24 brd 172.16.86.255 scope global eth0
          valid_lft forever preferred_lft forever

   $ docker exec my-macvlan-alpine ip route
   default via 172.16.86.1 dev eth0
   172.16.86.0/24 dev eth0 scope link  src 172.16.86.2
   ```

5. 停止容器（由于`--rm`选项Docker自动将其删除），并删除网络。

   ```sh
   $ docker container stop my-macvlan-alpine
   $ docker network rm my-macvlan-net
   ```


### 802.1q中继桥接网络

---

本示例中数据流量通过`eth0`（调用`eth0.10`）的子接口传输，并且Docker使用其MAC地址将流量路由到你的容器。要将网络中的设备联网，你的容器看起来就是物理连接到网络上的。

1. 创建一个名为`my-8021q-macvlan-net`的`macvlan`网络，修改 `subnet`，`gateway`和`parent`值。

   ```shell
   $ docker network create -d macvlan \
     --subnet=172.16.86.0/24 \
     --gateway=172.16.86.1 \
     -o parent=eth0.10 \
     my-8021q-macvlan-net
   ```

   可以使用`docker network ls`和`docker network inspect my-8021q-macvlan-net` 命令来验证网络是否存在，是`macvlan`网络还是父级`eth0.10`。可以在Docker主机上使用`ip addr show`以验证接口`eth0.10`是否存在并具有单独的IP地址

2. 启动一个`alpine`容器并将其连接到`my-8021q-macvlan-net` 网络。`-dit`选项在后台启动容器，`--rm`选项意味着当它停止容器就被删除。

   ```shell
   $ docker run --rm -itd \
     --network my-8021q-macvlan-net \
     --name my-second-macvlan-alpine \
     alpine:latest \
     ash
   ```

3. 检查`my-second-macvlan-alpine`容器并注意`Networks`的`MacAddress` 值：

   ```shell
   $ docker container inspect my-second-macvlan-alpine

   "Networks": {
                   "my-8021q-macvlan-net": {
                       "IPAMConfig": null,
                       "Links": null,
                       "Aliases": [
                           "a539bcb79a00"
                       ],
                       "NetworkID": "d7de9db87d8651454107b2f0ffdc1ab8b51ddafc46dbaf70be4ba83256df98ac",
                       "EndpointID": "3dbfa9531c0428f185e497bc7192e77d6017de43862378f5bce3c5bb4386c7ba",
                       "Gateway": "172.16.86.1",
                       "IPAddress": "172.16.86.2",
                       "IPPrefixLen": 24,
                       "IPv6Gateway": "",
                       "GlobalIPv6Address": "",
                       "GlobalIPv6PrefixLen": 0,
                       "MacAddress": "02:42:ac:10:56:02",
                       "DriverOpts": null
                   }
               }
   ```

4. 通过运行一些`docker exec`命令来了解容器的网络接口。

   ```shell
   $ docker exec my-second-macvlan-alpine ip addr show eth0
   66: eth0@if65: <BROADCAST,MULTICAST,UP,LOWER_UP,M-DOWN> mtu 1500 qdisc noqueue state UP
       link/ether 02:42:ac:10:56:02 brd ff:ff:ff:ff:ff:ff
       inet 172.16.86.2/24 brd 172.16.86.255 scope global eth0
          valid_lft forever preferred_lft forever
   ```

   ```shell
   $ docker exec my-second-macvlan-alpine ip route
   default via 172.16.86.1 dev eth0
   172.16.86.0/24 dev eth0 scope link  src 172.16.86.2
   ```

5. 停止容器（由于`--rm`选项，Docker会将容器删除），并删除网络。

   ```shell
   $ docker container stop my-second-macvlan-alpine

   $ docker network rm my-8021q-macvlan-net
   ```

# 为容器禁用网络



如果要完全禁用容器上的网络，则可以在启动容器时使用`--network none`选项。在容器内，仅创建回送设备。

1. 创建容器。

   ```sh
   $ docker run --rm -dit \
     --network none \
     --name no-net-alpine \
     alpine:latest \
     ash
   ```

2. 通过在容器内执行一些常用的网络命令来检查容器的网络。发现没有创建`eth0`。

   ```sh
   $ docker exec no-net-alpine ip link show
   1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN qlen 1
       link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
   ```

   ```sh
   $ docker exec no-net-alpine ip route
   ```

   第二个命令返回空白，因为没有路由。

3. 停止容器。它被自动删除，因为使用了`--rm`选项创建的。

   ```sh
   $ docker container stop no-net-alpine
   ```

# 可选配置

## 启用IPv6

在Docker容器或集群服务中使用IPv6之前，需要在Docker守护程序中启用IPv6支持。之后才可以选择将IPv4或IPv6（或两者）用于任何容器、服务或网络。

> **注意**：只有在Linux主机上运行的Docker守护程序支持IPv6网络。

1. 编辑`/etc/docker/daemon.json`并设置`ipv6`值为`true`。

   ```
   {
     "ipv6": true
   }
   ```

   保存文件。

2. 重新加载Docker配置文件。

   ```
   $ systemctl reload docker
   ```

现在可以使用`--ipv6`选项创建网络，并使用`--ip6`选项分配容器IPv6地址。

## iptables

在Linux上，Docker操纵`iptables`规则来提供网络隔离。

### 在Docker的规则之前添加iptables策略

所有Docker的`iptables`规则都被添加到`DOCKER`链中。不要手动操作此配置。如果你需要添加在Docker规则之前加载的规则，请将其添加到`DOCKER-USER`链配置中。这些规则在Docker自动创建其他规则之前加载。

#### 限制连接到Docker守护进程

默认情况下，所有外部源IP都被允许连接到Docker守护进程。要**仅允许特定的IP或网络访问容器**，请在DOCKER过滤器链的顶部插入否定规则。例如，以下规则限制外部访问除`192.168.1.1`之外的所有IP地址：

```sh
$ iptables -I DOCKER-USER -i ext_if ! -s 192.168.1.1 -j DROP
```

你可以改为允许来自子网的连接。以下规则仅允许从子网`192.168.1.0/24`进行访问：

```sh
$ iptables -I DOCKER-USER -i ext_if ! -s 192.168.1.0/24 -j DROP
```

最后，你可以使用`--src-range`指定一个可接受的IP地址范围 （请记住，在使用`--src-range`或`--dst-range`时还要添加`-m iprange`）：

```sh
$ iptables -I DOCKER-USER -m iprange -i ext_if ! --src-range 192.168.1.1-192.168.1.3 -j DROP
```

你可以使用`-s`或`--src-range`与`-d`或`--dst-range`结合起来控制源和目标。例如，如果Docker守护进程同时监听`192.168.1.99`和`10.1.2.3`，则可以制定特定于`10.1.2.3`的规则并保持`192.168.1.99`处于打开状态。

### 防止Docker操纵iptables

为了防止Docker操纵这些`iptables`策略，请在 `/etc/docker/daemon.json`文件中将`iptables`值设置 为`false`。这样这些`iptables`策略需要手工管理。

## 容器网络

容器使用网络无论是`bridge`、`overlay`、`macvlan`，或自定义网络插件，从容器内都是透明公开的。从容器的角度来看它有一个带IP地址、网关、路由、DNS服务和其他网络细节的网络接口（假设容器不使用网络驱动程序`none`）。

### 发布的端口

默认情况下，创建容器时它不会将任何端口发布到外界。**要使端口可用于Docker之外的服务或未连接到容器网络的Docker容器**，请使用 `--publish`或 `-p`选项。这会创建一个`iptables`规则，将容器端口映射到Docker主机上的端口。

| 选项                            | 描述                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| `-p 8080:80`                    | 将容器中的TCP端口80映射到Docker主机上的端口8080。            |
| `-p 8080:80/udp`                | 将容器中的UDP端口80映射到Docker主机上的端口8080。            |
| `-p 8080:80/tcp -p 8080:80/udp` | 将容器中的TCP端口80映射到Docker主机上的TCP端口8080，并将容器中的UDP端口80映射到Docker主机上的UDP端口8080。 |

### IP地址和主机名

默认情况下，容器会为每个连接到Docker网络分配一个IP地址。IP地址分配是从网络池中获取的，因此Docker守护程序有效地充当每个容器的DHCP服务器。每个网络也有一个默认的子网掩码和网关。

当容器启动时，它使用 `--network`只能连接到单个网络。但是，你可以使用运行的容器连接到多个网络`docker network connect`。使用`--network`选项启动容器时 ，可以使用`--ip`或`--ip6`选项指定分配给网络上容器的IP地址。

当使用现有容器连接到不同的网络时 ，可以使用`docker network connect`命令上的`--ip`或`--ip6`选项在附加网络上指定容器的IP地址。

以同样的方式，容器的主机名默认为Docker中的容器名称。你可以使用`--hostname`覆盖主机名。使用`docker network connect`连接到现有网络时，可以使用该`--alias` 选项为网络上的容器指定附加网络别名。

### DNS服务

默认情况下，容器会继承Docker守护程序的DNS设置，包括`/etc/hosts`和`/etc/resolv.conf`。你可以基于每个容器覆盖这些设置。

| 选项           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| `--dns`        | DNS服务器的IP地址。要指定多个DNS服务器，请使用多个`--dns`标志。如果容器无法访问您指定的任何IP地址，则会添加Google的公共DNS服务器`8.8.8.8`，以便您的容器可以解析互联网域名。 |
| `--dns-search` | 一个DNS搜索域，用于搜索非完全限定的主机名。要指定多个DNS搜索前缀，请使用多个`--dns-search`标志。 |
| `--dns-opt`    | 代表DNS选项及其值的键值对。有关`resolv.conf`有效选项，请参阅操作系统的文档。 |
| `--hostname`   | 容器为自己使用的主机名。如果未指定，则默认为容器的名称。     |

### 代理

如果你的容器需要使用代理服务器，请参阅 [使用代理服务器](https://docs.docker.com/network/proxy/)。

## 使用代理服务

如果你的容器需要使用HTTP、HTTPS、FTP代理服务器，则可以采用不同的方式对其进行配置：

- 在Docker 17.07及更高版本中，你可以 [配置Docker客户端](https://docs.docker.com/network/proxy/#configure-the-docker-client)以自动将代理信息传递给容器。
- 在Docker 17.06及更低版本中，你必须 在容器中[设置适当的环境变量](https://docs.docker.com/network/proxy/#use-environment-variables)。你可以在构建镜像时（这会使镜像的可移植性降低）或创建或运行容器时执行此操作。

### 使用 Docker 客户端方式

1. 在Docker客户端上，创建或编辑`~/.docker/config.json`启动容器的用户的主目录中的文件。添加JSON（如下所示），用代理服务器的类型`httpsProxy`或`ftpProxy`必要时替换代理服务器的类型，并替换代理服务器的地址和端口。你可以同时配置多个代理服务器。

   通过将`noProxy`设置为一个或多个逗号分隔的IP地址或主机，你可以选择性地排除通过代理服务器的主机或范围。如本例所示，支持使用字符`*`作为通配符。

   ```json
   {
    "proxies":
    {
      "default":
      {
        "httpProxy": "http://127.0.0.1:3001",
        "noProxy": "*.test.example.com,.example2.com"
      }
    }
   }
   ```

2. 在创建或启动新容器时，环境变量会在容器中自动加载这些设置。

### 使用 Docker 环境变量方式

当创建镜像和在创建、运行容器时使用`--env`标记时，可以将一个或多个以下变量设置为适当的值。此方法使镜像的**可移植性降低**，因此如果你的Docker 17.07或更高版本，则应该[配置Docker客户端](https://docs.docker.com/network/proxy/#configure-the-docker-client) 。

| 变量          | Dockerfile示例                                    | `docker run` 例                                     |
| ------------- | ------------------------------------------------- | --------------------------------------------------- |
| `HTTP_PROXY`  | `ENV HTTP_PROXY "http://127.0.0.1:3001"`          | `--env HTTP_PROXY "http://127.0.0.1:3001"`          |
| `HTTPS_PROXY` | `ENV HTTPS_PROXY "https://127.0.0.1:3001"`        | `--env HTTPS_PROXY "https://127.0.0.1:3001"`        |
| `FTP_PROXY`   | `ENV FTP_PROXY "ftp://127.0.0.1:3001"`            | `--env FTP_PROXY "ftp://127.0.0.1:3001"`            |
| `NO_PROXY`    | `ENV NO_PROXY "*.test.example.com,.example2.com"` | `--env NO_PROXY "*.test.example.com,.example2.com"` |

# 传统网络

## 传统容器连接

在安装Docker时自动创建的Docker默认`bridge`网络中的旧容器链接。可以使用Docker链接功能来允许容器相互发现并安全地将有关一个容器的信息传输到另一个容器。

> **警告**：`--link`选项是Docker的遗留功能。它最终可能会被删除。除非你绝对需要继续使用它，否则我们建议你使用用户定义的网络来促进两个容器之间的通信而不是使用 `--link`。用户定义的网络不支持的一个功能是在容器之间共享环境变量。但是，你可以使用其他机制（如卷）以受控制的方式在容器之间共享环境变量。
>
> 请参阅[用户定义的网桥和默认网桥之间的差异](https://docs.docker.com/network/bridge/##differences-between-user-defined-bridges-and-the-default-bridge) 以获取一些使用替代方法`--link`。

### 使用网络端口映射容器连接

---

#### 自动端口映射

假设你使用此命令来运行简单的Python Flask应用程序：

```sh
$ docker run -d -P training/webapp python app.py
```

创建容器时`-P`选项用于**自动将其内部的任何网络端口**映射到Docker主机上**临时端口范围**内的随机端口。接下来运行`docker ps`时，可以看到容器中的端口5000已绑定到主机上的端口32768。

```sh
$ docker ps
CONTAINER ID        IMAGE               COMMAND             CREATED              STATUS              PORTS                     NAMES
aa4797af9359        training/webapp     "python app.py"     About a minute ago   Up About a minute   0.0.0.0:32768->5000/tcp   dazzling_mclean
```

#### 固定端口映射

如何使用`-p`选项将容器的端口绑定到特定的端口，这里主机的端口80映射到容器的端口5000：

```sh
$ docker run -d -p 80:5000 training/webapp python app.py
```

这不是一个好主意，因为它将你**限制在特定端口**上的一个容器上。

#### 随机范围映射

可以指定一系列主机端口来绑定与默认**临时端口范围**不同的容器端口：

```sh
$ docker run -d -p 8000-9000:5000 training/webapp python app.py
```

容器中的端口5000绑定到主机上8000到9000之间的随机可用端口。

#### 固定IP端口映射

还有其他一些方法可以配置`-p`选项。默认情况下，`-p`选项将指定的端口绑定到主机上的所有接口。但是你也可以指定一个绑定到一个特定的接口，例如只对`localhost`。

```sh
$ docker run -d -p 127.0.0.1:80:5000 training/webapp python app.py
```

这会将容器内的端口5000绑定到主机`localhost`或`127.0.0.1`接口上的端口80 。

#### 动态端口映射

将容器的端口5000绑定到动态端口，但仅限于`localhost`端口可用：

```sh
$ docker run -d -p 127.0.0.1::5000 training/webapp python app.py
```

#### 端口协议映射

还可以通过添加尾随`/udp`或绑定来绑定UDP和SCTP（通常由诸如SIGTRAN，Diameter和S1AP / X2AP等电信协议使用）端口`/sctp`。例如：

```sh
$ docker run -d -p 127.0.0.1:80:5000/udp training/webapp python app.py
```

#### 查看映射端口

当前端口绑定的有用快捷方式，对于显示特定的端口配置`docker port`也很有用。例如，如果已经将容器端口绑定到 `localhost`主机上，那么`docker port`输出反映了这一点。

```sh
$ docker port naughty_turing
5000/tcp -> 0.0.0.0:80

$ docker port naughty_turing 5000
0.0.0.0:80
```

> **注意**：该`-p`选项可以多次使用来配置多个端口。

### 使用链接系统连接容器

---

网络端口映射不是Docker容器可以互相连接的唯一方式。Docker也有一个链接系统，允许你**将多个容器链接在一起**，并将连接信息从一个连接到另一个。当容器被链接时，关于**源容器的信息可以被发送到收件人容器**。这使得收件人可以查看描述源容器方面的特定数据。

为了建立链接，Docker依赖于容器的名字。已经看到创建的每个容器都有一个自动创建的名称。你也可以自己命名容器，这个命名提供了两个有用的功能：

1. 容器命名可以很方便地使用特定的功能，这样可以更容易记住它们，例如命名包含Web应用程序的容器`web`。
2. 它为Docker提供了一个引用点，允许它引用其他容器，例如，可以指定将容器`web`链接到容器`db`。

你可以使用`--name`选项为容器命名，例如：

```sh
$ docker run -d -P --name python_web training/webapp python app.py
```

这将启动一个新的容器并使用`--name`选项来命名该容器`python_web`。你可以使用该`docker ps`命令查看容器的名称 。

```shell
$ docker ps
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS                     NAMES
b39604ac20ee        training/webapp     "python app.py"     1 second ago        Up 3 seconds        0.0.0.0:32769->5000/tcp   python_web
```

也可以使用`docker inspect`返回容器的名称。

> **注意**：容器名称必须是唯一的。这意味着你只能调用一个`python_web`容器。如果要重新使用容器名称，则必须先删除旧容器（`docker container rm`），然后才能创建具有相同名称的新容器。作为替代方案，你可以`--rm`在`docker run`命令中使用选项。这会在停止后立即删除容器。

### 使用链接系统进行容器通信

---

链接允许容器**相互发现**并安全地将有关一个容器的信息传输到另一个容器。当你设置链接时，你会在源容器和收件人容器之间**创建管道**。接收者可以访问关于源的选择数据。要创建链接，请使用`--link` 选项。首先，创建一个包含数据库的新容器。

```sh
# -d 分离模式，后台运行
$ docker run -d --name db training/postgres
```

这将从`training/postgres`镜像创建一个名为`db`的新容器，其中包含`PostgreSQL`数据库。

现在，需要删除`web`先前创建的容器，以便将其替换为链接的容器：

```sh
# -f 强制删除
$ docker container rm -f python_web
```

现在，创建一个新`python_web`容器并将其与`db`容器链接起来。

```sh
# --link 链接容器
$ docker run -d -P --name python_web --link db:postgres_db training/webapp python app.py
```

这将新`python_web`容器与先前创建的容器`db`链接起来。该`--link`参数的形式是：

```sh
--link <name or id>:alias
```

其中`name`是我们链接到的容器的名称，而`alias`是链接名称的别名。`--link`选项也采用以下形式：

```sh
--link <name or id>
```

在这种情况下，别名与名称相同。也可以把前面的例子写成：

```sh
# 别名和容器相同
$ docker run -d -P --name python_web --link db training/webapp python app.py
```

检查你的链接容器`docker inspect`：

```sh
$ docker inspect -f "{{ .HostConfig.Links }}" python_web
[/db:/python_web/db]
```

可以看到`python_web`容器现在已链接到`db`容器 `python_web/db`。它允许它访问有关`db`容器的信息。

那么连接容器究竟做了什么？已经了解到，链接允许源容器向收件人容器提供有关其自身的信息。在我们的例子中，收件人`python_web`可以访问关于`db`源的信息。因此，Docker在容器之间创建一个安全隧道，不需要在容器外部公开任何端口。当我们启动 `db`容器时，我们没有使用`-P`或 `-p`选项。这是链接的一大好处：**我们不需要将源容器（这里是PostgreSQL数据库）公开到网络中**。

Docker通过两种方式将源容器的连接信息公开给收件人容器：

- 环境变量
- 更新`/etc/hosts`文件。

#### 环境变量

---

当链接容器时，Docker会创建几个环境变量。Docker根据`--link`参数**自动在目标容器中创建环境变量**。它还**公开源容器中来自Docker的所有环境变量**。这些包括以下变量：

- 源容器的`Dockerfile`中的`ENV`命令
- 源容器启动时，`docker run`命令中的`-e`，`--env`和`--env-file`选项

这些环境变量允许在目标容器内对与源容器相关的信息进行编程式发现。

> **警告**：重要的是：源自容器内的Docker的**所有**环境变量都可供链接到它的**任何**容器使用。如果敏感数据存储在其中，这可能会产生严重的安全隐患。

Docker为`--link`参数中列出的每个目标容器设置一个`<alias>_NAME`环境变量。例如，如果一个名为`web`的新容器通过`--link db：webdb`链接到一个名为`db`的数据库容器，那么Docker将在`Web`容器中创建一个`WEBDB_NAME=/web/webdb`变量。

Docker还为源容器公开的每个端口定义一组环境变量。每个变量都有一个唯一的前缀形式：`<name>_PORT_<port>_<protocol>`  示例：`webdb_PORT_80_tcp`

这个前缀中的组件是：

- `<name>`：`--link`参数中指定的别名（例如`webdb`）
- `<port>`：暴露的端口
- `<protocol>`：是TCP或UDP协议方式

Docker使用这个前缀格式来定义三个不同的环境变量：

- 例如，`prefix_ADDR`变量包含来自URL的IP地址`WEBDB_PORT_5432_TCP_ADDR=172.17.0.82`。
- 例如，`prefix_PORT`变量仅包含来自URL的端口号`WEBDB_PORT_5432_TCP_PORT=5432`。
- 例如，`prefix_PROTO`变量仅包含来自URL的协议`WEBDB_PORT_5432_TCP_PROTO=tcp`。

如果容器**暴露多个端口**，则为**每个端口定义一个环境变量集**。这意味着，如果一个容器暴露了4个端口，Docker创建了12个环境变量，每个端口3个。

另外，Docker创建一个名为的环境变量`<alias>_PORT`。该变量包含源容器的第一个暴露端口的URL。这个“第一”端口被定义为具有**最小号码**的暴露端口。例如，考虑这个`WEBDB_PORT=tcp://172.17.0.82:5432`变量。如果该端口同时用于tcp和udp，则指定tcp。

最后，Docker还将源容器中的**每个Docker源环境变量公开为目标中的环境变量**。对于每个变量，Docker 在目标容器中创建一个变量`<alias>_ENV_<name>`。变量的值设置为启动源容器时使用的值。

回到我们的数据库示例，你可以运行`env` 命令来列出指定容器的环境变量。

```sh
$ docker run --rm --name web2 --link db:postgres_db training/webapp env
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
HOSTNAME=ecf4255e74b9
POSTGRES_DB_PORT=tcp://172.17.0.6:5432
POSTGRES_DB_PORT_5432_TCP=tcp://172.17.0.6:5432
POSTGRES_DB_PORT_5432_TCP_ADDR=172.17.0.6
POSTGRES_DB_PORT_5432_TCP_PORT=5432
POSTGRES_DB_PORT_5432_TCP_PROTO=tcp
POSTGRES_DB_NAME=/web2/postgres_db
POSTGRES_DB_ENV_PG_VERSION=9.3
HOME=/root
```

你可以看到Docker创建了一系列包含`POSTGRES_DB`有关源容器的有用信息的环境变量。每个变量的前缀 `POSTGRES_DB_`都是从上面指定的`alias`填充的。如果`alias` 是`db1`，变量将以前缀`DB1_`。你可以**使用这些环境变量来配置应用程序**以连接到`db`容器上的数据库。连接是安全和私密的， 只有链接的`web`容器才能与`db`容器通信。

#### 有关Docker环境变量的重要说明

与[`/etc/hosts`文件](https://docs.docker.com/network/links/#updating-the-etchosts-file)中的主机host映射不同，**如果源容器重新启动，则存储在环境变量中的IP地址不会自动更新**。我们建议使用主机 `/etc/hosts`来解析链接容器的IP地址。

这些环境变量仅为容器中的第一个进程设置。一些守护进程，比如`sshd`在产生shell连接时删除清理它们。

#### 更新`/etc/hosts`文件

除了环境变量外，Docker还将源容器的主机host映射添加到`/etc/hosts`文件中。以下是`web` 容器的条目：

```sh
$ winpty docker run -t -i --rm --link db:webdb training/webapp bash

root@3e039a0513be:/opt/webapp# cat /etc/hosts
....
172.17.0.7  aed84ee21bde
172.17.0.5  webdb 6e5cdeb2d300 db
```

你可以看到两个相关的主机host。第一个是`web` 使用`Container ID`作为主机名的容器条目。第二项使用链接别名来引用`db`容器的IP地址。除了你提供的别名之外，链接容器的**名称**（如果提供给`--link`参数的别名是唯一的）以及链接容器的**主机名**也会添加到`/etc/hosts`链接容器的IP地址。可以通过以下任一条目ping该主机：

```shell
root@3e039a0513be:/opt/webapp# ping -c 2 webdb
PING webdb (172.17.0.6) 56(84) bytes of data.
64 bytes from webdb (172.17.0.6): icmp_seq=1 ttl=64 time=0.099 ms
64 bytes from webdb (172.17.0.6): icmp_seq=2 ttl=64 time=0.110 ms

--- webdb ping statistics ---
7 packets transmitted, 7 received, 0% packet loss, time 6232ms
rtt min/avg/max/mdev = 0.099/0.127/0.140/0.019 ms

root@3e039a0513be:/opt/webapp# ping -c 2 db
PING webdb (172.17.0.6) 56(84) bytes of data.
64 bytes from webdb (172.17.0.6): icmp_seq=1 ttl=64 time=0.133 ms
64 bytes from webdb (172.17.0.6): icmp_seq=2 ttl=64 time=0.067 ms

--- webdb ping statistics ---
2 packets transmitted, 2 received, 0% packet loss, time 1076ms
rtt min/avg/max/mdev = 0.067/0.100/0.133/0.033 ms
```

没有安装**ping** 使用命令安装 `apt-get install -yqq inetutils-ping`

在这里，用`ping`命令使用主机host来ping db容器，该host解析为`172.17.0.6`。你可以使用此主机host来配置应用程序以使用你的`db`容器。

> **注意**：可以将多个收件人容器链接到单个来源容器。例如，可以将多个（不同名称）Web容器附加到 `db`容器。

如果重新启动源容器，`/etc/hosts`链接容器上的文件将**自动更新**为源容器的新IP地址，从而允许进行链接通信。

```sh
$ docker restart db

$ winpty docker run -t -i --rm --link db:webdb training/webapp bash
root@ac40ee7d321f:/opt/webapp# cat /etc/hosts
127.0.0.1       localhost
::1     localhost ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters

# db的 ip被刷新为容器的ip
172.17.0.3      webdb 78b4131a38db db
172.17.0.4      ac40ee7d321f

# 跟容器的ip对应
$ docker container inspect db --format={{.NetworkSettings.Networks.bridge.IPAddress}}
172.17.0.3
```

## 多主机网络和独立集群

### 独立集群

如果你使用Docker的独立集群，而不是集群模式。独立集群（有时称为`Swarm Classic` 传统经典集群）依靠外部键值存储来存储网络信息。Docker集群模式在集群管理器中的`Raft`日志中存储网络信息。如果你使用集群模式，请参阅 [集群模式网络，](https://docs.docker.com/engine/swarm/networking/)而不是本文。

通用客户端控制面板的用户**可以**使用外部键值存储，但UCP可以为你进行管理，而且你无需手动干预。如果遇到键值存储问题，请参阅 [解决etcd键值存储问题](https://docs.docker.com/datacenter/ucp/2.2/guides/admin/monitor-and-troubleshoot/troubleshoot-configurations/#troubleshoot-the-etcd-key-value-store)

如果你正在使用独立集群而不使用UCP，则本文可能对你有用。本文使用一个示例来解释使用独立集群和`overlay`网络驱动程序，创建多主机网络的基础知识。与`bridge`网络不同，覆盖网络需要一些预先存在的条件才能创建一个：

### 使用外部键值存储覆盖网络

要将Docker与外部键值存储一起使用，你需要以下内容：

- 访问键值存储。Docker支持`Consul`，`Etcd`和`ZooKeeper`（分布式存储）键值存储。这个例子使用Consul。
- 连接到键值存储的主机集群。
- Docker在集群中的每台主机上运行。
- 集群中的主机必须具有唯一主机名，因为键值存储使用主机名来标识集群成员。

Docker Machine和Docker Swarm不是强制性的，可以通过键值存储体验Docker多主机网络。但是，这个例子使用它们来说明它们如何被整合。你可以使用Machine使用独立集群创建键值存储服务器和主机集群。

> **注意**：这些示例与在集群模式下运行的Docker无关，并且不适用于这种配置。

#### 设置一个键值存储

---

`overlay`覆盖网络需要键值存储。键值存储保存有关网络状态的信息，其中包括自动发现、网络、端点、IP地址等。Docker支持`Consul`、`Etcd`和`ZooKeeper`键值存储。这个例子使用Consul。

1. 登录到安装了Docker和Docker Machine的系统中。

   ```sh
   $ cd E:\Docker Toolbox
   $ sh start.sh
   ```

2. 配置名为的VirtualBox机器`mh-keystore`。

   ```sh
   $ docker-machine create -d virtualbox mh-keystore
   ```

   当创建新机器时，会将Docker添加到主机。这意味着不是手动安装Consul，而是使用[Docker Hub](https://hub.docker.com/_/consul/)的[consul镜像](https://hub.docker.com/_/consul/)创建一个实例。下一步中执行此操作。

3. 将本地环境设置为`mh-keystore`机器，让shell命令默认发送到本机器。

   ```sh
   $  eval "$(docker-machine env mh-keystore)"
   ```

4. 启动在`mh-keystore`Docker机器上运行的容器`consul`。

   ```sh
   $  docker run -d \
     --name consul \
     -p "8500:8500" \
     -h "consul" \
     consul agent -server -bootstrap -client "0.0.0.0"
   ```

   服务器被调用`consul`并正在侦听端口`8500`。

5. 运行`docker ps`命令以查看`consul`容器。

   ```sh
   $ docker ps
   ```

#### 创建一个群集

---

在这一步中，将使用`docker-machine`网络配置主机。你实际上并没有创建网络。你在`VirtualBox`中创建了几个Docker机器。其中一台机器充当`swarm manager`，你首先创建该机器。在创建每台主机时，你需要在`overlay`网络驱动程序所需的机器选项上传递Docker守护进程。

> **注意**：这会创建一个独立集群，而不是在集群模式下使用Docker。这些示例与在集群模式下运行的Docker无关，并且不适用于这种配置。

1. 创建一个`swarm manager`。

   ```sh
   $ docker-machine create \
   -d virtualbox \
   --swarm --swarm-master \
   --swarm-discovery="consul://$(docker-machine ip mh-keystore):8500" \
   --engine-opt="cluster-store=consul://$(docker-machine ip mh-keystore):8500" \
   --engine-opt="cluster-advertise=eth1:2376" \
   mhs-demo0
   ```

   在创建时，你需要为Docker守护程序提供`--cluster-store` 选项。该选项告诉引擎`overlay`网络的键值存储位置。`$(docker-machine ip mh-keystore)` bash 解析为你在“步骤1”中创建的Consul服务器的IP地址。该`--cluster-advertise`选项通知网络上的机器。

2. 创建另一个主机并将其添加到群中。

   ```sh
   $ docker-machine create \
     -d virtualbox \
     --swarm \
     --swarm-discovery="consul://$(docker-machine ip mh-keystore):8500" \
     --engine-opt="cluster-store=consul://$(docker-machine ip mh-keystore):8500" \
     --engine-opt="cluster-advertise=eth1:2376" \
     mhs-demo1
   ```

3. 列出你的Docker机器以确认它们全部正常运行。

   ```sh
   $ docker-machine ls

   NAME         ACTIVE   DRIVER       STATE     URL                         SWARM
   default      -        virtualbox   Running   tcp://192.168.99.100:2376
   mh-keystore  *        virtualbox   Running   tcp://192.168.99.103:2376
   mhs-demo0    -        virtualbox   Running   tcp://192.168.99.104:2376   mhs-demo0 (master)
   mhs-demo1    -        virtualbox   Running   tcp://192.168.99.105:2376   mhs-demo0
   ```

此时，你的网络上正在运行一组主机。你已准备好使用这些主机为容器创建多主机网络。

#### 创建覆盖网络

---

1. 将docker环境设置为`swarm manager`。

   ```sh
   $ eval $(docker-machine env --swarm mhs-demo0)
   ```

   使用`--swarm`选项`docker-machine`限制`docker` 命令单独输出集群信息。

2. 使用该`docker info`命令查看群。

   ```sh
   $ docker info
   Containers: 3
    Running: 3
    Paused: 0
    Stopped: 0
   Images: 2
   Server Version: swarm/1.2.8
   Role: primary
   Strategy: spread
   Filters: health, port, containerslots, dependency, affinity, constraint, whitelist
   Nodes: 2
    mhs-demo0: 192.168.99.104:2376
     └ ID: HHV7:NLU7:Z4T7:NJSG:BZGQ:JSQC:RB24:JZFF:LNIO:OCME:Z6WK:L562|192.168.99.104:2376
     └ Status: Healthy
     └ Containers: 2 (2 Running, 0 Paused, 0 Stopped)
     └ Reserved CPUs: 0 / 1
     └ Reserved Memory: 0 B / 1.021 GiB
     └ Labels: kernelversion=4.9.93-boot2docker, operatingsystem=Boot2Docker 18.03.1-ce (TCL 8.2.1); HEAD : cb77972 - Thu Apr 26 16:40:36 UTC 2018, ostype=linux, provider=virtualbox, storagedriver=aufs
     └ UpdatedAt: 2018-05-03T02:18:33Z
     └ ServerVersion: 18.03.1-ce
    mhs-demo1: 192.168.99.105:2376
     └ ID: DDSY:75LL:AGNE:5VVA:EO3X:JB4X:HIDK:YWVX:WIME:5U4R:WWCZ:277J|192.168.99.105:2376
     └ Status: Healthy
     └ Containers: 1 (1 Running, 0 Paused, 0 Stopped)
     └ Reserved CPUs: 0 / 1
     └ Reserved Memory: 0 B / 1.021 GiB
     └ Labels: kernelversion=4.9.93-boot2docker, operatingsystem=Boot2Docker 18.03.1-ce (TCL 8.2.1); HEAD : cb77972 - Thu Apr 26 16:40:36 UTC 2018, ostype=linux, provider=virtualbox, storagedriver=aufs
     └ UpdatedAt: 2018-05-03T02:18:27Z
     └ ServerVersion: 18.03.1-ce
   Kernel Version: 4.9.93-boot2docker
   Operating System: linux
   Architecture: amd64
   CPUs: 2
   Total Memory: 2.042GiB
   Name: 854d81944ea5
   ```

   上面输出显示正在管理器上运行三个容器和两个镜像。

3. 创建`overlay`网络。

   ```sh
   $ docker network create --driver overlay --subnet=10.0.9.0/24 my-net
   ```

   只需要在集群中的单个主机上创建网络。因为你使用了`swarm manager`，可以很容易地在swarm中的任何主机上运行它。

   > **注意**：强烈建议在创建网络时使用`--subnet`选项。如果未指定`--subnet`，则Docker会自动选择并为网络分配一个子网，并且可能会与基础架构中未由Docker管理的另一个**子网重叠**。当容器连接到该网络时，这种重叠会导致连接问题或失败。

4. 检查网络是否存在

   ```sh
   $ docker network ls

   NETWORK ID          NAME                DRIVER
   412c2496d0eb        mhs-demo1/host      host
   dd51763e6dd2        mhs-demo0/bridge    bridge
   6b07d0be843f        my-net              overlay
   b4234109bd9b        mhs-demo0/none      null
   1aeead6dd890        mhs-demo0/host      host
   d0bb78cbe7bd        mhs-demo1/bridge    bridge
   1c0eb8f69ebb        mhs-demo1/none      null
   ```

   由于位于`swarm manager`环境中，因此可以看到所有swarm参与者的所有网络：每个Docker守护程序和单个覆盖网络上的默认网络。每个网络都有唯一的ID和名称。

5. 依次切换到每个群体代理并列出网络。

   ```sh
   $ eval $(docker-machine env mhs-demo0)
   $ docker network ls
   NETWORK ID          NAME                DRIVER
   6b07d0be843f        my-net              overlay
   dd51763e6dd2        bridge              bridge
   b4234109bd9b        none                null
   1aeead6dd890        host                host  

   $ eval $(docker-machine env mhs-demo1)
   $ docker network ls
   NETWORK ID          NAME                DRIVER
   d0bb78cbe7bd        bridge              bridge
   1c0eb8f69ebb        none                null
   412c2496d0eb        host                host
   6b07d0be843f        my-net              overlay
   ```

   两个节点都拥有`my-net`带有`6b07d0be843f`ID 的网络。现在有一个多主机容器网络正在运行！

   ​

#### 在网络上运行应用程序

---

网络创建完成后，可以在任何主机上启动容器，并自动将其作为网络的一部分。

1. 将环境设置为`swarm manager`。

   ```sh
   $ eval $(docker-machine env --swarm mhs-demo0)
   ```

2. 在`mhs-demo0`实例上启动一个`Nginx Web`服务器，使用刚才创建的网络`my-net`。`constraint`代表约束规则。

   ```sh
   $ docker run -itd \
     --name=web \
     --network=my-net \
     --env="constraint:node==mhs-demo0" \
     nginx:alpine
   ```

3. 在`mhs-demo1`实例上运行`busybox`实例并获取`Nginx web`服务器主页的内容。

   ```sh
   $ docker run -it --rm \
     --network=my-net \
     --env="constraint:node==mhs-demo1" \
     busybox wget -O- http://web
     
   Connecting to web (10.0.9.2:80)
   <!DOCTYPE html>
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
   -                    100% |*******************************|   612   0:00:00 ETA  
   ```

#### 检查外部连接

---

Docker的内置覆盖网络驱动程序可在同一网络中多个主机上的容器之间提供开箱即用的连接。另外，连接到多主机网络的容器会自动连接到`docker_gwbridge`网络。该网络允许容器在集群外部具有外部连接。

1. 将环境更改为`swarm agent`。

   ```sh
   $ eval $(docker-machine env mhs-demo1)
   ```

2. 通过列出网络来查看网络`docker_gwbridge`。

   ```sh
   $ docker network ls
   NETWORK ID          NAME                DRIVER
   6b07d0be843f        my-net              overlay
   dd51763e6dd2        bridge              bridge
   b4234109bd9b        none                null
   1aeead6dd890        host                host
   e1dbd5dff8be        docker_gwbridge     bridge
   ```

3. 重复swarm管理器上的步骤1和2。

   ```sh
   $ eval $(docker-machine env mhs-demo0)

   $ docker network ls
   NETWORK ID          NAME                DRIVER
   6b07d0be843f        my-net              overlay
   d0bb78cbe7bd        bridge              bridge
   1c0eb8f69ebb        none                null
   412c2496d0eb        host                host
   97102a22e8d2        docker_gwbridge     bridge
   ```

4. 检查Nginx容器的网络接口。

   ```sh
   $ docker container exec web ip addr
   1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN qlen 1
       link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
       inet 127.0.0.1/8 scope host lo
          valid_lft forever preferred_lft forever
   13: eth0@if14: <BROADCAST,MULTICAST,UP,LOWER_UP,M-DOWN> mtu 1450 qdisc noqueue state UP
       link/ether 02:42:0a:00:09:02 brd ff:ff:ff:ff:ff:ff
       inet 10.0.9.2/24 brd 10.0.9.255 scope global eth0
          valid_lft forever preferred_lft forever
   16: eth1@if17: <BROADCAST,MULTICAST,UP,LOWER_UP,M-DOWN> mtu 1500 qdisc noqueue state UP
       link/ether 02:42:ac:12:00:02 brd ff:ff:ff:ff:ff:ff
       inet 172.18.0.2/16 brd 172.18.255.255 scope global eth1
          valid_lft forever preferred_lft forever
   ```

该`eth0`接口表示连接到`my-net`覆盖网络的容器接口。`eth1`接口代表连接到容器的接口`docker_gwbridge`网络。