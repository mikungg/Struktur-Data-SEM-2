#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    int data;
    struct node *next;                                              //buat node

} Node, *NodePtr;

typedef struct stack{
    NodePtr head;                                                   //buat stack yang berisi pointer to node dan size
    int size;

} Stack;

void initStack(Stack *);                                            //prototype fungsi
void pushElem(Stack *, int);
void printStack(Stack);
void popElem(Stack *);
void sortStack(Stack *);

int main()
{
    Stack pstacks;                                                  //deklarasikan stack

    int k, n, p;                                                    //deklarasikan variabel-variabel
    int unopened = 0;

    scanf("%d %d", &k, &n);                                         //masukkan input k dan n
    initStack(&pstacks);                                            //buat node head

    while(k != 0)
    {
        scanf("%d", &p);                                            
        pushElem(&pstacks, p);                                      //push value kedalam stack
        k--;
    }

    sortStack(&pstacks);                                            //urutkan stack dari besar ke kecil

    NodePtr trav;
    NodePtr trav2;
    trav = pstacks.head;
    while(n != 0)                                                   //algoritma buka kado
    {   
        if(trav == pstacks.head)                                    //jika pointer trav masih di head
        {
            pstacks.head->data = sqrt(trav->data);                  //akarkan elemen di head
            trav = pstacks.head->next;                              //traverse ponter trav
            trav2 = pstacks.head;                                   //assign pointer trav2 ke head
            n--;                                                    //decrement n
        }
        else                                                        //jika pointer trav sudah tidak di head
        {
            while(trav2 != trav)                                    //selama trav2 belum mencapai trav
            {
                if(trav2->data > trav->data)                        //jika elemen pada trav2 > dari elemen trav
                {
                    trav2->data = sqrt(trav2->data);                //akarkan elemen trav2
                    n--;                                            //decrement n
                }
                if(n == 0)                                          //jika n == 0, break;
                {
                    break;
                }
                trav2 = trav2->next;                                //traverse ponter trav2
            }
            if(n > 0)                                               //jika n masih lebih dari 0
            {
                trav->data = sqrt(trav->data);                      //akarkan elemen pada trav
                n--;                                                //decrement n
                trav2 = pstacks.head;                               //reset pointer trav2 ke head
                trav = trav->next;                                  //traverse trav
            }
        }
    }

    while(pstacks.size != 0)
    {
        unopened += pstacks.head->data;                             //tambahkan semua kado yang tidak dibuka
        popElem(&pstacks);
    }
    printf("%d", unopened);                                         //output
}

void initStack(Stack *stack)
{
    stack->size = 0;
    stack->head = (NodePtr) malloc(sizeof(Node));
    stack->head->next = NULL;
}

void pushElem(Stack *stack, int elem)
{
    NodePtr curr;

    if(stack->size == 0)
    {
        stack->head->data = elem;
        stack->head->next = NULL;
        stack->size++;
    }
    else
    {
        NodePtr curr = (NodePtr) malloc(sizeof(Node));
        curr->data = elem;
        curr->next = stack->head;
        stack->head = curr;
        stack->size++;
    }
}

void printStack(Stack stack)
{
    while(stack.size != 0)
    {
        printf("%d ", stack.head->data);
        stack.head = stack.head->next;
        stack.size--;
    }
}

void popElem(Stack *stack)
{
    NodePtr curr;

    if(stack->size == 1)
    {
        stack->head->data = 0;
        stack->size--;
    }
    else
    {
        curr = stack->head->next;
        free(stack->head);
        stack->head = curr;
        stack->size--;
    }
}

void sortStack(Stack *stack)
{
    Stack temp;
    int datatemp;
    temp.size = 0;
    
    initStack(&temp);
    pushElem(&temp, stack->head->data);
    popElem(stack);
    while(stack->size != 0)
    {
        if(temp.head->data > stack->head->data)
        {
            datatemp = stack->head->data;
            popElem(stack);
            while(temp.head->data > datatemp)
            {
                pushElem(stack, temp.head->data);
                popElem(&temp);
            }
            pushElem(&temp, datatemp);
        }
        else
        {
            pushElem(&temp, stack->head->data);
            popElem(stack);
        }
    }

    *stack = temp;
}
