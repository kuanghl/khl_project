//服务端程序
//接收客户端字符串，将其大小写变换后返回。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define PORT 1234
#define BACKLOG 16
#define MAXDATASIZE 256

struct ipc_server_s{
    int listenfd;
    int connectfd;
	struct sockaddr_in server;
	struct sockaddr_in client;
	socklen_t addrlen;
    char buf_to[MAXDATASIZE];
    char buf_from[MAXDATASIZE];
    uint8_t connect_status;
    uint8_t serv_status;
};

void server_exit(struct ipc_server_s *serv){
    printf("server_exit.\n");
}

void server_init(struct ipc_server_s *serv){
    uint32_t num;
    strcpy(serv->buf_from, "hello, come in server tid");

    pthread_cleanup_push(server_exit, (void *)serv);

	if((serv->listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket() error.\n");
		exit(1);
	}

	bzero(&serv->server, sizeof(serv->server));
	serv->server.sin_family = AF_INET;
	serv->server.sin_port = htons(PORT);
	serv->server.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(serv->listenfd, (struct sockaddr *)&serv->server, sizeof(serv->server)) < 0)
	{
		perror("Bind() error.\n");
		exit(1);
	}

	if(listen(serv->listenfd, BACKLOG) < 0)
	{
		perror("listen() error.\n");
		exit(1);
	}

    while (1)
    {  
        if(serv->connect_status == 0){
            serv->addrlen = sizeof(serv->client);
            if((serv->connectfd = accept(serv->listenfd, (struct sockaddr *)&serv->client, &serv->addrlen)) < 0){
                perror("accept() error\n");
                exit(1);
            }else{
                printf("You got a connection from client's ip is %s, port is %d.\n",inet_ntoa(serv->client.sin_addr),ntohs(serv->client.sin_port));
                num = send(serv->connectfd, &serv->buf_from, sizeof(serv->buf_from), MSG_DONTWAIT);
                printf("client send: buf size = %d, %s.\n", num, &serv->buf_from);
                serv->connect_status = 1;
            }
        }else{
            num = recv(serv->connectfd, &serv->buf_to, sizeof(serv->buf_to), 0);
            printf("serv recv: buf size = %d, %s.\n", num, &serv->buf_to);
            // num = send(serv->connectfd, &serv->buf, sizeof(serv->buf), MSG_DONTWAIT);
            // printf("client send: buf size = %d, %s.\n", num, &serv->buf);
            if(num <= 0){
                serv->connect_status = 0;
            }
        }
        if(serv->serv_status){
            break;
        }
    }

    pthread_cleanup_pop(0);
}

int main(int argc, char *argv[])
{
    struct ipc_server_s serv;
    uint32_t num;
    char buf[MAXDATASIZE] = "hello, I am server";
    memset(&serv, 0, sizeof(serv));
    pthread_t server_tid;

    pthread_create(&server_tid, NULL, server_init, &serv);

    sleep(4);
    if(serv.connect_status){
        num = send(serv.connectfd, &buf, sizeof(buf), MSG_DONTWAIT);
        printf("client send: buf size = %d, %s.\n", num, &buf);
    }
    sleep(4);
    if(serv.connect_status){
        num = send(serv.connectfd, &buf, sizeof(buf), MSG_DONTWAIT);
        printf("client send: buf size = %d, %s.\n", num, &buf);
    }
    sleep(4);
    if(serv.connect_status){
        num = send(serv.connectfd, &buf, sizeof(buf), MSG_DONTWAIT);
        printf("client send: buf size = %d, %s.\n", num, &buf);
    }
    sleep(4);
    if(serv.connect_status){
        num = send(serv.connectfd, &buf, sizeof(buf), MSG_DONTWAIT);
        printf("client send: buf size = %d, %s.\n", num, &buf);
    }
    // sleep(4);

	// close(serv.connectfd);
	// close(serv.listenfd);
    // shutdown(serv.connectfd, SHUT_RDWR);
    // shutdown(serv.listenfd, SHUT_RDWR);

    // serv.serv_status = 1;
    // pthread_cancel(server_tid);
    pthread_join(server_tid, NULL);
    printf("end server.\n");
	return 0;
}