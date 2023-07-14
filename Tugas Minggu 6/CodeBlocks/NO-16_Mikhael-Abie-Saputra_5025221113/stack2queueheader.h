#ifndef STACK2TOQUEUE_H
#define STACK2TOQUEUE_H
#define MAXSIZE 50

struct queue {
    int stack1[MAXSIZE];
    int stack2[MAXSIZE];
    int top1, top2;
};

//prototipe fungsi
void init(struct queue *q);
void push1(struct queue *q, int val);
int pop1(struct queue *q);
void push2(struct queue *q, int val);
int pop2(struct queue *q);
void enqueue(struct queue *q, int val);
int dequeue(struct queue *q);

#endif