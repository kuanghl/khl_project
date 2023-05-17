- config:
  ```
  # linux
  sudo apt-get install doxygen
  sudo apt install graphviz
  # or
  sudo apt-get install doxygen-gui 
  sudo apt install graphviz
  # windows
  htmlhelp
  ```

- doxygen注释语法：
  - 函数API/文件注释：
  - [ref](https://zhuanlan.zhihu.com/p/510925324)
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
    |@class      |引用类	     |用于文档生成连接|
    |@var	       |引用变量     |用于文档生成连接|
    |@enum       |引用枚举     |用于文档生成连接|
    |@code       |代码块开始   |与@endcode成对使用|
    |@endcode    |代码块结束   |与@code成对使用|
    |@remarks    |备注说明     |	|
  - 单行/多行注释：
    - 单行注释：`///`或者`//!`
    - 多行注释：`/**`或者`/*!`
- doxygen指令：
  - [ref](https://blog.csdn.net/m0_51586788/article/details/123700545)
  - [ref](https://www.doxygen.nl/manual/config.html) 
  ```
  # 生成doxyfile
  doxygen -g <config-file>
  # 或（不含注释）
  doxygen -s -g <config-file>
  ...配置
  # 使配置生效
  doxygen Doxyfile # 选择你自己的文件，默认是 Doxyfile
  # doxygen gui
  doxywizard
  # 修改配置文件
  doxywizard Doxyfile
  ```

  