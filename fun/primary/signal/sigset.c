#include <stdio.h>
#include <signal.h>
#include <unistd.h>
 
void handler(int sig)
{
    printf("Handle the signal %d\n", sig);
}
 
int main(int argc, char **argv)
{
    sigset_t sigset;    // 用于记录屏蔽字
    sigset_t ign;       // 用于记录被阻塞(屏蔽)的信号集
    struct sigaction act;
 
    // 清空信号集
    sigemptyset(&sigset);
    sigemptyset(&ign);
 
    // 向信号集中添加 SIGINT
    sigaddset(&sigset, SIGINT);
 
    // 设置处理函数 和 信号集
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, 0);
 
    printf("Wait the signal SIGNAL...\n");
    pause();
 
    // 设置进程屏蔽字, 在本例中为屏蔽 SIGINT
    sigprocmask(SIG_SETMASK, &sigset, 0);
    printf("Please press Ctrl + C in 10 seconds...\n");
    sleep(10);
 
    // 测试 SIGINT 是否被屏蔽
    sigpending(&ign);
    if (sigismember(&ign, SIGINT))
    {
        printf("The SIGINT signal has ignored\n");
    }
 
    // 从信号集中删除信号 SIGINT
    sigdelset(&sigset, SIGINT);
    printf("Wait the signal SIGINT...\n");
 
    // 将进程的屏蔽字重新设置, 即取消对 SIGINT 的屏蔽
    // 并挂起进程
    sigsuspend(&sigset);
 
    printf("The app will exit in 2 secondes!\n");
    sleep(2);
 
    return 0;
}