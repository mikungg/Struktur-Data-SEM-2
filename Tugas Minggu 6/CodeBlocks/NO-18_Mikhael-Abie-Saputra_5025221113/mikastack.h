#ifndef MIKASTACK_H
#define MIKASTACK_H

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

void initStack(Stack *);
void pushElem(Stack *, int);
void popElem(Stack *);
void sortStackSToL(Stack *);
void printStack(Stack);

#endif