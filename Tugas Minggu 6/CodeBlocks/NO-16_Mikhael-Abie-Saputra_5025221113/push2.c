#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

// Push an element onto stack2
void push2(struct queue *q, int val) {
    if (q->top2 == MAXSIZE-1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    q->stack2[++q->top2] = val;
}