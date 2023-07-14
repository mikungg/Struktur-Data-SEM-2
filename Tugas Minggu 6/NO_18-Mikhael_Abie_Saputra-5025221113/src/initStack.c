#include <stdio.h>
#include <stdlib.h>
#include "mikastack.h"

/* Initialize stack */
void initStack(Stack *stack)
{
    stack->size = 0;
    stack->head = (NodePtr) malloc(sizeof(Node));               //allocate memory for head node
    stack->head->next = NULL;                                   //assign NULL to head's link 
}