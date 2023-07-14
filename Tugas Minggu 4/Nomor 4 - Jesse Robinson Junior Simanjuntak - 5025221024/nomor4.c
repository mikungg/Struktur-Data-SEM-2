/*4. Modify program p5.6 to recognize infix expressions with mismatched brackets.*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char ch;
} StackData;

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