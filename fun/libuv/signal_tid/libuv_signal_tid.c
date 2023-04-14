#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <uv.h>

void signal_handler(uv_signal_t *handle, int signum)
{
    printf("signal received: %d\n", signum);
    //uv_signal_stop(handle);
    sleep(1);
}

void thread1_entry(void *userp)
{
    // usleep(10);
    // kill(0, SIGUSR1);
    // usleep(10);
    // kill(0, SIGUSR1);
    // usleep(10);
    // kill(0, SIGUSR1);
    usleep(1);
    raise(SIGUSR1);
    printf("Send SIGUSR1 signal.\n");
    //usleep(10);
    raise(SIGUSR1);
    printf("Send SIGUSR1 signal.\n");
    //usleep(10);
    raise(SIGUSR1);
    printf("Send SIGUSR1 signal.\n");
}


void thread2_entry(void *userp)
{
    uv_signal_t signal;
    
    uv_signal_init(uv_default_loop(), &signal);
    uv_signal_start(&signal, signal_handler, SIGUSR1);
    
    uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}

int main()
{
    uv_thread_t thread1, thread2;

    /*此处如果thread1先执行的话会将信号优先发送到管道中而没有thread2的处理，报错User defined signal 1*/
    uv_thread_create(&thread2, thread2_entry, NULL);
    uv_thread_create(&thread1, thread1_entry, NULL);

    uv_thread_join(&thread1);
    uv_thread_join(&thread2);
    return 0;
}
