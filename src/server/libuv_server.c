#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

#pragma comment(lib,"uv.lib")

#define DEFAULT_PORT 7000
#define DEFAULT_BACKLOG -1

uv_loop_t *loop;
struct sockaddr_in addr;

void free_write_req(uv_write_t *req) {
	free(req);
}

void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
	buf->base = (char*)malloc(suggested_size);
	buf->len = suggested_size;
}

void write_client_cb(uv_write_t* req, int status) {
	if (status) {
		fprintf(stderr, "Write error %s\n", uv_strerror(status));
	}
	free_write_req(req);
}

void read_client_cb(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
	if (nread > 0) {
		printf("get message from client: %.*s\n", nread, buf->base);
		char* str = "hello client, this is server!";
		printf("write message to client: %.*s\n", nread, str);

		uv_write_t* uvreq = (uv_write_t*)malloc(sizeof(uv_write_t));

		uv_buf_t uvBuf = uv_buf_init(str, strlen(str));
		uv_write(uvreq, client, &uvBuf, 1, write_client_cb);

		return;
	}
	if (nread < 0) {
		if (nread != UV_EOF)
			fprintf(stderr, "Read error %s\n", uv_err_name(nread));
		uv_close((uv_handle_t*)client, NULL);
	}

	free(buf->base);
}

void on_new_connection(uv_stream_t *server, int status) {
	if (status < 0) {
		fprintf(stderr, "New connection error %s\n", uv_strerror(status));
		return;
	}

	uv_tcp_t *client = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
	uv_tcp_init(loop, client);

	//4.uv_accept接收链接。
	//5.使用stream处理来和客户端通信。
	if (uv_accept(server, (uv_stream_t*)client) == 0) {
		uv_read_start((uv_stream_t*)client, alloc_buffer, read_client_cb);
	}
	else {
		uv_close((uv_handle_t*)client, NULL);
	}
}

int main() {
	//1.uv_tcp_init建立tcp句柄
	loop = uv_default_loop();
	uv_tcp_t server;
	uv_tcp_init(loop, &server);

	//2.uv_tcp_bind绑定。
	uv_ip4_addr("127.0.0.1", DEFAULT_PORT, &addr);
	uv_tcp_bind(&server, (const struct sockaddr*)&addr, 0);

	//3.uv_listen建立监听，当有新的连接到来时，激活调用回调函数。
	int r = uv_listen((uv_stream_t*)&server, DEFAULT_BACKLOG, on_new_connection);
	if (r) {
		fprintf(stderr, "Listen error %s\n", uv_strerror(r));
		return 1;
	}
	uv_run(loop, UV_RUN_DEFAULT);
	return 0;
}