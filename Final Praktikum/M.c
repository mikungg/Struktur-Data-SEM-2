#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Struktur Node */

typedef struct dnode_t{
    char data;
    struct dnode_t *next, *prev;
} DListNode;

typedef struct deque_t {
    DListNode *_head, *_tail;
    unsigned _size;
} Deque;

/* PROTOTYPE */

DListNode* __dlist_createNode(char value);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, char value);
void deq_pushBack(Deque *deque, char value);
int  deq_front(Deque *deque);
int  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

/* FUNCTIONS */

DListNode* __dlist_createNode(char value)
{
    DListNode *newNode = \
        (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque)
{
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && \
            deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, char value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, char value)
{
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

int deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

int deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque)
{
    if (!deq_isEmpty(deque)) {
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

int main()
{
    int n = 0;
    char str[1000000];
    Deque parant;
    deq_init(&parant);

    scanf("%s", str);

    while (n < strlen(str))
    {
        deq_pushBack(&parant, str[n]);
        n++;
    }

    if(strlen(str) % 2 == 1)
    {
        printf("unvaldi");
    }
    else
    {
        while(!deq_isEmpty(&parant)){
            char temp = deq_front(&parant);
            deq_popFront(&parant);
            
            if (temp == '{' && deq_front(&parant) == '}'){
                deq_popFront(&parant);
            }
            else if (temp == '[' && deq_front(&parant) == ']'){
                deq_popFront(&parant);
            }
            else if(temp == '(' && deq_front(&parant) == ')'){
                deq_popFront(&parant);
            }
            else{
                if(temp == '{' && deq_back(&parant) == '}'){
                    deq_popBack(&parant);
                }
                else if(temp == '[' && deq_back(&parant) == ']'){
                    deq_popBack(&parant);
                }
                else if(temp == '(' && deq_back(&parant) == ')'){
                    deq_popBack(&parant);
                }
                else{
                    printf("unvaldi");
                }
            }
        }

        if(deq_isEmpty(&parant))
        {
            printf("valdi");
        }
    }
    


}