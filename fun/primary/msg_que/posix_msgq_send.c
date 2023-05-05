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
    unsigned int iprio;
    struct mq_attr attr;
    attr.mq_maxmsg = 5;
    attr.mq_msgsize = 8192;
    // if (argc!=4)
    // {
    //     printf("usage: ./ipc_posix_mq_send <mq name> <message> <priority>\n");
    //     exit(0);
    // }
    iprio = 0;
    
    mqID = mq_open(POSIX_MSGQ_NAME, O_RDWR | O_CREAT, 0666, &attr);
    if (mqID < 0)
    {
        printf("open message queue %s error[%s]\n", POSIX_MSGQ_NAME, strerror(errno));
        return -1;
    }
    for(int i = 0; i < 100; i++){
        printf("sn: %d, open message queue succ, mqID = %d\n", i, mqID);
        mq_send(mqID, argv[1], strlen(argv[1]), iprio);
    }

    return 0;
}

