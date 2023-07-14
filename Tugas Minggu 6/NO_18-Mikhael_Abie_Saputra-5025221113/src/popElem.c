#include <stdio.h>
#include <stdlib.h>
#include "mikastack.h"

/* Pop an element from a stack */
void popElem(Stack *stack)
{
    NodePtr curr;                                               //declare a new node pointer, curr

    if(stack->size == 1)                                        //if there is only 1 element at a stack
    {
        stack->head->data = 0;                                  //head's data become 0
        stack->size--;                                          //decrement size to track the number of elements in a stack
    }
    else                                                        //if stack elements is > 1
    {
        curr = stack->head->next;                               //curr is pointing at the node after head
        free(stack->head);                                      //free the head node
        stack->head = curr;                                     //pointer curr is now the head of stack
        stack->size--;                                          //decrement size to track the number of elements in a stack
    }
}