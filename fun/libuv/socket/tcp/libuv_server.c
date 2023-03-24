#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <uv.h>

static uv_loop_t *loop;

static void on_close(uv_handle_t* handle) {
    free(handle);
}

static void on_response_callback(uv_write_t* req, int status) {

    if (status < 0) {
        fprintf(stderr, "failed to response world to client, err: %s\n", uv_strerror(status));
    } else {
        printf("succeeded in responsing world to client\n");
        return;
    }

    fprintf(stderr, "uv_write error: %s\n", uv_strerror(status));

    if (status == UV_ECANCELED)
        return;

    assert(status == UV_EPIPE);
    uv_close((uv_handle_t*)req->handle, on_close);
    free(req);
}

void on_new_connection(uv_stream_t *conn, int status) {
    int r;
    uv_write_t wr;

    if (status < 0) {
        fprintf(stderr, "failed to create new connection, err: %s\n", uv_strerror(status));
        return;
    }

    uv_tcp_t *client = malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop, client);
    if ((r = uv_accept(conn, (uv_stream_t *)client)) != 0) {
        printf("failed to accept a new connection, err: %s\n", uv_strerror(r));
        return;
    }

    uv_buf_t b[] = {
        {.base = "world", .len = 5}
    };

    if ((r = uv_write(&wr, (uv_stream_t *)client, b, 1, on_response_callback)) != 0) {
        printf("failed to response world to client, err: %s\n", uv_strerror(r));
    }
}

int main(void) {
    struct sockaddr_in addr;
    uv_tcp_t server;
    int res = 0;

    loop = uv_default_loop();

    uv_tcp_init(loop, &server);

    if ((res = uv_ip4_addr("127.0.0.1", 10086, &addr)) != 0) {
        printf("failed to init listening address, err: %s\n", uv_strerror(res));
        return 1;
    }

    if ((res = uv_tcp_bind(&server, (const struct sockaddr *)&addr, 0)) != 0) {
        printf("failed to bind the listening address, err: %s\n", uv_strerror(res));
        return 2;
    }

    if ((res = uv_listen((uv_stream_t *)&server, 5, on_new_connection)) != 0) {
        printf("failed to listen on the address, err: %s\n", uv_strerror(res));
        return 3;
    }

    return uv_run(loop, UV_RUN_DEFAULT);
}