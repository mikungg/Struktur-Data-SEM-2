#include <stdio.h>
#include <stdlib.h>
#include "queue2tostack.h"

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue();
    stack->q2 = createQueue();
    return stack;
}