#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>


#define POSIX_MSGQ_NAME "/posix_msgq"

int main(int argc, char** argv)
{
    mqd_t mqID;
    struct mq_attr mqAttr;
    unsigned int iprio;
    unsigned int n;
    static int i = 0;
    char buff[8192];
    
    // if (argc!=2)
    // {
    //     printf("usage: ./ipc_posix_mq_recv <mq name>\n");
    //     exit(0);
    // }
    
    mqID = mq_open(POSIX_MSGQ_NAME, O_RDONLY, 0666, NULL);
    if (mqID < 0)
    {
        printf("open message queue %s error[%s]\n", POSIX_MSGQ_NAME, strerror(errno));
        return -1;
    }
    mq_getattr(mqID, &mqAttr);
    while(1)
    {
        n = mq_receive(mqID, buff, mqAttr.mq_msgsize, NULL);
        printf("sn:%d, read from mq`s msg = %s\n", i, buff);
        i++;
    }
    return 0;
}