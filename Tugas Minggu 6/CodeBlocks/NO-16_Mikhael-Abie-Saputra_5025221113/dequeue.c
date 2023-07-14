#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

// Dequeue an element from the queue
int dequeue(struct queue *q) {
    int val;

    // If both stacks are empty, the queue is empty
    if (q->top1 == -1 && q->top2 == -1) {
        printf("Queue Underflow\n");
        exit(1);
    }

    // If stack2 is empty, transfer elements from stack1 to stack2
    if (q->top2 == -1) {
        while (q->top1 != -1) {
            val = pop1(q);
            push2(q, val);
        }
    }

    // Pop an element from stack2 to dequeue it from the queue
    val = pop2(q);

    return val;
}