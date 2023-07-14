#ifndef QUEUE2TOSTACK_H
#define QUEUE2TOSTACK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack {
    Queue* q1;
    Queue* q2;
} Stack;

//prototipe fungsi
Queue* createQueue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int isEmpty(Queue* queue);
Stack* createStack();
void push(Stack* stack, int data);
int pop(Stack* stack);

#endif