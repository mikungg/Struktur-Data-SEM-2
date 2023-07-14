#include <stdio.h>
#include <ctype.h>

typedef struct {
    int num;
} StackData;

#include "stack.h"

int main() {
    int readConvert(int[]);
    void printPostfix(int[], int);
    int post[50];

    int n = readConvert(post);

    if (n > 0)
    {
        printPostfix(post, n);
    }
    
} //end main

int readConvert(int post[]) {
    char getToken(void), token, c;
    int precedence(char);
    StackData temp;
    int h = 0, detectBrackets = 0;

    Stack S = initStack();
    printf("Type an infix expression and press Enter\n");
    
    token = getToken();
    
    while (token != '\n') {
        if (isdigit(token)){
            // read in multiple digits to form the full operand
            int operand = token - '0';
            while (isdigit(token = getToken()))
            {
                operand = operand * 10 + (token - '0');
            }
            post[h++] = operand; // store the integer operand directly
            continue;

        } else if (token == '(') {
            detectBrackets++;
            temp.num = -1; // use -1 to represent '('
            push(S, temp);
        } else if (token == ')') {
            if (detectBrackets > 0)
            {
                detectBrackets--;

                while ((c = pop(S).num) != -1) {
                    post[h++] = c;
                }
            } else if (detectBrackets < 0)
            {
                printf("Mismatched brackets detected.\n");
                exit(0);
            }
            
        } else {
            int prec = precedence(token);
            while (!empty(S) && precedence(peek(S).num) >= prec){
                post[h++] = pop(S).num;
            }
            temp.num = -prec; // use negative values to represent operators
            push(S, temp);
        }
        
        token = getToken();
    } //end while
        
    while (!empty(S)) {
        if (detectBrackets > 0)
        {
            printf("Error: Mismatched opening bracket.\n");
            exit(0);
        }
        post[h++] = pop(S).num;
    }

    if (detectBrackets > 0)
    {
        printf("Error: Mismatched opening bracket.\n");
        exit(0);
    }
    post[h] = 0; // use 0 to indicate the end of the expression
    return h + 1; //the size of the expression, including the end marker
} //end readConvert

void printPostfix(int post[], int n) {
    printf("\nThe postfix form is \n");

    for (int h = 0; post[h] != 0; h++) {
        if (post[h] >= 0) {
            printf("%d ", post[h]);
        } else {
            switch (post[h]) {
                case -1: printf("( "); break;
                case -2: printf("+ "); break;
                case -3: printf("* "); break;
                case -4: printf("/ "); break;
            }
        }
    }

    printf("\n");
} //end printPostfix

char getToken() {
    char ch;
    
    while ((ch = getchar()) == ' ') ; //empty body
    return ch;
} //end getToken

int precedence(char c) {
    if (c == '(') return 0;
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
} //end precedence