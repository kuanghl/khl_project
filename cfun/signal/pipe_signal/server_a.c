/*
server：
        1.socket()    创建socket
        2.bind()      绑定服务器地址结构
        3.listen()    设置监听上限
        4.accept()    阻塞监听客户端连接
        5.read(fd)    读socket获取客户端数据
        6.小--大写     toupper()
        7.write(fd)      
        8.close(); 

server端代码示例：
*/
 #include<stdio.h>
 #include<ctype.h>
 #include<sys/socket.h>
 #include<arpa/inet.h>
 #include<string.h>
 #include<stdlib.h>
 #include<fcntl.h>
 #include<errno.h>
 #include<unistd.h>
 #include<pthread.h>

 #define SERV_PORT 9527

 void sys_err(const char *str)
 {
     perror(str);
     exit(1);
 }

 int main(int argc,char *argv[])
 {   
     int lfd=0,cfd=0;
     int ret,i;
     char buf[BUFSIZ],client_IP[1024];
     
     printf("Starting server...\n");

     struct sockaddr_in serv_addr,clit_addr;
     socklen_t clit_addr_len;
     
     printf("1. Creating socket...\n");
     serv_addr.sin_family=AF_INET;
     serv_addr.sin_port=htons(SERV_PORT);
     serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

     lfd=socket(AF_INET,SOCK_STREAM,0);
     if(lfd==-1){
         sys_err("socket error");
     }
     printf("   Socket created.\n");

     printf("2. Binding address...\n");
     bind(lfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
     printf("   Binded.\n");

     printf("3. Listening to port...\n");
     listen(lfd,128);
     printf("  Listening.\n");

     clit_addr_len=sizeof(clit_addr);
     
     printf("4. Waiting for client connection.\n");
     cfd=accept(lfd,(struct sockaddr *)&clit_addr,&clit_addr_len);
     if(cfd==-1)
         sys_err("accept error");
     printf("   One client connected.\n");
     printf("   This is server pid: %d\n",getpid());
     printf("client ip:%s port:%d\n",inet_ntop(AF_INET,&clit_addr.sin_addr.s_addr,client_IP,
                 sizeof(client_IP)),ntohs(clit_addr.sin_port));
     while(1){
	 //printf("4. Receiving message from client...\n");    
         ret=read(cfd,buf,sizeof(buf));
         //printf("   Message received: %s\n", buf);

         write(STDOUT_FILENO,buf,ret);

         for(i=0;i<ret;i++)
             buf[i]=toupper(buf[i]);
         
         //printf("5. Responing client...\n");
         write(cfd,buf,ret);
	 //printf("   Message sent: %s\n", buf);
     }
     printf("6. Closing server socket...\n");   
     close(lfd);
     printf("   Socket closed.\n");
     printf("7. Closing client socket...\n");
     close(cfd);
     printf("   Socket closed.\n");

     return 0;
 }   
