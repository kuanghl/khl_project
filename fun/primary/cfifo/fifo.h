#ifndef _FIFO_H_
#define _FIFO_H_

#include <sys/sem.h>
#include <pthread.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//判断x是0否1为2的次方
#define is_power_of_2(x) ((x) != 0 && (((x) & ((x) - 1)) == 0))
//取a和b中最小值
#define min(a, b) (((a) < (b)) ? (a) : (b))
//向2的n次幂圆整
#define roundup_pow_of_two(a)  ({int _a = a,_b = 1,_ret;\
                                    while(a >>= 1) _b <<= 1; \
                                    _ret = _b < _a ? _b << 1 : _b; \
                                    _ret;})

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

/*
used size: in - out <= size
unused size : size - (in - out)
right size: size - in & (size - 1)
*/
typedef struct fifo_s
{
    void *addr;
    uint64_t size;
    uint64_t in;
    uint64_t out;
    pthread_mutex_t *mutex;
}fifo_t;

/*
fifo
*/
fifo_t* __fifo_init(void *buf, uint32_t size, pthread_mutex_t *mutex)
{
    assert(buf);
    fifo_t *fifo = NULL;
    if (!is_power_of_2(size))  //size是2的n次方
    {
        size = roundup_pow_of_two(size);
    	printf("warning size must be power of 2.\n");
        // return ring_buf;
    }
    fifo = (fifo_t *)malloc(sizeof(fifo_t));
    if (!fifo)
    {
        printf("Failed to malloc memory,errno:%u,reason:%s",
            errno, strerror(errno));
        return NULL;
    }
    memset(fifo, 0, sizeof(fifo_t));
    fifo->addr = buf;
    fifo->size = size;
    fifo->in = 0;
    fifo->out = 0;
    fifo->mutex = mutex;
    return fifo;
}

void __fifo_free(fifo_t *fifo)
{
    if (fifo)
    {
		if (fifo->addr)
		{
			free(fifo->addr);
		    fifo->addr = NULL;
		}
		free(fifo);
		fifo = NULL;
    }
}

uint64_t __fifo_used_len(fifo_t *fifo)
{
    return (fifo->in - fifo->out);
}

uint64_t __fifo_unused_len(fifo_t *fifo)
{
    return (fifo->size - (fifo->in - fifo->out));
}

void __fifo_reset_auto(fifo_t *fifo)
{  
    if(fifo->in == fifo->out){
        fifo->in = fifo->out = 0;
    }
}

uint64_t __fifo_put(fifo_t *fifo, void *buf, uint64_t len)
{
    assert(fifo != NULL && buf != NULL);
    uint64_t size;

    pthread_mutex_lock(fifo->mutex);
    if(__fifo_unused_len(fifo) < len){
        pthread_mutex_unlock(fifo->mutex);
        printf("error buffer space no enough!!!\n");
        return 0;
    }
    __fifo_reset_auto(fifo);
    uint64_t in = fifo->in;
    uint64_t out = fifo->out;
    pthread_mutex_unlock(fifo->mutex);

    len = min(len, fifo->size - (in - out));
    /* first put the data starting from fifo->in to buffer end */
    size = min(len, fifo->size - (in & (fifo->size - 1)));
    memcpy(fifo->addr + (in & (fifo->size - 1)), buf, size);
    /* then put the rest (if any) at the beginning of the buffer */
    memcpy(fifo->addr, buf + size, len - size);

    pthread_mutex_lock(fifo->mutex);
    fifo->in = in + len;
    pthread_mutex_unlock(fifo->mutex);

    return len;
}

uint64_t __fifo_get(fifo_t *fifo, void *buf, uint64_t len)
{
    assert(fifo != NULL && buf != NULL); 
    uint64_t size;

    pthread_mutex_lock(fifo->mutex);
    if(__fifo_used_len(fifo) <= 0){
        pthread_mutex_unlock(fifo->mutex);
        printf("warning no data in buffer space...\n");
        return 0;
    }
    uint64_t in = fifo->in;
    uint64_t out = fifo->out;
    pthread_mutex_unlock(fifo->mutex);

    len = min(len, in - out);
    /* first get the data from fifo->out until the end of the buffer */
    size = min(len, fifo->size - (out & (fifo->size - 1)));
    memcpy(buf, fifo->addr + (out & (fifo->size - 1)), size);
    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(buf + size, fifo->addr, len - size);

    pthread_mutex_lock(fifo->mutex);
    fifo->out = out + len;
    pthread_mutex_unlock(fifo->mutex);

    return len;
}

/*
sem
*/
int __sem_init(int __id, int __index, int __val) {
    union semun sem_union;
    sem_union.val = __val;
    return semctl(__id, __index, SETVAL, sem_union);
}

int __sem_del(int __id, int __index) {
    union semun sem_union;
    return semctl(__id, __index, IPC_RMID, sem_union);
}

int __sem_getval(int __id, int __index) {
    union semun sem_union;
    return semctl(__id, __index, GETVAL, sem_union);
}

int __sem_post(int __id, int __index) {
    struct sembuf sops;
    sops.sem_num = __index;
    sops.sem_op = 1;
    sops.sem_flg = SEM_UNDO;
    return semop(__id, &sops, 1);
}

int __sem_wait(int __id, int __index) {
    struct sembuf sops;
    sops.sem_num = __index;
    sops.sem_op = -1;
    sops.sem_flg = SEM_UNDO;
    return semop(__id, &sops, 1);
}

#endif/* fifo.h  */