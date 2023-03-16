/*
头文件: #include<sys/types.h>

#include<signal.h>

函数原型: int kill(pid_t pid,int sig);

函数功能: kill（）可以用来送参数 sig 指定的信号给参数 pid 指定的进程。参数 pid 有几种情况：

pid>0 将信号传给进程识别码为 pid 的进程。

pid=0 将信号传给和目前进程相同进程组的所有进程

pid=-1 将信号广播传送给系统内所有的进程

pid<0 将信号传给进程组识别码为 pid 绝对值的所有进程

返回值: 执行成功则返回 0，如果有错误则返回-1。
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main( void )
{
    pid_t childpid;
    int status;
    int retval;

    childpid = fork();
    if ( -1 == childpid )
    {
        perror( "fork()" );
        exit( EXIT_FAILURE );
    }
    else if ( 0 == childpid )
    {
        puts( "In child process" );
        sleep( 3 );//让子进程睡眠，看看父进程的行为
        exit(EXIT_SUCCESS);
    }
    else
    {
       // waitpid( childpid, &status, 0);
        if ( 0 == (waitpid( childpid, &status, WNOHANG )))
        {
	    sleep(1);
            retval = kill( childpid,SIGKILL );

            if ( retval )
            {
                puts( "kill failed." );
                perror( "kill" );
                waitpid( childpid, &status, 0 );
            }
            else
            {
                printf( "%d killed\n", childpid );
            }

        }
    }

    exit(EXIT_SUCCESS);
}
