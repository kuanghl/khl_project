/**
 * @brief 仿照linux kfifo写的cycled_fifo
 * */

#ifndef CYCLED_FIFO_H
#define CYCLED_FIFO_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <pthread.h>

//判断x是0否1为2的次方
#define is_power_of_2(x) ((x) != 0 && (((x) & ((x) - 1)) == 0))
//取a和b中最小值
#define min(a, b) (((a) < (b)) ? (a) : (b))
//向2的n次幂圆整
#define roundup_pow_of_two(a)  ({int _a = a,_b = 1,_ret;\
                                    while(a >>= 1) _b <<= 1; \
                                    _ret = _b < _a ? _b << 1 : _b; \
                                    _ret;})

/*
filled size: in - out <= size
empty size : size - in + out
right size: size - in & (size - 1)
*/
struct ring_buffer
{
    void            *buffer;     //缓冲区
    uint32_t         size;       //大小
    uint32_t         in;         //入口位置
    uint32_t         out;        //出口位置
    pthread_mutex_t *f_lock;     //互斥锁
};

/*
-- 初始化缓冲区
- buffer 缓冲区指针
- size 缓冲区大小
- f_lock 互斥锁
*/
struct ring_buffer* ring_buffer_init(void *buffer, uint32_t size, pthread_mutex_t *f_lock)
{
    assert(buffer);
    struct ring_buffer *ring_buf = NULL;
    if (!is_power_of_2(size))  //size是2的n次方
    {
        size = roundup_pow_of_two(size);
    	printf("warning size must be power of 2.\n");
        // return ring_buf;
    }
    ring_buf = (struct ring_buffer *)malloc(sizeof(struct ring_buffer));
    if (!ring_buf)
    {
        printf("Failed to malloc memory,errno:%u,reason:%s",
            errno, strerror(errno));
        return ring_buf;
    }
    memset(ring_buf, 0, sizeof(struct ring_buffer));
    ring_buf->buffer = buffer;
    ring_buf->size = size;
    ring_buf->in = 0;
    ring_buf->out = 0;
    ring_buf->f_lock = f_lock;
    return ring_buf;
}

/*
--释放缓冲区
- ring_buf缓冲队列指针
*/
void ring_buffer_free(struct ring_buffer *ring_buf)
{
    if (ring_buf)
    {
		if (ring_buf->buffer)
		{
			free(ring_buf->buffer);
			ring_buf->buffer = NULL;
		}
		free(ring_buf);
		ring_buf = NULL;
    }
}

/*
--获取已填充缓冲区的大小
- ring_buf缓冲队列指针
*/
uint32_t __ring_buffer_fill_len(const struct ring_buffer *ring_buf)
{
    return (ring_buf->in - ring_buf->out);
}

/*
--获取空缓冲区的大小
- ring_buf缓冲队列指针
*/
uint32_t __ring_buffer_empty_len(const struct ring_buffer *ring_buf)
{
    return (ring_buf->size - (ring_buf->in - ring_buf->out));
}

/*
--从缓冲区中取数据
- ring_buf缓冲队列指针
- buffer缓冲区指针
- size缓冲区大小
*/
uint32_t __ring_buffer_get(struct ring_buffer *ring_buf, void * buffer, uint32_t size)
{
    assert(ring_buf && buffer);
    uint32_t len = 0;
    size  = min(size, ring_buf->in - ring_buf->out);
    /* first get the data from fifo->out until the end of the buffer */
    len = min(size, ring_buf->size - (ring_buf->out & (ring_buf->size - 1)));
    memcpy(buffer, ring_buf->buffer + (ring_buf->out & (ring_buf->size - 1)), len);
    /* then get the rest (if any) from the beginning of the buffer */
    memcpy(buffer + len, ring_buf->buffer, size - len);
    ring_buf->out += size;
    return size;
}

/*
--向缓冲区中存放数据
- ring_buf缓冲队列指针
- buffer缓冲区指针
- size缓冲区大小
*/
uint32_t __ring_buffer_put(struct ring_buffer *ring_buf, void *buffer, uint32_t size)
{
    assert(ring_buf && buffer);
    uint32_t len = 0;
    size = min(size, ring_buf->size - (ring_buf->in - ring_buf->out));
    /* first put the data starting from fifo->in to buffer end */
    len  = min(size, ring_buf->size - (ring_buf->in & (ring_buf->size - 1)));
    memcpy(ring_buf->buffer + (ring_buf->in & (ring_buf->size - 1)), buffer, len);
    /* then put the rest (if any) at the beginning of the buffer */
    memcpy(ring_buf->buffer, buffer + len, size - len);
    ring_buf->in += size;
    return size;
}

/*
--线程安全的读取已填充缓冲区大小
- ring_buf缓冲队列指针
*/
uint32_t ring_buffer_fill_len(const struct ring_buffer *ring_buf)
{
    uint32_t len = 0;
    pthread_mutex_lock(ring_buf->f_lock);
    len = __ring_buffer_fill_len(ring_buf);
    pthread_mutex_unlock(ring_buf->f_lock);
    return len;
}
/*
--线程安全的方式读取缓冲区数据
- ring_buf缓冲队列指针
- buffer缓冲区指针
- size缓冲区大小
*/
uint32_t ring_buffer_get(struct ring_buffer *ring_buf, void *buffer, uint32_t size)
{
    uint32_t ret;
    pthread_mutex_lock(ring_buf->f_lock);
    ret = __ring_buffer_get(ring_buf, buffer, size);
    //buffer中没有数据
    if (ring_buf->in == ring_buf->out)
    	ring_buf->in = ring_buf->out = 0;
    pthread_mutex_unlock(ring_buf->f_lock);
    return ret;
}
/*
--线程安全的向缓冲区存入数据
- ring_buf缓冲队列指针
- buffer缓冲区指针
- size缓冲区大小
*/
uint32_t ring_buffer_put(struct ring_buffer *ring_buf, void *buffer, uint32_t size)
{
    uint32_t ret;
    pthread_mutex_lock(ring_buf->f_lock);
    ret = __ring_buffer_put(ring_buf, buffer, size);
    pthread_mutex_unlock(ring_buf->f_lock);
    return ret;
}
#endif