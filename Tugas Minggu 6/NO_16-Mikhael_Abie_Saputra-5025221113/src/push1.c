#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

// Push an element onto stack1
void push1(struct queue *q, int val) {
    if (q->top1 == MAXSIZE-1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    q->stack1[++q->top1] = val;
}