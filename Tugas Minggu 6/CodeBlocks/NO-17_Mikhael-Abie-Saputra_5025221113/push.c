#include <stdio.h>
#include <stdlib.h>
#include "queue2tostack.h"

void push(Stack* stack, int data) {
    if (isEmpty(stack->q1)) {
        enqueue(stack->q2, data);
    } else {
        enqueue(stack->q1, data);
    }
}