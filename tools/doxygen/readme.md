- config:
  ```
  sudo apt-get install doxygen
  # or
  sudo apt-get install doxygen-gui 
  ```

- doxygen注释语法：

  | #    |                  Title                   |                                       Use|
  | :--- | :--------------------------------------  | :--------------------------------------------------- |
  |__命令__  |__字段名__|	__语法__|
  |@file	     |文件名   |file [< name >]|
  |@brief	     |简介	   |brief { brief description }|
  |@author     |作者     |author { list of authors }|
  |@mainpage   |主页信息 |mainpage [(title)]|
  |@date	     |年-月-日 |date { date description }|
  |@author     |版本号   |version { version number }|
  |@copyright  |版权     |copyright { copyright description }|
  |@param	     |参数     |param [(dir)] < parameter-name> { parameter description }|
  |@return     |返回     |return { description of the return value }|
  |@retval     |返回值   |retval { description }|
  |@bug        |漏洞   |bug { bug description }|
  |@details    |细节   |details { detailed description }|
  |@pre        |前提条件  |pre { description of the precondition }|
  |@see        |参考  |see { references }|
  |@link       |连接(与@see类似，{@link http://www.google.com})  |link < link-object>|
  |@throw      |异常描述  |throw < exception-object> { exception description }|
  |@todo       |待处理    |todo { paragraph describing what is to be done }|
  |@warning    |警告信息                               |warning { warning message }|
  |@deprecated |弃用说明。可用于描述替代方案，预期寿命等  |deprecated { description }|
  |@example    |弃用说明。可用于描述替代方案，预期寿命等  |deprecated { description }|
- [ref-1](https://zhuanlan.zhihu.com/p/510925324)
  