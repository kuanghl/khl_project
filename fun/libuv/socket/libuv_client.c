#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

#pragma comment(lib,"uv.lib")

#define DEFAULT_PORT 7000
#define DEFAULT_BACKLOG -1

uv_loop_t *loop;
struct sockaddr_in addr;
uv_tcp_t client;

typedef struct {
	uv_write_t req;
	uv_buf_t buf;
} write_req_t;

void free_write_req(uv_write_t *req) {
	write_req_t *wr = (write_req_t*)req;
	free(wr);
}

void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
	buf->base = (char*)malloc(suggested_size);
	buf->len = suggested_size;
}

void echo_write(uv_write_t* req, int status) {
	if (status) {
		fprintf(stderr, "Write error %s\n", uv_strerror(status));
	}
	free_write_req(req);
}

void read_client_cb(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
	if (nread > 0) {
		printf("get message from server: %.*s\n", nread, buf->base);
		return;
	}
	if (nread < 0) {
		if (nread != UV_EOF)
			fprintf(stderr, "Read error %s\n", uv_err_name(nread));
		uv_close((uv_handle_t*)client, NULL);
	}

	free(buf->base);
}


void on_connect(uv_connect_t* req, int status)
{

	if (status < 0)
	{
		fprintf(stderr, "Connection error %s\n", uv_strerror(status));
		return;
	}

	uv_read_start((uv_stream_t*)req->handle, alloc_buffer, read_client_cb);

	uv_write_t* uvreq = (uv_write_t*)malloc(sizeof(uv_write_t));

	char* str = "hello server, this is client!";

	uv_buf_t uvBuf = uv_buf_init(str, strlen(str));

	uv_write(uvreq, req->handle, &uvBuf, 1, echo_write);

	uv_tcp_t *client = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
	uv_tcp_init(loop, client);

	fprintf(stdout, "Connect ok\n");

}

int main() {

	loop = uv_default_loop();

	uv_tcp_init(loop, &client);

	uv_connect_t* connect = (uv_connect_t*)malloc(sizeof(uv_connect_t));

	uv_ip4_addr("127.0.0.1", DEFAULT_PORT, &addr);

	int r = uv_tcp_connect(connect, &client, (const struct sockaddr*)&addr, on_connect);

	if (r)
	{
		fprintf(stderr, "connect error %s\n", uv_strerror(r));
		return 1;
	}

	uv_run(loop, UV_RUN_DEFAULT);

	return 0;
}