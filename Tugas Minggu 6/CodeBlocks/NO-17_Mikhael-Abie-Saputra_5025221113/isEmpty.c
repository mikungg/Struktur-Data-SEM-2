#include <stdio.h>
#include <stdlib.h>
#include "queue2tostack.h"

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}