#include <stdio.h>
#include <stdlib.h>
#include "stack2queueheader.h"

int main() {
    struct queue q;
    init(&q);

    enqueue(&q, 45);
    enqueue(&q, 21);
    enqueue(&q, 334);

    while(1)
    {
        printf("%d ", dequeue(&q));
    }
}