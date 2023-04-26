### google test/gtest单元测试平台.
- googletest--clone googletest源码.
- gtest--googletest release版本.
- common_test--放置通用函数API测试集.
- test 指令：
  - 整个测试集：`./test/common_test/common_test --gtest_filter=CommonTest*`
  - 单个测试例：`./test/common_test/common_test --gtest_filter=CommonTest.Negative`