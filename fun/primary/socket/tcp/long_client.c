//客户端程序：
//向服务端发送字符串，经过大小写变换后返回。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <pthread.h>

#define PORT 1234
#define IP "127.0.0.1"
#define MAXDATASIZE 256

int main(int argc, char *argv[])
{
	int sockfd, num;
    uint32_t timeout = 1000;
	char buf_from[MAXDATASIZE];
    char buf_to[MAXDATASIZE] = "hello world! I am client";
	// struct hostent *he;
	struct sockaddr_in server;

	// if(argc != 2)
	// {
	// 	printf("Usage: %s <IP Address>\n", argv[0]);
	// 	exit(1);
	// }

	// if((he = gethostbyname(argv[1])) == NULL)
	// {
	// 	printf("gethostbyname() error.\n");
	// 	exit(1);
	// }

	if((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("socket() error.\n");
		exit(1);
	}

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr(IP);

do_connect:
	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
        if(timeout--){
            if(timeout % 100 == 0){ 
                printf("waiting for server...\n");
            }
            usleep(10000);
            goto do_connect;
        }
        else{
            printf("connect() error.\n");
		    exit(1);
        }
	}
	printf("Connected to server:IP: %s, PORT: %d.\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port));
	
    while(1){
        num = send(sockfd, &buf_to, sizeof(buf_to), MSG_DONTWAIT);
        printf("client send: buf size = %d, %s.\n", num, &buf_to);     
        num = recv(sockfd, &buf_from, sizeof(buf_from), 0);
        printf("client recv: buf size = %d, %s.\n", num, &buf_from);
        num = send(sockfd, &buf_to, sizeof(buf_to), MSG_DONTWAIT);
        printf("client send: buf size = %d, %s.\n", num, &buf_to);
        close(sockfd);
        break;
	}
    printf("disconnect.\n");

	//close(sockfd);
	return 0;
}