#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

// Enqueue an element into the queue
void enqueue(struct queue *q, int val) {
    push1(q, val);
}