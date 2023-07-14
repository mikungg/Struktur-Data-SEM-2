#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
};

typedef struct List{
    struct node *head;
    struct node *current;
} List;

void dlist_init(List *list) {

}

void printElement(int *elem) {

}

void multiply2(int *elem) {
}

int main()
{
    List *myList;
    dlist_init(&myList);

    // Anggap isi linked list adalah [1,2,3,4,5]
    // .
    // .
    // .

    // contoh fungsi forEachElement untuk mencetak data pada list

    forEachElement(&myList, printElement);

    // contoh fungsi forEachElement untuk mengalikan setiap elemen
    // dengan 2

    forEachElement(&myList, multiply2);

    // isi list menjadi [2,4,6,8,10]
    return 0;
}