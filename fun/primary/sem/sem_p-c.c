#include<semaphore.h>
#include<string.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>


#define CONSUME_PNUM 5
#define PRODUCT_PNUM 5

#define CONSUME_TIME 2
#define PRODUCT_TIME 2

#define ITEM_NUM 10

int inventory[ITEM_NUM] = {0};
int product_index = 0;
int consume_index = 0;

pthread_mutex_t mutex;
sem_t product_sem;
sem_t consume_sem;

void print_inventory_action(unsigned char is_product,unsigned int id, int item_id){
    if(is_product)
        printf("第%u个生产者放入了第%d个物品,此时各个物品数量为:\n",id,item_id);
    else
        printf("第%u个消费者拿走了第%d个物品,此时各个物品数量为:\n",id,item_id);
    for(int i =0; i < ITEM_NUM; i++){
        printf("%d  ",inventory[i]);
    }
    printf("\n");
}

void* product(void *id){
    unsigned int cur_p_id = *(unsigned int*)id;
    while(1){
        sleep(PRODUCT_TIME);
        sem_wait(&product_sem);
        pthread_mutex_lock(&mutex);
        inventory[product_index%ITEM_NUM] += 1;
        print_inventory_action(1,cur_p_id+1,(product_index%ITEM_NUM) + 1);
        product_index++;
        pthread_mutex_unlock(&mutex);
        sem_post(&consume_sem);
    }
}

void* consume(void *id){
    unsigned int cur_p_id = *(unsigned int*)id;
    while(1){
        sleep(CONSUME_TIME);
        sem_wait(&consume_sem);
        pthread_mutex_lock(&mutex);
        inventory[consume_index%ITEM_NUM] -= 1;
        print_inventory_action(0,cur_p_id+1,(consume_index%ITEM_NUM) + 1);
        consume_index++;
        pthread_mutex_unlock(&mutex);
        sem_post(&product_sem);
    }
}


int main(){
    if(sem_init(&product_sem,0,ITEM_NUM) != 0 ){  //注意生产者信号量的初始化值要为ITEM_NUM值
        printf("sem init failed\n");
        return 1;
    }

    if(sem_init(&consume_sem,0,0) != 0 ){  //注意消费者信号量的初始化值要为0
        printf("sem init failed\n");
        return 1;
    }

     pthread_t product_threads[PRODUCT_PNUM];
    int product_threads_id[PRODUCT_PNUM] = {0};
    for(int i = 0; i < PRODUCT_PNUM; i++){
        product_threads_id[i] = i;
        if(pthread_create(product_threads+i,NULL,product,product_threads_id+i) != 0){
            printf("pthread creates failed");
            return 1;
        }
    }

    pthread_t consume_threads[CONSUME_PNUM];
    int consume_threads_id[CONSUME_PNUM] = {0};
    for(int i = 0; i< CONSUME_PNUM; i++){
        consume_threads_id[i] = i;
        if(pthread_create(consume_threads+i, NULL, consume,consume_threads_id+i) != 0 ){
            printf("pthread creates failed");
            return 1;
        }
    }

    for(int i = 0; i < PRODUCT_PNUM; i++){
        pthread_join(product_threads[i],NULL);
    }

    for( int i =0; i < CONSUME_PNUM; i++){
        pthread_join(consume_threads[i],NULL);
    }

    return 0;
}


