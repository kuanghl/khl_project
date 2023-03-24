#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*log*/
#include <log.h>
/*linux*/
#include <pthread.h>
#include <list.h>
/*3rd*/
#include <uv.h>

typedef struct libuv_cli_s{
#define PORT_NUM  10086
    pthread_t tid;

	uv_loop_t loop;
	struct sockaddr_in addr;
	uv_tcp_t client;
	uv_connect_t connect_req;
	uv_write_t write_req;
	uv_shutdown_t shutdown_req;

    uv_buf_t buf_to;
    uv_buf_t buf_from;
    
    uint8_t to_buf[65536];
    uint8_t from_buf[65536];
}libuv_cli_t;

static uv_loop_t *loop;


static void on_close(uv_handle_t* handle) {
    free(handle);
}

static void on_shutdown(uv_shutdown_t *sd, int status) {
    if (status < 0) {
        fprintf(stderr, "failed to shutdown connection, err: %s\n", uv_strerror(status));
        return;
    } else {
        uv_close((uv_handle_t *)sd->handle, on_close);
    }

    free(sd);
}

void read_alloc_callback(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
    buf->base = malloc(suggested_size);
    buf->len = suggested_size;
}

void read_callback(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf) {
    if (nread < 0) {
        fprintf(stderr, "failed to read from server, err: %s\n", uv_strerror(nread));
        free(buf->base);
        exit(1);
        return;
    } else if (nread > 0) {
        buf->base[nread] = '\0';
        printf("recv %s\n", buf->base);

        uv_shutdown_t *sd = malloc(sizeof(uv_shutdown_t));
        uv_shutdown(sd, stream, on_shutdown);
    }

    free(buf->base);
}

static void on_response_callback(uv_write_t* req, int status) {
    if (status < 0) {
        fprintf(stderr, "failed to write hello to server, err: %s\n", uv_strerror(status));
    } else {
        return;
    }

    fprintf(stderr, "uv_write error: %s\n", uv_strerror(status));

    if (status == UV_ECANCELED)
        return;

    assert(status == UV_EPIPE);
    uv_close((uv_handle_t *)req->handle, on_close);
    free(req);
}

void on_connected(uv_connect_t *conn, int status) {
    int r;
    uv_write_t wr;

    if (status < 0) {
        fprintf(stderr, "failed to dial to server, err: %s\n", uv_strerror(status));
        return;
    }

    uv_buf_t b[] = {
        {.base = "hello", .len = 5}
    };

    if ((r = uv_write(&wr, conn->handle, b, 1, on_response_callback)) != 0) {
        printf("failed to send hello to server, err: %s\n", uv_strerror(r));
        return;
    }

    printf("sent hello\n");

    if ((r = uv_read_start(conn->handle, read_alloc_callback, read_callback)) != 0) {
        printf("failed to start reading data from server, err: %s\n", uv_strerror(r));
        return ;
    }
}

int main(void) {
    int r;
    struct sockaddr_in addr;
    uv_tcp_t *client = malloc(sizeof(uv_tcp_t));
    uv_connect_t *connect = malloc(sizeof(uv_connect_t));

    loop = uv_default_loop();

    uv_tcp_init(loop, client);

    if ((r = uv_ip4_addr("127.0.0.1", 10086, &addr)) != 0) {
        printf("failed to init server address, err: %s\n", uv_strerror(r));
        return 1;
    }

    if ((r = uv_tcp_connect(connect, client, (const struct sockaddr *)&addr, on_connected)) != 0) {
        printf("failed to connect to server, err: %s\n", uv_strerror(r));
        return 2;
    }

    return uv_run(loop, UV_RUN_DEFAULT);
}

void connect_cb(uv_connect_t *connect, int status){

}

int ipc_connoct(libuv_cli_t *libuv_cli){
    int r;

    r = uv_loop_init(&libuv_cli->loop);
    if (r != 0) {
        log_error("%s, uv_loop_init error %s\n", __func__, uv_err_name(r));
        return -1;
    }

    r = uv_tcp_init(&libuv_cli->loop, &libuv_cli->client);
    if (r != 0) {
        log_error("%s, uv_tcp_init error %s\n", __func__, uv_err_name(r));
        return -1;
    }

    r = uv_ip4_addr("127.0.0.1", PORT_NUM, &libuv_cli->addr);
    log_info("Connect to %s:%d\n", inet_ntoa(libuv_cli->addr.sin_addr), htons(libuv_cli->addr.sin_port));
    if (r != 0) {
        log_error("%s, uv_ip4_addr error %s\n", __func__, uv_err_name(r));
        return -1;
    }

    r = uv_tcp_connect(&libuv_cli->connect_req, &libuv_cli->client, &libuv_cli->addr, connect_cb);
    if (r != 0) {
        log_error("%s, uv_tcp_connect error %s\n", __func__, uv_err_name(r));
        return -1;
    }

    r = uv_run(&libuv_cli->loop, UV_RUN_DEFAULT);
    if (r != 0) {
        log_error("%s, uv_run error %s\n", __func__, uv_err_name(r));
        return -1;
    } 

    return 0;

}