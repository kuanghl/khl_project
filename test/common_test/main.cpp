#include <unistd.h>
#include <gtest/gtest.h>

class MyEnvironment: public ::testing::Environment
{
public:
    virtual ~MyEnvironment() = default;
    int ii = 1;

    virtual void SetUp() {
        int jj = 2;
        ASSERT_EQ(2, jj);
    }

    virtual void TearDown() {
        int kk = 3;
        ASSERT_EQ(3, kk);
    }
};

int main(int argc, char **argv)
{
    MyEnvironment *env = new MyEnvironment();
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(env);

    int ret = RUN_ALL_TESTS();
    return ret;
}