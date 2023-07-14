#include <stdio.h>
#include <stdlib.h>
#include "palindromstack.h"

int isPalindrome(Stack stack1, Stack stack2)
{
    int diff = 0;
    while(stack1.size != 0)
    {
        if(stack1.head->data != stack2.head->data)
        {
            diff++;
        }

        popElem(&stack1);
        popElem(&stack2);

        if(diff > 0)
        {
            break;
        }
    }

    if(diff == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}