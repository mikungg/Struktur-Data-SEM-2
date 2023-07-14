#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

// Pop an element from stack1
int pop1(struct queue *q) {
    if (q->top1 == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return q->stack1[q->top1--];
}