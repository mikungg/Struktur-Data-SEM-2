#include "mikaqueue.h"
#include <stdlib.h>

int isEmptyq(Queue queue)
{
    if(queue.size == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}