#include <stdio.h>
#include <stdlib.h>
#include "mikastack.h"

/* Sorting function from smallest to largest using temporary stack*/
void sortStackSToL(Stack *stack)
{
    Stack temp;                                                 //declare temporary stack
    int datatemp;                                               //declare temporary data
    temp.size = 0;                                              //make the temporary stack size 0
    
    initStack(&temp);                                           //initialize temporary stack
    pushElem(&temp, stack->head->data);                         //push element from stack to temp stack
    popElem(stack);                                             //pop an element from stack
    while(stack->size != 0)                                     //while stack still has an element
    {
        if(temp.head->data < stack->head->data)                 //if temp head's data is smaller than stack's head
        {
            datatemp = stack->head->data;                       //assign stack's head data to temporary data
            popElem(stack);                                     //pop an element from a stack
            while(temp.head->data < datatemp && temp.size != 0) //while temp stack head's is smaller than temporary data and the temp still have element
            {
                pushElem(stack, temp.head->data);               //push an element from temp stack's head to stack
                popElem(&temp);                                 //pop an element from temp stack
            }
            pushElem(&temp, datatemp);                          //push temporary data to temp stack
        }
        else                                                    //if temp head's data is smaller than stack's head
        {
            pushElem(&temp, stack->head->data);                 //push an element from stack's head to temp stack
            popElem(stack);                                     //pop an element from stack
        }
    }

    *stack = temp;                                              //stack is now sorted
}