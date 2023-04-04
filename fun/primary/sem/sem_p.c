/**
 * filename: named_sem2.c
 * author: Suzkfly
 * date: 2021-01-31
 * platform: Ubuntu
 *     配合named_sem1使用，先运行named_sem1，此时程序在第二次打印"sem_wait"时卡
 *     住，再另开一个终端，运行named_sem2，此时named_sem1会继续运行。
 *     编译时加-lpthread
 */
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define SEM_NAME "mysem"    /* 定义信号量的名字 */

int main(int argc, const char *argv[])
{
    int ret = 0;
    sem_t *p_sem = NULL;
    int value = 0;

    /* 创建信号量 */
    p_sem = sem_open(SEM_NAME, O_RDWR);
    printf("process 2 sem_open p_sem = %p\n", p_sem);
    if (p_sem == SEM_FAILED) {
        printf("process 2 sem_open failed\n");
        return 0;
    }

    /* 释放信号量 */
    ret = sem_getvalue(p_sem, &value);
    printf("process 2 sem_getvalue ret = %d, value = %d.\n", ret, value);
    ret = sem_post(p_sem);
    ret = sem_getvalue(p_sem, &value);
    printf("process 2 sem_getvalue ret = %d, value = %d.\n", ret, value);

    /* 关闭信号量 */
    ret = sem_close(p_sem);
    printf("process 2 sem_close ret = %d\n", ret);

    return 0;
}