#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/shm.h>

struct info_s
{
    unsigned int info1;
    unsigned char info2;
    unsigned short int info3;
};

typedef struct pti_ipc_shm_s{
    int shm_id;
    void *shm_addr;      // shm space header address
    uint64_t shm_used;   // fulled size n bytes
    uint8_t shm_flags;   // 1 full but no process, 0 empty
#define PTI_SHM_COUNT 4
#define PER_PTI_SHM_SIZE (32*1024 + 8)  //32k
}pti_ipc_shm_t;

typedef struct pti_serv_s{
    pti_ipc_shm_t *pti_shm;
    uint8_t pti_shm_first;
    uint8_t pti_shm_last;
}pti_serv_t;

int pti_shm_create(pti_serv_t *pti_serv){
    uint8_t i;

    pti_serv->pti_shm = (pti_ipc_shm_t *)calloc(PTI_SHM_COUNT, sizeof(struct pti_ipc_shm_s));
    if(pti_serv->pti_shm == NULL){
        //log_debug("%s, out of resource...\n", __func__);
        return -1;
    }
    //log_debug("%s, pti shm count: %d, per shm size:0x%llx.\n", __func__, PTI_SHM_COUNT, PER_PTI_SHM_SIZE);
    pti_ipc_shm_t *pti_shm_buf = pti_serv->pti_shm;
    pti_serv->pti_shm_first = 0;
    pti_serv->pti_shm_last = 0;

    srand((unsigned)time(NULL));
    for(i = 0; i < PTI_SHM_COUNT; i++){
        if (geteuid() == 0) {
            pti_shm_buf->shm_id = shmget((key_t)rand(), PER_PTI_SHM_SIZE, SHM_HUGETLB|IPC_CREAT|0666);
        } else {
            pti_shm_buf->shm_id = shmget((key_t)rand(), PER_PTI_SHM_SIZE, IPC_CREAT|0666);
        }
        if(pti_shm_buf->shm_id < 0){
            //log_error("%s, pti shmget error...\n", __func__);
            return -1;
        }
        pti_shm_buf->shm_addr = shmat(pti_shm_buf->shm_id, NULL, 0);
        if(pti_shm_buf->shm_addr == (void *)-1) {
            //log_error("%s, shm id = %d, pti shmat error...\n", __func__, pti_shm_buf->shm_id);
            return -1;
        }
        pti_shm_buf->shm_used = 0;
        pti_shm_buf->shm_flags = 0;
        pti_shm_buf = (uint8_t *)pti_shm_buf + sizeof(pti_ipc_shm_t);
    }

    return 0;
}

void pti_shm_free(pti_serv_t *pti_serv){
    pti_ipc_shm_t *pti_shm_buf = pti_serv->pti_shm;
    uint8_t i;
    // pti_serv->pti_shm_first = 0;
    // pti_serv->pti_shm_last = 0;
    for(i = 0; i < PTI_SHM_COUNT; i++){
        shmdt(pti_shm_buf->shm_addr);
        shmctl(pti_shm_buf->shm_id, IPC_RMID, 0);
        pti_shm_buf = (uint8_t *)pti_shm_buf + sizeof(pti_ipc_shm_t);
    }
    free(pti_serv->pti_shm);
    pti_serv->pti_shm = NULL;
}

int main(){
    struct info_s info[4];
    struct info_s *info_addr = &info;
    struct info_s *info_de = (struct info_s *)calloc(10, sizeof(struct info_s));

    unsigned char i;
    printf("**************************array\n");
    srand((unsigned)time(NULL));
    for(i =  0; i < 4; i++){
        info[i].info1 = rand();
        info[i].info2 = rand();
        info[i].info3 = rand();
        printf("SN%3d:info1 = %11d, info2 = %11d, info3 = %11d.\n", i, info[i].info1, info[i].info2, info[i].info3);
    }
    printf("**************************out\n");
    for(i =  0; i < 4; i++){
        printf("SN%3d:info1 = %11d, info2 = %11d, info3 = %11d.\n", i, (info_addr+i)->info1, (info_addr+i)->info2, (info_addr+i)->info3);
    }
    printf("\n\n");
    printf("**************************dynamic\n");
    for(i = 0; i < 10; i++){
        (info_de + i * sizeof(struct info_s))->info1 = rand();
        (info_de + i * sizeof(struct info_s))->info2 = rand();
        (info_de + i * sizeof(struct info_s))->info3 = rand();
        printf("SN%3d:info1 = %11d, info2 = %11d, info3 = %11d.\n", i, (info_de + i * sizeof(struct info_s))->info1, (info_de + i * sizeof(struct info_s))->info2, (info_de + i * sizeof(struct info_s))->info3);
    }
    info_addr = info_de;
    printf("**************************out\n");
    for(i =  0; i < 10; i++){
        printf("SN%3d:info1 = %11d, info2 = %11d, info3 = %11d.\n", i, (info_addr+i * sizeof(struct info_s))->info1, (info_addr+i * sizeof(struct info_s))->info2, (info_addr+i * sizeof(struct info_s))->info3);
    }

    size_t sizei = 6,sizej;
    sizej = -1/sizei;
    printf("size_t j = %ld. -1 = %ld.\n", sizej, (size_t)(-1));

    /*test*/
    int r;
    pti_serv_t *pti_serv = (pti_serv_t *)calloc(1, sizeof(pti_serv_t)); 
    r = pti_shm_create(pti_serv);
    pti_shm_free(pti_serv);
    free(pti_serv);

    free(info_de);
    return 0;
}
