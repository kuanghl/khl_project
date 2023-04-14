#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>

void sig_handler1(int arg){
    printf("This is signal handle 1.\n");
}

void sig_handler2(int arg){
    printf("This is signal handle 2.\n");
}   

void thread_fun1(void *arg){
    printf("This is thread1 tid = %d.\n", pthread_self());
    
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_handler = sig_handler1;
    sigaction(SIGQUIT, &act, NULL);

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGQUIT);
    pthread_sigmask(SIG_BLOCK, &mask, NULL);
    sleep(2);
}

void thread_fun2(void *arg){
    printf("This is thread2 tid = %d.\n", pthread_self());
    
    struct sigaction act;
    memset(&act, 0, sizeof(act));
    sigaddset(&act.sa_mask, SIGQUIT);
    act.sa_handler = sig_handler2;
    sigaction(SIGQUIT, &act, NULL);

    // sigset_t mask;   //设置信号集
    // sigemptyset(&mask);
    // sigaddset(&mask, SIGQUIT);
    // pthread_sigmask(SIG_BLOCK, &mask, NULL);

    sleep(2);
}

int main(void){
    pthread_t tid1,tid2;

    pthread_create(&tid1, NULL, thread_fun1, NULL);
    pthread_create(&tid2, NULL, thread_fun2, NULL);

    sleep(1);
    /*向指定线程发送SIGQUIT信号*/
    pthread_kill(tid1, SIGQUIT);
    pthread_kill(tid2, SIGQUIT);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
