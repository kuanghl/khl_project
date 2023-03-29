#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*log*/
#include <log.h>
/*linux*/
#include <pthread.h>
/*3rd*/
#include <uv.h>

uv_sem_t sem;
uv_async_t async;
uv_loop_t loop;

int wake_entry(void) 
{
    printf("wake_entry running, wake async!\n");

    /*只能单次调用*/
    uv_async_send(&async);
    // uv_async_send((uv_async_t*)arg);

    printf("go to continue!\n");

    uv_stop(&loop);

    uv_loop_close(&loop);

    return 0;
}

void my_async_cb(uv_handle_t* handle)
{
    printf("my async running!\n");
}

int main(void) 
{
    uv_thread_t wake;

    uv_loop_init(&loop);

    uv_sem_init(&sem, 0);

    uv_async_init(&loop, &async, my_async_cb);

    uv_thread_create(&wake, wake_entry, NULL);

    // uv_sem_post(&sem);
    printf("log0. sem = %d.\n", sem);
    // uv_sem_wait(&sem);
    // printf("log1. sem = %d.\n", sem);

    uv_run(&loop, UV_RUN_DEFAULT);


    
    uv_thread_join(&wake);

    return 0;
}
