#include <stdio.h>
#include <stdlib.h>
#include "mikaqueue.h"

int main()
{
    Queue qwewe;

    initQueue(&qwewe);
    enqueLast(&qwewe, 5.3);
    enqueLast(&qwewe, 7.4);
    enqueLast(&qwewe, 2.8);
    printQueue(qwewe);
    dequeueFront(&qwewe);
    printQueue(qwewe);

    if(isEmptyq(qwewe))
    {
        printf("kosong T^T");
    }
    else
    {
        printf("ada isinya :D");
    }
}