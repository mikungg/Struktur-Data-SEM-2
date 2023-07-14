/*
    Function to evaluate postfix expression
*/
int evaluate_postfix(char* expression)
{
    int stack[100];                                         //initiate array stack
    int top = -1;
    char* token = strtok(expression, " ");

    while (token != NULL)
    {
        if (isdigit(token[0]))                              //if the token is not an operator then operand is converted from string to int
        {
            int operand = atoi(token);                      
            stack[++top] = operand;                         //insert the operand to the top of the stack
        }
        else
        {
            int operand2 = stack[top--];                    //operand2 is assigned from the top of the stack, then delete the element
            int operand1 = stack[top--];                    //operand1 is assigned from the second top of the stack, then delete the element
            int result;
            switch (token[0])
            {
                case '+':
                    result = operand1 + operand2;           //aritmethic operations
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid token: %s\n", token);
                    exit(1);
            }
            stack[++top] = result;                              //the result is inserted at the top of the stack
        }
        token = strtok(NULL, " ");                              
    }

    if (top != 0)
    {
        printf("Invalid expression\n");                         //if the top is not 0 at the end then print "Invalid expression"
        exit(1);
    }

    return stack[top];                                          //return the last integer
}