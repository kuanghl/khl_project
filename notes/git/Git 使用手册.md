# Git 使用手册
* [Git 使用手册](#git-%E4%BD%BF%E7%94%A8%E6%89%8B%E5%86%8C)
* [1、Git简介](#1git%E7%AE%80%E4%BB%8B)
  * [Git 是什么？](#git-%E6%98%AF%E4%BB%80%E4%B9%88)
  * [Git 的特点](#git-%E7%9A%84%E7%89%B9%E7%82%B9)
  * [Git 的功能特征](#git-%E7%9A%84%E5%8A%9F%E8%83%BD%E7%89%B9%E5%BE%81)
  * [Git 的优缺点](#git-%E7%9A%84%E4%BC%98%E7%BC%BA%E7%82%B9)
* [2、Git的安装](#2git%E7%9A%84%E5%AE%89%E8%A3%85)
  * [下载Git工具](#%E4%B8%8B%E8%BD%BDgit%E5%B7%A5%E5%85%B7)
  * [安装Windows Git](#%E5%AE%89%E8%A3%85windows-git)
  * [检查是否安装成功](#%E6%A3%80%E6%9F%A5%E6%98%AF%E5%90%A6%E5%AE%89%E8%A3%85%E6%88%90%E5%8A%9F)
* [3、Git常用命令](#3git%E5%B8%B8%E7%94%A8%E5%91%BD%E4%BB%A4)
  * [配置工具/ Configuration Tooling](#%E9%85%8D%E7%BD%AE%E5%B7%A5%E5%85%B7-configuration-tooling)
    * [配置个人信息](#%E9%85%8D%E7%BD%AE%E4%B8%AA%E4%BA%BA%E4%BF%A1%E6%81%AF)
    * [配置文本编辑器](#%E9%85%8D%E7%BD%AE%E6%96%87%E6%9C%AC%E7%BC%96%E8%BE%91%E5%99%A8)
    * [查看当前配置](#%E6%9F%A5%E7%9C%8B%E5%BD%93%E5%89%8D%E9%85%8D%E7%BD%AE)
    * [配置命令别名](#%E9%85%8D%E7%BD%AE%E5%91%BD%E4%BB%A4%E5%88%AB%E5%90%8D)
  * [创建仓库/ Create Repositories](#%E5%88%9B%E5%BB%BA%E4%BB%93%E5%BA%93-create-repositories)
    * [git clone克隆一个存在的远程仓库](#git-clone%E5%85%8B%E9%9A%86%E4%B8%80%E4%B8%AA%E5%AD%98%E5%9C%A8%E7%9A%84%E8%BF%9C%E7%A8%8B%E4%BB%93%E5%BA%93)
    * [git init创建一个新的本地仓库](#git-init%E5%88%9B%E5%BB%BA%E4%B8%80%E4%B8%AA%E6%96%B0%E7%9A%84%E6%9C%AC%E5%9C%B0%E4%BB%93%E5%BA%93)
  * [本地修改 和 基本快照/ Local Changes &amp; Basic Snapshotting](#%E6%9C%AC%E5%9C%B0%E4%BF%AE%E6%94%B9-%E5%92%8C-%E5%9F%BA%E6%9C%AC%E5%BF%AB%E7%85%A7-local-changes--basic-snapshotting)
    * [git status查看本地工作目录变更修改记录](#git-status%E6%9F%A5%E7%9C%8B%E6%9C%AC%E5%9C%B0%E5%B7%A5%E4%BD%9C%E7%9B%AE%E5%BD%95%E5%8F%98%E6%9B%B4%E4%BF%AE%E6%94%B9%E8%AE%B0%E5%BD%95)
    * [git status \-s 简版文件状态信息](#git-status--s-%E7%AE%80%E7%89%88%E6%96%87%E4%BB%B6%E7%8A%B6%E6%80%81%E4%BF%A1%E6%81%AF)
    * [git diff \-\-staged比较暂存区文件变更内容](#git-diff---staged%E6%AF%94%E8%BE%83%E6%9A%82%E5%AD%98%E5%8C%BA%E6%96%87%E4%BB%B6%E5%8F%98%E6%9B%B4%E5%86%85%E5%AE%B9)
    * [git diff比较文件变更内容](#git-diff%E6%AF%94%E8%BE%83%E6%96%87%E4%BB%B6%E5%8F%98%E6%9B%B4%E5%86%85%E5%AE%B9)
    * [git add添加所有文件到暂存区](#git-add%E6%B7%BB%E5%8A%A0%E6%89%80%E6%9C%89%E6%96%87%E4%BB%B6%E5%88%B0%E6%9A%82%E5%AD%98%E5%8C%BA)
    * [git add \-p &lt;file&gt;添加文件部分内容到暂存区](#git-add--p-file%E6%B7%BB%E5%8A%A0%E6%96%87%E4%BB%B6%E9%83%A8%E5%88%86%E5%86%85%E5%AE%B9%E5%88%B0%E6%9A%82%E5%AD%98%E5%8C%BA)
    * [git commit \-a 提交所有修改，不含新增](#git-commit--a-%E6%8F%90%E4%BA%A4%E6%89%80%E6%9C%89%E4%BF%AE%E6%94%B9%E4%B8%8D%E5%90%AB%E6%96%B0%E5%A2%9E)
    * [git commit 提交暂存区所有修改内容](#git-commit-%E6%8F%90%E4%BA%A4%E6%9A%82%E5%AD%98%E5%8C%BA%E6%89%80%E6%9C%89%E4%BF%AE%E6%94%B9%E5%86%85%E5%AE%B9)
    * [git commit \-\-amend修改最后的提交](#git-commit---amend%E4%BF%AE%E6%94%B9%E6%9C%80%E5%90%8E%E7%9A%84%E6%8F%90%E4%BA%A4)
    * [git commit \-\-amend | git rebase 修改以前历史任意版本信息](#git-commit---amend--git-rebase-%E4%BF%AE%E6%94%B9%E4%BB%A5%E5%89%8D%E5%8E%86%E5%8F%B2%E4%BB%BB%E6%84%8F%E7%89%88%E6%9C%AC%E4%BF%A1%E6%81%AF)
    * [git reset重置暂存区的修改记录](#git-reset%E9%87%8D%E7%BD%AE%E6%9A%82%E5%AD%98%E5%8C%BA%E7%9A%84%E4%BF%AE%E6%94%B9%E8%AE%B0%E5%BD%95)
  * [预览历史/ Review History](#%E9%A2%84%E8%A7%88%E5%8E%86%E5%8F%B2-review-history)
    * [git log 查看提交日志](#git-log-%E6%9F%A5%E7%9C%8B%E6%8F%90%E4%BA%A4%E6%97%A5%E5%BF%97)
    * [git log \-\-follow &lt;file&gt; 跟踪指定文件的版本日志](#git-log---follow-file-%E8%B7%9F%E8%B8%AA%E6%8C%87%E5%AE%9A%E6%96%87%E4%BB%B6%E7%9A%84%E7%89%88%E6%9C%AC%E6%97%A5%E5%BF%97)
    * [git log \-p &lt;file&gt; 查看指定文件提交版本日志、变更内容](#git-log--p-file-%E6%9F%A5%E7%9C%8B%E6%8C%87%E5%AE%9A%E6%96%87%E4%BB%B6%E6%8F%90%E4%BA%A4%E7%89%88%E6%9C%AC%E6%97%A5%E5%BF%97%E5%8F%98%E6%9B%B4%E5%86%85%E5%AE%B9)
    * [git reflog 查看操作日志](#git-reflog-%E6%9F%A5%E7%9C%8B%E6%93%8D%E4%BD%9C%E6%97%A5%E5%BF%97)
    * [git blame查看内容变更者和时间、版本](#git-blame%E6%9F%A5%E7%9C%8B%E5%86%85%E5%AE%B9%E5%8F%98%E6%9B%B4%E8%80%85%E5%92%8C%E6%97%B6%E9%97%B4%E7%89%88%E6%9C%AC)
    * [git show &lt;commit\-id&gt; 查看某个版本的变更日志记录](#git-show-commit-id-%E6%9F%A5%E7%9C%8B%E6%9F%90%E4%B8%AA%E7%89%88%E6%9C%AC%E7%9A%84%E5%8F%98%E6%9B%B4%E6%97%A5%E5%BF%97%E8%AE%B0%E5%BD%95)
    * [git diff &lt;branch 1&gt;\.\.\.&lt;branch 2&gt;比较第一个分支和第二个分支的不同](#git-diff-branch-1branch-2%E6%AF%94%E8%BE%83%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%88%86%E6%94%AF%E5%92%8C%E7%AC%AC%E4%BA%8C%E4%B8%AA%E5%88%86%E6%94%AF%E7%9A%84%E4%B8%8D%E5%90%8C)
  * [分支和标签/ Branches &amp; Tags](#%E5%88%86%E6%94%AF%E5%92%8C%E6%A0%87%E7%AD%BE-branches--tags)
    * [git branch 显示所有分支列表](#git-branch-%E6%98%BE%E7%A4%BA%E6%89%80%E6%9C%89%E5%88%86%E6%94%AF%E5%88%97%E8%A1%A8)
    * [git branch &lt;new\-branch&gt; 创建一个新的分支](#git-branch-new-branch-%E5%88%9B%E5%BB%BA%E4%B8%80%E4%B8%AA%E6%96%B0%E7%9A%84%E5%88%86%E6%94%AF)
    * [git branch \-d &lt;branch&gt; 删除分支](#git-branch--d-branch-%E5%88%A0%E9%99%A4%E5%88%86%E6%94%AF)
    * [git checkout &lt;branch&gt; 切换分支](#git-checkout-branch-%E5%88%87%E6%8D%A2%E5%88%86%E6%94%AF)
    * [git branch \-\-trick 将本地分支与远程分支同步](#git-branch---trick-%E5%B0%86%E6%9C%AC%E5%9C%B0%E5%88%86%E6%94%AF%E4%B8%8E%E8%BF%9C%E7%A8%8B%E5%88%86%E6%94%AF%E5%90%8C%E6%AD%A5)
    * [git tag 标签管理](#git-tag-%E6%A0%87%E7%AD%BE%E7%AE%A1%E7%90%86)
  * [合并和变基/ Merge &amp; Rebase](#%E5%90%88%E5%B9%B6%E5%92%8C%E5%8F%98%E5%9F%BA-merge--rebase)
    * [git merge 合并分支](#git-merge-%E5%90%88%E5%B9%B6%E5%88%86%E6%94%AF)
    * [git rebase &lt;branch&gt; 变更分支基线](#git-rebase-branch-%E5%8F%98%E6%9B%B4%E5%88%86%E6%94%AF%E5%9F%BA%E7%BA%BF)
    * [git rebase \-\-abort 变更分支基线](#git-rebase---abort-%E5%8F%98%E6%9B%B4%E5%88%86%E6%94%AF%E5%9F%BA%E7%BA%BF)
    * [git rebase \-\-continue 从基线历史版本回到最新版本](#git-rebase---continue-%E4%BB%8E%E5%9F%BA%E7%BA%BF%E5%8E%86%E5%8F%B2%E7%89%88%E6%9C%AC%E5%9B%9E%E5%88%B0%E6%9C%80%E6%96%B0%E7%89%88%E6%9C%AC)
  * [回退提交/ Undo Commit](#%E5%9B%9E%E9%80%80%E6%8F%90%E4%BA%A4-undo-commit)
    * [git reset &lt;commit\-id&gt;回退提交到仓库的版本](#git-reset-commit-id%E5%9B%9E%E9%80%80%E6%8F%90%E4%BA%A4%E5%88%B0%E4%BB%93%E5%BA%93%E7%9A%84%E7%89%88%E6%9C%AC)
    * [git reset \-\-hard &lt;commit\-d&gt;回退提交不留痕迹](#git-reset---hard-commit-d%E5%9B%9E%E9%80%80%E6%8F%90%E4%BA%A4%E4%B8%8D%E7%95%99%E7%97%95%E8%BF%B9)
    * [git checkout HEAD &lt;file&gt;切出当前分支最新文件版本](#git-checkout-head-file%E5%88%87%E5%87%BA%E5%BD%93%E5%89%8D%E5%88%86%E6%94%AF%E6%9C%80%E6%96%B0%E6%96%87%E4%BB%B6%E7%89%88%E6%9C%AC)
    * [git revert撤销某次操作，并保留历史记录](#git-revert%E6%92%A4%E9%94%80%E6%9F%90%E6%AC%A1%E6%93%8D%E4%BD%9C%E5%B9%B6%E4%BF%9D%E7%95%99%E5%8E%86%E5%8F%B2%E8%AE%B0%E5%BD%95)
    * [git revert HEAD \-m 撤退合并操作](#git-revert-head--m-%E6%92%A4%E9%80%80%E5%90%88%E5%B9%B6%E6%93%8D%E4%BD%9C)
  * [重构文件/Refactor Files](#%E9%87%8D%E6%9E%84%E6%96%87%E4%BB%B6refactor-files)
    * [git rm &lt;file&gt;删除仓库文件](#git-rm-file%E5%88%A0%E9%99%A4%E4%BB%93%E5%BA%93%E6%96%87%E4%BB%B6)
    * [git rm \-\-cached &lt;file&gt;删除暂存区的文件，保留到工作区](#git-rm---cached-file%E5%88%A0%E9%99%A4%E6%9A%82%E5%AD%98%E5%8C%BA%E7%9A%84%E6%96%87%E4%BB%B6%E4%BF%9D%E7%95%99%E5%88%B0%E5%B7%A5%E4%BD%9C%E5%8C%BA)
    * [git rm \-f &lt;file&gt;彻底删除暂存区的文件](#git-rm--f-file%E5%BD%BB%E5%BA%95%E5%88%A0%E9%99%A4%E6%9A%82%E5%AD%98%E5%8C%BA%E7%9A%84%E6%96%87%E4%BB%B6)
    * [git mv &lt;file\-orig&gt; &lt;file\-renamed&gt;移动文件并重命名](#git-mv-file-orig-file-renamed%E7%A7%BB%E5%8A%A8%E6%96%87%E4%BB%B6%E5%B9%B6%E9%87%8D%E5%91%BD%E5%90%8D)
  * [保存片段 / Save FrageMents](#%E4%BF%9D%E5%AD%98%E7%89%87%E6%AE%B5--save-fragements)
    * [git stash 备份仓库最近提交，并同步工作区](#git-stash-%E5%A4%87%E4%BB%BD%E4%BB%93%E5%BA%93%E6%9C%80%E8%BF%91%E6%8F%90%E4%BA%A4%E5%B9%B6%E5%90%8C%E6%AD%A5%E5%B7%A5%E4%BD%9C%E5%8C%BA)
    * [git stash list 查看所有备份](#git-stash-list-%E6%9F%A5%E7%9C%8B%E6%89%80%E6%9C%89%E5%A4%87%E4%BB%BD)
    * [git stash pop恢复备份历史记录](#git-stash-pop%E6%81%A2%E5%A4%8D%E5%A4%87%E4%BB%BD%E5%8E%86%E5%8F%B2%E8%AE%B0%E5%BD%95)
    * [git stash drop删除最近的备份历史记录](#git-stash-drop%E5%88%A0%E9%99%A4%E6%9C%80%E8%BF%91%E7%9A%84%E5%A4%87%E4%BB%BD%E5%8E%86%E5%8F%B2%E8%AE%B0%E5%BD%95)
    * [git stash show显示备份历史记录的文件跟踪对比情况](#git-stash-show%E6%98%BE%E7%A4%BA%E5%A4%87%E4%BB%BD%E5%8E%86%E5%8F%B2%E8%AE%B0%E5%BD%95%E7%9A%84%E6%96%87%E4%BB%B6%E8%B7%9F%E8%B8%AA%E5%AF%B9%E6%AF%94%E6%83%85%E5%86%B5)
    * [git stash apply应用指定节点历史备份记录](#git-stash-apply%E5%BA%94%E7%94%A8%E6%8C%87%E5%AE%9A%E8%8A%82%E7%82%B9%E5%8E%86%E5%8F%B2%E5%A4%87%E4%BB%BD%E8%AE%B0%E5%BD%95)
  * [更新和发布/ Update &amp; Publish](#%E6%9B%B4%E6%96%B0%E5%92%8C%E5%8F%91%E5%B8%83-update--publish)
    * [git remote 查看所有远程仓库主机](#git-remote-%E6%9F%A5%E7%9C%8B%E6%89%80%E6%9C%89%E8%BF%9C%E7%A8%8B%E4%BB%93%E5%BA%93%E4%B8%BB%E6%9C%BA)
    * [git remote show &lt;remote&gt; 查看远程仓库主机详细信息](#git-remote-show-remote-%E6%9F%A5%E7%9C%8B%E8%BF%9C%E7%A8%8B%E4%BB%93%E5%BA%93%E4%B8%BB%E6%9C%BA%E8%AF%A6%E7%BB%86%E4%BF%A1%E6%81%AF)
    * [git remote add &lt;shortname&gt; &lt;url&gt; 添加远程仓库](#git-remote-add-shortname-url-%E6%B7%BB%E5%8A%A0%E8%BF%9C%E7%A8%8B%E4%BB%93%E5%BA%93)
    * [git remote remove &lt;shortname&gt;删除远程仓库主机](#git-remote-remove-shortname%E5%88%A0%E9%99%A4%E8%BF%9C%E7%A8%8B%E4%BB%93%E5%BA%93%E4%B8%BB%E6%9C%BA)
    * [git fetch &lt;remote&gt; 拉取远程主机更新](#git-fetch-remote-%E6%8B%89%E5%8F%96%E8%BF%9C%E7%A8%8B%E4%B8%BB%E6%9C%BA%E6%9B%B4%E6%96%B0)
    * [git pull &lt;remote&gt; &lt;branch&gt;从远程分支拉取更新版本](#git-pull-remote-branch%E4%BB%8E%E8%BF%9C%E7%A8%8B%E5%88%86%E6%94%AF%E6%8B%89%E5%8F%96%E6%9B%B4%E6%96%B0%E7%89%88%E6%9C%AC)
    * [git push &lt;remote&gt; &lt;branch&gt; 推送版本到远程分支](#git-push-remote-branch-%E6%8E%A8%E9%80%81%E7%89%88%E6%9C%AC%E5%88%B0%E8%BF%9C%E7%A8%8B%E5%88%86%E6%94%AF)
    * [git branch \-dr &lt;remote/branch&gt; 删除远程仓库分支](#git-branch--dr-remotebranch-%E5%88%A0%E9%99%A4%E8%BF%9C%E7%A8%8B%E4%BB%93%E5%BA%93%E5%88%86%E6%94%AF)
    * [git push \-\-tags 发布标签](#git-push---tags-%E5%8F%91%E5%B8%83%E6%A0%87%E7%AD%BE)
* [4、Github 的使用](#4github-%E7%9A%84%E4%BD%BF%E7%94%A8)
  * [配置ssh key秘钥](#%E9%85%8D%E7%BD%AEssh-key%E7%A7%98%E9%92%A5)
    * [1、切换https协议到ssh](#1%E5%88%87%E6%8D%A2https%E5%8D%8F%E8%AE%AE%E5%88%B0ssh)
    * [2、生成个人ssh key，在git bash中键入命令](#2%E7%94%9F%E6%88%90%E4%B8%AA%E4%BA%BAssh-key%E5%9C%A8git-bash%E4%B8%AD%E9%94%AE%E5%85%A5%E5%91%BD%E4%BB%A4)
    * [3、配置key 到 ssh agent中](#3%E9%85%8D%E7%BD%AEkey-%E5%88%B0-ssh-agent%E4%B8%AD)
    * [4、配置config文件](#4%E9%85%8D%E7%BD%AEconfig%E6%96%87%E4%BB%B6)
    * [5、配置github的SSH keys公钥](#5%E9%85%8D%E7%BD%AEgithub%E7%9A%84ssh-keys%E5%85%AC%E9%92%A5)
    * [6、常见问题汇总](#6%E5%B8%B8%E8%A7%81%E9%97%AE%E9%A2%98%E6%B1%87%E6%80%BB)
* [参考资料](#%E5%8F%82%E8%80%83%E8%B5%84%E6%96%99)

# 1、Git简介

## Git 是什么？
> Git是一款免费、开源的分布式版本控制系统，用于敏捷高效地处理任何或大或小的项目版本管理。



## Git 的特点

>分布式相比于集中式的最大区别在于开发者可以提交到本地，每个开发者通过克隆（git clone），在本地机器上拷贝一个完整的Git仓库。



## Git 的功能特征

>1、从服务器上克隆完整的Git仓库（包括代码和版本信息）到单机上。<br/>
>2、在自己的机器上根据不同的开发目的，创建分支，修改代码。<br/>
>3、在单机上自己创建的分支上提交代码。<br/>
>4、在单机上合并分支。<br/>
>5、把服务器上最新版的代码fetch下来，然后跟自己的主分支合并。<br/>
>6、生成补丁（patch），把补丁发送给主开发者。<br/>
>7、看主开发者的反馈，如果主开发者发现两个一般开发者之间有冲突（他们之间可以合作解决的冲突），就会要求他们先解决冲突，然后再由其中一个人提交。如果主开发者可以自己解决，或者没有冲突，就通过。<br/>
>8、一般开发者之间解决冲突的方法，开发者之间可以使用pull 命令解决冲突，解决完冲突之后再向主开发者提交补丁。



## Git 的优缺点

**优点** 
> 分布式开发（安全、支持离线），强调个体（灵活、高效），主库坏掉了也不影响工作。

**缺点**
> 代码保密性差，一旦开发者把整个库克隆下来就可以完全公开所有代码和版本信息。



# 2、Git的安装

由于我这边的系统是Windows，这里我只介绍Windows平台上的安装。
> 早期Git是在Linux上开发的，很长一段时间内，Git也只能在Linux和Unix系统上使用。慢慢地有人把它移植到了Windows上。现在，Git可以在Linux、Unix、Mac和Windows这几大平台上正常运行了。



## 下载Git工具

速度很慢，可以去找其他可下载的地址，对应好自己的操作系统和系统位数

官方下载站点：https://git-for-windows.github.io/  <br/>
Git for Windows 下载站点：https://git-for-windows.github.io/  <br/>
更多版本下载：https://github.com/git-for-windows/build-extra/releases/latest <br/>

直接下载：[Windows Git-2.14.1-64 位](https://github.com/git-for-windows/git/releases/download/v2.14.1.windows.1/Git-2.14.1-64-bit.exe) <br/>

我下载安装的版本是**Git-2.8.1-64-bit**



## 安装Windows Git

双击运行一直下一步，直到看到这个步骤，选择Git命令行的使用方式，是GUI Bash还是Windows的Docs命令行窗口或是Windows下的Unix工具的命令行窗口。
一般选择第一个选项，Git GUI Bash就可以了，这个工具还是非常好用的，支持提示和快捷输入。
![git-install](F:\HandBook Document\Note\img\git-install.png)
最后一直下一步，直到完成。

==当然windows下操作git还有其他工具，如：cygwin。如果你喜欢话不妨试试，但我觉得上面的工具已经很够用了==



## 检查是否安装成功

安装成功完成后，启动快捷菜单中的 `Git`-> `Git Bash`后可以看到窗口，在窗口中输入命令：
```shell
$ git --version
```
如果输出内容如下，那就成功安装。否则请检查安装包文件跟系统是否对应和安装步骤是否有问题
```shell
git version 2.8.1.windows.1
```





# 3、Git常用命令

## 配置工具/ Configuration Tooling

- [x] Git支持配置一些全局的选项，就像客户端工具的设置功能一样。通过配置这些选项，可以定制不同的体验和用法，还有一些常规的选项，这些都是必须的配置。一般情况下安装好的git在用户目录下（C:\Users\Administrator）就会生成几个全局的配置文件。

      ```sh
      .bash_history
      .gitconfig
      .viminfo
      ```

      + 其中`.gitconfig`就是全局的配置文件，后面的`git config`命令都是操作这个文件的配置选项
      + `viminfo` 是vi编辑窗口的历史记录信息
      + `bash_history` 是我们在bash工具中的命令记录，每个操作记录都会缓存到这个文件

      ​

### 配置个人信息
Git安装完成后，需要设置个人信息，也就是版本提交人的基本资料，用来区分是谁做的版本变更，方便找到责任人。
```shell
$ git config --global user.name "Your Name"
$ git config --global user.email "email@example.com
```



### 配置文本编辑器

如果你不喜欢vi、vim编辑器可以配置你自己的编辑器
```shell
git config --global core.editor emacs
```
==注意`git config`命令的`--global`参数，用了这个参数，表示你这台机器上所有的Git仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和Email地址。==



### 查看当前配置
使用`git config --global --list`查看当前全局配置信息
```shell
git config --global --list
```
输出内容如下
```shell
$ git config --global --list
user.email=hoojo@qq.com
user.name=hoojo
color.ui=auto
```

查看当前仓库的个人配置信息 `git config --list`
```shell
$ git config --list
core.symlinks=false
core.autocrlf=true
core.fscache=true
color.diff=auto
color.status=auto
color.branch=auto
color.interactive=true
help.format=html
http.sslcainfo=E:/Git/mingw64/ssl/certs/ca-bundle.crt
diff.astextplain.textconv=astextplain
rebase.autosquash=true
credential.helper=manager
user.email=hoojo@qq.com
user.name=hoojo
color.ui=auto
core.repositoryformatversion=0
core.filemode=false
core.bare=false
core.logallrefupdates=true
core.symlinks=false
core.ignorecase=true
core.hidedotfiles=dotGitOnly
remote.origin.fetch=+refs/heads/*:refs/remotes/origin/*
```



### 配置命令别名

`git config --global alias` git的命令支持配置别名（短名称、简写）

***举个栗子***

```shell
###别名的配置也需要使用config命令，比如给 git status 设置别名 st：
git config --global alias.st status
```

> 这样我们以后使用的时候，直接用 git st 就可以做 git status 的事

```shell
##配置log日志的别名，以及格式化选项
git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
```

执行 git lg 的效果是这样的，惊不惊喜，意不意外？
![img](https://segmentfault.com/img/bVNtBq?w=442&h=298)

***举个栗子***

```shell
##对颜色选项进行配置
log --color --graph --pretty=format:'%C(bold red)%h%C(reset) - %C(bold green)(%cr)%C(bold blue)<%an>%C(reset) -%C(bold yellow)%d%C(reset) %s' --abbrev-commit
```

> 其中，
> %h 表示提交id；
> %cr 表示提交时间；
> %an 表示提交人；
> %d 表示 分支、tag、HEAD 等信息；
> %s 表示提交的信息。

效果如下：
![img](https://segmentfault.com/img/bVOGPf?w=683&h=463)



## 创建仓库/ Create Repositories

- [x] 仓库就是存储储备用的地方，这里的仓库

### `git clone`克隆一个存在的远程仓库

---

`git clone`
> 这个命令可以把远程服务器的git项目给下载到本地仓库

***示例如下***
```shell
git clone git@github.com:hooj0/xxxx.git
```

上面使用的是git协议，git获取远程仓库代码的协议还有以下几种：

* ssh://[user@]host.xz[:port]/path/to/repo.git/
* git://host.xz[:port]/path/to/repo.git/
* http[s]://host.xz[:port]/path/to/repo.git/
* ftp[s]://host.xz[:port]/path/to/repo.git/


具体使用何种协议和服务器端配置有关



### `git init`创建一个新的本地仓库

---

`git init`
> 创建一个本地的Git仓库，会在当前目录下初始化 `.git`子目录，在这个目录中存放git仓库是配置和版本跟踪信息。本地仓库所有的变更版本数据，缓存数据都会存在这个目录下。<br/>
> **注意**：这个目录中的文件是git仓库的数据文件，不能随便修改和删除，否则会破坏git的仓库数据

***示例如下***
```shell
$ cd workspace
$ mkdir gittest
$ pwd
/d/workspace/gittest
$ git init
Initialized empty Git repository in D:/workspace/gittest/.git/
```
在D盘下的workspace目录下创建一个`gittest`的目录，进入目录后执行`git init`，这样`gittest`就是被成功创建了一个git仓库。随后可以在这个仓库中增加文件或目录





## 本地修改 和 基本快照/ Local Changes & Basic Snapshotting

### `git status`查看本地工作目录变更修改记录

---

`git status`
> 查看本地仓库状态，如果没有修改记录，会显示干净的工作目录和分支一致。如果存在修改的记录，则提示提交。如果存在修改目录，又没有添加到暂存区就提示添加到暂存区。

***举个栗子***
> 当首次创建完仓库后，运行`git status`命令查看仓库状态
```shell
$ git status
On branch master
Initial commit
nothing to commit (create/copy files and use "git add" to track)
```

> 在gittest目录中创建一个文件后，运行`git status`命令查看仓库状态
```shell
$ git status
On branch master
Initial commit

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        readme.txt

nothing added to commit but untracked files present (use "git add" to track)
```
> 上面会看到一个看到`readme.txt`是没有放入暂存区的文件，提示使用`"git add <file>..."`添加该文档到暂存区

> 当把 `readme.txt`用`git add`添加到暂存区后，查看本地工作目录状态

```shell
$ git status
On branch master
Initial commit

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   readme.txt
        
##提示可以删除缓存中的文件在暂存区
```

> 修改曾经被提交过到仓库的文件，查看状态

```shell
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   readme.txt

no changes added to commit (use "git add" and/or "git commit -a")
#提示可以执行add添加到暂存区，也可以从新checkout服务器上的版本到工作目录

$ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        modified:   readme.txt
#将文件提交到暂存区后，可以通过reset进行回滚出暂存区
```



### `git status -s` 简版文件状态信息

---
`git status -s`
> 如果你觉得git status的内容太过冗余，你可以试试这个命令，它会减少内容的输出
> （M: 修改，??：新增，D：删除）
>
> 与此命令相同的还有一个命令就是：`git checkout` 它也可以显示版本差异情况，当然它不止这么点点用途，更多使用方法后面会慢慢提到。

***举个栗子***

```shell
#git status -s 可以查看简版的文件状态信息 （M: 修改，??：新增，D：删除）
$ git status -s
 M "2/2 dir.txt"
 M 2/temp.txt
 M FileInfo.java
 D foo.txt

## git checkout达到的效果是一样的 
 $  git checkout
M       2/2 dir.txt
M       2/temp.txt
M       FileInfo.java
D       foo.txt

## 效果同上
$  git checkout HEAD

```



### `git diff --staged`比较暂存区文件变更内容

---

`git diff --staged`

> 比较暂存区的文件，--staged 表示暂存区，显示变更的内容和版本信息

***举个栗子***

```shell
##创建一个文件readme.txt 添加到暂存区后，执行`diff --staged`命令
$ git add readme.txt
$ git diff --staged readme.txt
diff --git a/readme.txt b/readme.txt
new file mode 100644
index 0000000..4c9de27
--- /dev/null
+++ b/readme.txt
@@ -0,0 +1 @@
+this is first
\ No newline at end of file

#将暂存区的文件commit提交后，再执行比较会发现没有修改内容
$ git commit -m 'commit readme.txt'
$ git diff --staged readme.txt
```



### `git diff`比较文件变更内容

---

`git diff`

> 比较之前提交过到仓库的文件（即被跟踪过的文件），如果文件修改过内容，就显示变更的内容和版本信息<br/>
> （+ 表示新增加或编辑的内容，- 表示删除过的内容）

***举个栗子***

```shell
##创建一个文件readme.txt，提交到仓库后，对这个文件进行下一次修改后比较
$ git diff
diff --git a/readme.txt b/readme.txt
index 4c9de27..202ee0d 100644
--- a/readme.txt
+++ b/readme.txt
@@ -1 +1,2 @@
-this is first
\ No newline at end of file
+this is first
+add content
\ No newline at end of file

## （+ 表示新增加或编辑的内容，-表示删除过的内容）
$ git diff readme.txt
diff --git a/readme.txt b/readme.txt
index 5375821..1fb3b4e 100644
--- a/readme.txt
+++ b/readme.txt
@@ -1,4 +1,4 @@
+11111 new add
 this is first
-add content
 part 3 content
----------------hahaha
\ No newline at end of file
+-------#########--------hahaha
\ No newline at end of file
```



### `git add`添加所有文件到暂存区

---

`git add`

> 添加修改或者新文件到本地git仓库暂存区，相当于在本地有一个缓存存储，每一次修改可以单独添加到暂存区，也可以和其他修改一起提交到暂存区。<br/>
> `git add` 可以每次提交一个文件或多个文件，也可以是全部文件记录一次性提交到暂存区。
> 把每次分散的修改提交到暂存区后，就可以用`commit`一次性提交到本地仓库。

***举个栗子***

```shell
#1、新增文件file2.txt，修改仓库中文件file1.txt，执行git status
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        file2.txt

no changes added to commit (use "git add" and/or "git commit -a")

#2、将file1.txt 提交到暂存区
$ git add file1.txt

#3、查看文件状态
$ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        file2.txt

#4、不提交commit文件file1.txt ，继续再次修改file1.txt
$ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        modified:   file1.txt

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        file2.txt
#5、经过一番操作后发现file1.txt 即在暂存区也有在非暂存区，怎么会这样？
#其实这个是有两个版本的数据，暂存区存放的是上一个未有commit的file1.txt，而工作目录的是最新的。
#此时如果提交commit就只提交了上一次的版本数据，而最新修改的还在非暂存区
#此时若将非暂存区的file1.txt添加add 到暂存区将会合并到上一个版本
```

> `git add fiel1 file2` 或 `git add .`添加多个文件到暂存区

```shell
#1、多个待添加的文件记录
$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   file1.txt

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        file2.txt

no changes added to commit (use "git add" and/or "git commit -a")

#2、添加多个文件
$ git add file1.txt file2.txt

#3、成功添加到暂存区
$ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        modified:   file1.txt
        new file:   file2.txt
        
#3、添加当前目录下(包含子目录)的所有文件到暂存区        
$ git add .
```



### `git add -p <file>`添加文件部分内容到暂存区

---

`git add -p <file>`

> 添加文件的改动内容中的部分内容到暂存区，其他部分可以不添加到暂存区；前提是该文件之前已被添加到暂存区或者仓库，即已经被跟踪过版本的文件记录。<br/>
> 有时候我们修改一个文件，写了好几段代码，有些已经完成了，有些还未完成就写了一半或是不能编译。现在领导需要检查功能演示，这个时候不能不提交。但是不能回退，因为要演示好的功能，也不能让上级等。按照以前的做法就是把未完成的注释掉，然后提交代码编译运行。<br/>
> 而`git add -p`刚好就是针对这种情况，我们可以不注释掉代码，可以把写好的部分内容提交到暂存区，没有写好的可以选择不提交。
>
> 执行该目录后会出现这种选择操作，分别代码如下：
> Stage this hunk [y,n,q,a,d,/,s,e,?]
>
> * y 表示add到暂存区
> * n 表示不add到暂存区
> * q 退出当前操作
> * a 
> * d 退出或进入下一个文件
> * s 表示分块处理
> * e 表示编辑内容

***举个栗子***

```shell
###1、在一个文件的几个部分添加或删除内容或修改内容
### 执行 diff 查看变更内容发现
$ git diff stage.txt
diff --git a/stage.txt b/stage.txt
index 8dfe3fd..35a7210 100644
--- a/stage.txt
+++ b/stage.txt
@@ -1,8 +1,9 @@
 000000000000000000
-111111111111111111 #<这里是修改过>
+111111111AAAAAAAAA #<将后面的111，修改成AAA>
 222222222222222222
 333333333333333333
-444444444444444444 #<这里是删除整行>
+                   #<空行>
 555555555555555555
 666666666666666666
-777777777777777777 #<删除本行>
\ No newline at end of file
+777777777777777777
+ZZZZZZZZZZZZZZZZZZ #<这里是新增的>
\ No newline at end of file

###2、利用 git add -p stage.txt 来动态存储里面部分内容
$ git add -p stage.txt
diff --git a/stage.txt b/stage.txt
index 8dfe3fd..35a7210 100644
--- a/stage.txt
+++ b/stage.txt
@@ -1,8 +1,9 @@
 000000000000000000
-111111111111111111
+111111111AAAAAAAAA
 222222222222222222
 333333333333333333
-444444444444444444
+
 555555555555555555
 666666666666666666
-777777777777777777
\ No newline at end of file
+777777777777777777
+ZZZZZZZZZZZZZZZZZZ
\ No newline at end of file
Stage this hunk [y,n,q,a,d,/,s,e,?]? s #1 s 表示分块处理
Split into 3 hunks. #分成3块
@@ -1,4 +1,4 @@
 000000000000000000
-111111111111111111
+111111111AAAAAAAAA
 222222222222222222
 333333333333333333
Stage this hunk [y,n,q,a,d,/,j,J,g,e,?]? n #n 表示不缓存
@@ -3,5 +3,5 @@
 222222222222222222
 333333333333333333
-444444444444444444
+
 555555555555555555
 666666666666666666
Stage this hunk [y,n,q,a,d,/,K,J,g,e,?]? y #y 表示缓存
@@ -6,3 +6,6 @@
 555555555555555555
 666666666666666666
-777777777777777777
\ No newline at end of file
+777777777777777777
+ZZZZZZZZZZZZZZZZZZ
\ No newline at end of file
Stage this hunk [y,n,q,a,d,/,k,K,g,e,?]? y
```



### `git commit -a` 提交所有修改，不含新增

---

`git commit -a`

> 将之前已经提交过到分支的修改文件记录（已被跟踪过的文件）直接提交到分支，相当于git add 和 git commit 的组合版本，但这个文件不能是初次创建的文件。这样就减少了一个步骤，就不需要先add，再进行commit，真是省时省力。

***举个栗子***

```shell
#1、修改一个已经存在的文件，并且这个文件被提交到仓库，查看状态
$ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)
        modified:   readme.txt

#2、执行命令如下 git commit -a 就可以直接提交文件到仓库，可以减少git add 的步骤
$ git commit -a -m '直接提交修改的文件'
[master 30818bf] 直接提交修改的文件
 1 file changed, 3 insertions(+), 1 deletion(-)
 
#3、最终文件被成功提交到分支仓库
$ git status
On branch master
nothing to commit, working directory clean

##同样还可以这样写
$ git commit -am '也可以提交成功'
[master 21818ba] 直接提交修改的文件
 1 file changed, 3 insertions(+), 1 deletion(-)
```

> ***`git commit -a -m 'commit message' 可以简写 git commit -am 'commit message'`***



### `git commit` 提交暂存区所有修改内容

---

`git commit`

> 将暂存区的修改文件记录提交到仓库分支，这个操作就是提交操作了。之前的`git add`是提交到暂存区，而这个就是提交到本地仓库。每一个提交操作都会生成一个版本跟踪信息，记录版本提交时间、提交人、版本号、变更内容等

***举个栗子***

```shell
$ git commit -m 'commit readme.txt'
[master (root-commit) ca18b2f] commit readme.txt
 1 file changed, 1 insertion(+)
 create mode 100644 readme.txt

###上面执行commit命令后，可以看到提交的分支、版本号，并且告知1个文件修改，1个文件添加

$ git status
On branch master
nothing to commit, working directory clean
###最终文件被成功提交到分支仓库
```



### `git commit --amend`修改最后的提交

---

`git commit --amend`

> 修改最后一次的提交版本信息，当把暂存区的修改记录提交后，想重新对最后一次提交的记录进行提交或编辑提交的注释，可以使用这个命令。<br/>
> 修改后的注释内容会替换上一次提交的内容，并且在`git log`日志记录中不会出现上一次提交的日志，版本信息也会发生改变。<br/>
> 如果要看上一次提交的版本信息，当然也不是不可以。使用`git reflog`即可查看上一次提交日志记录。

***举个栗子***

```shell
##查看版本操作日志
$ git log
commit c6f9877eaace3f710908bd1574c4f7b3d2b6219a
Author: hoojo <hoojo@qq.com>
Date:   Fri Sep 1 21:05:47 2017 +0800

    commit modify

commit 7db59caad3b8ce489aa77b2f84bc69e38a704ae3
Author: hoojo <hoojo@qq.com>
Date:   Mon Aug 28 23:21:14 2017 +0800

    都提交

##执行最后一次版本信息变更操作，这个命令会弹出vi编辑窗口，这个时候我们就可以修改注释内容
##vi操作 insert键编辑/ESC退出搬家/:wq保存并退出
##将提交的注释变更为 “commit last modify”
$ git commit --amend
[master bc22454] commit last modify
 Date: Fri Sep 1 21:05:47 2017 +0800
 2 files changed, 4 insertions(+), 2 deletions(-)
 
 ##查看日志内容，上一次的日志不见了，版本号发生了改变
 $ git log
commit bc224545eaf7ce32614de2dca920beca1f6cd9d5
Author: hoojo <hoojo@qq.com>
Date:   Fri Sep 1 21:05:47 2017 +0800

    commit last modify

commit 7db59caad3b8ce489aa77b2f84bc69e38a704ae3
Author: hoojo <hoojo@qq.com>
Date:   Mon Aug 28 23:21:14 2017 +0800

    都提交

commit 311ce7908e2671ce3fb771664190f0696c5df2d4
Author: hoojo <hoojo@qq.com>
Date:   Mon Aug 28 23:21:00 2017 +0800

    都提交


##还可以修改作者，但前提是该作者email要在仓库中提交过版本
$ git commit --amend --author=hoojo2@qq.com
fatal: --author 'hoojo2@qq.com' is not 'Name <email>' and matches no existing author
```



### `git commit --amend | git rebase` 修改以前历史任意版本信息

---

`git commit --amend  + git rebase`

> 上面使用`git commit --amend`可以修改最后次提交的版本信息，但如果要修改前几次或是很久前的版本信息呢？
>
> 可以如下做法：<br/>
> 1、可以使用`git rebase`做版本变基，找到要修改的版本。<br/>
> 2、弹出vi编辑窗口后，将要修改的版本的pick修改成edit。保存并退出，**这时我们的当前版本就回到了历史版本**<br/>
> 3、执行 `git commit --amend` 修改历史当前版本注释<br/>
> 4、保存并退出，注释修改完毕<br/>
> 5、回到最新版本 `git rebase --continue`

***举个栗子***

```shell
##找到前5个历史版本，会弹出vi编辑框，选择要变更的版本;
$ git rebase -i master~5
--------------vi-------------------
pick f167b82 add ex file
pick 5866aef 全部提交，包括新增的文件和目录
edit ed70d9e 都提交       ###将这个版本标记为当前版本 pick修改为edit
pick aa01a90 都提交
pick b4a7b68 commit last modify
---------------vi-------------------
###保存并退出，会显示如下内容
Stopped at ed70d9e95a492177eafb7ca23bac3e09fae03542... 都提交
You can amend the commit now, with
        git commit --amend
Once you are satisfied with your changes, run
        git rebase --continue
        
JojO@JojO-PC MINGW64 /d/workspace/gittest (master|REBASE-i 3/5)
###退出后会发现我们从master变成了历史的倒数第三个版本 (master|REBASE-i 3/5)

##执行 git commit --amend，和之前一样变更下注释，保存并退出vi；
$ git commit --amend
[detached HEAD 05b9eab] 不再是都提交，而是被修改
 Date: Mon Aug 28 23:21:00 2017 +0800
 2 files changed, 5 insertions(+), 4 deletions(-)
 delete mode 100644 file2.txt

##退出后我们还在 (master|REBASE-i 3/5) 历史版本中，不过注释已被修改
$ git log
commit 05b9eab93f3c7fc5184063bd98157ba46847dc20
Author: hoojo <hoojo@qq.com>
Date:   Mon Aug 28 23:21:00 2017 +0800

    不再是都提交，而是被修改

commit 5866aef279767bdea2bdb82ae984de5adc517f1f
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 22:13:32 2017 +0800

    全部提交，包括新增的文件和目录

commit f167b82a38ac0f5900d30e2ad18d39e8e949a459
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 19:41:03 2017 +0800

    add ex file

##git rebase --continue 回到最新的历史版本
$ git rebase --continue
Successfully rebased and updated refs/heads/master.

##这样就回到最新版本，查看下日志，历史版本日志注释被成功修改
$ git log
commit 82c9452b075339106bb307481258d4b8699803a5
Author: hoojo <hoojo@qq.com>
Date:   Fri Sep 1 21:05:47 2017 +0800
    commit last modify

commit d0d1ef7498a243f26252e01787e3966df80c73e4
Author: hoojo <hoojo@qq.com>
Date:   Mon Aug 28 23:21:14 2017 +0800
    都提交

commit 05b9eab93f3c7fc5184063bd98157ba46847dc20
Author: hoojo <hoojo@qq.com>
Date:   Mon Aug 28 23:21:00 2017 +0800
    不再是都提交，而是被修改  ---------------------这里注释被修改了

commit 5866aef279767bdea2bdb82ae984de5adc517f1f
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 22:13:32 2017 +0800
    全部提交，包括新增的文件和目录

commit f167b82a38ac0f5900d30e2ad18d39e8e949a459
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 19:41:03 2017 +0800
    add ex file   
```



### `git reset`重置暂存区的修改记录

---

`git rest`

> 1、如果add了修改记录，又不想添加到暂存区，可以用这个命令进行重置回滚，这样就变成了工作区的记录。相当于没有执行`git add`操作。<br/>
> 2、当更新或提交的版本是有bug的，想要回退到历史的某个版本，也可以用这个命令。

***举个栗子***

```shell
#1、重置文件到非暂存区，若不带HEAD则回滚上一次 add 的文件记录
$ git reset HEAD readme.txt
Unstaged changes after reset:
M       readme.txt

#2、重置所有暂存区文件到非暂存区
$ git reset
Unstaged changes after reset:
M       readme.txt
M       stage.txt

#3、回退某个暂存区的文件记录
$ git reset readme.txt
Unstaged changes after reset:
M       readme.txt
```

> **关于历史版本的回退将在后面会重点介绍**





##  预览历史/ Review History

### `git log` 查看提交日志

---

`git log`
> 1、查看文件的提交到仓库分支的日志信息，日志包含提交版本、时间、作者、注释内容<br/>
> 2、如果日志版本信息很多，要看最后N个版本的日志，可以带参数 `git log -n` n 表示最后版本数<br/>
> 3、如果觉得日志信息太多，可以用`--pretty=oneline` 会让日志显示更简单。<br/>
> 4、如果要看跟踪版本合并情况，可以用`--graph`<br/>
> 5、版本id看起来比较长，也可以显示短的版本id，可以用`--abbrev-commit`

***举个栗子***
```shell
## 查看日志信息
$ git log
commit 82c9452b075339106bb307481258d4b8699803a5
Author: hoojo <hoojo@qq.com>
Date:   Fri Sep 1 21:05:47 2017 +0800
    commit last modify

commit d0d1ef7498a243f26252e01787e3966df80c73e4
Author: hoojo <hoojo@qq.com>
Date:   Mon Aug 28 23:21:14 2017 +0800
    都提交
    
## 只显示最后2个版本
$ git log -2
commit 82c9452b075339106bb307481258d4b8699803a5
Author: hoojo <hoojo@qq.com>
Date:   Fri Sep 1 21:05:47 2017 +0800
    commit last modify
    
##如果觉得上面的日志内容很多，可以用--pretty=oneline来看简写的内容版本
$ git log --pretty=oneline
c1224d54f12af239059cf387cad50b32e8a2c39f new foo data
3359d98ac41eb94bc27d9a8e668326af295156a8 new foo
b5c4f4ae6b9fbfaad1fd4623e501cde5d08a6c45 dev commit
9fa621dcac87186363e0cfb0c0b3478c87357c5a dev commit
cdab573523df349534c4239f9761ef2449c92538 rebase commit

### 可以看到版本合并分支记录
$ git log --pretty=oneline --graph
* c1224d54f12af239059cf387cad50b32e8a2c39f new foo data
* 3359d98ac41eb94bc27d9a8e668326af295156a8 new foo
* b5c4f4ae6b9fbfaad1fd4623e501cde5d08a6c45 dev commit
* 9fa621dcac87186363e0cfb0c0b3478c87357c5a dev commit
* cdab573523df349534c4239f9761ef2449c92538 rebase commit
* bd33df7486f27327c3a560bdc20da7eee6d37f17 ......
* eaa2e222cac8af0e12edbb87c1e9232576dcf560 dev commit
*   e8f064e5e99518d604592668dbc73268fd19f7ff Merge branch 'dev'
|\
| * f499424f2464e7c96eb0248f905d4162d0017147 first dev branch commit
* | 184edb0874e601609e4e6d959f052d4da987cb07 master commit
|/
* 82c9452b075339106bb307481258d4b8699803a5 commit last modify

###查看日志让id不那么长
$ git log --pretty=oneline --graph --abbrev-commit
* c1224d5 new foo data
* 3359d98 new foo
* b5c4f4a dev commit
* 9fa621d dev commit
* cdab573 rebase commit
* bd33df7 ......
* eaa2e22 dev commit
*   e8f064e Merge branch 'dev'
|\
| * f499424 first dev branch commit
* | 184edb0 master commit
|/
* 82c9452 commit last modify
```



### `git log --follow <file>` 跟踪指定文件的版本日志

---

`git log --follow <file>`
> 可以指定文件，只看当前文件的版本日志信息，包括作者、日期、版本、注释等

***举个栗子***
```shell
$ git log --follow file1.txt
commit 5866aef279767bdea2bdb82ae984de5adc517f1f
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 22:13:32 2017 +0800

    全部提交，包括新增的文件和目录

commit f167b82a38ac0f5900d30e2ad18d39e8e949a459
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 19:41:03 2017 +0800

    add ex file

commit 857a447eb3dcc8b999b532003f2b7e31ef2bbfd6
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 19:36:38 2017 +0800

    add file1 commit stage
```



### `git log -p <file>` 查看指定文件提交版本日志、变更内容

---

`git log -p <file>`
> 这个命令是针对文件的版本日志，并且显示每次提交版本的修改内容

***举个栗子***
```shell
$ git log -p FileInfo.java
commit f167b82a38ac0f5900d30e2ad18d39e8e949a459
Author: hoojo <hoojo@qq.com>
Date:   Sun Aug 27 19:41:03 2017 +0800

    add ex file

diff --git a/FileInfo.java b/FileInfo.java
new file mode 100644
index 0000000..b6fc4c6
--- /dev/null
+++ b/FileInfo.java
@@ -0,0 +1 @@
+hello
\ No newline at end of file
```



### `git reflog` 查看操作日志

---

`git reflog`
> 任何操作都会在这里留下痕迹，`-n`查看最后的几个版本

***举个栗子***
```shell
$ git reflog
c1224d5 HEAD@{0}: commit: new foo data
3359d98 HEAD@{1}: commit: new foo
b5c4f4a HEAD@{2}: reset: moving to b5c4f4a
2eb0cfb HEAD@{3}: checkout: moving from test-dev to dev
546be65 HEAD@{4}: commit: ddddddd
96da980 HEAD@{5}: commit (amend): 3ljlsdf..

###如果版本数据太多，可以带数量显示最后的n个版本
$ git reflog -3
c1224d5 HEAD@{0}: commit: new foo data
3359d98 HEAD@{1}: commit: new foo
b5c4f4a HEAD@{2}: reset: moving to b5c4f4a
```



### `git blame`查看内容变更者和时间、版本

---

`git blame`
> 查看文件的内容是由谁变更修改的，显示更改日期、提交的版本号，谁动了我的文件一目了然。

***举个栗子***

```shell
## 每一行都有信息跟踪
$ git blame file1.txt
af4a6435 (hoojo 2017-08-27 19:35:42 +0800 1) file 1
857a447e (hoojo 2017-08-27 19:36:38 +0800 2) new line content
f167b82a (hoojo 2017-08-27 19:41:03 +0800 3) 2 add line
f167b82a (hoojo 2017-08-27 19:41:03 +0800 4) 3 add line
```



### `git show <commit-id>` 查看某个版本的变更日志记录

---

`git show <commit-id>`
> `git log` 是针对文件或分支的变更日志，而 git show可以查看某个具体版本的变更记录内容

***举个栗子***
```shell
###先找到要查看的版本id
$ git reflog
eaa2e22 HEAD@{0}: commit: dev commit
f499424 HEAD@{8}: commit: first dev branch commit
82c9452 HEAD@{9}: checkout: moving from master to dev
82c9452 HEAD@{10}: rebase -i (finish): returning to refs/heads/master
82c9452 HEAD@{11}: rebase -i (pick): commit last modify
d0d1ef7 HEAD@{12}: rebase -i (pick): 都提交

###查看具体版本的变更记录日志
$ git show eaa2e22
commit eaa2e222cac8af0e12edbb87c1e9232576dcf560
Author: hoojo <hoojo@qq.com>
Date:   Sat Sep 2 12:21:59 2017 +0800

    dev commit

diff --git a/FileInfo.java b/FileInfo.java
index b6fc4c6..b0c780a 100644
--- a/FileInfo.java
+++ b/FileInfo.java
@@ -1 +1,2 @@
-hello
\ No newline at end of file
+hello
+dev..dev..
\ No newline at end of file
```



### `git diff <branch 1>...<branch 2>`比较第一个分支和第二个分支的不同

---

`git diff <branch 1>...<branch 2>`
> 比较前者分支与后者分支存在的不同，只显示前者比后者存在的变更内容。也就是说前者在后者的基础上存在什么文件内容不同；相反，如果调换前者和后者的位置，会看到一个相反的比较，所以参照物以后者为准。

***举个栗子***
```shell
###有两个分支 master和dev，它们是一模一样的内容。现在在dev分支上变更一个文件内容并提交到分支dev，做出分支比较
$ git diff master...dev
diff --git a/FileInfo.java b/FileInfo.java
index b6fc4c6..b0c780a 100644
--- a/FileInfo.java
+++ b/FileInfo.java
@@ -1 +1,2 @@
-hello
\ No newline at end of file
+hello
+dev..dev..
\ No newline at end of file

###可以看到差距，相反用dev和master比较将会没有差别，这是dev是最新的分支版本
$ git diff dev...master
```





## 分支和标签/ Branches & Tags

- [x] 分支的意思就是一个独立的版本枝干，相当于SVN中的基线，当前分支的所有操作和其他分支互不干扰。在实际开发中，一个项目可能存在很多分支，比如开发分支、测试分支、BUG修复分支、准线上分支、正式线上分支等等，每个分支都不影响，它们可以在每个不同阶段进行合并拆分，方便协调工作。
- [x] 标签是一个标记，用来做一个记号，方便日后找到具体版本而不用记住版本号等信息



### `git branch` 显示所有分支列表

---

`git branch`

> 1、`git branch`显示当前仓库所有分支，以列表的形式显示。当前所在分支会以绿色并且带 * 高亮显示<br/>
> 2、`git branch --av` 分支显示信息会比上面1的显示多出版本信息和最后次的操作信息

***举个栗子***

```shell
## 查看所有分支， dev 为当前分支
$ git branch
* dev
  master
  
## 查看分支的版本信息，包括最后一次的git操作指令
$ git branch -av
* dev    eaa2e22 dev commit
  master e8f064e Merge branch 'dev'
```



### `git branch <new-branch>` 创建一个新的分支

---

`git branch <new-branch>`

> 在当前仓库创建一个新的分支

***举个栗子***

```shell
##创建一个叫dev的分支
$ git branch dev

##创建一个指定当前分支版本的分支
$ git branch local_dev aa1ecb3
## local_dev 是新分支名称，aa1ecb3是当前dev分支的一个版本
```



### `git branch -d <branch>` 删除分支

---

`git branch -d <branch>`

> 删除分支操作，既然能创建分支，也可以删除分支。

***举个栗子***

```shell
##1、创建一个叫 test 的分支
$ git branch test
##2、查看分支
$ git branch
* dev
  master
  test
##3、删除刚刚创建的 test 分支
$ git branch -d test
Deleted branch test (was eaa2e22).
##4、再次查看分支 test 被删除
$ git branch
* dev
  master

```



### `git checkout <branch>` 切换分支

---

`git checkout <branch>`

> 从当前分支切换到另一个分支，做一些版本变更操作

***举个栗子***

```shell
#1、查看当前所在分支
$ git branch
* dev
  master
#2、切换到 master分支
$ git checkout master
Switched to branch 'master'
#3、再次查看当前分支已经变更为master
$ git branch
  dev
* master

```



### `git branch --trick` 将本地分支与远程分支同步

---

`git branch --trick`

> 相当于把远程分支checkout到本地，执行此命令会创建一个分支，该分支版本数据和远程分支保持一致

***举个栗子***

```shell
## 创建一个本地分支local-dev 与远程分支 dev保持一致
$ git branch --track local-dev origin/dev
```



### `git tag` 标签管理

---

`git tag`

> 可以给分支的当前版本定义标签，方便找到具体的版本。在经常更新发布的系统中，定义标签可以快速定位到具体的版本。

***举个栗子***

```shell
##1、查看已有的标签
$ git tag
v1.0
v1.1
##2、定义版本标签
$ git tag v1.2
##3、模糊匹配标签
$ git tag -l 'v1.*'
v1.0
v1.0.1
v1.2
v1.3

##4、切换到某个标签版本
$ git checkout v1.2
Note: checking out 'v1.2'.

admin@hoojo-PC MINGW64 /d/workspace/gittest ((v1.2))
## 可以看到切换到v1.2的标签分支

## 给某个commit-id 打标签
$ git tag -a v1.0.1 05b9eab

## 删除标签
$ git tag -d v1.1
Deleted tag 'v1.1' (was eaa2e22)

##创建附注标签，带有注释说明的标签
$ git tag -a v1.4 -m 'new version'

##查看标签标注信息
$ git tag -n
v1.0            dev commit
v1.0.1          commit tag version
v1.2            dev commit
v1.3            new commit
v1.4            new version
```





## 合并和变基/ Merge & Rebase

- [x] 合并分支，当前开发分支发生版本变更后，会与其他测试分支或线上分支进行合并，以保持其他分支是最新的分支

- [x] 改变基线，有时候需要从当前版本切换到历史的某一个版本，进行历史记录的更新或是内容的更新



### `git merge` 合并分支

---

`git merge`
> 将当前分支和某一个分支进行合并，保持两个分支版本达到最新的版本数据

***举个栗子***

```shell
## 当前分支在master，将当前分支和dev分支进行合并
$ git merge dev
Merge made by the 'recursive' strategy.
 FileInfo.java | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)
```



### `git rebase <branch>` 变更分支基线

---

`git rebase <branch>`

> 变更分支基线会把分支的版本合并到当前分支上

***举个栗子***

```shell
#1、修改master分支文件file1.txt，并提交
$ git commit -am 'master commit'
#2、切换到dev分支
$ git checkout dev
#3、修改dev分支file2.txt，并提交
$ git commit -am 'dev commit'

##4、当前在dev分支上，master分支和本地分支
$ git rebase master
First, rewinding head to replay your work on top of it...
Applying: dev commit
###结果会发现master分支上的修改被同步到dev上
```



### `git rebase --abort` 变更分支基线

---

`git rebase --abort`

> 中断当前rebase操作，回到rebase变更基线操作之前的状态，相当于没有做rebase操作

***举个栗子***

```shell
$ git rebase --abort
```



### `git rebase --continue` 从基线历史版本回到最新版本

---

`git rebase --continue`

> 从rebase操作历史版本中，回到最新的版本，在前面的`git commit --amend`指令中已经有介绍

***举个栗子***

```shell
$ git rebase --continue
```





## 回退提交/ Undo Commit

- [x] Git的后悔药，可以撤销某一次的版本提交。上面已经介绍过在暂存区使用reset可以将暂存区提交的版本变更到工作区，这里将介绍在仓库中进行后退版本。
- [x] `reset`和`revert`后面会使用到这两个命令，它们的区别在于reset是把回退版本后提交的操作删除，相当于指定版本后的操作没有发生原因；而revert则是保留回退版本操作后的操作，再把回退版本的内容重新提交一遍，覆盖掉之前的版本内容。简单的来说，reset是版本的**后退**操作，而revert则是版本的**前进**。




### `git reset <commit-id>`回退提交到仓库的版本

---

`git reset <commit-id>`

> 将某一次的提交版本变更回退到提交前的状态

***举个栗子***

```shell
##回退版本
$ git reset b5c4f4a
Unstaged changes after reset:
M       2/temp.txt

# 回退版本后查看status，有一个文件没有提交
$ git status -s
 M 2/temp.txt
```



### `git reset --hard <commit-d> `回退提交不留痕迹

---

`git reset --hard <commit-d>`

> 当我们有时候错误的把不需要提交的版本文件提交到仓库后，若想后退到某个版本，可以使用该指令。但它不在日志里面留下痕迹，后退完成后在这个版本后的提交都无法查看到日志信息。当然你可以通过`git reflog`去查找版本记录。
>
> `git reset --hard HEAD`重置到当前版本，在git中`HEAD`是指向当前版本的一个指针，用`HEAD`表示当前版本，也就是最新的提交`3628164...882e1e0`（注意我的提交ID和你的肯定不一样），上一个版本就是`HEAD^`，上上一个版本就是`HEAD^^`，当然往上100个版本写100个`^`比较容易数不过来，所以写成`HEAD~100`。

***举个栗子***

```shell
##创建一个新文件
$ touch foo.txt
$ git add .
$ git commit -am 'new foo'
$ echo 'new foo data' >> foo.txt
$ git commit -am 'new foo'

##查看最后3个版本的日志记录
$ git log -3
commit c1224d54f12af239059cf387cad50b32e8a2c39f
Author: hoojo <hoojo@qq.com>
Date:   Sat Sep 2 22:52:57 2017 +0800

    new foo data

commit 3359d98ac41eb94bc27d9a8e668326af295156a8
Author: hoojo <hoojo@qq.com>
Date:   Sat Sep 2 22:51:58 2017 +0800

    new foo

commit b5c4f4ae6b9fbfaad1fd4623e501cde5d08a6c45
Author: hoojo <hoojo@qq.com>
Date:   Sat Sep 2 21:28:11 2017 +0800

    dev commit


###回退到b5c4f4a版本
$ git reset --hard b5c4f4a
HEAD is now at b5c4f4a dev commit

##再次查看日志发现之前提交的版本日志都不见了，之前的操作文件也不在
$ git log -3
commit b5c4f4ae6b9fbfaad1fd4623e501cde5d08a6c45
Author: hoojo <hoojo@qq.com>
Date:   Sat Sep 2 21:28:11 2017 +0800

    dev commit

commit 9fa621dcac87186363e0cfb0c0b3478c87357c5a
Author: hoojo <hoojo@qq.com>
Date:   Sat Sep 2 21:19:58 2017 +0800

    dev commit

commit cdab573523df349534c4239f9761ef2449c92538
Author: hoojo <hoojo@qq.com>
Date:   Sat Sep 2 21:17:47 2017 +0800

    rebase commit

##查看日志版本
$ git reflog -5
b5c4f4a HEAD@{0}: reset: moving to b5c4f4a
c1224d5 HEAD@{1}: commit: new foo data
3359d98 HEAD@{2}: commit: new foo
b5c4f4a HEAD@{3}: reset: moving to b5c4f4a
2eb0cfb HEAD@{4}: checkout: moving from test-dev to dev

##再次回退到版本后，发现文件和日志都恢复
$ git reset --hard c1224d5
HEAD is now at c1224d5 new foo data
```

> `git reset --hard HEAD`重置到当前版本

```shell
## 回滚到当前版本
$ git reset --hard HEAD
## 回到上一个版本
$ git reset --hard HEAD^
```



### `git checkout HEAD <file>`切出当前分支最新文件版本

---

`git checkout HEAD <file>`

> 1、会从当前分支最新版本中切出指定文件，来覆盖工作空间和暂存区的文件
>
> 2、从指定分支上切出文件覆盖当前分支文件，包括当前分支暂存区和工作区

***举个栗子***

```shell
##1、在File2.java文件中写入新内容
$ echo 'checkout file' >> File2.java
##2、查看文件
$ cat File2.java
file2 java
new date row now
OMGGGGGGGGGGGGGGGGGGGGG
hahahahhacheckout file
##3、添加到暂存区
$ git add File2.java
##4、查看状态，文件已被修改
$ git status -s
M  File2.java
##5、切出仓库中的File2.java
$ git checkout HEAD File2.java
##6、再次查看，之前新增的内容不见了
$ cat File2.java
file2 java
new date row now
OMGGGGGGGGGGGGGGGGGGGGG
hahahahha
##7、再次查看状态，没有需要新的状态版本
$ git status -s

###以上操作就说明git checkout HEAD File2.java 会覆盖我们工作区和暂存区的文件记录
```

***举个栗子***

```shell
##从master主干分支上切出File2.java
$ git checkout master File2.java
##查看文件内容，发现比之前的少一行数据
$ cat File2.java
file2 java
new date row now
OMGGGGGGGGGGGGGGGGGGGGG
```



### `git revert`撤销某次操作，并保留历史记录

---

`git revert`

> `git revert` 撤销某次操作，此次操作之前和之后的commit和history都会保留，并且把这次撤销
> 作为一次最新的提交。
>
> `git revert HEAD --no-edit` 撤销操作，且不编辑注释

***举个栗子***

```shell
##显示最近几条操作记录
$ git log -5
commit 4086522568122e128c105dc44f325ad2cc2b84fc
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 16:10:10 2017 +0800
    ..

commit 22e53c05884b26122aa68db89525637e8ce22cea
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 15:30:58 2017 +0800
    commit2

##执行revert操作，会让你编辑注释
$ git revert HEAD
###再次查看日志，发现在之前的基础上有了新的提交操作
$ git log -5
commit a9f11ec84d8136eff07fb33c7457d1b5f25d548d
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 16:10:19 2017 +0800
    Revert ".." go back
    This reverts commit 4086522568122e128c105dc44f325ad2cc2b84fc.

commit 4086522568122e128c105dc44f325ad2cc2b84fc
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 16:10:10 2017 +0800
    ..
```

***举个栗子***

```shell
##1、带要回滚的版本号进行回滚操作
$ git revert 9a9870e
[dev da719ed] Revert "roll back"
 1 file changed, 0 insertions(+), 0 deletions(-)
 delete mode 100644 foo.txt

##2、回滚，不编辑注释
$ git revert HEAD --no-edit
[local_dev ad689ba] Revert "提交"
 1 file changed, 1 deletion(-)
```



### `git revert HEAD -m` 撤退合并操作

---

`git revert HEAD -m`

> 当一个revert操作涉及到分支合并撤退的就会失败，需要增加额外参数-m来设置回退哪个分支版本。

***举个栗子***

```shell
$ git log -5
commit 8625ff6e7f191a712273c29292154b18671e4d22
Merge: ad689ba (1) da719ed (2)          #####这里是一个分支合并的操作日志###
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 18:06:22 2017 +0800
    合并

commit ad689ba3e9ee5b00b058391800df892577378e9e (=1)
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 17:28:46 2017 +0800
    Revert "提交"

    This reverts commit 7834a80e9aa58410066d40aa1ba76544713910b0.

commit 7834a80e9aa58410066d40aa1ba76544713910b0
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 17:28:23 2017 +0800
    提交

commit da719edb61ccb8ead3d6298470f0d0a417c5c5fc (=2)
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 16:21:14 2017 +0800
    Revert "roll back"

    This reverts commit 9a9870ec76bf96204186970c1bdd9bf9eeb6cd6c.

commit 9a9870ec76bf96204186970c1bdd9bf9eeb6cd6c
Author: hoojo <hoojo@qq.com>
Date:   Sun Sep 3 16:19:01 2017 +0800
    ..

##git revert回退发现失败，需要配置-m来选择回退到哪个版本
$ git revert 8625ff6e7f191a712273c29292154b18671e4d22
error: Commit 8625ff6e7f191a712273c29292154b18671e4d22 is a merge but no -m option was given.
fatal: revert failed

## revert 配置-m 2 撤退成功
##-m 2 代表日志中 8625ff6e7f191a712273c29292154b18671e4d22 的Merge: ad689ba da719ed 的（da719ed）版本，而-m 1 则是（ad689ba）;回顾下上面的git log日志看看就知道。
## -m 参数只有1和2
$ git revert 8625ff6e7f191a712273c29292154b18671e4d22 -m 2
[local_dev 5582a97] Revert "撤退合并" back commit
 2 files changed, 2 insertions(+), 12 deletions(-)
```





## 重构文件/Refactor Files

### `git rm <file>`删除仓库文件

---

`git rm <file>`
>删除文件会将文件从仓库移动到暂存区，执行commit后文件才被完全移除。同时工作区也不会存在删除文件的记录。当一个文件在工作区或者暂存区没有添加到仓库，将不能被移除。只有完整提交到仓库，没有被修改过的文件才能执行此操作。

***举个栗子***

```shell
### 删除仓库中的new.txt
$ git rm new.txt
rm 'new.txt'

### 查看状态，发现在暂存区了，已经被删除
$ git status
On branch local_dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        deleted:    new.txt

###若继续删除的话会出现
$ git rm new.txt
fatal: pathspec 'new.txt' did not match any files

$ git rm new.txt
error: the following file has changes staged in the index:
    new.txt
(use --cached to keep the file, or -f to force removal)

```



### `git rm --cached <file>`删除暂存区的文件，保留到工作区

---

`git rm --cached <file>`

> 会将暂存区的文件删除掉，被删除的文件进入到工作区变成未`git add`之前的状态。

***举个栗子***

```shell
##创建一个新文件，并且add到暂存区，查看状态
$ git status
On branch local_dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        new file:   a..txt

## 执行 git rm --cached 删除暂存区刚刚 add 的文件
$ git rm --cached a..txt
rm 'a..txt'

### 文件又回到当初的工作区
$ git status
On branch local_dev
Untracked files:
  (use "git add <file>..." to include in what will be committed)

        a..txt
```



### `git rm -f <file>`彻底删除暂存区的文件

---

`git rm -f <file>`

> 会将暂存区的文件彻底删除掉，不会有其他状态。

***举个栗子***

```shell
##创建一个新文件，并且add到暂存区，查看状态
$ git status
On branch local_dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        new file:   a.txt

## 执行 git rm --cached 删除暂存区刚刚 add 的文件
$ git rm -f a.txt
rm 'a.txt'

### 文件又回到当初的工作区
$ git status
On branch local_dev
nothing to commit, working directory clean
```



### `git mv <file-orig> <file-renamed>`移动文件并重命名

---

`git mv <file-orig> <file-renamed>`

> 移动并重命名被版本跟踪过的文件，新建的文件不能被操作。

***举个栗子***

```shell
##创建一个新文件,不被版本控制，操作失败
$ git mv too.txt foo.txt
fatal: not under version control, source=too.txt, destination=foo.txt

##add到暂存区，查看状态
$ git status
On branch local_dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        new file:   too.txt

## 移动重命名
$ git mv too.txt foo.txt

## 查看状态发现被重命名成功
$ git status
On branch local_dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        renamed:    too.txt -> foo.txt
```





## 保存片段 / Save FrageMents

### `git stash` 备份仓库最近提交，并同步工作区

---

`git stash`

> 备份当前工作区的内容，从最近一次提交中读取内容，让工作区和上次提交的内容保持一致，并且将备份的内容版本记录下来，方便后面从备份记录中恢复变更又未提交的版本。
>
> 注意：它会忽略工作区和暂存区中的修改记录，用最近一次提交的仓库数据替换或覆盖掉工作区、暂存区内容。但同时你又可以从备份的历史中恢复记录。

***举个栗子***

```shell
## 1、向file1.txt写入内容
$ echo 'hello world' >> file1.txt
## 2、查看状态，有变更数据
$ git status
On branch dev
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)
        modified:   file1.txt

## 3、执行备份
$ git stash
The file will have its original line endings in your working directory.
Saved working directory and index state WIP on dev: da719ed Revert "roll back"
HEAD is now at da719ed Revert "roll back"

## 4、刚才的变更版本不见
$ git status
On branch dev
nothing to commit, working directory clean

```



### `git stash list` 查看所有备份

---

`git stash list` 

> 显示所有备份操作历史版本，并且可以利用历史中版本决定恢复的位置

***举个栗子***

```shell
$ git stash list
stash@{0}: WIP on dev: 16289de new change
stash@{1}: WIP on dev: 16289de new change
stash@{2}: WIP on dev: 16289de new change
stash@{3}: WIP on dev: 16289de new change
stash@{4}: WIP on dev: da719ed Revert "roll back"
stash@{5}: WIP on dev: da719ed Revert "roll back"
stash@{6}: WIP on dev: da719ed Revert "roll back"
```



### `git stash pop `恢复备份历史记录

---

`git stash pop`

> 从最近一次备份的历史记录中进行恢复操作，之前未提交的数据都可以从这里恢复。
>
> 也可以从指定版本中进行恢复 `git stash pop stash@{2}`

***举个栗子***

```shell
## 恢复最近备份的版本
$ git stash pop
On branch dev
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)
        modified:   File2.java

no changes added to commit (use "git add" and/or "git commit -a")
Dropped refs/stash@{0} (7c2d5f5459c3feacf7b7a87dbb90bbc69a28f60e)--------恢复的同时也会删除之前备份历史

## 可以多次恢复操作
$ git stash pop
On branch dev
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   File2.java
        modified:   file1.txt

## 恢复指定节点版本
$ git stash pop stash@{2}
On branch dev
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   readme.txt

```



### `git stash drop`删除最近的备份历史记录

---

`git stash dropo`

> 有时候不想恢复最近的这个版本，那么可以用drop删除掉最近的，然后继续用pop恢复下一个备份节点记录。

***举个栗子***

```shell
$ git stash drop
Dropped refs/stash@{0} (d6700ee5c69213de0a296e314c9fc538035611e2)

$ git stash list
stash@{0}: WIP on dev: 16289de new change
stash@{1}: WIP on dev: da719ed Revert "roll back"
stash@{2}: WIP on dev: da719ed Revert "roll back"
stash@{3}: WIP on dev: da719ed Revert "roll back"
stash@{4}: WIP on local_dev: f594117 ...

## 删除指定节点版本
$ git stash drop  stash@{1}
Dropped stash@{1} (5776a835f04bddf17138bf9ca64feaaecda79525)
```



### `git stash show`显示备份历史记录的文件跟踪对比情况

---

`git stash show`

> 查看某个版本的文件备份跟踪情况，可以看到具体的变更记录。

***举个栗子***

```shell
$ git stash show stash@{1}
 file1.txt | 1 +
 1 file changed, 1 insertion(+)

$ git stash show stash@{2}
 foo.txt | 1 -
 too.txt | 1 +
 2 files changed, 1 insertion(+), 1 deletion(-)
```



### `git stash apply`应用指定节点历史备份记录

---

`git stash apply`

> 直接找到某个具体的版本备份历史记录，选择版本号直接应用

***举个栗子***

```shell
## 直接把之前备份的历史记录取出来
$ git stash apply stash@{2}
On branch dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

        new file:   too.txt
```





## 更新和发布/ Update & Publish

### `git remote` 查看所有远程仓库主机
---
`git remote`

> 可以显示已经存在的远程仓库主机
>
> git remote -v | --verbose 列出详细信息，`-v` 可以显示更详细的说明和地址

***举个栗子***

```shell
$ git remote
　　origin

#git remote -v | --verbose 列出详细信息，在每一个名字后面列出其远程url
#此时， -v 选项(译注:此为 –verbose 的简写,取首字母),显示对应的克隆地址:
$ git remote -v
git-world       git://github.com/hoojo/git-world.git (fetch)
git-world       git://github.com/hoojo/git-world.git (push)

# git 设置url
$ git remote set-url origin git@github.com:hooj0/rapid-framework.git
```



### `git remote show <remote>` 查看远程仓库主机详细信息
---
`git remote show <remote>`

> 查看远程分支详细信息

***举个栗子***

```shell
$ git remote show git-world
```



### `git remote add <shortname> <url>` 添加远程仓库
---
`git remote add <shortname> <url>`

> 添加远程仓库主机，设置短名称和仓库主机url就可以添加一个远程的仓库

***举个栗子***

```shell
$ git remote add git-world git:github.com/hoojo/git-world.git
```



### `git remote remove <shortname>`删除远程仓库主机
---
`git remote remove <shortname>`

> 删除远程仓库主机，设置短名称和仓库主机url就可以删除一个远程的仓库主机

***举个栗子***

```shell
$ git remote remove git-world
```



### `git fetch <remote>` 拉取远程主机更新
---
`git fetch`

> 1、`git fetch`取回远程主机的所有分支更新版本，不对本地代码造成冲突。<br/>
> 2、`git fetch <remote>`取指定分支更新

***举个栗子***

```shell
## 获取远程主机git-world仓库的master分支
$ git fetch git-world master

## 获取远程主机仓库origin的master分支
$ git fetch origin master
```



### `git pull <remote> <branch>`从远程分支拉取更新版本
---
`git pull <remote> <branch>`

> `git pull`在不带参数的情况下是拉取当前本地分支对应的远程分支版本，带参数可以指定远程主机和分支。

***举个栗子***

```shell
# 当前在dev分支，关联远程origin的dev分支；git pull会直接去拉取当前origin/dev分支
$ git pull

# 指定主机和分支，这种情况是远程master分支和本地当前分支是合并情况
$ git pull git-world master

# 将远程master分支和本地dev分支合并
$ git pull git-world master:dev
```



### `git push <remote> <branch>` 推送版本到远程分支
---
`git push <remote> <branch>`

> 1、推送本地分支master版本到远程`origin`分支`master`： `git push origin master`<br/>
> 2、推送本地分支dev版本到远程`origin`分支`rm_dev`：`git push origin dev:rm_dev`<br/>
> 3、推送本地分支到已关联的远程分支：`git push`<br/>
> 4、推送一个空的本地分支覆盖远程分支，即删除远程分支：`git push origin :master`<br/>
> 5、推送所有本地分支到远程主机：`git push --all origin`<br/>
>
> 以上推送的远程分支如果不存在会自动创建，例如本地master分支推送到origin主机仓库，但远程还没有master分支，系统会自动创建好该分支。

***举个栗子***

```shell
# 推送本地dev分支到远程origin/remote-dev分支
$ git push origin dev:remote-dev

# 推送本地dev分支到远程origin上
$ git push origin dev
# or
$ git pull origin master --allow-unrelated-histories

# 推送已跟踪过的分支到远程分支
$ git push
```



### `git branch -dr <remote/branch>` 删除远程仓库分支
---
`git branch -dr <remote/branch>`

> 删除远程分支

***举个栗子***

```shell
$ git branch -dr remove-dev
```



### `git push --tags` 发布标签
---
`git push --targs`

> 1、发布标签到远程仓库分支：`git push --tags`<br/>
> 2、发布标签到指定远程仓库分支：`$ git push --tags origin`

***举个栗子***

```shell
$ git push --tags

$ git push --tags git-world
```




# 4、Github 的使用

## 配置ssh key秘钥

> 如果你使用https的协议方式，每次提交代码都需要输入用户名、密码。而使用ssh方式的情况下，你可以配置ssh的key方便提交，不需要重复输入代码。

### 1、切换https协议到ssh

> 切换方式有两种：
>
> * 提交所有代码，并保存到远程仓库，最后删除本地代码，然后`git clone`远程仓库代码，注意克隆下来的时候使用ssh协议
>
> * 直接命令修改协议方式：
>
>   `git remote set-url origin git@github.com:account/project.git`

### 2、生成个人ssh key，在git bash中键入命令

```shell
## 切换到用户命令下的.ssh目录 C:\Users\Administrator\.ssh
$ cd ~/.ssh

## 执行 ssh-keygen方法生成key
$ ssh-keygen -t rsa -b 4096 -C "hoojo_@126.com"

## 输入id_rsa 秘钥文件的名称，默认名称是id_ras, 因为之前已成存在了一个git 账号的key，这里不能同名
Enter file in which to save the key (/c/Users/Administrator/.ssh/id_rsa): id_rsa_github

## 需要输入密码和确认密码
Enter passphrase (empty for no passphrase):
Enter same passphrase again:

## 生成完成
The key fingerprint is:
SHA256:meYAXwqpIgi5tnAv9ndJ2m8+mx/Dau6R7HvzWrB6vtk hoojo_@126.com
The key's randomart image is:
+---[RSA 4096]----+
|                 |
| .   .           |
|o   +   .        |
|o. . + o o       |
|*.o   + S   .    |
|+o..   +.. o o   |
| .o .  +..+ = .  |
| . o  o +.+=+*   |
|    .. . B%O*=E  |
+----[SHA256]-----+
```

### 3、配置key 到 ssh agent中

> `ssh` 默认读取的秘钥是 `id_rsa`，为了让ssh能识别到新的秘钥，需要把刚才生成的`id_rsa_github`添加到ssh agent中。

```shell
$ ssh-add.exe ~/.ssh/id_rsa_github
Could not open a connection to your authentication agent.
```

> 上面执行发生错误，解决方法如下：

```shell
## 执行命令
$ ssh-agent.exe bash
## 再次执行上一步的命令，添加秘钥到ssh agent中
$ ssh-add.exe ~/.ssh/id_rsa_github
Enter passphrase for /c/Users/Administrator/.ssh/id_rsa_github:
Identity added: /c/Users/Administrator/.ssh/id_rsa_github (/c/Users/Administrator/.ssh/id_rsa_github)
```

### 4、配置config文件

> 因为有多个秘钥文件，为了让ssh知道每个账号和git 域名host对应的秘钥文件，所以需要在~/.ssh 目录下配置config

```shell
# 该配置用于个人 github 上
# Host 服务器别名
Host github.com
# HostName 服务器ip地址或机器名
HostName github.com
# User连接服务器的用户名，和下面的 ssh -T git@github.com 中输出的用户名对应
User hoojo
# IdentityFile 密匙文件的具体路径
IdentityFile ~/.ssh/id_rsa_github

# 该配置用于个人 gitlib 上
# Host 服务器别名
Host xxx.gitlib.com
# HostName 服务器ip地址或机器名
HostName xxx.gitlib.com
# User连接服务器的用户名
User git_lib_user_name
# IdentityFile 密匙文件的具体路径
IdentityFile ~/.ssh/id_rsa
```

### 5、配置github的SSH keys公钥
> 访问地址：https://github.com/settings/keys
>
> **测试配置是否成功，测试之前还需要把id_rsa_github 的秘钥内容粘贴到 github 的ssh key中**
```shell
$ ssh -T git@github.com
Hi hoojo! You've successfully authenticated, but GitHub does not provide shell access.
```

### 6、常见问题汇总
- [ ] 1、重启电脑后发现push数据需要重新写入git密码(当我们把当前的Git窗口关闭，重新打开一个时，又会出现这个错误了)

> $ ssh -T git@gitee.com
> Enter passphrase for key '/c/Users/Administrator/.ssh/id_rsa_gitee':
> Permission denied (publickey).
>
> 这是因为： 
>
> **ssh-agent 是一个用于存储私钥的临时性的 session 服务，也就是说当你重启之后，ssh-agent 服务也就重置了**
>
> 解决办法，重新将秘钥加入到ssh中：
>
> ```shell
> ## 执行命令
> $ ssh-agent.exe bash
> ## 再次执行上一步的命令，添加秘钥到ssh agent中
> $ ssh-add.exe ~/.ssh/id_rsa_github
> Enter passphrase for /c/Users/Administrator/.ssh/id_rsa_github:
> Identity added: /c/Users/Administrator/.ssh/id_rsa_github 
> ```



# 参考资料

* [介绍与特征](https://baike.baidu.com/item/GIT/12647237?fr=aladdin)
* [教程](https://www.liaoxuefeng.com/wiki/0013739516305929606dd18361248578c67b8067c8c017b000/001373962845513aefd77a99f4145f0a2c7a7ca057e7570000)
* [官方资料、教程](https://git-scm.com/book/zh/v2)
* [官方pdf文档](https://services.github.com/on-demand/downloads/github-git-cheat-sheet.pdf)

