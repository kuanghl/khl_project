#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

static const int DEFAULT_BACKLOG = 10;

void on_alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);
void on_echo_read(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf);
void on_complete_write(uv_write_t *req, int status);
void on_new_connection(uv_stream_t *server, int status);

int main() 
{
    uv_tcp_t server;
    uv_tcp_init(uv_default_loop(), &server);

    struct sockaddr_in addr;

    uv_ip4_addr("0.0.0.0", 7000, &addr);

    uv_tcp_bind(&server, (const struct sockaddr*)&addr, 0);
    int r = uv_listen((uv_stream_t*)&server, DEFAULT_BACKLOG, on_new_connection);
    if(r) {
        fprintf(stderr, "Listen error %s\n", uv_strerror(r));
        return 1;
    }
    printf("server end?\n");

    uv_run(uv_default_loop(), UV_RUN_DEFAULT);

    return 0;
}

void on_alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf)
{
  buf->base = (char*)malloc(suggested_size);
  buf->len = suggested_size;
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
        if(nread == UV_EOF){
            uv_close((uv_handle_t*)stream, NULL);
        } 
        else {
            fprintf(stderr, "on echo read error %s\n", uv_strerror(nread));
        }
        return;
    } 
    printf("%s\n", buf->base);
    free(buf->base);

    char buffer[100] = "hello world";
    int len = strlen(buffer);

    uv_buf_t req_buf = uv_buf_init(buffer, len);

    uv_write_t req;
    uv_write(&req, (uv_stream_t*)stream, &req_buf, 1, on_complete_write);
}

void on_complete_write(uv_write_t *req, int status)
{
    if( status < 0 )
    {
        fprintf(stderr, "write error %s\n", uv_strerror(status));
        uv_close((uv_handle_t*)req->handle, NULL);
        return;
    }
    //uv_close((uv_handle_t*)test, NULL);
}

void on_new_connection(uv_stream_t *server, int status)
{
    if(status < 0 ) {
        fprintf(stderr, "New Connection error %s\n", uv_strerror(status));
        return;
    }

    uv_tcp_t *client = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
    uv_tcp_init(uv_default_loop(), client);

    int r = uv_accept(server, (uv_stream_t*)client);
    if(r < 0){
        fprintf(stderr, "Accept error %s\n", uv_strerror(r));
        uv_close((uv_handle_t*)client, NULL);
        free(client);
    }
    else {
        uv_read_start((uv_stream_t*)client, on_alloc_buffer, on_echo_read);
    }
}