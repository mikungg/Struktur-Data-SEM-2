typedef struct {
    double data[100];
    int top;
} stack;

void init_stack(stack* s)               //set the top of the stack to -1 (array stack)
{
    s->top = -1;
}

void push(stack* s, double val)         //insert a value to the top of the stack
{
    if (s->top == 100 - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }

    s->data[++s->top] = val;
}

double pop(stack* s)
{
    if (s->top == -1)                   //bring out the value of the top of the stack then delete it from the stack
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

double peek(stack* s)
{
    if (s->top == -1)                   //peek the top of the stack (doesn't delete the value from the stack)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top];
}

int is_empty(stack* s)                  //function to check if the stack is empty or not (return 1 if the stack is empty)
{
    return s->top == -1;
}