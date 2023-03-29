#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/ipc.h>

int getPidByName(pid_t *pid, char *task_name);
int getNameByPid(pid_t pid, char *task_name);

int getPidByName(pid_t *pid, char *task_name)
{
    
    ////1. open the /proc , and every read, it will return the next dir struct dirent
    DIR * dirp;
    dirp = opendir("/proc");
    if(NULL == dirp)
    {
        perror("opendir");
        return -1;
    }

    //2.read the directory
    struct dirent *dp;
    while(NULL != (dp = readdir(dirp)))
    {
        //if direactory is . or .. or not a direct, skip
        if((dp->d_name == ".") || (dp->d_name == ".."))
            continue;
        if(DT_DIR != dp->d_type)
            continue;
        
        //open the /proc/pid/status file
        char fileName[128];
        FILE *fd ;
        sprintf(fileName, "/proc/%s/status", dp->d_name);
        fd = fopen(fileName, "r");
        
        if(NULL != fd)
        {
            //copy the /proc/pid/status content to buf
            char buf[128];
            fgets(buf, sizeof(buf), fd);
            
            //
            char cur_task[32] ;
            sscanf(buf, "%*s%s", cur_task);

            if(!strcmp(cur_task, task_name))
            {
                sscanf(dp->d_name, "%d", pid);
            }
        }
    }

    return 0;
}



int getNameByPid(pid_t pid, char *task_name)
{
    char fileName[128];
    sprintf(fileName, "/proc/%d/status", pid);

    FILE *fd;
    fd  = fopen(fileName, "r");
    if(NULL == fd)
    {
        perror("fopen");
        return -1;
    }
    
    char buf[128];
    fgets(buf, sizeof(buf), fd);
    sscanf(buf, "%*s%s", task_name);

    return 0;
    
}


#define TAR_TASK "server"

int main(int argc, char* argv[])
{
    int pid=-1;
    int ret;
    

    //get the server task pid
    ret = getPidByName(&pid, TAR_TASK);
    if((-1 == ret) || (-1 == pid))
    {
        printf("getPidByName was failed!\n");
        exit(EXIT_FAILURE);
    }

    printf("The task %s: pid=%d\n", TAR_TASK, pid);

    
    //Send a signal to server every 1 second
    int i=0;
    while(i < 10)
    {
        kill(pid,SIGUSR1);
        i++;
        printf("send %d times signal!\n", i);
        sleep(1);
    }
    
    printf("\nEnd the server and myself!\n");
    kill(pid, SIGUSR2);
    kill(getpid(), SIGSTOP);
   
    return 0;
}



