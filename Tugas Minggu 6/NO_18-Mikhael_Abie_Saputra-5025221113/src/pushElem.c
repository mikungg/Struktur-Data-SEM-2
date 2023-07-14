#include <stdio.h>
#include <stdlib.h>
#include "mikastack.h"

/* Push an element to a stack */
void pushElem(Stack *stack, int elem)
{
    NodePtr curr;                                               //declare a new node pointer, curr

    if(stack->size == 0)                                        //if stack doesn't have an element yet
    {
        stack->head->data = elem;                               //assign element to head's data
        stack->head->next = NULL;                               
        stack->size++;                                          //increment size to track the number of elements in a stack
    }
    else                                                        //if stack already has an element
    {
        NodePtr curr = (NodePtr) malloc(sizeof(Node));          //allocate memory for a new node(curr)
        curr->data = elem;                                      //assign element to curr's data
        curr->next = stack->head;                               //assign curr's link to head pointer
        stack->head = curr;                                     //pointer curr is now the head of stack
        stack->size++;                                          //increment size to track the number of elements in a stack
    }
}