#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int num;
    struct node *next;
};
 
void create(struct node **);
int survivor(struct node **, int);
 
int main()
{
    struct node *head = NULL;
    int tagged, m;
 
    create(&head);

    scanf("%d", &m);
    tagged = survivor(&head, m);
    printf("The person to tagged is : %d\n", tagged);
    free(head);
 
}
 
int survivor(struct node **head, int k)
{
    struct node *p, *q;
    int i;
 
    q = p = *head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        free(p);
        p = q->next;
    }
    *head = p;
 
    return (p->num);
}
 
void create (struct node **head)
{
    struct node *temp, *rear;
    int n;
    int a = 1;
    
    scanf("%d", &n);
 
    while(n != 0)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = a;
        temp->next = NULL;

        if (*head == NULL)
        {
            *head = temp;
        }
        else
        {
            rear->next = temp;
        }
        rear = temp;

        a++;
        n--;
    };

    rear->next = *head;
}
