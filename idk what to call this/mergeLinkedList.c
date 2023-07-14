#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    Node *next;
} Node, *NodePtr;

typedef struct list
{
    NodePtr head;
} List;

NodePtr makeNode(int);

int main()
{
    
}

NodePtr makeNode(int val)
{
   (NodePtr*) malloc(sizeof(Node));
}