/*5. program p5.6 works with single-digit operands. Modify it to handle any integer operands.*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    char ch;
} StackData;

#include "stack.h"

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

int readConvert(char post[]) {
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
            post[h++] = operand + '0'; // convert the integer operand back to a string
            continue;

            post[h++] = token;   
        } else if (token == '(') {
            detectBrackets++;
            temp.ch = token;
            push(S, temp);
        } else if (token == ')') {
            if (detectBrackets > 0)
            {
                detectBrackets--;

                while ((c = pop(S).ch) != '(') {
                post[h++] = c;
                }
            } else if (detectBrackets < 0)
            {
                printf("Mismatched brackets detected.\n");
                exit(0);
            }
            
        } else {
            while (!empty(S) && precedence(peek(S).ch) >= precedence(token)){
            post[h++] = pop(S).ch;
            }
            temp.ch = token;
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
            post[h++] = pop(S).ch;
        }

        if (detectBrackets > 0)
        {
            printf("Error: Mismatched opening bracket.\n");
            exit(0);
        }
    return h; //the size of the expression
} //end readConvert

void printPostfix(char post[], int n) {
    printf("\nThe postfix form is \n");

    for (int h = 0; h < n; h++) {
        printf("%c ", post[h]);
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
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '^') return 4;
    if (c == 's' || c == 'c' || c == 't' || c == 'l') return 6;
    else return -1;
} //end precedence