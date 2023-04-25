#include <gtest/gtest.h>
#include <log.h>

#define TESTING

int Factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  log_fatal("%s, factorial result = %d.\n", __func__, result);
  log_debug("%s, n = %d.\n", __func__, n);

  return result;
}

class CommonTest : public testing::Test
{
    void SetUp(){}

    void TearDown(){}
};

// 正数为一组
TEST(CommonTest, Negative) {
  EXPECT_EQ(1, Factorial(-5));
  EXPECT_EQ(1, Factorial(-1));
  EXPECT_GT(Factorial(-10), 0);
}
// 0
TEST(CommonTest, Zero) {
  EXPECT_EQ(1, Factorial(0));
}
// 负数为一组
TEST(CommonTest, Positive) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(24, Factorial(4));
  EXPECT_EQ(40320, Factorial(8));
}