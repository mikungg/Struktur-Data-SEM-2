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