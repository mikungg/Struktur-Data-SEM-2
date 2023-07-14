#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    NodePtr next;
} Node, *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
    int size;
} Queue, *QueuePtr;

QueuePtr createQueue() {
    QueuePtr queue = (QueuePtr) malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

int isEmpty(QueuePtr queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

void enqueueFront(QueuePtr queue, int value) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->data = value;
    if (isEmpty(queue)) {
        newNode->next = NULL;
        queue->rear = newNode;
    }
    else {
        newNode->next = queue->front;
    }
    queue->front = newNode;
    queue->size++;
}

void enqueueRear(QueuePtr queue, int value) {
    NodePtr newNode = (NodePtr) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(queue)) {
        queue->front = newNode;
    }
    else {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    queue->size++;
}

int dequeue(QueuePtr queue) {
    int value;
    NodePtr temp;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if (queue->front == queue->rear) {
        temp = queue->front;
        value = temp->data;
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        temp = queue->front;
        value = temp->data;
        queue->front = queue->front->next;
    }
    free(temp);
    queue->size--;
    return value;
}

int front(QueuePtr queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int rear(QueuePtr queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->rear->data;
}

int poprear(QueuePtr queue) {
    int value;
    NodePtr temp;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if (queue->front == queue->rear) {
        temp = queue->rear;
        value = temp->data;
        queue->front = NULL;
        queue->rear = NULL;
    }
    else {
        NodePtr prev = queue->front;
        NodePtr curr = queue->front->next;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        temp = curr;
        value = temp->data;
        prev->next = NULL;
        queue->rear = prev;
    }
    free(temp);
    queue->size--;
    return value;
}

int main() {
    QueuePtr queue = createQueue();
    enqueueRear(queue, 1);
    enqueueRear(queue, 2);
    enqueueRear(queue, 3);
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    printf("Popped rear element: %d\n", poprear(queue));
    printf("Front element: %d\n", front(queue));
    printf("Rear element: %d\n", rear(queue));
    return 0;
}

