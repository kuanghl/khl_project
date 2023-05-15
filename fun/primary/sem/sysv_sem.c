#include<sys/ipc.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

#define NAME "./"
#define NAME_ID 3

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

//初始化信号量
int init_sem(int sem_id,int init_value)
{
	union semun sem_union;
	sem_union.val = init_value;
	if(semctl(sem_id,0,SETVAL,sem_union) == -1)
	{
		printf("Initialize semaphore.\n");
		return -1;
	}
	return 0;
}

//删除信号量
int del_sem(int sem_id)
{
	union semun sem_union;
	if(semctl(sem_id,0,IPC_RMID,sem_union) == -1)
	{
		perror("Delete semahore.\n");
		return -1;
	}
}

int get_semval(int sem_id) {
    union semun sem_union;
    return semctl(sem_id, 0, GETVAL, sem_union);
}

// p 操作
int sem_p(int sem_id)
{
	struct sembuf sops;
	sops.sem_num = 0;//单个信号量的编号应该为0
	sops.sem_op = -1;//表示 p 操作，减操作
	sops.sem_flg = SEM_UNDO;//到最后系统会自动释放系统中残留的信号量
	if(semop(sem_id,&sops,1) == -1)
	{
		perror("P operation.\n");
		return -1;
	}
	return 0;
}

// v 操作
int sem_v(int sem_id)
{
	struct sembuf sops;
	sops.sem_num = 0;//单个信号量的编号为 0 
	sops.sem_op = 1;//表示 v 操作
	sops.sem_flg = SEM_UNDO;//系统自动释放残留的信号量
	if(semop(sem_id,&sops,1) == -1)
	{
		perror("V operation.\n");
		return -1;
	}
	return 0;
}

#define DELAY_TIME	1

int main(void)
{
	pid_t result;
    key_t sem_key;
	int sem_id;

    sem_key = ftok(NAME, NAME_ID);
	//创建一个信号量
	sem_id = semget(sem_key, 1, 0666 | IPC_CREAT);
    printf("sem_key = %d, sem_id = %d.\n", sem_key, sem_id);
    sem_key = ftok(NAME, NAME_ID);
	sem_id = semget(sem_key, 1, 0666 | IPC_CREAT);
    printf("sem_key = %d, sem_id = %d.\n", sem_key, sem_id);
	//信号量的id，和信号量初始化的值为0
	init_sem(sem_id, 0);
	//调用 fork() 函数
	result = fork();
	if(-1 == result)
	{
		perror("Fail fork.\n");
	}
	else if(0 == result)//子进程
	{
		printf("Child process will wait for some seconds ...\n");
		sleep(DELAY_TIME);
        // printf("the child process is running ...\n");
		printf("sem_val = %d, the child process is running ...\n", get_semval(sem_id));
		//给信号量的值加1
		sem_v(sem_id);
        printf("sem_val = %d, the child process is running ...\n", get_semval(sem_id));
	}
	else//父进程
	{
		//若信号量的值已经为0，那么这个减1的操作将阻塞于此
		//从而保证子进程运行在父进程的前面
        sem_p(sem_id);
        printf("sem_val = %d, the father process is running ...\n", get_semval(sem_id));
		sem_v(sem_id);
        // printf("the father process is running ...\n");
		printf("sem_val = %d, the father process is running ...\n", get_semval(sem_id));
		sem_v(sem_id);
        printf("sem_val = %d, the father process is running ...\n", get_semval(sem_id));
		del_sem(sem_id);
	}
	// exit(0);
}