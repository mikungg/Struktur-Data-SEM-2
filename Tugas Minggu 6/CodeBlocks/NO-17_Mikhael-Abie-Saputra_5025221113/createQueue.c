#include <stdio.h>
#include <stdlib.h>
#include "queue2tostack.h"

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}