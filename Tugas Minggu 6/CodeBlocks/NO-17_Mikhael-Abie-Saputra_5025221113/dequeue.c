#include <stdio.h>
#include <stdlib.h>
#include "queue2tostack.h"

int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}