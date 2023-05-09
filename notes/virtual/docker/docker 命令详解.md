# docker 命令详解

* [docker 命令详解](#docker-%E5%91%BD%E4%BB%A4%E8%AF%A6%E8%A7%A3)
* [docker 命令简介](#docker-%E5%91%BD%E4%BB%A4%E7%AE%80%E4%BB%8B)
  * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9)
  * [环境变量](#%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
  * [配置文件](#%E9%85%8D%E7%BD%AE%E6%96%87%E4%BB%B6)
    * [自定义格式化输出](#%E8%87%AA%E5%AE%9A%E4%B9%89%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA)
    * [自定义快捷键](#%E8%87%AA%E5%AE%9A%E4%B9%89%E5%BF%AB%E6%8D%B7%E9%94%AE)
    * [config\.json 文件示例](#configjson-%E6%96%87%E4%BB%B6%E7%A4%BA%E4%BE%8B)
  * [公证](#%E5%85%AC%E8%AF%81)
* [docker 基本命令行](#docker-%E5%9F%BA%E6%9C%AC%E5%91%BD%E4%BB%A4%E8%A1%8C)
  * [\* create 创建](#-create-%E5%88%9B%E5%BB%BA)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-1)
    * [示例](#%E7%A4%BA%E4%BE%8B)
      * [创建并启动一个容器](#%E5%88%9B%E5%BB%BA%E5%B9%B6%E5%90%AF%E5%8A%A8%E4%B8%80%E4%B8%AA%E5%AE%B9%E5%99%A8)
      * [初始化卷](#%E5%88%9D%E5%A7%8B%E5%8C%96%E5%8D%B7)
      * [处理动态创建的设备（\-\-device\-cgroup\-rule）](#%E5%A4%84%E7%90%86%E5%8A%A8%E6%80%81%E5%88%9B%E5%BB%BA%E7%9A%84%E8%AE%BE%E5%A4%87--device-cgroup-rule)
  * [\* update 更新容器](#-update-%E6%9B%B4%E6%96%B0%E5%AE%B9%E5%99%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-2)
    * [示例](#%E7%A4%BA%E4%BE%8B-1)
      * [更新容器的cpu\-shares](#%E6%9B%B4%E6%96%B0%E5%AE%B9%E5%99%A8%E7%9A%84cpu-shares)
      * [使用cpu\-shares和内存更新容器](#%E4%BD%BF%E7%94%A8cpu-shares%E5%92%8C%E5%86%85%E5%AD%98%E6%9B%B4%E6%96%B0%E5%AE%B9%E5%99%A8)
      * [更新容器的内核内存限制](#%E6%9B%B4%E6%96%B0%E5%AE%B9%E5%99%A8%E7%9A%84%E5%86%85%E6%A0%B8%E5%86%85%E5%AD%98%E9%99%90%E5%88%B6)
      * [更新容器的重新启动策略](#%E6%9B%B4%E6%96%B0%E5%AE%B9%E5%99%A8%E7%9A%84%E9%87%8D%E6%96%B0%E5%90%AF%E5%8A%A8%E7%AD%96%E7%95%A5)
  * [\* commit 提交](#-commit-%E6%8F%90%E4%BA%A4)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-3)
    * [示例](#%E7%A4%BA%E4%BE%8B-2)
      * [提交一个容器](#%E6%8F%90%E4%BA%A4%E4%B8%80%E4%B8%AA%E5%AE%B9%E5%99%A8)
      * [提交新配置的容器](#%E6%8F%90%E4%BA%A4%E6%96%B0%E9%85%8D%E7%BD%AE%E7%9A%84%E5%AE%B9%E5%99%A8)
      * [提交修改后的CMD和EXPOSE容器](#%E6%8F%90%E4%BA%A4%E4%BF%AE%E6%94%B9%E5%90%8E%E7%9A%84cmd%E5%92%8Cexpose%E5%AE%B9%E5%99%A8)
  * [\* cp 复制文件](#-cp-%E5%A4%8D%E5%88%B6%E6%96%87%E4%BB%B6)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-4)
    * [示例](#%E7%A4%BA%E4%BE%8B-3)
  * [\* start 启动容器](#-start-%E5%90%AF%E5%8A%A8%E5%AE%B9%E5%99%A8)
  * [\* stop 停止容器](#-stop-%E5%81%9C%E6%AD%A2%E5%AE%B9%E5%99%A8)
  * [\* restart 重启容器](#-restart-%E9%87%8D%E5%90%AF%E5%AE%B9%E5%99%A8)
  * [\* rm 删除容器](#-rm-%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-5)
    * [示例](#%E7%A4%BA%E4%BE%8B-4)
      * [删除容器](#%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8)
      * [删除在默认网桥上使用\-\-link指定的链接](#%E5%88%A0%E9%99%A4%E5%9C%A8%E9%BB%98%E8%AE%A4%E7%BD%91%E6%A1%A5%E4%B8%8A%E4%BD%BF%E7%94%A8--link%E6%8C%87%E5%AE%9A%E7%9A%84%E9%93%BE%E6%8E%A5)
      * [强制删除正在运行的容器](#%E5%BC%BA%E5%88%B6%E5%88%A0%E9%99%A4%E6%AD%A3%E5%9C%A8%E8%BF%90%E8%A1%8C%E7%9A%84%E5%AE%B9%E5%99%A8)
      * [删除所有停止的容器](#%E5%88%A0%E9%99%A4%E6%89%80%E6%9C%89%E5%81%9C%E6%AD%A2%E7%9A%84%E5%AE%B9%E5%99%A8)
      * [删除出容器及数据卷](#%E5%88%A0%E9%99%A4%E5%87%BA%E5%AE%B9%E5%99%A8%E5%8F%8A%E6%95%B0%E6%8D%AE%E5%8D%B7)
      * [删除容器并选择性的删除卷](#%E5%88%A0%E9%99%A4%E5%AE%B9%E5%99%A8%E5%B9%B6%E9%80%89%E6%8B%A9%E6%80%A7%E7%9A%84%E5%88%A0%E9%99%A4%E5%8D%B7)
  * [\* rename 重命名容器](#-rename-%E9%87%8D%E5%91%BD%E5%90%8D%E5%AE%B9%E5%99%A8)
  * [\* attach 附加容器](#-attach-%E9%99%84%E5%8A%A0%E5%AE%B9%E5%99%A8)
    * [覆盖分离序列](#%E8%A6%86%E7%9B%96%E5%88%86%E7%A6%BB%E5%BA%8F%E5%88%97)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-6)
    * [示例](#%E7%A4%BA%E4%BE%8B-5)
      * [附加分离到正在运行的容器](#%E9%99%84%E5%8A%A0%E5%88%86%E7%A6%BB%E5%88%B0%E6%AD%A3%E5%9C%A8%E8%BF%90%E8%A1%8C%E7%9A%84%E5%AE%B9%E5%99%A8)
      * [获取容器命令的退出代码](#%E8%8E%B7%E5%8F%96%E5%AE%B9%E5%99%A8%E5%91%BD%E4%BB%A4%E7%9A%84%E9%80%80%E5%87%BA%E4%BB%A3%E7%A0%81)
  * [\* diff 比较容器](#-diff-%E6%AF%94%E8%BE%83%E5%AE%B9%E5%99%A8)
  * [\* exec 执行](#-exec-%E6%89%A7%E8%A1%8C)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-7)
    * [示例](#%E7%A4%BA%E4%BE%8B-6)
      * [在运行的容器上运行](#%E5%9C%A8%E8%BF%90%E8%A1%8C%E7%9A%84%E5%AE%B9%E5%99%A8%E4%B8%8A%E8%BF%90%E8%A1%8C)
      * [在暂停的容器上运行](#%E5%9C%A8%E6%9A%82%E5%81%9C%E7%9A%84%E5%AE%B9%E5%99%A8%E4%B8%8A%E8%BF%90%E8%A1%8C)
  * [\* export 导出容器](#-export-%E5%AF%BC%E5%87%BA%E5%AE%B9%E5%99%A8)
  * [\* import 导入容器](#-import-%E5%AF%BC%E5%85%A5%E5%AE%B9%E5%99%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-8)
    * [示例](#%E7%A4%BA%E4%BE%8B-7)
      * [从远程位置导入](#%E4%BB%8E%E8%BF%9C%E7%A8%8B%E4%BD%8D%E7%BD%AE%E5%AF%BC%E5%85%A5)
      * [从本地文件导入](#%E4%BB%8E%E6%9C%AC%E5%9C%B0%E6%96%87%E4%BB%B6%E5%AF%BC%E5%85%A5)
      * [从本地目录导入](#%E4%BB%8E%E6%9C%AC%E5%9C%B0%E7%9B%AE%E5%BD%95%E5%AF%BC%E5%85%A5)
      * [从具有新配置的本地目录导入](#%E4%BB%8E%E5%85%B7%E6%9C%89%E6%96%B0%E9%85%8D%E7%BD%AE%E7%9A%84%E6%9C%AC%E5%9C%B0%E7%9B%AE%E5%BD%95%E5%AF%BC%E5%85%A5)
  * [\* kill 杀死容器](#-kill-%E6%9D%80%E6%AD%BB%E5%AE%B9%E5%99%A8)
    * [示例](#%E7%A4%BA%E4%BE%8B-8)
      * [KILL一个容器](#kill%E4%B8%80%E4%B8%AA%E5%AE%B9%E5%99%A8)
      * [将自定义信号发送到容器](#%E5%B0%86%E8%87%AA%E5%AE%9A%E4%B9%89%E4%BF%A1%E5%8F%B7%E5%8F%91%E9%80%81%E5%88%B0%E5%AE%B9%E5%99%A8)
  * [\* logs 容器日志](#-logs-%E5%AE%B9%E5%99%A8%E6%97%A5%E5%BF%97)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-9)
    * [示例](#%E7%A4%BA%E4%BE%8B-9)
      * [跟踪日志](#%E8%B7%9F%E8%B8%AA%E6%97%A5%E5%BF%97)
      * [指定行数](#%E6%8C%87%E5%AE%9A%E8%A1%8C%E6%95%B0)
      * [时间戳](#%E6%97%B6%E9%97%B4%E6%88%B3)
      * [详细信息](#%E8%AF%A6%E7%BB%86%E4%BF%A1%E6%81%AF)
      * [日期过滤](#%E6%97%A5%E6%9C%9F%E8%BF%87%E6%BB%A4)
  * [\* wait 阻塞](#-wait-%E9%98%BB%E5%A1%9E)
    * [示例](#%E7%A4%BA%E4%BE%8B-10)
  * [\* pause 暂停容器](#-pause-%E6%9A%82%E5%81%9C%E5%AE%B9%E5%99%A8)
  * [\* unpause 取消暂停容器](#-unpause-%E5%8F%96%E6%B6%88%E6%9A%82%E5%81%9C%E5%AE%B9%E5%99%A8)
  * [\* port 容器端口](#-port-%E5%AE%B9%E5%99%A8%E7%AB%AF%E5%8F%A3)
  * [\* ps 查看容器](#-ps-%E6%9F%A5%E7%9C%8B%E5%AE%B9%E5%99%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-10)
    * [示例](#%E7%A4%BA%E4%BE%8B-11)
      * [防止截断输出](#%E9%98%B2%E6%AD%A2%E6%88%AA%E6%96%AD%E8%BE%93%E5%87%BA)
      * [显示所有容器](#%E6%98%BE%E7%A4%BA%E6%89%80%E6%9C%89%E5%AE%B9%E5%99%A8)
      * [显示最后和最新的容器](#%E6%98%BE%E7%A4%BA%E6%9C%80%E5%90%8E%E5%92%8C%E6%9C%80%E6%96%B0%E7%9A%84%E5%AE%B9%E5%99%A8)
      * [过滤](#%E8%BF%87%E6%BB%A4)
        * [标签过滤](#%E6%A0%87%E7%AD%BE%E8%BF%87%E6%BB%A4)
        * [状态过滤](#%E7%8A%B6%E6%80%81%E8%BF%87%E6%BB%A4)
        * [ancestor](#ancestor)
        * [创建时间](#%E5%88%9B%E5%BB%BA%E6%97%B6%E9%97%B4)
        * [卷](#%E5%8D%B7)
        * [网络](#%E7%BD%91%E7%BB%9C)
        * [发布/公开](#%E5%8F%91%E5%B8%83%E5%85%AC%E5%BC%80)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96)
  * [\* stats 统计容器](#-stats-%E7%BB%9F%E8%AE%A1%E5%AE%B9%E5%99%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-11)
    * [示例](#%E7%A4%BA%E4%BE%8B-12)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-1)
  * [\* top 显示](#-top-%E6%98%BE%E7%A4%BA)
  * [build 构建](#build-%E6%9E%84%E5%BB%BA)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-12)
    * [构建 URL 参数资源](#%E6%9E%84%E5%BB%BA-url-%E5%8F%82%E6%95%B0%E8%B5%84%E6%BA%90)
      * [Git 仓库](#git-%E4%BB%93%E5%BA%93)
      * [Tarball上下文](#tarball%E4%B8%8A%E4%B8%8B%E6%96%87)
      * [文本文件](#%E6%96%87%E6%9C%AC%E6%96%87%E4%BB%B6)
    * [示例](#%E7%A4%BA%E4%BE%8B-13)
      * [用 PATH 构建](#%E7%94%A8-path-%E6%9E%84%E5%BB%BA)
      * [用 URL 构建](#%E7%94%A8-url-%E6%9E%84%E5%BB%BA)
      * [用\-构建](#%E7%94%A8-%E6%9E%84%E5%BB%BA)
      * [使用\.dockerignore文件](#%E4%BD%BF%E7%94%A8dockerignore%E6%96%87%E4%BB%B6)
      * [镜像标签 (\-t)](#%E9%95%9C%E5%83%8F%E6%A0%87%E7%AD%BE--t)
      * [指定Dockerfile (\-f)](#%E6%8C%87%E5%AE%9Adockerfile--f)
      * [使用自定义父级cgroup (\-\-cgroup\-parent)](#%E4%BD%BF%E7%94%A8%E8%87%AA%E5%AE%9A%E4%B9%89%E7%88%B6%E7%BA%A7cgroup---cgroup-parent)
      * [在容器中设置ulimits （\-\-ulimit）](#%E5%9C%A8%E5%AE%B9%E5%99%A8%E4%B8%AD%E8%AE%BE%E7%BD%AEulimits---ulimit)
      * [设置生成时间变量 （\-\-build\-arg）](#%E8%AE%BE%E7%BD%AE%E7%94%9F%E6%88%90%E6%97%B6%E9%97%B4%E5%8F%98%E9%87%8F---build-arg)
      * [可选的安全选项（\-\-security\-opt）](#%E5%8F%AF%E9%80%89%E7%9A%84%E5%AE%89%E5%85%A8%E9%80%89%E9%A1%B9--security-opt)
      * [指定容器的隔离 （ \- isolation）](#%E6%8C%87%E5%AE%9A%E5%AE%B9%E5%99%A8%E7%9A%84%E9%9A%94%E7%A6%BB----isolation)
      * [将键值添加到容器host文件（\-\-add\-host）](#%E5%B0%86%E9%94%AE%E5%80%BC%E6%B7%BB%E5%8A%A0%E5%88%B0%E5%AE%B9%E5%99%A8host%E6%96%87%E4%BB%B6--add-host)
      * [指定目标构建阶段（\-\-target）](#%E6%8C%87%E5%AE%9A%E7%9B%AE%E6%A0%87%E6%9E%84%E5%BB%BA%E9%98%B6%E6%AE%B5--target)
      * [挤压镜像的图层 (\-\-squash) (experimental)](#%E6%8C%A4%E5%8E%8B%E9%95%9C%E5%83%8F%E7%9A%84%E5%9B%BE%E5%B1%82---squash-experimental)
  * [run 运行镜像](#run-%E8%BF%90%E8%A1%8C%E9%95%9C%E5%83%8F)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-13)
    * [示例](#%E7%A4%BA%E4%BE%8B-14)
      * [分配名称和TTY选项 \-\-name \-it](#%E5%88%86%E9%85%8D%E5%90%8D%E7%A7%B0%E5%92%8Ctty%E9%80%89%E9%A1%B9---name--it)
      * [提取容器ID \-\-cidfile](#%E6%8F%90%E5%8F%96%E5%AE%B9%E5%99%A8id---cidfile)
      * [完整的容器功能 \-\-privileged](#%E5%AE%8C%E6%95%B4%E7%9A%84%E5%AE%B9%E5%99%A8%E5%8A%9F%E8%83%BD---privileged)
      * [设置工作目录 \-w](#%E8%AE%BE%E7%BD%AE%E5%B7%A5%E4%BD%9C%E7%9B%AE%E5%BD%95--w)
      * [为容器设置存储驱动器选项](#%E4%B8%BA%E5%AE%B9%E5%99%A8%E8%AE%BE%E7%BD%AE%E5%AD%98%E5%82%A8%E9%A9%B1%E5%8A%A8%E5%99%A8%E9%80%89%E9%A1%B9)
      * [挂载tmpfs \-\-tmpfs](#%E6%8C%82%E8%BD%BDtmpfs---tmpfs)
      * [挂载卷 装入卷  \-v， \-\-read\-only](#%E6%8C%82%E8%BD%BD%E5%8D%B7-%E8%A3%85%E5%85%A5%E5%8D%B7---v---read-only)
      * [使用\-\-mount标志添加绑定挂载或卷](#%E4%BD%BF%E7%94%A8--mount%E6%A0%87%E5%BF%97%E6%B7%BB%E5%8A%A0%E7%BB%91%E5%AE%9A%E6%8C%82%E8%BD%BD%E6%88%96%E5%8D%B7)
      * [发布或公开端口 \-p，\-\-expose](#%E5%8F%91%E5%B8%83%E6%88%96%E5%85%AC%E5%BC%80%E7%AB%AF%E5%8F%A3--p--expose)
      * [设置环境变量 \-e，\-\-env，\-\-env\-file](#%E8%AE%BE%E7%BD%AE%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F--e--env--env-file)
      * [在容器上设置元数据 \-l，\-\-label，\-\-label\-file](#%E5%9C%A8%E5%AE%B9%E5%99%A8%E4%B8%8A%E8%AE%BE%E7%BD%AE%E5%85%83%E6%95%B0%E6%8D%AE--l--label--label-file)
      * [将容器连接到网络  \-\-network](#%E5%B0%86%E5%AE%B9%E5%99%A8%E8%BF%9E%E6%8E%A5%E5%88%B0%E7%BD%91%E7%BB%9C----network)
      * [从容器装入卷 \-\-volumes\-from](#%E4%BB%8E%E5%AE%B9%E5%99%A8%E8%A3%85%E5%85%A5%E5%8D%B7---volumes-from)
      * [附加到STDIN / STDOUT / STDERR \-a](#%E9%99%84%E5%8A%A0%E5%88%B0stdin--stdout--stderr--a)
      * [将主机设备添加到容器 \- 设备](#%E5%B0%86%E4%B8%BB%E6%9C%BA%E8%AE%BE%E5%A4%87%E6%B7%BB%E5%8A%A0%E5%88%B0%E5%AE%B9%E5%99%A8---%E8%AE%BE%E5%A4%87)
      * [重新启动策略 \-\-restart](#%E9%87%8D%E6%96%B0%E5%90%AF%E5%8A%A8%E7%AD%96%E7%95%A5---restart)
      * [将条目添加到容器host文件 \-\-add\-host](#%E5%B0%86%E6%9D%A1%E7%9B%AE%E6%B7%BB%E5%8A%A0%E5%88%B0%E5%AE%B9%E5%99%A8host%E6%96%87%E4%BB%B6---add-host)
      * [在容器中设置ulimits \-\-ulimit](#%E5%9C%A8%E5%AE%B9%E5%99%A8%E4%B8%AD%E8%AE%BE%E7%BD%AEulimits---ulimit-1)
      * [对于NPROC使用](#%E5%AF%B9%E4%BA%8Enproc%E4%BD%BF%E7%94%A8)
      * [停止带有信号的容器](#%E5%81%9C%E6%AD%A2%E5%B8%A6%E6%9C%89%E4%BF%A1%E5%8F%B7%E7%9A%84%E5%AE%B9%E5%99%A8)
      * [可选的安全选项（\-\-security\-opt）](#%E5%8F%AF%E9%80%89%E7%9A%84%E5%AE%89%E5%85%A8%E9%80%89%E9%A1%B9--security-opt-1)
      * [用超时停止容器（\-\-stop\-timeout）](#%E7%94%A8%E8%B6%85%E6%97%B6%E5%81%9C%E6%AD%A2%E5%AE%B9%E5%99%A8--stop-timeout)
      * [指定容器的隔离技术](#%E6%8C%87%E5%AE%9A%E5%AE%B9%E5%99%A8%E7%9A%84%E9%9A%94%E7%A6%BB%E6%8A%80%E6%9C%AF)
      * [指定容器可用内存](#%E6%8C%87%E5%AE%9A%E5%AE%B9%E5%99%A8%E5%8F%AF%E7%94%A8%E5%86%85%E5%AD%98)
      * [在运行时配置名称空间内核参数](#%E5%9C%A8%E8%BF%90%E8%A1%8C%E6%97%B6%E9%85%8D%E7%BD%AE%E5%90%8D%E7%A7%B0%E7%A9%BA%E9%97%B4%E5%86%85%E6%A0%B8%E5%8F%82%E6%95%B0)
      * [目前支持的SYSCTLS](#%E7%9B%AE%E5%89%8D%E6%94%AF%E6%8C%81%E7%9A%84sysctls)
  * [tag 镜像标签](#tag-%E9%95%9C%E5%83%8F%E6%A0%87%E7%AD%BE)
    * [标记由ID引用的镜像](#%E6%A0%87%E8%AE%B0%E7%94%B1id%E5%BC%95%E7%94%A8%E7%9A%84%E9%95%9C%E5%83%8F)
    * [标记名称引用的镜像](#%E6%A0%87%E8%AE%B0%E5%90%8D%E7%A7%B0%E5%BC%95%E7%94%A8%E7%9A%84%E9%95%9C%E5%83%8F)
    * [标记名称和标签引用的镜像](#%E6%A0%87%E8%AE%B0%E5%90%8D%E7%A7%B0%E5%92%8C%E6%A0%87%E7%AD%BE%E5%BC%95%E7%94%A8%E7%9A%84%E9%95%9C%E5%83%8F)
    * [为私人仓库标记镜像](#%E4%B8%BA%E7%A7%81%E4%BA%BA%E4%BB%93%E5%BA%93%E6%A0%87%E8%AE%B0%E9%95%9C%E5%83%8F)
  * [images 镜像列表](#images-%E9%95%9C%E5%83%8F%E5%88%97%E8%A1%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-14)
    * [示例](#%E7%A4%BA%E4%BE%8B-15)
      * [列出镜像](#%E5%88%97%E5%87%BA%E9%95%9C%E5%83%8F)
        * [列出最近创建的镜像](#%E5%88%97%E5%87%BA%E6%9C%80%E8%BF%91%E5%88%9B%E5%BB%BA%E7%9A%84%E9%95%9C%E5%83%8F)
        * [按名称和标签列出镜像](#%E6%8C%89%E5%90%8D%E7%A7%B0%E5%92%8C%E6%A0%87%E7%AD%BE%E5%88%97%E5%87%BA%E9%95%9C%E5%83%8F)
        * [列出镜像全长ID](#%E5%88%97%E5%87%BA%E9%95%9C%E5%83%8F%E5%85%A8%E9%95%BFid)
        * [列出镜像摘要](#%E5%88%97%E5%87%BA%E9%95%9C%E5%83%8F%E6%91%98%E8%A6%81)
      * [过滤](#%E8%BF%87%E6%BB%A4-1)
        * [显示未加标签的镜像](#%E6%98%BE%E7%A4%BA%E6%9C%AA%E5%8A%A0%E6%A0%87%E7%AD%BE%E7%9A%84%E9%95%9C%E5%83%8F)
        * [显示给定的标签镜像](#%E6%98%BE%E7%A4%BA%E7%BB%99%E5%AE%9A%E7%9A%84%E6%A0%87%E7%AD%BE%E9%95%9C%E5%83%8F)
        * [按时间过滤镜像](#%E6%8C%89%E6%97%B6%E9%97%B4%E8%BF%87%E6%BB%A4%E9%95%9C%E5%83%8F)
        * [通过引用过滤镜像](#%E9%80%9A%E8%BF%87%E5%BC%95%E7%94%A8%E8%BF%87%E6%BB%A4%E9%95%9C%E5%83%8F)
      * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA)
  * [history 镜像历史](#history-%E9%95%9C%E5%83%8F%E5%8E%86%E5%8F%B2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-15)
    * [示例](#%E7%A4%BA%E4%BE%8B-16)
      * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA-1)
  * [pull 拉取镜像](#pull-%E6%8B%89%E5%8F%96%E9%95%9C%E5%83%8F)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-16)
    * [代理配置](#%E4%BB%A3%E7%90%86%E9%85%8D%E7%BD%AE)
    * [并发下载](#%E5%B9%B6%E5%8F%91%E4%B8%8B%E8%BD%BD)
    * [示例](#%E7%A4%BA%E4%BE%8B-17)
      * [从Docker Hub中提取镜像](#%E4%BB%8Edocker-hub%E4%B8%AD%E6%8F%90%E5%8F%96%E9%95%9C%E5%83%8F)
      * [通过digest（不可变标识符）提取镜像](#%E9%80%9A%E8%BF%87digest%E4%B8%8D%E5%8F%AF%E5%8F%98%E6%A0%87%E8%AF%86%E7%AC%A6%E6%8F%90%E5%8F%96%E9%95%9C%E5%83%8F)
      * [从不同的注册表中提取](#%E4%BB%8E%E4%B8%8D%E5%90%8C%E7%9A%84%E6%B3%A8%E5%86%8C%E8%A1%A8%E4%B8%AD%E6%8F%90%E5%8F%96)
      * [使用多个镜像拉取一个仓库](#%E4%BD%BF%E7%94%A8%E5%A4%9A%E4%B8%AA%E9%95%9C%E5%83%8F%E6%8B%89%E5%8F%96%E4%B8%80%E4%B8%AA%E4%BB%93%E5%BA%93)
      * [取消拉取](#%E5%8F%96%E6%B6%88%E6%8B%89%E5%8F%96)
  * [push 推送镜像](#push-%E6%8E%A8%E9%80%81%E9%95%9C%E5%83%8F)
    * [并发上传](#%E5%B9%B6%E5%8F%91%E4%B8%8A%E4%BC%A0)
    * [示例](#%E7%A4%BA%E4%BE%8B-18)
  * [rmi 删除镜像](#rmi-%E5%88%A0%E9%99%A4%E9%95%9C%E5%83%8F)
    * [示例](#%E7%A4%BA%E4%BE%8B-19)
  * [save 备份镜像](#save-%E5%A4%87%E4%BB%BD%E9%95%9C%E5%83%8F)
    * [示例](#%E7%A4%BA%E4%BE%8B-20)
      * [创建备份](#%E5%88%9B%E5%BB%BA%E5%A4%87%E4%BB%BD)
      * [选择特定的标签](#%E9%80%89%E6%8B%A9%E7%89%B9%E5%AE%9A%E7%9A%84%E6%A0%87%E7%AD%BE)
  * [load 装载镜像](#load-%E8%A3%85%E8%BD%BD%E9%95%9C%E5%83%8F)
  * [search 搜索镜像](#search-%E6%90%9C%E7%B4%A2%E9%95%9C%E5%83%8F)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-17)
    * [示例](#%E7%A4%BA%E4%BE%8B-21)
      * [按名称搜索镜像](#%E6%8C%89%E5%90%8D%E7%A7%B0%E6%90%9C%E7%B4%A2%E9%95%9C%E5%83%8F)
      * [显示非截断描述（\-\-no\-trunc）](#%E6%98%BE%E7%A4%BA%E9%9D%9E%E6%88%AA%E6%96%AD%E6%8F%8F%E8%BF%B0--no-trunc)
      * [限制搜索结果（\-\-limit）](#%E9%99%90%E5%88%B6%E6%90%9C%E7%B4%A2%E7%BB%93%E6%9E%9C--limit)
      * [过滤](#%E8%BF%87%E6%BB%A4-2)
      * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA-2)
  * [login 登陆](#login-%E7%99%BB%E9%99%86)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-18)
    * [示例](#%E7%A4%BA%E4%BE%8B-22)
      * [登录到自我托管的注册表](#%E7%99%BB%E5%BD%95%E5%88%B0%E8%87%AA%E6%88%91%E6%89%98%E7%AE%A1%E7%9A%84%E6%B3%A8%E5%86%8C%E8%A1%A8)
      * [使用STDIN提供密码](#%E4%BD%BF%E7%94%A8stdin%E6%8F%90%E4%BE%9B%E5%AF%86%E7%A0%81)
      * [特权用户需求](#%E7%89%B9%E6%9D%83%E7%94%A8%E6%88%B7%E9%9C%80%E6%B1%82)
      * [凭证商店](#%E5%87%AD%E8%AF%81%E5%95%86%E5%BA%97)
      * [默认行为](#%E9%BB%98%E8%AE%A4%E8%A1%8C%E4%B8%BA)
      * [凭证帮助程序协议](#%E5%87%AD%E8%AF%81%E5%B8%AE%E5%8A%A9%E7%A8%8B%E5%BA%8F%E5%8D%8F%E8%AE%AE)
      * [凭证助手](#%E5%87%AD%E8%AF%81%E5%8A%A9%E6%89%8B)
      * [注销](#%E6%B3%A8%E9%94%80)
  * [logout 注销](#logout-%E6%B3%A8%E9%94%80)
  * [info 系统信息](#info-%E7%B3%BB%E7%BB%9F%E4%BF%A1%E6%81%AF)
    * [示例](#%E7%A4%BA%E4%BE%8B-23)
      * [显示输出](#%E6%98%BE%E7%A4%BA%E8%BE%93%E5%87%BA)
      * [显示调试输出](#%E6%98%BE%E7%A4%BA%E8%B0%83%E8%AF%95%E8%BE%93%E5%87%BA)
      * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA-3)
      * [关于内核支持的警告](#%E5%85%B3%E4%BA%8E%E5%86%85%E6%A0%B8%E6%94%AF%E6%8C%81%E7%9A%84%E8%AD%A6%E5%91%8A)
  * [inspect 查看详细](#inspect-%E6%9F%A5%E7%9C%8B%E8%AF%A6%E7%BB%86)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-19)
    * [示例](#%E7%A4%BA%E4%BE%8B-24)
      * [获取实例的IP地址](#%E8%8E%B7%E5%8F%96%E5%AE%9E%E4%BE%8B%E7%9A%84ip%E5%9C%B0%E5%9D%80)
      * [获取实例的MAC地址](#%E8%8E%B7%E5%8F%96%E5%AE%9E%E4%BE%8B%E7%9A%84mac%E5%9C%B0%E5%9D%80)
      * [获取实例的日志路径](#%E8%8E%B7%E5%8F%96%E5%AE%9E%E4%BE%8B%E7%9A%84%E6%97%A5%E5%BF%97%E8%B7%AF%E5%BE%84)
      * [获取实例的镜像名称](#%E8%8E%B7%E5%8F%96%E5%AE%9E%E4%BE%8B%E7%9A%84%E9%95%9C%E5%83%8F%E5%90%8D%E7%A7%B0)
      * [列出所有端口绑定](#%E5%88%97%E5%87%BA%E6%89%80%E6%9C%89%E7%AB%AF%E5%8F%A3%E7%BB%91%E5%AE%9A)
      * [找到一个特定的端口映射](#%E6%89%BE%E5%88%B0%E4%B8%80%E4%B8%AA%E7%89%B9%E5%AE%9A%E7%9A%84%E7%AB%AF%E5%8F%A3%E6%98%A0%E5%B0%84)
      * [以JSON格式获取子部分](#%E4%BB%A5json%E6%A0%BC%E5%BC%8F%E8%8E%B7%E5%8F%96%E5%AD%90%E9%83%A8%E5%88%86)
  * [events 系统事件](#events-%E7%B3%BB%E7%BB%9F%E4%BA%8B%E4%BB%B6)
  * [version 系统版本](#version-%E7%B3%BB%E7%BB%9F%E7%89%88%E6%9C%AC)
* [container 管理容器](#container-%E7%AE%A1%E7%90%86%E5%AE%B9%E5%99%A8)
* [config 管理配置](#config-%E7%AE%A1%E7%90%86%E9%85%8D%E7%BD%AE)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-20)
    * [示例](#%E7%A4%BA%E4%BE%8B-25)
  * [inspect 查看](#inspect-%E6%9F%A5%E7%9C%8B)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-21)
    * [示例](#%E7%A4%BA%E4%BE%8B-26)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4)
* [checkpoint 检查点](#checkpoint-%E6%A3%80%E6%9F%A5%E7%82%B9)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-22)
    * [示例](#%E7%A4%BA%E4%BE%8B-27)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-1)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-1)
* [image 管理镜像](#image-%E7%AE%A1%E7%90%86%E9%95%9C%E5%83%8F)
  * [build 构建](#build-%E6%9E%84%E5%BB%BA-1)
  * [history 历史](#history-%E5%8E%86%E5%8F%B2)
  * [import 导入](#import-%E5%AF%BC%E5%85%A5)
  * [inspect 详细](#inspect-%E8%AF%A6%E7%BB%86)
  * [load 加载](#load-%E5%8A%A0%E8%BD%BD)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-2)
  * [prune 修剪](#prune-%E4%BF%AE%E5%89%AA)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-23)
    * [示例](#%E7%A4%BA%E4%BE%8B-28)
      * [过滤](#%E8%BF%87%E6%BB%A4-3)
  * [pull 拉取](#pull-%E6%8B%89%E5%8F%96)
  * [push 推送](#push-%E6%8E%A8%E9%80%81)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-2)
  * [save 保存](#save-%E4%BF%9D%E5%AD%98)
  * [tag 标签](#tag-%E6%A0%87%E7%AD%BE)
* [network 管理网络](#network-%E7%AE%A1%E7%90%86%E7%BD%91%E7%BB%9C)
  * [ls 查看](#ls-%E6%9F%A5%E7%9C%8B)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-24)
    * [示例](#%E7%A4%BA%E4%BE%8B-29)
      * [查看网络](#%E6%9F%A5%E7%9C%8B%E7%BD%91%E7%BB%9C)
      * [查看过滤](#%E6%9F%A5%E7%9C%8B%E8%BF%87%E6%BB%A4)
      * [查看格式化](#%E6%9F%A5%E7%9C%8B%E6%A0%BC%E5%BC%8F%E5%8C%96)
      * [其他](#%E5%85%B6%E4%BB%96)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA-2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-25)
    * [延伸阅读](#%E5%BB%B6%E4%BC%B8%E9%98%85%E8%AF%BB)
      * [覆盖网络限制](#%E8%A6%86%E7%9B%96%E7%BD%91%E7%BB%9C%E9%99%90%E5%88%B6)
    * [示例](#%E7%A4%BA%E4%BE%8B-30)
      * [创建网络](#%E5%88%9B%E5%BB%BA%E7%BD%91%E7%BB%9C)
      * [连接容器](#%E8%BF%9E%E6%8E%A5%E5%AE%B9%E5%99%A8)
      * [高级选项](#%E9%AB%98%E7%BA%A7%E9%80%89%E9%A1%B9)
      * [桥模式选项](#%E6%A1%A5%E6%A8%A1%E5%BC%8F%E9%80%89%E9%A1%B9)
      * [网络内部模式](#%E7%BD%91%E7%BB%9C%E5%86%85%E9%83%A8%E6%A8%A1%E5%BC%8F)
      * [网络ingress模式](#%E7%BD%91%E7%BB%9Cingress%E6%A8%A1%E5%BC%8F)
  * [connect 连接](#connect-%E8%BF%9E%E6%8E%A5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-26)
    * [示例](#%E7%A4%BA%E4%BE%8B-31)
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
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-3)
* [plugin 管理插件](#plugin-%E7%AE%A1%E7%90%86%E6%8F%92%E4%BB%B6)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA-3)
  * [install 安装](#install-%E5%AE%89%E8%A3%85)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-27)
    * [示例](#%E7%A4%BA%E4%BE%8B-32)
  * [disable 禁用](#disable-%E7%A6%81%E7%94%A8)
  * [enable 启用](#enable-%E5%90%AF%E7%94%A8)
  * [inspect 查看](#inspect-%E6%9F%A5%E7%9C%8B-1)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-3)
    * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-2)
  * [push 推送](#push-%E6%8E%A8%E9%80%81-1)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-4)
  * [set 设置](#set-%E8%AE%BE%E7%BD%AE)
    * [更改环境变量](#%E6%9B%B4%E6%94%B9%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F)
    * [更改安装源](#%E6%9B%B4%E6%94%B9%E5%AE%89%E8%A3%85%E6%BA%90)
    * [更改设备路径](#%E6%9B%B4%E6%94%B9%E8%AE%BE%E5%A4%87%E8%B7%AF%E5%BE%84)
    * [更改参数的来源](#%E6%9B%B4%E6%94%B9%E5%8F%82%E6%95%B0%E7%9A%84%E6%9D%A5%E6%BA%90)
  * [upgrade 升级](#upgrade-%E5%8D%87%E7%BA%A7)
* [volume 管理数据卷](#volume-%E7%AE%A1%E7%90%86%E6%95%B0%E6%8D%AE%E5%8D%B7)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA-4)
    * [基本选项](#%E5%9F%BA%E6%9C%AC%E9%80%89%E9%A1%B9)
    * [创建卷](#%E5%88%9B%E5%BB%BA%E5%8D%B7)
    * [使用卷](#%E4%BD%BF%E7%94%A8%E5%8D%B7)
    * [驱动程序特定的选项](#%E9%A9%B1%E5%8A%A8%E7%A8%8B%E5%BA%8F%E7%89%B9%E5%AE%9A%E7%9A%84%E9%80%89%E9%A1%B9)
  * [ls 查看](#ls-%E6%9F%A5%E7%9C%8B-1)
    * [基本选项](#%E5%9F%BA%E6%9C%AC%E9%80%89%E9%A1%B9-1)
    * [过滤](#%E8%BF%87%E6%BB%A4-4)
      * [dangling 是否引用](#dangling-%E6%98%AF%E5%90%A6%E5%BC%95%E7%94%A8)
      * [driver 驱动](#driver-%E9%A9%B1%E5%8A%A8)
      * [label 标签](#label-%E6%A0%87%E7%AD%BE)
      * [name 称](#name-%E7%A7%B0)
    * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-3)
  * [inspect 检查](#inspect-%E6%A3%80%E6%9F%A5-1)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-5)
  * [prune 裁剪](#prune-%E8%A3%81%E5%89%AA)
* [secret 管理私密](#secret-%E7%AE%A1%E7%90%86%E7%A7%81%E5%AF%86)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA-5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-28)
    * [示例](#%E7%A4%BA%E4%BE%8B-33)
      * [创建secret](#%E5%88%9B%E5%BB%BAsecret)
      * [用文件创建](#%E7%94%A8%E6%96%87%E4%BB%B6%E5%88%9B%E5%BB%BA)
      * [用标签创建](#%E7%94%A8%E6%A0%87%E7%AD%BE%E5%88%9B%E5%BB%BA)
  * [inspect 查看](#inspect-%E6%9F%A5%E7%9C%8B-2)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-4)
    * [过滤](#%E8%BF%87%E6%BB%A4-5)
    * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA-4)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-6)
* [system 管理系统](#system-%E7%AE%A1%E7%90%86%E7%B3%BB%E7%BB%9F)
  * [df  查看磁盘空间](#df--%E6%9F%A5%E7%9C%8B%E7%A3%81%E7%9B%98%E7%A9%BA%E9%97%B4)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-29)
    * [示例](#%E7%A4%BA%E4%BE%8B-34)
  * [events 事件](#events-%E4%BA%8B%E4%BB%B6)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-30)
    * [事件对象类型](#%E4%BA%8B%E4%BB%B6%E5%AF%B9%E8%B1%A1%E7%B1%BB%E5%9E%8B)
      * [集装箱](#%E9%9B%86%E8%A3%85%E7%AE%B1)
      * [镜像](#%E9%95%9C%E5%83%8F)
      * [插件](#%E6%8F%92%E4%BB%B6)
      * [卷](#%E5%8D%B7-1)
      * [网络](#%E7%BD%91%E7%BB%9C-1)
      * [守护进程](#%E5%AE%88%E6%8A%A4%E8%BF%9B%E7%A8%8B)
    * [过滤 &amp; 格式化](#%E8%BF%87%E6%BB%A4--%E6%A0%BC%E5%BC%8F%E5%8C%96)
      * [按时间限制事件](#%E6%8C%89%E6%97%B6%E9%97%B4%E9%99%90%E5%88%B6%E4%BA%8B%E4%BB%B6)
      * [过滤](#%E8%BF%87%E6%BB%A4-6)
      * [格式](#%E6%A0%BC%E5%BC%8F)
    * [示例](#%E7%A4%BA%E4%BE%8B-35)
      * [基本示例](#%E5%9F%BA%E6%9C%AC%E7%A4%BA%E4%BE%8B)
      * [按时间过滤事件](#%E6%8C%89%E6%97%B6%E9%97%B4%E8%BF%87%E6%BB%A4%E4%BA%8B%E4%BB%B6)
      * [按标准过滤事件](#%E6%8C%89%E6%A0%87%E5%87%86%E8%BF%87%E6%BB%A4%E4%BA%8B%E4%BB%B6)
      * [格式化输出](#%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%BE%93%E5%87%BA-5)
  * [info 信息](#info-%E4%BF%A1%E6%81%AF)
  * [prune 修剪](#prune-%E4%BF%AE%E5%89%AA-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-31)
    * [示例](#%E7%A4%BA%E4%BE%8B-36)
* [node 管理集群节点](#node-%E7%AE%A1%E7%90%86%E9%9B%86%E7%BE%A4%E8%8A%82%E7%82%B9)
  * [demote 降级](#demote-%E9%99%8D%E7%BA%A7)
  * [promote 升级](#promote-%E5%8D%87%E7%BA%A7)
  * [inspect 检查](#inspect-%E6%A3%80%E6%9F%A5-2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-32)
    * [示例](#%E7%A4%BA%E4%BE%8B-37)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-33)
    * [示例](#%E7%A4%BA%E4%BE%8B-38)
      * [查看节点](#%E6%9F%A5%E7%9C%8B%E8%8A%82%E7%82%B9)
      * [过滤](#%E8%BF%87%E6%BB%A4-7)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-4)
  * [ps 查看任务](#ps-%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-34)
    * [示例](#%E7%A4%BA%E4%BE%8B-39)
      * [查看任务](#%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1)
      * [过滤](#%E8%BF%87%E6%BB%A4-8)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-7)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-35)
    * [示例](#%E7%A4%BA%E4%BE%8B-40)
      * [删除停止节点](#%E5%88%A0%E9%99%A4%E5%81%9C%E6%AD%A2%E8%8A%82%E7%82%B9)
      * [删除运行节点](#%E5%88%A0%E9%99%A4%E8%BF%90%E8%A1%8C%E8%8A%82%E7%82%B9)
      * [强行删除不可访问的节点](#%E5%BC%BA%E8%A1%8C%E5%88%A0%E9%99%A4%E4%B8%8D%E5%8F%AF%E8%AE%BF%E9%97%AE%E7%9A%84%E8%8A%82%E7%82%B9)
  * [update 更新](#update-%E6%9B%B4%E6%96%B0)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-36)
    * [示例](#%E7%A4%BA%E4%BE%8B-41)
* [service 管理服务](#service-%E7%AE%A1%E7%90%86%E6%9C%8D%E5%8A%A1)
  * [create 创建](#create-%E5%88%9B%E5%BB%BA-6)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-37)
    * [示例](#%E7%A4%BA%E4%BE%8B-42)
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
  * [inspect 检查](#inspect-%E6%A3%80%E6%9F%A5-3)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-38)
    * [示例](#%E7%A4%BA%E4%BE%8B-43)
      * [按名称或ID检查服务](#%E6%8C%89%E5%90%8D%E7%A7%B0%E6%88%96id%E6%A3%80%E6%9F%A5%E6%9C%8D%E5%8A%A1)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-5)
  * [logs 日志](#logs-%E6%97%A5%E5%BF%97)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-39)
    * [示例](#%E7%A4%BA%E4%BE%8B-44)
      * [查看日志](#%E6%9F%A5%E7%9C%8B%E6%97%A5%E5%BF%97)
      * [跟踪日志](#%E8%B7%9F%E8%B8%AA%E6%97%A5%E5%BF%97-1)
      * [查看指定行数](#%E6%9F%A5%E7%9C%8B%E6%8C%87%E5%AE%9A%E8%A1%8C%E6%95%B0)
      * [时间戳](#%E6%97%B6%E9%97%B4%E6%88%B3-1)
      * [额外详细信息](#%E9%A2%9D%E5%A4%96%E8%AF%A6%E7%BB%86%E4%BF%A1%E6%81%AF)
      * [日期过滤](#%E6%97%A5%E6%9C%9F%E8%BF%87%E6%BB%A4-1)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-6)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-40)
    * [示例](#%E7%A4%BA%E4%BE%8B-45)
      * [查看](#%E6%9F%A5%E7%9C%8B)
      * [过滤](#%E8%BF%87%E6%BB%A4-9)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-6)
  * [ps 任务列表](#ps-%E4%BB%BB%E5%8A%A1%E5%88%97%E8%A1%A8)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-41)
    * [示例](#%E7%A4%BA%E4%BE%8B-46)
      * [查看任务](#%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1-1)
      * [过滤](#%E8%BF%87%E6%BB%A4-10)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-7)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-8)
  * [rollback 回滚](#rollback-%E5%9B%9E%E6%BB%9A)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-42)
    * [示例](#%E7%A4%BA%E4%BE%8B-47)
  * [scale 副本比例](#scale-%E5%89%AF%E6%9C%AC%E6%AF%94%E4%BE%8B)
    * [示例](#%E7%A4%BA%E4%BE%8B-48)
      * [扩展单个服务](#%E6%89%A9%E5%B1%95%E5%8D%95%E4%B8%AA%E6%9C%8D%E5%8A%A1)
      * [扩展多个服务](#%E6%89%A9%E5%B1%95%E5%A4%9A%E4%B8%AA%E6%9C%8D%E5%8A%A1)
  * [update 更新](#update-%E6%9B%B4%E6%96%B0-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-43)
    * [示例](#%E7%A4%BA%E4%BE%8B-49)
      * [更新服务](#%E6%9B%B4%E6%96%B0%E6%9C%8D%E5%8A%A1)
      * [在不更改参数的情况下执行滚动重启](#%E5%9C%A8%E4%B8%8D%E6%9B%B4%E6%94%B9%E5%8F%82%E6%95%B0%E7%9A%84%E6%83%85%E5%86%B5%E4%B8%8B%E6%89%A7%E8%A1%8C%E6%BB%9A%E5%8A%A8%E9%87%8D%E5%90%AF)
      * [添加或删除挂载](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E6%8C%82%E8%BD%BD)
      * [添加或删除已发布的服务端口](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E5%B7%B2%E5%8F%91%E5%B8%83%E7%9A%84%E6%9C%8D%E5%8A%A1%E7%AB%AF%E5%8F%A3)
      * [添加或删除网络](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E7%BD%91%E7%BB%9C)
      * [回滚到服务的先前版本](#%E5%9B%9E%E6%BB%9A%E5%88%B0%E6%9C%8D%E5%8A%A1%E7%9A%84%E5%85%88%E5%89%8D%E7%89%88%E6%9C%AC)
      * [添加或删除秘密](#%E6%B7%BB%E5%8A%A0%E6%88%96%E5%88%A0%E9%99%A4%E7%A7%98%E5%AF%86)
* [swarm 管理集群](#swarm-%E7%AE%A1%E7%90%86%E9%9B%86%E7%BE%A4)
  * [ca 证书](#ca-%E8%AF%81%E4%B9%A6)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-44)
    * [\-\-rotate](#--rotate)
    * [\-\-detach](#--detach)
    * [示例](#%E7%A4%BA%E4%BE%8B-50)
      * [生成证书](#%E7%94%9F%E6%88%90%E8%AF%81%E4%B9%A6)
      * [轮转证书](#%E8%BD%AE%E8%BD%AC%E8%AF%81%E4%B9%A6)
  * [init 初始化](#init-%E5%88%9D%E5%A7%8B%E5%8C%96)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-45)
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
    * [示例](#%E7%A4%BA%E4%BE%8B-51)
      * [创建集群](#%E5%88%9B%E5%BB%BA%E9%9B%86%E7%BE%A4)
  * [join 加入](#join-%E5%8A%A0%E5%85%A5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-46)
    * [\-\-listen\-addr value](#--listen-addr-value)
    * [\-\-advertise\-addr value](#--advertise-addr-value)
    * [\-\-data\-path\-addr](#--data-path-addr-1)
    * [\-\-token string](#--token-string)
    * [\-\-availability](#--availability-1)
    * [示例](#%E7%A4%BA%E4%BE%8B-52)
      * [加入管理节点](#%E5%8A%A0%E5%85%A5%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9)
      * [加入工作节点](#%E5%8A%A0%E5%85%A5%E5%B7%A5%E4%BD%9C%E8%8A%82%E7%82%B9)
  * [join\-token 令牌](#join-token-%E4%BB%A4%E7%89%8C)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-47)
    * [示例](#%E7%A4%BA%E4%BE%8B-53)
      * [获取加入工作节点的token](#%E8%8E%B7%E5%8F%96%E5%8A%A0%E5%85%A5%E5%B7%A5%E4%BD%9C%E8%8A%82%E7%82%B9%E7%9A%84token)
      * [获取加入管理节点的token](#%E8%8E%B7%E5%8F%96%E5%8A%A0%E5%85%A5%E7%AE%A1%E7%90%86%E8%8A%82%E7%82%B9%E7%9A%84token)
      * [查看token](#%E6%9F%A5%E7%9C%8Btoken)
      * [轮转](#%E8%BD%AE%E8%BD%AC)
  * [leave 离开](#leave-%E7%A6%BB%E5%BC%80)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-48)
    * [示例](#%E7%A4%BA%E4%BE%8B-54)
  * [unlock 解锁](#unlock-%E8%A7%A3%E9%94%81)
  * [unlock\-key 解锁秘钥](#unlock-key-%E8%A7%A3%E9%94%81%E7%A7%98%E9%92%A5)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-49)
    * [示例](#%E7%A4%BA%E4%BE%8B-55)
  * [update 更新](#update-%E6%9B%B4%E6%96%B0-2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-50)
    * [示例](#%E7%A4%BA%E4%BE%8B-56)
* [stack 服务编排](#stack-%E6%9C%8D%E5%8A%A1%E7%BC%96%E6%8E%92)
  * [deploy 部署](#deploy-%E9%83%A8%E7%BD%B2)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-51)
    * [示例](#%E7%A4%BA%E4%BE%8B-57)
      * [Compose 文件](#compose-%E6%96%87%E4%BB%B6)
      * [DAB文件](#dab%E6%96%87%E4%BB%B6)
  * [ls 列表](#ls-%E5%88%97%E8%A1%A8-7)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-52)
    * [示例](#%E7%A4%BA%E4%BE%8B-58)
      * [查看](#%E6%9F%A5%E7%9C%8B-1)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-8)
  * [ps 查看任务](#ps-%E6%9F%A5%E7%9C%8B%E4%BB%BB%E5%8A%A1-1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-53)
    * [示例](#%E7%A4%BA%E4%BE%8B-59)
      * [查看](#%E6%9F%A5%E7%9C%8B-2)
      * [过滤](#%E8%BF%87%E6%BB%A4-11)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-9)
  * [rm 删除](#rm-%E5%88%A0%E9%99%A4-9)
  * [services 查看服务](#services-%E6%9F%A5%E7%9C%8B%E6%9C%8D%E5%8A%A1)
    * [命令参数选项](#%E5%91%BD%E4%BB%A4%E5%8F%82%E6%95%B0%E9%80%89%E9%A1%B9-54)
    * [示例](#%E7%A4%BA%E4%BE%8B-60)
      * [查看](#%E6%9F%A5%E7%9C%8B-3)
      * [过滤](#%E8%BF%87%E6%BB%A4-12)
      * [格式化](#%E6%A0%BC%E5%BC%8F%E5%8C%96-10)




# docker 命令简介

根据Docker系统配置，可能需要使用`sudo`为每个docker命令添加前缀。为了避免必须使用docker命令使用`sudo`，系统管理员可以创建一个名为`docker`的**Unix组**并向其添加**用户**。

## 命令参数选项

```sh
$ docker -h
Usage:  docker COMMAND
Docker CLI的基本命令

Options:
      --config string      客户端配置文件的位置 (default "C:\\Users\\Administrator\\.docker")
  -D, --debug              启用调试模式
  -H, --host list          要连接到的守护程序套接字
  -l, --log-level string   设置日志级别
                           ("debug"|"info"|"warn"|"error"|"fatal")
                           (default "info")
      --tls                使用TLS;由--tlsverify
      --tlscacert string   仅由此CA签名的信任证书 (default
                          "C:\\Users\\Administrator\\.docker\\machine\\machines\\manager1\\ca.pem")
      --tlscert string     TLS证书文件的路径 (default
                        "C:\\Users\\Administrator\\.docker\\machine\\machines\\manager1\\cert.pem")
      --tlskey string      TLS密钥文件的路径 (default
                         "C:\\Users\\Administrator\\.docker\\machine\\machines\\manager1\\key.pem")
      --tlsverify          使用TLS并验证远程 (default true)
  -v, --version            打印版本信息并退出

Management Commands:
  config      # 管理Docker配置
  container   # 管理容器
  image       # 管理镜像
  network     # 管理网络
  node        # 管理集群节点
  plugin      # 管理插件
  secret      # 管理私密
  service     # 管理服务
  swarm       # 管理集群
  system      # 管理docker 系统
  trust       # 管理Docker镜像上的信任
  volume      # 管理挂载卷
  stack		 # 管理Docker堆栈

Commands:
  attach      # 将本地标准输入，输出和错误流附加到正在运行的容器
  build       # 从Dockerfile构建镜像
  commit      # 根据容器的更改创建新镜像
  cp          # 复制容器和本地文件系统之间的文件/文件夹
  create      # 创建一个新的容器
  deploy      # 部署新的堆栈或更新现有的堆栈
  diff        # 检查对容器文件系统上文件或目录的更改
  events      # 从服务器获取实时事件
  exec        # 在正在运行的容器中运行命令
  export      # 将容器的文件系统导出为tar存档
  history     # 显示镜像的历史记录
  images      # 列出镜像
  import      # 从tarball中导入内容以创建文件系统镜像
  info        # 显示系统广泛的信息
  inspect     # 返回有关Docker对象的低级信息
  kill        # 杀死一个或多个正在运行的容器
  load        # 从tar档案或STDIN加载镜像
  login       # 登录到Docker注册表
  logout      # 从Docker注册表中注销
  logs        # 获取容器的日志
  manifest    # 管理Docker镜像清单和清单列表
  pause       # 暂停一个或多个容器内的所有进程
  port        # 列出容器的端口映射或特定映射
  ps          # 列出容器
  pull        # 从注册表中提取镜像或仓库
  push        # 将镜像或仓库推送到注册表
  rename      # 重命名一个容器
  restart     # 重新启动一个或多个容器
  rm          # 删除一个或多个容器
  rmi         # 删除一个或多个镜像
  run         # 在新容器中运行命令
  save        # 将一个或多个镜像保存到tar归档文件（默认流式传输到STDOUT）
  search      # 在Docker Hub中搜索镜像
  start       # 启动一个或多个停止的容器
  stats       # 显示容器资源使用统计信息的实时流
  stop        # 停止一个或多个运行容器
  tag         # 创建一个引用SOURCE_IMAGE的标记TARGET_IMAGE
  top         # 显示容器的运行过程
  unpause     # 取消暂停一个或多个容器内的所有进程
  update      # 更新一个或多个容器的配置
  version     # 显示Docker版本信息
  wait        # 阻塞，直到一个或多个容器停止，然后打印退出代码
```

## 环境变量

为了便于参考，`docker`命令行支持以下环境变量列表：

- `DOCKER_API_VERSION`要使用的**API版本**（例如`1.19`）
- `DOCKER_CONFIG` 你的**客户端配置文件**的位置。
- `DOCKER_CERT_PATH` 你的**身份验证密钥**的位置。
- `DOCKER_DRIVER` 要使用的**驱动**程序。
- `DOCKER_HOST` 守护进程**套接字**连接。
- `DOCKER_NOWARN_KERNEL_VERSION` 防止你的Linux**内核**不适合Docker的警告。
- `DOCKER_RAMDISK` 如果设置这将**禁用'pivot_root'**。
- `DOCKER_TLS` 设置Docker**使用TLS**。
- `DOCKER_TLS_VERIFY` 当设置Docker使用TLS并**远程验证**。
- `DOCKER_CONTENT_TRUST`设置Docker时使用**公证人签名**和**验证镜像**。等于`--disable-content-trust=false` `build, create, pull, push, run `。
- `DOCKER_CONTENT_TRUST_SERVER`要使用的**公证服务器的URL**。这默认与注册表相同的URL。
- `DOCKER_HIDE_LEGACY_COMMANDS`设置后，Docker会在**输出中隐藏“传统”顶级命令**（如`docker rm`，和`docker pull`）`docker help`，并且仅打印`Management commands`每个对象类型（例如，`docker container`）。这可能会成为未来版本中的默认值，此时会删除此环境变量。
- `DOCKER_TMPDIR` **临时Docker文件**的位置。

由于Docker是使用Go开发的，因此还可以使用Go运行时使用的任何环境变量。特别是，你可能会发现这些有用的：

- `HTTP_PROXY`
- `HTTPS_PROXY`
- `NO_PROXY`

这些Go环境变量不区分大小写。

## 配置文件

默认情况下，Docker命令行将其**配置文件存储在`$HOME`目录下名为`.docker`的目录**中。但是，可以**通过`DOCKER_CONFIG`环境变量或`--config`命令行选项指定不同的位置**。如果两者都指定，则`--config`选项将**覆盖**`DOCKER_CONFIG`环境变量。例如：

```sh
$ docker --config ~/testconfigs/ ps
```

指示Docker在运行ps命令时使用`~/testconfigs/`目录中的配置文件。

Docker管理配置目录中的大部分文件，不应修改它们。但是，可以**修改**`config.json`文件来控制docker命令行为的某些方面。

目前，可以使用环境变量或命令行选项修改docker命令行为。你也可以使用`config.json`中的选项来修改一些相同的行为。在使用这些机制时，必须牢记其中的优先顺序。**命令行选项覆盖环境变量，环境变量覆盖你在config.json文件中指定的属性**。

### 自定义格式化输出

---

**`config.json`文件存储了几个属性的JSON编码：**

`HttpHeaders`属性指定一组标题，以包含从Docker客户端发送到守护程序的所有消息。Docker不会试图解释或理解这些头文件，它只是将它们放入消息中。Docker不允许这些头文件改变它自己设置的头文件。

属性`psFormat`指定`docker ps`输出的默认格式。当`docker ps`命令未提供`--format`选项时，Docker的客户端使用此属性。如果未设置此属性，则客户端将回到默认表格格式。

属性`imagesFormat`指定`docker images` 输出的默认格式。当`docker images`命令没有提供`--format`选项时，Docker的客户端使用这个属性。如果未设置此属性，则客户端将回到默认表格格式。

属性`pluginsFormat`指定`docker plugin ls`输出的默认格式。当`docker plugin ls`没有被提供`--format`选项时，Docker的客户端使用这个属性。如果未设置此属性，则客户端将回到默认表格格式。

属性`servicesFormat`指定`docker service ls`输出的默认格式。当`docker service ls`没有被提供`--format`选项时，Docker的客户端使用这个属性。如果此属性未设置，则客户端将回到默认的json格式。

属性`serviceInspectFormat`指定`docker service inspect`输出的默认格式。当`docker service inspect`没有被提供`--format`选项时，Docker的客户端使用这个属性。如果此属性未设置，则客户端将回到默认的json格式。

属性`statsFormat`指定`docker stats`输出的默认格式。当 `docker stats`没有被提供`--format`选项时，Docker的客户端使用这个属性。如果未设置此属性，则客户端将回到默认表格格式。

属性`secretFormat`指定`docker secret ls`输出的默认格式。当`docker secret ls`没有被提供`--format`选项时，Docker的客户端使用这个属性。如果未设置此属性，则客户端将回到默认表格格式。

属性`nodesFormat`指定`docker node ls`输出的默认格式。当命令`docker node ls`未提供该选项`--format`时，Docker的客户端将使用值`nodesFormat`。如果`nodesFormat`未设置值，则客户端使用默认表格格式。

属性`configFormat`指定`docker config ls`输出的默认格式。当`docker config ls`没有被提供`--format`选项时，Docker的客户端使用这个属性。如果未设置此属性，则客户端将回到默认表格格式。

属性`credsStore`指定一个外部二进制文件作为默认凭证存储。设置此属性时，`docker login`将尝试将凭据存储在`docker-credential-<value>`由其上可见的指定二进制文件中`$PATH`。如果未设置此属性，则凭据将存储在`auths`配置的属性中。

属性`credHelpers`指定一组凭据佣工超过优先使用`credsStore`或`auths`存储和检索特定注册表凭据时。如果设置了此属性，则`docker-credential-<value>`在存储或检索特定注册表的凭据时将使用该二进制文件 。

### 自定义快捷键

---

一旦连接到一个容器，用户要脱离它并使用`CTRL-p-q`键序列让它继续运行。此分离键序列可使用`detachKeys`属性进行自定义。为属性指定一个`<sequence>`值。`<sequence>`的格式是以逗号分隔的一个字母`[a-Z]`或者`ctrl-`与以下任意一个组合的列表：

- `a-z` （一个小写字母字符）
- `@` （在选项处）
- `[` （左括号）
- `\\` （两个反向斜线）
- `_` （下划线）
- `^` （脱字符号）

你的自定义适用于你的Docker客户端启动的所有容器。用户可以基于每个容器覆盖自定义或默认的按键顺序。要做到这一点，用户指定`--detach-keys`旗`docker attach`，`docker exec`，`docker run`或`docker start`命令。

### `config.json` 文件示例

---

```json
{
  "HttpHeaders": {
    "MyHeader": "MyValue"
  },
  "psFormat": "table {{.ID}}\\t{{.Image}}\\t{{.Command}}\\t{{.Labels}}",
  "imagesFormat": "table {{.ID}}\\t{{.Repository}}\\t{{.Tag}}\\t{{.CreatedAt}}",
  "pluginsFormat": "table {{.ID}}\t{{.Name}}\t{{.Enabled}}",
  "statsFormat": "table {{.Container}}\t{{.CPUPerc}}\t{{.MemUsage}}",
  "servicesFormat": "table {{.ID}}\t{{.Name}}\t{{.Mode}}",
  "secretFormat": "table {{.ID}}\t{{.Name}}\t{{.CreatedAt}}\t{{.UpdatedAt}}",
  "configFormat": "table {{.ID}}\t{{.Name}}\t{{.CreatedAt}}\t{{.UpdatedAt}}",
  "serviceInspectFormat": "pretty",
  "nodesFormat": "table {{.ID}}\t{{.Hostname}}\t{{.Availability}}",
  "detachKeys": "ctrl-e,e",
  "credsStore": "secretservice",
  "credHelpers": {
    "awesomereg.example.org": "hip-star",
    "unicorn.example.com": "vcbait"
  }
}
```

## 公证

如果使用自己的**公证服务器**和自签名**证书**或内部证书颁发机构，则需要将证书放在docker config目录 `tls/<registry_url>/ca.crt`中。

或者，可以通过将其添加到**系统的根证书颁发机构列表**中来全局信任该证书。

# docker 基本命令行

## * create 创建

`docker create`命令在指定的镜像上创建一个可写容器层，并为运行指定的命令做好准备。然后将容器ID打印到`STDOUT`。这与`docker run -d` 容器永远不会启动的情况类似。然后你可以使用该 `docker start <container_id>`命令随时启动容器。

当你希望提前设置容器配置以便在需要时启动它时，这非常有用。新容器的初始状态是`created`。

### 命令参数选项

---

| 选项，简写                | 默认      | 描述                                                         |
| ------------------------- | --------- | ------------------------------------------------------------ |
| `--add-host`              |           | 添加自定义的主机到IP映射（主机：IP）                         |
| `--attach , -a`           |           | 附加到STDIN，STDOUT或STDERR                                  |
| `--blkio-weight`          |           | 阻止IO（相对权重），介于10和1000之间，或0禁用（默认值为0）   |
| `--blkio-weight-device`   |           | 块IO重量（相对设备重量）                                     |
| `--cap-add`               |           | 添加Linux功能                                                |
| `--cap-drop`              |           | 删除Linux功能                                                |
| `--cgroup-parent`         |           | 容器的可选父cgroup                                           |
| `--cidfile`               |           | 将容器ID写入文件                                             |
| `--cpu-count`             |           | CPU数量（仅限Windows）                                       |
| `--cpu-percent`           |           | CPU百分比（仅限Windows）                                     |
| `--cpu-period`            |           | 限制CPU CFS（完全公平调度程序）期间                          |
| `--cpu-quota`             |           | 限制CPU CFS（完全公平调度程序）配额                          |
| `--cpu-rt-period`         |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 以微秒为单位限制CPU实时周期 |
| `--cpu-rt-runtime`        |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 以微秒为单位限制CPU实时运行时间 |
| `--cpu-shares , -c`       |           | CPU份额（相对重量）                                          |
| `--cpus`                  |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) CPU数量 |
| `--cpuset-cpus`           |           | 允许执行的CPU（0-3,0,1）                                     |
| `--cpuset-mems`           |           | 允许执行的MEM（0-3,0,1）                                     |
| `--device`                |           | 将主机设备添加到容器                                         |
| `--device-cgroup-rule`    |           | 将规则添加到cgroup允许的设备列表                             |
| `--device-read-bps`       |           | 限制设备的读取速率（每秒字节数）                             |
| `--device-read-iops`      |           | 限制设备的读取速率（每秒IO）                                 |
| `--device-write-bps`      |           | 限制写入速率（每秒字节数）到设备                             |
| `--device-write-iops`     |           | 限制写入速率（每秒IO）到设备                                 |
| `--disable-content-trust` | `true`    | 跳过镜像验证                                                 |
| `--dns`                   |           | 设置自定义DNS服务器                                          |
| `--dns-opt`               |           | 设置DNS选项                                                  |
| `--dns-option`            |           | 设置DNS选项                                                  |
| `--dns-search`            |           | 设置自定义DNS搜索域                                          |
| `--entrypoint`            |           | 覆盖镜像的默认入口点                                         |
| `--env , -e`              |           | 设置环境变量                                                 |
| `--env-file`              |           | 读入环境变量文件                                             |
| `--expose`                |           | 公开一个端口或一系列端口                                     |
| `--group-add`             |           | 添加其他群组加入                                             |
| `--health-cmd`            |           | 运行以检查运行状况的命令                                     |
| `--health-interval`       |           | 运行检查之间的时间（ms \| s \| m \| h）（默认为0）           |
| `--health-retries`        |           | 需要报告不健康的连续失败                                     |
| `--health-start-period`   |           | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 在开始健康重试倒数前，容器要初始化的起始时间段（ms \| s \| m \| h）（默认值为0） |
| `--health-timeout`        |           | 允许一次检查运行的最长时间（ms \| s \| m \| h）（默认值为0） |
| `--help`                  |           | 打印用法                                                     |
| `--hostname , -h`         |           | 容器主机名称                                                 |
| `--init`                  |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 在容器中运行一个init，用于转发信号并收集进程 |
| `--interactive , -i`      |           | 即使没有连接，也要保持STDIN打开                              |
| `--io-maxbandwidth`       |           | 系统驱动器的最大IO带宽限制（仅限Windows）                    |
| `--io-maxiops`            |           | 系统驱动器的最大IOps限制（仅限Windows）                      |
| `--ip`                    |           | IPv4地址（例如172.30.100.104）                               |
| `--ip6`                   |           | IPv6地址（例如，2001：db8 :: 33）                            |
| `--ipc`                   |           | 使用IPC模式                                                  |
| `--isolation`             |           | 容器隔离技术                                                 |
| `--kernel-memory`         |           | 内核内存限制                                                 |
| `--label , -l`            |           | 在容器上设置元数据                                           |
| `--label-file`            |           | 阅读标签的行分隔文件                                         |
| `--link`                  |           | 将链接添加到其他容器                                         |
| `--link-local-ip`         |           | Container IPv4 / IPv6链路本地地址                            |
| `--log-driver`            |           | 记录容器的驱动程序                                           |
| `--log-opt`               |           | 日志驱动选项                                                 |
| `--mac-address`           |           | 容器MAC地址（例如，92：d0：c6：0a：29：33）                  |
| `--memory , -m`           |           | 内存限制                                                     |
| `--memory-reservation`    |           | 内存软限制                                                   |
| `--memory-swap`           |           | 交换限制等于内存加交换：'-1'以启用无限交换                   |
| `--memory-swappiness`     | `-1`      | 调整容器内存swappiness（0到100）                             |
| `--mount`                 |           | 将文件系统挂载附加到容器                                     |
| `--name`                  |           | 为容器分配一个名称                                           |
| `--net`                   |           | 将容器连接到网络                                             |
| `--net-alias`             |           | 为容器添加网络范围的别名                                     |
| `--network`               |           | 将容器连接到网络                                             |
| `--network-alias`         |           | 为容器添加网络范围的别名                                     |
| `--no-healthcheck`        |           | 禁用任何容器指定的HEALTHCHECK                                |
| `--oom-kill-disable`      |           | 禁用OOM杀手                                                  |
| `--oom-score-adj`         |           | 调整主机的OOM首选项（从-1000到1000）                         |
| `--pid`                   |           | 要使用的PID名称空间                                          |
| `--pids-limit`            |           | 调整容器匹配限制（无限制地设置-1）                           |
| `--platform`              |           | [实验（守护程序）](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)[API 1.32+](https://docs.docker.com/engine/api/v1.32/) 如果服务器具有多平台功能，请设置平台 |
| `--privileged`            |           | 给这个容器赋予扩展权限                                       |
| `--publish , -p`          |           | 将容器的端口发布到主机                                       |
| `--publish-all , -P`      |           | 将所有暴露的端口发布到随机端口                               |
| `--read-only`             |           | 将容器的根文件系统挂载为只读                                 |
| `--restart`               | `no`      | 重新启动策略以在容器退出时应用                               |
| `--rm`                    |           | 当容器退出时自动移除容器                                     |
| `--runtime`               |           | 运行时用于此容器                                             |
| `--security-opt`          |           | 安全选项                                                     |
| `--shm-size`              |           | / dev / shm的大小                                            |
| `--stop-signal`           | `SIGTERM` | 停止容器的信号                                               |
| `--stop-timeout`          |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 超时（以秒为单位）停止容器 |
| `--storage-opt`           |           | 容器的存储驱动程序选项                                       |
| `--sysctl`                |           | Sysctl选项                                                   |
| `--tmpfs`                 |           | 挂载一个tmpfs目录                                            |
| `--tty , -t`              |           | 分配一个伪TTY                                                |
| `--ulimit`                |           | Ulimit选项                                                   |
| `--user , -u`             |           | 用户名或UID（格式：<name \| uid> [：<group \| gid>]）        |
| `--userns`                |           | 要使用的用户名称空间                                         |
| `--uts`                   |           | UTS命名空间使用                                              |
| `--volume , -v`           |           | 绑定安装一个卷                                               |
| `--volume-driver`         |           | 容器的可选卷驱动程序                                         |
| `--volumes-from`          |           | 从指定容器装载卷                                             |
| `--workdir , -w`          |           | 容器内的工作目录                                             |



### 示例

---

#### 创建并启动一个容器

```sh
$ docker create -t -i fedora bash
21260c81742a88e44128f90e32a41be803ef6b8b7e2d2612df8201577ef152a7

$ docker start -a -i 21260c81742a88e44128f90e32a41be803ef6b8b7e2d2612df8201577ef152a7
bash-4.2#
```

#### 初始化卷

---

从v1.4.0开始，容器卷在`docker create`阶段被**初始化**（`docker run`也是）。例如，这允许创建容器数据卷，然后在另一个容器中使用它： 

```sh
# 创建一个卷 data，并且使用ubuntu镜像，创建一个容器 test_ubuntu
$ docker create -v /data --name test_ubuntu ubuntu
324a44901ede3dbd55f8bf75ab2d6debf243e22cbbd82fc84c5deebf61bcd052

# 利用busybox镜像运行容器，使用容器卷 test_ubuntu
$ docker run --rm --volumes-from test_ubuntu busybox ls -la /data

total 8
drwxr-xr-x  2 root root 4096 Dec  5 04:10 .
drwxr-xr-x 48 root root 4096 Dec  5 04:11 ..
```

同样，`create`主机目录绑定安装的卷容器，然后可以从后续容器中使用该容器：

```sh
$ docker create -v /home/docker:/docker --name docker_ubuntu ubuntu
9aa88c08f319cd1e4515c3c46b0de7cc9aa75e878357b1e96f91e2c773029f03

$ docker run --rm --volumes-from docker_ubuntu ubuntu ls -la /docker
total 16
drwxr-sr-x  5 1000 staff  160 May 14 06:32 .
drwxr-xr-x 35 root root  4096 May 16 02:05 ..
-rw-rw-r--  1 1000 staff 1886 May 15 05:59 .ash_history
-rw-r--r--  1 1000 staff  446 May 14 02:22 .ashrc
drwx------  2 1000 staff  100 May 14 02:22 .docker
drwxr-sr-x  3 1000 staff   60 May 14 06:32 .local
-rw-r--r--  1 1000 staff  920 May 14 02:22 .profile
drwx--S---  2 1000 staff   80 Jan  1  1970 .ssh
```

为每个容器设置存储驱动器选项

```sh
$ docker create -it --storage-opt size=120G fedora /bin/bash
Error response from daemon: --storage-opt is not supported for aufs
```

这个（大小）将允许在创建时将容器`rootfs`大小设置为`120G`。此选项仅适用于`devicemapper`，`btrfs`，`overlay2`，`windowsfilter`和`zfs`驱动程序。对于`devicemapper`，`btrfs`，`windowsfilter`和`zfs`驱动程序，用户无法通过的尺寸小于默认尺寸`BaseFS`。对于`overlay2`存储驱动程序，只有当后备`fs`为`xfs`并使用`pquota`安装选项安装时，`size`选项才可用。在这些条件下，用户可以传递小于后备`fs`大小的任何大小。

#### 处理动态创建的设备`（--device-cgroup-rule）`
---

在创建时分配可用于容器的设备。分配的设备都将被添加到`cgroup.allow`文件，并在运行后创建到容器中。当需要将新设备添加到正在运行的容器时，这会造成问题。

解决方案之一是向容器添加更宽松的规则，以允许访问更广泛的设备。例如，假设我们的容器需要访问具有主要`42`和任意次数的字符设备（添加为新设备出现），则会添加以下规则：

```sh
$ docker create --device-cgroup-rule='c 42:* rmw' -name my-container my-image
```

然后，用户可能会要求`udev`执行脚本，`docker exec my-container mknod newDevX c 42 <minor>` 以便在添加所需设备时使用该脚本。

注意：最初存在的设备仍然需要明确地添加到`create / run`命令中

## * update 更新容器

`docker update`命令**动态更新容器**配置。可以使用此命令**防止容器从其Docker主机消耗太多资源**。使用单个命令，可以将限制放在单个容器上或多个容器上。要指定多个容器，请提供容器名称或ID的空格分隔列表。

除`--kernel-memory`选项外，可以在运行或停止的容器上指定这些选项。在4.6以前的内核版本上，只能`--kernel-memory`在已停止的容器或已初始化内核内存的正在运行的容器上进行更新。

> **警告**：Windows容器不支持`docker update`和`docker container update`命令。

### 命令参数选项

---

| 选项，简写             | 默认 | 描述                                                         |
| ---------------------- | ---- | ------------------------------------------------------------ |
| `--blkio-weight`       |      | 阻止IO（相对权重），介于10和1000之间，或0禁用（默认值为0）   |
| `--cpu-period`         |      | 限制CPU CFS（完全公平调度程序）期间                          |
| `--cpu-quota`          |      | 限制CPU CFS（完全公平调度程序）配额                          |
| `--cpu-rt-period`      |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 以微秒为单位限制CPU实时周期 |
| `--cpu-rt-runtime`     |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 以微秒为单位限制CPU实时运行时间 |
| `--cpu-shares , -c`    |      | CPU份额（相对重量）                                          |
| `--cpus`               |      | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) CPU数量 |
| `--cpuset-cpus`        |      | 允许执行的CPU（0-3,0,1）                                     |
| `--cpuset-mems`        |      | 允许执行的MEM（0-3,0,1）                                     |
| `--kernel-memory`      |      | 内核内存限制                                                 |
| `--memory , -m`        |      | 内存限制                                                     |
| `--memory-reservation` |      | 内存软限制                                                   |
| `--memory-swap`        |      | 交换限制等于内存加交换：'-1'以启用无限交换                   |
| `--restart`            |      | 重新启动策略以在容器退出时应用                               |



### 示例

---

#### 更新容器的`cpu-shares`
要将容器的`cpu-shares`限制为`512`，请首先标识容器名称或标识。可以使用`docker ps`查找这些值。也可以使用从`docker run`命令返回的ID 。然后，执行以下操作：

```sh
$ docker update --cpu-shares 512 abebf7571666
```

#### 使用`cpu-shares`和内存更新容器
---
要更新多个容器的多个资源配置：

```sh
$ docker update --cpu-shares 512 -m 300M abebf7571666 hopeful_morse
```

#### 更新容器的内核内存限制
---
可以使用`--kernel-memory` 选项更新容器的**内核内存限制**。在4.6以前的内核版本上，只有容器启动时才能在正在运行的容器上更新此选项`--kernel-memory`。如果容器启动时**不需要** `--kernel-memory`在更新内核内存之前停止容器。

例如，如果使用此命令启动了一个容器：

```sh
$ docker run -dit --name test --kernel-memory 50M ubuntu bash
```

可以在容器运行时更新内核内存：

```sh
$ docker update --kernel-memory 80M test
```

如果你启动了一个**没有**内核内存初始化的容器：

```sh
$ docker run -dit --name test2 --memory 300M ubuntu bash
```

更新运行容器的内核内存`test2`将**失败**。在更新`--kernel-memory`设置之前，需要**停止容器**。**下次启动**它时，容器将**使用新值**。

比（include）4.6更新的内核版本没有此限制，可以使用`--kernel-memory`与其他选项相同的方式。

#### 更新容器的重新启动策略
---
可以在正在运行的容器上更改容器的重新启动策略。新的重新启动策略`docker update`在容器上运行后立即生效。

要更新一个或多个容器的重新启动策略：

```sh
$ docker update --restart=on-failure:3 abebf7571666 hopeful_morse
```

请注意，如果容器以`-rm`选项启动，则无法为其更新重新启动策略。`AutoRemove`和`RestartPolicy`是容器相互排斥。


## * commit 提交

将**容器的文件更改或设置**提交到**新镜像**可能很有用。这允许通过**运行交互式shell来调试容器**，或者将**工作数据集**导出到另一台服务器。一般来说，最好使用`Dockerfiles`以**文件化和可维护**的方式管理镜像。 [详细了解有效的镜像名称和标签](https://docs.docker.com/engine/reference/commandline/tag/)。

提交操作将**不包含**容器内安装的**卷**中包含的**任何数据**。

默认情况下，提交的容器及其进程将**在镜像提交时暂停**。这可以降低创建提交过程中遇到**数据损坏的可能性**。如果此行为不是希望的，请将`--pause`选项设置为false。

`--change`选项会将`Dockerfile`指令应用于所创建的镜像。支持的`Dockerfile`指令：`CMD`| `ENTRYPOINT`| `ENV`| `EXPOSE`| `LABEL`| `ONBUILD`| `USER`| `VOLUME`|`WORKDIR`

### 命令参数选项

---

| 选项，简写       | 默认   | 描述                                                         |
| ---------------- | ------ | ------------------------------------------------------------ |
| `--author , -a`  |        | 作者（例如，“John Hannibal Smith [hannibal@a-team.com](mailto:hannibal@a-team.com) ”） |
| `--change , -c`  |        | 将Dockerfile指令应用于创建的镜像                             |
| `--message , -m` |        | 提交消息                                                     |
| `--pause , -p`   | `true` | 在提交期间暂停容器                                           |



### 示例

---

#### 提交一个容器

```sh
$ docker ps
CONTAINER ID        IMAGE               COMMAND                  CREATED             STATUS              PORTS               NAMES
8e71d8636d0e        redis:latest        "docker-entrypoint.s…"   32 hours ago        Up 32 hours         6379/tcp            redis.1.n7d0oijypm5sdlx9nxa1g5k30
23e4312832d5        busybox:latest      "top"                    33 hours ago        Up 33 hours                             hosttempl.1.egmwgoylgljbe00c3bsqri6dw
7b418736bd60        nginx:latest        "sh -c 'exec nginx -…"   33 hours ago        Up 33 hours         80/tcp              nginx.1.wwmhy93zcv8zj4mrou57gglhg

$ docker commit 23e4312832d5 test/my_busybox:v1
sha256:059eb58c8c55befc88fe237473a2a578ed3448818c38b8b97db02275e244b877

$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED                  SIZE
test/my_busybox     v1                  059eb58c8c55        Less than a second ago   1.15MB
```

#### 提交新配置的容器
---
```sh
$ docker ps
CONTAINER ID        IMAGE               COMMAND                  CREATED             STATUS              PORTS               NAMES
8e71d8636d0e        redis:latest        "docker-entrypoint.s…"   32 hours ago        Up 32 hours         6379/tcp            redis.1.n7d0oijypm5sdlx9nxa1g5k30
23e4312832d5        busybox:latest      "top"                    33 hours ago        Up 33 hours                             hosttempl.1.egmwgoylgljbe00c3bsqri6dw
7b418736bd60        nginx:latest        "sh -c 'exec nginx -…"   33 hours ago        Up 33 hours         80/tcp              nginx.1.wwmhy93zcv8zj4mrou57gglhg


$ docker inspect -f "{{ .Config.Env }}" 23e4312832d5
[PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin]

$ docker commit --change "ENV DEBUG true" 23e4312832d5 test/my_busybox:v2
sha256:e4f3423f03098d96d5bff610a97aa6b1d3e503aa1aaaf1315aad6365a0658ebf

$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
test/my_busybox     v2                  e4f3423f0309        33 seconds ago      1.15MB
test/my_busybox     v1                  059eb58c8c55        3 minutes ago       1.15MB

$ docker inspect -f "{{ .Config.Env }}" e4f3423f0309
[HOME=/ PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin DEBUG=true]
```

#### 提交修改后的`CMD`和`EXPOSE`容器
---
```sh
$ docker ps
CONTAINER ID        IMAGE               COMMAND                  CREATED             STATUS              PORTS               NAMES
8e71d8636d0e        redis:latest        "docker-entrypoint.s…"   32 hours ago        Up 32 hours         6379/tcp            redis.1.n7d0oijypm5sdlx9nxa1g5k30
23e4312832d5        busybox:latest      "top"                    33 hours ago        Up 33 hours                             hosttempl.1.egmwgoylgljbe00c3bsqri6dw
7b418736bd60        nginx:latest        "sh -c 'exec nginx -…"   33 hours ago        Up 33 hours         80/tcp              nginx.1.wwmhy93zcv8zj4mrou57gglhg

$ docker commit --change='CMD ["apachectl", "-DFOREGROUND"]' -c "EXPOSE 80" 23e4312832d5  test/my_busybox:v3


$ docker run -d test/my_busybox:v3 sh
f646923d2c15f32edb14adfd64124e05950fa736466b592baf95216d44eab91d

$ docker ps
CONTAINER ID        IMAGE                COMMAND                  CREATED             STATUS              PORTS               NAMES
0d05ef9210f8        test/my_busybox:v3   "sh"                     11 seconds ago      Up 24 seconds       80/tcp              vigorous_panini
```

## * cp 复制文件

复制容器和本地文件系统之间的文件/文件夹

### 命令参数选项

---

| 选项，简写           | 默认 | 描述                              |
| -------------------- | ---- | --------------------------------- |
| `--archive , -a`     |      | 归档模式（复制所有uid / gid信息） |
| `--follow-link , -L` |      | 始终遵循SRC_PATH中的符号链接      |



### 示例

---

`docker cp`程序将**内容复制`SRC_PATH`到`DEST_PATH`**。可以从**容器的文件系统**复制到**本地机器**或从**本地文件系统**复制到**容器**。如果为`SRC_PATH`或`DEST_PATH`指定了 `-` 也可以从`STDIN`或`STDOUT`流式传输`tar`归档文件。 `CONTAINER`可以是运行或停止容器。`SRC_PATH`或`DEST_PATH`可以是**文件或目录**。

`docker cp`命令假定容器路径与容器的 `/`（根）目录相关。这意味着提供初始正斜杠是可选的，命令看起来`compassionate_darwin:/tmp/foo/myfile.txt`和 `compassionate_darwin:tmp/foo/myfile.txt`完全相同。**地机器路径可以是绝对或相对**。该命令将本地机器的**相对路径**解释为相对于当前运行`docker cp`的工作目录。

`cp`命令的行为与Unix `cp -a`命令类似，即在可能的情况下保留权限时**递归复制**目录。所有权设置为**目标用户和主要组**。例如，复制到容器的文件是由`UID:GID` **root用户**创建的。复制到本地机器的文件是由`UID:GID` **调用`docker cp` 命令的用户**创建的。但是，如果指定了`-a`选项，`docker cp`则将所有权设置为**源用户和主组**。如果指定了`-L`选项，则`docker cp`将跟随`SRC_PATH`中的任何符号链接。如果`docker cp`不存在，`docker cp`不会为`DEST_PATH`创建父目录。

假设一个路径分隔符为`/`，第一个参数`SRC_PATH`和第二个参数`DEST_PATH`的行为如下：

+ `SRC_PATH` 指定一个文件 
  + `DEST_PATH` 不存在 ，该文件被保存到在`DEST_PATH`创建的文件中
  + `DEST_PATH` 不存在并以 `/` 结尾，错误情况：目标目录必须存在。
  + `DEST_PATH` 存在并且是一个文件 ，目标将被源文件的内容覆盖
  + `DEST_PATH` 存在并且是目录 ，该文件将使用基本名称从中复制到此目录中 `SRC_PATH`
+ `SRC_PATH` 指定一个目录 
  + `DEST_PATH` 不存在 ，`DEST_PATH`被创建为一个目录，源目录的**内容**被复制到这个目录中
  + `DEST_PATH` 存在并且是一个文件 ，错误情况：无法将目录复制到文件
  + `DEST_PATH` 存在并且是目录 
    + `SRC_PATH`不以`/.`（即：*斜线*后跟*点*）结束 ，源目录被复制到这个目录中
    + `SRC_PATH`结束于`/.`（即：*斜线*后跟*点*） ，源目录的*内容*被复制到这个目录中

根据上述规则，该命令需要`SRC_PATH`和`DEST_PATH`存在。如果`SRC_PATH`是本地的并且是符号链接，则默认情况下复制符号链接而不是目标。要复制**链接目标**而不是链接，请指定`-L`选项。

冒号（`:`)用作`CONTAINER`与其路径之间的分隔符。在本地机器上指定`SRC_PATH`或`DEST_PATH`的路径时，还可以使用`：`例如`file：name.txt`。如果在本地机器路径中使用`a：`，则必须使用相对或绝对路径进行显式指定，例如：

```sh
`/path/to/file:name.txt` or `./file:name.txt`
```

无法复制某些系统文件，例如`/proc`，`/sys`，`/dev`，`tmpfs`和用户在容器中创建的`挂载下的资源`。但是，仍然可以通过在`docker exec`中手动运行`tar`来复制这些文件。以下两个示例以不同的方式执行相同的操作（请考虑`SRC_PATH`和`DEST_PATH`是目录）：

```sh
$ docker exec CONTAINER tar Ccf $(dirname SRC_PATH) - $(basename SRC_PATH) | tar Cxf DEST_PATH -
$ tar Ccf $(dirname SRC_PATH) - $(basename SRC_PATH) | docker exec -i CONTAINER tar Cxf DEST_PATH -
```

使用` - `由于`SRC_PATH`将`STDIN`的内容作为`tar`归档文件进行流式传输。该命令将`tar`的内容提取到容器文件系统中的`DEST_PATH`。在这种情况下，`DEST_PATH`必须指定一个目录。使用` - `作为`DEST_PATH`将资源的内容作为`tar`归档文件传送到`STDOUT`。

## * start 启动容器

启动一个或多个停止的容器

```sh
$ docker start my_container

--attach , -a		连接STDOUT / STDERR和转发信号
--checkpoint		实验（守护进程）从此检查点恢复
--checkpoint-dir		实验（守护进程）使用自定义检查点存储目录
--detach-keys		覆盖分离容器的键序列
--interactive , -i		连接容器的STDIN
```

## * stop 停止容器

停止一个或多个运行容器

```sh
$ docker stop my_container
```
## * restart 重启容器

重新启动一个或多个容器

```sh
$ docker restart my_container
```
## * rm 删除容器

删除一个或多个容器

### 命令参数选项

---

| 选项，简写       | 默认 | 描述                                  |
| ---------------- | ---- | ------------------------------------- |
| `--force , -f`   |      | 强制删除正在运行的容器（使用SIGKILL） |
| `--link , -l`    |      | 删除指定的链接                        |
| `--volumes , -v` |      | 删除与容器关联的卷                    |



### 示例

---

#### 删除容器

这将删除链接中引用的容器 `/redis`。

```sh
$ docker rm /redis
/redis
```

#### 删除在默认网桥上使用`--link`指定的链接
---
这将删除`/webapp`和默认桥接网络上的`/redis`容器之间的**基础链接**，从而移除两个容器之间的**所有网络通信**。当`--link`与用户指定的网络一起使用时，这不适用。

```sh
$ docker rm --link /webapp/redis
/webapp/redis
```

#### 强制删除正在运行的容器
---
该命令将强制删除正在运行的容器。

```sh
$ docker rm --force redis
redis
```

链接下引用的容器内的主进程`redis`将收到 `SIGKILL`，然后该容器将被删除。

#### 删除所有停止的容器
---
```sh
$ docker rm $(docker ps -a -q)
```

该命令将删除所有停止的容器。命令 `docker ps -a -q`将返回**所有现有的容器ID**并将它们传递给`rm`将删除它们的命令。任何正在运行的容器都不会被删除。

#### 删除出容器及数据卷
---
```sh
$ docker rm -v redis
redis
```

该命令将删除容器及与其**相关的任何卷**。请注意，如果卷是使用名称指定的，则不会被删除。

#### 删除容器并选择性的删除卷
---
```sh
$ docker create -v awesome:/foo -v /bar --name hello redis
hello
$ docker rm -v hello
```

在本例中，卷`/foo`将保持不变，但卷 `/bar`将被删除。同样的行为适用于继承的卷 `--volumes-from`。

## * rename 重命名容器

重命名一个容器

```sh
$ docker rename my_container my_new_container
```

## * attach 附加容器

`docker attach`用于使用容器的ID或名称将终端的标准输入、输出和错误（或三者的任意组合）附加到正在运行的容器。这就允许查看其正在**进行的输出或以交互方式控制**它，就像**命令直接在终端中运行**一样。

> **注意：**如果容器有设置 `cmd`或`ENTRYPOINT  ` 那么，`attach`命令将显示`ENTRYPOINT/CMD`进程的**输出**。这可能看起来好像挂接命令挂起，而实际上**进程可能根本不会与终端进行交互**。

可以从Docker主机上的不同会话同时多次附加到同一个包含的进程。

要停止容器，请使用`CTRL-c`，密钥序列发送`SIGKILL`到容器。如果`--sig-proxy`为真（默认），则`CTRL-c`发送一个`SIGINT`到容器。可以从容器中分离并使用`CTRL-p + CTRL-q`键序列保持运行 。

> **注意：** 在容器中作为PID 1运行的进程会被Linux专门处理：它会忽略具有默认操作的任何信号。因此，过程将不会终止`SIGINT`或者`SIGTERM`除非它被编写这样做。

**禁止附加到容器，启用tty**的容器时重定向`docker attach`命令的标准输入（即：使用`-t`启动）。

当客户端使用`docker attach`连接到容器的`stdio`时，Docker使用约`1MB`的内存缓冲区来最大化应用程序的吞吐量。如果填充此缓冲区，则API连接的速度将**开始影响进程输出写入速度**。这与其他应用程序（如SSH）类似。因此，**不建议**运行**性能重要**的应用程序，通过**慢速客户端**连接在前台生成大量输出。相反，用户应该使用`docker logs`命令来访问日志。

### 覆盖分离序列

---

如果你愿意，你可以配置覆盖Docker键序列进行分离。如果Docker默认序列与你用于其他应用程序的键序列冲突，这很有用。有两种方法可以定义你自己的分离键序列，作为每个容器的覆盖或作为整个配置的配置属性。

要覆盖单个容器的序列，请在`docker attach`命令中使用`--detach-keys="<sequence>"`选项。`<sequence>`的格式可以是一个字母`[a-Z]`，或者是`ctrl-`与以下任何一个组合：

- `a-z` （一个小写字母字符）
- `@` （在选项处）
- `[` （左括号）
- `\\` （两个反向斜线）
- `_` （下划线）
- `^` （脱字符号）

这些`a`，`ctrl-a`，`X`，或`ctrl-\\`值都是有效密钥序列的示例。要为所有容器配置不同的配置默认密钥序列，请参阅配置文件部分。

### 命令参数选项

---

| 选项，简写      | 默认   | 描述                         |
| --------------- | ------ | ---------------------------- |
| `--detach-keys` |        | 覆盖分离容器的键序列         |
| `--no-stdin`    |        | 不要连接STDIN                |
| `--sig-proxy`   | `true` | 将所有接收到的信号代理到进程 |



### 示例

---

#### 附加分离到正在运行的容器

```sh
$ docker run -d --name topdemo ubuntu /usr/bin/top -b
51693aa8de0d0271f9ac6afd1ff597e33b3f23fc2c09adb1d41170afe1cb768f

$ docker attach topdemo

top - 08:04:22 up 20:04,  0 users,  load average: 0.00, 0.00, 0.00
Tasks:   1 total,   1 running,   0 sleeping,   0 stopped,   0 zombie
%Cpu(s):  2.0 us,  0.7 sy,  0.0 ni, 97.3 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
KiB Mem :  1019528 total,   588832 free,   102484 used,   328212 buff/cache
KiB Swap:  1174748 total,  1174748 free,        0 used.   557368 avail Mem

  PID USER      PR  NI    VIRT    RES    SHR S %CPU %MEM     TIME+ COMMAND
    1 root      20   0   36528   2860   2508 R  0.0  0.3   0:00.03 top
    
$ echo $?
0
$ docker ps -a | grep topdemo
51693aa8de0d        ubuntu                    "/usr/bin/top -b"        About a minute ago   Exited (0) 48 seconds ago                       topdemo    
```

#### 获取容器命令的退出代码
---
可以看到`bash` 进程返回的退出代码也被`docker attach`命令返回给其调用者：

```sh
$ docker run --name test -d -it debian
275c44472aebd77c926d4527885bb09f2f6db21d878c75f0a1c212c03d3bcfab

$ docker attach test
root@f38c87f2a42d:/# exit 13
exit

$ echo $?
13

$ docker ps -a | grep test
8b9db546ede3        debian                    "bash"                   5 minutes ago       Exited (13) 15 seconds ago                       test
```

## * diff 比较容器

自容器创建以来，将已更改的文件和目录列出在容器文件系统中。跟踪三种不同类型的变化：

| 符号 | 描述                 |
| ---- | -------------------- |
| `A`  | 一个文件或目录被添加 |
| `D`  | 文件或目录已删除     |
| `C`  | 文件或目录已更改     |

可以使用完整或缩短的容器标识或使用`docker run -name`选项设置的容器名称。

检查`nginx`容器的更改：

```sh
$ docker ps
CONTAINER ID        IMAGE                COMMAND                  CREATED             STATUS              PORTS               NAMES
7b418736bd60        nginx:latest         "sh -c 'exec nginx -…"   2 days ago          Up 2 days           80/tcp              nginx.1.wwmhy93zcv8zj4mrou57gglhg


$ docker diff 7b418736bd60
A /E:
A /E:/Git
A /E:/Git/etc
A /E:/Git/etc/nginx
A /E:/Git/etc/nginx/conf.d
A /E:/Git/etc/nginx/conf.d/site.conf
C /run
A /run/nginx.pid
A /run/secrets
A /run/secrets/site.crt
A /run/secrets/site.key
C /var
C /var/cache
C /var/cache/nginx
A /var/cache/nginx/client_temp
A /var/cache/nginx/fastcgi_temp
A /var/cache/nginx/proxy_temp
A /var/cache/nginx/scgi_temp
A /var/cache/nginx/uwsgi_temp
```
## * exec 执行

`docker exec`命令在正在运行的容器中运行新命令。使用`docker exec`启动的命令**仅在容器的主进程**（`PID 1`）正在运行时运行，并且如果**容器重新启动，则不会重新启动该命令**。

命令将在容器的默认目录中运行。如果底层镜像的`Dockerfile`中有`WORKDIR`指令指定的自定义目录，则将使用此目录。命令应该是可执行文件，链接或引用的命令将不起作用。例如：`docker exec -ti my_container "echo a && echo b"`不会工作，但`docker exec -ti my_container sh -c "echo a && echo b"`会成功执行。

### 命令参数选项

---

| 选项，简写           | 默认 | 描述                                                         |
| -------------------- | ---- | ------------------------------------------------------------ |
| `--detach , -d`      |      | 分离模式：在后台运行命令                                     |
| `--detach-keys`      |      | 覆盖分离容器的键序列                                         |
| `--env , -e`         |      | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 设置环境变量 |
| `--interactive , -i` |      | 即使没有连接，也要保持STDIN打开                              |
| `--privileged`       |      | 给命令赋予扩展权限                                           |
| `--tty , -t`         |      | 分配一个伪TTY                                                |
| `--user , -u`        |      | 用户名或UID（格式：<name \| uid> [：<group \| gid>]）        |
| `--workdir , -w`     |      | [API 1.35+](https://docs.docker.com/engine/api/v1.35/) 容器内的工作目录 |

  

### 示例

---

#### 在运行的容器上运行

首先，启动一个容器。

```sh
$ docker run --name ubuntu_bash --rm -i -t ubuntu bash
```

这将创建一个名为`ubuntu_bash`容器并启动`Bash`会话。

接下来，在容器上执行一个命令。

```sh
$ docker exec -d ubuntu_bash touch /tmp/execWorks
```

这将在后台创建一个`ubuntu_bash`运行容器内的 `/tmp/execWorks`新文件。

接下来，在容器上执行交互式`bash shell`。

```sh
$ docker exec -it ubuntu_bash bash
```

这将在容器中创建一个新的Bash会话`ubuntu_bash`。

接下来，在当前的bash会话中设置一个环境变量。

```sh
$ docker exec -it -e VAR=1 ubuntu_bash bash
```

这将在环境变量`$VAR`设置为`1`的容器`ubuntu_bash`中创建一个新的`Bash`会话。请注意，**此环境变量仅在当前的`Bash`会话中有效**。

默认情况下，`docker exec`命令在创建容器时运行在**相同的工作目录**中。

```sh
$ winpty docker exec -it ubuntu_bash pwd
/
```

可以选择要执行的命令的工作目录

```sh
$ docker exec -it -w /root ubuntu_bash pwd
/root
```

#### 在暂停的容器上运行
---
如果容器暂停，那么该`docker exec`命令将**失败并出现错误**：

```sh
$ docker pause test
test

$ docker ps
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS                   PORTS               NAMES
1ae3b36715d2        ubuntu:latest       "bash"              17 seconds ago      Up 16 seconds (Paused)                       test

$ docker exec test ls
FATA[0000] Error response from daemon: Container test is paused, unpause the container before exec

$ echo $?
1
```

## * export 导出容器

`docker export`命令不会导出与容器**关联的卷**的内容。如果将卷安装在容器中现有目录的顶部，`docker export`将导出**基础** 目录的内容，而不是卷的内容。

有关导出[卷](https://docs.docker.com/engine/tutorials/dockervolumes/#backup-restore-or-migrate-data-volumes)中[数据](https://docs.docker.com/engine/tutorials/dockervolumes/#backup-restore-or-migrate-data-volumes)的示例，请参阅用户指南中的[备份，还原或迁移数据卷](https://docs.docker.com/engine/tutorials/dockervolumes/#backup-restore-or-migrate-data-volumes)。

```sh
# 每个命令都有相同的结果。
$ docker export red_panda > latest.tar
$ docker export --output="latest.tar" red_panda
```

## * import 导入容器

可以指定一个`URL`或`-`（破折号）直接从`STDIN`中获取数据。该`URL`可以指向包含文件系统或Docker主机上的单个文件的存档（`.tar，.tar.gz，.tgz，.bzip，.tar.xz或.txz`）。如果你指定了一个档案，Docker会在相对于`/`（root）的容器中对它进行解压缩。如果指定单个文件，则必须在主机中指定**完整路径**。要从**远程位置导入**，请指定以`http：//`或`https：//`协议开头的URI。

`--change`选项会将`Dockerfile`指令应用于所创建的镜像。支持的`Dockerfile`说明： `CMD`| `ENTRYPOINT`| `ENV`| `EXPOSE`| `ONBUILD`| `USER`| `VOLUME`|`WORKDIR`

### 命令参数选项

---

| 选项，简写       | 默认 | 描述                             |
| ---------------- | ---- | -------------------------------- |
| `--change , -c`  |      | 将Dockerfile指令应用于创建的镜像 |
| `--message , -m` |      | 为导入的镜像设置提交消息         |

### 示例

---

#### 从远程位置导入

这将创建一个新的未标记的镜像。

```sh
$ docker import http://example.com/exampleimage.tgz
```

#### 从本地文件导入
---
- 通过管道和`STDIN`导入到docker。

  ```sh
  $ cat exampleimage.tgz | docker import - exampleimagelocal:new
  ```

- 用提交消息导入。

  ```sh
  $ cat exampleimage.tgz | docker import --message "New image imported from tarball" - exampleimagelocal:new
  ```

- 从本地存档导入到docker。

  ```sh
  $ docker import /path/to/exampleimage.tgz
  $ docker import helloworld.tar test/hello:v1
  ```

#### 从本地目录导入
---
```sh
$ sudo tar -c . | docker import - exampleimagedir
```

#### 从具有新配置的本地目录导入
---
```sh
$ sudo tar -c . | docker import --change "ENV DEBUG true" - exampleimagedir
```

请注意本例中的`sudo` ` - `你必须在使用`tar`进行归档期间保留文件的所有权（尤其是root用户的所有权）。如果你在tar时不是root用户（或sudo命令），则所有权可能无法保留。

## * kill 杀死容器

`docker kill`子命令**杀死一个或多个容器**。容器内的主要过程是**发送`SIGKILL`信号**（默认），或使用`--signal`选项指定的信号。可以使用容器的`ID`，`ID-前缀`或`名称`来杀死一个容器。

> **注意**：`shell`格式的`ENTRYPOINT`和`CMD`作为`/bin/sh -c`的子命令运行，它不传递信号。这意味着可执行文件不是容器的`PID 1`，并且不接收Unix信号。

### 示例

---

#### KILL一个容器

以下示例将默认`KILL`信号发送到名为`my_container`的容器 ：

```sh
$ docker kill my_container
```

#### 将自定义信号发送到容器
---
以下示例向名为`my_container`的容器发送一个`SIGHUP`信号 ：

```sh
$ docker kill --signal=SIGHUP  my_container
```

可以通过**名称**或**编号**指定自定义信号。`SIG`前缀是可选的，所以下面的例子是等价的：

```sh
$ docker kill --signal=SIGHUP my_container
$ docker kill --signal=HUP my_container
$ docker kill --signal=1 my_container
```

请参阅[`signal(7)`](http://man7.org/linux/man-pages/man7/signal.7.html) 手册页以获取标准Linux信号的列表。

## * logs 容器日志

批量检索容器执行时的日志。

> **注意**：该命令仅适用于使用`json-file`或`journald`日志记录驱动程序启动的容器。

### 命令参数选项

---

| 名字，简写          | 默认  | 描述                                                         |
| ------------------- | ----- | ------------------------------------------------------------ |
| `--details`         |       | 显示提供给日志的额外细节                                     |
| `--follow , -f`     |       | 按照日志输出                                                 |
| `--since`           |       | 自时间戳（例如2013-01-02T13：23：37）或相对（例如42分钟42分钟）显示日志 |
| `--tail`            | `all` | 从日志末尾显示的行数                                         |
| `--timestamps , -t` |       | 显示时间戳                                                   |
| `--until`           |       | [API 1.35+](https://docs.docker.com/engine/api/v1.35/) 在时间戳之前（例如2013-01-02T13：23：37）或相对（例如42分钟42分钟）显示日志 |



### 示例

---

#### 跟踪日志

`docker logs --follow`命令将继续流式传输容器的`STDOUT`和新的输出`STDERR`。

```sh
$ docker logs my-web --follow
```

#### 指定行数
---
传递一个负数或一个非整数`--tail`是无效的，`all`在这种情况下值被设置为。

```sh
$ docker logs my-web --tail 2
```

#### 时间戳
---
`docker logs --timestamps`命令将增加一个[RFC3339Nano时间戳](https://golang.org/pkg/time/#pkg-constants) ，例如`2014-09-16T06:17:46.000000000Z`，每个日志条目。为确保时间戳对齐，必要时，时间戳的纳秒部分将填充零。

```sh
$ docker logs my-web --tail 2 --timestamps
```

#### 详细信息
---
`docker logs --details`命令将添加额外的属性，例如`--log-opt`创建容器时提供的环境变量和标签。

```sh
$ docker logs --details my-web
```

#### 日期过滤
---
`--since`选项仅显示给定日期后生成的服务日志。如果这个应用运行时间过长，比如3天，那么指定日志的开始时间是非常有必要的。可以使用--since，让容器日志只输出指定日期之后的时间。这个时间可以是RFC 3339时间，也可以是UNIX timestamp，你可以结合使用 `--since`选择具有的一种或两种`--follow`或`--tail`选项。例如： 

```sh
# 日期 时间
$ docker service logs --details my-web --since "2018-05-08"
# 毫秒
$ docker service logs --details my-web --since "1441018800"

$ docker run --name test -d busybox sh -c "while true; do $(echo date); sleep 1; done"
$ date
Tue 14 Nov 2017 16:40:00 CET
$ docker logs -f --until=2s
Tue 14 Nov 2017 16:40:00 CET
Tue 14 Nov 2017 16:40:01 CET
Tue 14 Nov 2017 16:40:02 CET
```
## * wait 阻塞

阻塞，直到一个或多个容器停止，然后打印退出代码

### 示例

---

在后台启动一个容器。

```sh
$ docker run -dit --name=my_container ubuntu bash
```

运行`docker wait`，应该阻塞，直到容器退出。

```sh
$ docker wait my_container
```

在另一个终端中，停止第一个容器。`docker wait`上面的命令返回退出代码。

```sh
$ docker stop my_container
```

这是与`docker wait`上面相同的命令，但现在退出并返回 `0`。

```sh
$ docker wait my_container
0
```
## * pause 暂停容器

`docker pause`命令暂停指定容器中的**所有进程**。在Linux上，这使用`cgroups freezer` 。传统上，当暂停进程时，使用`SIGSTOP`信号，这可以通过暂停进程来观察。对于`cgroups freezer`，该过程不知道，无法捕获，它正在暂停，随后又恢复。在Windows上，只能暂停Hyper-V容器。 

```sh
$ docker pause my_container
```
## * unpause 取消暂停容器

取消暂停一个或多个容器内的所有进程

```sh
$ docker unpause my_container
```
## * port 容器端口

列出容器的端口映射或特定映射

可以找出所有映射的端口没有指定`PRIVATE_PORT`，或只是一个特定的映射：

```sh
$ docker ps
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS                                            NAMES
b650456536c7        busybox:latest      top                 54 minutes ago      Up 54 minutes       0.0.0.0:1234->9876/tcp, 0.0.0.0:4321->7890/tcp   test

$ docker port test
7890/tcp -> 0.0.0.0:4321
9876/tcp -> 0.0.0.0:1234

$ docker port test 7890/tcp
0.0.0.0:4321

$ docker port test 7890/udp
2014/06/24 11:53:36 Error: No public port '7890/udp' published for test

$ docker port test 7890
0.0.0.0:4321
```

## * ps 查看容器

显示所有运行容器

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                                   |
| --------------- | ---- | -------------------------------------- |
| `--all , -a`    |      | 显示所有容器（默认显示正在运行）       |
| `--filter , -f` |      | 根据提供的条件过滤输出                 |
| `--format`      |      | 漂亮的打印容器使用Go模板               |
| `--last , -n`   | `-1` | 显示**最后**创建的容器（包括所有状态） |
| `--latest , -l` |      | 显示**最新**创建的容器（包括所有状态） |
| `--no-trunc`    |      | 不要截断输出                           |
| `--quiet , -q`  |      | 只显示数字ID                           |
| `--size , -s`   |      | 显示总文件大小                         |



### 示例

---

#### 防止截断输出

运行`docker ps --no-trunc`显示2个链接的容器。

```sh
$ docker ps

CONTAINER ID        IMAGE                        COMMAND                CREATED              STATUS              PORTS               NAMES
4c01db0b339c        ubuntu:12.04                 bash                   17 seconds ago       Up 16 seconds       3300-3310/tcp       webapp
d7886598dbe2        crosbymichael/redis:latest   /redis-server --dir    33 minutes ago       Up 33 minutes       6379/tcp            redis,webapp/db
```

#### 显示所有容器
---
`docker ps`命令仅默认显示正在运行的容器。要查看所有容器，请使用`-a`（或`--all`）选项：

```sh
$ docker ps -a
```

`docker ps`如果可能，将暴露的端口分组到单个范围。例如，`100, 101, 102`显示TCP端口的容器显示`100-102/tcp`在`PORTS`列中。

#### 显示最后和最新的容器
---
```sh
$ docker ps -l
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
22efd3343a01        ubuntu              "bash"              5 hours ago         Up 5 hours                              ubuntu_bash

$ docker ps -n -1

# 显示容器大小
$ docker ps -s
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES                                    SIZE
22efd3343a01        ubuntu              "bash"              5 hours ago         Up 5 hours                              ubuntu_bash                              17B (virtual 113MB)
57f6073f0240        alpine:latest       "ping docker.com"   2 days ago          Up 2 days                               helloworld.1.i90uai5v8brougdmtxx5ain6t   0B (virtual 4.15MB)
```



#### 过滤
---
过滤选项（`-f`或`--filter`）格式是一`key=value`对。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

| 过滤                | 描述                                                         |
| ------------------- | ------------------------------------------------------------ |
| `id`                | 容器的ID                                                     |
| `name`              | 容器的名称                                                   |
| `label`             | 表示键或键值对的任意字符串。表示为`<key>`或`<key>=<value>`   |
| `exited`            | 表示容器退出代码的整数。只用于`--all`。                      |
| `status`            | `created`，`restarting`，`running`，`removing`，`paused`，`exited`，或者`dead` |
| `ancestor`          | 筛选共享给定镜像的容器作为祖先。表现为`<image-name>[:<tag>]`， `<image id>`或`<image@digest>` |
| `before` / `since`  | 过滤在给定容器ID或名称之前或之后创建的容器                   |
| `volume`            | 过滤运行已安装给定卷或绑定安装的容器。                       |
| `network`           | 过滤运行连接到给定网络的容器。                               |
| `publish` /`expose` | 过滤发布或公开给定端口的容器。表示为`<port>[/<proto>]`或`<startport-endport>/[<proto>]` |
| `health`            | 根据其健康检查状态过滤容器。`starting`，`healthy`，`unhealthy`或`none`。 |
| `isolation`         | 仅限Windows守护进程。其中一个`default`，`process`或`hyperv`。 |
| `is-task`           | 筛选作为服务“任务”的容器。布尔选项（`true`或`false`）        |



##### 标签过滤
---
```sh
# color标签的容器
$ docker ps --filter "label=color"
# 匹配color具有blue值的标签的容器
$ docker ps --filter "label=color=blue"
# 包含该nostalgic_stallman字符串的名称
$ docker ps --filter "name=nostalgic_stallman"
# 名称中筛选子字符串
$ docker ps --filter "name=nostalgic"
# 过滤已成功退出的容器
$ docker ps -a --filter 'exited=0'
# 退出状态为137 意味着SIGKILL(9)杀死它们的容器
#任何这些事件都会导致以下137状态：
	# init容器的进程被手动终止
	# docker kill 杀死容器
	# Docker守护进程重启会杀死所有正在运行的容器
$ docker ps -a --filter 'exited=137'

```

##### 状态过滤
---
`status`过滤器的状态相匹配的容器。<br/>可以使用筛选`created`，`restarting`，`running`，`removing`，`paused`，`exited`和`dead`。<br/>例如，要过滤`running`容器：

```sh
$ docker ps --filter status=running
$ docker ps --filter status=paused
```

##### `ancestor`
---
`ancestor`过滤器匹配基于它的形象或它的**后代**在容器上。该过滤器支持以下镜像表示形式：

- `image`
- `image:tag`
- `image:tag@digest`
- `short-id`
- `full-id`

如果未指定`tag`，则使用`latest`标签。例如，要筛选使用最新`ubuntu`镜像的容器，请执行以下操作：

```sh
$ docker ps --filter ancestor=ubuntu
$ docker ps --filter ancestor=ubuntu:12.04.5
# 图层d0e008c6cf02或图层的图层的容器
$ docker ps --filter ancestor=d0e008c6cf02
CONTAINER ID        IMAGE               COMMAND             CREATED              STATUS              PORTS               NAMES
82a598284012        ubuntu:12.04.5      "top"               3 minutes ago        Up 3 minutes    
```

##### 创建时间
---
```sh
# before过滤器只显示与给定id或名称容器之前创建的容器
$ docker ps -f before=9c3527ed70ce
# since过滤器只显示自定id或名称的容器中创建容器
$ docker ps -f since=6e63f6ff38b0
```

##### 卷
---
`volume`筛选器仅显示装载特定卷或将卷装入特定路径的容器：

```sh
$ docker ps --filter volume=remote-volume --format "table {{.ID}}\t{{.Mounts}}"
CONTAINER ID        MOUNTS
9c3527ed70ce        remote-volume

$ docker ps --filter volume=/data --format "table {{.ID}}\t{{.Mounts}}"
CONTAINER ID        MOUNTS
9c3527ed70ce        remote-volume
```

##### 网络
---
`network`过滤器仅显示了连接到网络的具有给定名称或ID的容器。

以下过滤器匹配连接到名称包含`net1`的网络的所有容器。

```sh
$ docker run -d --net=net1 --name=test1 ubuntu top
$ docker run -d --net=net2 --name=test2 ubuntu top

$ docker ps --filter network=net1
```

 网络过滤器匹配网络的名称和ID。以下示例显示了使用`net1`网络ID作为过滤器连接到网络的所有容器;

```sh
$ docker network inspect --format "{{.ID}}" net1
8c0b4110ae930dbe26b258de9bc34a03f98056ed6f27f991d32919bfe401d7c5

$ docker ps --filter network=8c0b4110ae930dbe26b258de9bc34a03f98056ed6f27f991d32919bfe401d7c5
```

##### 发布/公开
---
`publish`和`expose`过滤器仅显示**已发布或暴露**端口与**给定的端口**号，端口范围，或协议的容器。默认协议是`tcp`没有指定的时候。

以下过滤器匹配发布端口为80的所有容器：

```sh
$ docker run -d --publish=80 busybox top
$ docker run -d --expose=8080 busybox top

$ docker ps --filter publish=80
```

以下过滤器匹配所有具有`8000-8080`以下范围的暴露TCP端口的容器：

```sh
$ docker ps --filter expose=8000-8080/tcp

CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
9833437217a5        busybox             "top"               21 seconds ago      Up 19 seconds       8080/tcp            dreamy_mccarthy
```

以下过滤器匹配具有公开`80`UDP端口的所有容器：

```sh
$ docker ps --filter publish=80/udp
```

#### 格式化
---
格式化选项（`--format`）使用Go模板漂亮地打印容器输出。下面列出了Go模板的有效占位符：

| 占位符        | 描述                                                         |
| ------------- | ------------------------------------------------------------ |
| `.ID`         | 容器ID                                                       |
| `.Image`      | 镜像ID                                                       |
| `.Command`    | 引用的命令                                                   |
| `.CreatedAt`  | 容器创建的时间。                                             |
| `.RunningFor` | 自从容器启动以来的耗时。                                     |
| `.Ports`      | 暴露的端口。                                                 |
| `.Status`     | 容器状态。                                                   |
| `.Size`       | 容器磁盘大小。                                               |
| `.Names`      | 容器名称。                                                   |
| `.Labels`     | 所有分配给容器的标签。                                       |
| `.Label`      | 此容器的特定标签的值。例如`'{{.Label "com.docker.swarm.cpu"}}'` |
| `.Mounts`     | 安装在此容器中的卷的名称。                                   |
| `.Networks`   | 连接到此容器的网络的名称。                                   |

使用`--format`选项时，该`ps`命令将按照模板声明输出数据，或者在使用该`table`指令时也包含列标题。

下面的示例使用的模板没有报头，并输出`ID`与 `Command`由所有正在运行的容器冒号分隔条目：

```sh
$ docker ps --format "{{.ID}}: {{.Command}}"

a87ecb4f327c: /bin/sh -c #(nop) MA
01946d9d34d8: /bin/sh -c #(nop) MA
c1d3b0166030: /bin/sh -c yum -y up
41d50ecd2f57: /bin/sh -c #(nop) MA
```

要以表格格式列出所有正在运行的容器及其标签，可以使用：

```sh
$ docker ps --format "table {{.ID}}\t{{.Labels}}"

CONTAINER ID        LABELS
a87ecb4f327c        com.docker.swarm.node=ubuntu,com.docker.swarm.storage=ssd
```
## * stats 统计容器

显示容器资源使用统计信息的实时流。要将数据限制到一个或多个特定容器，请指定由空格分隔的容器**名称或ID**列表。可以指定已停止的容器，但**已停止的容器不会返回任何数据**。

> **注意**：在Linux上，Docker CLI通过从**总内存使用量**中**减去**页面**缓存使用情况**来报告内存使用情况。API不执行此类计算，而是提供内存使用**总量和页面缓存中的数量**，以便客户端可以根据需要使用这些数据。

### 命令参数选项

---

| 选项，简写    | 默认 | 描述                               |
| ------------- | ---- | ---------------------------------- |
| `--all , -a`  |      | 显示所有容器（默认显示正在运行）   |
| `--format`    |      | 使用Go模板打印出漂亮的镜像         |
| `--no-stream` |      | 禁用流式统计信息并仅提取第一个结果 |
| `--no-trunc`  |      | 不要截断输出                       |



### 示例

---

针对Linux守护进程运行 `docker stats` 查看所有正在运行的容器统计数据。

```sh
$ docker stats
CONTAINER ID        NAME                                    CPU %               MEM USAGE / LIMIT     MEM %               NET I/O             BLOCK I/O           PIDS
b95a83497c91        awesome_brattain                        0.28%               5.629MiB / 1.952GiB   0.28%               916B / 0B           147kB / 0B          9
67b2525d8ad1        foobar                                  0.00%               1.727MiB / 1.952GiB   0.09%               2.48kB / 0B         4.11MB / 0B         2
e5c383697914        test-1951.1.kay7x1lh1twk9c0oig50sd5tr   0.00%               196KiB / 1.952GiB     0.01%               71.2kB / 0B         770kB / 0B          1
4bda148efbc0        random.1.vnc8on831idyr42slu578u3cr      0.00%               1.672MiB / 1.952GiB   0.08%               110kB / 0B          578kB / 0B          2
```

如果未[指定使用的格式字符串`--format`](https://docs.docker.com/engine/reference/commandline/stats/#formatting)，则会显示以下列。

| 列名称                   | 描述                                                 |
| ------------------------ | ---------------------------------------------------- |
| `CONTAINER ID` 和 `Name` | 容器的ID和名称                                       |
| `CPU %` 和 `MEM %`       | 容器正在使用的主机CPU和内存的百分比                  |
| `MEM USAGE / LIMIT`      | 容器**使用**的**内存总量**以及**允许**使用的内存总量 |
| `NET I/O`                | 容器通过其**网络**接口发送和接收的数据量             |
| `BLOCK I/O`              | 容器从主机上的块设备读取和写入的数据量               |
| `PIDs`                   | 容器创建的进程或线程的数量                           |

通过**名称和id**在Linux守护进程上运行`docker stats`多个容器。

```sh
$ docker stats awesome_brattain 67b2525d8ad1

CONTAINER ID        NAME                CPU %               MEM USAGE / LIMIT     MEM %               NET I/O             BLOCK I/O           PIDS
b95a83497c91        awesome_brattain    0.28%               5.629MiB / 1.952GiB   0.28%               916B / 0B           147kB / 0B          9
67b2525d8ad1        foobar              0.00%               1.727MiB / 1.952GiB   0.09%               2.48kB / 0B         4.11MB / 0B         2
```

在所有（运行和停止）容器上运行`docker stats`自定义格式。`drunk_visvesvaraya`并且`big_heisenberg`在上述示例中是停止的容器。

```sh
$ docker stats --all --format "table {{.Container}}\t{{.CPUPerc}}\t{{.MemUsage}}" fervent_panini 5acfcb1b4fd1 drunk_visvesvaraya big_heisenberg

CONTAINER                CPU %               MEM USAGE / LIMIT
fervent_panini           0.00%               56KiB / 15.57GiB
5acfcb1b4fd1             0.07%               32.86MiB / 15.57GiB
drunk_visvesvaraya       0.00%               0B / 0B
big_heisenberg           0.00%               0B / 0B
```

#### 格式化
---
格式化选项（`--format`）可以使用Go模板打印容器输出。下面列出了Go模板的有效占位符：

| 占位符       | 描述                          |
| ------------ | ----------------------------- |
| `.Container` | 容器名称或ID（用户输入）      |
| `.Name`      | 容器名称                      |
| `.ID`        | 容器ID                        |
| `.CPUPerc`   | CPU百分比                     |
| `.MemUsage`  | 内存使用情况                  |
| `.NetIO`     | 网络IO                        |
| `.BlockIO`   | 块IO                          |
| `.MemPerc`   | 内存百分比（Windows上不可用） |
| `.PIDs`      | PID数量（在Windows上不可用）  |

使用该`--format`选项时，该`stats`命令可以完全按照模板声明输出数据，或者在使用该 `table`指令时也包含列标题。

以下示例使用不带标题的模板，并输出 由冒号分隔的所有镜像`Container`和`CPUPerc`条目：

```sh
$ docker stats --format "{{.Container}}: {{.CPUPerc}}"

09d3bb5b1604: 6.61%
9db7aa4d986d: 9.19%
3f214c61ad1d: 0.00%
```

要以表格格式列出所有容器统计信息及其名称，CPU百分比和内存使用情况，可以使用：

```sh
$ docker stats --format "table {{.Container}}\t{{.CPUPerc}}\t{{.MemUsage}}"

CONTAINER           CPU %               PRIV WORKING SET
1285939c1fd3        0.07%               796 KiB / 64 MiB
9c76f7834ae2        0.07%               2.746 MiB / 64 MiB
d1ea048f04e4        0.03%               4.583 MiB / 64 MiB
```

默认格式如下：

在Linux上：

```sh
"table {{.ID}}\t{{.Name}}\t{{.CPUPerc}}\t{{.MemUsage}}\t{{.MemPerc}}\t{{.NetIO}}\t{{.BlockIO}}\t{{.PIDs}}"
```

在Windows上：

```sh
"table {{.ID}}\t{{.Name}}\t{{.CPUPerc}}\t{{.MemUsage}}\t{{.NetIO}}\t{{.BlockIO}}"
```

> **注意**：在Docker 17.09及更高版本上，使用`{{.Container}}`列代替`{{.ID}}\t{{.Name}}`。

## * top 显示 

显示容器的运行进程

```sh
$ docker top ubuntu_bash
PID                 USER                COMMAND
20301               root                bash
```
## build 构建

`docker build`命令从Dockerfile和**上下文**构建Docker镜像。构建的上下文是位于指定`PATH`或`URL`中的一组文件。 构建过程可以引用上下文中的任何文件。例如，你的构建可以使用[*COPY*](https://docs.docker.com/engine/reference/builder/#copy) 指令来引用上下文中的文件。

### 命令参数选项

---

| 选项，简写                | 默认   | 描述                                                         |
| ------------------------- | ------ | ------------------------------------------------------------ |
| `--add-host`              |        | 添加自定义的主机到IP映射（主机：IP）                         |
| `--build-arg`             |        | 设置构建时间变量                                             |
| `--cache-from`            |        | 要考虑作为缓存源的镜像                                       |
| `--cgroup-parent`         |        | 容器的可选父cgroup                                           |
| `--compress`              |        | 使用gzip压缩构建上下文                                       |
| `--cpu-period`            |        | 限制CPU CFS（完全公平调度程序）期限                          |
| `--cpu-quota`             |        | 限制CPU CFS（完全公平调度程序）配额                          |
| `--cpu-shares , -c`       |        | CPU份额（相对重量）                                          |
| `--cpuset-cpus`           |        | 允许执行的CPU（0-3,0,1）                                     |
| `--cpuset-mems`           |        | 允许执行的MEM（0-3,0,1）                                     |
| `--disable-content-trust` | `true` | 跳过镜像验证                                                 |
| `--file , -f`             |        | Dockerfile的名称（默认为'PATH / Dockerfile'）                |
| `--force-rm`              |        | 始终删除中间容器                                             |
| `--iidfile`               |        | 将镜像ID写入文件                                             |
| `--isolation`             |        | 容器隔离技术                                                 |
| `--label`                 |        | 设置镜像的元数据                                             |
| `--memory , -m`           |        | 内存限制                                                     |
| `--memory-swap`           |        | 交换限制等于内存加交换：'-1'以启用无限交换                   |
| `--network`               |        | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 在构建期间为RUN指令设置联网模式 |
| `--no-cache`              |        | 构建镜像时不要使用缓存                                       |
| `--platform`              |        | [实验（守护程序）](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)[API 1.32+](https://docs.docker.com/engine/api/v1.32/) 如果服务器具有多平台功能，请设置平台 |
| `--pull`                  |        | 始终尝试拉取镜像的较新版本                                   |
| `--quiet , -q`            |        | 取消构建输出并在成功时打印镜像ID                             |
| `--rm`                    | `true` | 成功构建后移除中间容器                                       |
| `--security-opt`          |        | 安全选项                                                     |
| `--shm-size`              |        | `/dev/shm`的大小                                             |
| `--squash`                |        | [实验（守护进程）](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)[API 1.25+将](https://docs.docker.com/engine/api/v1.25/) 新构建的图层[压缩](https://docs.docker.com/engine/api/v1.25/)到单个新图层中 |
| `--stream`                |        | [实验（守护进程）](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)[API 1.31+](https://docs.docker.com/engine/api/v1.31/) Stream连接到服务器以协商构建上下文 |
| `--tag , -t`              |        | 以'名称：标记'格式命名和可选的标记                           |
| `--target`                |        | 设置要构建的目标构建阶段。                                   |
| `--ulimit`                |        | Ulimit选项                                                   |



### 构建 URL 参数资源

---

`URL`参数可以引用三种资源：Git仓库，预打包的tarball上下文和纯文本文件。

#### Git 仓库
---
当`URL`参数指向Git 仓库的位置时，仓库将充当构建上下文。系统递归地获取仓库及其子模块。提交历史记录不会保留。首先将仓库**拉入本地主机的临时目录**中。在成功之后，目录将**作为上下文**发送到**Docker守护进程**。本地副本能够使用本地用户凭证、VPN等访问私人仓库。

> **注意：** 如果`URL`参数包含一个片段，则系统将使用`git clone --recursive`命令递归地克隆仓库及其子模块。

Git URL接受片段中的上下文配置，用冒号`:`分隔。第一部分代表Git将**检出的引用，可以是分支**，标记或远程引用。第二部分表示**仓库内的子目录**，将用作构建上下文。

例如，运行以下命令以使用`docker`分支中 调用的目录`container`：

```sh
$ docker build https://github.com/docker/rootfs.git#container:docker
```

下表显示了所有有效的后缀及其构建上下文：

| 构建语法后缀                   | 提交使用              | 使用构建上下文 |
| ------------------------------ | --------------------- | -------------- |
| `myrepo.git`                   | `refs/heads/master`   | `/`            |
| `myrepo.git#mytag`             | `refs/tags/mytag`     | `/`            |
| `myrepo.git#mybranch`          | `refs/heads/mybranch` | `/`            |
| `myrepo.git#pull/42/head`      | `refs/pull/42/head`   | `/`            |
| `myrepo.git#:myfolder`         | `refs/heads/master`   | `/myfolder`    |
| `myrepo.git#master:myfolder`   | `refs/heads/master`   | `/myfolder`    |
| `myrepo.git#mytag:myfolder`    | `refs/tags/mytag`     | `/myfolder`    |
| `myrepo.git#mybranch:myfolder` | `refs/heads/mybranch` | `/myfolder`    |



#### Tarball上下文
---
如果将URL传递到远程tarball，则URL本身会发送到守护进程：

```sh
$ docker build http://server/context.tar.gz
```

下载操作将在运行Docker**守护进程的主机**上执行，它**不一定是发出构建命令的主机**。Docker守护进程将获取`context.tar.gz`并使用它作为构建上下文。Tarball上下文必须是符合标准`tar`UNIX格式的tar档案， 并且可以使用`'xz'，'bzip2'，'gzip'或'identity'（无压缩）`格式中的任何一种进行压缩。

#### 文本文件
---
可以在URL中传递一个`Dockerfile`，或者通过`STDIN`传输文件，而不是指定上下文。从`STDIN`管道`Dockerfile`：

```sh
$ docker build - < Dockerfile
```

通过`Windows`上的`Powershell`，可以运行：

```sh
Get-Content Dockerfile | docker build -
```

如果使用`STDIN`或指定一个`URL`指向一个**纯文本文件**时，系统将**内容**放入一个名为`Dockerfile`，任何`-f`，`--file` 选项被**忽略**。在这种情况下，没有上下文。

默认情况下，`docker build`命令将在**构建上下文**的**根目录**中查找`Dockerfile`。使用`-f，--file`选项可以指定**替代文件的路径**。这在多个版本使用同一组文件的情况下很有用。路径**必须是构建上下文**中的文件。如果指定了相对路径，则它被解释为**相对于上下文**的根。

在大多数情况下，最好将每个`Dockerfile`放在一个**空目录**中。然后，仅向目录添加构建`Dockerfile`所需的文件。为了提高构建的性能，也可以通过将`.dockerignore`文件**添加该目录来排除文件和目录**。请参阅[.dockerignore文件](https://docs.docker.com/engine/reference/builder/#dockerignore-file)。

如果Docker客户端**失去**与守护进程的连接，则**构建将被取消**。如果使用`CTRL-c`中断Docker客户端，或者因为任何原因**终止**了Docker客户端，就会发生这种情况。如果构建启动了一个在**构建被取消**时仍在运行的`pull`，`pull`也被取消。

### 示例

---

#### 用 PATH 构建

```sh
$ docker build .

Uploading context 10240 bytes
Step 1/3 : FROM busybox
Pulling repository busybox
 ---> e9aa60c60128MB/2.284 MB (100%) endpoint: https://cdn-registry-1.docker.io/v1/
Step 2/3 : RUN ls -lh /
 ---> Running in 9c9e81692ae9
total 24
drwxr-xr-x    2 root     root        4.0K Mar 12  2013 bin
drwxr-xr-x    5 root     root        4.0K Oct 19 00:19 dev
drwxr-xr-x    2 root     root        4.0K Oct 19 00:19 etc
drwxr-xr-x    2 root     root        4.0K Nov 15 23:34 lib
lrwxrwxrwx    1 root     root           3 Mar 12  2013 lib64 -> lib
dr-xr-xr-x  116 root     root           0 Nov 15 23:34 proc
lrwxrwxrwx    1 root     root           3 Mar 12  2013 sbin -> bin
dr-xr-xr-x   13 root     root           0 Nov 15 23:34 sys
drwxr-xr-x    2 root     root        4.0K Mar 12  2013 tmp
drwxr-xr-x    2 root     root        4.0K Nov 15 23:34 usr
 ---> b35f4035db3f
Step 3/3 : CMD echo Hello world
 ---> Running in 02071fceb21b
 ---> f52f38b7823e
Successfully built f52f38b7823e
Removing intermediate container 9c9e81692ae9
Removing intermediate container 02071fceb21b
```

这个例子指定了`PATH `为当前目录 `.`，因此本地目录中的所有文件都**得到`tar`并发送到Docker守护进程**。`PATH`指定在Docker**守护进程中查找构建“上下文”的文件**的位置。请记住守护进程可能在远程计算机上运行，并且在客户端（运行docker生成的地方）**不会解析 `Dockerfile`**。这意味着PATH中的**所有文件**都会被**发送**，而不仅仅是在`Dockerfile`中列出的`ADD`文件。 

上下文从本地机器到Docker守护进程的转移是Docker客户机在看到“发送构建上下文”消息时的含义。

如果希望在构建完成后**保留中间容器**，则必须使用`--rm = false`。这不会影响构建缓存。

#### 用 URL 构建
---
```sh
$ docker build github.com/creack/docker-firefox
```

这将克隆`GitHub`仓库，并将克隆的仓库用作上下文。仓库根目录下的`Dockerfile`用作构建的`Dockerfile`。你可以使用`git://`或 `git@`方案来指定一个任意的`Git`仓库。

```sh
$ docker build -f ctx/Dockerfile http://server/ctx.tar.gz

Downloading context: http://server/ctx.tar.gz [===================>]    240 B/240 B
Step 1/3 : FROM busybox
 ---> 8c2e06607696
Step 2/3 : ADD ctx/container.cfg /
 ---> e7829950cee3
Removing intermediate container b35224abf821
Step 3/3 : CMD /bin/ls
 ---> Running in fbc63d321d73
 ---> 3286931702ad
Removing intermediate container fbc63d321d73
Successfully built 377c409b35e4
```

这会将**URL发送`http://server/ctx.tar.gz`到Docker守护进程**，Docker守护进程会**下载并提取**引用的tarball。`-f ctx/ Dockerfile`参数在`ctx.tar.gz`中指定用于构建镜像的`Dockerfile`中的路径。该`Dockerfile`中引用本地路径的任何`ADD`命令都必须与`ctx.tar.gz`内的根目录相关。在上面的示例中，tarball包含一个目录`ctx/`，因此`ADD ctx/container.cfg /`操作按预期工作。

#### 用` - `构建
---
```sh
$ docker build - < Dockerfile
```

这将从`STDIN`中读取一个**没有上下文**的`Dockerfile`。由于缺少上下文，任何本地目录的内容都**不会发送**到Docker守护进程。由于没有上下文，因此`Dockerfile`  `ADD`仅在引用远程`URL`时才起作用。

```sh
$ docker build - < context.tar.gz
```

这将为从`STDIN`读取的**压缩上下文**构建一个镜像。支持的格式是：`bzip2，gzip和xz`。

#### 使用`.dockerignore`文件
---
```sh
$ docker build .

Uploading context 18.829 MB
Uploading context
Step 1/2 : FROM busybox
 ---> 769b9341d937
Step 2/2 : CMD echo Hello world
 ---> Using cache
 ---> 99cc1ad10469
Successfully built 99cc1ad10469

$ echo ".git" > .dockerignore

$ docker build .
Uploading context  6.76 MB
Uploading context
Step 1/2 : FROM busybox
 ---> 769b9341d937
Step 2/2 : CMD echo Hello world
 ---> Using cache
 ---> 99cc1ad10469
Successfully built 99cc1ad10469
```

上面显示使用`.dockerignore`文件从上下文中**排除`.git`目录**。其效果可以在**上传的上下文的改变大小**容量空间看到。

#### 镜像标签 `(-t)`
---
```sh
$ docker build -t vieux/apache:2.0 .
```

这将像前面的示例一样构建，但它会**标签生成的镜像**。仓库名称是`vieux/apache`，标签将会是`2.0`。 [详细了解有效标签](https://docs.docker.com/engine/reference/commandline/tag/)。

可以将**多个标签应用于镜像**。例如，可以将`latest` 标签应用于新建的镜像，并添加引用特定版本的另一个标签。例如，要将镜像标记为`whenry/fedora-jboss:latest`和 `whenry/fedora-jboss:v2.1`，请使用以下内容：

```sh
$ docker build -t whenry/fedora-jboss:latest -t whenry/fedora-jboss:v2.1 .
```

#### 指定Dockerfile `(-f)`
---
```sh
$ docker build -f Dockerfile.debug .
```

这将使用一个叫做`Dockerfile.debug`构建指令的文件来代替`Dockerfile`。

```sh
$ curl example.com/remote/Dockerfile | docker build -f - .
```

上述命令将使用当前目录作为构建上下文，并从`stdin`中读取`Dockerfile`。

```sh
$ docker build -f dockerfiles/Dockerfile.debug -t myapp_debug .
$ docker build -f dockerfiles/Dockerfile.prod  -t myapp_prod .
```

上述命令将一次使用`Dockerfile`的**调试版本**和一次使用**生产版本**的情况下，两次构建当前构建上下文。

```sh
$ cd /home/me/myapp/some/dir/really/deep
$ docker build -f /home/me/myapp/dockerfiles/debug /home/me/myapp
$ docker build -f ../../../../dockerfiles/debug /home/me/myapp
```

这两个`docker build`命令完成同样的事情。他们都使用调试文件的内容而不是查找`Dockerfile`，并将`/home/me/myapp`用作构建上下文的根。请注意，`debug`位于构建上下文的目录结构中，而不管在命令行上如何引用它。

> **注意：** 如果**文件或目录**不存在于**上传的上下文**中，`docker build`将返回`no such file or directory`错误。如果**没有**上下文，或者指定的文件位于**主机系统**的其他位置，则可能会发生这种情况。由于安全原因，上下文**仅限于当前目录（及其子目录）**，并确保远程Docker主机上的**可重复构建**。这也是`ADD ../file`不能工作的原因 。

#### 使用自定义父级cgroup `(--cgroup-parent)`

当`docker build`使用`--cgroup-parent`选项运行时，构建中使用的容器将与[相应的`docker run` 选项](https://docs.docker.com/engine/reference/run/#specifying-custom-cgroups)一起运行。

#### 在容器中设置ulimits `（--ulimit）`
---
在Docker构建中使用`--ulimit`选项将会使用`--ulimit`选项值来启动每个构建步骤的容器。

#### 设置生成时间变量 `（--build-arg）`
---
可以在`Dockerfile`中使用`ENV`指令来定义**变量值**。这些值**持久在构建的镜像**中。但是，往往持久不是我们想要的。用户想要根据他们在哪个主机上构建镜像来**指定不同的变量**。

下面的例子是用于`pull`中间文件的`http_proxy`或源版本。`ARG`指令允许`Dockerfile`作者定义用户可以在构建时使用`--build-arg`选项设置的值：

```sh
$ docker build --build-arg HTTP_PROXY=http://10.20.30.2:1234 .
```

`--build-arg`选项允许在`Dockerfile`的`RUN`指令中**传递像常规环境变量那样访问的构建时变量**。而且，这些值不会像`ENV`值那样**保留在中间或最终镜像**中。

使用此选项不会改变在构建过程中回显来自`Dockerfile`的`ARG`行时看到的输出。

有关使用`ARG`和`ENV`指令的详细信息，请参阅 [Dockerfile参考](https://docs.docker.com/engine/reference/builder/)。

#### 可选的安全选项`（--security-opt）`
---
该选项仅在Windows上运行的守护程序上受支持，并且只支持`credentialspec`选项。在`credentialspec`必须在格式`file://spec.txt`或`registry://keyname`。

#### 指定容器的隔离 `（ - isolation）`
---
在Windows上运行Docker容器的情况下，此选项很有用。`--isolation=<value>`选项设置容器的隔离技术。在Linux上，唯一支持的是`default`使用**Linux命名空间**的选项。在Microsoft Windows上，可以指定这些值：

| 值        | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| `default` | 使用Docker守护进程指定的值`--exec-opt`。如果`daemon`不指定隔离技术，则Microsoft Windows会将`process`其用作其默认值。 |
| `process` | 仅命名空间隔离。                                             |
| `hyperv`  | 基于Hyper-V管理程序分区的隔离。                              |

<br/>指定不带值的`--isolation`选项与设置`--isolation =default`相同。

#### 将键值添加到容器host文件`（--add-host）`
---
可以使用一个或多个`--add-host`选项将其他主机添加到容器的`/etc/hosts`文件中。本示例为名为`docker`的主机添加一个静态地址：

```sh
$ docker build --add-host=docker:10.180.0.1 .
```

#### 指定目标构建阶段`（--target）`
---
在构建具有**多个构建阶段的Dockerfile时**，可以使用`--target`通过**名称**指定**中间构建阶段**作为结果镜像的最后阶段。目标阶段之后的命令将被**跳过**。

```sh
FROM debian AS build-env
...

FROM alpine AS production-env
...
$ docker build -t mybuildimage --target build-env .
```

#### 挤压镜像的图层 `(--squash) (experimental)`
---
**概述**

---

建立镜像后，将新图层**压缩**为具有**单个新图层**的新镜像。压缩**不会破坏**任何现有镜像，而是会**创建**一个**压缩图层**内容的新镜像。这有效地使得它看起来像所有`Dockerfile`命令都是用**单层**创建的。构建缓存使用此方法保留。

`--squash`选项是一个**实验性功能，会存在为不稳定**的可能。

如果`Dockerfile`生成多个修改**相同文件的图层**，例如，在一个步骤中创建并在另一个步骤中删除的文件，则压缩图层可能会有所帮助。对于其他使用情况，挤压镜像实际上可能会**对性能产生负面影响**，当`pull`由多个图层组成的镜像时，可以**平行拉取图层**，并允许在镜像之间**共享图层**（节省空间）。

对于大多数用例而言，**多阶段**是更好的选择，因为它们可以**更精细**地控制构建，并且可以利用**构建器中的优化未来**。 有关更多信息，请参阅用户指南中的[使用多阶段构建](https://docs.docker.com/engine/userguide/eng-image/multistage-build/)部分。

**已知的限制**

---

`--squash`选项有许多已知的限制：

- 压缩图层时，生成的镜像**无法利用与其他镜像共享的图层**，并**可能使用更多空间**。**共享基础镜像**仍然受支持。
- 使用此选项时，可能会看到**占用更多的空间**，因为**存储了两个镜像副本**，一个用于构建**高速缓存**，其中所有高速缓存层均已完成，另一个用于**压缩版本**。
- 虽然挤压图层**可能会产生较小**的镜像，但它可能会对**性能产生负面**影响，因为单个图层需要**更长的时间**才能提取，而**下载**单个图层**无法并行化**。
- 当试图压缩**不会**对文件系统进行**更改**的镜像（例如，Dockerfile只包含`ENV`指令）时，**压缩步骤将失败**

**必备条件**

---

此页面上的示例在Docker 1.13中使用**实验模式**。可以通过在启动Docker守护进程时使用`--experimental`选项或在`daemon.json`配置文件中设置`experimental：true`来**启用实验模式**。

默认情况下，实验模式被**禁用**。要查看当前配置，请使用`docker version`命令。

```sh
Server:
 Version:      1.13.1
 API version:  1.26 (minimum version 1.12)
 Go version:   go1.7.5
 Git commit:   092cba3
 Built:        Wed Feb  8 06:35:24 2017
 OS/Arch:      linux/amd64
 Experimental: false

 [...]
```

要启用实验模式，用户需要**重启**启用实验选项的docker**守护进程**。

**启用DOCKER实验**

---

从版本1.13.0开始，标准Docker二进制文件现在**包含实验性**功能。为了启用实验性功能，需要启动带有`--experimental`选项的Docker守护进程。你也可以通过`/etc/docker/daemon.json`启用守护进程选项。例如

```sh
{
    "experimental": true
}
```

然后确保实验选项已启用：

```sh
$ docker version -f '{{.Server.Experimental}}'
true
```

**用`--SQUASH`参数构建镜像**

---

以下是使用`--squash`参数构建docker的示例

```sh
FROM busybox
RUN echo hello > /hello
RUN echo world >> /hello
RUN touch remove_me /remove_me
ENV HELLO world
RUN rm /remove_me
```

一个名为`test`的镜像是用`--squash`参数构建的。

```sh
$ docker build --squash -t test .

[...]
```

如果一切正常，历史将如下所示：

```sh
$ docker history test 
IMAGE               CREATED             CREATED BY                                      SIZE                COMMENT
4e10cb5b4cac        3 seconds ago                                                       12 B                merge sha256:88a7b0112a41826885df0e7072698006ee8f621c6ab99fca7fe9151d7b599702 to sha256:47bcc53f74dc94b1920f0b34f6036096526296767650f223433fe65c35f149eb
<missing>           5 minutes ago       /bin/sh -c rm /remove_me                        0 B
<missing>           5 minutes ago       /bin/sh -c #(nop) ENV HELLO=world               0 B
<missing>           5 minutes ago       /bin/sh -c touch remove_me /remove_me           0 B
<missing>           5 minutes ago       /bin/sh -c echo world >> /hello                 0 B
<missing>           6 minutes ago       /bin/sh -c echo hello > /hello                  0 B
<missing>           7 weeks ago         /bin/sh -c #(nop) CMD ["sh"]                    0 B
<missing>           7 weeks ago         /bin/sh -c #(nop) ADD file:47ca6e777c36a4cfff   1.113 MB
```

我们可以发现所有图层的名称都是`<missing>`，并且COMMENT有一个新图层`merge`。<br/>测试镜像，检查`/remove_me`是否消失，确保`hello\nworld`处于`/hello`确定`HELLO`envvar的值`world`。

## run 运行镜像

`docker run`命令首先在指定的映像上`creates`一个可写容器层，然后使用指定的`starts`命令启动它。也就是说， `docker run`相当于API `/containers/create`，然后调用 `/containers/(id)/start`。已停止的容器可以`docker start`重新启动，并保持原来的所有更改不变。请参阅`docker ps -a`查看所有容器的列表。

`docker run`命令可以在组合使用`docker commit`，以 [*改变一个容器中运行的命令*](https://docs.docker.com/engine/reference/commandline/commit/)。

### 命令参数选项

---

| 选项，简写                | 默认      | 描述                                                         |
| ------------------------- | --------- | ------------------------------------------------------------ |
| `--add-host`              |           | 添加自定义的主机到IP映射（主机：IP）                         |
| `--attach , -a`           |           | 附加到STDIN，STDOUT或STDERR                                  |
| `--blkio-weight`          |           | 阻止IO（相对权重），介于10和1000之间，或0禁用（默认值为0）   |
| `--blkio-weight-device`   |           | 块IO重量（相对设备重量）                                     |
| `--cap-add`               |           | 添加Linux功能                                                |
| `--cap-drop`              |           | 删除Linux功能                                                |
| `--cgroup-parent`         |           | 容器的可选父cgroup                                           |
| `--cidfile`               |           | 将容器ID写入文件                                             |
| `--cpu-count`             |           | CPU数量（仅限Windows）                                       |
| `--cpu-percent`           |           | CPU百分比（仅限Windows）                                     |
| `--cpu-period`            |           | 限制CPU CFS（完全公平调度程序）期间                          |
| `--cpu-quota`             |           | 限制CPU CFS（完全公平调度程序）配额                          |
| `--cpu-rt-period`         |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 以微秒为单位限制CPU实时周期 |
| `--cpu-rt-runtime`        |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 以微秒为单位限制CPU实时运行时间 |
| `--cpu-shares , -c`       |           | CPU份额（相对重量）                                          |
| `--cpus`                  |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) CPU数量 |
| `--cpuset-cpus`           |           | 允许执行的CPU（0-3,0,1）                                     |
| `--cpuset-mems`           |           | 允许执行的MEM（0-3,0,1）                                     |
| `--detach , -d`           |           | 在后台运行容器并打印容器ID                                   |
| `--detach-keys`           |           | 覆盖分离容器的键序列                                         |
| `--device`                |           | 将主机设备添加到容器                                         |
| `--device-cgroup-rule`    |           | 将规则添加到cgroup允许的设备列表                             |
| `--device-read-bps`       |           | 限制设备的读取速率（每秒字节数）                             |
| `--device-read-iops`      |           | 限制设备的读取速率（每秒IO）                                 |
| `--device-write-bps`      |           | 限制写入速率（每秒字节数）到设备                             |
| `--device-write-iops`     |           | 限制写入速率（每秒IO）到设备                                 |
| `--disable-content-trust` | `true`    | 跳过图像验证                                                 |
| `--dns`                   |           | 设置自定义DNS服务器                                          |
| `--dns-opt`               |           | 设置DNS选项                                                  |
| `--dns-option`            |           | 设置DNS选项                                                  |
| `--dns-search`            |           | 设置自定义DNS搜索域                                          |
| `--entrypoint`            |           | 覆盖图像的默认入口点                                         |
| `--env , -e`              |           | 设置环境变量                                                 |
| `--env-file`              |           | 读入环境变量文件                                             |
| `--expose`                |           | 公开一个端口或一系列端口                                     |
| `--group-add`             |           | 添加其他群组加入                                             |
| `--health-cmd`            |           | 运行以检查运行状况的命令                                     |
| `--health-interval`       |           | 运行检查之间的时间（ms \| s \| m \| h）（默认为0）           |
| `--health-retries`        |           | 需要报告不健康的连续失败                                     |
| `--health-start-period`   |           | [API 1.29+](https://docs.docker.com/engine/api/v1.29/) 在开始健康重试倒数前，容器要初始化的起始时间段（ms \| s \| m \| h）（默认值为0） |
| `--health-timeout`        |           | 允许一次检查运行的最长时间（ms \| s \| m \| h）（默认值为0） |
| `--help`                  |           | 打印用法                                                     |
| `--hostname , -h`         |           | 容器主机名称                                                 |
| `--init`                  |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 在容器中运行一个init，用于转发信号并收集进程 |
| `--interactive , -i`      |           | 即使没有连接，也要保持STDIN打开                              |
| `--io-maxbandwidth`       |           | 系统驱动器的最大IO带宽限制（仅限Windows）                    |
| `--io-maxiops`            |           | 系统驱动器的最大IOps限制（仅限Windows）                      |
| `--ip`                    |           | IPv4地址（例如172.30.100.104）                               |
| `--ip6`                   |           | IPv6地址（例如，2001：db8 :: 33）                            |
| `--ipc`                   |           | 使用IPC模式                                                  |
| `--isolation`             |           | 容器隔离技术                                                 |
| `--kernel-memory`         |           | 内核内存限制                                                 |
| `--label , -l`            |           | 在容器上设置元数据                                           |
| `--label-file`            |           | 阅读标签的行分隔文件                                         |
| `--link`                  |           | 将链接添加到其他容器                                         |
| `--link-local-ip`         |           | Container IPv4 / IPv6链路本地地址                            |
| `--log-driver`            |           | 记录容器的驱动程序                                           |
| `--log-opt`               |           | 日志驱动选项                                                 |
| `--mac-address`           |           | 容器MAC地址（例如，92：d0：c6：0a：29：33）                  |
| `--memory , -m`           |           | 内存限制                                                     |
| `--memory-reservation`    |           | 内存软限制                                                   |
| `--memory-swap`           |           | 交换限制等于内存加交换：'-1'以启用无限交换                   |
| `--memory-swappiness`     | `-1`      | 调整容器内存swappiness（0到100）                             |
| `--mount`                 |           | 将文件系统挂载附加到容器                                     |
| `--name`                  |           | 为容器分配一个名称                                           |
| `--net`                   |           | 将容器连接到网络                                             |
| `--net-alias`             |           | 为容器添加网络范围的别名                                     |
| `--network`               |           | 将容器连接到网络                                             |
| `--network-alias`         |           | 为容器添加网络范围的别名                                     |
| `--no-healthcheck`        |           | 禁用任何容器指定的HEALTHCHECK                                |
| `--oom-kill-disable`      |           | 禁用OOM杀手                                                  |
| `--oom-score-adj`         |           | 调整主机的OOM首选项（从-1000到1000）                         |
| `--pid`                   |           | 要使用的PID名称空间                                          |
| `--pids-limit`            |           | 调整容器匹配限制（无限制地设置-1）                           |
| `--platform`              |           | [实验（守护程序）](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)[API 1.32+](https://docs.docker.com/engine/api/v1.32/) 如果服务器具有多平台功能，请设置平台 |
| `--privileged`            |           | 给这个容器赋予扩展权限                                       |
| `--publish , -p`          |           | 将容器的端口发布到主机                                       |
| `--publish-all , -P`      |           | 将所有暴露的端口发布到随机端口                               |
| `--read-only`             |           | 将容器的根文件系统挂载为只读                                 |
| `--restart`               | `no`      | 重新启动策略以在容器退出时应用                               |
| `--rm`                    |           | 当容器退出时自动移除容器                                     |
| `--runtime`               |           | 运行时用于此容器                                             |
| `--security-opt`          |           | 安全选项                                                     |
| `--shm-size`              |           | `/dev/shm`的大小                                             |
| `--sig-proxy`             | `true`    | 代理接收到进程的信号                                         |
| `--stop-signal`           | `SIGTERM` | 停止容器的信号                                               |
| `--stop-timeout`          |           | [API 1.25+](https://docs.docker.com/engine/api/v1.25/) 超时（以秒为单位）停止容器 |
| `--storage-opt`           |           | 容器的存储驱动程序选项                                       |
| `--sysctl`                |           | Sysctl选项                                                   |
| `--tmpfs`                 |           | 挂载一个tmpfs目录                                            |
| `--tty , -t`              |           | 分配一个伪TTY                                                |
| `--ulimit`                |           | Ulimit选项                                                   |
| `--user , -u`             |           | 用户名或UID（格式：`<name | uid> [：<group | gid>]`）        |
| `--userns`                |           | 要使用的用户名称空间                                         |
| `--uts`                   |           | UTS命名空间使用                                              |
| `--volume , -v`           |           | 绑定安装一个卷                                               |
| `--volume-driver`         |           | 容器的可选卷驱动程序                                         |
| `--volumes-from`          |           | 从指定容器装载卷                                             |
| `--workdir , -w`          |           | 容器内的工作目录                                             |

### 示例

---

#### 分配名称和TTY选项 `--name -it`

```sh
$ winpty docker run --name box -it busybox
/ # ls
bin   dev   etc   home  proc  root  sys   tmp   usr   var
/ # exit 13

$ echo $?
13
```

这个例子运行一个`busybox:latest` 图像使用`box`命名的容器。`-it`指示docker分配一个伪TTY连接到容器的`stdin`。 `bash`在容器中创建一个交互式shell。在示例中，`bash`通过输入`exit 13`来退出shell 。此退出代码被传递给`docker run`调用者 ，并记录在`box`容器的元数据中。

#### 提取容器ID `--cidfile`

---

```sh
$ docker run --cidfile /tmp/docker_test.cid busybox echo "test"
test
$ cat /tmp/docker_test.cid
5e1fd236d25df9c4e90a51d1bdf0ba6d3c302162d3d06c196aa0a3b891ddc602
```

创建一个容器并打印`test`到控制台。`cidfile` 标志使得Docker尝试创建一个新文件并将容器ID写入到这个文件中。如果文件已经存在，Docker会返回一个错误。Docker在`docker run`退出时会关闭这个文件。

#### 完整的容器功能 `--privileged`

---

```sh
$ winpty docker run --name box -it busybox
root@bc338942ef20:/# mount -t tmpfs none /mnt
mount: permission denied  (are you root?)
```

会发现**没有权限**，因为默认情况下，大多数具有**潜在危险**的内核功能**都被屏蔽**。 包括`cap_sys_admin`（这是挂载文件系统所必需的）。但是 `--privileged`标志将允许它运行：

```sh
$ winpty docker run --name box -it --rm --privileged  busybox
root@50e3f57e16e6:/# mount -t tmpfs none /mnt
root@50e3f57e16e6:/# df -h
Filesystem      Size  Used Avail Use% Mounted on
none            1.9G     0  1.9G   0% /mnt
```

`--privileged`标志为容器提供了**所有**功能，并且还提升了`device`cgroup控制器执行的**所有**限制。换句话说，**容器可以做主机可以做的几乎所有事情**。这个标志存在允许特殊的用例，比如**在Docker中运行Docker**。

#### 设置工作目录 `-w`

---

```sh
$ docker run -w /path/to/dir/ -it  busybox pwd
/path/to/dir
```

`-w` 让命令在给定的目录里执行，这里是`/path/to/dir/`。如果路径不存在，它将在容器内创建。

#### 为容器设置存储驱动器选项

---

```sh
$ docker run -it --rm --storage-opt size=1G busybox /bin/bash
```

`size`选项将在创建时将容器`rootfs`大小设置为`1G`。此选项仅适用于`devicemapper`，`btrfs`，`overlay2`， `windowsfilter`和`zfs`图形驱动程序。对于`devicemapper`，`btrfs`，`windowsfilter`和`zfs`图形驱动程序，用户无法通过的尺寸小于默认尺寸`BaseFS`。对于`overlay2`存储驱动程序，大小选项仅在支持`fs`为`xfs`并使用`pquota`安装选项安装时可用。在这些条件下，用户可以传递小于后备`fs`大小的任何大小。

#### 挂载tmpfs `--tmpfs`

---

```sh
$ docker run -d --tmpfs /run:rw,noexec,nosuid,size=65536k my_image
```

`--tmpfs`标志将空`tmpfs`与`rw，noexec，nosuid，size = 65536k`选项一起装载到容器中 

#### 挂载卷 装入卷  `-v， --read-only`

---

```sh
$ docker run  -v `pwd`:`pwd` -w `pwd` -i -t  busybox pwd
```

`-v`标志将**当前工作目录挂载到容器**中。在`-w` 让容器在当前的工作目录内执行。`pwd` 会输出当前容器的工作目录。

```sh
$ docker run -v /doesnt/exist:/foo -w /foo -i -t busybox sh
```

当绑定挂载卷的主机**目录不存在**时，Docker会自动在主机上**创建此目录**。在上面的例子中，Docker将`/doesnt/exist` 在启动容器之前创建文件夹。

```sh
$ docker run --read-only -v /icanwrite busybox touch /icanwrite/here

$ docker run --read-only -v /icanwrite busybox sh
```

卷可以结合使用`--read-only`来控制容器写入文件的位置。`--read-only`标志将容器的根文件系统挂载为**只读**，**禁止写入容器指定卷以外的位置**。

```sh
$ docker run -ti -v /var/run/docker.sock:/var/run/docker.sock -v /path/to/static-docker-binary:/usr/bin/docker busybox sh
```

通过绑定`docker unix`套接字和静态链接的docker二进制文件（请参阅[获取linux二进制文件](https://docs.docker.com/engine/installation/binaries/#/get-the-linux-binary)），可以赋予容器完全访问权限，以创建和操作主机的Docker守护进程。

#### 使用--mount标志添加绑定挂载或卷

---

`--mount`标志允许在容器中安装`tmpfs`卷、主机目录和挂载。`--mount`标志支持`-v` 或`--volume`标志支持的大多数选项，但使用不同的语法。即使没有计划弃用`-volume`，建议使用`--mount`。

```sh
$ docker run --read-only --mount type=volume,target=/icanwrite busybox touch /icanwrite/here
$ docker run -t -i --mount type=bind,src=/data,dst=/data busybox sh
```

#### 发布或公开端口 `-p，--expose`

---

```sh
$ docker run -p 127.0.0.1:80:8080/tcp ubuntu bash
```

这将`8080`容器的端口绑定到主机`127.0.0.1`的TCP`80`端口上。也可以指定`udp`和`sctp`端口。

```sh
$ docker run --expose 80 ubuntu bash
```

暴露`80`容器的端口而不将端口发布到主机系统的接口。 

#### 设置环境变量 `-e，--env，--env-file`

---

```sh
$ docker run -e MYVAR1 --env MYVAR2=foo --env-file ./env.list ubuntu bash
```

使用`-e，--env`和`--env-file`标志在运行的容器中设置简单（非数组）的环境变量，或覆盖正在运行的映像的`Dockerfile`中定义的变量。可以在运行容器时定义变量及其值：

```sh
$ docker run --env VAR1=value1 --env VAR2=value2 busybox env | grep VAR
VAR1=value1
VAR2=value2
```

也可以使用已经`export`到本地环境的变量：

```sh
export VAR1=value1
export VAR2=value2

$ docker run --env VAR1 --env VAR2 ubuntu env | grep VAR
VAR1=value1
VAR2=value2
```

在运行命令时，Docker CLI 客户端将**检查变量在本地环境中的值并将其传递给容器**。如果没有提供 `=`赋值，并且变量未在本地环境中`export`，则该变量将不会在容器中进行设置。

也可以**从文件中加载环境变量**。该文件应该使用语法`<variable>=value`（将变量设置为给定值）或 `<variable>`（从本地环境获取值）以及`#`注释。

```sh
$ cat env.list
# This is a comment
VAR1=value1
VAR2=value2
USER

$ docker run --env-file env.list ubuntu env | grep VAR
VAR1=value1
VAR2=value2
USER=denis
```

#### 在容器上设置元数据 `-l，--label，--label-file`

---

标签`label`是将元数据应用于容器的`键=值`对。用两个标签标注容器：

```sh
$ docker run -l my-label --label com.example.foo=bar ubuntu bash
```

`my-label`键没有指定值，因此标签默认为空字符串（`""`）。要添加多个标签，请重复标签标志（`-l`或`--label`）。`key=value`必须是**唯一**的，以避免**覆盖**的标签值。如果使用相同的键但指定了不同的值，则每个**后续值都会覆盖前一个值**。Docker 使用提供的最后一个`key=value`。

使用`--label-file`标志从文件加载多个标签。用EOL标记分隔文件中的每个标签。下面的示例从当前目录中的标签文件加载标签：

```sh
$ docker run --label-file ./labels ubuntu bash
```

标签文件格式与加载环境变量的格式类似。（与环境变量不同，**标签对容器内运行的进程不可见**。）以下示例说明了标签文件格式：

```sh
com.example.label1="a label"

# this is a comment
com.example.label2=another\ label
com.example.label3
```

可以通过提供多个`--label-file`标志来加载多个标签文件 。

#### 将容器连接到网络  `--network`

---

当启动容器时，请使用`--network`标志将其连接到网络。将`busybox`容器添加到`my-net`网络。

```sh
$ docker run -itd --network=my-net busybox
```

当在用户定义的网络上启动容器时，还可以选择带有`--ip`和`--ip6`标志的容器的IP地址。

```sh
$ docker run -itd --network=my-net --ip=10.10.9.75 busybox
```

如果要将正在运行的容器添加到网络，请使用`docker network connect`子命令。

可以将多个容器连接到同一个网络。一旦连接，容器可以很容易地通信，只需要另一个容器的IP地址或名称。对于`overlay`支持多主机连接的网络或自定义插件，连接到相同多主机网络但从不同引擎启动的容器也可以通过这种方式进行通信。

> **注意**：服务发现在默认网桥上不可用。容器默认通过IP地址进行通信。要通过名称进行交流，他们必须联系起来。

可以使用`docker network disconnect`命令从网络断开容器。

#### 从容器装入卷 `--volumes-from`

---

```sh
$ docker run --volumes-from 777f7dc92da7 --volumes-from ba8c0c54f0f2:ro -i -t ubuntu pwd
```

`--volumes-from`标志会从引用的容器中挂载所定义的卷。容器可以通过重复`-volumes-from`参数来指定。容器ID可以选择性地添加后缀`：ro`或`：rw`以分别将卷挂载到只读或读写模式。默认情况下，卷以相同模式（读写或只读）作为参考容器挂载。

像`SELinux`这样的标签系统要求在挂载到容器中的卷内容上放置正确的标签。如果没有标签，安全系统可能会阻止容器内运行的进程使用内容。默认情况下，Docker不会更改OS设置的标签。

要更改容器上下文中的标签，可以添加两个后缀中的任意一个`:z`或添加 `:Z`到卷装载。这些后缀告诉Docker重新标记共享卷上的文件对象。`z`选项告诉Docker两个容器共享卷内容。因此，Docker使用共享内容标签来标记内容。共享卷标允许所有容器读取/写入内容。`Z`选项告诉Docker使用私有非共享标签标记内容。只有当前容器可以使用私人卷。

#### 附加到`STDIN / STDOUT / STDERR` `-a`

---

`-a`标志告诉`docker run`绑定到容器的`STDIN`，`STDOUT` 或`STDERR`。这可以根据需要操作输出和输入。

```sh
$ echo "test" | docker run -i -a stdin busybox cat -
```

这将数据管理到容器中，并通过仅附加到容器上来打印容器的ID `STDIN`。

```sh
$ docker run -a stderr busybox echo test
```

这不会打印任何东西，除非出现错误，因为我们只附加到容器的`STDERR`。容器的日志仍然存储了写入`STDERR`和`STDOUT`的内容。

```sh
$ cat somefile | docker run -i -a stdin busybox dobuild
```

这是如何将文件传输到容器中以便构建的。构建完成后将打印容器的ID，并可使用检索构建日志`docker logs`。如果需要将文件或其他内容传输到容器中，并在容器运行完毕后检索容器的ID，这非常有用。

#### 将主机设备添加到容器 ` - 设备`

---

```sh
$ docker run --device=/dev/sdc:/dev/xvdc \
             --device=/dev/sdd --device=/dev/zero:/dev/nulo \
             -i -t \
             ubuntu ls -l /dev/{xvdc,sdd,nulo}

brw-rw---- 1 root disk 8, 2 Feb  9 16:05 /dev/xvdc
brw-rw---- 1 root disk 8, 3 Feb  9 16:05 /dev/sdd
crw-rw-rw- 1 root root 1, 5 Feb  9 16:05 /dev/nulo
```

通常需要将设备直接暴露于容器，启用`--device` 选项。例如，一个特定的块存储设备或循环设备或音频设备可以添加到另一个没有特权的容器（没有`--privileged`标志），并让应用程序直接访问它。

默认情况下，容器就可以`read`，`write`和`mknod`这些设备。这可以使用`--device` 标志的第三组选项`:rwm`来覆盖：

```sh
$ docker run --device=/dev/sda:/dev/xvdc --rm -it ubuntu fdisk  /dev/xvdc

Command (m for help): q
$ docker run --device=/dev/sda:/dev/xvdc:r --rm -it ubuntu fdisk  /dev/xvdc
You will not be able to write the partition table.

Command (m for help): q

$ docker run --device=/dev/sda:/dev/xvdc:rw --rm -it ubuntu fdisk  /dev/xvdc

Command (m for help): q

$ docker run --device=/dev/sda:/dev/xvdc:m --rm -it ubuntu fdisk  /dev/xvdc
fdisk: unable to open /dev/xvdc: Operation not permitted
```

> **注意**：`--device`不能安全地用于临时设备。使用`--device`不能将不可用的块设备添加到不受信任的容器中。 

#### 重新启动策略 `--restart`

---

使用`Docker's`  `--restart`来指定容器的**重新启动策略**。重新启动策略控制Docker守护程序在退出后是否重新启动容器。Docker支持以下重启策略：

| 策略                       | 结果                                                         |
| -------------------------- | ------------------------------------------------------------ |
| `no`                       | 退出时**不自动重启**容器。这是**默认**设置。                 |
| `on-failure[:max-retries]` | 仅在容器以**非零退出状态**退出时才能重新启动。或者，限制Docker守护程序尝试**重新启动的次数**。 |
| `unless-stopped`           | 重新启动容器，除非它明确停止或者Docker本身停止或重新启动。   |
| `always`                   | 不管退出状态如何，**始终重新启动**容器。当你总是指定时，Docker守护进程将尝试无限期地重启容器。无论容器的当前状态如何，容器也将始终在守护进程启动时启动。 |

```sh
$ docker run --restart=always redis
```

这将运行`redis`**始终**重启策略的容器， 如果容器退出，Docker将重启它。

#### 将条目添加到容器host文件 `--add-host`

---

可以`/etc/hosts`使用一个或多个`--add-host`标志将其他主机添加到容器的文件中。此示例为名为 `docker`添加一个静态地址：

```sh
$ docker run --add-host=docker:10.180.0.1 --rm -it debian

root@f38c87f2a42d:/# ping docker
PING docker (10.180.0.1): 48 data bytes
56 bytes from 10.180.0.1: icmp_seq=0 ttl=254 time=7.600 ms
56 bytes from 10.180.0.1: icmp_seq=1 ttl=254 time=30.705 ms
^C--- docker ping statistics ---
2 packets transmitted, 2 packets received, 0% packet loss
round-trip min/avg/max/stddev = 7.600/19.152/30.705/11.553 ms
```

有时需要从容器内连接到Docker主机。要启用此功能，请使用`--add-host`标志将Docker主机的IP地址传递给容器。要查找主机的地址，请使用`ip addr show`命令。

传递的标志`ip addr show`取决于容器中是使用IPv4还是IPv6网络。使用以下标志为名为`eth0`的网络设备检索IPv4地址：

```sh
$ HOSTIP=`ip -4 addr show scope global dev eth0 | grep inet | awk '{print \$2}' | cut -d / -f 1`
$ docker run  --add-host=docker:${HOSTIP} --rm -it debian
```

对于IPv6，使用`-6`标志而不是`-4`标志。对于其他网络设备，请用正确的设备名称替换`eth0`（例如`docker0` 桥接设备）。

#### 在容器中设置ulimits `--ulimit`

由于在容器中设置`ulimit`需要在默认容器中设置不可用的额外特权，因此可以使用`--ulimit`标志来设置这些特权。 `--ulimit`用软和硬限制来指定 `<type>=<soft limit>[:<hard limit>]`，例如：

```sh
$ docker run --ulimit nofile=1024:1024 --rm debian sh -c "ulimit -n"
1024
```

> **注意**：如果你不提供一个`hard limit`，这个`soft limit`值将被用于这两个值。如果没有`ulimits`设置，它们将从`ulimits`守护进程的默认设置继承。 `as`选项现在被禁用。换句话说，不支持以下脚本：
>
> ```sh
> $ docker run -it --ulimit as=1024 fedora /bin/bash`
> ```

这些值`syscall`在设置时会发送到适当的位置。Docker不执行任何字节转换。设置这些值时请考虑这一点。

#### 对于`NPROC`使用

`nproc`使用Linux设计的`ulimit`标志时要小心设置，`nproc`以便为用户设置可用的最大进程数，而不是容器。例如，用`daemon`用户启动四个容器：

```sh
$ docker run -d -u daemon --ulimit nproc=3 busybox top

$ docker run -d -u daemon --ulimit nproc=3 busybox top

$ docker run -d -u daemon --ulimit nproc=3 busybox top

$ docker run -d -u daemon --ulimit nproc=3 busybox top
```

第四个容器失败并报告“[8]系统错误：资源暂时不可用”错误。这会失败，因为调用者设置`nproc=3`导致前三个容器使用为`daemon`用户设置的三个进程配额。

#### 停止带有信号的容器

---

`--stop-signal`标志设置将发送给容器的系统调用信号退出。这个信号可以是一个有效的无符号数字，与内核`syscall`表中的位置相匹配，例如`9`，或者`SIGNAME`格式的信号名称，例如`SIGKILL`。 

#### 可选的安全选项（--security-opt）

---

在Windows上，该标志可用于指定`credentialspec`选项。在`credentialspec`必须在格式`file://spec.txt`或`registry://keyname`。

#### 用超时停止容器（--stop-timeout）

---

`--stop-timeout`标志设置超时（以秒为单位）`--stop-signal`表示将发送给容器退出的预定义（请参阅）系统调用信号。超时后，容器将被`SIGKILL`杀死。

#### 指定容器的隔离技术

---

在Windows上运行Docker容器的情况下，此选项很有用。`--isolation <value>`选项设置容器的隔离技术。在Linux上，唯一支持的是使用Linux命名空间的选项`default`。这两个命令在Linux上是等效的：

```sh
$ docker run -d busybox top
$ docker run -d --isolation default busybox top
```

在Windows上，`--isolation`可以采用以下值之一：

| 值        | 描述                                                         |
| --------- | ------------------------------------------------------------ |
| `default` | 使用Docker守护进程`--exec-opt`或系统默认值指定的值（见下文）。 |
| `process` | 共享内核命名空间隔离（`Windows`客户端操作系统不支持）。      |
| `hyperv`  | 基于`Hyper-V`管理程序分区的隔离。                            |

Windows服务器操作系统上的默认隔离是`process`。Windows客户端操作系统上的默认（且仅支持）隔离是`hyperv`。尝试在客户端操作系统上启动容器`--isolation process`将失败。

在Windows服务器上，假设使用默认配置，这些命令是等同的并导致`process`隔离：

```sh
PS C:\> docker run -d microsoft/nanoserver powershell echo process
PS C:\> docker run -d --isolation default microsoft/nanoserver powershell echo process
PS C:\> docker run -d --isolation process microsoft/nanoserver powershell echo process
```

如果您`--exec-opt isolation=hyperv`在Docker上设置了该选项`daemon`，或者针对基于Windows客户端的守护进程运行了这些命令，则这些命令是等同的并会导致`hyperv`隔离：

```sh
PS C:\> docker run -d microsoft/nanoserver powershell echo hyperv
PS C:\> docker run -d --isolation default microsoft/nanoserver powershell echo hyperv
PS C:\> docker run -d --isolation hyperv microsoft/nanoserver powershell echo hyperv
```

#### 指定容器可用内存

---

`--memory`参数始终设置容器可用内存的上限。在Linux上，这是在`cgroup`上设置的，容器中的应用程序可以通过查询来查询它`/sys/fs/cgroup/memory/memory.limit_in_bytes`。

在Windows上，这将根据使用的隔离类型对容器产生不同的影响。

- 通过`process`隔离，Windows将报告主机系统的全部内存，而不是对容器内运行的应用程序的限制

  ```sh
    PS C:\> docker run -it -m 2GB --isolation=process microsoft/nanoserver powershell Get-ComputerInfo *memory*
  
    CsTotalPhysicalMemory      : 17064509440
    CsPhyicallyInstalledMemory : 16777216
    OsTotalVisibleMemorySize   : 16664560
    OsFreePhysicalMemory       : 14646720
    OsTotalVirtualMemorySize   : 19154928
    OsFreeVirtualMemory        : 17197440
    OsInUseVirtualMemory       : 1957488
    OsMaxProcessMemorySize     : 137438953344
  ```

- 在`hyperv`隔离的情况下，Windows将创建一个足够容纳内存限制的实用程序虚拟机，以及承载容器所需的最小操作系统。该大小被报告为“总物理内存”。

  ```sh
    PS C:\> docker run -it -m 2GB --isolation=hyperv microsoft/nanoserver powershell Get-ComputerInfo *memory*
  
    CsTotalPhysicalMemory      : 2683355136
    CsPhyicallyInstalledMemory :
    OsTotalVisibleMemorySize   : 2620464
    OsFreePhysicalMemory       : 2306552
    OsTotalVirtualMemorySize   : 2620464
    OsFreeVirtualMemory        : 2356692
    OsInUseVirtualMemory       : 263772
    OsMaxProcessMemorySize     : 137438953344
  ```

#### 在运行时配置名称空间内核参数

---

`--sysctl`容器中的命名空间的内核参数（`sysctl`）集。例如，要打开容器网络名称空间中的IP转发，请运行以下命令：

```sh
$ docker run --sysctl net.ipv4.ip_forward=1 someimage
```

> **注意**：并非所有`sysctl`都是命名空间。Docker不支持更改也修改主机系统的容器内部的`sysctls`。随着内核的发展，我们期望看到更多的`sysctl`变成命名空间。

#### 目前支持的SYSCTLS

- `IPC Namespace`：

  ```sh
  kernel.msgmax, kernel.msgmnb, kernel.msgmni, kernel.sem, kernel.shmall, kernel.shmmax, kernel.shmmni, kernel.shm_rmid_forced
  Sysctls beginning with fs.mqueue.*
  ```

  如果你使用这个`--ipc=host`选项，这些`sysctl`将不被允许。

- `Network Namespace`：

  以`net`开头的`Sysctl`。如果`--network=host`使用这些选项，则不允许使用这些`sysctl`。
  
## tag 镜像标签

镜像名称由**斜杠分隔**的名称组件组成，可选地以**注册表主机名**作为前缀。主机名必须符合标准DNS规则，但不能包含下划线。如果存在主机名，则可以选择使用格式中的端口号`:8080`。如果不存在，命令`registry-1.docker.io`默认使用Docker的**公共注册表**。名称组件可能包含**小写字母，数字和分隔符**。分隔符定义为句点，一个或两个下划线或一个或多个破折号。名称组件不能以分隔符开始或结束。

标签名称必须是有效的ASCII码，可能包含小写和大写字母，数字，下划线，句点和破折号。标签名称不能以句号或短划线开头，最多可包含128个字符。

可以使用名称和标签将镜像分组在一起，然后将其上传到[*通过仓库共享镜像*](https://docs.docker.com/engine/tutorials/dockerrepos/#/contributing-to-docker-hub)。

### 标记由ID引用的镜像
---
使用ID`0e5574283393`将本地镜像标记到`版本1.0`的`fedora`仓库中：

```sh
$ docker tag 0e5574283393 fedora/httpd:version1.0
```

### 标记名称引用的镜像
---
要将名为`httpd`的本地镜像标记为`版本1.0`的`fedora`仓库：

```sh
$ docker tag httpd fedora/httpd:version1.0
```

请注意，未指定标记名称，因此会为现有本地版本创建别名`httpd:latest`。

### 标记名称和标签引用的镜像
---
使用名称`httpd`标记本地镜像并用`version1.0.test`将标签`test`标记到`fedora`仓库中：

```sh
$ docker tag httpd:test fedora/httpd:version1.0.test
```

### 为私人仓库标记镜像
---
要将镜像推送到私有注册表而不是中央Docker注册表，你必须使用注册表主机名和端口（如果需要）对其进行标记。

```sh
$ docker tag 0e5574283393 myregistryhost:5000/fedora/httpd:version1.0
```
## images 镜像列表

默认值`docker images`将显示所有顶级镜像、仓库和标签以及它们的大小。

Docker镜像具**有中间层**，`docker build`通过允许**缓存**每个步骤来**提高可重用性**，**减少磁盘**使用并**加快速度**。这些中间层默认**不显示**。<br/>`SIZE`是**镜像及其所有父镜像**占用的**累积**空间。也是`docker save`在镜像中创建的**tar文件内容所使用的磁盘空间**。<br/>如果镜像具有多个仓库名称或标签，则镜像将被多次列出。单个镜像（通过匹配识别`IMAGE ID`）`SIZE`只用了一次。

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                             |
| --------------- | ---- | -------------------------------- |
| `--all , -a`    |      | 显示所有镜像（默认隐藏中间镜像） |
| `--digests`     |      | 显示摘要                         |
| `--filter , -f` |      | 根据提供的条件过滤输出           |
| `--format`      |      | 使用Go模板打印出漂亮的镜像       |
| `--no-trunc`    |      | 不要截断输出                     |
| `--quiet , -q`  |      | 只显示数字ID                     |

### 示例

---

#### 列出镜像
---
##### 列出最近创建的镜像
---
```sh
$ docker images
```

##### 按名称和标签列出镜像
---
`docker images`命令采用可选`[REPOSITORY[:TAG]]`参数，将列表限制为与参数匹配的镜像。如果指定 `REPOSITORY`但不是`TAG`，则`docker images`命令会列出给定仓库中的所有镜像。

例如，要列出`python`仓库中的所有镜像，请运行以下命令：

```sh
$ docker images python
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
python              2.7-slim            b16fde09c92c        7 weeks ago         139MB
python              3.4-alpine          6610ae9fa51a        7 weeks ago         83.6MB
```

`[REPOSITORY[:TAG]]`值必须是**完全匹配**。这意味着，例如， `docker images jav`与镜像不匹配`java`。

如果`REPOSITORY`和`TAG`两个都提供，仅匹配库和标签镜像中列出。要在标签为`8`的`java`仓库中查找所有本地镜像，可以使用：

```sh
$ docker images java:8
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
java                8                   308e519aac60        6 days ago          824.5 MB
```

如果没有匹配`REPOSITORY[:TAG]`，则列表为空。

```sh
$ docker images java:0
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
```

##### 列出镜像全长ID
---
```
$ docker images --no-trunc
REPOSITORY                    TAG                 IMAGE ID                                                                  CREATED             SIZE
<none>                        <none>              sha256:77af4d6b9913e693e8d0b4b294fa62ade6054e6b2f1ffb617ac955dd63fb0182   19 hours ago        1.089 GB
committest                    latest              sha256:b6fa739cedf5ea12a620a439402b6004d057da800f91c7524b5086a5e4749c9f   19 hours ago        1.089 GB
```

##### 列出镜像摘要
---
使用`v2`或更高版本格式的镜像具有称为**摘要的内容可寻址标识符**。只要用于生成镜像的输入不变，摘要值就可以预测。要列出镜像摘要值，请使用`--digests`选项：

```sh
$ docker images --digests
REPOSITORY                         TAG                 DIGEST                                                                    IMAGE ID            CREATED             SIZE
localhost:5000/test/busybox        <none>              sha256:cbbf2f9a99b47fc460d422812b6a5adff7dfee951d8fa2e4a98caa0382cfbdbf   4986bf8c1536        9 weeks ago         2.43 MB
```

`推或拉`到`2.0`注册表时，`push`或`pull`命令输出包含镜像摘要。你可以使用摘要值进行`pull`。还可以通过`create`，`run`和`rmi`命令中的摘要，以及`Dockerfile`中的`FROM`镜像引用。

#### 过滤
---
过滤选项（`-f`或`--filter`）格式为`key = value`。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- dangling（布尔 - 真或假）
- label（`label=<key>`或`label=<key>=<value>`）
- before  （<image-name>[:<tag>]， <image id>或<image@digest>） -过滤在给定的id或引用之**前**创建的镜像
- since  （<image-name>[:<tag>]， <image id>或<image@digest>） -过滤从给定id或引用**后**创建的镜像
- reference （镜像参考的图案） - 过滤引用与指定模式匹配的镜像

##### 显示未加标签的镜像
---
```sh
$ docker images --filter "dangling=true"

REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
<none>              <none>              8abc22fbb042        4 weeks ago         0 B
<none>              <none>              48e5f45168b9        4 weeks ago         2.489 MB
<none>              <none>              bf747efa0e2f        4 weeks ago         0 B
<none>              <none>              980fe10e5736        12 weeks ago        101.4 MB
<none>              <none>              dea752e4e117        12 weeks ago        101.4 MB
<none>              <none>              511136ea3c5a        8 months ago        0 B
```

这将显示**未打标签**的镜像，即镜像树的叶子（不是中间层）。这些镜像在镜像的新版本 `repo:tag`将镜像标识从镜像标识中移开时保留为`<none>:<none>`或不标记。如果在容器正在使用时尝试删除镜像，则会发出警告。通过拥有这个选项，它可以批量清理。

你可以结合使用`docker rmi ...`做清理操作：

```sh
$ docker rmi $(docker images -f "dangling=true" -q)

8abc22fbb042
48e5f45168b9
bf747efa0e2f
980fe10e5736
dea752e4e117
511136ea3c5a
```

> **注意**：如果存在任何使用这些未标记镜像的容器，Docker会警告你。

##### 显示给定的标签镜像
---
过滤器匹配`label`基础上的存在的镜像单独`label`或`label`和值。

以下过滤器将镜像与`com.example.version`标签进行匹配，而不管其值如何。

```sh
$ docker images --filter "label=com.example.version"
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
match-me-1          latest              eeae25ada2aa        About a minute ago   188.3 MB
match-me-2          latest              dea752e4e117        About a minute ago   188.3 MB
```

以下过滤器将带有`com.example.version`标签的镜像与`1.0`值匹配。

```sh
$ docker images --filter "label=com.example.version=1.0"
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
match-me            latest              511136ea3c5a        About a minute ago   188.3 MB
```

在此示例中，使用该`0.1`值，它会返回空集，因为找不到匹配项。

```sh
$ docker images --filter "label=com.example.version=0.1"
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
```

##### 按时间过滤镜像
---
`before`过滤器仅显示在具有给定ID或引用的镜像**之前创建**的镜像。例如，拥有这些镜像：

```sh
$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
image1              latest              eeae25ada2aa        4 minutes ago        188.3 MB
image2              latest              dea752e4e117        9 minutes ago        188.3 MB
image3              latest              511136ea3c5a        25 minutes ago       188.3 MB
```

过滤`image1`之前创建的镜像：

```sh
$ docker images --filter "before=image1"
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
image2              latest              dea752e4e117        9 minutes ago        188.3 MB
image3              latest              511136ea3c5a        25 minutes ago       188.3 MB
```

过滤`image3`之后创建的镜像：

```sh
$ docker images --filter "since=image3"
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
image1              latest              eeae25ada2aa        4 minutes ago        188.3 MB
image2              latest              dea752e4e117        9 minutes ago        188.3 MB
```

##### 通过引用过滤镜像
---
`reference`过滤器仅显示引用与指定模式匹配的镜像。

```sh
$ docker images

REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
busybox             latest              e02e811dd08f        5 weeks ago         1.09 MB
busybox             uclibc              e02e811dd08f        5 weeks ago         1.09 MB
busybox             musl                733eb3059dce        5 weeks ago         1.21 MB
busybox             glibc               21c16b6787c6        5 weeks ago         4.19 MB
```

过滤`reference`将给：

```sh
$ docker images --filter=reference='busy*:*libc'

REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
busybox             uclibc              e02e811dd08f        5 weeks ago         1.09 MB
busybox             glibc               21c16b6787c6        5 weeks ago         4.19 MB
```

#### 格式化输出
---
格式化选项（`--format`）将使用Go模板打印容器输出。

下面列出了Go模板的有效占位符：

| 占位符          | 描述                 |
| --------------- | -------------------- |
| `.ID`           | 镜像ID               |
| `.Repository`   | 镜像仓库           |
| `.Tag`          | 镜像标签             |
| `.Digest`       | 镜像摘要             |
| `.CreatedSince` | 自创建镜像以来的耗时 |
| `.CreatedAt`    | 镜像创建的时间       |
| `.Size`         | 镜像磁盘大小         |

当使用该`--format`选项时，该`image`命令将完全按照模板声明输出数据，或者在使用该 `table`指令时也会包含列标题。

以下示例使用不带标题的模板，并输出 由冒号分隔的所有镜像`ID`和`Repository`条目：

```sh
$ docker images --format "{{.ID}}: {{.Repository}}"

77af4d6b9913: <none>
b6fa739cedf5: committ
78a85c484f71: <none>
30557a29d5ab: docker
5ed6274db6ce: <none>
746b819f315e: postgres
746b819f315e: postgres
746b819f315e: postgres
746b819f315e: postgres
```

要以表格格式列出仓库和标签的所有镜像，可以使用：

```sh
$ docker images --format "table {{.ID}}\t{{.Repository}}\t{{.Tag}}"

IMAGE ID            REPOSITORY                TAG
77af4d6b9913        <none>                    <none>
b6fa739cedf5        committ                   latest
78a85c484f71        <none>                    <none>
30557a29d5ab        docker                    latest
5ed6274db6ce        <none>                    <none>
746b819f315e        postgres                  9
746b819f315e        postgres                  9.3
746b819f315e        postgres                  9.3.5
746b819f315e        postgres                  latest
```

## history 镜像历史

显示镜像的历史记录

### 命令参数选项

---

| 选项，简写     | 默认   | 描述                       |
| -------------- | ------ | -------------------------- |
| `--format`     |        | 使用Go模板打印出漂亮的镜像 |
| `--human , -H` | `true` | 以可读格式打印大小和日期   |
| `--no-trunc`   |        | 不要截断输出               |
| `--quiet , -q` |        | 只显示数字ID               |



### 示例

---

要了解`docker:latest`镜像是如何构建的：

```sh
$ docker history docker

IMAGE               CREATED             CREATED BY                                      SIZE                COMMENT
3e23a5875458        8 days ago          /bin/sh -c #(nop) ENV LC_ALL=C.UTF-8            0 B
8578938dd170        8 days ago          /bin/sh -c dpkg-reconfigure locales &&    loc   1.245 MB
be51b77efb42        8 days ago          /bin/sh -c apt-get update && apt-get install    338.3 MB
4b137612be55        6 weeks ago         /bin/sh -c #(nop) ADD jessie.tar.xz in /        121 MB
750d58736b4b        6 weeks ago         /bin/sh -c #(nop) MAINTAINER Tianon Gravi <ad   0 B
511136ea3c5a        9 months ago                                                        0 B                 Imported from -
```

要查看`docker:apache`镜像如何添加到容器的基本镜像：

```sh
$ docker history docker:scm
IMAGE               CREATED             CREATED BY                                      SIZE                COMMENT
2ac9d1098bf1        3 months ago        /bin/bash                                       241.4 MB            Added Apache to Fedora base image
88b42ffd1f7c        5 months ago        /bin/sh -c #(nop) ADD file:1fd8d7f9f6557cafc7   373.7 MB
c69cab00d6ef        5 months ago        /bin/sh -c #(nop) MAINTAINER Lokesh Mandvekar   0 B
511136ea3c5a        19 months ago                                                       0 B                 Imported from -
```

#### 格式化输出
---
格式化选项（`--format`）将使用Go模板来显示历史输出。

下面列出了Go模板的有效占位符：

| 占位符          | 描述                                                         |
| --------------- | ------------------------------------------------------------ |
| `.ID`           | 镜像ID                                                       |
| `.CreatedSince` | 自创建镜像以来耗费的时间`--human=true`，否则创建镜像时的时间戳 |
| `.CreatedAt`    | 何时创建镜像的时间戳                                         |
| `.CreatedBy`    | 用于创建镜像的命令                                           |
| `.Size`         | 镜像磁盘大小                                                 |
| `.Comment`      | 评论形象                                                     |

当使用`--format`选项时，`history`命令将完全按照模板声明输出数据，或者在使用该 `table`指令时也会包含列标题。以下示例使用不带标题的模板，并输出 由冒号分隔的所有镜像`ID`和`CreatedSince`条目：

```sh
$ docker images --format "{{.ID}}: {{.Created}} ago"

cc1b61406712: 2 weeks ago
<missing>: 2 weeks ago
<missing>: 2 weeks ago
<missing>: 2 weeks ago
<missing>: 2 weeks ago
<missing>: 3 weeks ago
<missing>: 3 weeks ago
<missing>: 3 weeks ago
```












## pull 拉取镜像

大部分镜像将在[Docker Hub](https://hub.docker.com/)注册表的基础镜像上创建 。[Docker Hub](https://hub.docker.com/)包含许多预构建的镜像，可以`pull`尝试而无需定义和配置自己的镜像。要下载特定镜像或一组镜像（即仓库），请使用`docker pull`。

### 命令参数选项

---

| 选项，简写                | 默认   | 描述                                                         |
| ------------------------- | ------ | ------------------------------------------------------------ |
| `--all-tags , -a`         |        | 下载仓库中的所有标记镜像                                   |
| `--disable-content-trust` | `true` | 跳过镜像验证                                                 |
| `--platform`              |        | [实验（守护程序）](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file)[API 1.32+](https://docs.docker.com/engine/api/v1.32/) 如果服务器具有多平台功能，请设置平台 |



### 代理配置

---

如果你是后面的HTTP代理服务器，例如在公司的设置，前打开一个连接到注册表，可能需要配置docker守护进程的代理设置，使用`HTTP_PROXY`，`HTTPS_PROXY`和`NO_PROXY` 环境变量。要在`systemd`使用的主机上设置这些环境变量 ，请参阅[控制并使用systemd配置Docker以](https://docs.docker.com/engine/admin/systemd/#http-proxy) 获取变量配置。

### 并发下载

---

默认情况下，Docker守护进程将一次拉出三层镜像。如果你使用的是低带宽连接，则可能会导致超时问题，你可能需要通过`--max-concurrent-downloads`守护进程选项降低此问题。

### 示例

---

#### 从`Docker Hub`中提取镜像

要下载特定镜像或一组镜像，请使用 `docker pull`。如果未提供标签，则Docker Engine将`:latest`标签用作默认标签。该命令会拉出`debian:latest`镜像：

```sh
$ docker pull debian

Using default tag: latest
latest: Pulling from library/debian
fdd5d7827f33: Pull complete
a3ed95caeb02: Pull complete
Digest: sha256:e7d38b3517548a1c71e41bffe9c8ae6d6d29546ce46bf62159837aad072c90aa
Status: Downloaded newer image for debian:latest
```

Docker镜像可以由**多个图层**组成。在上面的例子中，镜像由两层组成，`fdd5d7827f33`和`a3ed95caeb02`。

图层可以**重复使用图层**。例如，`debian:jessie`镜像与两个图层共享`debian:latest`。`debian:jessie`因此，拉取镜像只会拉取元数据，而不是其图层，因为所有图层都已经存在于本地：

```sh
$ docker pull debian:jessie

jessie: Pulling from library/debian
fdd5d7827f33: Already exists
a3ed95caeb02: Already exists
Digest: sha256:a9c958be96d7d40df920e7041608f2f017af81800ca5ad23e327bc402626b58e
Status: Downloaded newer image for debian:jessie
```

要查看本地存在哪些镜像，请使用以下[`docker images`](https://docs.docker.com/engine/reference/commandline/images/) 命令：

```sh
$ docker images

REPOSITORY   TAG      IMAGE ID        CREATED      SIZE
debian       jessie   f50f9524513f    5 days ago   125.1 MB
debian       latest   f50f9524513f    5 days ago   125.1 MB
```

Docker使用内容可寻址的镜像存储，镜像ID是一个涵盖镜像配置和图层的SHA256摘要。在上面的例子中，`debian:jessie`并且`debian:latest`具有相同的镜像ID，因为它们实际上是用不同名称标记的**相同**镜像。因为它们是相同的镜像，所以它们的图层**只存储一次**，不会占用额外的磁盘空间。

有关镜像，图层和内容寻址存储的更多信息，请参阅[了解镜像，容器和存储驱动程序](https://docs.docker.com/engine/userguide/storagedriver/imagesandcontainers/)。

#### 通过`digest`（不可变标识符）提取镜像
---
到目前为止，已经通过名称（和“标签”）来拉取镜像。使用名称和标签是处理镜像的便捷方式。使用标签时，可以`docker pull`再次使用镜像，以确保拥有该镜像的最新版本。例如，`docker pull ubuntu:14.04`拉取最新版本的Ubuntu 14.04镜像。

在某些情况下，你不希望将镜像更新为新版本，但更喜欢使用**固定版本**的镜像。Docker使你能够通过**摘要**来提取镜像 。当通过摘要拉取的镜像，你指定**确切**的镜像的版本。这样做，可让将镜像“钉”到该版本，并确保你使用的镜像**始终保持不变**。

要知道镜像的摘要，请先拉取镜像。让我们从Docker Hub中提取最新的`ubuntu:14.04` 镜像：

```sh
$ docker pull ubuntu:14.04

14.04: Pulling from library/ubuntu
5a132a7e7af1: Pull complete
fd2731e4c50c: Pull complete
28a2f68d1120: Pull complete
a3ed95caeb02: Pull complete
Digest: sha256:45b23dee08af5e43a7fea6c4cf9c25ccf269ee113168c19722f87876677c5cb2
Status: Downloaded newer image for ubuntu:14.04
```

在pull完成后，Docker会打印镜像的摘要。在上面的例子中，镜像的摘要是：

```sh
sha256:45b23dee08af5e43a7fea6c4cf9c25ccf269ee113168c19722f87876677c5cb2
```

在**推**送到注册表时，Docker还会打印镜像的摘要。如果想固定刚刚推送的镜像版本，这可能会很有用。

当摘取镜像时摘要代替标签，例如，通过摘要拉出上面的镜像，运行以下命令：

```sh
$ docker pull ubuntu@sha256:45b23dee08af5e43a7fea6c4cf9c25ccf269ee113168c19722f87876677c5cb2

sha256:45b23dee08af5e43a7fea6c4cf9c25ccf269ee113168c19722f87876677c5cb2: Pulling from library/ubuntu
5a132a7e7af1: Already exists
fd2731e4c50c: Already exists
28a2f68d1120: Already exists
a3ed95caeb02: Already exists
Digest: sha256:45b23dee08af5e43a7fea6c4cf9c25ccf269ee113168c19722f87876677c5cb2
Status: Downloaded newer image for ubuntu@sha256:45b23dee08af5e43a7fea6c4cf9c25ccf269ee113168c19722f87876677c5cb2
```

摘要也可以在`FROM`Dockerfile中使用，例如：

```dockerfile
FROM ubuntu@sha256:45b23dee08af5e43a7fea6c4cf9c25ccf269ee113168c19722f87876677c5cb2
MAINTAINER some maintainer <maintainer@example.com>
```

> **注意**：使用此功能可以及时将镜像“钉”到**特定版本**。因此，Docker不会提取镜像的更新版本，其中可能包含安全更新。如果你想拉一个更新的镜像，你需要相应地更改摘要。

#### 从不同的注册表中提取
---
默认情况下，`docker pull`从[Docker Hub中](https://hub.docker.com/)提取镜像。也可以手动指定要从中注册的注册表路径。例如，如果已设置本地注册表，则可以指定路径以从中取消注册。注册表路径类似于URL，但不包含协议说明符（`https://`）。

以下命令从侦听端口5000（`myregistry.local:5000`）的本地注册表中获取`testing/test-image`镜像：

```sh
$ docker pull myregistry.local:5000/testing/test-image
```

注册表凭证由[docker登录](https://docs.docker.com/engine/reference/commandline/login/)管理。

Docker使用`https://`协议与注册表进行通信，除非允许通过不安全的连接访问注册表。有关更多信息，请参阅 [不安全的注册表](https://docs.docker.com/engine/reference/commandline/dockerd/#insecure-registries)部分。

#### 使用多个镜像拉取一个仓库
---
默认情况下，`docker pull`从注册表中提取一张镜像。仓库可以包含多个镜像。要从仓库中**提取所有镜像**，请在使用`docker pull`时提供`-a（或--all-tags）`选项。

命令从仓库中提取所有`fedora`镜像：

```sh
$ docker pull --all-tags fedora

Pulling repository fedora
ad57ef8d78d7: Download complete
105182bb5e8b: Download complete
511136ea3c5a: Download complete
73bd853d2ea5: Download complete
....

Status: Downloaded newer image for fedora
```

拉取完成后，使用`docker images`命令查看拉出的镜像。以下示例显示了`fedora`本地存在的所有镜像：

```sh
$ docker images fedora

REPOSITORY   TAG         IMAGE ID        CREATED      SIZE
fedora       rawhide     ad57ef8d78d7    5 days ago   359.3 MB
fedora       20          105182bb5e8b    5 days ago   372.7 MB
fedora       heisenbug   105182bb5e8b    5 days ago   372.7 MB
fedora       latest      105182bb5e8b    5 days ago   372.7 MB
```

#### 取消拉取
---
例如通过`docker pull`在终端中运行时按下`CTRL-c`来终止拉取进程操作。

```sh
$ docker pull fedora

Using default tag: latest
latest: Pulling from library/fedora
a3ed95caeb02: Pulling fs layer
236608c7b546: Pulling fs layer
^C
```

> **注意**：从技术上讲，当Docker引擎守护程序和启动拉的Docker引擎客户端之间的**连接丢失**时，引擎会**终止拉取**操作。如果与引擎守护进程的连接由于其他原因（而不是手动交互）而丢失，则拉也会中止。

## push 推送镜像

`docker push`用于将镜像分享到[Docker Hub](https://hub.docker.com/) 注册表或自行托管的镜像。例如通过`CTRL-c`在终端中运行时按下该进程来终止`docker push`推进操作。

在docker push期间显示进度条，显示未压缩的大小。推送的实际数据量在**发送之前会被压缩**，因此上传的大小不会被进度条反映出来。

### 并发上传

---

默认情况下，Docker守护进程将**一次推送五层**镜像。如果使用的是低带宽连接，则可能会导致超时问题，可能需要通过`--max-concurrent-uploads`守护进程选项降低此问题。

### 示例

---

首先通过查找容器ID（使用[`docker ps`](https://docs.docker.com/engine/reference/commandline/ps/)）保存新镜像，然后将其提交给新镜像名称。请注意，只有`a-z0-9-_.`才符合命名镜像规则：

```sh
$ docker commit c16378f943fe rhel-httpd
```

现在，使用镜像ID将镜像推送到注册表。在这个例子中，注册表位于名为`registry-host`和监听端口的主机上`5000`。为此，请使用主机名或IP地址以及注册表的端口标记镜像：

```sh
$ docker tag rhel-httpd registry-host:5000/myadmin/rhel-httpd
$ docker push registry-host:5000/myadmin/rhel-httpd
```

检查这是通过运行：

```sh
$ docker images
```

你应该看到`rhel-httpd`并列出`registry-host:5000/myadmin/rhel-httpd` 。







## rmi 删除镜像

删除一个或多个镜像

### 示例

---

可以使用其短或长ID、标记或摘要来移除镜像。如果镜像有一个或多个**引用**它的标签，则必须在删除镜像之前将其全部删除。摘要引用会在标签删除镜像时自动删除。

```sh
$ docker images
REPOSITORY                TAG                 IMAGE ID            CREATED             SIZE
test1                     latest              fd484f19954f        23 seconds ago      7 B (virtual 4.964 MB)
test                      latest              fd484f19954f        23 seconds ago      7 B (virtual 4.964 MB)
test2                     latest              fd484f19954f        23 seconds ago      7 B (virtual 4.964 MB)

$ docker rmi fd484f19954f
Error: Conflict, cannot delete image fd484f19954f because it is tagged in multiple repositories, use -f to force
2013/12/11 05:47:16 Error: failed to remove one or more images

$ docker rmi test1
Untagged: test1:latest

$ docker rmi test2
Untagged: test2:latest

$ docker images
REPOSITORY                TAG                 IMAGE ID            CREATED             SIZE
test                      latest              fd484f19954f        23 seconds ago      7 B (virtual 4.964 MB)

$ docker rmi test
Untagged: test:latest
Deleted: fd484f19954f4920da7ff372b5067f5b7ddb2fd3830cecd17b96ea9e286ba5b8
```

如果使用`-f`选项并指定镜像的短或长ID，那么此命令将除去并删除与指定ID匹配的所有镜像。

```sh
$ docker images

REPOSITORY                TAG                 IMAGE ID            CREATED             SIZE
test1                     latest              fd484f19954f        23 seconds ago      7 B (virtual 4.964 MB)
test                      latest              fd484f19954f        23 seconds ago      7 B (virtual 4.964 MB)
test2                     latest              fd484f19954f        23 seconds ago      7 B (virtual 4.964 MB)

$ docker rmi -f fd484f19954f

Untagged: test1:latest
Untagged: test:latest
Untagged: test2:latest
Deleted: fd484f19954f4920da7ff372b5067f5b7ddb2fd3830cecd17b96ea9e286ba5b8
```

由摘要拉取的镜像没有与其关联的标签：

```sh
$ docker images --digests

REPOSITORY                     TAG       DIGEST                                                                    IMAGE ID        CREATED         SIZE
localhost:5000/test/busybox    <none>    sha256:cbbf2f9a99b47fc460d422812b6a5adff7dfee951d8fa2e4a98caa0382cfbdbf   4986bf8c1536    9 weeks ago     2.43 MB
```

使用摘要删除镜像：

```sh
$ docker rmi localhost:5000/test/busybox@sha256:cbbf2f9a99b47fc460d422812b6a5adff7dfee951d8fa2e4a98caa0382cfbdbf
Untagged: localhost:5000/test/busybox@sha256:cbbf2f9a99b47fc460d422812b6a5adff7dfee951d8fa2e4a98caa0382cfbdbf
Deleted: 4986bf8c15363d1c5d15512d5266f8777bfba4974ac56e3270e7760f6f0a8125
Deleted: ea13149945cb6b1e746bf28032f02e9b5a793523481a0a18645fc77ad53c4ea2
Deleted: df7546f9f060a2268024c8a230d8639878585defcc1bc6f79d2728a13957871b
```

## save 备份镜像

将一个或多个镜像保存到tar归档文件（默认流式传输到`STDOUT`）。为标准输出流生成仓库。包含所有`父层`、所有`标签+版本`或指定`repo:tag`的每个参数。

### 示例

---

#### 创建备份

```sh
# 保存备份
$ docker save busybox > busybox.tar

$ ls -sh busybox.tar
2.7M busybox.tar

# 设置保存输出 ·写入文件·
$ docker save --output busybox.tar busybox

$ ls -sh busybox.tar
2.7M busybox.tar

# 保存镜像版本
$ docker save -o fedora-all.tar fedora
$ docker save -o fedora-latest.tar fedora:latest
```

#### 选择特定的标签
---
甚至可以挑选镜像仓库的特定标签，将多个标签镜像一起保存备份。

```sh
$ docker save -o ubuntu.tar ubuntu:lucid ubuntu:saucy
$ docker save -o h.tar test/hello:v1 alpine:latest
```

## load 装载镜像

从文件或`STDIN`中加载`tar`档案中的镜像或仓库（即使用`gzip，bzip2或xz`进行压缩）。它恢复镜像和标签。

| 选项，简写     | 默认 | 描述                           |
| -------------- | ---- | ------------------------------ |
| `--input , -i` |      | 从tar档案文件读取，而不是STDIN |
| `--quiet , -q` |      | 抑制负载输出                   |



示例演示

```sh
$ docker docker image ls
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE

$ docker load < busybox.tar.gz
Loaded image: busybox:latest

$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
busybox             latest              769b9341d937        7 weeks ago         2.489 MB

$ docker load --input fedora.tar
Loaded image: fedora:rawhide
Loaded image: fedora:20

$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
busybox             latest              769b9341d937        7 weeks ago         2.489 MB
fedora              rawhide             0d20aec6529d        7 weeks ago         387 MB
fedora              20                  58394af37342        7 weeks ago         385.5 MB
fedora              heisenbug           58394af37342        7 weeks ago         385.5 MB
fedora              latest              58394af37342        7 weeks ago         385.5 MB
```
## search 搜索镜像

在Docker Hub中搜索镜像，搜索查询最多返回25个结果。 

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                                                         |
| :-------------- | ---- | ------------------------------------------------------------ |
| `--automated`   |      | [不推荐使用](https://docs.docker.com/engine/deprecated/) 仅显示自动构建 |
| `--filter , -f` |      | 根据提供的条件过滤输出                                       |
| `--format`      |      | 使用Go模板进行漂亮的打印搜索                                 |
| `--limit`       | `25` | 最大搜索结果数量                                             |
| `--no-trunc`    |      | 不要截断输出                                                 |
| `--stars , -s`  |      | [不建议使用](https://docs.docker.com/engine/deprecated/) 仅显示至少x个星号 |

  

### 示例

---

#### 按名称搜索镜像

此示例显示名称中包含`busybox`的镜像：

```sh
$ docker search busybox
```

#### 显示非截断描述`（--no-trunc）`
---
此示例显示名称中包含`busybox`的镜像，至少3星，并且说明在输出中不会被截断：

```sh
$ docker search --stars=3 --no-trunc busybox
NAME                 DESCRIPTION                                                                               STARS     OFFICIAL   AUTOMATED
busybox              Busybox base image.            
```

#### 限制搜索结果`（--limit）`
---
选项`--limit`是搜索结果返回的最大数量。该值可以在1到100之间的范围内。默认值为`--limit`25。

```sh
$ docker search helloworld --limit 5
```

#### 过滤
---
过滤选项（`-f`或`--filter`）格式是一`key=value`对。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- `stars`  （int - 镜像中星星的数量）
- `is-automated` （boolean - 真或假） - 镜像是否自动化
- `is-official`（boolean - true或false） - 镜像是否为官方

```sh
# 名称中包含'busybox'且至少3星的镜像
$ docker search --filter stars=3 busybox
# 名称中包含“busybox”的镜像，并且是自动生成的
$ docker search --filter is-automated busybox
# 名称中包含'busybox'，至少3星，并且是官方版本
$ docker search --filter "is-official=true" --filter "stars=3" busybox
```

#### 格式化输出
---
格式化选项（`--format`）使用Go模板漂亮地打印搜索输出。Go模板的有效占位符是：

| 占位符         | 描述                         |
| -------------- | ---------------------------- |
| `.Name`        | 镜像名称                     |
| `.Description` | 镜像描述                     |
| `.StarCount`   | 镜像的星星数量               |
| `.IsOfficial`  | 如果镜像是官方的，“确定”     |
| `.IsAutomated` | 如果镜像构建是自动的，“确定” |

当使用`--format`选项时，`search`命令将完全按照模板声明输出数据。如果使用 `table`指令，则也包含列标题。

以下示例使用不带标题的模板，并输出 由冒号分隔的所有镜像`Name`和`StarCount`条目：

```sh
$ docker search --format "{{.Name}}: {{.StarCount}}" nginx
nginx: 5441
jwilder/nginx-proxy: 953
richarvey/nginx-php-fpm: 353
```

这个例子输出一个表格格式：

```sh
$ docker search --format "table {{.Name}}\t{{.IsAutomated}}\t{{.IsOfficial}}" nginx
NAME                                     AUTOMATED           OFFICIAL
nginx                                                        [OK]
jwilder/nginx-proxy                      [OK] 
```







## login 登陆

登录到Docker注册表

### 命令参数选项

---

| 选项，简写         | 默认 | 描述                 |
| ------------------ | ---- | -------------------- |
| `--password , -p`  |      | 密码                 |
| `--password-stdin` |      | 从标准输入中获取密码 |
| `--username , -u`  |      | 用户名               |



### 示例

---

#### 登录到自我托管的注册表

如果想登录自托管注册表，可以通过添加服务器名称来指定。

```sh
$ docker login localhost:8080
$ winpty docker login --username xxx registry.cn-hangzhou.aliyuncs.com
```

#### 使用STDIN提供密码
---
要以`docker login`非交互方式运行该命令，可以设置 `--password-stdin`选项以提供密码`STDIN`。**使用 `STDIN`防止密码结束在shell的历史记录或日志**文件中。

以下示例从文件读取密码，并`docker login`使用`STDIN`以下命令将其传递给该 命令：

```sh
$ cat ~/my_password.txt | docker login --username foo --password-stdin
```

#### 特权用户需求
---
`docker login`要求用户使用`sudo`或者是`root`，除非：

1. 连接到**远程守护进程**，如`docker-machine`配置`docker engine`。
2. 用户被添加到`docker`组中。这会影响你系统的安全性。`docker`组是`root`等同的。有关详细信息，请参阅[Docker守护进程攻击面](https://docs.docker.com/engine/security/security/#docker-daemon-attack-surface)。

你可以登录到拥有凭据的任何公共或私人仓库。登录时，命令通过以下步骤`$HOME/.docker/config.json`在Linux或`%USERPROFILE%/.docker/config.json`Windows 上存储凭据 。

#### 凭证商店
---
Docker引擎可以将用户凭证**保存在外部凭证库**中，例如操作系统的本地钥匙串。使用**外部存储**比在Docker配置文件中存储凭据**更安全**。

要使用凭证存储，需要一个外部帮助程序来与特定的钥匙串或外部存储进行交互。Docker需要帮助程序在客户端的`$PATH`主机中。

这是当前可用凭据助手的列表，可以从以下位置下载它们：

- D-Bus秘密服务：https：//github.com/docker/docker-credential-helpers/releases
- Apple MacOS钥匙串：https：//github.com/docker/docker-credential-helpers/releases
- Microsoft Windows Credential Manager：https：//github.com/docker/docker-credential-helpers/releases
- [pass](https://www.passwordstore.org/)：https：//github.com/docker/docker-credential-helpers/releases

需要在`$HOME/.docker/config.json` 中指定**凭证存储**以告诉docker引擎使用它。config属性的值应该是要使用的程序的后缀（即`docker-credential`之后的所有内容）。例如，要使用`docker-credential-osxkeychain`：

```json
{
	"credsStore": "osxkeychain"
}
```

如果当前已登录，请运行`docker logout`以从文件中删除凭据并`docker login`再次运行。

#### 默认行为
---
默认情况下，Docker会在每个平台上查找本地二进制文件，例如macOS上的`osxkeychain`，Windows上的`wincred`以及Linux上的`pass`。一个特殊情况是在Linux上，如果找不到`pass`二进制文件，Docker会回退到`secretservice`二进制文件。如果这些二进制文件**都不存在**，它将在上述配置文件中**以`base64`编码存储凭证**（即密码）。

#### 凭证帮助程序协议
---
凭证助手可以是遵循一个**非常简单的协议的任何程序或脚本**。这个协议很受Git的启发，但它在共享的信息上有所不同。助手总是使用命令中的第一个参数来标识该操作。这个参数只有三种可能的值：`store`，`get`，和`erase`。

`store`命令从标准输入中获取JSON负载。该有效载荷携带服务器地址，识别凭证，用户名以及密码或身份令牌。

```json
{
	"ServerURL": "https://index.docker.io/v1",
	"Username": "david",
	"Secret": "passw0rd1"
}
```

如果存储的秘密是身份标记，则应将用户名设置为 `<token>`。<br/>`store`命令可以向`STDOUT`写入错误消息，如果存在问题，Docker引擎将显示该消息。

`get`命令从**标准输入**中获取字符串负载。该有效负载携带docker引擎需要凭据的服务器地址。这是有效负载的一个例子：`https://index.docker.io/v1`。

`get`命令将`JSON`有效内容写入`STDOUT`。Docker从这个有效载荷中读取用户名和密码：

```json
{
	"Username": "david",
	"Secret": "passw0rd1"
}
```

`erase`命令从`STDIN`中获取字符串有效内容。该有效负载携带了docker引擎想要为其移除凭据的服务器地址。这是有效载荷的一个例子：`https://index.docker.io/v1`。

`erase`命令可以写入`STDOUT`错误消息，以便在出现问题时Docker引擎将显示该消息。

#### 凭证助手
---
凭证助手与上面的凭证存储类似，但充当指定程序来处理**特定注册管理机构的**凭证。默认凭证库（`credsStore`或配置文件本身）不会用于有关指定注册表的凭证的操作。

#### 注销
---
如果你当前已登录，请运行`docker logout`以从默认存储中删除凭据。

凭证助手以类似`credsStore`的方式指定，但允许一次配置多个助手。键指定注册表域，值指定要使用的程序的后缀（即后面的所有内容`docker-credential-`）。例如：

```json
{
  "credHelpers": {
    "registry.example.com": "registryhelper",
    "awesomereg.example.org": "hip-star",
    "unicorn.example.io": "vcbait"
  }
}
```

## logout 注销

从Docker注册表中注销

```sh
$ docker logout localhost:8080
```
## info 系统信息

此命令显示有关Docker安装的**系统信息**。显示的信息包括内核版本、容器数量和镜像。显示的镜像数量是唯一镜像的数量，用不同名称标记的相同镜像只计算一次。

如果指定了格式，则将执行**给定模板**而不是默认格式。Go的[文本/模板](http://golang.org/pkg/text/template/)包描述了格式的所有细节。

根据使用的存储驱动程序，可以显示其他信息，例如池名称，数据文件，元数据文件，使用的数据空间，总数据空间，使用的元数据空间以及总元数据空间。<br/>数据文件是存储镜像的位置，元数据文件是存储关于这些镜像的元数据的位置。当第一次运行时，Docker会从`/var/lib/docker`挂载的卷上可用的空间中**分配一定数量的数据空间和元数据空间**。

### 示例

---

#### 显示输出

以下示例显示了使用`devicemapper`存储驱动程序在`Red Hat Enterprise Linux`上运行的守护程序的输出。从输出中可以看出，显示了有关`devicemapper`存储驱动程序的附加信息：

```sh
$ docker info
```

#### 显示调试输出
---
以下是在Ubuntu上运行的守护进程的示例输出，使用`overlay2`存储驱动程序和属于双节点群集的节点：

```sh
$ docker -D info
```

全局`-D`选项会导致所有`docker`命令输出调试信息。

#### 格式化输出
---
也可以指定输出格式：

```sh
$ docker info --format '{{json .}}'
{"ID":"I54V:OLXT:HVMM:TPKO:JPHQ:CQCD:JNLC:O3BZ:4ZVJ:43XJ:PFHZ:6N2S","Containers":14, ...} 
```

#### 关于内核支持的警告
---
如果你的操作系统未启用某些功能，则在运行`docker info`时可能会看到以下警告之一：

```sh
WARNING: Your kernel does not support swap limit capabilities. Limitation discarded.
WARNING: No swap limit support
```

你可以忽略这些警告，除非你确实需要[限制这些资源](https://docs.docker.com/engine/admin/resource_constraints/)的能力 ，在这种情况下，你应该查阅操作系统的文档以启用它们。 [了解更多](https://docs.docker.com/engine/installation/linux/linux-postinstall/#your-kernel-does-not-support-cgroup-swap-limit-capabilities)。

## inspect 查看详细

Docker检查提供了Docker控制的构造的详细信息。默认情况下，`docker inspect`会将结果呈现在JSON数组中。

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                             |
| --------------- | ---- | -------------------------------- |
| `--format , -f` |      | 使用给定的Go模板格式化输出       |
| `--size , -s`   |      | 如果类型是容器，则显示总文件大小 |
| `--type`        |      | 返回指定类型的JSON               |



### 示例

---

#### 获取实例的IP地址

大多数情况下，可以以相当直接的方式从JSON中挑选任何字段。

```sh
$ docker inspect --format='{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' $INSTANCE_ID
```

#### 获取实例的MAC地址
---
```sh
$ docker inspect --format='{{range .NetworkSettings.Networks}}{{.MacAddress}}{{end}}' $INSTANCE_ID
```

#### 获取实例的日志路径
---
```sh
$ docker inspect --format='{{.LogPath}}' $INSTANCE_ID
```

#### 获取实例的镜像名称
---
```sh
$ docker inspect --format='{{.Config.Image}}' $INSTANCE_ID
```

#### 列出所有端口绑定
---
你可以遍历结果中的数组和地图来生成简单的文本输出：

```sh
$ docker inspect --format='{{range $p, $conf := .NetworkSettings.Ports}} {{$p}} -> {{(index $conf 0).HostPort}} {{end}}' $INSTANCE_ID
```

#### 找到一个特定的端口映射
---
当字段名称以数字开头，但模板语言的`index`函数具有此功能时，`.Field`语法不起作用。该 `.NetworkSettings.Ports`部分包含内部端口映射到外部地址/端口对象列表的映射。要抓取数字公共端口，可以使用`index`来查找特定端口映射，然后在`index`其中包含第一个对象。然后我们要求`HostPort`现场获得公开地址。

```sh
$ docker inspect --format='{{(index (index .NetworkSettings.Ports "8787/tcp") 0).HostPort}}' $INSTANCE_ID
```

#### 以JSON格式获取子部分
---
如果你请求一个本身是包含其他字段的结构的字段，则默认情况下会获得内部值的Go样式转储。Docker添加了一个模板函数，`json`它可以用于以JSON格式获取结果。

```sh
$ docker inspect --format='{{json .Config}}' $INSTANCE_ID
```
## events 系统事件

从服务器获取实时事件。参考：**docker system events** 命令

## version 系统版本

显示Docker版本信息

```sh
$ docker version
Client:
 Version:       18.03.0-ce
 API version:   1.37
 Go version:    go1.9.4
 Git commit:    0520e24302
 Built: Fri Mar 23 08:31:36 2018
 OS/Arch:       windows/amd64
 Experimental:  false
 Orchestrator:  swarm

Server:
 Engine:
  Version:      18.04.0-ce
  API version:  1.37 (minimum version 1.12)
  Go version:   go1.9.4
  Git commit:   3d479c0
  Built:        Tue Apr 10 18:23:35 2018
  OS/Arch:      linux/amd64
  Experimental: false

$ docker version --format '{{.Server.Version}}'
18.04.0-ce

$ docker version --format '{{json .}}'
```
# container 管理容器

```sh
$ docker container -h
Usage:  docker container COMMAND

管理容器

Commands:
  attach      # 将本地标准输入，输出和错误流附加到正在运行的容器
  commit      # 根据容器的更改创建新图像
  cp          # 复制容器和本地文件系统之间的文件/文件夹
  create      # 创建一个新的容器
  diff        # 检查对容器文件系统上文件或目录的更改
  exec        # 在正在运行的容器中运行命令
  export      # 将容器的文件系统导出为tar存档
  inspect     # 显示一个或多个容器的详细信息
  kill        # 杀死一个或多个正在运行的容器
  logs        # 获取容器的日志
  ls          # 列出容器
  pause       # 暂停一个或多个容器内的所有进程
  port        # 列出容器的端口映射或特定映射
  prune       # 删除所有停止的容器
  rename      # 重命名一个容器
  restart     # 重新启动一个或多个容器
  rm          # 删除一个或多个容器
  run         # 在新容器中运行命令
  start       # 启动一个或多个停止的容器
  stats       # 显示容器资源使用统计信息的实时流
  stop        # 停止一个或多个运行容器
  top         # 显示容器的运行过程
  unpause     # 取消暂停一个或多个容器内的所有进程
  update      # 更新一个或多个容器的配置
  wait        # 阻塞，直到一个或多个容器停止，然后打印退出代码
```
#  config 管理配置

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
$ docker service create --name redis --config my-config redis:alpine
# 查看配置文件内容
$ docker container exec $(docker ps --filter name=redis -q) cat /my-config

# 将index.html文件保存为名为的群集配置homepage。
$ docker config create homepage index.html
$ docker service create
    --name my-iis
    --publish published=8000,target=8000
    --config src=homepage,target="\inetpub\wwwroot\index.html"
    microsoft/iis:nanoserver
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
# checkpoint 检查点

> **该命令是实验性的**<br/>该命令在Docker守护进程中是实验性的。它不应该用于生产环境。要在Docker守护程序上启用实验功能，请编辑[daemon.json](https://docs.docker.com/engine/reference/commandline/dockerd/#daemon-configuration-file) 并设置`experimental`为`true`。

## create 创建

从正在运行的容器创建检查点

### 命令参数选项

---

| 选项，简写         | 默认 | 描述                     |
| ------------------ | ---- | ------------------------ |
| `--checkpoint-dir` |      | 使用自定义检查点存储目录 |
| `--leave-running`  |      | 在检查点之后让容器运行   |

### 示例

---

```sh
$ docker checkpoint create CONTAINER_ID CHECKPOINT_NAME
```

## ls 列表

列出容器的检查点

```sh
$ docker checkpoint ls CONTAINER_ID CHECKPOINT_NAME
$ docker checkpoint ls CONTAINER_ID CHECKPOINT_NAME --checkpoint-dir /data
```

## rm 删除

```sh
$ docker checkpoint rm CONTAINER_ID CHECKPOINT_NAME
```

#   image 管理镜像

```sh
$ docker image -h
Usage:  docker image COMMAND

管理镜像

Commands:
  build       # 从Dockerfile构建镜像
  history     # 显示镜像的历史记录
  import      # 从tarball中导入内容以创建文件系统镜像
  inspect     # 显示一个或多个镜像的详细信息
  load        # 从tar档案或STDIN加载镜像
  ls          # 列出镜像
  prune       # 删除未使用的镜像
  pull        # 从注册表中提取镜像或仓库
  push        # 将镜像或仓库推送到注册表
  rm          # 删除一个或多个镜像
  save        # 将一个或多个镜像保存到tar归档文件（默认流式传输到STDOUT）
  tag         # 创建一个引用SOURCE_IMAGE的标记TARGET_IMAGE
```

## build 构建

从Dockerfile构建镜像。参考：**docker build**命令

```sh
$ docker image build [OPTIONS] PATH | URL | -
```

## history 历史

显示镜像的历史记录。参考：**docker history** 命令

```sh
$ docker image history [OPTIONS] IMAGE
--format		使用Go模板打印出漂亮的镜像
--human , -H	true	以可读格式打印大小和日期
--no-trunc		不要截断输出
--quiet , -q		只显示数字ID
```

## import 导入

从tarball中导入内容以创建文件系统镜像。参考：**docker import** 命令

```sh
$ docker image import [OPTIONS] file|URL|- [REPOSITORY[:TAG]]
--change , -c		将Dockerfile指令应用于创建的镜像
--message , -m		为导入的镜像设置提交消息
```

## inspect 详细

显示一个或多个镜像的详细信息。参考：**docker inspect** 命令

```sh
$ docker image inspect [OPTIONS] IMAGE [IMAGE...]
--format , -f		使用给定的Go模板格式化输出
```

## load 加载

从tar档案或STDIN加载镜像。参考：**docker load** 命令

```sh
$ docker image load [OPTIONS]
--input , -i		从tar档案文件读取，而不是STDIN
--quiet , -q		抑制负载输出
```

## ls 列表

列出镜像。参考：**docker images** 命令

```sh
$ docker image ls [OPTIONS] [REPOSITORY[:TAG]]
--all , -a		显示所有镜像（默认隐藏中间镜像）
--digests		显示摘要
--filter , -f		根据提供的条件过滤输出
--format		使用Go模板打印出漂亮的镜像
--no-trunc		不要截断输出
--quiet , -q		只显示数字ID
```

## prune 修剪

删除所有未使用的镜像。如果`-a`指定，还将删除未被任何容器引用的所有镜像。

### 命令参数选项

------

| 选项，简写     | 默认 | 描述                                       |
| -------------- | ---- | ------------------------------------------ |
| `--all , -a`   |      | 删除所有未使用的镜像，而不仅仅是悬挂的镜像 |
| `--filter`     |      | 提供过滤器值（例如'until =“）              |
| `--force , -f` |      | 不要提示确认                               |

### 示例

------

```sh
$ docker image prune -a

WARNING! This will remove all images without at least one container associated to them.
Are you sure you want to continue? [y/N] y
```

#### 过滤
---
过滤选项（`--filter`）格式为`key = value`。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- until  （`<timestamp>`） - 仅删除在给定**时间戳之前**创建的镜像
- label  （`label=<key>，label=<key>=<value>，label!=<key>，或label!=<key>=<value>`） - 仅删除**带有标签**的镜像（如果`label!=... `被使用）指定的标签。 

`until`过滤器可以是Unix的时间戳，日期格式的时间戳，或持续时间字符串（例如，去`10m`，`1h30m`）计算相对于守护机器的时间。支持的格式为日期格式时间戳包括`RFC3339Nano，RFC3339`， `2006-01-02T15:04:05`，`2006-01-02T15:04:05.999999999`，`2006-01-02Z07:00`和`2006-01-02`。如果在时间戳结束时未提供时区偏移`Z`或`+-00:00`时区偏移，则将使用守护程序上的本地时区。在提供Unix时间戳时，输入`seconds [.nanoseconds]`，其中`seconds`是自1970年1月1日（午夜`UTC / GMT`）以来经过的秒数，不包括闰秒（又名Unix时代或Unix时间）和可选项。纳秒字段是一秒不到9位数字的一小部分。

`label`过滤器接受两种格式。一个是`label=...`（`label=<key>`或`label=<key>=<value>`），这会删除具有指定标签的镜像。另一种格式是`label!=...`（`label!=<key>`或`label!=<key>=<value>`），这会删除没有指定标签的镜像。

> **预测将被删除的内容**<br/>如果使用正向过滤（测试是否存在标签或标签是否具有特定值），则可以使用`docker image ls`相同的过滤语法查看哪些镜像与过滤器匹配。
>
> 但是，如果使用否定过滤（测试是否**缺少标签**或标签**没有特定**值），则此类过滤器不适用于`docker image ls`，因此无法轻松预测哪些镜像将被删除。此外，`docker image prune` 的确认提示会**始终警告**，即使正在使用`--filter`，所有悬挂的镜像也会被移除。

下面删除`2017-01-04T00:00:00`之前创建的镜像：

```sh
# 格式化输出
$ docker images --format 'table {{.Repository}}\t{{.Tag}}\t{{.ID}}\t{{.CreatedAt}}\t{{.Size}}'
REPOSITORY          TAG                 IMAGE ID            CREATED AT                      SIZE
foo                 latest              2f287ac753da        2017-01-04 13:42:23 -0800 PST   3.98 MB
alpine              latest              88e169ea8f46        2016-12-27 10:17:25 -0800 PST   3.98 MB
busybox             latest              e02e811dd08f        2016-10-07 14:03:58 -0700 PDT   1.09 MB

# 删除镜像

$ docker image prune -a --force --filter "until=2017-01-04T00:00:00"
Deleted Images:
untagged: alpine:latest
untagged: alpine@sha256:dfbd4a3a8ebca874ebd2474f044a0b33600d4523d03b0df76e5c5986cb02d7e8
untagged: busybox:latest
untagged: busybox@sha256:29f5d56d12684887bdfa50dcd29fc31eea4aaf4ad3bec43daf19026a7ce69912
deleted: sha256:e02e811dd08fd49e7f6032625495118e63f597eb150403d02e3238af1df240ba
deleted: sha256:e88b3f82283bc59d5e0df427c824e9f95557e661fcb0ea15fb0fb6f97760f9d9

Total reclaimed space: 1.093 MB
# 删除24小时之前的
# docker network prune --filter "until=24h"

# 格式化输出
$ docker images --format 'table {{.Repository}}\t{{.Tag}}\t{{.ID}}\t{{.CreatedAt}}\t{{.Size}}'
REPOSITORY          TAG                 IMAGE ID            CREATED AT                      SIZE
foo                 latest              2f287ac753da        2017-01-04 13:42:23 -0800 PST   3.98 MB
```

以下删除10天`240h`以前创建的镜像：

```sh
$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
foo                 latest              2f287ac753da        14 seconds ago      3.98 MB
alpine              latest              88e169ea8f46        8 days ago          3.98 MB
debian              jessie              7b0a06c805e8        2 months ago        123 MB
busybox             latest              e02e811dd08f        2 months ago        1.09 MB
golang              1.7.0               138c2e655421        4 months ago        670 MB

$ docker image prune -a --force --filter "until=240h"
Deleted Images:
untagged: golang:1.7.0
untagged: golang@sha256:6765038c2b8f407fd6e3ecea043b44580c229ccfa2a13f6d85866cf2b4a9628e
deleted: sha256:138c2e6554219de65614d88c15521bfb2da674cbb0bf840de161f89ff4264b96
deleted: sha256:ec353c2e1a673f456c4b78906d0d77f9d9456cfb5229b78c6a960bfb7496b76a
deleted: sha256:fe22765feaf3907526b4921c73ea6643ff9e334497c9b7e177972cf22f68ee93
deleted: sha256:ff845959c80148421a5c3ae11cc0e6c115f950c89bc949646be55ed18d6a2912
deleted: sha256:a4320831346648c03db64149eafc83092e2b34ab50ca6e8c13112388f25899a7
deleted: sha256:4c76020202ee1d9709e703b7c6de367b325139e74eebd6b55b30a63c196abaf3
deleted: sha256:d7afd92fb07236c8a2045715a86b7d5f0066cef025018cd3ca9a45498c51d1d6
deleted: sha256:9e63c5bce4585dd7038d830a1f1f4e44cb1a1515b00e620ac718e934b484c938
untagged: debian:jessie
untagged: debian@sha256:c1af755d300d0c65bb1194d24bce561d70c98a54fb5ce5b1693beb4f7988272f
deleted: sha256:7b0a06c805e8f23807fb8856621c60851727e85c7bcb751012c813f122734c8d
deleted: sha256:f96222d75c5563900bc4dd852179b720a0885de8f7a0619ba0ac76e92542bbc8

Total reclaimed space: 792.6 MB

$ docker images
REPOSITORY          TAG                 IMAGE ID            CREATED              SIZE
foo                 latest              2f287ac753da        About a minute ago   3.98 MB
alpine              latest              88e169ea8f46        8 days ago           3.98 MB
busybox             latest              e02e811dd08f        2 months ago         1.09 MB
```

以下示例使用标签`deprecated`去除镜像：

```sh
$ docker image prune --filter="label=deprecated"
```

以下示例删除标签`maintainer`设置为`john`的镜像：

```sh
$ docker image prune --filter="label=maintainer=john"
```

这个例子删除没有`maintainer`标签的镜像：

```sh
$ docker image prune --filter="label!=maintainer"
```

此示例移除具有未设置为`maintainer`标签`john`的镜像：

```sh
$ docker image prune --filter="label!=maintainer=john"
```

> **注意**：在`prune`删除任何内容之前，系统会提示**进行确认**，但未显示可能会被删除的内容的列表。另外，`docker image ls`不支持负面过滤，因此很难预测哪些镜像实际上会被移除。

## pull 拉取

从注册表中提取镜像或仓库。参考：**docker pull** 命令

```sh
$ docker image pull [OPTIONS] NAME[:TAG|@DIGEST]
--all-tags , -a		下载仓库中的所有标记镜像
--disable-content-trust	true	跳过镜像验证
--platform		实验（守护程序）API 1.32+ 如果服务器具有多平台功能，请设置平台
```

## push 推送

将镜像或仓库推送到注册表。参考：**docker push** 命令

```sh
$ docker image push [OPTIONS] NAME[:TAG]
--disable-content-trust	true	跳过镜像签名
```

## rm 删除

删除一个或多个镜像。参考：**docker rmi** 命令

```sh
$ docker image rm [OPTIONS] IMAGE [IMAGE...]
--force , -f		强制删除镜像
--no-prune		不要删除未标记的父母
```

## save 保存

将一个或多个镜像保存到tar归档文件（默认流式传输到STDOUT）。参考：**docker save** 命令

```sh
$ docker image save [OPTIONS] IMAGE [IMAGE...]
--output , -o		写入文件，而不是STDOUT
```

## tag 标签

创建一个引用SOURCE_IMAGE的标记TARGET_IMAGE。参考： **docker tag** 命令

```sh
$ docker image tag SOURCE_IMAGE[:TAG] TARGET_IMAGE[:TAG]
```

# network 管理网络

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
---
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
---
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
---
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
---
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
---
当你启动容器时，请使用`--network`选项将其连接到网络。本例将`busybox`容器添加到`mynet`网络中：

```shell
$ docker network create -d bridge mynet
$ docker run -itd --network=mynet busybox
```

如果要将已经运行的容器添加到网络，请使用`docker network connect`命令。

你可以将多个容器连接到同一个网络。连接后，容器只能使用另一个容器的IP地址或名称进行通信。对于`overlay`支持多主机连接的网络或自定义插件，连接到相同多主机网络但从不同引擎启动的容器也可以通过这种方式进行通信。

你可以使用`docker network disconnect`命令从网络断开容器。

#### 高级选项
---
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
---
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
---
默认情况下，当你将容器连接到`overlay`网络时，Docker也会将桥接网络连接到它以提供外部连接。如果你想创建一个外部隔离的`overlay`网络，你可以指定该 `--internal`选项。

```shell
$ docker network create --internal -d overlay my-overlay-inte-net
```

#### 网络ingress模式
---
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
---
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
---
可以使用`docker run --network=<network-name>`选项启动容器并立即将其连接到网络。

```shell
$ docker run -it --network=my-bridge-net helloworld-jdk-9:latest
$ docker run -itd --network=multi-host-network busybox
```

#### 连接网络使用固定IP
---
可以指定要分配给容器固定的IP地址。对于不同的网络，分配的IP网段跟网络有关，所以先查看网络的子网网段，再分配合法的IP。

```shell
$ docker network inspect my-bri-0
$ docker network inspect my-bri-0 --format={{.IPAM.Config}}
[{192.168.0.0/18   map[]}]

$ docker network connect --ip 192.168.5.122 my-bri-0 suspicious_kepler
```

#### 使用旧版`--link`选项
---
可以使用`--link`选项将另一个容器与首选别名链接起来

```shell
$ docker network connect --link silly_curie:my_container my-bridge suspicious_kepler
```

#### 连接网络时创建网络别名
---
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
---
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
# plugin 管理插件

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
| `--disable-content-trust` | `true` | 跳过镜像验证               |
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

列出当前安装的所有插件。你可以使用该[`docker plugin install`](https://docs.docker.com/engine/reference/commandline/plugin_install/)命令安装插件。你也可以使用`-f`或`--filter`选项进行过滤。有关可用过滤器选项的更多信息，请参阅[过滤](https://docs.docker.com/engine/reference/commandline/plugin_ls/#filtering)部分。

 ```sh
$ docker plugin ls
ID                  NAME                             TAG                 DESCRIPTION                ENABLED
69553ca1d123        tiborvass/sample-volume-plugin   latest              A test plugin for Docker   true

# 过滤
$ docker plugin ls --filter enabled=true
 ```

### 格式化
---
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

使用`docker plugin create`插件创建插件并准备好发布之后，用于`docker plugin push`将镜像分享到Docker Hub或自托管注册表。

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
---
以下示例更改插件`DEBUG`上的 env变量`sample-volume-plugin`。

```sh
$ docker plugin inspect -f {{.Settings.Env}} tiborvass/sample-volume-plugin
[DEBUG=0]

$ docker plugin set tiborvass/sample-volume-plugin DEBUG=1

$ docker plugin inspect -f {{.Settings.Env}} tiborvass/sample-volume-plugin
[DEBUG=1]
```

### 更改安装源
---
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
---
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

将现有插件升级到指定的远程插件镜像。如果未指定远程，Docker将重新提取当前镜像并使用更新后的版本。所有现有的插件引用将继续工作。运行升级之前，必须禁用该插件。

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
# volume 管理数据卷

与绑定挂载不同，你可以创建和管理任何容器范围之外的卷。

```sh
$ docker volume -h
Usage:  docker volume COMMAND
管理任何容器范围之外的卷

Commands:
  create      # 创建卷
  inspect     # 查看卷详细信息
  ls          # 卷列表
  prune       # 删除未用的卷
  rm          # 删除一个或多个卷
```

## create 创建

### 基本选项

---

```shell
--driver , -d	#默认值：local，指定卷驱动程序名称
--label		    #设置卷的元数据
--name		    #指定卷名称
--opt , -o		#设置驱动程序特定选项
```

创建容器可以使用和存储数据的新卷。如果未指定名称，则Docker会生成一个随机名称。

### 创建卷
---
```sh
$ docker volume create my-vol
```

### 使用卷
---
创建一个卷，然后配置容器以使用它：

```sh
$ docker volume create hello
hello
$ docker run -d -v hello:/world busybox ls /world
```

挂载目录`/world`是在容器的中创建的。Docker不支持容器内的挂载点的相对路径。

多个容器可以在同一时间段内使用相同的挂载卷。如果两个容器需要访问共享数据，这很有用。例如，如果一个容器写入，另一个容器读取数据。

**卷的名字在设备中必须是唯一的**。这意味着你不能在两个不同的设备中使用相同的卷名称。如果你尝试此操作`docker`将返回一个错误：

```sh
A volume named  "hello"  already exists with the "some-other" driver. Choose a different volume name.
```

如果你指定当前设备程序中已使用的卷名称，则Docker会假定你想要重新使用现有卷并且不会返回错误。

### 驱动程序特定的选项
---
某些卷驱动程序可能会采用选项来创建自定义卷。使用 `-o`或`--opt`选项来传递驱动程序选项：

```sh
$ docker volume create --driver fake \
    --opt tardis=blue \
    --opt timey=wimey \
    foo
    
Error response from daemon: create foo: error looking up volume plugin fake: plugin "fake" not found    
```

这些选项**直接传递给卷**驱动程序。不同卷驱动程序的选项可能会做不同的事情（或根本没有）。

Windows上的内置`local`驱动程序不支持任何选项。

Linux上的内置`local`驱动程序接受类似于linux `mount`命令的选项 。你可以通过多次传递`--opt`选项来提供多个选项。某些`mount`选项（如`o`选项）可以使用逗号分隔的选项列表。可在[此处](http://man7.org/linux/man-pages/man8/mount.8.html)找到完整的可用挂载选项列表。

例如，下面创建一个名为`foo`的`tmpfs`卷，其大小为`100`兆字节，`uid`为`1000`。

```sh
$ docker volume create --driver local \
    --opt type=tmpfs \
    --opt device=tmpfs \
    --opt o=size=100m,uid=1000 \
    foo
```

另一个例子使用`btrfs`：

```sh
$ docker volume create --driver local \
    --opt type=btrfs \
    --opt device=/dev/sda2 \
    foo
```

另一个使用`nfs`从`192.168.1.1`开始以`rw`模式挂载`/path/to/dir`的例子：

```sh
$ docker volume create --driver local \
    --opt type=nfs \
    --opt o=addr=192.168.1.1,rw \
    --opt device=:/path/to/dir \
    foo
```

## ls 查看

### 基本选项
---
```shell
--filter , -f		#提供过滤器值（例如'dangling = true'）
--format			#使用Go模板的漂亮打印卷
--quiet , -q		#只显示卷名称
```

### 过滤
---
过滤选项（`-f`或`--filter`）格式为“key = value”。如果有多个过滤器，则传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）

目前支持的过滤器是：

- `dangling`（布尔值 - true或false，0或1）
- `driver`  （卷驱动程序的名称）
- `label`（`label=<key>`或`label=<key>=<value>`）
- `name`（卷的名称）

#### dangling 是否引用
---
过滤器上没有任何容器引用的所有匹配卷

```sh
$ docker run -d  -v tyler:/tmpwork  busybox
f86a7dd02898067079c99ceacd810149060a70528eff3754d0b0f1a93bd0af18
$ docker volume ls -f dangling=true
DRIVER              VOLUME NAME
local               rosemary
```

#### driver 驱动
---
`driver`过滤器根据其驱动程序匹配卷。以下示例匹配使用该`local`驱动程序创建的卷：

```sh
$ docker volume ls -f driver=local

DRIVER              VOLUME NAME
local               rosemary
local               tyler
```

#### label 标签
---
标签过滤器根据单独存在标签或标签和值来匹配卷。

首先，我们来创建一些卷来说明这一点;

```sh
$ docker volume create the-doctor --label is-timelord=yes
the-doctor

$ docker volume create daleks --label is-timelord=no
daleks
```

以下示例过滤器将卷与`is-timelord`标签进行匹配，而不考虑值。

```sh
$ docker volume ls --filter label=is-timelord

DRIVER              VOLUME NAME
local               daleks
local               the-doctor
```

正如上面的例子演示的那样，带有`is-timelord=yes`和 `is-timelord=no`被返回的两个卷。

对两者`key` *和* `value`标签进行过滤，产生预期的结果：

```sh
$ docker volume ls --filter label=is-timelord=yes

DRIVER              VOLUME NAME
local               the-doctor
```

指定多个标签过滤器会产生**and**搜索，应该满足所有条件

```sh
$ docker volume ls --filter label=is-timelord=yes --filter label=is-timelord=no
DRIVER              VOLUME NAME
```

#### name 称
---
名称过滤器匹配全部或部分卷的名称。以下过滤器匹配所有包含该`rose`字符串的名称的卷。

```sh
$ docker volume ls -f name=rose

DRIVER              VOLUME NAME
local               rosemary
```

### 格式化
---
格式化选项（`--format`）使用Go模板输出卷。下面列出了Go模板的有效占位符：

| 占位符        | 描述                                                   |
| ------------- | ------------------------------------------------------ |
| `.Name`       | 卷名称                                                 |
| `.Driver`     | 卷驱动程序                                             |
| `.Scope`      | 卷范围（本地，全局）                                   |
| `.Mountpoint` | 主机上卷的安装点                                       |
| `.Labels`     | 分配给该卷的所有标签                                   |
| `.Label`      | 此卷的特定标签的值。例如`{{.Label "project.version"}}` |

使用`--format`选项时，`volume ls`命令将按照模板声明输出数据，或者在使用 `table`指令时也包含列标题。

下面的示例使用的模板没有报头，并输出 `Name`与`Driver`由所有卷冒号分隔的条目：

```sh
$ docker volume ls --format "{{.Name}}: {{.Driver}}"
vol1: local
vol2: local
vol3: local

$ docker volume ls --format "table {{.Name}}: {{.Driver}}"
vol1: local
vol2: local
vol3: local
```

## inspect 检查

```sh
$ docker volume inspect my-vol
[
    {
        "Driver": "local",
        "Labels": {},
        "Mountpoint": "/var/lib/docker/volumes/my-vol/_data",
        "Name": "my-vol",
        "Options": {},
        "Scope": "local"
    }
]

$ docker volume inspect --format '{{ .Mountpoint }}' my-vol

$ docker volume inspect foo --format '{{.Options}}'
map[o:size=100m,uid=100 type:tmpfs device:tmpfs]

$ docker volume inspect foo --format '{{json .Options}}'
{"device":"tmpfs","o":"size=100m,uid=100","type":"tmpfs"}

$ docker volume inspect foo --format='{{json .Options}}'
```

## rm 删除

删除一个或多个卷。你无法删除容器正在使用的卷。

```sh
$ docker volume rm my-vol
# 删除多个
$ docker volume rm hello e425b890f45
# 强制删除
$ docker volume rm -f hello e425b890f45
```

## prune 裁剪

删除所有未使用的本地卷。未使用的本地卷是那些没有被任何容器引用的卷

```shell
$ docker volume prune
# 强制删除，不提示输入
$ docker volume prune -f
## 过滤裁剪
$ docker volume prune -f --filter driver=local	
```
# secret 管理私密

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

#### 用文件创建
---
```sh
$ docker secret create my_secret ./secret.json
dg426haahpi5ezmkkj5kyl3sn

$ docker secret ls
ID                          NAME                CREATED             UPDATED
dg426haahpi5ezmkkj5kyl3sn   my_secret           7 seconds ago       7 seconds ago
```

#### 用标签创建
---
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
# system 管理系统

```sh
$ docker system -h
Usage:  docker system COMMAND

管理 Docker

Commands:
  df          # 显示docker磁盘使用情况
  events      # 从服务器获取实时事件
  info        # 显示广泛的系统信息
  prune       # 删除未使用的数据
```

## df  查看磁盘空间

`docker system df`命令显示有关docker守护程序使用的磁盘空间量的信息。

### 命令参数选项

---

| 名字，简写       | 默认 | 描述                       |
| ---------------- | ---- | -------------------------- |
| `--format`       |      | 使用Go模板打印出漂亮的镜像 |
| `--verbose , -v` |      | 显示空间使用情况的详细信息 |

### 示例

---

默认情况下，该命令将仅显示所用数据的摘要：

```sh
$ docker system df
TYPE                TOTAL               ACTIVE              SIZE                RECLAIMABLE
Images              14                  6                   1.183GB             634.5MB (53%)
Containers          16                  4                   15B                 13B (86%)
Local Volumes       3                   3                   0B                  0B
Build Cache                                                 0B                  0B
```

使用`-v, --verbose`选项可以请求更详细的视图：

```sh
$ docker system df -v

Images space usage:

REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE                SHARED SIZE         UNIQUE SIZE         CONTAINERS
my-curl             latest              b2789dd875bf        6 minutes ago       11 MB               11 MB               5 B                 0
my-jq               latest              ae67841be6d0        6 minutes ago       9.623 MB            8.991 MB            632.1 kB            0
<none>              <none>              a0971c4015c1        6 minutes ago       11 MB               11 MB               0 B                 0
alpine              latest              4e38e38c8ce0        9 weeks ago         4.799 MB            0 B                 4.799 MB            1
alpine              3.3                 47cf20d8c26c        9 weeks ago         4.797 MB            4.797 MB            0 B                 1

Containers space usage:

CONTAINER ID        IMAGE               COMMAND             LOCAL VOLUMES       SIZE                CREATED             STATUS                      NAMES
4a7f7eebae0f        alpine:latest       "sh"                1                   0 B                 16 minutes ago      Exited (0) 5 minutes ago    hopeful_yalow
f98f9c2aa1ea        alpine:3.3          "sh"                1                   212 B               16 minutes ago      Exited (0) 48 seconds ago   anon-vol

Local Volumes space usage:

NAME                                                               LINKS               SIZE
07c7bdf3e34ab76d921894c2b834f073721fccfbbcba792aa7648e3a7a664c2e   2                   36 B
my-named-vol                                                       0                   0 B
```

- `SHARED SIZE` 是镜像与另一个镜像**共享的空间**量（即它们的**公共数据**）
- `UNIQUE SIZE` 是仅由给定镜像**使用的空间**量
- `SIZE`是镜像的**虚拟大小**，它是的总和`SHARED SIZE`与`UNIQUE SIZE`

> **注意**：网络信息未显示，因为它不占用磁盘空间。

## events 事件

用于`docker system events`从服务器获取实时事件。这些事件根据Docker对象类型而不同。

### 命令参数选项

---

| 选项，简写      | 默认 | 描述                               |
| --------------- | ---- | ---------------------------------- |
| `--filter , -f` |      | 根据提供的条件过滤输出             |
| `--format`      |      | 使用给定的Go模板格式化输出         |
| `--since`       |      | 显示自**时间戳**以来创建的所有事件 |
| `--until`       |      | 在此时**间戳之前**将事件流化       |

### 事件对象类型

---

#### 集装箱

Docker容器报告以下事件：

- `attach`
- `commit`
- `copy`
- `create`
- `destroy`
- `detach`
- `die`
- `exec_create`
- `exec_detach`
- `exec_start`
- `export`
- `health_status`
- `kill`
- `oom`
- `pause`
- `rename`
- `resize`
- `restart`
- `start`
- `stop`
- `top`
- `unpause`
- `update`

#### 镜像

Docker镜像报告以下事件：

- `delete`
- `import`
- `load`
- `pull`
- `push`
- `save`
- `tag`
- `untag`

#### 插件

Docker插件报告以下事件：

- `install`
- `enable`
- `disable`
- `remove`

#### 卷

Docker卷报告以下事件：

- `create`
- `mount`
- `unmount`
- `destroy`

#### 网络

Docker网络报告以下事件：

- `create`
- `connect`
- `disconnect`
- `destroy`

#### 守护进程

Docker守护进程报告以下事件：

- `reload`



### 过滤 & 格式化

---

#### 按时间限制事件

`--since`和`--until`参数可以是Unix的时间戳，日期格式化时间戳或Go持续时间字符串（例如`10m，1h30m`），相对于**客户端**计算机的时间计算。 如果不提供`--since`选项，则命令仅返回**新事件或现场事件**。支持的格式为日期格式时间戳包括`RFC3339Nano，RFC3339`， `2006-01-02T15:04:05`，`2006-01-02T15:04:05.999999999`，`2006-01-02Z07:00`和`2006-01-02`。如果你在时间戳结束时未提供`Z或+00：00`时区偏移量，则将使用**客户端上的本地**时区。 在提供Unix时间戳时输入`seconds [.nanoseconds]`，其中`seconds`是自1970年1月1日（`UTC / GMT午夜`）以来经过的**秒数**，不包括闰秒（又名Unix时代或Unix时间）和可选项。纳秒字段是一秒不到9位数字的一小部分。

#### 过滤
---
过滤选项（`-f`或`--filter`）格式为`“key = value”`。如果你想使用多个过滤器，传递多个选项（例如`--filter "foo=bar" --filter "bif=baz"`）。

多次使用相同的过滤器将作为**OR**处理。 例如 `--filter container=588a23dac085 --filter container=a8f7720b8c22`将显示容器`588a23dac085` **或**容器`a8f7720b8c22`的事件。

使用多个过滤器将作为**AND**处理。 例如 `--filter container=588a23dac085 --filter event=start`将显示容器容器`588a23dac085 `的事件*，*并且事件类型**start**。

目前支持的过滤器是：

- container（`container=<name or id>`）
- daemon（`daemon=<name or id>`）
- event（`event=<event action>`）
- image（`image=<tag or id>`）
- label（`label=<key>`或`label=<key>=<value>`）
- network（`network=<name or id>`）
- plugin（`plugin=<name or id>`）
- type（`type=<container or image or volume or network or daemon or plugin>`）
- volume（`volume=<name or id>`）

#### 格式
---
如果指定了格式（`--format`），则将执行给定模板而不是默认格式。Go的文本/模板包描述了格式的所有细节。

如果格式设置为`{{json .}}`，则事件将作为有效的JSON行进行流式传输。有关JSON行的信息，请参阅http://jsonlines.org/。

### 示例

---

#### 基本示例

这个例子你将需要两个shell。

**shell 窗口1：监听事件：**

```sh
$ docker system events
```

**shell 窗口2：启动和停止容器：**

```sh
$ docker create --name test alpine:latest top
$ docker start test
$ docker stop test
```

**查看窗口1的shell显示事件日志**

```sh
2017-01-05T00:35:58.859401177+08:00 container create 0fdb48addc82871eb34eb23a847cfd033dedd1a0a37bef2e6d9eb3870fc7ff37 (image=alpine:latest, name=test)
2017-01-05T00:36:04.703631903+08:00 network connect e2e1f5ceda09d4300f3a846f0acfaa9a8bb0d89e775eb744c5acecd60e0529e2 (container=0fdb...ff37, name=bridge, type=bridge)
2017-01-05T00:36:04.795031609+08:00 container start 0fdb...ff37 (image=alpine:latest, name=test)
2017-01-05T00:36:09.830268747+08:00 container kill 0fdb...ff37 (image=alpine:latest, name=test, signal=15)
2017-01-05T00:36:09.840186338+08:00 container die 0fdb...ff37 (exitCode=143, image=alpine:latest, name=test)
2017-01-05T00:36:09.880113663+08:00 network disconnect e2e...29e2 (container=0fdb...ff37, name=bridge, type=bridge)
2017-01-05T00:36:09.890214053+08:00 container stop 0fdb...ff37 (image=alpine:latest, name=test)
```

要退出`docker system events`命令，请使用`CTRL+C`。

#### 按时间过滤事件
---
你可以使用以下不同的时间语法在主机上按绝对时间戳或相对时间过滤输出：

```sh
$ docker system events --since 1483283804
$ docker system events --since '2017-01-05'
$ docker system events --since '2013-09-03T15:49:29'
$ docker system events --since '10m'
```

#### 按标准过滤事件
---
以下命令显示了几种不同的方法来过滤`docker event` 输出。

```sh
$ docker system events --filter 'event=stop'
$ docker system events --filter 'image=alpine'
$ docker system events --filter 'container=test'
$ docker system events --filter 'container=test' --filter 'container=d9cdb1525ea8'
$ docker system events --filter 'container=test' --filter 'event=stop'
$ docker system events --filter 'type=volume'
$ docker system events --filter 'type=network'
$ docker system events --filter 'container=container_1' --filter 'container=container_2'
$ docker system events --filter 'type=volume'
$ docker system events --filter 'type=plugin'
```

#### 格式化输出
---
```sh
$ docker system events --filter 'type=container' --format 'Type={{.Type}}  Status={{.Status}}  ID={{.ID}}'

# 格式为JSON
$ docker system events --format '{{json .}}'
```

## info 信息

显示系统范围的信息

 ```sh
$ docker system info
$ docker system info -f "{{json .}}"
$ docker info -f '{{json .ID}}'
"IXQ5:IG3J:BRRN:56OH:5MC3:4WZT:U725:KHML:HQGO:J5BZ:L4WY:2OYK"
 ```

## prune 修剪

删除所有未使用的容器，网络，镜像（包括挂起和未引用），和卷(可选)。

### 命令参数选项

---

| 选项，简写     | 默认 | 描述                                                         |
| -------------- | ---- | ------------------------------------------------------------ |
| `--all , -a`   |      | 删除所有未使用的镜像，而不仅仅是悬挂的镜像                   |
| `--filter`     |      | [API 1.28+](https://docs.docker.com/engine/api/v1.28/) 提供过滤器值（例如'label ==“） |
| `--force , -f` |      | 不要提示确认                                                 |
| `--volumes`    |      | 修剪卷                                                       |

### 示例

---

删除数据并提出警告

```sh
$ docker system prune

WARNING! This will remove:
        - all stopped containers
        - all networks not used by at least one container
        - all dangling images
        - all build cache
Are you sure you want to continue? [y/N] y

Deleted Containers:
f44f9b81948b3919590d5f79a680d8378f1139b41952e219830a33027c80c867
792776e68ac9d75bce4092bc1b5cc17b779bc926ab04f4185aec9bf1c0d4641f

Deleted Networks:
network1
network2

Deleted Images:
untagged: hello-world@sha256:f3b3b28a45160805bb16542c9531888519430e9e6d6ffc09d72261b0d26ff74f
deleted: sha256:1815c82652c03bfd8644afda26fb184f2ed891d921b20a0703b46768f9755c57
deleted: sha256:45761469c965421a92a69cc50e92c01e0cfa94fe026cdd1233445ea00e96289a

Total reclaimed space: 1.84kB
```

默认情况下，如果当前没有容器使用卷，则**不会删除卷**以防止删除重要数据。运行命令删除卷时使用`--volumes` 选项：

```sh
$ docker system prune -a --volumes

WARNING! This will remove:
        - all stopped containers
        - all networks not used by at least one container
        - all volumes not used by at least one container
        - all images without at least one container associated to them
        - all build cache
Are you sure you want to continue? [y/N] y

Deleted Containers:
0998aa37185a1a7036b0e12cf1ac1b6442dcfa30a5c9650a42ed5010046f195b
73958bfb884fa81fa4cc6baf61055667e940ea2357b4036acbbe25a60f442a4d

Deleted Networks:
my-network-a
my-network-b

Deleted Volumes:
named-vol

Deleted Images:
untagged: my-curl:latest
deleted: sha256:7d88582121f2a29031d92017754d62a0d1a215c97e8f0106c586546e7404447d
deleted: sha256:dd14a93d83593d4024152f85d7c63f76aaa4e73e228377ba1d130ef5149f4d8b
untagged: alpine:3.3
deleted: sha256:695f3d04125db3266d4ab7bbb3c6b23aa4293923e762aa2562c54f49a28f009f
untagged: alpine:latest
deleted: sha256:ee4603260daafe1a8c2f3b78fd760922918ab2441cbb2853ed5c439e59c52f96
deleted: sha256:9007f5987db353ec398a223bc5a135c5a9601798ba20a1abba537ea2f8ac765f
deleted: sha256:71fa90c8f04769c9721459d5aa0936db640b92c8c91c9b589b54abd412d120ab
deleted: sha256:bb1c3357b3c30ece26e6604aea7d2ec0ace4166ff34c3616701279c22444c0f3
untagged: my-jq:latest
deleted: sha256:6e66d724542af9bc4c4abf4a909791d7260b6d0110d8e220708b09e4ee1322e1
deleted: sha256:07b3fa89d4b17009eb3988dfc592c7d30ab3ba52d2007832dffcf6d40e3eda7f
deleted: sha256:3a88a5c81eb5c283e72db2dbc6d65cbfd8e80b6c89bb6e714cfaaa0eed99c548

Total reclaimed space: 13.5 MB
```

> **注意**：`--volumes`选项已添加到Docker 17.06.1中。默认情况下，老版本的Docker修剪卷以及其他Docker对象。在旧版本中，运行`docker container prune`，`docker network prune`和 `docker image prune`分别删除未使用的容器，网络和镜像，无需拆卸卷。

# node 管理集群节点

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
---
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
---
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
---
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
---
从群中删除指定的节点，但只有当节点处于停机状态时才会这样。如果**尝试删除活动节点，将收到错误消息**：

```sh
$ docker node rm swarm-node-03
Error response from daemon: rpc error: code = 9 desc = node swarm-node-03 is not
down and can't be removed

$ docker node rm swarm-node-03 -f
```

#### 强行删除不可访问的节点
---
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

# service 管理服务

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
| `--entrypoint`                 |              | 覆盖镜像的默认入口点                                         |
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
| `--no-resolve-image`           |              | [API 1.30+](https://docs.docker.com/engine/api/v1.30/) 不要查询注册表以解析镜像摘要和支持的平台 |
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
---
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
---
以下选项只能用于命名卷（`type=volume`）：

| 选项              | 描述                                                         |
| ----------------- | ------------------------------------------------------------ |
| **volume-driver** | 用于卷的卷驱动程序**插件的名称**。如果该卷不存在，则默认为 **local**，以使用本地卷驱动程序创建卷。 |
| **volume-label**  | 创建时应用于卷的一个或多个自定义元数据（“标签”）。<br/>例如， `volume-label = mylabel = hello-world，my-other-label = hello-mars`。<br/>有关标签的更多信息，请参阅 [应用自定义元数据](https://docs.docker.com/engine/userguide/labels-custom-metadata/)。 |
| **volume-nocopy** | 默认情况下，如果你将空卷附加到容器，并且文件或目录已经存在于容器中的安装路径（`dst`）中，则引擎会将这些文件和目录**复制到卷中**，以便主机访问它们。设置`volume-nocopy`以**禁止**将文件从容器的文件系统复制到卷并挂载空卷。 <br/>值是可选的：  <br/> `true` or `1`： 如果你不提供值，则为默认值。禁用复制。<br/> `false` or `0：` 启用复制 |
| **volume-opt**    | 特定于给定卷驱动程序的**选项，将在创建卷时传递给驱动程序**。选项以逗号分隔的键/值对列表形式提供，例如， `volume-opt = some-option = some-value，volume-opt = some-other-option = some-other-value`。<br/>有关给定驱动程序的可用选项，请参阅该驱动程序的文档。 |

##### **TMPFS的选项**
---
以下选项只能用于`tmpfs mounts`（`type=tmpfs`）;

| 选项           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| **tmpfs-size** | tmpfs的大小，以字节为单位。Linux中默认无限制。               |
| **tmpfs-mode** | tmpfs的八进制文件模式。（例如`“700”`或`“0700”）`。在Linux中默认为`“1777”`。 |

##### **`--MOUNT`和`--VOLUME`的区别**
---
`--mount`选项支持`docker run`的`-v` 或`--volume`的大多数选项，有一些重要的例外情况：

- `--mount`选项允许你为**每个卷**指定卷驱动程序和卷驱动程序选项，而无需预先创建卷。相反`docker run`允许你使用`--volume-driver`选项来指定由**所有**卷共享的**单个**卷驱动程序。
- `--mount`选项允许你在卷创建之前指定卷的**自定义元数据**（“标签”）。
- 在使用`--mount` `type=bind`时，主机路径必须引用主机上的**现有* *路径。路径将**不会为你创建**，如果路径不存在，服务将**失败**并显示错误。
- `--mount`选项**不允许**你重新标记用于标记的卷`Z`或`z`选项`selinux`。

##### 使用命名卷创建服务
---
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
---
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
---
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
| 协议           | `-p 8080：80 / tcp`        | `--publish published = 8080，target = 80，protocol = tcp` | 要使用的协议，`tcp`，`udp`或`sctp`。默认为 `tcp`。要为两种协议绑定端口，请指定`-p`或 `--publish`选项两次。 |

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
---
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
---
`docker service logs --follow`命令将继续流式传输来自服务`STDOUT`和服务的新输出`STDERR`。

```sh
$ docker service logs my-web --follow
```

#### 查看指定行数
---
传递一个负数或一个非整数`--tail`是无效的，`all`在这种情况下值被设置为。

```sh
$ docker service logs my-web --tail 2
my-web.2.k027kb6dsgwz@my-vm-node-1    | 10.255.0.2 - - [08/May/2018:07:25:26 +0000] "GET /favicon.ico HTTP/1.1" 404 572 "http://192.168.99.100:8080/" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36" "-"
my-web.2.k027kb6dsgwz@my-vm-node-1    | 2018/05/08 07:25:26 [error] 5#5: *1 open() "/usr/share/nginx/html/favicon.ico" failed (2: No such file or directory), client: 10.255.0.2, server: localhost, request: "GET /favicon.ico HTTP/1.1", host: "192.168.99.100:8080", referrer: "http://192.168.99.100:8080/"
```

#### 时间戳
---
`docker service logs --timestamps`命令将增加一个[RFC3339Nano时间戳](https://golang.org/pkg/time/#pkg-constants) ，例如`2014-09-16T06:17:46.000000000Z`，每个日志记录。为确保时间戳对齐，必要时，时间戳的纳秒部分将填充零。

```sh
$ docker service logs my-web --tail 2 --timestamps
2018-05-08T07:25:26.919177543Z my-web.2.k027kb6dsgwz@my-vm-node-1    | 10.255.0.2 - - [08/May/2018:07:25:26 +0000] "GET /favicon.ico HTTP/1.1" 404 572 "http://192.168.99.100:8080/" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36" "-"
```

#### 额外详细信息
---
`docker service logs --details`命令将添加额外的属性，例如`--log-opt`创建服务时提供的环境变量和标签。

```sh
$ docker service logs --details my-web
my-web.2.k027kb6dsgwz@my-vm-node-1    |  10.255.0.2 - - [08/May/2018:07:25:26 +0000] "GET / HTTP/1.1" 200 612 "-" "Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/65.0.3325.181 Safari/537.36" "-"
```

#### 日期过滤
---
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
---
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
---
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
---
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
---
格式化选项（`--format`）可以很好地打印使用Go模板输出的任务。下面列出了Go模板的有效占位符：

| 占位符          | 描述                                                  |
| --------------- | ----------------------------------------------------- |
| `.ID`           | 任务ID                                                |
| `.Name`         | 任务名称                                              |
| `.Image`        | 任务镜像                                              |
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
---
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
| `--entrypoint`                 |      | 覆盖镜像的默认入口点                                         |
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
| `--image`                      |      | 服务镜像标签                                                 |
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
| `--no-resolve-image`           |      | [API 1.30+](https://docs.docker.com/engine/api/v1.30/) 不要查询注册表以解析镜像摘要和支持的平台 |
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
---
```sh
$ docker service update --force --update-parallelism 1 --update-delay 30s redis
```

在这个例子中，`--force`选项导致服务的任务**被关闭并被新的替换**，即使其他参数通常都不会导致这种情况发生。`--update-parallelism 1`设置确保一次只替换一个任务（这是默认行为）。 `--update-delay 30s`设置在任务之间引入了30秒的延迟，以便滚动重启逐渐发生。

#### 添加或删除挂载
---
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
---
使用`--publish-add`或`--publish-rm`选项添加或删除服务的已发布端口。以下示例将已发布的服务端口添加到现有服务。

```sh
$ docker service update \
  --publish-add published=8080,target=80 \
  myservice
```

#### 添加或删除网络
---
使用`--network-add`或`--network-rm`选项为服务添加或删除网络。以下示例将新的别名添加到已连接到网络my-network的现有服务：

```sh
$ docker service update \
  --network-rm my-network \
  --network-add name=my-network,alias=web1 \
  myservice
```

#### 回滚到服务的先前版本
---
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
---
使用`--secret-add`或`--secret-rm`选项添加或删除服务的秘密。

以下示例添加一个名为`ssh-2`并删除的秘密`ssh-1`：

```sh
$ docker service update \
    --secret-add source=ssh-2,target=ssh-2 \
    --secret-rm ssh-1 \
    myservice
```
# swarm 管理集群

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
---
如果一个或多个**集群管理节点遭到入侵，建议使用根CA轮换**，以便这些管理节点**不能再连接到集群中的任何其他节点**或受其信任。或者，可以使用**根CA旋转来将集群CA控制权授予外部CA**，或从**外部CA获取控制权**。

`--rotate`选项不需要任何参数进行轮换，但可以选择**指定证书和密钥**，或者**证书和外部CA URL**，并且将使用这些参数代替自动生成的证书/密钥对。

由于根CA密钥应该保密，如果提供，通过CLI或API查看集群任何信息时都不可见。直到**所有注册节点**都旋转了他们的TLS证书后，根CA轮换才能完成。如果旋转**没有在合理的时间**内完成，请尝试运行`docker node ls --format '{{.ID}} {{.Hostname}} {{.Status}} {{.TLSStatus}}'`以查看是否有节点关闭或无法旋转TLS证书。

```sh
$ docker node ls --format '{{.ID}} {{.Hostname}} {{.Status}} {{.TLSStatus}}'
888gi7byqi5p7wtd2yv1z465i default Ready Ready
jx49db999birkx3myeorh9qvg my-vm-node-1 Ready Ready
```

### `--detach`
---
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
---
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
---
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

| 选项，简写               | 默认        | 描述                                                         |
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
# stack 服务编排

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
| `--resolve-image`      | `always` | [API 1.30+](https://docs.docker.com/engine/api/v1.30/)Swarm 查询注册表以解析镜像摘要和支持的平台（“always”\|“changed”\|“never”） |
| `--with-registry-auth` |          | Swarm 向Swarm代理发送注册表认证详细信息                      |
| `--kubeconfig`         |          | [实验（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes配置文件 |
| `--namespace`          |          | [实验性（CLI）](https://docs.docker.com/engine/reference/commandline/cli/#configuration-files)Kubernetes Kubernetes命名空间使用 |



### 示例

---

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
---
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
---
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
---
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
---
格式化选项（`--format`）可以很好地打印使用Go模板输出的任务。下面列出了Go模板的有效占位符：

| 占位符          | 描述                                                  |
| --------------- | ----------------------------------------------------- |
| `.ID`           | 任务ID                                                |
| `.Name`         | 任务名称                                              |
| `.Image`        | 任务镜像                                              |
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
---
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
---
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