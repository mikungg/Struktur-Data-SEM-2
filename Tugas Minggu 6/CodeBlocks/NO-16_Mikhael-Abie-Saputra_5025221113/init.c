#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

// Initialize the queue
void init(struct queue *q) {
    q->top1 = -1;
    q->top2 = -1;
}