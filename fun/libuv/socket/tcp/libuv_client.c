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

typedef struct libuv_cli_s{
#define PORT_NUM 10086
    pthread_t tid;
    pthread_mutex_t mutex;
    pthread_cond_t cond;

    uv_loop_t loop;
    struct sockaddr_in addr;
    uv_tcp_t client_sock;
    uv_connect_t connect_req;
    uv_write_t write_req;
    uv_shutdown_t shutdown_req;

    uv_buf_t buf;
    uint8_t to[65536];
    uint8_t from[65536];
}libuv_cli_t;

static uv_loop_t *loop;


static void close_cb(uv_handle_t* handle) {
    // free(handle);
}

static void write_cb(uv_write_t *req, int status){
    if(status < 0){
        uv_close((uv_handle_t *)req->handle, close_cb);
        return;
    }
    // free(req);
}

static void shutdown_cb(uv_shutdown_t *req, int status){
    if(status < 0){
        uv_close((uv_handle_t *)req->handle, close_cb);
        return;
    }
    // free(req);
}   

// 申请接收缓冲区buf空间
static void alloc_cb(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf){
    buf->base = calloc(1, suggested_size);
    buf->len = suggested_size;
}

static void read_cb(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf){
    libuv_cli_t *libuv_cli = container_of((uv_tcp_t *)stream, libuv_cli_t, client_sock);
    //读取数据
    if(nread > 0){
        log_debug("Reading.\n");
        return;
    }
    //读取数据完毕
    if(nread == 0){
        log_debug("EAGAIN or EWOULDBLOCK.\n");
        uv_close((uv_handle_t *)stream, close_cb);
        free(libuv_cli);
        free(buf->base);
        return;
    }
    //读取数据错误
    if (nread < 0) {
        if (nread == UV_EOF) {
            uv_close((uv_handle_t*) stream, close_cb);
        } else if (nread == UV_ECONNRESET) {
            log_error("Read error %s\n", uv_err_name(nread));
            uv_close((uv_handle_t*) stream, close_cb);
        } else {
            log_error("Read error %s\n", uv_err_name(nread));
        }
        free(buf->base);
        return;
    }
}

static void connect_cb(uv_connect_t *req, int status){
    int r;
    libuv_cli_t *libuv_cli = container_of(req, libuv_cli_t, connect_req);

    r = uv_is_readable((uv_stream_t *)req->handle);
    r = uv_is_writable((uv_stream_t *)req->handle);
    r = uv_is_closing((uv_handle_t *)req->handle);

    r = uv_write(&libuv_cli->write_req, (uv_stream_t *)req->handle, &libuv_cli->buf, 1, write_cb);
    // r = uv_write2();

    r = uv_shutdown(&libuv_cli->shutdown_req, (uv_stream_t *)req->handle, shutdown_cb);

    r = uv_read_start((uv_stream_t *)req->handle, alloc_cb, read_cb);
}

int ipc_connect(libuv_cli_t *libuv_cli){
    int r;

    r = uv_loop_init(&libuv_cli->loop);

    r =  uv_tcp_init(&libuv_cli->loop, &libuv_cli->client_sock);

    r = uv_ip4_addr("127.0.0.1", PORT_NUM, &libuv_cli->addr);

    log_info("Connect to %s:%d\n", inet_ntoa(libuv_cli->addr.sin_addr), htons(libuv_cli->addr.sin_port));
    r = uv_tcp_connect(&libuv_cli->connect_req, &libuv_cli->client_sock, &libuv_cli->addr, connect_cb);

    r = uv_run(&libuv_cli->loop, UV_RUN_DEFAULT);

    return r;
}

int main(void){
    
    int r;
    libuv_cli_t *libuv_cli = (libuv_cli_t *)calloc(1, sizeof(libuv_cli_t));
    r = ipc_connect(libuv_cli);

    return 0;
}
