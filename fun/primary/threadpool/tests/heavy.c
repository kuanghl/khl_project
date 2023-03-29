#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <assert.h>

#include "threadpool.h"

#define THREAD 4
#define SIZE   8192
#define QUEUES 64

/*
 * Warning do not increase THREAD and QUEUES too much on 32-bit
 * platforms: because of each thread (and there will be THREAD *
 * QUEUES of them) will allocate its own stack (8 MB is the default on
 * Linux), you'll quickly run out of virtual space.
 */

threadpool_t *pool[QUEUES];
int tasks[SIZE], left;
pthread_mutex_t lock;

int error;

void dummy_task(void *arg) {
    int *pi = (int *)arg;
    *pi += 1;

    if(*pi < QUEUES) {
        assert(threadpool_add(pool[*pi], &dummy_task, arg, 0) == 0);
    } else {
        pthread_mutex_lock(&lock);
        left--;
        printf("left = %d.\n", left);
        pthread_mutex_unlock(&lock);
    }
}

int main(int argc, char **argv)
{
    int i, copy = 1;

    left = SIZE;
    pthread_mutex_init(&lock, NULL);

    /*创建64个线程池*/
    for(i = 0; i < QUEUES; i++) {
        /*线程池中的线程数为THREAD，队列大小为SIZE*/
        pool[i] = threadpool_create(THREAD, SIZE, 0);
        assert(pool[i] != NULL);
    }

    usleep(10);

    for(i = 0; i < SIZE; i++) {
        tasks[i] = 0;
        /*向线程池0中添加任务*/
        assert(threadpool_add(pool[0], &dummy_task, &(tasks[i]), 0) == 0);
    }

    /*更新left到copy*/
    while(copy > 0) {
        usleep(10);
        pthread_mutex_lock(&lock);
        copy = left;
        pthread_mutex_unlock(&lock);
    }
    /*销毁线程池*/
    for(i = 0; i < QUEUES; i++) {
        assert(threadpool_destroy(pool[i], 0) == 0);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}
