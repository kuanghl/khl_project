#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>


void on_alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);
void on_new_connection(uv_connect_t *req, int status);
void on_complete_write(uv_write_t *req, int status);
void on_echo_read(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf);


int main()
{

    uv_tcp_t* client = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
    uv_tcp_init(uv_default_loop(), client);

    uv_connect_t *connect = (uv_connect_t*)malloc(sizeof(uv_connect_t));

    struct sockaddr_in dest;
    uv_ip4_addr("127.0.0.1", 7000, &dest);

    uv_tcp_connect(connect, client, (const struct sockaddr*)&dest, on_new_connection);

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    return 0;
}

void on_alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf)
{
    buf->base = (char*)malloc(suggested_size);
    buf->len = suggested_size;
}

void on_new_connection(uv_connect_t *connection, int status)
{
    fprintf(stdout, "new connection\n");
    if(status < 0) {
        fprintf(stderr, "on_new_connection error %s\n", uv_strerror(status));

        uv_close((uv_handle_t*)connection->handle, NULL);

        free(connection->handle);
        free(connection);
        return;
    }

    char buffer[100] = "hello server";
    int len = strlen(buffer);

    uv_buf_t req_buf = uv_buf_init(buffer, len);

    uv_write_t req;
    uv_write(&req, (uv_stream_t*)connection->handle, &req_buf, 1, on_complete_write);
}

void on_complete_write(uv_write_t *req, int status)
{
    fprintf(stdout, "on_complete..\n");

    if( status < 0 )
    {
        fprintf(stderr, "write error %s\n", uv_strerror(status));
        uv_close((uv_handle_t*)req->handle, NULL);
        return;
    }

    uv_read_start((uv_stream_t*)req->handle, on_alloc_buffer, on_echo_read);
}

void on_echo_read(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf)
{
    if( nread == 0)
    {
        fprintf(stderr, "EAGAIN or EWOULDBLOCK\n");
        return;
    }
    else if( nread < 0 )
    {
        fprintf(stderr, "on echo read error %s\n", uv_strerror(nread));
        uv_close((uv_handle_t*)stream, NULL);
        return;
    }
    else if ( nread == UV_EOF)
    {
        fprintf(stderr, "%s\n", uv_strerror(nread));
        return;
    }

    printf("%s\n", buf->base);
    free(buf->base);
    uv_close((uv_handle_t*)stream, NULL);
}