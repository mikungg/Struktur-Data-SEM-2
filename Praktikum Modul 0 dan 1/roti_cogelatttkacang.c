#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;

} Node, *NodePtr;

typedef struct stack{
    NodePtr head;
    int size;

} Stack;

typedef struct queue{
    NodePtr head;
    NodePtr tail;
    int size;
} Queue;

void initStack(Stack *);
void pushElem(Stack *, int);
void popElem(Stack *);
void printStack(Stack);
void initQueue(Queue *);
void enqueLast(Queue *, int);
void delqueFirst(Queue *);
void printQueue(Queue);

int main(){
    int n, bred, stud, temp;                                    //deklarasikan variabel
    int indef = 0;                                              //buat counter untuk looping infinite
    Stack bstack;                                               
    Queue squeue;

    scanf("%d", &n);                                            //input berapa banyak siswa dan roti
    bred = n;
    stud = n;

    initStack(&bstack);                                         //inisialisasi queue & stack
    initQueue(&squeue);

    while(bred != 0)
    {
        scanf("%d", &temp);                                     //input roti cokelat atau kavang (1 atau 0)
        pushElem(&bstack, temp);                                //push ke stack untuk setiap elemennhya
        bred--;
    }
    while(stud != 0)
    {
        scanf("%d", &temp);                                     //input keperluan siswa roti cokelat atau kacang (1 atau 0)
        enqueLast(&squeue, temp);                               //enqueue siswa seperti antrian irl
        stud--;
    }

    while(squeue.size != 0)                                     //algoritma yang akan berjalan selama queue atau siswa yang mengantre masih ada
    {
        if(squeue.head->data == bstack.head->data)              //jika antrean paling depan dan roti paling atas sama (1 dengan 1, 0 dengan 0), maka  
        {
            popElem(&bstack);                                   //stack roti di pop
            delqueFirst(&squeue);                               //queue siswa di dequeue
            indef = 0;                                          //mereset kembali counter infinite loop menjadi 0
        }
        else if(indef == squeue.size)
        {
            break;                                              //kalau loop sudah berjalan sebanyak jumlah siswa pada antrean lakukan break
        }                                                       //karena jika looping sudah sebanyak 
        else
        {
            temp = squeue.head->data;                           //membuat siswa paling depan pada queue kebelakang
            delqueFirst(&squeue);
            enqueLast(&squeue, temp);
            indef++;                                            //tambahkan value variabel infinite loop
        }
    }

    if(squeue.size == 0)
    {
        printf("Yeay semua dapet");                             //print output jika antrean habis
    }
    else
    {
        printf("Yah %d orang ga dapet", squeue.size);           //print output jika antrean akan infinite loop
    }
}

void initStack(Stack *stack)
{
    stack->size = 0;
    stack->head = (NodePtr) malloc(sizeof(Node));               //allocate memory for head node
    stack->head->next = NULL;                                   //assign NULL to head's link 
}

void pushElem(Stack *stack, int elem)
{
    NodePtr curr;                                               //declare a new node pointer, curr

    if(stack->size == 0)                                        //if stack doesn't have an element yet
    {
        stack->head->data = elem;                               //assign element to head's data                              
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
    while(stack.size != 0)                                      //print all the elements
    {
        printf("%d ", stack.head->data);
        stack.head = stack.head->next;
        stack.size--;
    }
}

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

void delqueFirst(Queue *queue)
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