#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct Node* next; 
} Node;

Node* addMhs(int);
Node* delMhs(Node*);
int solve(Node*, int);

int main(){
    int t, n, x;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d %d", &n, &x);

        Node* head = addMhs(n);

        int classLeader = solve(head, x);
        printf("%d\n", classLeader);

        //Membebaskan memori linked list sebelum menyelesaikan program
        Node* currentnode = head;
        Node* nextnode = NULL;
        do{
            nextnode = currentnode->next;
            free(currentnode);
            currentnode = nextnode;
        }while(currentnode != head);
    }
}

Node* addMhs(int bil){
    Node* head = NULL;
    Node* tail = NULL;
    for(int i=0; i<bil; i++){
        Node* newnode = (Node*) malloc(sizeof(Node));
        newnode->data = i+1;
        if(head == NULL){
            head = newnode;
            tail = newnode;
        } 
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }
    tail->next = head;
    return head;
}

Node* delMhs(Node* currentnode){
    Node* removednode = currentnode->next;
    currentnode->next = removednode->next;
    free(removednode);
    currentnode = currentnode->next;
    return currentnode;
}

int solve(Node* head, int bil){
    Node *currentnode = head;
    while(currentnode->next != currentnode){
        for(int i=0; i<bil-1; i++){
            currentnode = currentnode->next;
        }
        printf("%d ", currentnode->next->data);
        currentnode = delMhs(currentnode);
    }
    printf("@\n");
    return currentnode->data;
}