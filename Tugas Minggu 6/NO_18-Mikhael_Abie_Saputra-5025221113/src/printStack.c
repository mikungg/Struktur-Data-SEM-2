#include <stdio.h>
#include <stdlib.h>
#include "mikastack.h"

/* Print a stack */
void printStack(Stack stack)
{
    while(stack.size != 0)                                      //print all the elements
    {
        printf("%d ", stack.head->data);
        stack.head = stack.head->next;
        stack.size--;
    }
}