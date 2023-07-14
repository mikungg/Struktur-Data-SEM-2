#include <stdio.h>
#include <stdlib.h>
#include "queue2tostack.h"

int main() {
    Stack* stack = createStack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    push(stack, 4);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    return 0;
}