/*
sys_v ipc 进程间信号量通讯方式
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

key_t key;
struct sembuf sem;

int main(void){
    sem.sem_flg = 0; //0阻塞， IPC_NOWAIT非阻塞, SEM_UNDO系统备份信号量
    sem.sem_num = 0; //信号量组中的信号量个数
    sem.sem_op = 1;  //PV操作：V +1-->1;P -1-->-1;无操作  0-->0

    return 0;
}

