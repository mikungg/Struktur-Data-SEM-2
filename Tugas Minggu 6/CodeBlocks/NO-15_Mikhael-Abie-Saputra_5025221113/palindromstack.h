#ifndef PALINDROMSTACK_H
#define PALINDROMSTACK_H

typedef struct node{
    char data;
    struct node *next;

} Node, *NodePtr;

typedef struct stack{
    NodePtr head;
    int size;

} Stack;

void initStack(Stack *);
void pushElem(Stack *, char);
void popElem(Stack *);
void printStack(Stack);
int isPalindrome(Stack, Stack);

#endif