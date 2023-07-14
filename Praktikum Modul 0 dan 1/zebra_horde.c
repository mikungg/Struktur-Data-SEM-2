#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    long long data;
    struct node *next;

} Node, *NodePtr;

typedef struct stack{
    NodePtr head;
    long long size;

} Stack;

typedef struct queue{
    NodePtr head;
    NodePtr tail;
    long long size;

} Queue;

void initStack(Stack *);
void pushElem(Stack *, long long elem);
void popElem(Stack *);
void printStack(Stack);
long long power(long long elem, long long powval);
void initQueue(Queue *);
void enqueLast(Queue *, long long elem);
void dequeueFront(Queue *);
void printQueue(Queue);

int main()
{
    int t;
    long long num;
    Stack biners, stcreset;
    NodePtr curr, curr2, comp;
    Queue result;

    scanf("%d", &t);
    if(t<1)
    {
        return -1;
    }

    initStack(&biners);
    initStack(&stcreset);
    initQueue(&result);

    while(t != 0)
    {
        scanf("%lld", &num);
        
        if(num < 0)
        {
            pushElem(&biners, 0);
        }
        else
        {
            while(num > 0)
            {
                pushElem(&biners, num % 2);
                num /= 2;
            }
        }

        // printStack(biners);
        // printf("\n");

        curr = biners.head;
        curr2 = biners.head;
        comp = curr2->next;
        
        while(comp != NULL)
        {   
            if(comp->data == curr2->data && curr2 == biners.head)
            {
                popElem(&biners);
                popElem(&biners);
                curr = biners.head;
                curr2 = biners.head;
                comp = curr2->next;
            }
            else if(comp->data == curr2->data && comp->next == NULL)
            {
                free(curr2);
                free(comp);
                biners.size -= 2;
                curr->next = NULL;
                curr = biners.head;
                curr2 = biners.head;
                comp = curr2->next;
            }
            else if(comp->data == curr2->data)
            {
                curr->next = comp->next;
                free(curr2);
                free(comp);
                biners.size -= 2;
                curr = biners.head;
                curr2 = biners.head;
                comp = curr2->next;
            }
            else
            {
                if(curr2 == biners.head)
                {
                    curr2 = curr2->next;
                    comp = comp->next;
                }
                else
                {
                    curr = curr->next;
                    curr2 = curr2->next;
                    comp = comp->next;
                }
            }
        }
        
        // printStack(biners);
        // printf("\n");
    
        long long temp;

        while(biners.size != 0)
        {
            temp = biners.head->data * power(2, biners.size-1);
            num += temp;
            popElem(&biners);
        }
        
        enqueLast(&result, num);
        
        biners = stcreset;
        t--;
    }

    printQueue(result);
}

void initStack(Stack *stack)
{
    stack->size = 0;
    stack->head = (NodePtr) malloc(sizeof(Node));               //allocate memory for head node
    stack->head->next = NULL;                                   //assign NULL to head's link 
}

void pushElem(Stack *stack, long long elem)
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
        curr = (NodePtr) malloc(sizeof(Node));          //allocate memory for a new node(curr)
        curr->data = elem;                                      //assign element to curr's data
        curr->next = stack->head;                               //assign curr's link to head pointer
        stack->head = curr;                                     //pointer curr is now the head of stack
        stack->size++;                                          //increment size to track the number of elements in a stack
    }
}

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

void printStack(Stack stack)
{
    while(stack.head != NULL)                                      //print all the elements
    {
        printf("%lld ", stack.head->data);
        stack.head = stack.head->next;
    }
}

long long power(long long elem, long long powval)
{
    if(powval == 0)
    {
        elem = 1;
    }
    else
    {
        long long initelem = elem;

        for(long long i = 1; i<powval; i++)
        {
            elem *= initelem;
        }
    }

    return elem;
}

void initQueue(Queue *queue)
{
    queue->size = 0;
    queue->head = (NodePtr) malloc(sizeof(Node));
    queue->tail = queue->head;
    queue->head->next = NULL;
}

void enqueLast(Queue *queue, long long elem)
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
    printf("%lld\n", queue.head->data);
    queue.head = queue.head->next;
    queue.size--;
    }
}