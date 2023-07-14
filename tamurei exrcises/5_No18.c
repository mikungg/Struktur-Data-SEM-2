#include <stdio.h>
#include <stdlib.h>

/* Node */ 
typedef struct node{
    int data;
    struct node *next;

} Node, *NodePtr;

/* Stack */
typedef struct stack{
    NodePtr head;
    int size;

} Stack;

/* Function Prototype */
void initStack(Stack *);
void pushElem(Stack *, int);
void popElem(Stack *);
void sortStackLToS(Stack *);
void sortStackSToL(Stack *);
void printStack(Stack);

int main()
{
    Stack mystack;
    initStack(&mystack);
    pushElem(&mystack, 45);
    pushElem(&mystack, 22);
    pushElem(&mystack, 8);
    pushElem(&mystack, 21);
    sortStackSToL(&mystack);
    printStack(mystack);
}

/* Initialize stack */
void initStack(Stack *stack)
{
    stack->size = 0;
    stack->head = (NodePtr) malloc(sizeof(Node));               //allocate memory for head node
    stack->head->next = NULL;                                   //assign NULL to head's link 
}

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

/* Sorting function from largest to smallest using temporary stack*/
void sortStackLToS(Stack *stack)
{
    Stack temp;                                                 //declare temporary stack
    int datatemp;                                               //declare temporary data
    temp.size = 0;                                              //make the temporary stack size 0
    
    initStack(&temp);                                           //initialize temporary stack
    pushElem(&temp, stack->head->data);                         //push element from stack to temp stack
    popElem(stack);                                             //pop an element from stack
    while(stack->size != 0)                                     //while stack still has an element
    {
        if(temp.head->data > stack->head->data)                 //if temp head's data is bigger than stack's head
        {
            datatemp = stack->head->data;                       //assign stack's head data to temporary data
            popElem(stack);                                     //pop an element from a stack
            while(temp.head->data > datatemp)                   //while temp stack head's is bigger than temporary data
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
        else                                                    //if temp head's data is larger than stack's head
        {
            pushElem(&temp, stack->head->data);                 //push an element from stack's head to temp stack
            popElem(stack);                                     //pop an element from stack
        }
    }

    *stack = temp;                                              //stack is now sorted
}

/* Print a stack */
void printStack(Stack stack)
{
    while(stack.head != NULL)                                      //print all the elements
    {
        printf("%d ", stack.head->data);
        stack.head = stack.head->next;
        stack.size--;
    }
}