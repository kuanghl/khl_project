#include <stdio.h>
#include <pthread.h>
#include <unistd.h>    // sleep() 函数

//创建一个互斥量
pthread_mutex_t mutex;

//线程执行的函数
void * thread_func2(void * arg) 
{
    printf("新建线程开始执行.....\n");

    //加锁
    pthread_mutex_lock(&mutex);

    printf("新建线程执行中.....\n");
    //sleep(10); //函数内没有系统调用，故没有设置一个取消点（cancelpoint），线程将不会退出而是继续往下执行代码 

    //解锁
    pthread_mutex_unlock(&mutex);

    printf("新建线程执行完毕.....\n");
}

int main()
{
    pthread_t myThread;
    void * mess;
    int value;
    int res;

    //初始化互斥量
    pthread_mutex_init(&mutex, NULL);

    //创建 myThread 线程
    res = pthread_create(&myThread, NULL, thread_func2, NULL);
    if (res != 0) 
    {
        printf("线程创建失败\n");
        return 0;
    }

    sleep(1);

    //向 myThread 线程发送 Cancel 信号
    res = pthread_cancel(myThread);
    if (res != 0) 
    {
        printf("终止 myThread 线程失败\n");
        // return 0;
    }

    //获取已终止线程的返回值
    res = pthread_join(myThread, &mess);
    if (res != 0) 
    {
        printf("等待线程失败\n");
        // return 0;
    }

    //如果线程被强制终止，其返回值为 PTHREAD_CANCELED
    if (mess == PTHREAD_CANCELED) 
    {
        printf("myThread 线程被强制终止\n");
    }
    else 
    {
        printf("error\n");
    }

    //释放互斥量资源
    pthread_mutex_destroy(&mutex);

    return 0;
}
