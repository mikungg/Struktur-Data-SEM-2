#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
#include <stdio.h>

/* Struktur Node */

typedef struct pqueueNode_t {
    char nama[100];
    float data;
    struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
    float profit;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, char bazar[100], float value);
void pqueue_pop(PriorityQueue *pqueue);
float  pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue)
{
    pqueue->_top = NULL;
    pqueue->_size = 0;
    pqueue->profit = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char bazar[100], float value)
{
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = \
        (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = value;
    strcpy(newNode->nama, bazar);
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (value > pqueue->_top->data) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && temp->next->data > value)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue)
{
    if (!pqueue_isEmpty(pqueue)) {
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

float pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

char *pqueue_topC(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->nama;
    else return 0;
}

typedef struct stalls
{
    char name[100];
    float inc, exp, nett;
}data;


int main(){

    data stalls;
    PriorityQueue mipy;
    PriorityQueue temp;
    PriorityQueue bubu;
    pqueue_init(&mipy);
    pqueue_init(&temp);

    while (1)
    {
        scanf("%s", stalls.name);
        if (strcmp(stalls.name, "xxxxxx") == 0)
        {
            break;
        }   

        scanf("%f %f", &stalls.inc, &stalls.exp);

        stalls.nett = stalls.inc - stalls.exp;
        pqueue_push(&mipy, stalls.name, stalls.nett);
        mipy.profit += stalls.nett;
        mipy._size += 1;
    }

    temp = mipy;
    bubu = temp;

    while (!pqueue_isEmpty(&temp))
    {
        printf("%s, %.2f\n", pqueue_topC(&temp), pqueue_top(&temp));
        pqueue_pop(&temp);
    }

    printf("Number of Stalls Available: %d\n", mipy._size);
    printf("Total Profit/Loss: %.2f\n", mipy.profit);
    printf("Stall(s) with the most profit: %s", bubu._top->nama);
    
    
}