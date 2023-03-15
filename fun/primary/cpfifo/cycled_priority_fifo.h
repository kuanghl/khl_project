//
// Created by Andrey Tabakov on 27.10.2019.
//

#ifndef CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_FIFO_H
#define CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_FIFO_H


//priority 
typedef struct cpq_node_ptr {
    struct cpq_node * first;
    struct cpq_node * second;
}cpq_node_ptr_t;
// 双向list
typedef struct cpq_node {
    void* data;
    cpq_node_ptr_t* next;
    cpq_node_ptr_t* prev;
}cpq_node_t;
// fifo
typedef struct cpq {
    cpq_node_ptr_t* head;
}cpq_t;

int init(cpq_t *);
int enqueue(cpq_t* q, void *data);
int dequeue(cpq_t* q, void **data);
void printList(cpq_t q);

#endif //CYCLEDPRIORITYQUEUE_CYCLED_PRIORITY_FIFO_H