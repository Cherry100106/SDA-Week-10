#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmptyQueue(Queue q) {
    return q.front == NULL;
}

void enqueue(Queue *q, address value) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = NULL;

    if (isEmptyQueue(*q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

address dequeue(Queue *q) {
    if (isEmptyQueue(*q)) {
        printf("Queue kosong!\n");
        return NULL;
    }

    QueueNode *temp = q->front;
    address value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

void printQueue(Queue q) {
    QueueNode *curr = q.front;
    printf("Isi Queue: ");
    while (curr != NULL) {
        printf("%d ", Info(curr->data));
        curr = curr->next;
    }
    printf("\n");
}
