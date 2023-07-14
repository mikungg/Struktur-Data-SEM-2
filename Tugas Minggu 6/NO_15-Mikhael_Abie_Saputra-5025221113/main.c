#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "palindromstack.h"

int main()
{
    Stack line, revline;
    char str[100];

    initStack(&line);
    initStack(&revline);

    scanf("%s", str);

    for(int i=strlen(str)-1, j=0; i>=0; i--, j++)
    {
        pushElem(&line, str[i]);
        pushElem(&revline, str[j]);
    }

    printStack(line);
    printStack(revline);
    
    if(isPalindrome(line, revline) == 1)
    {
        printf("yey palindrom");
    }
    else
    {
        printf("yah bukan palindrom");
    }
}