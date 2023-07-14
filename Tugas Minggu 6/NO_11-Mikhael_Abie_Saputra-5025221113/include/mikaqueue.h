#ifndef MIKAQUEUE_H
#define MIKAQUEUE_H

typedef struct node{
    double data;
    struct node *next;

} Node, *NodePtr;

typedef struct queue{
    NodePtr head;
    NodePtr tail;
    int size;
} Queue;

void initQueue(Queue *);
void enqueLast(Queue *, double);
void dequeueFront(Queue *);
void printQueue(Queue);
int isEmptyq(Queue);

#endif