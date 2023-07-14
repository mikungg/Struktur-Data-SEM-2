#include <stdio.h>
#include <stdlib.h>
#include "queue2tostack.h"

int pop(Stack* stack) {
    if (isEmpty(stack->q1) && isEmpty(stack->q2)) {
        printf("Error: Stack is empty\n");
        return -1;
    }
    int data;
    if (isEmpty(stack->q1)) {
        while (!isEmpty(stack->q2)) {
            data = dequeue(stack->q2);
            if (!isEmpty(stack->q2)) {
                enqueue(stack->q1, data);
            }
        }
    } else {
        while (!isEmpty(stack->q1)) {
            data = dequeue(stack->q1);
            if (!isEmpty(stack->q1)) {
                enqueue(stack->q2, data);
            }
        }
    }
    return data;
}