/*5. program p5.6 works with single-digit operands. Modify it to handle any integer operands.*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char ch;
} StackData;

#include "stack.h"
#include "stack.h"
#include "readConvert.h"
#include "printPostfix.h"
#include "getToken.h"
#include "precedence.h"

int main() {
    int readConvert(char[]);
    void printPostfix(char[], int);
    char post[50];

    int n = readConvert(post);

    if (n > 0)
    {
        printPostfix(post, n);
    }
    
} //end main