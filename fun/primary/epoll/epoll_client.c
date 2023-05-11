/*client 多路复用socket*/
#include <stdio.h>    
#include <sys/types.h>    
#include <sys/socket.h>    
#include <netinet/in.h>    
#include <arpa/inet.h>
#include <sys/epoll.h> 
#include <errno.h>     
#include <string.h>  
#include <stdlib.h> 
#include <fcntl.h> 

#define EPOLLEVENTS 20
#define MAXSIZE 1024

static void add_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev);
}

static void delete_event(int epollfd,int fd,int state)
{
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,&ev);
}

static void handle_events(int epollfd,struct epoll_event *events,int num)
{
    int fd;
    int i;
    static int j = 0;
    static int k = 0;
    char ip[32] = {0};
    for (i = 0;i < num;i++)
    {
        k++;
        fd = events[i].data.fd;
        if (events[i].events & EPOLLIN){
            printf("do_read : %d\n", k);
        }
            //do_read(epollfd,fd,sockfd,buf);
        else if (events[i].events & EPOLLOUT){
            printf("do_write : %d\n", k);
            //do_write(epollfd,fd,sockfd,buf);
        }else{
            printf("other op : %d\n", k);
        }

        struct sockaddr_in sa;
        int len = sizeof(sa);
        if(!getpeername(fd, (struct sockaddr *)&sa, &len))
        {
            j++;
            printf( "==ip%s %d\n", inet_ntoa(sa.sin_addr),j);
        }

        delete_event(epollfd,fd,EPOLLIN | EPOLLOUT | EPOLLET);
        close(fd);
    }
}

int init_connect(int epollfd, char *ip, int port)
{
    int satate;   
    int client_sockfd;     
    int len;     
    struct sockaddr_in remote_addr; // 服务器端网络地址结构体     
    memset(&remote_addr,0,sizeof(remote_addr)); // 数据初始化--清零     
    remote_addr.sin_family=AF_INET; // 设置为IP通信     
    remote_addr.sin_addr.s_addr=inet_addr(ip);// 服务器IP地址     
    remote_addr.sin_port=htons(port); // 服务器端口号     
    // 创建客户端套接字--IPv4协议，面向连接通信，TCP协议   
    if((client_sockfd=socket(PF_INET,SOCK_STREAM,0))<0)     
    {     
        perror("client socket creation failed");     
        return -1; 
    } 
    //设置非阻塞socket
    int flags;
    flags = fcntl(client_sockfd, F_GETFL, NULL);
    fcntl(client_sockfd, F_SETFL, flags | O_NONBLOCK);

    // 将套接字绑定到服务器的网络地址上   
    connect(client_sockfd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr));
    if (errno != EINPROGRESS)
    {
        close(client_sockfd);
        perror("connect..2");
        return -1;
    }

    add_event(epollfd,client_sockfd,EPOLLIN | EPOLLOUT | EPOLLET);

    return 0;
}

int main(int argc, char *argv[])     
{  

    int epollfd = 0;
    struct epoll_event events[EPOLLEVENTS];
    epollfd = epoll_create(MAXSIZE);

    char ip[32] = {0};
    int i;
    for(i = 0; i < 254; ++i){
        memset(ip, 0 ,32);
        sprintf(ip,"192.168.6.%d",i);
        init_connect(epollfd, ip, 22);
    }

    int ret;
    while(1){
        //创建epoll
        ret = epoll_wait(epollfd,events,EPOLLEVENTS,-1);
        handle_events(epollfd,events,ret);
    }

    return 0;  
}