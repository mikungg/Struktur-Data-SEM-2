#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "evaluatePostfix.h"

int main()
{
    char expression[] = "2 3 + 8 4 / * 6 -";
    int result = evaluate_postfix(expression);
    printf("%d\n", result);
    return 0;
}
