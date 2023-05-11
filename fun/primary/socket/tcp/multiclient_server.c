#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <fcntl.h>
#include <pthread.h>

// #include <sys/poll.h>
// #include <sys/epoll.h>

#define BUFFER_LENGTH 1024

#define POLL_SIZE 1024

#define CLIENT_MAX_NUM 2048

// 1 connection 1 thread
void *client_thread(void *arg)
{

    int clientfd = *(int *)arg;

    while (1)
    { // slave

        char buffer[BUFFER_LENGTH] = {0};
        int ret = recv(clientfd, buffer, BUFFER_LENGTH, 0);
        if (ret == 0)
        {
            close(clientfd);
            break;
        }

        printf("ret: %d, buffer: %s\n", ret, buffer);

        send(clientfd, buffer, ret, 0);
    }
}

int main()
{
  pthread_t threadid[2048];
  uint16_t tid_num;
  // 创建socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(struct sockaddr_in)); // 清空
  servaddr.sin_family = AF_INET;                    // 设置协议族为 IPV4
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);     // 0.0.0.0
  servaddr.sin_port = htons(9999);                  // 监听端口为 9999

  // 绑定好初始化的信息，出错就打印出错信息
  if (-1 == bind(sockfd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr)))
  {
      printf("bind failed: %s", strerror(errno));
      return -1;
  }

  // 监听绑定好的信息
  listen(sockfd, 128);
#if 0
  // 将socket设置为非阻塞
  int flags = fcntl(sockfd, F_GETFL, 0);
  flags |= O_NONBLOCK;
  fcntl(sockfd, F_SETFL, flags);
#endif
  // 为了保存 client的信息锁创建的结构
  struct sockaddr_in clientaddr;
  socklen_t len = sizeof(clientaddr);
  while (1)
  { // master
      int clientfd = accept(sockfd, (struct sockaddr *)&clientaddr, &len);
#if 0 
		char buffer[BUFFER_LENGTH] = {0};
		int ret = recv(clientfd, buffer, BUFFER_LENGTH, 0);

		printf("ret: %d, buffer: %s\n", ret, buffer);

		send(clientfd, buffer, ret, 0);
#else
    if(tid_num < CLIENT_MAX_NUM){
      pthread_create(&threadid[tid_num++], NULL, client_thread, &clientfd);
    }
#endif
  }

  for(tid_num = 0; tid_num < CLIENT_MAX_NUM; tid_num++){
    pthread_cancel(threadid[tid_num]);
    pthread_join(threadid[tid_num], NULL);
  }
  
  getchar(); // block
  return 0;
}