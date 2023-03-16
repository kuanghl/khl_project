/*
client:
        1.socket()      创建socket
        2.connect();    与服务器建立连接
        3.write()       写数据到socket
        4.read()        读转换后的数据
        5.显示读取结果
        6.close()

client端代码示例：
*/
 #include<stdio.h>
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
     int cfd;
     int conter=10;
     char buf[BUFSIZ];

     printf("Starting client...\n");
     struct sockaddr_in serv_addr;   //服务器地址结构

     printf("1. Creating socket...\n");
     serv_addr.sin_family=AF_INET;
     serv_addr.sin_port=htons(SERV_PORT);
     inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr.s_addr);
     
     cfd=socket(AF_INET,SOCK_STREAM,0);
     if(cfd==-1)
         sys_err("socket error");
     printf("   Socket created.\n");
     
     printf("2. Connecting to server...\n");
     int ret=connect(cfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr));
     if(ret !=0)
         sys_err("connect err");
     printf("   Server connected.\n");

    printf("3. Generating message to be sent...\n");
    printf("This is client pid: %d\n", getpid());
    printf("   Message: %s\n", buf);

     while(--conter){
	 printf("%x. Sending message to server...\n",(10-conter));    
         write(cfd,"hello\n",6);
	 printf("   Message sent.\n");

	 printf("%x. Receiving message from server... \n",(10-conter));
         ret=read(cfd,buf,sizeof(buf));
         printf("   Message from server: %s\n", buf);

         //write(STDOUT_FILENO,buf,ret);
         sleep(1);
     }
     printf("6. Mission complete, closing socket...\n");
     close(cfd);
     printf("   Socket closed, exit\n");

     return 0;
 }
