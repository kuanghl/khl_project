#include <stdio.h>
#include <stdlib.h>
// #include <sys/mman.h>
// #include <string.h>
// #include <fcntl.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <unistd.h>
#include <stdint.h>
#include <semaphore.h>
#include <pthread.h>

#define NUM_TO_POW2N(num_a)  ({int buf_num_a = num_a,num_b = 1,num_ret;\
                            while(num_a >>= 1) num_b <<= 1; \
                            num_ret = num_b < buf_num_a ? num_b << 1 : num_b; \
                            num_ret;})
#define _SHM_NAME "_shm"
#define _SEM_PRODUCER_A "_sem_pa"
#define _SEM_CONSUMER_A "_sem_ca"
#define _SEM_PRODUCER_B "_sem_pb"
#define _SEM_CONSUMER_B "_sem_cb"
#define _SHM_PATH "/dev/shm/_shm"
#define _SEM_PRODUCER_PATH "/dev/shm/sem._sem_pa"
#define _SEM_CONSUMER_PATH "/dev/shm/sem._sem_ca"
#define _SEM_PRODUCER_PATH "/dev/shm/sem._sem_pb"
#define _SEM_CONSUMER_PATH "/dev/shm/sem._sem_cb"
#define _DATA_SIZE_MAX (512)
#define _SHM_SIZE (64 * 1024)    //64k
#define _SEM_MAX (_SHM_SIZE / _DATA_SIZE_MAX)   //512bytes/sem 

typedef struct _data_buf_s{
    void *addr;
    size_t len;
}_data_buf_t;

typedef struct _ipc_shm_s{
    int shm_fd;
    void *shm_addr;
    uint64_t shm_offset;
    sem_t *shm_sem_pa;
    sem_t *shm_sem_ca;
    sem_t *shm_sem_pb;
    sem_t *shm_sem_cb;
    pthread_mutex_t shm_mutex;
}_ipc_shm_t;

typedef struct consumer_shm_s
{
    pthread_t tid;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

    _ipc_shm_t shm;
    _data_buf_t data;
}consumer_shm_t;

int _shm_pre(){

}

int _shm_post(){

}

void _shm_unmap(consumer_shm_t *consumer_shm){

}

int _shm_map(consumer_shm_t *consumer_shm){

}

int _shm_init(){

}

void _shm_exit(){

}

int main(void){
    return 0;
}