/*
* Filename: producer.c
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <signal.h>

int sem_id;

int init(void)
{
    key_t key;

    key = ftok(".", 0xFF);
    
    sem_id = semget(key, 2, IPC_CREAT|0644);
    if(-1 == sem_id)
    {
        perror("semget");
        return -1;
    }    

    return 0;
}

void del()
{
    semctl(sem_id, 0, IPC_RMID);
}

int main()
{
    struct sembuf sops[2];  //for function semop()
    sops[0].sem_num = 0;
    sops[0].sem_op = -1;     //increase 1
    sops[0].sem_flg = 0;
    
    sops[1].sem_num = 1;
    sops[1].sem_op = 1;    //decrease 1
    sops[1].sem_flg = 0;
    
    signal(SIGALRM, NULL);

    if(-1 == init())
    {
        fprintf(stderr,"init error!\n");
        exit(EXIT_FAILURE);
    }

    printf("This is customer:\n");

    while(1)
    {
        alarm(0);   //cancel the previous alarm
        alarm(10);  //set the 10s , if timeout, the process
        printf("Before consume:\n");
        printf("\tThe produce is %d\n", semctl(sem_id, 0, GETVAL));
        printf("\tThe space is %d\n", semctl(sem_id, 1, GETVAL));

        printf("\n\nNow, consuming...\n\n");

        semop(sem_id, sops, 2);

        printf("After consume:\n");
        printf("\tThe produce is %d\n", semctl(sem_id, 0, GETVAL));
        printf("\tThe space is %d\n", semctl(sem_id, 1, GETVAL));

        sleep(3);
    }

    del();

    return 0;
}

