#include <stdio.h>
#include <stdlib.h>
#include "mikastack.h"


int main()
{
    Stack stack;

    initStack(&stack);
    pushElem(&stack, 45);
    pushElem(&stack, 22);
    pushElem(&stack, 8);
    pushElem(&stack, 21);
    sortStackSToL(&stack);
    printStack(stack);
}