/* Mikha's general queue functions */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;

} Node, *NodePtr;

typedef struct queue{
    NodePtr head;
    NodePtr tail;
    int size;

} Queue;

void initQueue(Queue *);
void enqueLast(Queue *, int);
void dequeueFront(Queue *);
void printQueue(Queue);
int isEmptyq(Queue);


void initQueue(Queue *queue)
{
    queue->size = 0;
    queue->head = (NodePtr) malloc(sizeof(Node));
    queue->tail = queue->head;
    queue->head->next = NULL;
}

void enqueLast(Queue *queue, int elem)
{
    NodePtr newnode;

    if(queue->size == 0)
    {
        queue->head->data = elem;
        queue->size++;
    }
    else
    {
        newnode = (NodePtr) malloc(sizeof(Node));
        newnode->data = elem;
        queue->tail->next = newnode;
        queue->tail = newnode;
        queue->size++;
    }
}

void dequeueFront(Queue *queue)
{
    NodePtr curr;

    if(queue->head->next == NULL)
    {
        queue->head->data = 0;
        queue->size--;
    }
    else
    {
        curr = queue->head->next;
        free(queue->head);
        queue->head = curr;
        queue->size--;
    }
}

void printQueue(Queue queue)
{
    while(queue.size != 0)
    {
    printf("%d ", queue.head->data);
    queue.head = queue.head->next;
    queue.size--;
    }
}

int isEmptyq(Queue queue)
{
    if(queue.size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}