#include <stdio.h>
#include <stdlib.h>
#include "DoubleStack.h"

int main()
{
    stack s;

    init_stack(&s);
    push(&s, 4.2);
    push(&s, 5.3);

    while(is_empty(&s) != 1)
    {
        printf("%.2f\n", pop(&s));
    }

    return 0;
}