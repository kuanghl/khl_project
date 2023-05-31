### src code.
- doctest_fakeilt:https://github.com/vladiant/cpp_doctest_fakeit_project.git
  - doctest:https://github.com/doctest/doctest.git
  - fakeilt:https://github.com/eranpeer/FakeIt.git
- googletest:https://github.com/google/googletest.git
- sqlite:https://github.com/sqlite/sqlite.git
### google test/gtest单元测试平台.
- [x] googletest--clone googletest源码.
- [x] gtest--googletest release版本.
- [x] common_test--放置通用函数API测试集.
- [x] test 指令： 
      - 整个测试集：`./test/common_test/common_test --gtest_filter=CommonTest*`
      - 单个测试例：`./test/common_test/common_test --gtest_filter=CommonTest.Negative`
- [ ] gtest代替项目：doctest + fakeilt--完整项目尚未整合.