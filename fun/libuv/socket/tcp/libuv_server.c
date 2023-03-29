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

// 根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针
#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})

typedef struct libuv_header_s{
    int tid;
    int uid;
    int pid;
    int currtime;
}libuv_header_t;

typedef struct libuv_serv_s{
#define PORT_NUM 10086
    pthread_t tid;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

    uv_loop_t loop;
    struct sockaddr_in addr;
    uv_tcp_t server_sock;

    uv_buf_t buf;
    uint8_t to[65536];
    uint8_t from[65536];
}libuv_serv_t;

static void close_cb(uv_handle_t* handle) {
    free(handle);
}


int ipc_accept(libuv_serv_t *libuv_serv){
    int r;

    r = uv_loop_init(&libuv_serv->loop);

    r = uv_ip4_addr("127.0.0.1", PORT_NUM, &libuv_serv->addr);
}

int main(void){

    return 0;
}
