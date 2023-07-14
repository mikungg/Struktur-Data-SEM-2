#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

// Pop an element from stack2
int pop2(struct queue *q) {
    if (q->top2 == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return q->stack2[q->top2--];
}