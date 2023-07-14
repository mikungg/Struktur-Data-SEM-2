/* 
Tamara Jovanka - 5025221213
Struktur Data B
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
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

int detectSortUtil(Node *front){
    if (front->next == NULL){
        return 1;
    }
    else if(front->data >= front->next->data){
        return 0;
    }
    else{
        detectSortUtil(front->next);
    }

}

void detectSort(Queue *queue) {
   printf("%d", detectSortUtil(queue->front));
}

int main() {
 int n, x;
 QueuePtr LL = createQueue();

scanf("%d", &n);

while ((n != 0)){
    scanf("%d", &x);
    enqueueRear(LL, x);
    n--;
 }

 detectSort((LL));
}
