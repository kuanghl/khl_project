# docker 高级—程序配置

* [docker 高级—程序配置](#docker-%E9%AB%98%E7%BA%A7%E7%A8%8B%E5%BA%8F%E9%85%8D%E7%BD%AE)
* [配置对象](#%E9%85%8D%E7%BD%AE%E5%AF%B9%E8%B1%A1)
  * [自定义元数据](#%E8%87%AA%E5%AE%9A%E4%B9%89%E5%85%83%E6%95%B0%E6%8D%AE)
    * [标签键和值](#%E6%A0%87%E7%AD%BE%E9%94%AE%E5%92%8C%E5%80%BC)
      * [格式建议](#%E6%A0%BC%E5%BC%8F%E5%BB%BA%E8%AE%AE)
      * [价值准则](#%E4%BB%B7%E5%80%BC%E5%87%86%E5%88%99)
    * [管理对象上的标签](#%E7%AE%A1%E7%90%86%E5%AF%B9%E8%B1%A1%E4%B8%8A%E7%9A%84%E6%A0%87%E7%AD%BE)
  * [剪裁未使用的对象](#%E5%89%AA%E8%A3%81%E6%9C%AA%E4%BD%BF%E7%94%A8%E7%9A%84%E5%AF%B9%E8%B1%A1)
    * [剪裁镜像](#%E5%89%AA%E8%A3%81%E9%95%9C%E5%83%8F)
    * [剪裁容器](#%E5%89%AA%E8%A3%81%E5%AE%B9%E5%99%A8)
    * [剪裁卷](#%E5%89%AA%E8%A3%81%E5%8D%B7)
    * [剪裁网络](#%E5%89%AA%E8%A3%81%E7%BD%91%E7%BB%9C)
    * [剪裁全部](#%E5%89%AA%E8%A3%81%E5%85%A8%E9%83%A8)
  * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA)
    * [join](#join)
    * [json](#json)
    * [lower](#lower)
    * [split](#split)
    * [title](#title)
    * [upper](#upper)
    * [println](#println)
* [配置守护进程](#%E9%85%8D%E7%BD%AE%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
  * [配置/运行守护进程](#%E9%85%8D%E7%BD%AE%E8%BF%90%E8%A1%8C%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
    * [使用操作系统启动守护进程](#%E4%BD%BF%E7%94%A8%E6%93%8D%E4%BD%9C%E7%B3%BB%E7%BB%9F%E5%90%AF%E5%8A%A8%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
      * [配置Docker在系统启动时启动](#%E9%85%8D%E7%BD%AEdocker%E5%9C%A8%E7%B3%BB%E7%BB%9F%E5%90%AF%E5%8A%A8%E6%97%B6%E5%90%AF%E5%8A%A8)
        * [systemd](#systemd)
        * [upstart](#upstart)
        * [chkconfig](#chkconfig)
    * [手动启动守护程序](#%E6%89%8B%E5%8A%A8%E5%90%AF%E5%8A%A8%E5%AE%88%E6%8A%A4%E7%A8%8B%E5%BA%8F)
    * [配置Docker守护进程](#%E9%85%8D%E7%BD%AEdocker%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
    * [Docker 守护进程目录](#docker-%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B%E7%9B%AE%E5%BD%95)
    * [守护进程故障排除](#%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B%E6%95%85%E9%9A%9C%E6%8E%92%E9%99%A4)
      * [排查daemon\.json和启动脚本之间的冲突](#%E6%8E%92%E6%9F%A5daemonjson%E5%92%8C%E5%90%AF%E5%8A%A8%E8%84%9A%E6%9C%AC%E4%B9%8B%E9%97%B4%E7%9A%84%E5%86%B2%E7%AA%81)
        * [使用SYSTEMD中的DAEMON\.JSON中的主机密钥](#%E4%BD%BF%E7%94%A8systemd%E4%B8%AD%E7%9A%84daemonjson%E4%B8%AD%E7%9A%84%E4%B8%BB%E6%9C%BA%E5%AF%86%E9%92%A5)
      * [内存异常（OOME）](#%E5%86%85%E5%AD%98%E5%BC%82%E5%B8%B8oome)
      * [阅读日志](#%E9%98%85%E8%AF%BB%E6%97%A5%E5%BF%97)
      * [启用调试](#%E5%90%AF%E7%94%A8%E8%B0%83%E8%AF%95)
      * [强制堆栈跟踪被记录](#%E5%BC%BA%E5%88%B6%E5%A0%86%E6%A0%88%E8%B7%9F%E8%B8%AA%E8%A2%AB%E8%AE%B0%E5%BD%95)
      * [查看堆栈跟踪](#%E6%9F%A5%E7%9C%8B%E5%A0%86%E6%A0%88%E8%B7%9F%E8%B8%AA)
    * [检查Docker是否正在运行](#%E6%A3%80%E6%9F%A5docker%E6%98%AF%E5%90%A6%E6%AD%A3%E5%9C%A8%E8%BF%90%E8%A1%8C)
  * [使用systemd控制Docker](#%E4%BD%BF%E7%94%A8systemd%E6%8E%A7%E5%88%B6docker)
    * [启动Docker守护进程](#%E5%90%AF%E5%8A%A8docker%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
      * [手动启动](#%E6%89%8B%E5%8A%A8%E5%90%AF%E5%8A%A8)
      * [在系统启动时自动启动](#%E5%9C%A8%E7%B3%BB%E7%BB%9F%E5%90%AF%E5%8A%A8%E6%97%B6%E8%87%AA%E5%8A%A8%E5%90%AF%E5%8A%A8)
    * [自定义Docker守护进程选项](#%E8%87%AA%E5%AE%9A%E4%B9%89docker%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B%E9%80%89%E9%A1%B9)
      * [运行时目录和存储驱动程序](#%E8%BF%90%E8%A1%8C%E6%97%B6%E7%9B%AE%E5%BD%95%E5%92%8C%E5%AD%98%E5%82%A8%E9%A9%B1%E5%8A%A8%E7%A8%8B%E5%BA%8F)
      * [HTTP/HTTPS代理](#httphttps%E4%BB%A3%E7%90%86)
    * [配置Docker守护程序侦听连接的位置](#%E9%85%8D%E7%BD%AEdocker%E5%AE%88%E6%8A%A4%E7%A8%8B%E5%BA%8F%E4%BE%A6%E5%90%AC%E8%BF%9E%E6%8E%A5%E7%9A%84%E4%BD%8D%E7%BD%AE)
    * [手动创建systemd单元文件](#%E6%89%8B%E5%8A%A8%E5%88%9B%E5%BB%BAsystemd%E5%8D%95%E5%85%83%E6%96%87%E4%BB%B6)
* [配置容器](#%E9%85%8D%E7%BD%AE%E5%AE%B9%E5%99%A8)
  * [自动启动容器](#%E8%87%AA%E5%8A%A8%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8)
    * [使用重启策略](#%E4%BD%BF%E7%94%A8%E9%87%8D%E5%90%AF%E7%AD%96%E7%95%A5)
    * [重新启动策略详情](#%E9%87%8D%E6%96%B0%E5%90%AF%E5%8A%A8%E7%AD%96%E7%95%A5%E8%AF%A6%E6%83%85)
    * [使用流程管理器](#%E4%BD%BF%E7%94%A8%E6%B5%81%E7%A8%8B%E7%AE%A1%E7%90%86%E5%99%A8)
    * [使用容器内的进程管理器](#%E4%BD%BF%E7%94%A8%E5%AE%B9%E5%99%A8%E5%86%85%E7%9A%84%E8%BF%9B%E7%A8%8B%E7%AE%A1%E7%90%86%E5%99%A8)
  * [实时恢复保持容器运行](#%E5%AE%9E%E6%97%B6%E6%81%A2%E5%A4%8D%E4%BF%9D%E6%8C%81%E5%AE%B9%E5%99%A8%E8%BF%90%E8%A1%8C)
    * [启用实时恢复](#%E5%90%AF%E7%94%A8%E5%AE%9E%E6%97%B6%E6%81%A2%E5%A4%8D)
    * [在升级期间进行实时恢复](#%E5%9C%A8%E5%8D%87%E7%BA%A7%E6%9C%9F%E9%97%B4%E8%BF%9B%E8%A1%8C%E5%AE%9E%E6%97%B6%E6%81%A2%E5%A4%8D)
    * [重启时进行实时恢复](#%E9%87%8D%E5%90%AF%E6%97%B6%E8%BF%9B%E8%A1%8C%E5%AE%9E%E6%97%B6%E6%81%A2%E5%A4%8D)
    * [实时恢复对运行容器的影响](#%E5%AE%9E%E6%97%B6%E6%81%A2%E5%A4%8D%E5%AF%B9%E8%BF%90%E8%A1%8C%E5%AE%B9%E5%99%A8%E7%9A%84%E5%BD%B1%E5%93%8D)
    * [实时恢复和集群模式](#%E5%AE%9E%E6%97%B6%E6%81%A2%E5%A4%8D%E5%92%8C%E9%9B%86%E7%BE%A4%E6%A8%A1%E5%BC%8F)
  * [在容器中运行多个服务](#%E5%9C%A8%E5%AE%B9%E5%99%A8%E4%B8%AD%E8%BF%90%E8%A1%8C%E5%A4%9A%E4%B8%AA%E6%9C%8D%E5%8A%A1)
  * [运行时指标](#%E8%BF%90%E8%A1%8C%E6%97%B6%E6%8C%87%E6%A0%87)
    * [stats 统计信息](#stats-%E7%BB%9F%E8%AE%A1%E4%BF%A1%E6%81%AF)
    * [cgroup 控制组](#cgroup-%E6%8E%A7%E5%88%B6%E7%BB%84)
      * [枚举 cgroups](#%E6%9E%9A%E4%B8%BE-cgroups)
      * [查看容器的 cgroup](#%E6%9F%A5%E7%9C%8B%E5%AE%B9%E5%99%A8%E7%9A%84-cgroup)
      * [cgroups 指标：MEMORY/CPU/IO](#cgroups-%E6%8C%87%E6%A0%87memorycpuio)
    * [network  统计信息](#network--%E7%BB%9F%E8%AE%A1%E4%BF%A1%E6%81%AF)
      * [IPTABLES](#iptables)
      * [接口级计数器](#%E6%8E%A5%E5%8F%A3%E7%BA%A7%E8%AE%A1%E6%95%B0%E5%99%A8)
      * [高性能指标收集技巧](#%E9%AB%98%E6%80%A7%E8%83%BD%E6%8C%87%E6%A0%87%E6%94%B6%E9%9B%86%E6%8A%80%E5%B7%A7)
      * [在容器退出时收集指标](#%E5%9C%A8%E5%AE%B9%E5%99%A8%E9%80%80%E5%87%BA%E6%97%B6%E6%94%B6%E9%9B%86%E6%8C%87%E6%A0%87)
* [限制容器的资源](#%E9%99%90%E5%88%B6%E5%AE%B9%E5%99%A8%E7%9A%84%E8%B5%84%E6%BA%90)
  * [内存](#%E5%86%85%E5%AD%98)
    * [了解耗尽内存的风险](#%E4%BA%86%E8%A7%A3%E8%80%97%E5%B0%BD%E5%86%85%E5%AD%98%E7%9A%84%E9%A3%8E%E9%99%A9)
    * [限制容器对内存的访问](#%E9%99%90%E5%88%B6%E5%AE%B9%E5%99%A8%E5%AF%B9%E5%86%85%E5%AD%98%E7%9A%84%E8%AE%BF%E9%97%AE)
      * [\-\-memory\-swap 细节](#--memory-swap-%E7%BB%86%E8%8A%82)
    * [\-\-memory\-swappiness 细节](#--memory-swappiness-%E7%BB%86%E8%8A%82)
    * [\-\-kernel\-memory 细节](#--kernel-memory-%E7%BB%86%E8%8A%82)
  * [CPU](#cpu)
    * [配置默认的CFS调度程序](#%E9%85%8D%E7%BD%AE%E9%BB%98%E8%AE%A4%E7%9A%84cfs%E8%B0%83%E5%BA%A6%E7%A8%8B%E5%BA%8F)
    * [配置实时调度程序](#%E9%85%8D%E7%BD%AE%E5%AE%9E%E6%97%B6%E8%B0%83%E5%BA%A6%E7%A8%8B%E5%BA%8F)
      * [配置主机的内核](#%E9%85%8D%E7%BD%AE%E4%B8%BB%E6%9C%BA%E7%9A%84%E5%86%85%E6%A0%B8)
      * [配置DOCKER守护进程](#%E9%85%8D%E7%BD%AEdocker%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B-1)
* [docker 日志配置](#docker-%E6%97%A5%E5%BF%97%E9%85%8D%E7%BD%AE)
  * [查看容器或服务的日志](#%E6%9F%A5%E7%9C%8B%E5%AE%B9%E5%99%A8%E6%88%96%E6%9C%8D%E5%8A%A1%E7%9A%84%E6%97%A5%E5%BF%97)
  * [配置日志驱动](#%E9%85%8D%E7%BD%AE%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
    * [配置默认日志驱动](#%E9%85%8D%E7%BD%AE%E9%BB%98%E8%AE%A4%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
    * [配置容器的日志驱动](#%E9%85%8D%E7%BD%AE%E5%AE%B9%E5%99%A8%E7%9A%84%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
      * [配置容器到日志驱动程序的日志传送模式](#%E9%85%8D%E7%BD%AE%E5%AE%B9%E5%99%A8%E5%88%B0%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8%E7%A8%8B%E5%BA%8F%E7%9A%84%E6%97%A5%E5%BF%97%E4%BC%A0%E9%80%81%E6%A8%A1%E5%BC%8F)
      * [使用环境变量或标签与日志驱动程序](#%E4%BD%BF%E7%94%A8%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F%E6%88%96%E6%A0%87%E7%AD%BE%E4%B8%8E%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8%E7%A8%8B%E5%BA%8F)
    * [支持的日志驱动](#%E6%94%AF%E6%8C%81%E7%9A%84%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
  * [使用日志驱动插件](#%E4%BD%BF%E7%94%A8%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8%E6%8F%92%E4%BB%B6)
    * [安装日志驱动插件](#%E5%AE%89%E8%A3%85%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8%E6%8F%92%E4%BB%B6)
    * [将插件配置为默认的日志驱动](#%E5%B0%86%E6%8F%92%E4%BB%B6%E9%85%8D%E7%BD%AE%E4%B8%BA%E9%BB%98%E8%AE%A4%E7%9A%84%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
    * [配置容器以使用插件作为日志驱动](#%E9%85%8D%E7%BD%AE%E5%AE%B9%E5%99%A8%E4%BB%A5%E4%BD%BF%E7%94%A8%E6%8F%92%E4%BB%B6%E4%BD%9C%E4%B8%BA%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
  * [自定义日志驱动输出](#%E8%87%AA%E5%AE%9A%E4%B9%89%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8%E8%BE%93%E5%87%BA)
  * [日志驱动使用详解](#%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8%E4%BD%BF%E7%94%A8%E8%AF%A6%E8%A7%A3)
    * [json 日志驱动](#json-%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
      * [用法](#%E7%94%A8%E6%B3%95)
      * [选项](#%E9%80%89%E9%A1%B9)
      * [例子](#%E4%BE%8B%E5%AD%90)
    * [syslog 日志驱动](#syslog-%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
      * [用法](#%E7%94%A8%E6%B3%95-1)
      * [选项](#%E9%80%89%E9%A1%B9-1)
    * [journald日志驱动](#journald%E6%97%A5%E5%BF%97%E9%A9%B1%E5%8A%A8)
      * [用法](#%E7%94%A8%E6%B3%95-2)
      * [选项](#%E9%80%89%E9%A1%B9-2)
      * [有关容器名称的说明](#%E6%9C%89%E5%85%B3%E5%AE%B9%E5%99%A8%E5%90%8D%E7%A7%B0%E7%9A%84%E8%AF%B4%E6%98%8E)
      * [用检索日志消息 journalctl](#%E7%94%A8%E6%A3%80%E7%B4%A2%E6%97%A5%E5%BF%97%E6%B6%88%E6%81%AF-journalctl)
      * [查看启用了TTY的容器的日志](#%E6%9F%A5%E7%9C%8B%E5%90%AF%E7%94%A8%E4%BA%86tty%E7%9A%84%E5%AE%B9%E5%99%A8%E7%9A%84%E6%97%A5%E5%BF%97)
      * [使用journalAPI 检索日志消息](#%E4%BD%BF%E7%94%A8journalapi-%E6%A3%80%E7%B4%A2%E6%97%A5%E5%BF%97%E6%B6%88%E6%81%AF)
* [docker 安全配置](#docker-%E5%AE%89%E5%85%A8%E9%85%8D%E7%BD%AE)
  * [Docker 安全性](#docker-%E5%AE%89%E5%85%A8%E6%80%A7)
    * [内核命名空间](#%E5%86%85%E6%A0%B8%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4)
    * [控制组](#%E6%8E%A7%E5%88%B6%E7%BB%84)
    * [Docker 守护进程攻击](#docker-%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B%E6%94%BB%E5%87%BB)
    * [Linux内核功能](#linux%E5%86%85%E6%A0%B8%E5%8A%9F%E8%83%BD)
    * [其他内核安全功能](#%E5%85%B6%E4%BB%96%E5%86%85%E6%A0%B8%E5%AE%89%E5%85%A8%E5%8A%9F%E8%83%BD)
    * [结论](#%E7%BB%93%E8%AE%BA)
  * [保护Docker守护进程套接字](#%E4%BF%9D%E6%8A%A4docker%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B%E5%A5%97%E6%8E%A5%E5%AD%97)
    * [使用OpenSSL创建CA，服务器和客户端密钥](#%E4%BD%BF%E7%94%A8openssl%E5%88%9B%E5%BB%BAca%E6%9C%8D%E5%8A%A1%E5%99%A8%E5%92%8C%E5%AE%A2%E6%88%B7%E7%AB%AF%E5%AF%86%E9%92%A5)
      * [创建 CA 证书](#%E5%88%9B%E5%BB%BA-ca-%E8%AF%81%E4%B9%A6)
      * [创建服务器端秘钥](#%E5%88%9B%E5%BB%BA%E6%9C%8D%E5%8A%A1%E5%99%A8%E7%AB%AF%E7%A7%98%E9%92%A5)
      * [创建客户端秘钥](#%E5%88%9B%E5%BB%BA%E5%AE%A2%E6%88%B7%E7%AB%AF%E7%A7%98%E9%92%A5)
      * [清理签名/控制权限](#%E6%B8%85%E7%90%86%E7%AD%BE%E5%90%8D%E6%8E%A7%E5%88%B6%E6%9D%83%E9%99%90)
    * [默认安全模式](#%E9%BB%98%E8%AE%A4%E5%AE%89%E5%85%A8%E6%A8%A1%E5%BC%8F)
    * [其他模式](#%E5%85%B6%E4%BB%96%E6%A8%A1%E5%BC%8F)
      * [守护进程模式](#%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B%E6%A8%A1%E5%BC%8F)
      * [客户端模式](#%E5%AE%A2%E6%88%B7%E7%AB%AF%E6%A8%A1%E5%BC%8F)
      * [使用 curl连接到安全的Docker端口](#%E4%BD%BF%E7%94%A8-curl%E8%BF%9E%E6%8E%A5%E5%88%B0%E5%AE%89%E5%85%A8%E7%9A%84docker%E7%AB%AF%E5%8F%A3)
  * [用证书验证存储库客户端](#%E7%94%A8%E8%AF%81%E4%B9%A6%E9%AA%8C%E8%AF%81%E5%AD%98%E5%82%A8%E5%BA%93%E5%AE%A2%E6%88%B7%E7%AB%AF)
    * [了解配置](#%E4%BA%86%E8%A7%A3%E9%85%8D%E7%BD%AE)
    * [创建客户端证书](#%E5%88%9B%E5%BB%BA%E5%AE%A2%E6%88%B7%E7%AB%AF%E8%AF%81%E4%B9%A6)
    * [疑难解答提示](#%E7%96%91%E9%9A%BE%E8%A7%A3%E7%AD%94%E6%8F%90%E7%A4%BA)
  * [利用命名空间隔离容器](#%E5%88%A9%E7%94%A8%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4%E9%9A%94%E7%A6%BB%E5%AE%B9%E5%99%A8)
    * [关于重新映射和从属用户和组ID](#%E5%85%B3%E4%BA%8E%E9%87%8D%E6%96%B0%E6%98%A0%E5%B0%84%E5%92%8C%E4%BB%8E%E5%B1%9E%E7%94%A8%E6%88%B7%E5%92%8C%E7%BB%84id)
    * [先决条件](#%E5%85%88%E5%86%B3%E6%9D%A1%E4%BB%B6)
  * [在守护程序上启用用户名重新映射](#%E5%9C%A8%E5%AE%88%E6%8A%A4%E7%A8%8B%E5%BA%8F%E4%B8%8A%E5%90%AF%E7%94%A8%E7%94%A8%E6%88%B7%E5%90%8D%E9%87%8D%E6%96%B0%E6%98%A0%E5%B0%84)
    * [禁用容器的命名空间重新映射](#%E7%A6%81%E7%94%A8%E5%AE%B9%E5%99%A8%E7%9A%84%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4%E9%87%8D%E6%96%B0%E6%98%A0%E5%B0%84)
    * [用户命名空间已知限制](#%E7%94%A8%E6%88%B7%E5%91%BD%E5%90%8D%E7%A9%BA%E9%97%B4%E5%B7%B2%E7%9F%A5%E9%99%90%E5%88%B6)

# 配置对象

## 自定义元数据

标签是一种将元数据应用于Docker对象的机制，包括：

- `Images` 镜像
- `Containers` 容器
- `Local daemons` 本地守护进程
- `Volumes` 卷
- `Networks` 网络
- `Swarm nodes` 集群节点
- `Swarm services` 集群服务

*可以使用标签来组织镜像、记录许可信息、容器注释、卷和网络之间的关系，或以任何对业务或应用程序有意义的进行注释*。

### 标签键和值

---

标签是一个**键值对**，以**字符串形式存储**。可以为对象指定**多个**标签，但每个键值对在对象中必须是**唯一**的。如果同一个键有多个值，则最近写入的值会**覆盖**所有以前的值。

#### 格式建议

标签*键*是*键值*对的左侧。键是可能包含句点（`.`）和连字符（`-`）的字母数字字符串。大多数Docker用户使用由其他组织创建的镜像，并且以下指导原则有助于防止跨对象无意间重复标签，特别是如果打算将标签用作**自动化**机制。

- 第三方工具的作者应该为每个标签关键字加上他们拥有的**域的反向DNS标记**，例如`com.example.some-label`。
- 未经域所有者的许可，请勿在标签中**使用域名**。
- 这些`com.docker.*`，`io.docker.*`和`org.dockerproject.*`名称空间由Docker保留供**内部使用**。
- 标签键应以**小写字母开头和结尾**，并且**只能**包含小写字母数字字符，句点字符（`.`）和连字符（`-`）。**不允许连续的句点或连字符**。
- 句点字符（。）分隔命名空间“字段”。没有命名空间的标签被保留用于CLI使用，允许CLI的用户使用更短的键入友好字符串交互地标记Docker对象。

#### 价值准则

标签值可以包含任何可以表示为字符串的数据类型，包括（但不限于）JSON，XML，CSV或YAML。唯一的要求是，首先使用特定于结构类型的机制将该值**序列化**为字符串。例如，要将JSON序列化为字符串，你可以使用`JSON.stringify()`方法。

由于Docker并未**反序列化**该值，因此在按标签值**查询或过滤**时，不能将JSON或XML文档视为**嵌套结构**，除非你将此功能构建到第三方工具中。

### 管理对象上的标签

---

支持标签的每种类型的对象都具有添加和管理它们的机制，并在与该类型对象相关时使用它们。这些链接提供了一个开始学习如何在Docker部署中使用标签的好地方。

镜像、容器、本地守护进程、卷和网络上的标签在对象的生命周期内是静态的。要更改这些标签，必须**重新创建**该对象。**swarm节点和服务上的标签可以动态更新**。

- 镜像和容器
  - [为镜像添加标签](https://docs.docker.com/engine/reference/builder/#label)
  - [运行时覆盖容器的标签](https://docs.docker.com/engine/reference/commandline/run/#set-metadata-on-container--l---label---label-file)
  - [检查镜像或容器上的标签](https://docs.docker.com/engine/reference/commandline/inspect/)
  - [按标签过滤镜像](https://docs.docker.com/engine/reference/commandline/images/#filtering)
  - [按标签过滤容器](https://docs.docker.com/engine/reference/commandline/ps/#filtering)
- 本地Docker守护进程
  - [在运行时向Docker守护进程添加标签](https://docs.docker.com/engine/reference/commandline/dockerd/)
  - [检查Docker守护进程的标签](https://docs.docker.com/engine/reference/commandline/info/)
- 卷
  - [为卷添加标签](https://docs.docker.com/engine/reference/commandline/volume_create/)
  - [检查卷的标签](https://docs.docker.com/engine/reference/commandline/volume_inspect/)
  - [按标签过滤卷](https://docs.docker.com/engine/reference/commandline/volume_ls/#filtering)
- 网络
  - [向网络添加标签](https://docs.docker.com/engine/reference/commandline/network_create/)
  - [检查网络标签](https://docs.docker.com/engine/reference/commandline/network_inspect/)
  - [按标签过滤网络](https://docs.docker.com/engine/reference/commandline/network_ls/#filtering)
- Swarm节点
  - [添加或更新集群节点的标签](https://docs.docker.com/engine/reference/commandline/node_update/#add-label-metadata-to-a-node)
  - [检查集群节点的标签](https://docs.docker.com/engine/reference/commandline/node_inspect/)
  - [通过标签过滤swarm节点](https://docs.docker.com/engine/reference/commandline/node_ls/#filtering)
- 集群服务
  - [创建集群服务时添加标签](https://docs.docker.com/engine/reference/commandline/service_create/#set-metadata-on-a-service-l-label)
  - [更新swarm服务的标签](https://docs.docker.com/engine/reference/commandline/service_update/)
  - [检查集群服务的标签](https://docs.docker.com/engine/reference/commandline/service_inspect/)
  - [通过标签过滤集群服务](https://docs.docker.com/engine/reference/commandline/service_ls/#filtering)

## 剪裁未使用的对象

Docker采用**保守**的方法来清理未使用的对象（通常称为“垃圾回收”），例如镜像，容器，卷和网络：除非明确要求Docker这样做，否则通常不会删除这些对象。如果不删除这可能会导致Docker使用**额外的磁盘空间**。对于每种类型的对象，Docker都提供一个`prune`命令。另外，可以使用`docker system prune`一次**清理多种类型**的对象。

### 剪裁镜像

---

`docker image prune`命令允许清理未使用的镜像。默认情况下`docker image prune`只清理**dangling**镜像。一个`dangling`的镜像是一个没有**被标记**的镜像，并且**没有被任何容器引用**。删除`dangling`镜像：

```sh
$ docker image prune
WARNING! This will remove all dangling images.
Are you sure you want to continue? [y/N] y
```

要删除现有容器**未使用的所有镜像**，请使用以下`-a` 选项：

```sh
$ docker image prune -a
WARNING! This will remove all images without at least one container associated to them.
Are you sure you want to continue? [y/N] y
```

默认情况下，系统会提示是否继续。要绕过提示，请使用`-f`或 `--force`选项。

可以使用带有`--filter`选项的**过滤**表达式来限制剪裁哪些镜像 。例如，要考虑超过24小时前创建的镜像：

```sh
# 超过24小时
$ docker image prune -a --filter "until=24h"
```

### 剪裁容器

---

当你停止一个容器时，它不会被自动删除，除非你用`--rm`选项启动它。要查看Docker主机上的所有容器（包括已停止的容器），请使用`docker ps -a`。可能会惊讶有多少个容器存在，尤其是在开发系统上！已停止的容器的可写层仍占用磁盘空间。要清理它，可以使用`docker container prune`命令。

```sh
$ docker container prune

WARNING! This will remove all stopped containers.
Are you sure you want to continue? [y/N] y
```

默认情况下，系统会提示继续。要绕过提示，请使用`-f`或 `--force`选项。

默认情况下，所有停止的容器都被删除。可以使用`--filter`选项限制范围。例如，以下命令仅删除24小时以前停用的容器：

```sh
$ docker container prune --filter "until=24h"
```

### 剪裁卷

---

卷可以被一个或多个容器使用，并占用Docker主机上的空间。卷不会自动删除，因为这样做可能会破坏数据。

```sh
$ docker volume prune

WARNING! This will remove all volumes not used by at least one container.
Are you sure you want to continue? [y/N] y
```

默认情况下，系统会提示是否继续。要绕过提示，请使用`-f`或 `--force`选项。

默认情况下，所有未使用的卷都被删除。可以使用`--filter`选项限制范围。例如，以下命令仅删除没有标签`keep`标签的卷：

```sh
$ docker volume prune --filter "label!=keep"
```

### 剪裁网络

---

Docker网络不会占用太多的磁盘空间，但它们确实会创建`iptables` 规则，桥接网络设备和路由规则。要清理这些东西，可以使用`docker network prune`清理未被任何容器使用的网络。

```sh
$ docker network prune

WARNING! This will remove all networks not used by at least one container.
Are you sure you want to continue? [y/N] y
```

默认情况下，系统会提示是否继续。要绕过提示，请使用`-f`或 `--force`选项。

默认情况下，所有未使用的网络都将被删除。可以使用`--filter`选项限制范围。例如，以下命令仅删除超过24小时的网络：

```sh
$ docker network prune --filter "until=24h"
```

### 剪裁全部

---

`docker system prune`命令是清理镜像，容器和网络的捷径。在Docker 17.06.0及更早版本中，卷也被剪裁。在Docker 17.06.1及更高版本中，必须指定`docker system prune`修剪卷的`--volumes`选项 。

```sh
$ docker system prune

WARNING! This will remove:
        - all stopped containers
        - all networks not used by at least one container
        - all dangling images
        - all build cache
Are you sure you want to continue? [y/N] y
```

如果使用的是Docker 17.06.1或更高版本，并且还想修剪卷，请添加`--volumes`选项：

```sh
$ docker system prune --volumes

WARNING! This will remove:
        - all stopped containers
        - all networks not used by at least one container
        - all volumes not used by at least one container
        - all dangling images
        - all build cache
Are you sure you want to continue? [y/N] y
```

## 格式化输出

Docker使用[Go模板](https://golang.org/pkg/text/template/)，可以使用它来控制某些命令和日志驱动程序的输出格式。

Docker提供了一组基本的函数来操作模板元素。所有这些示例都使用`docker inspect`命令，但许多其他CLI命令都有一个`--format`选项，这些CLI命令参考都包含自定义输出格式。

### join

`join`连接字符串列表以创建单个字符串。它在列表中的每个元素之间放置一个分隔符。

```sh
$ docker inspect --format '{{join .Args " , "}}' container_id
```

### json

`json` 将元素编码为`json`格式字符串。

```sh
$ docker inspect --format '{{json .Mounts}}' container
```

### lower

`lower` 将字符串转换为其小写形式。

```sh
$ docker inspect --format "{{lower .Name}}" container
```

### split

`split` 将字符串切分为由分隔符分隔的字符串列表。

```sh
$ docker inspect --format '{{split (join .Names "/") "/"}}' container
```

### title

`title` 大写字符串的第一个字符。

```sh
$ docker inspect --format "{{title .Name}}" container
```

### upper

`upper` 将字符串转换为大写形式。

```sh
$ docker inspect --format "{{upper .Name}}" container
```

### println

`println` 在新行上打印每个值。

```sh
$ docker inspect --format='{{range .NetworkSettings.Networks}}{{println .IPAddress}}{{end}}' container
```

# 配置守护进程

## 配置/运行守护进程

在成功安装并启动Docker后，`dockerd`守护进程将以其默认配置运行。如何自定义配置，手动启动守护程序以及如果遇到问题时对守护程序进行故障排除和调试。 

### 使用操作系统启动守护进程

---

在典型的安装中，Docker守护进程由**系统应用程序启动**，而不是由用户**手动启动**。这使得在机器重新启动时自动启动Docker变得更加容易。

启动Docker的命令取决于操作系统。查看[安装Docker](https://docs.docker.com/install/)的正确页面。要将Docker配置为在系统引导时自动启动，请参阅将 [Docker配置为在引导时启动](https://docs.docker.com/install/linux/linux-postinstall/#configure-docker-to-start-on-boot)。

#### 配置Docker在系统启动时启动

大多数当前的Linux发行版（RHEL，CentOS，Fedora，Ubuntu 16.04和更高版本）用于[`systemd`](https://docs.docker.com/install/linux/linux-postinstall/#systemd)管理在**系统引导**时启动哪些服务。Ubuntu 14.10及以下版本使用[`upstart`](https://docs.docker.com/install/linux/linux-postinstall/#upstart)。

##### `systemd`

```sh
$ sudo systemctl enable docker
```

要禁用此行为，请`disable`改为使用。

```sh
$ sudo systemctl disable docker
```

如果需要添加HTTP代理，为Docker运行时文件设置不同的目录或分区，或者进行其他自定义，请参阅 [自定义你的systemd Docker守护程序选项](https://docs.docker.com/engine/admin/systemd/)。

##### `upstart`

Docker会自动配置为在启动时使用 `upstart`。要禁用此行为，请使用以下命令：

```sh
$ echo manual | sudo tee /etc/init/docker.override
```

##### `chkconfig`

```sh
$ sudo chkconfig docker on
```

### 手动启动守护程序

---

如果不想使用系统应用程序来管理Docker守护进程，则可以使用`dockerd` 命令**手动运行**它。可能需要使用`sudo`，具体取决于操作系统配置。当以这种方式启动Docker时，它会在前台运行，并将其日志直接发送到终端。

```sh
$ dockerd

INFO[0000] +job init_networkdriver()
INFO[0000] +job serveapi(unix:///var/run/docker.sock)
INFO[0000] Listening for HTTP on unix (/var/run/docker.sock)
```

要手动启动Docker时停止Docker，请`Ctrl+C`在你的终端中发出一个。

### 配置Docker守护进程

---

有两种方法可以配置Docker守护进程：

- 使用**JSON配置**文件。这是首选，因为它将所有配置保留在一个地方。
- 开始时使用选项`dockerd`。

只要**不指定相同的选项**作为选项和JSON文件，就可以同时使用这两个选项。如果使用相同的选项，Docker守护程序将不会启动并输出错误消息。

要使用JSON文件配置Docker守护进程，请在Linux系统`/etc/docker/daemon.json`或Windows 上创建文件`C:\ProgramData\docker\config\daemon.json`  。

以下是配置文件的样子：

```json
{
  "debug": true,
  "tls": true,
  "tlscert": "/var/docker/server.pem",
  "tlskey": "/var/docker/serverkey.pem",
  "hosts": ["tcp://192.168.59.3:2376"]
}
```

通过此配置，Docker守护进程以**调试模式**运行，**使用TLS**，并侦听路由`192.168.59.3`端口的流量`2376`。可以了解[dockerd参考文档](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)中提供了哪些配置选项。

也可以手动启动Docker守护程序并使用选项对其进行配置。这对**解决问题很有用**。下面是一个如何手动启动Docker守护进程的例子，使用与上面相同的配置：

```sh
$ dockerd --debug \
  --tls=true \
  --tlscert=/var/docker/server.pem \
  --tlskey=/var/docker/serverkey.pem \
  --host tcp://192.168.59.3:2376
```

可以在[dockerd参考文档中](https://docs.docker.com/engine/reference/commandline/dockerd/)了解哪些配置选项可用 ，或者运行以下命令：

```sh
$ dockerd --help
```

Docker文档中会讨论许多特定的配置选项。接下来的一些地方包括：

- [自动启动容器](https://docs.docker.com/engine/admin/host_integration/)
- [限制容器的资源](https://docs.docker.com/engine/admin/resource_constraints/)
- [配置存储驱动程序](https://docs.docker.com/engine/userguide/storagedriver/)
- [容器安全](https://docs.docker.com/engine/security/)

### Docker 守护进程目录

---

Docker守护进程将所有数据保存在一个目录中。这将跟踪与Docker相关的所有内容，包括容器，镜像，卷，服务定义和秘密。

默认情况下，这个目录是：

- `/var/lib/docker` 在Linux上。
- `C:\ProgramData\docker` 在Windows上。

可以使用`data-root`配置选项将Docker守护程序配置为**使用其他目录** 。由于Docker守护进程的状态保留在此目录中，因此请确保为每个**守护进程使用专用目录**。如果两个守护程序**共享相同**的目录（例如NFS共享），则你将遇到难以排除**故障**的错误。

### 守护进程故障排除

---

可以在守护进程上**启用调试**，以了解守护进程的运行时活动并帮助进行故障排除。如果守护进程完全没有响应，还可以通过向Docker守护进程发送`SIGUSR`信号来[强制将](https://docs.docker.com/config/daemon/#force-a-full-stack-trace-to-be-logged)所有线程[的完整堆栈服务跟踪](https://docs.docker.com/config/daemon/#force-a-full-stack-trace-to-be-logged)添加到守护进程日志中。

#### 排查`daemon.json`和启动脚本之间的冲突

如果使用`daemon.json`文件并且还`dockerd` 手动将选项传递给命令或使用启动脚本，并且这些选项冲突，则Docker无法启动，如以下错误：

```sh
unable to configure the Docker daemon with file /etc/docker/daemon.json:
the following directives are specified both as a flag and in the configuration
file: hosts: (from flag: [unix:///var/run/docker.sock], from file: [tcp://127.0.0.1:2376])
```

如果看到与此类似的错误，并且使用选项手动启动守护进程，则可能需要调整选项或`daemon.json`删除冲突。

> **注意**：如果看到此特定错误，请继续 [下一部分](https://docs.docker.com/config/daemon/#use-the-hosts-key-in-daemon-json-with-systemd)的解决方法。

如果你使用操作系统的`init`脚本启动Docker，则可能需要以特定于操作系统的方式**覆盖**这些脚本中的默认值。

##### 使用SYSTEMD中的DAEMON.JSON中的主机密钥

配置冲突难以解决的一个值得注意的例子是，希望从默认值指定不同的守护进程程序地址。默认情况下，**Docker在套接字上侦听**。在使用`systemd`的Debian和Ubuntu系统时，这意味着`-H`启动时始终使用主机选项`dockerd`。如果在`daemon.json`中指定`hosts`配置，则会导致配置冲突（如上面的消息中所述），并且Docker无法启动。

要解决此问题，请使用以下内容创建一个新文件`/etc/systemd/system/docker.service.d/docker.conf`，以删除在`-H`默认情况下启动守护程序时使用的参数。

```properties
[Service]
ExecStart=
ExecStart=/usr/bin/dockerd
```

有时候可能需要使用Docker 进行`systemd`配置，例如 [配置HTTP或HTTPS代理](https://docs.docker.com/engine/admin/systemd/#httphttps-proxy)。

> **注意**：如果重写此选项，然后`hosts`在手动启动Docker时未在`daemon.json` 或 `-H`选项中指定条目，则Docker无法启动。

在尝试启动Docker之前运行`sudo systemctl daemon-reload`。如果Docker启动成功，它现在正在侦听`daemon.json`的`hosts`键中**指定的IP地址**，而不是套接字。

> **重要提示**：在Docker for Windows或Docker for Mac上不支持在`daemon.json`中设置主机。

#### 内存异常（OOME）

如果容器尝试使用**比系统可用的内存更多的内存**，则可能会遇到内存异常（OOME），并且容器或Docker守护程序可能会被内核OOM所杀。要防止发生这种情况，请确保应用程序在具有**足够内存**的主机上运行，并且请参阅 [了解耗尽内存的风险](https://docs.docker.com/engine/admin/resource_constraints/#understand-the-risks-of-running-out-of-memory)。

#### 阅读日志

守护进程日志可以帮助你诊断问题。根据操作系统配置和使用的日志记录子系统，日志可以保存在几个位置之一中：

| 操作系统               | 位置                                                         |
| ---------------------- | ------------------------------------------------------------ |
| RHEL，Oracle Linux     | `/var/log/messages`                                          |
| Debian                 | `/var/log/daemon.log`                                        |
| Ubuntu 16.04+，CentOS  | 使用命令 `journalctl -u docker.service`                      |
| Ubuntu 14.10-          | `/var/log/upstart/docker.log`                                |
| macOS（Docker 18.01+） | `~/Library/Containers/com.docker.docker/Data/vms/0/console-ring` |
| macOS（Docker <18.01） | `~/Library/Containers/com.docker.docker/Data/com.docker.driver.amd64-linux/console-ring` |
| Windows                | `AppData\Local`                                              |

#### 启用调试

有两种方法来启用调试。推荐的方法是将 `debug`设置`true`在`daemon.json`文件中。此方法适用于每个Docker平台。

1. 编辑`daemon.json`通常位于的文件`/etc/docker/`。如果文件尚不存在，可能需要创建该文件。在macOS或Windows上，请勿直接编辑文件。请转到 **首选项** / **守护进程** / **高级**进行配置。

2. 如果文件为空，请添加以下内容：

   ```json
   {
     "debug": true
   }
   ```

   如果文件已经包含JSON，只需添加`"debug": true`，如果它不是结束括号之前的最后一行，请谨慎地在该行的末尾添加逗号。同时验证是否`log-level`已设置，将其设置为`info`或`debug`。`info`是默认的，其他可选择的值是`debug`，`info`，`warn`，`error`，`fatal`。

3. `HUP`向守护程序发送信号以使其重新加载其配置。在Linux主机上，使用以下命令。

   ```sh
   $ sudo kill -SIGHUP $(pidof dockerd)
   ```

   在Windows主机上，重新启动Docker。

也可以**停止Docker守护进程**并使用**调试选项手动重新启动**它，而不是遵循此过程。但是，这可能会导致Docker使用与主机**启动脚本**创建的环境不同的环境重新启动，这可能会使调试更加困难。

#### 强制堆栈跟踪被记录

如果守护进程没有响应，可以通过向守护进程发送信号`SIGUSR1`来强制记录完整的堆栈跟踪。

- **Linux**：

  ```
  $ sudo kill -SIGUSR1 $(pidof dockerd)
  ```

- **Windows服务器**：

  下载 [docker-signal](https://github.com/jhowardmsft/docker-signal)

  用`--pid=<PID of daemon>`选项运行可执行文件。

这会强制堆栈跟踪被记录，但不会停止守护进程。守护进程日志显示**堆栈跟踪或包含堆栈跟踪的文件**的路径（如果它已记录到文件中）。

守护进程在处理完`SIGUSR1`信号并将堆栈跟踪**转储到日志**后继续运行。堆栈跟踪可用于**确定守护进程内所有goroutine和线程**的状态。

#### 查看堆栈跟踪

Docker守护进程日志可以通过使用以下方法之一来查看：

- 通过`journalctl -u docker.service`在Linux系统上运行使用`systemctl`
- `/var/log/messages`，`/var/log/daemon.log`或者`/var/log/docker.log`在较老的Linux系统上
- 通过`Get-EventLog -LogName Application -Source Docker -After (Get-Date).AddMinutes(-5) | Sort-Object Time | Export-CSV ~/last5minutes.CSV`在Windows Server上运行Docker EE

> **注意**：无法在Docker for Mac或Docker for Windows上手动生成堆栈跟踪。但是，如果遇到问题，可以单击Docker任务栏图标并选择**诊断和反馈**来向Docker发送信息。

查看Docker日志中的消息，如下所示：

```
...goroutine stacks written to /var/run/docker/goroutine-stacks-2017-06-02T193336z.log
...daemon datastructure dump written to /var/run/docker/daemon-data-2017-06-02T193336z.log
```

Docker保存这些堆栈跟踪和转储的位置取决于操作系统和配置。有时可以直接从堆栈跟踪和转储中获取有用的诊断信息。否则，你可以将此信息提供给Docker以帮助诊断问题。

### 检查Docker是否正在运行

---

检查Docker是否运行的独立于操作系统的方法是使用`docker info`命令询问Docker 。<br/>还可以使用操作系统实用程序（例如 `sudo systemctl is-active docker`或`sudo status docker`或`sudo service docker status`），或使用Windows实用程序检查服务状态。

最后，可以使用`ps`或`top`之类的命令来检查`dockerd`进程的进程列表。

## 使用systemd控制Docker

许多Linux发行版使用systemd来启动Docker守护进程。 

### 启动Docker守护进程

---

#### 手动启动

一旦安装了Docker，需要启动Docker守护进程。大多数Linux发行版都用`systemctl`来启动服务。如果没有`systemctl`，请使用`service`命令。

- **systemctl**：

  ```
  $ sudo systemctl start docker
  ```

- **service**：

  ```
  $ sudo service docker start
  ```

#### 在系统启动时自动启动

如果你希望Docker在启动时启动，请参阅上面的 **配置Docker以在启动时启动**。

### 自定义Docker守护进程选项

---

有很多方法可以为你的Docker守护进程配置守护进程选项和环境变量。推荐的方法是使用平台无关 `daemon.json`文件，该文件默认位于Linux上`/etc/docker/`。请参阅 [守护程序配置文件](https://docs.docker.com/engine/reference/commandline/dockerd//#daemon-configuration-file)。

可以使用配置几乎所有守护程序配置`daemon.json`选项。以下示例配置了两个选项。无法使用`daemon.json`机制配置的一件事是[HTTP代理](https://docs.docker.com/config/daemon/#http-proxy)。

#### 运行时目录和存储驱动程序

你可能希望通过将Docker镜像、容器和卷移动到单独的分区来控制镜像、容器和卷的磁盘空间。

 要完成此操作，请在`daemon.json`文件中设置以下选项：

```json
{
    "data-root": "/mnt/docker-data",
    "storage-driver": "overlay"
}
```

#### HTTP/HTTPS代理

docker守护程序使用`HTTP_PROXY`，`HTTPS_PROXY`以及`NO_PROXY`环境变量在其启动环境来配置HTTP或HTTPS代理的行为。不能使用`daemon.json`文件配置这些环境变量。

此示例覆盖默认`docker.service`文件。

如果你位于HTTP或HTTPS代理服务器的后面（例如在公司设置中），则需要在`Docker systemd`服务文件中添加此配置。

1. 为docker服务创建一个systemd放置目录：

   ```sh
   $ sudo mkdir -p /etc/systemd/system/docker.service.d
   ```

2. 创建一个名为`/etc/systemd/system/docker.service.d/http-proxy.conf`的文件 ，添加`HTTP_PROXY`环境变量：

   ```properties
   [Service]
   Environment="HTTP_PROXY=http://proxy.example.com:80/"
   ```

   或者，如果你位于HTTPS代理服务器的后面，请创建一个名为`/etc/systemd/system/docker.service.d/https-proxy.conf`的文件 来添加`HTTPS_PROXY`环境变量：

   ```properties
   [Service]
   Environment="HTTPS_PROXY=https://proxy.example.com:443/"
   ```

3. 如果有内部Docker注册表，需要访问而无需代理，则可以通过`NO_PROXY`环境变量指定它们：

   ```properties
   [Service]    
   Environment="HTTP_PROXY=http://proxy.example.com:80/" "NO_PROXY=localhost,127.0.0.1,docker-registry.somecorporation.com"
   ```

   或者，如果你位于HTTPS代理服务器的后面：

   ```properties
   [Service]    
   Environment="HTTPS_PROXY=https://proxy.example.com:443/" "NO_PROXY=localhost,127.0.0.1,docker-registry.somecorporation.com"
   ```

4. 重新加载得到更改：

   ```sh
   $ sudo systemctl daemon-reload
   ```

5. 重新启动Docker：

   ```sh
   $ sudo systemctl restart docker
   ```

6. 确认配置已加载：

   ```sh
   $ systemctl show --property=Environment docker
   Environment=HTTP_PROXY=http://proxy.example.com:80/
   ```

   或者，如果你位于HTTPS代理服务器的后面：

   ```sh
   $ systemctl show --property=Environment docker
   Environment=HTTPS_PROXY=https://proxy.example.com:443/
   ```

### 配置Docker守护程序侦听连接的位置

---

请参阅 [配置Docker守护程序侦听连接的位置](https://docs.docker.com/install/linux/linux-postinstall/#control-where-the-docker-daemon-listens-for-connections)。

### 手动创建systemd单元文件

---

在没有包的情况下安装二进制文件时，你可能需要将Docker与systemd集成。为此，将两个单元文件（`service`和`socket`）从[github存储库安装](https://github.com/moby/moby/tree/master/contrib/init/systemd) 到`/etc/systemd/system`

# 配置容器

## 自动启动容器

Docker提供了[重新启动策略](https://docs.docker.com/engine/reference/run/#restart-policies---restart)， 以控制容器在退出时是**自动启动**还是在Docker重新启动时启动。**重启策略**可确保链接的容器以**正确的顺序**启动。Docker**建议使用重新启动策略**，并**避免**使用进程管理器启动容器。

重新启动策略`--live-restore`与`dockerd` 命令的选项不同。使用`--live-restore`允许你在Docker**升级期间**保持容器运行，但网络和用户输入被**中断**。

### 使用重启策略

---

要为容器配置重启策略，请在使用`docker run`命令时使用`--restart`选项。`--restart`选项的值可以是以下任何一项：

| 选项             | 描述                                                         |
| ---------------- | ------------------------------------------------------------ |
| `no`             | 不要自动重启容器。（默认）                                   |
| `on-failure`     | 如果容器由于错误而退出，则将其重新启动，该错误表现为**非零退出代码**。 |
| `unless-stopped` | 重新启动容器，除非它**明确停止或者Docker本身停止或重新启动**。 |
| `always`         | 如果停止，请**始终**重新启动容器。                           |

以下示例启动Redis容器并将其配置为始终重新启动，除非它明确停止或Docker重新启动。

```sh
$ docker run -dit --restart unless-stopped redis
```

### 重新启动策略详情

---

使用重新启动策略时请记住以下几点：

- 重新启动策略仅在**容器启动成功**后才生效。在这种情况下，启动成功意味着容器已启动**至少10秒**，并且Docker已开始**监视**它。这可以防止根本不启动的容器进入**重启循环**。
- 如果**手动**停止容器，则在重新启动Docker**守护程序**或**手动重新启动**容器之前，将**忽略**其重新启动策略。这是另一个防止**重启循环**的尝试。
- 重新启动策略仅适用于**容器**。集群服务的重新启动策略配置不同。查看[与重新启动服务相关](https://docs.docker.com/engine/reference/commandline/service_create/)的 [选项](https://docs.docker.com/engine/reference/commandline/service_create/)。

### 使用流程管理器

---

如果重新启动策略不适合你的需求，例如**Docker以外的进程依赖于Docker容器**，则可以使用诸如[upstart](http://upstart.ubuntu.com/)， [systemd](http://freedesktop.org/wiki/Software/systemd/)或[supervisor之](http://supervisord.org/)类的**进程管理器 **。

> **警告**：不要尝试将Docker重新启动策略与主机级进程管理器结合使用，因为这会产生冲突。

要使用进程管理器，请将其配置为使用你通常用于**手动启动**容器的命令`docker start`或`docker service`命令启动容器或服务。

### 使用容器内的进程管理器

---

进程管理器也可以在容器中运行，以**检查进程是否正在运行**，如果没有，则启动/重启进程。

> **警告**：这些不是Docker感知的，只是监视容器内的操作系统进程。<br/>Docker**不推荐**这种方法，因为它**依赖于平台**，甚至在给定的Linux发行版的不同版本中有所不同。

## 实时恢复保持容器运行

默认情况下，当Docker守护进程**终止**时，会**关闭正在运行**的容器。从Docker Engine 1.12开始，你可以配置守护进程，以便在守护进程**不可用时保持容器运行**。这个功能被称为**实时恢复**。实时恢复选项有助于**减少由于守护进程崩溃，计划停机或升级导致的容器停机时间**。

> **注意**：Windows容器不支持实时恢复，但它适用于在Docker for Windows上运行的Linux容器。

### 启用实时恢复

---

有两种方法可以启用实时还原设置，以便在守护程序变得不可用时保持容器活动状态。**只做下列其中一项**。

- 将**配置添加到守护程序配置文件**。在Linux上，这个默认为`/etc/docker/daemon.json`。在Docker for Mac或Docker for Windows上，从任务栏中选择Docker图标，然后单击 **首选项** - > **守护程序** - > **高级**。

  - 使用以下JSON启用`live-restore`。

    ```json
    {
      "live-restore": true
    }
    ```

  - 重新启动Docker守护进程。在Linux上，可以通过**重新加载Docker守护程序**来**避免重新启动**（并**避免容器停机**）。如果你使用 `systemd`，然后使用命令`systemctl reload docker`。否则，发送一个 `SIGHUP`信号给`dockerd`进程。

- 如果你愿意，可以`dockerd`使用`--live-restore`选项手动启动该过程 。**不推荐**这种方法，因为它不会建立`systemd`启动Docker进程时或其他进程管理器使用的环境。这可能会**导致意外**的行为。

### 在升级期间进行实时恢复

---

实时恢复功能支持将**容器恢复到守护进程**以便从一个次要版本升级到下一个次要版本，例如从Docker 1.12.1升级到1.12.2时。

如果在升级过程中**跳过**版本，守护进程可能**无法恢复其与容器的连接**。如果守护程序无法恢复连接，则**无法管理正在运行**的容器，必须**手动停止**它们。

### 重启时进行实时恢复

---

如果守护进程选项（如网桥IP地址和图形驱动程序）未发生更改，则实时还原选项仅用于**还原容器**。如果任何这些守护程序级别的**配置选项已更改**，则实时恢复可能**不起作用**，你可能需要手动停止容器。

### 实时恢复对运行容器的影响

---

如果守护进程**长时间**关闭，正在运行的容器可能会**填满守护程序通常读取的FIFO日志**。完整的日志会**阻止**容器记录更多数据。默认缓冲区大小为**64K**。如果缓冲区填满，你**必须重新启动Docker守护程序**来刷新它们。

在Linux上，你可以通过更改修改**内核的缓冲区大小** `/proc/sys/fs/pipe-max-size`。你不能修改Docker for Mac或Docker for Windows的缓冲区大小。

### 实时恢复和集群模式

---

实时恢复选项仅适用于**独立**容器，**不适用于集群**服务。集群服务由集群管理节点管理。如果群管不可用，群服务将继续在工作节点上运行，但只有足够的群管理器可用来维护**法定节点数**时才能进行管理。

## 在容器中运行多个服务

容器的主要运行过程是`Dockerfile`末尾的`ENTRYPOINT`和/或`CMD`。通常建议通过每个容器使用一项服务来分隔关注区域。该服务可以分成**多个进程**（例如，Apache Web服务器启动多个工作进程）。可以**拥有多个进程**，但为了从Docker中获得最大效率，避免一个容器负责整个应用程序的多个方面。你可以使用**自定义的网络和共享卷**来连接多个容器。

容器的**主进程**负责管理它启动的所有进程。在某些情况下，主进程设计不好，并且在**容器退出时无法正常处理“回收”（停止）子进程**。如果你的过程属于此类别，则可以在运行容器时使用`--init`选项。这个`--init`选项**插入一个微小的`init`进程作为主进程**，并在容器**退出时处理所有进程的回收工作**。以这种方式处理这些进程**优于**使用完整的初始化进程，如`sysvinit`，`upstart`或者`systemd`来处理容器中的进程生命周期。

如果你需要在一个容器中运行多个服务，则可以通过几种不同的方式来实现：

- 将所有命令放入脚本中，并附带测试和调试信息。运行脚本作为`CMD`。脚本内容如下：

  ```sh
  #!/bin/bash
  
  # Start the first process
  ./my_first_process -D
  status=$?
  if [ $status -ne 0 ]; then
    echo "Failed to start my_first_process: $status"
    exit $status
  fi
  
  # Start the second process
  ./my_second_process -D
  status=$?
  if [ $status -ne 0 ]; then
    echo "Failed to start my_second_process: $status"
    exit $status
  fi
  
  # Naive check runs checks once a minute to see if either of the processes exited.
  # This illustrates part of the heavy lifting you need to do if you want to run
  # more than one service in a container. The container exits with an error
  # if it detects that either of the processes has exited.
  # Otherwise it loops forever, waking up every 60 seconds
  
  while sleep 60; do
    ps aux |grep my_first_process |grep -q -v grep
    PROCESS_1_STATUS=$?
    ps aux |grep my_second_process |grep -q -v grep
    PROCESS_2_STATUS=$?
    # If the greps above find anything, they exit with 0 status
    # If they are not both 0, then something is wrong
    if [ $PROCESS_1_STATUS -ne 0 -o $PROCESS_2_STATUS -ne 0 ]; then
      echo "One of the processes has already exited."
      exit 1
    fi
  done
  ```

  接下来，Dockerfile：

  ```dockerfile
  FROM ubuntu:latest
  COPY my_first_process my_first_process
  COPY my_second_process my_second_process
  COPY my_wrapper_script.sh my_wrapper_script.sh
  CMD ./my_wrapper_script.sh
  ```

- 使用`supervisord`类似的流程管理器。这是一种比较重量级的方法，要求`supervisord`在镜像中打包并配置（或将你的镜像基于包含`supervisord`的镜像）以及它所管理的不同应用程序。然后你开始`supervisord`，它为你管理你的流程。下面是Dockerfile使用这个方法的例子，它假定预先编写的`supervisord.conf`，`my_first_process`和`my_second_process`文件都在Dockerfile同一目录下存在。

  ```dockerfile
  FROM ubuntu:latest
  RUN apt-get update && apt-get install -y supervisor
  RUN mkdir -p /var/log/supervisor
  COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf
  COPY my_first_process my_first_process
  COPY my_second_process my_second_process
  CMD ["/usr/bin/supervisord"]
  ```

## 运行时指标

### `stats` 统计信息

---

可以使用`docker stats`命令**实时流式**查看容器的运行时统计数据。该命令支持CPU、内存使用情况、内存限制和网络IO度量标准。

以下是`docker stats`命令的输出示例

```sh
$ docker stats redis1 redis2
```

### `cgroup` 控制组

---

Linux Containers依赖于[控制组](https://www.kernel.org/doc/Documentation/cgroup-v1/cgroups.txt) ，这些[组](https://www.kernel.org/doc/Documentation/cgroup-v1/cgroups.txt)不仅跟踪进程组，还**公开有关CPU、内存和块IO使用情况**的度量标准。你也可以访问这些指标并获取网络使用指标。这与“纯”LXC容器以及Docker容器有关。

控制组通过**伪文件系统**公开。在最近的发行版中，你应该找到这个`/sys/fs/cgroup`文件系统。在该目录下，你会看到多个子目录，称为设备，冰柜，blkio等; 每个子目录实际上对应于不同的`cgroup`层次结构。

在较早的系统上，控制组可能会安装在`/cgroup`上，而没有明确的层次结构。在这种情况下，不是看到子目录，而是看到该目录中的一堆文件，并且可能有一些与现有容器相对应的目录。

要找到控件组的安装位置，可以运行：

```sh
$ grep cgroup /proc/mounts

cgroup /sys/fs/cgroup tmpfs rw,relatime,mode=755 0 0
cgroup /sys/fs/cgroup/cpuset cgroup rw,relatime,cpuset 0 0
cgroup /sys/fs/cgroup/cpu cgroup rw,relatime,cpu 0 0
cgroup /sys/fs/cgroup/cpuacct cgroup rw,relatime,cpuacct 0 0
cgroup /sys/fs/cgroup/blkio cgroup rw,relatime,blkio 0 0
cgroup /sys/fs/cgroup/memory cgroup rw,relatime,memory 0 0
cgroup /sys/fs/cgroup/devices cgroup rw,relatime,devices 0 0
cgroup /sys/fs/cgroup/freezer cgroup rw,relatime,freezer 0 0
cgroup /sys/fs/cgroup/net_cls cgroup rw,relatime,net_cls 0 0
cgroup /sys/fs/cgroup/perf_event cgroup rw,relatime,perf_event 0 0
cgroup /sys/fs/cgroup/net_prio cgroup rw,relatime,net_prio 0 0
cgroup /sys/fs/cgroup/hugetlb cgroup rw,relatime,hugetlb 0 0
cgroup /sys/fs/cgroup/pids cgroup rw,relatime,pids 0 0
```

#### 枚举 `cgroups`

可以查看`/proc/cgroups`以查看系统已知的不同控制组子系统，它们所属的层次结构以及它们包含的组数。

你也可以看看`/proc/<pid>/cgroup`哪些控制组属于一个进程。控制组显示为相对于层次结构安装点根的路径。`/`意味着进程尚未分配给组，同时`/lxc/pumpkin`指示该进程是名为容器的成员`pumpkin`。

```sh
docker@default:~$ cat /proc/cgroups
#subsys_name    hierarchy       num_cgroups     enabled
cpuset  1       10      1
cpu     2       10      1
cpuacct 3       10      1
blkio   4       10      1
memory  5       17      1
devices 6       10      1
freezer 7       10      1
net_cls 8       10      1
perf_event      9       10      1
net_prio        10      10      1
hugetlb 11      10      1
pids    12      10      1
```



#### 查看容器的 `cgroup`

对于每个容器，每个层次结构中创建一个`cgroup`。在较旧版本的`LXC userland`工具的旧系统上，`cgroup`的名称是容器的名称。使用更新版本的LXC工具，cgroup是`lxc/<container_name>`

对于使用`cgroup`的Docker容器，**容器名称是容器的完整ID或长ID**。如果`docker ps`容器显示为ae836c95b4c3 ，则其长ID可能与此类似 `ae836c95b4c3c9e9179e0e91015512da89fdec91612f63cebae57df9a5444c79`。你可以用`docker inspect`或查找它`docker ps --no-trunc`。

综合查看Docker容器的内存指标，请看看`/sys/fs/cgroup/memory/docker/<CONTAINER_longid>/`。

```sh
$ docker ps --no-trunc
CONTAINER ID                                                       IMAGE                     COMMAND                    CREATED             STATUS              PORTS               NAMES
cab611c4d3389254476d392da78af8b7a67ac38cc18a41e378502d4815d05e31   nginx:latest              "nginx -g 'daemon off;'"   26 hours ago        Up 26 hours         80/tcp              tmptest
8bc44d6099b5e93405495fe27f3896fc4e79a110597997883f0562b4d0ad070d   nginx:latest              "nginx -g 'daemon off;'"   43 hours ago        Up 43 hours         80/tcp              nginxtest
$ cd /sys/fs/cgroup/memory/docker/cab611c4d3389254476d392da78af8b7a67ac38cc18a41e378502d4815d05e31/
$ ls
cgroup.clone_children               memory.max_usage_in_bytes
cgroup.event_control                memory.memsw.failcnt
cgroup.procs                        memory.memsw.limit_in_bytes
memory.failcnt                      memory.memsw.max_usage_in_bytes
memory.force_empty                  memory.memsw.usage_in_bytes
memory.kmem.failcnt                 memory.move_charge_at_immigrate
memory.kmem.limit_in_bytes          memory.oom_control
memory.kmem.max_usage_in_bytes      memory.pressure_level
memory.kmem.slabinfo                memory.soft_limit_in_bytes
memory.kmem.tcp.failcnt             memory.stat
memory.kmem.tcp.limit_in_bytes      memory.swappiness
memory.kmem.tcp.max_usage_in_bytes  memory.usage_in_bytes
memory.kmem.tcp.usage_in_bytes      memory.use_hierarchy
memory.kmem.usage_in_bytes          notify_on_release
memory.limit_in_bytes               tasks
```

#### `cgroups` 指标：`MEMORY/CPU/IO`

对于每个子系统（内存，CPU和IO），存在一个或多个**伪文件**并包含统计信息。

**内存指标： `MEMORY.STAT`**

内存指标可在“内存”cgroup中找到。内存控制组添加了一点开销，因为它对**主机上的内存**使用情况进行了**非常细致**的记录。因此，许多发行版默认选择**不启用**它。一般来说，要启用它，你所要做的就是添加一些内核命令行参数：`cgroup_enable=memory swapaccount=1`。

度量标准位于伪文件中`memory.stat`。这是它的样子：

```sh
$ docker ps --no-trunc
$ cd /sys/fs/cgroup/memory/docker/cab611c4d3389254476d392da78af8b7a67ac38cc18a41e378502d4815d05e31/
$ ls
$ cat memory.stat

cache 32768
rss 1400832
rss_huge 0
mapped_file 4096
dirty 0
writeback 0
swap 0
pgpgin 816
pgpgout 466
pgfault 1119
pgmajfault 0
inactive_anon 8192
active_anon 1417216
inactive_file 8192
active_file 0
unevictable 0
hierarchical_memory_limit 9223372036854771712
hierarchical_memsw_limit 9223372036854771712
total_cache 32768
total_rss 1400832
total_rss_huge 0
total_mapped_file 4096
total_dirty 0
total_writeback 0
total_swap 0
total_pgpgin 816
total_pgpgout 466
total_pgfault 1119
total_pgmajfault 0
total_inactive_anon 8192
total_active_anon 1417216
total_inactive_file 8192
total_active_file 0
total_unevictable 0
```

前半部分（不含`total_`前缀）包含`cgroup`中进程相关的统计信息，不包括子`cgroup`。下半部分（带`total_`前缀）包含子`cgroups`。

一些指标是“量表”，或者可以增加或减少的值。例如， `swap`cgroup成员使用的交换空间量是多少。其他一些是“计数器”，或值只能上升，因为它们代表特定事件的发生。例如，`pgfault` 表示自创建`cgroup`以来的页面错误数量。

| 指标                               | 描述                                                         |
| ---------------------------------- | ------------------------------------------------------------ |
| **cache**                          | 控制组的进程使用的内存数量可以与块设备上的块精确关联。当您读取和写入磁盘上的文件时，此数量会增加。这样的话，如果你使用的“传统” IO（  `open`, `read`, `write` syscalls ），以及映射文件（含`mmap`）。它也解释了`tmpfs`挂载使用的 内存 ，但原因尚不清楚。 |
| **rss**                            | 与磁盘上的任何内容**不**对应的内存量：堆栈，堆和匿名内存映射。 |
| **mapped_file**                    | 指示控制组中的**进程映射的内存量**。它不会告诉你有*多少*内存被使用; 它会告诉你它是*如何*使用的。 |
| **pgfault**，**pgmajfault**        | 指示cgroup的进程分别触发**“页面错误”和“严重错误”**的次数。当进程访问**不存在或受保护**的虚拟内存空间时，会发生页面错误。如果进程有问题并尝试访问无效地址（它会发送一个`SIGSEGV`信号，通常使用知名的 `Segmentation fault `消息将其清除），则前者可能发生。当进程从已被换出的内存区读取或者对应于映射文件时，后者可能发生：在这种情况下，内核从磁盘加载页面，并让CPU完成内存访问。当进程写入时复制内存区域时，也可能发生这种情况：同样，内核会抢占进程，复制内存页面，并在进程自己的页面副本上恢复写入操作。内核实际需要从磁盘读取数据时发生“重大”故障。当它只是复制现有页面或分配空白页面时，它是一个常规（或“次要”）错误。 |
| **swap**                           | 此cgroup中进程当前使用的交换量。                             |
| **active_anon**，**inactive_anon** | 内核已识别的**匿名**内存数量分别**处于活动状态**和**非活动状态**。“匿名”内存是*未*链接到磁盘的内存。换句话说，这就是上述rss计数器的等价物。事实上，rss计数器的定义是**active_anon** + **inactive_anon** - **tmpfs**（其中tmpfs是用尽的内存量`tmpfs`由该控制组安装的文件系统）。现在，“主动”和“非主动”之间有什么区别？页面最初是“活动的”; 并定期将内核扫描到内存中，并将某些页面标记为“不活动”。每当他们再次访问时，他们立即被重新标记为“活跃”。当内核几乎内存不足，并且需要时间换出磁盘时，内核交换“非活动”页面。 |
| **active_file**，**inactive_file** | 高速缓冲存储器，具有与上述*匿名*存储器相似的*活动*和*非活动状态*。确切的公式是**cache** = **active_file** + **inactive_file** + **tmpfs**。内核用于在活动和非活动集之间移动内存页的确切规则与用于匿名内存的确切规则不同，但一般原则相同。当内核需要回收内存时，从该池中回收干净（=未修改）页面会更便宜，因为它可以立即回收（而匿名页面和脏/修改页面需要先写入磁盘）。 |
| **unevictable**                    | **无法回收的内存量**; 一般来说，它占用已被“锁定”的内存`mlock`。它通常被加密框架用来确保秘密密钥和其他敏感材料永远不会换出到磁盘。 |
| **memory_limit**，**memsw_limit**  | 这些并不是真正的指标，但是提醒了应用于此cgroup的限制。第一个表示该控制组的进程可以使用的**最大物理内存量**; 第二个表示**RAM +交换的最大数量**。 |

记录页面缓存中的内存非常复杂。如果不同控制组中的两个进程读取同一文件（最终依靠磁盘上的相同块），则相应的内存费用将在控制组之间分配。这很好，但这也意味着当一个cgroup被终止时，它可能会增加另一个cgroup的内存使用率，因为它们不再为这些内存页面分摊成本。

**CPU指标： `cpuacct.stat**`

现在我们已经介绍了内存指标，其他一切都比较简单。CPU指标位于 `cpuacct`控制器中。

对于每个容器，伪文件`cpuacct.stat`包含容器进程累积的CPU使用量，并分解为用户和系统时间。区别是：

- `user` 时间是**进程直接控制CPU**，执行进程代码的时间量。
- `system` 时间是**内核代表进程**执行系统调用的时间。

这些时间以1/100秒的刻度表示，也称为“user jiffies”。每秒钟有`USER_HZ` *“jiffies”*，在x86系统上 `USER_HZ`为100次。从历史上看，这恰好映射到每秒调度器“ticks”的数量，但更高的频率调度和 [无tickless内核](http://lwn.net/Articles/549580/)使得tick的数量无关紧要。

**阻止I/O指标**

IO在`blkio`控制器中计入。不同的指标分散在不同的文件中。虽然你可以在 内核文档的[blkio-controller](https://www.kernel.org/doc/Documentation/cgroup-v1/blkio-controller.txt)文件中找到详细的详细信息，但[下面](https://www.kernel.org/doc/Documentation/cgroup-v1/blkio-controller.txt)是一些最相关的列表：

| 公                         | 描述                                                         |
| -------------------------- | ------------------------------------------------------------ |
| **blkio.sectors**          | 包含由cgroup的进程成员逐个设备读取和写入的512字节**扇区数**。读取和写入被合并在一个计数器中。 |
| **blkio.io_service_bytes** | 指示由cgroup读取和写入的**字节数**。它每个设备有4个计数器，因为对于每个设备，它区分同步I/O和异步I/O，以及读取与写入。 |
| **blkio.io_serviced**      | 不论其大小如何，执行的**I/O操作的数量**。它也有每个设备4个计数器。 |
| **blkio.io_queued**        | 指示当前为此cgroup**排队的I/O操作的数量**。换句话说，如果cgroup没有执行任何I/O操作，则该值为零。相反是不正确的。换句话说，如果没有排队的I/O，这并不意味着cgroup是空闲的（I/O方式）。它可以在静态设备上进行纯粹的同步读取，因此可以立即处理它们，而无需排队。此外，尽管找出哪个cgroup正在对I/O子系统施加压力是有帮助的，但请记住它是一个相对数量。即使进程组没有执行更多的I/O，其队列大小也会因为其他设备的负载增加而增加。 |

### `network`  统计信息

---

网络指标不直接由控制组公开。有一个很好的解释：网络接口存在于**网络命名空间**的上下文中。内核可能会累积有关一组进程发送和接收的数据包和字节的衡量标准，但这些衡量标准不会很有用。你需要每个接口的衡量标准（因为在本地`lo`接口上发生的流量并不真正计数）。但是由于单个`cgroup`中的进程可能属于多个网络名称空间，因此这些衡量标准很难解释：多个网络名称空间意味着多个`lo` 接口，可能包含多个`eth0` 接口等; 所以这就是为什么没有简单的方法来收集控制组的网络指标。但是，我们可以从其他来源收集网络指标。

#### IPTABLES

IPtables（或者说，iptables只是一个接口的`netfilter`框架）可以做一些严肃的统计。

例如，可以设置一个规则来解释Web服务器上的HTTP流量：

```sh
$ iptables -I OUTPUT -p tcp --sport 80
```

没有`-j`或`-g`选项，所以规则只计算匹配的数据包并转到以下规则。

稍后，你可以检查计数器的值，具体如下：

```sh
$ iptables -nxvL OUTPUT
```

从技术上讲，`-n`并不是必需的，但它阻止iptables进行DNS反向查找，在这种情况下这可能没有用处。

计数器包括**数据包和字节**。如果你想为此类容器流量设置衡量标准，则可以执行一个`for` 循环以`iptables`在`FORWARD`链中为每个容器IP地址（每个方向一个）添加两条规则。这只会测量通过NAT层的流量，你还需要添加通过用户级代理的流量。然后，你需要定期检查这些统计信息。如果你碰巧使用`collectd`，有一个[很好的插件](https://collectd.org/wiki/index.php/Table_of_Plugins) 来自动化iptables计数器集合。

#### 接口级计数器

由于每个容器都有一个**虚拟以太网接口**，因此你可能需要直接检查该接口的**TX和RX**计数器。每个容器都与主机中的虚拟以太网接口关联，并带有类似的名称`vethKk8Zqi`。找出哪个接口对应于哪个容器是非常困难的。

但是现在，最好的方法是**从容器中**检查指标。为了达到这个目的，你可以使用**ip-netns magic**在容器的网络命名空间内的主机环境中**运行一个可执行文件**。

`ip-netns exec`命令允许你在当前进程可见的任何网络名称空间内**执行任何程序**（存在于主机系统中）。这意味着你的主机可以访问你的容器的网络名称空间，但你的容器无法访问主机或其他对等容器。尽管如此，**容器可以与其子容器**进行交互。

命令的确切格式是：

```sh
$ ip netns exec <nsname> <command...>
```

例如：

```sh
$ ip netns exec mycontainer netstat -i
```

`ip netns`通过使用命名空间伪文件找到“mycontainer”容器。每个进程属于一个网络名称空间，一个PID名称空间，一个`mnt`名称空间等，并且这些名称空间在下面具体化 `/proc/<pid>/ns/`。例如，PID 42的网络名称空间由伪文件实现`/proc/42/ns/net`。

运行时`ip netns exec mycontainer ...`，它期望`/var/run/netns/mycontainer`成为这些伪文件之一。换句话说，要在容器的网络名称空间内执行命令，我们需要：

- 找出我们想要统计查看的容器内的任何进程的PID;
- 从创建一个符号链接`/var/run/netns/<somename>`到`/proc/<thepid>/ns/net`
- 执行 `ip netns exec <somename> ....`

查看[枚举Cgroups](https://docs.docker.com/config/containers/runmetrics/#enumerate-cgroups)以了解如何查找要测量其网络使用情况的容器内过程的cgroup。从那里，你可以检查名为的伪文件`tasks`，其中包含cgroup中的所有PID（因此包含在容器中）。选择任何一个PID。

把所有的东西放在一起，如果一个容器的“短ID”保存在环境变量中`$CID`，那么你可以这样做：

```sh
$ TASKS=/sys/fs/cgroup/devices/docker/$CID*/tasks
$ PID=$(head -n 1 $TASKS)
$ mkdir -p /var/run/netns
$ ln -sf /proc/$PID/ns/net /var/run/netns/$CID
$ ip netns exec $CID netstat -i
```

#### 高性能指标收集技巧

每次想要更新指标时运行一个新流程都相当昂贵。如果你想要以高效率或通过大量容器收集度量标准（将单个主机上的容器想成1000个），则不需要每次都开辟一个新进程。

以下是如何从单个流程收集指标。你需要使用C语言编写公制收集器（或任何允许执行低级别系统调用的语言）。你需要使用一个特殊的系统调用， `setns()`它允许当前进程输入任意的命名空间。然而，它需要一个打开的文件描述符到命名空间伪文件（记住：这是伪文件 `/proc/<pid>/ns/net`）。

然而，有一个问题：你不能保持这个文件描述符打开。如果这样做，当控制组的最后一个进程退出时，名称空间不会被销毁，并且其网络资源（如容器的虚拟接口）**永远停留**（或直到关闭该文件描述符）。

**正确的做法是跟踪每个容器的第一个PID，并且每次重新打开命名空间伪文件。**

#### 在容器退出时收集指标

有时候，你不关心实时指标收集，但是当一个容器退出时，你想知道它使用了多少CPU，内存等。Docker使它变得困难，因为它依赖于`lxc-start`，在它之后仔细清理自己。定期收集指标通常更容易，这就是`collectd`LXC插件的工作方式。

但是，如果你仍想在容器停止时收集统计信息，请执行以下操作：

对于每个容器，**启动一个收集过程**，并通过将其**PID写入cgroup的任务**文件，将其移至要监控的控制组。收集过程应定期重新读取任务文件以检查它是否是控制组的最后一个过程。（如果你还想按前一节中的说明收集网络统计信息，则还应该将过程移至适当的网络名称空间。）

当容器退出时，`lxc-start`试图删除控制组。它失败了，因为控制组仍在使用中。但没关系。现在你的过程应该检测到它是该组中剩下的唯一一个。现在是收集你需要的所有指标的适当时机！

最后，你的过程应该移回到根控制组，并删除容器控制组。删除一个控制组，只是 `rmdir`它的目录。`rmdir`由于它仍然包含文件，因此它对目录不直观 ; 但请记住这是一个伪文件系统，所以通常的规则不适用。清理完成后，收集过程可以安全地退出。 

# 限制容器的资源

默认情况下，容器没有限制资源，可以使用**主机内核调度程序允许的给定资源**。Docker提供了一些方法来控制容器可以使用多少内存、CPU、IO，并设置`docker run`命令的运行时配置选项。

许多这些功能需要你的内核支持Linux功能。要检查支持，可以使用 [`docker info`](https://docs.docker.com/engine/reference/commandline/info/)命令。如果在内核中禁用了某个功能，则可能会在输出结尾看到类似以下内容的警告：

```sh
WARNING: No swap limit support
```

## 内存

### 了解耗尽内存的风险

---

重要的是**不要让正在运行的容器消耗太多的主机内存**。在Linux主机上，如果内核检测到没有足够的内存来执行重要的系统功能，它会抛出一个`OOME`或者 `Out Of Memory Exception`，然后开始**查杀进程**以释放内存。**任何进程都会遭到杀戮**，包括Docker和其他重要应用程序。如果进程被错误的杀死，这可能使**整个系统停机**。

Docker尝试通过调整Docker守护进程的OOM**优先级**来降低这些风险，从而不会比系统上的其他进程提早死亡。OOM容器优先级不调整，这使得**单个容器被杀死的可能性要大于Docker守护进程**或其他系统进程被终止的可能性。不应该通过手动设置`--oom-score-adj`守护进程或容器上的极端负数或通过设置容器`--oom-kill-disable`来绕过这些安全措施。

有关Linux内核的OOM管理的更多信息，请参阅 [内存不足管理](https://www.kernel.org/doc/gorman/html/understand/understand016.html)。

可以通过以下方式减轻由OOME引起的系统不稳定风险：

- 在投入生产之前，**执行测试**以了解应用程序的**内存需求**。
- 确保应用程序仅在具有**足够资源**的主机上运行。
- **限制容器可以使用的内存量**，如下所述。
- 在Docker主机上**配置交换**时请注意。**交换比内存更慢，性能更低**，但可以提供**缓冲区**以防系统内存耗尽。
- 考虑将容器转换为[服务](https://docs.docker.com/engine/swarm/services/)，并使用服务级别**约束和节点标签**来确保应用程序仅在具有**足够内存**的主机上运行

### 限制容器对内存的访问

---

Docker可以实施**硬内存限制**，允许容器使用**不超过给定数量的用户或系统内存或软限制**，这允许容器使用尽可能多的内存，除非满足某些条件，例如何时内核检测到内存不足或主机上的争用。其中一些选项在单独使用或设置了多个选项时会有不同的效果。

大部分的选项取正整数，单位表示字节，千字节，兆字节或千兆字节。

| 选项                   | 描述                                                         |
| ---------------------- | ------------------------------------------------------------ |
| `-m`  或 `--memory=`   | 容器可以使用的**最大内存**量。如果您设置此选项，则允许的最小值为`4m`（4兆字节）。 |
| `--memory-swap`*       | 此容器允许**交换到磁盘的内存量**。查看[`--memory-swap`详情](https://docs.docker.com/config/containers/resource_constraints/#--memory-swap-details)。 |
| `--memory-swappiness`  | 默认情况下，主机内核可以**交换容器使用的匿名页面**的百分比。您可以将其设置`--memory-swappiness`为0到100之间的值，以调整此百分比。查看[`--memory-swappiness`详情](https://docs.docker.com/config/containers/resource_constraints/#--memory-swappiness-details)。 |
| `--memory-reservation` | 允许指定一个**软限制**，它小于`--memory`。Docker在主机上检测到**争用或内存不足**时所激活的软限制。如果使用`--memory-reservation`，则必须设置为优先低于`--memory`。因为它是一个软限制，它并**不能保证容器不会超出限制**。 |
| `--kernel-memory`      | 容器可以使用的**最大内核内存量**。允许的最小值是`4m`。由于**内核内存不能被换出**，因此内核内存不足的容器可能会**阻塞主机资源**，这可能会对主机和其他容器产生副作用。查看[`--kernel-memory`详情](https://docs.docker.com/config/containers/resource_constraints/#--kernel-memory-details)。 |
| `--oom-kill-disable`   | 默认情况下，如果发生内存不足（OOM）错误，**内核会杀死容器中的进程**。要更改此行为，请使用`--oom-kill-disable`选项。只有在设置`-m/--memory`选项的容器上**禁用OOM杀手**。如果`-m`标志未设置，主机可能会**耗尽内存**，内核可能需要**终止主机系统的进程**以释放内存。 |

有关cgroups和内存的更多信息，请参阅[内存资源控制器](https://www.kernel.org/doc/Documentation/cgroup-v1/memory.txt)的文档。

#### `--memory-swap` 细节

`--memory-swap`是一个修饰符选项，只有在`--memory`设置时才有意义。使用**交换允许容器将多余的内存需求写入磁盘**，当容器**耗尽**了可用的所有RAM时。对于经常将内存交换到磁盘的应用程序会有**性能损失**。

其设置可能会产生复杂的效果：

- 如果`--memory-swap`设置为正整数，那么这两个`--memory`和 `--memory-swap`必须设置。`--memory-swap`表示可以使用的**内存和交换总量**，以及`--memory`控制非交换内存使用的数量 。所以，如果`--memory="300m"`和`--memory-swap="1g"`，容器可以使用300M的内存和700M（`1g - 300m`）交换。
- 如果`--memory-swap`设置为`0`，则忽略该设置，并将该值视为未设置。
- 如果`--memory-swap`设置为与其相同的值`--memory`并`--memory`设置为正整数，则**该容器无权访问交换**。请参阅[防止容器使用交换](https://docs.docker.com/config/containers/resource_constraints/#prevent-a-container-from-using-swap)。
- 如果`--memory-swap`未设置，并且已设置`--memory`，则如果主容器已配置交换内存，则容器可以使用两倍于`--memory`设置的交换。举例来说，如果`--memory="300m"`并`--memory-swap`没有设置，容器可以使用的内存300M和交换600M。
- 如果`--memory-swap`明确设置为`-1`，则允许容器使用**无限制**交换，直至主机系统上可用的数量。

**防止容器使用交换**

如果`--memory`和`--memory-swap`设置为相同的值，则会**阻止容器使用任何交换**。这是因为`--memory-swap`可以使用的组合内存和交换量，而`--memory`只是可以使用的物理内存量。

### `--memory-swappiness` 细节

- 值为0将**关闭匿名**页面交换。
- 值为100将**所有**匿名页面设置为可交换。
- 默认情况下，如果未设置`--memory-swappiness`，则该值将从**主机继承**。

### `--kernel-memory` 细节

**内核内存**限制以分配给容器的全部内存表示。考虑以下情况：

- **无限的内存，无限的内核内存**：这是默认行为。
- **无限的内存，有限的内核内存**：当所有cgroup所需的内存量大于主机上实际存在的内存量时，这是合适的。你可以将内核内存配置为永远不会覆盖主机上可用的内容，而需要更多内存的容器需要等待它。
- **有限的内存，无限的内核内存**：整体内存有限，但内核内存不足。
- **内存有限，内核内存有限**：限制用户内核和内核内存对**调试内存**相关问题可能很有用。如果某个容器使用的是任意类型的内存，则会导致内存不足而不会影响其他容器或主机。在此设置下，如果**内核内存限制低于用户内存限制，则内核内存用尽会导致容器遇到OOM错误**。如果内核内存限制高于用户内存限制，则内核限制不会导致容器体验OOM。

当打开任何内核内存限制时，主机会在每个进程的基础上跟踪“高段位”统计信息，以便可以跟踪哪些进程（在这种情况下是容器）正在使用超出的内存。通过`/proc/<PID>/status`在主机上查看，每个进程都可以看到这一点。

## CPU

默认情况下，每个容器对主机CPU周期的访问是无限的。可以设置各种**约束**来限制给定容器**访问主机的CPU周期**。大多数用户使用和配置 [默认的CFS调度程序](https://docs.docker.com/config/containers/resource_constraints/#configure-the-default-cfs-scheduler)。在Docker 1.13及更高版本中，你还可以配置 [实时调度程序](https://docs.docker.com/config/containers/resource_constraints/#configure-the-realtime-scheduler)。

### 配置默认的CFS调度程序

---

**CFS是用于普通Linux进程的Linux内核CPU调度**程序。几个运行时间选项允许配置容器的CPU资源**访问量**。当使用这些设置时，Docker会修改**主机上容器cgroup的设置**。

| 选项                   | 描述                                                         |
| ---------------------- | ------------------------------------------------------------ |
| `--cpus=<value>`       | 指定容器可以**使用多少可用CPU资源**。例如，如果主机有两个CPU并且设置`--cpus="1.5"`，则该容器最多可以保证一个半的CPU。这相当于设置`--cpu-period="100000"`和`--cpu-quota="150000"`。在Docker 1.13和更高版本中可用。 |
| `--cpu-period=<value>` | 指定CPU **CFS调度程序周期**，该周期与`--cpu-quota`一起使用。默认为100微秒。大多数用户不会从默认值更改此设置。如果您使用Docker 1.13或更高版本，请改用--cpus。 |
| `--cpu-quota=<value>`  | 在容器上添加CPU CFS配额。每个`--cpu-period`允许CPU访问的**容器数微秒数:** `cpu-quota` / `cpu-period`。如果您使用Docker 1.13或更高版本，请改用--cpus。 |
| `--cpuset-cpus`        | 限制容器可以使用的**特定CPU或核心**。如果有多个CPU，则容器可以使用的逗号分隔列表或连字符分隔的CPU范围。第一个CPU编号为0，有效值可能是`0-3`（使用第一，第二，第三和第四个CPU）或`1,3`（使用第二个和第四个CPU）。 |
| `--cpu-shares`         | 将此标志设置为**大于或小于默认值1024**的值，以**增加或减少容器的重量**，并使其能够访问主机CPU周期的更大或更小比例。这仅在CPU周期受到限制时才会执行。当大量CPU周期可用时，所有容器都使用尽可能多的CPU。这样，这是一个软限制。`--cpu-shares`不会阻止容器在群集模式下进行调度。它优先考虑容器CPU资源的可用CPU周期。它不保证或保留任何特定的CPU访问权限。 |

如果你有1个CPU，则以下每个命令都可以保证容器每秒钟最多有50％的CPU。

**Docker 1.13及更高版本**：

```sh
$ docker run -it --cpus=".5" ubuntu /bin/bash
```

**Docker 1.12及更低版本**：

```sh
$ docker run -it --cpu-period=100000 --cpu-quota=50000 ubuntu /bin/bash
```

### 配置实时调度程序

---

在Docker 1.13及更高版本中，可以将容器配置为使用**实时调度**程序，以用于无法使用CFS调度程序的任务。 在[配置Docker守护进程](https://docs.docker.com/config/containers/resource_constraints/#configure-the-docker-daemon)或 [配置单个容器](https://docs.docker.com/config/containers/resource_constraints/#configure-individual-containers)之前，你需要 [确保主机的内核配置正确](https://docs.docker.com/config/containers/resource_constraints/#configure-the-host-machines-kernel)。

> **警告**：CPU调度和优先级是高级内核级功能。大多数用户不需要从默认值更改这些值。错误地设置这些值会导致主机系统变得**不稳定或不可用**。

#### 配置主机的内核

验证在Linux内核中启用了`CONFIG_RT_GROUP_SCHED`，方法是运行`zcat /proc/config.gz | grep CONFIG_RT_GROUP_SCHED`或通过检查文件`/sys/fs/cgroup/cpu.rt_runtime_us`的存在。有关配置内核实时调度程序的指导，请参阅操作系统的文档。

#### 配置DOCKER守护进程

要使用实时调度程序运行容器，请运行Docker守护程序，并将`--cpu-rt-runtime`选项设置为每个运行时期为实时任务保留的**最大微秒数**。例如，默认周期为1000000微秒（1秒），设置`--cpu-rt-runtime=950000`可确保使用实时调度程序的容器可以每1000000微秒周期运行950000微秒，并为非实时任务留出至少50000微秒的可用时间。要在使用的系统上使此配置保持永久 `systemd`，请参阅[使用systemd控制和配置Docker](https://docs.docker.com/config/daemon/systemd/)。

**配置单个容器**

当`docker run`启动容器时，可以传递多个选项来控制容器的CPU优先级。有关`ulimit`适当值的信息，请查阅操作系统的文档或命令。

| 选项                       | 描述                                                         |
| -------------------------- | ------------------------------------------------------------ |
| `--cap-add=sys_nice`       | 向容器授予容器的`CAP_SYS_NICE`功能，该功能允许容器提高过程`nice`值，设置**实时调度策略**，设置CPU关联和其他操作。 |
| `--cpu-rt-runtime=<value>` | 容器可以在Docker守护进程的实时调度程序期间以**实时优先级**运行的最大微秒数。你还需要`--cap-add=sys_nice`。 |
| `--ulimit rtprio=<value>`  | 容器允许的**最大实时优先级**。你还需要`--cap-add=sys_nice`。 |

以下示例命令在`debian:jessie` 容器上设置这三个选项中的每一个。

```
$ docker run --it --cpu-rt-runtime=950000 \
                  --ulimit rtprio=99 \
                  --cap-add=sys_nice \
                  debian:jessie
```

如果内核或Docker守护进程未正确配置，则会发生错误。

# docker 日志配置

## 查看容器或服务的日志

`docker logs`命令显示**正在运行的容器**日志的信息。 `docker service logs`命令显示参与**服务的所有容器**日志的信息。日志的信息和日志的格式几乎完全取决于容器的端点命令。

默认情况下，`docker logs`或者`docker service logs`命令的输出，就像在终端中以交互方式运行命令一样。UNIX和Linux命令通常开在运行时间上三个IO流，所谓的 `STDIN`，`STDOUT`和`STDERR`。`STDIN`是命令的**输入**流，可能包括来自键盘的输入或来自另一个命令的输入。`STDOUT`通常是命令的正常**输出**，`STDERR`通常用于**输出错误**消息。默认情况下，`docker logs`显示命令的`STDOUT`和 `STDERR`。要阅读有关IO和Linux的更多信息，请参阅[有关I / O重定向](http://www.tldp.org/LDP/abs/html/io-redirection.html)的[Linux文档项目文章](http://www.tldp.org/LDP/abs/html/io-redirection.html)。

在某些情况下，除非采取其他措施，否则`docker logs`可能不会显示有用信息。

- 如果使用将[日志](https://docs.docker.com/config/containers/logging/configure/)发送到文件的[日志驱动程序](https://docs.docker.com/config/containers/logging/configure/)，则外部主机，数据库或另一个日志后端`docker logs`可能不会显示有用的信息。
- 如果镜像运行非交互式进程（如Web服务器或数据库），则应用程序可能会将其输出发送到**日志文件**而不是`STDOUT` 和`STDERR`。

在第一种情况下，日志以其他方式处理，可以选择不使用`docker logs`。在第二种情况下，官方`nginx`镜像显示了一种解决方法，并且官方Apache `httpd`镜像显示了另一种解决方法。

官方`nginx`镜像，从创建文件链接 `/dev/stdout`到`/var/log/nginx/access.log`，从创建另一个文件链接`/dev/stderr`到`/var/log/nginx/error.log`，覆盖日志文件，并导致日志而不是发送到相关的专用设备。请参阅[Dockerfile](https://github.com/nginxinc/docker-nginx/blob/8921999083def7ba43a06fabd5f80e4406651353/mainline/jessie/Dockerfile#L21-L23)。

官方`httpd`驱动程序更改`httpd`应用程序的配置，将其正常输出直接写入`/proc/self/fd/1`（是`STDOUT`），并将其错误写入`/proc/self/fd/2`（它是`STDERR`）。请参阅 [Dockerfile](https://github.com/docker-library/httpd/blob/b13054c7de5c74bbaa6d595dbe38969e6d4f860c/2.2/Dockerfile#L72-L75)。

## 配置日志驱动

Docker包含多种日志记录机制来帮助你 [从运行容器和服务中获取信息](https://docs.docker.com/engine/admin/logging/view_container_logs/)。这些机制被称为日志驱动程序。

每个Docker守护进程都有一个默认日志驱动程序，每个容器使用该驱动程序，除非你将其配置为使用其他日志记录驱动程序

除了使用Docker附带的日志驱动程序之外，你还可以实现和使用[日志驱动程序插件](https://docs.docker.com/engine/admin/logging/plugins/)。记录驱动程序插件在Docker 17.05和更高版本中可用。

### 配置默认日志驱动

---

要将Docker守护程序**配置为默认为特定的日志驱动**程序，请将`log-driver`的值设置为`daemon.json`文件中的日志驱动程序的名称，该文件位于Linux主机上的`/etc/docker/`目录或Windows服务器主机上的`C:\ProgramData\docker\config\`。默认的日志记录驱动程序是`json-file`。以下示例显式地将默认日志记录驱动程序设置为`syslog`：

```json
{
  "log-driver": "syslog"
}
```

如果日志驱动程序具有可配置的选项，则可以使用该键将它们作为JSON数组设置在 `daemon.json`文件中`log-opts`。以下示例在`json-file`日志记录驱动程序上设置两个可配置选项：

```json
{
  "log-driver": "json-file",
  "log-opts": {
    "labels": "production_status",
    "env": "os,customer"
  }
}
```

如果你**不指定日志驱动**程序，则**默认为`json-file`**。因此，诸如`docker inspect <CONTAINER>`JSON之类的命令的默认输出。

要查找Docker守护程序的当前默认日志记录驱动程序，请运行 `docker info`并搜索`Logging Driver`。可以在Windows上的Linux，macOS或PowerShell上使用以下命令：

```sh
$ docker info | grep 'Logging Driver'

Logging Driver: json-file
```

### 配置容器的日志驱动

---

在启动容器时，可以使用`--log-driver`选项将其配置为使用与Docker守护程序默认值不同的日志驱动程序。如果日志驱动程序具有可配置选项，则可以使用`--log-opt <NAME>=<VALUE>`选项的一个或多个实例来设置它们。即使容器使用默认的日志驱动程序，它也可以使用不同的可配置选项。

以下示例使用`none`日志驱动程序启动Alpine容器。

```sh
$ docker run -it --log-driver none alpine ash
```

要查找正在运行的容器的当前日志驱动程序，如果守护程序正在使用`json-file`日志驱动程序，请运行以下`docker inspect` 命令，将容器名称或ID替换为`<CONTAINER>`：

```sh
$ docker inspect -f '{{.HostConfig.LogConfig.Type}}' <CONTAINER>
json-file
```

#### 配置容器到日志驱动程序的日志传送模式

Docker提供了两种从容器向日志驱动程序传递消息的模式：

- （默认）直接**阻止从容器到驱动程序的交互**
- 非阻塞交互，将日志消息存储在中间每个容器的**环形缓冲区**中供驱动程序使用

`non-blocking `传送模式可**防止应用程序**因日志反压而被阻塞。当`STDERR`或`STDOUT`流阻塞时，应用程序可能会以意想不到的方式失败。

> **警告**：当缓冲区**已满**且新消息排**入队列**时，内存中**最早的消息将被丢弃**。丢弃消息通常首选阻止应用程序的日志写入过程。

在`mode`日志选项控制是否使用`blocking`（默认）或`non-blocking`消息传递。

`max-buffer-size`日志选项控制用于中间消息存储在**环形缓冲区**的大小`mode`被设置为`non-blocking`。`max-buffer-size`默认为1兆字节。

以下示例以非阻塞模式和4兆字节缓冲区启动日志输出的Alpine容器：

```sh
$ docker run -it --log-opt mode=non-blocking --log-opt max-buffer-size=4m alpine ping 127.0.0.1
```

#### 使用环境变量或标签与日志驱动程序

一些日志记录驱动程序将容器的一个`--env|-e`或多个`--label`的值添加到容器的日志中。本示例使用Docker守护进程的默认日志记录驱动程序启动容器（假设`json-file`），但设置环境变量`os=ubuntu`。

```sh
$ docker run -dit --label production_status=testing -e os=ubuntu alpine sh
```

如果日志记录驱动程序支持它，则会向日志输出添加其他字段。以下输出由`json-file`日志驱动程序生成：

```sh
"attrs":{"production_status":"testing","os":"ubuntu"}
```

### 支持的日志驱动

---

支持以下日志记录驱动程序。如果适用，请参阅每个驱动程序文档的链接以了解其可配置选项。如果你使用的是 [日志驱动程序插件](https://docs.docker.com/engine/admin/logging/plugins/)，则可能会看到更多选项。

| 驱动                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| `none`                                                       | 没有日志可用于容器，`docker logs`并且不返回任何输出。        |
| [`json-file`](https://docs.docker.com/config/containers/logging/json-file/) | 日志格式为JSON。Docker的默认日志记录驱动程序。               |
| [`syslog`](https://docs.docker.com/config/containers/logging/syslog/) | 将日志消息写入`syslog`设施。该`syslog`守护程序必须在主机上运行。 |
| [`journald`](https://docs.docker.com/config/containers/logging/journald/) | 将日志消息写入`journald`。该`journald`守护程序必须在主机上运行。 |
| [`gelf`](https://docs.docker.com/config/containers/logging/gelf/) | 将日志消息写入Graylog扩展日志格式（GELF）端点，如Graylog或Logstash。 |
| [`fluentd`](https://docs.docker.com/config/containers/logging/fluentd/) | 将日志消息写入`fluentd`（正向输入）。该`fluentd`守护程序必须在主机上运行。 |
| [`awslogs`](https://docs.docker.com/config/containers/logging/awslogs/) | 将日志消息写入Amazon CloudWatch Logs。                       |
| [`splunk`](https://docs.docker.com/config/containers/logging/splunk/) | 将日志消息写入`splunk`使用HTTP事件收集器。                   |
| [`etwlogs`](https://docs.docker.com/config/containers/logging/etwlogs/) | 将日志消息写为Windows事件跟踪（ETW）事件。仅在Windows平台上可用。 |
| [`gcplogs`](https://docs.docker.com/config/containers/logging/gcplogs/) | 将日志消息写入Google Cloud Platform（GCP）日志记录。         |
| [`logentries`](https://docs.docker.com/config/containers/logging/logentries/) | 将日志消息写入Rapid7 Logentries。                            |

## 使用日志驱动插件

Docker日志插件允许**扩展和定制**Docker的日志记录功能，超越了[内置日志记录驱动程序的功能](https://docs.docker.com/config/containers/logging/configure/)。日志服务提供者可以[实现他们自己的插件，](https://docs.docker.com/engine/extend/plugins_logging/)并在Docker Hub，Docker Store或私有注册表中使用它们。

### 安装日志驱动插件

要安装日志驱动程序插件，请使用`docker plugin install <org/image>`插件开发人员提供的信息。可以使用列出所有已安装的插件`docker plugin ls`，并且可以使用`docker inspect`检查特定的插件。

### 将插件配置为默认的日志驱动

插件安装完成后，可以通过`daemon.json`将插件名称设置为`logging-driver` 的值，将Docker守护程序配置为默认值，详见 [日志概述](https://docs.docker.com/config/containers/logging/configure/#configure-the-default-logging-driver)。如果日志记录驱动程序支持其他选项，则可以将它们设置为`log-opts`同一文件中数组的值。

### 配置容器以使用插件作为日志驱动

在插件安装完成后，可以通过`docker run`指定`--log-driver`标记来配置容器以使用该插件作为日志记录驱动程序，详细信息请参见 [日志记录概述](https://docs.docker.com/config/containers/logging/configure/#configure-the-logging-driver-for-a-container)。如果日志记录驱动程序支持其他选项，则可以使用一个或多个`--log-opt`选项来指定它们，其中选项名称为键，选项值为值。

## 自定义日志驱动输出

在日志选项指定如何格式化标识容器的日志信息的标签`tag`。默认情况下，系统使用容器标识的前12个字符。要覆盖此行为，请指定一个`tag`选项：

```sh
$ docker run --log-driver=fluentd --log-opt fluentd-address=myhost.local:24224 --log-opt tag="mailer" alpine ping 127.0.0.1

$ docker run -it --log-driver=syslog --log-opt tag="{{.ImageName}}/{{.Name}}/{{.ID}}" alpine ping 127.0.0.1
```

在指定标签值时，Docker支持一些特殊的模板标记：

| 标记               | 描述                         |
| ------------------ | ---------------------------- |
| `{{.ID}}`          | 容器ID的前12个字符。         |
| `{{.FullID}}`      | 完整的容器ID。               |
| `{{.Name}}`        | 容器名称。                   |
| `{{.ImageID}}`     | 容器图像ID的前12个字符。     |
| `{{.ImageFullID}}` | 容器的完整图像ID。           |
| `{{.ImageName}}`   | 容器使用的图像的名称。       |
| `{{.DaemonName}}`  | 码头程序的名称（`docker`）。 |

例如，指定一个`--log-opt tag="{{.ImageName}}/{{.Name}}/{{.ID}}"`值会生成如下所示的`syslog`日志行：

```sh
Aug  7 18:33:19 HOSTNAME hello-world/foobar/5790672ab6a0[9103]: Hello from Docker.
```

在启动时，系统设置`container_name`字段并`{{.Name}}`在标签中。如果使用`docker rename`重命名容器，则新名称不会反映在日志消息中。而是，这些消息继续使用原始容器名称。

## 日志驱动使用详解

### `json` 日志驱动

---

默认情况下，Docker捕获所有容器的标准输出（和标准错误），并使用JSON格式将它们写入文件。JSON格式用每个行的原点（`stdout`或`stderr`）及其时间戳注释。每个日志文件都包含只有一个容器的信息。

#### 用法

要将`json-file`驱动程序用作默认日志记录驱动程序，请将该键`log-driver` 和`log-opt`键设置`daemon.json`为位于`/etc/docker/`Linux主机或`C:\ProgramData\docker\config\daemon.json`Windows Server 上 的文件中的适当值。有关使用Docker配置的更多信息`daemon.json`，请参阅 [daemon.json](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)。

以下示例将日志驱动程序`json-file`设置为并设置该`max-size` 选项。

```json
{
  "log-driver": "json-file",
  "log-opts": {
    "max-size": "10m"
  }
}
```

重新启动Docker，以使更改对新创建的容器生效。现有容器不使用新的日志记录配置。

你可以通过使用`docker container create`或`docker run`的`--log-driver`选项来设置特定容器的日志记录驱动程序：

```sh
$ docker run \
      --log-driver json-file --log-opt max-size=10m \
      alpine echo hello world    
```

#### 选项

`json-file`记录驱动程序支持以下日志记录选项：

| 选项        | 描述                                                         | 示例值                                   |
| ----------- | ------------------------------------------------------------ | ---------------------------------------- |
| `max-size`  | 滚动前日志的最大大小。一个正整数加上代表测量单位的改性剂（`k`，`m`，或`g`）。默认为-1（无限制）。 | `--log-opt max-size=10m`                 |
| `max-file`  | 可以存在的最大日志文件数量。如果滚动日志会创建多余的文件，最旧的文件将被删除。**只有在max-size设置时才有效。**一个正整数。默认为1。 | `--log-opt max-file=3`                   |
| `labels`    | 在启动Docker守护进程时适用。守护进程接受的日志相关标签的逗号分隔列表。用于高级[日志标记选项](https://docs.docker.com/config/containers/logging/log_tags/)。 | `--log-opt labels=production_status,geo` |
| `env`       | 在启动Docker守护进程时适用。此守护程序接受的与日志相关的环境变量的逗号分隔列表。用于高级[日志标记选项](https://docs.docker.com/config/containers/logging/log_tags/)。 | `--log-opt env=os,customer`              |
| `env-regex` | 类似于并兼容`env`。一个正则表达式来匹配与日志相关的环境变量。用于高级[日志标记选项](https://docs.docker.com/config/containers/logging/log_tags/)。 | `--log-opt env-regex=^(os|customer).`    |

#### 例子

这个例子启动一个`alpine`容器，每个容器最多可以有3个不超过10兆字节的日志文件。

```
$ docker run -it --log-opt max-size=10m --log-opt max-file=3 alpine ash
```

### `syslog` 日志驱动

---

`syslog`日志记录驱动程序将日志路由到`syslog`服务器。`syslog`协议使用原始字符串作为日志消息并支持一组有限的元数据。系统日志消息必须以特定方式格式化才能生效。从有效的消息中，接收者可以提取以下信息：

- **优先级**：日志记录级别，如`debug`，`warning`，`error`，`info`。
- **时间戳**：事件发生的时间。
- **主机名**：事件发生的地方。
- **设施**：哪个子系统记录了消息，例如`mail`或`kernel`。
- **进程名称**和**进程ID（PID）**：生成日志的进程的名称和ID。

格式在[RFC 5424中](https://tools.ietf.org/html/rfc5424)定义，Docker的syslog驱动程序按以下方式实现 [ABNF引用](https://tools.ietf.org/html/rfc5424#section-6)：

```
                TIMESTAMP SP HOSTNAME SP APP-NAME SP PROCID SP MSGID
                    +          +             +           |        +
                    |          |             |           |        |
                    |          |             |           |        |
       +------------+          +----+        |           +----+   +---------+
       v                            v        v                v             v
2017-04-01T17:41:05.616647+08:00 a.vm {taskid:aa,version:} 1787791 {taskid:aa,version:}
```

#### 用法

要将`syslog`驱动程序用作默认日志记录驱动程序，请将该键`log-driver` 和`log-opt`键设置`daemon.json`为位于`/etc/docker/`Linux主机或`C:\ProgramData\docker\config\daemon.json`Windows Server 上 的文件中的适当值。有关使用Docker配置的更多信息`daemon.json`，请参阅 [daemon.json](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)。

以下示例将日志驱动程序`syslog`设置为并设置该 `syslog-address`选项。

```json
{
  "log-driver": "syslog",
  "log-opts": {
    "syslog-address": "udp://1.2.3.4:1111"
  }
}
```

重新启动Docker以使更改生效。

> **注意**：syslog-address支持UDP和TCP。

你可以通过设置特定容器的记录驾驶员 `--log-driver`选项`docker container create`或`docker run`：

```sh
$ docker run \
-–log-driver syslog –-log-opt syslog-address=udp://1.2.3.4:1111 \
alpine echo hello world
```

#### 选项

支持以下日志记录选项作为`syslog`日志记录驱动程序的选项。可以`daemon.json`通过将它们作为键值对添加到`log-opts`JSON数组中将它们设置为默认值。它们也可以通过`--log-opt <key>=<value>`在启动容器时为每个选项添加一个选项来设置给定的容器。

| 选项                     | 描述                                                         | 示例值                                                       |
| ------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| `syslog-address`         | 外部`syslog`服务器的地址。该URI指定符可以是`[tcp | udp|tcp+tls]://host:port`，`unix://path`，或`unixgram://path`。如果传输是`tcp`，`udp`或`tcp+tls`，默认端口是`514`。 | `--log-opt syslog-address=tcp+tls://192.168.1.3:514`，`--log-opt syslog-address=unix:///tmp/syslog.sock` |
| `syslog-facility`        | 使用的`syslog`设施。可以是任何有效`syslog`设施的编号或名称。请参阅[syslog文档](https://tools.ietf.org/html/rfc5424#section-6.2.1)。 | `--log-opt syslog-facility=daemon`                           |
| `syslog-tls-ca-cert`     | 由CA签署的信任证书的绝对路径。**如果地址协议不是，则忽略tcp+tls。** | `--log-opt syslog-tls-ca-cert=/etc/ca-certificates/custom/ca.pem` |
| `syslog-tls-cert`        | TLS证书文件的绝对路径。**如果地址协议不是，则忽略tcp+tls**。 | `--log-opt syslog-tls-cert=/etc/ca-certificates/custom/cert.pem` |
| `syslog-tls-key`         | TLS密钥文件的绝对路径。**如果地址协议不是，则忽略tcp+tls。** | `--log-opt syslog-tls-key=/etc/ca-certificates/custom/key.pem` |
| `syslog-tls-skip-verify` | 如果设置为`true`，则在连接`syslog`守护程序时跳过TLS验证。默认为`false`。**如果地址协议不是，则忽略tcp+tls。** | `--log-opt syslog-tls-skip-verify=true`                      |
| `tag`                    | 附加到邮件`APP-NAME`中的字符串`syslog`。默认情况下，Docker使用容器ID的前12个字符来标记日志消息。请参阅[日志标记选项文档](https://docs.docker.com/config/containers/logging/log_tags/)以定制日志标记格式。 | `--log-opt tag=mailer`                                       |
| `syslog-format`          | `syslog`要使用的消息格式。如果未指定，则使用本地UNIX系统日志格式，而不使用指定的主机名。指定`rfc3164`RFC-3164兼容格式，`rfc5424`RFC-5424兼容格式，或`rfc5424micro`RFC-5424兼容格式，微秒时间戳解析。 | `--log-opt syslog-format=rfc5424micro`                       |
| `labels`                 | 在启动Docker守护进程时适用。守护进程接受的日志相关标签的逗号分隔列表。用于高级[日志标记选项](https://docs.docker.com/config/containers/logging/log_tags/)。 | `--log-opt labels=production_status,geo`                     |
| `env`                    | 在启动Docker守护进程时适用。此守护程序接受的与日志相关的环境变量的逗号分隔列表。用于高级[日志标记选项](https://docs.docker.com/config/containers/logging/log_tags/)。 | `--log-opt env=os,customer`                                  |
| `env-regex`              | 在启动Docker守护进程时适用。类似于并兼容`env`。一个正则表达式来匹配与日志相关的环境变量。用于高级[日志标记选项](https://docs.docker.com/config/containers/logging/log_tags/)。 | `--log-opt env-regex=^(os\|customer)`                        |

### `journald `日志驱动

---

`journald`日志驱动程序发送容器日志的 [`systemd`日记](http://www.freedesktop.org/software/systemd/man/systemd-journald.service.html)。可以使用该`journalctl`命令，通过使用 `journal`API或使用`docker logs`命令来检索日志条目。

除了日志消息本身的文本之外，`journald`日志驱动程序还会在每条消息的日志中存储以下元数据：

| 领域                                 | 描述                                                         |
| ------------------------------------ | ------------------------------------------------------------ |
| `CONTAINER_ID`                       | 容器标识被截断为12个字符。                                   |
| `CONTAINER_ID_FULL`                  | 完整的64个字符的容器ID。                                     |
| `CONTAINER_NAME`                     | 容器名称在启动时。如果您使用`docker rename`重命名容器，则新名称不会反映在日记条目中。 |
| `CONTAINER_TAG`，`SYSLOG_IDENTIFIER` | 容器标签（[日志标签选项文档](https://docs.docker.com/config/containers/logging/log_tags/)）。 |
| `CONTAINER_PARTIAL_MESSAGE`          | 标记日志完整性的字段。改善长日志行的日志记录。               |

#### 用法

要将`journald`驱动程序用作默认日志记录驱动程序，请将`log-driver` 和`log-opt`设置`daemon.json`为位于`/etc/docker/`Linux主机或`C:\ProgramData\docker\config\daemon.json`Windows Server 上 的文件中的适当值。有关使用Docker配置的更多信息`daemon.json`，请参阅 [daemon.json](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)。

以下示例将日志驱动程序设置为`journald`：

```json
{
  "log-driver": "journald"
}
```

重新启动Docker以使更改生效。

要为特定容器配置日志记录驱动程序，请使用  `docker run`命令中的`--log-driver`选项。

```sh
$ docker run --log-driver=journald ...
```

#### 选项

使用`--log-opt NAME=VALUE`选项指定其他`journald`日志记录驱动程序选项。

| 选项        | 需要   | 描述                                                         |
| ----------- | ------ | ------------------------------------------------------------ |
| `tag`       | 可选的 | 指定模板以在日志记录日志中设置`CONTAINER_TAG`和`SYSLOG_IDENTIFIER`赋值。请参阅[日志标记选项文档](https://docs.docker.com/engine/admin/logging/log_tags/)以自定义日志标记格式 |
| `label`     | 可选的 | 如果为容器指定了这些标签，则应在消息中包含标签的逗号分隔键列表。 |
| `env`       | 可选的 | 如果为容器指定了这些变量，则应在消息中包含环境变量的键的逗号分隔列表。 |
| `env-regex` | 可选的 | 与env类似且兼容。一个正则表达式来匹配与日志相关的环境变量。用于高级  [日志标记选项](https://docs.docker.com/engine/admin/logging/log_tags/)。 |

如果标签和env键之间发生冲突，则env的值优先。每个选项都将附加字段添加到日志消息的属性中。以下是日志记录所需的日志记录选项示例。

```sh
$ docker run --log-driver=journald \
    --log-opt labels=location \
    --log-opt env=TEST \
    --env "TEST=false" \
    --label location=west \
    your/application
```

该配置还指示驱动程序在有效负载中包含标签位置和环境变量TEST。如果忽略`--env "TEST=false"`或`--label location=west`参数，相应的键不会在日志记录中设置。

#### 有关容器名称的说明

记录在`CONTAINER_NAME`字段中的值是在启动时设置的容器的名称。如果使用`docker rename`重命名容器，则新名称**不会反映**在日记条目中。日记条目继续使用原始名称。

#### 用检索日志消息 `journalctl`

使用`journalctl`命令检索日志消息。可以应用筛选器表达式将检索到的邮件限制为与特定容器关联的邮件：

```sh
$ sudo journalctl CONTAINER_NAME=webserver
```

可以使用其他过滤器来进一步限制检索到的消息。`-b` 选项仅检索自上次系统引导后生成的消息：

```sh
$ sudo journalctl -b CONTAINER_NAME=webserver
```

`-o`选项指定重试日志消息的格式。用于`-o json` 以JSON格式返回日志消息。

```json
$ sudo journalctl -o json CONTAINER_NAME=webserver
```

#### 查看启用了TTY的容器的日志

如果`[10B blob data]`在检索日志消息时可能在输出中看到的容器上启用了TTY 。原因是这`\r`是附加到行的末尾，`journalctl`除非`--all`设置，否则不会自动分离它：

```sh
$ sudo journalctl -b CONTAINER_NAME=webserver --all
```

#### 使用`journal`API 检索日志消息

本示例使用`systemd`Python模块来检索容器日志：

```python
import systemd.journal

reader = systemd.journal.Reader()
reader.add_match('CONTAINER_NAME=web')

for msg in reader:
    print '{CONTAINER_ID_FULL}: {MESSAGE}'.format(**msg)
```
# docker 安全配置

## Docker 安全性

在审查Docker安全性时，需要考虑四个主要方面：

- 内核的**内在安全性**及其对**命名空间**和**cgroups**的支持;
- Docker**守护进程**本身的攻击;
- 容器**配置文件**中的漏洞，默认情况下或用户自定义文件。
- 内核的“强化”安全功能以及它们如何与容器交互。

### 内核命名空间

------

Docker容器与LXC容器非常相似，并且它们具有类似的安全功能。当你`docker run`启动一个容器时 ，Docker为这个容器创建一组**命名空间和控制组**。

**命名空间提供了第一个也是最直接的隔离形式**：在容器中运行的进程看不到，甚至更少影响在另一个容器或主机系统中运行的进程。

**每个容器也都有自己的网络堆栈**，这意味着容器不会获得对另一个容器的**套接字或接口的特权**访问。当然，如果主机系统相应设置，容器可以通过**各自的网络接口相互交互** - 就像他们可以与外部主机进行交互一样。当你为容器指定公共端口或使用 [*链接时*](https://docs.docker.com/engine/userguide/networking/default_network/dockerlinks/) ，容器之间允许IP流量。它们可以互相ping通，发送/接收UDP数据包，并建立TCP连接，但如果需要可以限制它们。从网络体系结构的角度来看，给定Docker主机上的所有容器都位于网桥接口上。这意味着它们就像通过普通以太网交换机连接的物理机器一样，不多也不少。

### 控制组

------

控制组是Linux容器的另一个关键组件。他们执行**资源审计和限制**。它们提供了许多有用的度量标准，但它们也有助于确保每个**容器获得其公平的内存，CPU和磁盘IO**; 更重要的是，单个容器**不能耗尽**这些资源中的一个来降低系统的性能。

因此，尽管它们不能阻止一个容器访问或影响另一个容器的数据和进程，但它们对**抵御一些拒绝服务攻击**至关重要。它们对于多租户平台尤其重要，例如公共和私有PaaS，即使在某些应用程序开始出现故障时也能保证一致的正常运行时间（和性能）。

### Docker 守护进程攻击

------

使用Docker运行容器（和应用程序）意味着运行Docker守护进程。这个守护进程当前**需要`root`特权**，因此你应该知道一些重要的细节。

首先，**应该只允许受信任的用户来控制你的Docker守护进程**。这是一些强大的Docker功能的直接后果。具体来说，Docker允许在Docker主机和访客容器之间**共享一个目录**; 它允许在**不限制容器访问权限**的情况下这样做。这意味着可以启动一个容器，其`/host`目录是`/`主机上的目录; 容器可以不受任何限制地**改变你的主机文件系统**。这与虚拟化系统如何允许文件系统资源共享类似。没有什么能够阻止你与虚拟机共享你的根文件系统（甚至你的根块设备）。

这具有很强的安全意义：例如，如果你通过Web服务器来监控Docker以通过API配置容器，则应该比平时更加仔细地进行参数检查，以确保恶意用户无法传递控制的参数，从而导致Docker创建任意容器。

出于这个原因，Docker 0.5.2中更改了REST API端点（由Docker CLI用于与Docker守护进程通信），现在使用UNIX套接字而不是127.0.0.1上绑定的TCP套接字（后者容易发生如果碰巧在本地机器上直接运行Docker，而不是在虚拟机之外），则可以**发起跨站请求伪造攻击**。然后，可以使用**传统的UNIX权限检查**来限制对控制套接字的访问。

如果明确决定这么做，还可以通过HTTP公开REST API。但是，如果这样做，请注意上述安全隐患。确保它只能从**受信任的网络或VPN访问**，或者使用诸如**`stunnel`和客户端SSL证书**等机制进行保护。还可以使用[HTTPS和证书](https://docs.docker.com/engine/security/https/)来保护API端点。

守护进程也可能容易受到其他输入的影响，例如从磁盘`docker load`或从网络 加载磁盘的镜像`docker pull`。从Docker 1.3.2开始，镜像现在在Linux / Unix平台的chrooted子进程中提取，这是实现特权分离更广泛工作的第一步。从Docker 1.10.0开始，所有镜像都通过其内容的**加密校验和进行存储和访问**，从而限制了攻击者与现有镜像发生冲突的可能性。

最后，如果在服务器上运行Docker，则**建议在服务器上专门运行Docker**，并将所有其他服务移动到由Docker控制的容器中。当然，保留最喜欢的管理工具（可能至少是SSH服务器）以及现有的监控/监督流程（如NRPE和collectd）是很好的。

### Linux内核功能

------

默认情况下，Docker会使用一组受限制的功能启动容器。那是什么意思？

功能将二元“根/非根”二分法转变为一个细粒度的访问控制系统。只需要**绑定在1024以下端口**上的进程（如Web服务器）不需要以root身份运行：它们可以被赋予权限`net_bind_service`。对于几乎所有需要root权限的特定领域，还有许多其他功能。

这对于容器安全意义重大。让我们看看为什么！

典型的服务器运行多个`root`进程，包括SSH守护进程， `cron`守护进程，日志守护进程，内核模块，网络配置工具等。容器是不同的，因为几乎所有这些任务都是由容器周围的基础设施处理的：

- SSH访问通常由运行在Docker主机上的**单个服务器**管理;
- `cron`在必要时应作为**用户进程**运行，专门针对需要其**调度服务**的应用程序专门定制，而不是作为平台范围的设施;
- 日志管理通常也交给Docker，或Loggly或Splunk等第三方服务;
- 硬件管理是无关紧要的，这意味着你永远不需要`udevd`在容器中运行或等效的守护进程;
- 网络管理发生在容器的外面，执行关注点尽可能的分离，这意味着一个容器不应该需要执行`ifconfig`， `route`或IP命令（当容器被特别设计，以表现得象一个路由器或防火墙除外） 。

这意味着，在大多数情况下，**容器并不需要“真正的” root 权限**。因此，容器可以运行一个能力较低的集合。 这意味着容器中的“root”比真正的“root”要少得多。例如，有可能：

- 否认所有“挂载”操作;
- 拒绝访问原始套接字（以防止数据包欺骗）;
- 拒绝访问某些文件系统操作，如创建新设备节点，更改文件所有者或更改属性（包括不可变选项）;
- 拒绝模块加载;
- 和其他许多

这意味着即使入侵者设法升级到容器内的根目录，要做到严重的破坏或升级到主机也要困难得多。

这不会影响常规的Web应用程序，但会大大减少恶意用户的攻击媒介。默认情况下，Docker将删除除[所需](https://github.com/moby/moby/blob/master/oci/defaults.go#L14-L30)功能之外的所有功能，即白名单而不是黑名单方法。可以在[Linux手册页中](http://man7.org/linux/man-pages/man7/capabilities.7.html)看到完整的可用功能列表。

运行Docker容器的一个主要风险是给容器**默认的一组功能和挂载可能会独立提供不完全的隔离，或者与内核漏洞结合使用**。

Docker支持添加和删除功能，允许使用**非默认配置**文件。这可能会通过删除功能使Docker更安全，或者通过增加功能降低Docker的安全性。对于用户来说，最好的做法是去除**除了他们的进程明确需要的所有功能**。

### 其他内核安全功能

------

功能只是现代Linux内核提供的许多安全功能之一。还可以利用Docker等现有知名系统，如`TOMOYO，AppArmor，SELinux，GRSEC`等。

虽然Docker目前仅支持功能，但不会干扰其他系统。这意味着有很多不同的方法来加固Docker主机。这里有一些例子。

- 可以**使用GRSEC和PAX运行内核**。这在编译时和运行时都增加了许多**安全检查**; 它也击败了许多漏洞，这要归功于地址随机化等技术。它不需要特定于Docker的配置，因为这些安全特性适用于**系统范围，独立于容器**。
- 如果发行版带有Docker容器的**安全模型模板**，可以**直接使用**它们。例如，我们发布了一个可与AppArmor配合使用的模板，而Red Hat提供了适用于Docker的SELinux策略。这些模板提供了一个额外的安全网（尽管它与功能重叠）。
- 可以使用最喜欢的**访问控制机制**来定义自己的策略。

就像可以使用第三方工具来扩充Docker容器（包括特殊网络拓扑或共享文件系统）一样，存在用于Docker容器而无需修改Docker本身的工具。

从Docker 1.10起，Docker守护进程直接支持**用户命名空间**。此功能允许将容器中的**根用户映射到容器外部的非uid-0用户**，这有助于减轻容器突破的风险。该工具可用，但默认情况下不启用。

有关此功能的更多信息，请参阅命令行参考中的[守护程序命令](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-user-namespace-options)。有关Docker中用户命名空间实现的其他信息可以在[此博客文章中](https://integratedcode.us/2015/10/13/user-namespaces-have-arrived-in-docker/)找到 。

### 结论

------

默认情况下，Docker容器非常安全; 特别是如果在容器内将进程作为**非特权用户**运行时。可以通过**启用AppArmor，SELinux，GRSEC**或其他适当的**强化系统**来添加额外的安全层。

## 保护Docker守护进程套接字

默认情况下，Docker通过**非联网的Unix套接字**运行。它也可以选择使用**HTTP套接字**进行通信。

如果需要通过网络以安全的方式访问Docker，则可以通过指定`tlsverify`选项并将Docker `tlscacert`选项指向 **受信任的CA证书来启用TLS **。

在守护进程模式下，它只允许客户端通过由CA签名的证书进行身份验证。在客户端模式下，它仅连接到具有由该CA签名的证书的服务器。

> **高级话题**：使用TLS和管理CA是一个高级主题。在使用它之前，请熟悉OpenSSL，x509和TLS。

### 使用OpenSSL创建CA，服务器和客户端密钥

------

> **注意**：将`$HOST`以下示例中的所有实例替换为Docker守护进程主机的DNS名称。

#### 创建 CA 证书

首先，在**Docker守护进程的主机上**生成CA私钥和公钥：

```sh
# 10.0.2.3
$ winpty openssl genrsa -aes256 -out ca-key.pem 4096
Generating RSA private key, 4096 bit long modulus
............................................................................................................................................................................................++
........++
e is 65537 (0x10001)
Enter pass phrase for ca-key.pem:
Verifying - Enter pass phrase for ca-key.pem:

$ winpty openssl req -new -x509 -days 365 -key ca-key.pem -sha256 -out ca.pem
Enter pass phrase for ca-key.pem:
You are about to be asked to enter information that will be incorporated
into your certificate request.
What you are about to enter is what is called a Distinguished Name or a DN.
There are quite a few fields but you can leave some blank
For some fields there will be a default value,
If you enter '.', the field will be left blank.
-----
Country Name (2 letter code) [AU]:
State or Province Name (full name) [Some-State]:Queensland
Locality Name (eg, city) []:Brisbane
Organization Name (eg, company) [Internet Widgits Pty Ltd]:Docker Inc
Organizational Unit Name (eg, section) []:Sales
Common Name (e.g. server FQDN or YOUR name) []:$HOST
Email Address []:Sven@home.org.au
```

#### 创建服务器端秘钥

现在拥有一个CA，可以创建一个服务器密钥和证书签名请求（CSR）。确保“通用名称”与用于连接到Docker的主机名相匹配：

```sh
$ winpty openssl genrsa -out server-key.pem 4096
Generating RSA private key, 4096 bit long modulus
.....................................................................++
.................................................................................................++
e is 65537 (0x10001)

$ winpty openssl req -sha256 -new -key server-key.pem -out server.csr
```

接下来，我们将用我们的CA签署公钥：

由于TLS连接可以通过IP地址和DNS名称进行，因此创建证书时需要指定IP地址。例如，要允许`10.10.10.20`和`127.0.0.1`连接：

```sh
$ echo subjectAltName = DNS:$HOST,IP:10.10.10.20,IP:127.0.0.1 >> extfile.cnf
# echo subjectAltName = DNS:10.0.2.3,IP:192.168.99.100,IP:127.0.0.1 >> extfile.cnf
```

将Docker守护进程密钥的扩展使用属性设置为仅用于服务器身份验证：

```sh
$ echo extendedKeyUsage = serverAuth >> extfile.cnf
```

现在，生成签名证书：

```sh
$ winpty openssl x509 -req -days 365 -sha256 -in server.csr -CA ca.pem -CAkey ca-key.pem \
  -CAcreateserial -out server-cert.pem -extfile extfile.cnf
```

[授权插件](https://docs.docker.com/engine/extend/plugins_authorization)提供更细致的控制，以补充相互TLS的认证。除了上述文档中介绍的其他信息之外，在Docker守护程序上运行的授权插件会接收用于连接Docker客户端的证书信息。

#### 创建客户端秘钥

对于客户端身份验证，请创建客户端密钥和证书签名请求：

> **注意：**为了简化接下来的几个步骤，你也可以在Docker守护进程的主机上执行此步骤。

```sh
$ winpty openssl genrsa -out key.pem 4096
$ winpty openssl req -subj '/CN=client' -new -key key.pem -out client.csr
```

要使密钥适合客户端认证，请创建一个扩展配置文件：

```sh
$ echo extendedKeyUsage = clientAuth >> extfile.cnf
```

现在，生成签名证书：

```sh
$ winpty openssl x509 -req -days 365 -sha256 -in client.csr -CA ca.pem -CAkey ca-key.pem \
  -CAcreateserial -out cert.pem -extfile extfile.cnf
```

#### 清理签名/控制权限

生成后`cert.pem`，`server-cert.pem`可以安全地删除两个证书签名请求：

```sh
$ rm -v client.csr server.csr
```

默认`umask`值为022时，密钥是**全局可读**和可写的。

为防止意外损坏密钥，请删除其写入权限。要让它们只能被你读取，请按如下方式更改文件模式：

```sh
$ chmod -v 0400 ca-key.pem key.pem server-key.pem
```

证书可以是全局可读的，但可能想要删除写入访问以防止意外损坏：

```sh
$ chmod -v 0444 ca.pem server-cert.pem cert.pem
```

现在可以让Docker守护进程只接受来自提供你的CA信任的证书的客户端的连接：

```sh
$ sudo dockerd --tlsverify --tlscacert=ca.pem --tlscert=server-cert.pem --tlskey=server-key.pem -H=0.0.0.0:2376
```

要连接到Docker并验证其证书，请提供你的客户端密钥，证书和可信CA：

> **在客户机上运行它**<br/>这一步应该在你的Docker客户端机器上运行。因此，需要将CA证书，服务器证书和客户端证书复制到该机器。

```sh
$ docker --tlsverify --tlscacert=ca.pem --tlscert=cert.pem --tlskey=key.pem \
  -H=$HOST:2376 version
```

> **注意**：通过TLS的Docker应该在TCP端口2376上运行。

> **警告**：如上例所示，当你使用证书身份验证时，无需`docker`使用`sudo`或`docker`组运行客户端。这意味着任何拥有密钥的人都可以给你的Docker守护进程提供任何指令，让他们可以访问托管守护进程的机器。**保护这些密钥，就像你使用root密码一样**！

### 默认安全模式

------

如果想默认保护Docker客户端连接，可以将文件移动到`.docker`的主目录中的目录，并设置 `DOCKER_HOST`和`DOCKER_TLS_VERIFY`变量（而不是传递 `-H=tcp://$HOST:2376`和`--tlsverify`每次调用）。

```sh
$ mkdir -pv ~/.docker
$ cp -v {ca,cert,key}.pem ~/.docker

$ export DOCKER_HOST=tcp://$HOST:2376 DOCKER_TLS_VERIFY=1
```

Docker默认安全连接：

```sh
$ docker ps
```

### 其他模式

------

如果你不想有完整的双向认证，你可以通过混合选项来以各种其他模式运行Docker。

#### 守护进程模式

- `tlsverify`，`tlscacert`，`tlscert`，`tlskey`集：验证客户端
- `tls`，`tlscert`，`tlskey`：不要验证客户端

#### 客户端模式

- `tls`：基于公共/默认CA池对服务器进行身份验证
- `tlsverify`，`tlscacert`：根据给定的CA验证服务器
- `tls`，`tlscert`，`tlskey`：以验证客户端证书，不验证服务器基于给定CA
- `tlsverify`，`tlscacert`，`tlscert`，`tlskey`：以验证客户端证书并认证服务器基于给定CA

如果找到，客户端发送它的客户端证书，所以你只需要放下你的密钥`~/.docker/{ca,cert,key}.pem`。或者，如果你想将密钥存储在其他位置，则可以使用环境变量指定该位置`DOCKER_CERT_PATH`。

```sh
$ export DOCKER_CERT_PATH=~/.docker/zone1/
$ docker --tlsverify ps
```

#### 使用 `curl`连接到安全的Docker端口

要使用`curl`测试API请求，需要使用三个额外的命令行选项：

```sh
$ curl https://$HOST:2376/images/json \
  --cert ~/.docker/cert.pem \
  --key ~/.docker/key.pem \
  --cacert ~/.docker/ca.pem
```

## 用证书验证存储库客户端

在[使用HTTPS运行Docker时](https://docs.docker.com/engine/security/https/)，默认情况下，Docker通过**非联网的Unix套接字**运行，并且必须**启用TLS**才能让Docker客户端和后台进程通过HTTPS进行安全通信。**TLS**确保注册表端点的**真实性**，并且**加密注入/流出**注册表的流量。

如何确保Docker注册服务器和Docker守护进程（注册服务器的客户端）之间的通信使用**基于证书的客户端 - 服务器身份**验证进行**加密和正确验证**。<br/>下面将操作如何为注册表安装证书颁发机构（CA）根证书以及如何设置客户端TLS证书以进行验证。

### 了解配置

------

通过`/etc/docker/certs.d`使用与**注册表主机名相同的名称**创建目录来配置自定义证书 ，例如 `localhost`。所有`*.crt`文件都作为CA根添加到此目录。

> **注意**：从Docker 1.13开始，在Linux上，任何根证书颁发机构都会与系统默认值合并，包括作为主机的根CA集。在以前版本的Docker和Docker Enterprise Edition for Windows Server上，仅在未配置自定义根证书时才使用系统默认证书。

`<filename>.key/cert`一对或多对对象表示Docker有访问所需存储库所需的自定义证书。

> **注意**：如果存在多个证书，则按**字母顺序**尝试每个证书。如果存在4xx级别或5xx级别的身份验证错误，则Docker会继续尝试使用下一个证书。

以下说明了具有自定义证书的配置：

```sh
    /etc/docker/certs.d/        <-- Certificate directory
    └── localhost:5000          <-- Hostname:port
       ├── client.cert          <-- Client certificate
       ├── client.key           <-- Client key
       └── ca.crt               <-- Certificate authority that signed
                                    the registry certificate
```

前面的示例是特定于操作系统的，仅用于说明目的。应该查阅操作系统文档以创建一个os提供的捆绑证书链。

### 创建客户端证书

------

使用OpenSSL `genrsa`和`req`命令首先生成RSA密钥，然后使用密钥创建证书。

```sh
$ openssl genrsa -out client.key 4096
$ openssl req -new -x509 -text -key client.key -out client.cert
```

> **注意**：这些TLS命令仅在Linux上生成一组工作证书。macOS中的OpenSSL版本与Docker所需的证书类型不兼容。

### 疑难解答提示

------

Docker守护程序将`.crt`文件解释为CA证书和`.cert`文件作为客户端证书。如果CA证书意外地被赋予扩展名 `.cert`而不是正确的`.crt`扩展名，那么Docker守护程序会记录以下错误消息：

```sh
Missing key KEY_NAME for client certificate CERT_NAME. CA certificates should use the extension .crt.
```

如果没有端口号访问Docker注册表，请不要将端口添加到目录名称。以下显示了默认端口443上的注册表的配置，该端口可通过`docker login my-https.registry.example.com`以下方式访问：

```sh
    /etc/docker/certs.d/
    └── my-https.registry.example.com          <-- Hostname without port
       ├── client.cert
       ├── client.key
       └── ca.crt
```

## 利用命名空间隔离容器

Linux命名空间为正在运行的进程提供了**隔离**，**限制**了他们对**系统资源**的**访问**，而运行进程没有意识到这些限制。有关Linux命名空间的更多信息，请参阅 [Linux命名空间](https://www.linux.com/news/understanding-and-securing-linux-namespaces)。

**防止容器内的特权升级攻击**的最佳方法是将容器的应用程序配置为以**非特权用户身份**运行。对于其进程必须`root`以容器中的用户身份运行的容器，可以将此**用户重新映射到Docker主机上权限较低**的用户。映射的用户被分配了一系列UID，这些UID在名称空间内作为从0到65536的普通UID运行，但**对主机本身没有特权**。

### 关于重新映射和从属用户和组ID

------

重新映射本身由两个文件处理：`/etc/subuid`和`/etc/subgid`。每个文件的工作原理都是一样的，但其中一个关注用户ID范围，另一个关注组ID范围。考虑下列条目`/etc/subuid`：

```sh
testuser:231072:65536
```

这意味着将`testuser`为其分配一个从属用户ID范围`231072` 和下一个65536个整数。UID `231072`映射到名称空间（在本例中为容器内）为UID `0`（`root`）。UID `231073` 被映射为UID `1`等等。如果某个进程尝试在**名称空间外部提升特权**，则该进程将作为主机上无特权的高数字UID运行，该超级用户甚至**不映射到真实用户**。这意味着该进程**完全没有**主机系统的权限。

> **多个范围**<br/>通过为`/etc/subuid`或`/etc/subgid`文件中的同一用户或组添加多个不重叠的映射，可以为给定的用户或组分配多个从属范围。在这种情况下，根据内核对`/proc/self/uid_map`和`/proc/self/gid_map`中**只有五个条目的限制，Docker仅使用前五个映射**。

当将Docker配置为使用`userns-remap`功能时，可以选择指定现有的用户或组，也可以指定`default`。如果指定`default`，则会为此创建并使用用户和组`dockremap`。

> **警告**：某些发行版（如RHEL和CentOS 7.3）不会自动将新组添加到`/etc/subuid`和`/etc/subgid`文件。在这种情况下，负责编辑这些文件并分配不重叠的范围。[先决条件中](https://docs.docker.com/engine/security/userns-remap/#prerequisites)介绍了此步骤。

范围不重叠非常重要，这样一个进程无法在不同的名称空间中访问。在大多数Linux发行版中，当添加或删除用户时，系统实用程序会为你管理这些范围。

这种重新映射对容器是透明的，但是在容器需要访问Docker主机上的资源的情况下引入了一些配置复杂性，例如绑定到系统用户无法写入的文件系统区域。从安全角度来看，最好避免这些情况。

### 先决条件

------

1. 即使关联是实现细节，下级UID和GID范围也必须与现有用户关联。用户拥有`/var/lib/docker/`下的名称空间存储目录。如果你不想使用现有的用户，Docker可以为你创建一个并使用它。如果你想使用现有的用户名或用户标识，它必须已经存在。通常，这意味着相关条目需要位于`/etc/passwd`和`/etc/group`中，但如果你使用的是不同的身份验证后端，则此需求可能会有所不同。

   要验证这一点，请使用以下`id`命令：

   ```sh
   $ id testuser
   uid=1001(testuser) gid=1001(testuser) groups=1001(testuser)
   ```

2. 在主机上处理名称空间重映射的方式是使用两个文件`/etc/subuid`和`/etc/subgid`。这些文件通常在添加或删除用户或组时自动管理，但在少数发行版（如RHEL和CentOS 7.3）中，可能需要手动管理这些文件。

   每个文件包含三个字段：用户的用户名或ID，后跟一个开始UID或GID（在名称空间内被视为UID或GID 0）以及用户可用的最大数量的UID或GID。例如，给出以下条目：

   ```sh
   testuser:231072:65536
   ```

   这意味着通过296608（231072 + 65536）启动的用户名空间进程`testuser`由主机UID `231072`（它看起来像`0`名称空间内的UID ）拥有。这些范围不应该重叠，以确保名称空间的进程不能访问彼此的名称空间。

   添加用户后，请检查`/etc/subuid`并`/etc/subgid`查看用户是否有每个条目。如果不是，你需要添加它，小心避免重叠。

   如果想使用`dockremap`由Docker自动创建的用户，请**在** 配置并重新启动Docker **后**检查`dockremap`这些文件中的条目。

3. 如果在非特权用户需要写入的Docker主机上有任何位置，请相应地调整这些位置的权限。如果你想使用`dockremap`由Docker自动创建的用户，这也是正确的，但是在配置和重新启动Docker之后才能修改权限。

4. 使`userns-remap`有效现有的镜像和容器的层，以及`/var/lib/docker/`内的其它docker对象。这是因为Docker需要调整这些资源的所有权并实际将它们存储在其中的子目录`/var/lib/docker/`中。最好在新的Docker安装中启用此功能，而不是现有的。

   沿着相同的路线，如果禁用`userns-remap`，则无法访问启用时创建的任何资源。

5. 检查用户名空间的[限制](https://docs.docker.com/engine/security/userns-remap/#user-namespace-known-restrictions)，以确保你的用例可行。

## 在守护程序上启用用户名重新映射

你可以开始`dockerd`用`--userns-remap`选项或遵循此过程配置使用守护进程`daemon.json`的配置文件。`daemon.json`建议使用该方法。如果你使用该选项，请使用以下命令作为模型：

```sh
$ dockerd --userns-remap="testuser:testuser"
```

1. 编辑`/etc/docker/daemon.json`。假设文件先前为空，则以下条目将使用名为`testuser`的用户和组启用`userns-remap`。可以通过ID或名称来寻址用户和组。如果与用户名或ID不同，只需指定组名或ID。如果同时提供用户和组名称或ID，请使用冒号`:`字符分隔它们。假设`testuser`的UID和GID是`1001`，以下格式都适用于该值：

   - `testuser`
   - `testuser:testuser`
   - `1001`
   - `1001:1001`
   - `testuser:1001`
   - `1001:testuser`

   ```sh
   {
     "userns-remap": "testuser"
   }
   ```

   > **注意**：要使用`dockremap`用户并让Docker为你创建它，请将该值设置为`default`而不是`testuser`。

   保存该文件并重新启动Docker。

2. 如果使用的是`dockremap`用户，请验证Docker是否使用`id`命令创建它。

   ```sh
   $ id dockremap
   uid=112(dockremap) gid=116(dockremap) groups=116(dockremap)
   ```

   验证条目是否已添加到`/etc/subuid`和`/etc/subgid`：

   ```sh
   $ grep dockremap /etc/subuid
   dockremap:231072:65536
   
   $ grep dockremap /etc/subgid
   dockremap:231072:65536
   ```

   如果这些条目不存在，请以`root`用户身份编辑这些文件，并分配一个起始UID和GID，该起始UID和GID是最高分配的一个加上偏移量（在本例中为`65536`）。小心不要在范围内有任何重叠。

3. 使用`docker image ls` 命令验证以前的镜像不可用。输出应该是空的。

4. 从`hello-world`镜像启动一个容器。

   ```sh
   $ docker run hello-world
   ```

5. `/var/lib/docker/`使用该UID和GID拥有的名称空间用户的UID和GID，验证名称空间目录中是否存在名称空间目录，而不是组或全局可读的。一些子目录仍然拥有`root`并具有不同的权限。

   ```sh
   $ sudo ls -ld /var/lib/docker/231072.231072/
   drwx------ 11 231072 231072 11 Jun 21 21:19 /var/lib/docker/231072.231072/
   
   $ sudo ls -l /var/lib/docker/231072.231072/
   total 14
   drwx------ 5 231072 231072 5 Jun 21 21:19 aufs
   drwx------ 3 231072 231072 3 Jun 21 21:21 containers
   drwx------ 3 root   root   3 Jun 21 21:19 image
   drwxr-x--- 3 root   root   3 Jun 21 21:19 network
   drwx------ 4 root   root   4 Jun 21 21:19 plugins
   drwx------ 2 root   root   2 Jun 21 21:19 swarm
   drwx------ 2 231072 231072 2 Jun 21 21:21 tmp
   drwx------ 2 root   root   2 Jun 21 21:19 trust
   drwx------ 2 231072 231072 3 Jun 21 21:19 volumes
   ```

   你的目录列表可能有一些差异，特别是如果你使用不同的`aufs`容器存储驱动程序。

   使用重映射用户所拥有的目录而不是直接位于`/var/lib/docker/`下的相同目录，并且可以删除未使用的版本（例如此处的示例中的`/var/lib/docker/tmp/`）。在启用userns-remap时，Docker不使用它们。

### 禁用容器的命名空间重新映射

------

如果在**守护进程上启用用户命名空间**，则**所有容器**都将默认启用用户命名空间。在某些情况下，例如特权容器，可能需要**禁用特定容器**的用户命名空间。有关这些限制的其中一部分，请参阅 [用户名称空间已知限制](https://docs.docker.com/engine/security/userns-remap/#user-namespace-known-restrictions)

要**禁用用户名称空间**为特定容器，添加`--userns=host` 选项到`docker container create`，`docker container run`或`docker container exec`命令。

### 用户命名空间已知限制

------

以下标准Docker功能与启用用户命名空间的Docker守护程序不兼容：

- 与主机共享PID或NET命名空间（`--pid = host`或`--network = host`）。
- 外部（卷或存储）驱动程序不知道或不能使用守护程序用户映射。
- 在`docker run`上使用`--privileged mode`选项，而不指定`--userns = host`。

用户名称空间是一项高级功能，需要与其他功能协调。例如，如果卷从主机挂载，则必须预先安排文件所有权，以便对卷内容进行读取或写入访问。

尽管用户名容器过程中的root用户具有容器中**超级用户的许多期望特权**，但Linux内核根据内部知识限制这是一个用户名空间过程。一个显着的限制是无法使用`mknod`命令。由`root`用户运行时，容器内的设备创建权限被拒绝。

