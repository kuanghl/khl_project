#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
 
typedef void (*sighandler_t)(int);
unsigned char tmp_flag = 0;
 
void signal_fcuntion(int num)    //立即响应
{
    printf("signal_fcuntion:%d\n",num);
    tmp_flag=1;
}
 
int main(int argc,char *argv[])
{
    sighandler_t p = signal(SIGINT, signal_fcuntion);
    while(1)
    {
        printf("我还活着\n");
        sleep(1);
	if(tmp_flag == 1)
	{
		break;
	}
    }
    
    return 0;
}
