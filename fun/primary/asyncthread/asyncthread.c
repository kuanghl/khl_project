#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/*log*/
#include <log.h>
/*linux*/
#include <pthread.h>

pthread_t tid_a;
pthread_t tid_b;
pthread_mutex_t mutex;
int cond_a = 1;
int cond_b = 0;
int times = 0;

void fun_a(void){
    while (1)
    {
        // printf("enter thread a!\n");
        if(cond_a){
            printf("trigger condition a! times = %d.\n", times);
            pthread_mutex_lock(&mutex);
            cond_a = 0;
            cond_b = 1;
            pthread_mutex_unlock(&mutex);
            times++;
            if(times > 1024){
                pthread_cancel(tid_a);
                pthread_cancel(tid_b);
                pthread_join(tid_a, NULL);
                pthread_join(tid_b, NULL);
            }
        }
    } 
}

void fun_b(void){
    while (1)
    {
        // printf("enter thread b!\n");
        if(cond_b){
            printf("trigger condition b! times = %d.\n", times);
            pthread_mutex_lock(&mutex);
            cond_b = 0;
            cond_a = 1;
            pthread_mutex_unlock(&mutex);
        }
    }
    
}

int main(void){
    int r;
    r = pthread_mutex_init(&mutex, NULL);
    r = pthread_create(&tid_a, NULL, fun_a, NULL);
    r = pthread_create(&tid_b, NULL, fun_b, NULL);

    sleep(1);

    return 0;
}