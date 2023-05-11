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
#include <errno.h>

#include <fcntl.h>
#include <sys/select.h>
#include <sys/epoll.h>

#define PORT 9502
//#define IP "127.0.0.1"
#define IP "192.168.20.20"
#define MAXDATASIZE 256

#if 0
/*通过检测socket端是否可读可写判断连接状态，0成功/-1失败*/
int connect_wait(int __fd, const struct sockaddr *__addr, socklen_t __len, struct timeval *__timeout){
	fd_set r_set_e, w_set_e;
	int __fd_optval;
	socklen_t len = sizeof(__fd_optval);
	int r;

	FD_ZERO(&r_set_e);
	FD_SET(__fd, &r_set_e);
	w_set_e = r_set_e;
	if((r = select(__fd + 1, &r_set_e, &w_set_e, NULL, __timeout)) == 0){
		close(__fd);
		printf("%s error--%s.\n", __func__, strerror(errno));
		return -1;
	}
	if(FD_ISSET(__fd, &r_set_e)){
		if(getsockopt(__fd, SOL_SOCKET, SO_ERROR, &__fd_optval, &len) < 0){
			printf("%s error--%s.\n", __func__, strerror(errno));
			return -1;
		}
	}
	if(FD_ISSET(__fd, &w_set_e)){
		if(getsockopt(__fd, SOL_SOCKET, SO_ERROR, &__fd_optval, &len) < 0){
			printf("%s error--%s.\n", __func__, strerror(errno));
			return -1;
		}
	}
	return 0;
}
#else 
/*epoll超时等待connect(ms)*/
int connect_wait(int __fd, const struct sockaddr *__addr, socklen_t __len, int __timeout){
	struct epoll_event __fd_event;
	struct epoll_event __fd_event_arr[16];
	int __fd_optval;
	socklen_t len = sizeof(__fd_optval);
	int ep_fd;
	int n;
	int r;

	__fd_event.events = (uint32_t) (EPOLLIN | EPOLLOUT | EPOLLET);
	__fd_event.data.fd = __fd;

	ep_fd = epoll_create(16);
	if(ep_fd == -1){
		printf("%s error--%s.\n", __func__, strerror(errno));
		return -1;
	}

	r = epoll_ctl(ep_fd, EPOLL_CTL_ADD, __fd, &__fd_event);
	if(r == -1){
		printf("%s error--%s.\n", __func__, strerror(errno));
		return -1;
	}

	n = epoll_wait(ep_fd, __fd_event_arr, 16, __timeout);
	if(n == -1){
		printf("%s error--%s.\n", __func__, strerror(errno));
		return -1;
	}
	for(int i = 0; i < n; i++){
		r = __fd_event_arr[i].events;
		if((r & EPOLLERR) || (getsockopt(__fd, SOL_SOCKET, SO_ERROR, &__fd_optval, &len) < 0)){
			printf("%s error--%s.\n", __func__, strerror(errno));
			return -1;
		}
		if((r & EPOLLIN) || (r & EPOLLOUT)){
			return 0;
		}
	}
	return 0;
}
#endif

int main(int argc, char *argv[])
{
	int r;
	int sockfd, num;
	uint64_t timeout = 400*1000*10; 
    struct timeval tv;
	tv.tv_sec = 1;
	tv.tv_usec = 100;
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

	if((sockfd = socket(PF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0)) < 0)
	{
		printf("socket() error.\n");
		exit(1);
	}

	bzero(&server, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_port = htons(PORT);
	server.sin_addr.s_addr = inet_addr(IP);
#if 0
do_connect:
	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
        if(timeout--){
            if(timeout % 100000 == 0){ 
                printf("waiting for server...\n");
            }
            goto do_connect;
        }
        else{
            printf("connect() error.\n");
		    exit(1);
        }
	}
	printf("Connected to server:IP: %s, PORT: %d.\n", inet_ntoa(server.sin_addr), ntohs(server.sin_port));
#elif 1
	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){
		if(errno != EINPROGRESS){
			printf("connect error0--%s.\n", strerror(errno));
			return -1;
		}
	}

	r = connect_wait(sockfd, (struct sockaddr *)&server, sizeof(server), 10000);
	if(r < 0){
		printf("connect error1--%s.\n", strerror(errno));
		return -1;
	}else{
		printf("timeout to connected.\n");
	}
#elif 0

	while(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0){
		if(!(timeout--)){
			printf("connect() error.\n");
		    exit(1);
		}
	}
#endif
	fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFL) & (~O_NONBLOCK));
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