#include <stdio.h>
#include <stdlib.h>
#include "palindromstack.h"

void printStack(Stack stack)
{
    while(stack.size != 0)                                      //print all the elements
    {
        printf("%c ", stack.head->data);
        stack.head = stack.head->next;
        stack.size--;
    }
    printf("\n");
}