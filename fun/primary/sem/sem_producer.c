/*
* Filename: producer.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

int sem_id;

int init(void)
{
    key_t key;
    unsigned short int sem_array[2];    //for semaphore set, [0] for produce, [1] for space

    union semun     //used for function semop()
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    }arg;

    key = ftok(".", 0xFF);
    if(-1 == key)
    {
        perror("ftok");
        return -1;
    }    
    
    sem_id = semget(key, 2, IPC_CREAT|0644);
    if(-1 == sem_id)
    {
        perror("semget");
        return -1;
    }    

    sem_array[0] = 0;
    sem_array[1] = 100;
    arg.array = sem_array;
    
    if(-1 == (semctl(sem_id, 0, SETALL, arg)))
    {
        perror("semctl");
        return -1;
    }
        
    printf("produce init is %d\n", semctl(sem_id, 0, GETVAL));
    printf("space init is %d\n", semctl(sem_id, 1, GETVAL));

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
    sops[0].sem_op = 1;     //increase 1
    sops[0].sem_flg = 0;
    
    sops[1].sem_num = 1;
    sops[1].sem_op = -1;    //decrease 1
    sops[1].sem_flg = 0;
    
    signal(SIGALRM, NULL);

    if(-1 == init())
    {
        fprintf(stderr,"init error!\n");
        exit(EXIT_FAILURE);
    }

    printf("This is producer:\n");

    while(1)
    {
        alarm(0);   //cancel the previous alarm
        alarm(10);  //set the 10s , if timeout, the process

        printf("Before produce:\n");
        printf("\tThe produce is %d\n", semctl(sem_id, 0, GETVAL));
        printf("\tThe space is %d\n", semctl(sem_id, 1, GETVAL));

        printf("\n\nNow, producing...\n\n");

        semop(sem_id, &sops[0], 1);
        semop(sem_id, &sops[1], 1);

        printf("After produce:\n");
        printf("\tThe produce is %d\n", semctl(sem_id, 0, GETVAL));
        printf("\tThe space is %d\n", semctl(sem_id, 1, GETVAL));

        sleep(2);
    }

    del();

    return 0;
}


