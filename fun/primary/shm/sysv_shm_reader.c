//
// Created by perterwarlg on 2021/9/13.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TEXT_SIZE 1024

struct ShmDataStruct {
    int readable_;
    char text_[TEXT_SIZE];
};

//和write.cpp相同的key
#define KEY_OF_SHM 8888

int main() {
    //获取shm_id，在不同进程中这是唯一的，获取和KEY有关
    int shm_id = shmget(KEY_OF_SHM, sizeof(struct ShmDataStruct), 0666 | IPC_CREAT);

    //创建一个指针，用来指向共享内存
    void *addr_to_shm;

    //一个指针表明共享内存的结构体，应当和addr_to_shm互相转换来使用
    struct ShmDataStruct *shm_data;

    //将addr_to_shm连接到系统分配的共享内存，也就是将共享内存（物理地址）挂到当前进程的内存空间（虚拟地址）
    addr_to_shm = shmat(shm_id, (void*)0, 0);
    printf("\nMemory attached at %X\n", *(int*)addr_to_shm);

    //将获得的void*类型的转为我们需要的data struct
    shm_data = (struct ShmDataStruct*)addr_to_shm;

    while (1) {
        if (shm_data->readable_ == 1) {
            printf("The Text in SHM : %s\n", shm_data->text_);
            sleep(1);
        }
        if (strncmp(shm_data->text_, "end", 3) == 0) {
            printf("Close Read SHM.\n");
            break;
        }
    }

    //把共享内存从当前进程分离，也就是将其从进程内存空间的页表中除掉
    shmdt(addr_to_shm);

    //不设置删除共享内存，删除共享内存的工作交给write端去做
    exit(EXIT_SUCCESS);
}
