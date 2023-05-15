#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <time.h>


#define NAME "./"
#define NAME_ID 3

union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

int __sem_init(int __id, int __index, int __val) {
    union semun sem_union;
    sem_union.val = __val;
    return semctl(__id, __index, SETVAL, sem_union);
}

int __sem_del(int __id, int __index) {
    union semun sem_union;
    return semctl(__id, __index, IPC_RMID, sem_union);
}

int __sem_getval(int __id, int __index) {
    union semun sem_union;
    return semctl(__id, __index, GETVAL, sem_union);
}

int __sem_post(int __id, int __index) {
    struct sembuf sops;
    sops.sem_num = __index;
    sops.sem_op = 1;
    sops.sem_flg = SEM_UNDO;
    return semop(__id, &sops, 1);
}

int __sem_wait(int __id, int __index) {
    struct sembuf sops;
    sops.sem_num = __index;
    sops.sem_op = -1;
    sops.sem_flg = SEM_UNDO;
    return semop(__id, &sops, 1);
}

int main(void){
    key_t sem_key;
	int sem_id;

    sem_key = ftok(NAME, NAME_ID);
	sem_id = semget(sem_key, 1, 0666 | IPC_CREAT);
    printf("sem_key = %d, sem_id = %d.\n", sem_key, sem_id);
    sleep(5);
    __sem_del(sem_id, 0);
    return 0;
}

