#ifndef QUEUE_H
#define QUEUE_H
#include "bintree.h"

typedef struct QueueNode {
    address data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initQueue(Queue *q);
int isEmptyQueue(Queue q);
void enqueue(Queue *q, address value);
address dequeue(Queue *q);
void printQueue(Queue q);

#endif
