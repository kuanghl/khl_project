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



void handler(int num)
{
    static i=0;
    i++;
    printf("The %d times receive signal!\n", i);
}

int main(int argc, char* argv[])
{
    int pid=-1;
    int ret;
    
    signal(SIGUSR1, handler);
    signal(SIGUSR2, NULL);
    
    while(1);
    return 0;
}


