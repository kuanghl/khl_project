/* 
 *  fork_test.c 
 *  version 2 
 *  Created on: 2010-5-29 
 *      Author: wangth 
 */  
#include <unistd.h>  
#include <stdio.h>  
#include <sys/types.h>

int main(void)  
{  
   int i=0;  
   printf("i son/pa ppid pid  fpid.\n");  
   //ppid指当前进程的父进程pid  
   //pid指当前进程的pid,  
   //fpid指fork返回给当前进程的值  
   for(i=0;i<4;i++){  
       pid_t fpid=fork();  
       if(fpid==0)  
           printf("i = %d child : ppid = %8d, pid = %8d, fpid = %8d.\n",i,getppid(),getpid(),fpid);  
       else  
           printf("i = %d parent: ppid = %8d, pid = %8d, fpid = %8d.\n",i,getppid(),getpid(),fpid);  
   }  
   return 0;  
}  