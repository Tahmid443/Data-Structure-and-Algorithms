#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Stack
{
    char *arr;      
    int top;
    int size;
};

// Initialize Stack
void init(struct Stack *s, int size)
{
    s->arr = (char *)malloc(size * sizeof(char));
    s->size = size;
    s->top = -1;
}

// Check Empty
bool isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Check Full
bool isFull(struct Stack *s)
{
    return s->top == s->size - 1;
}

// Push
void push(struct Stack *s, char value)
{
    if(isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->arr[s->top] = value;
}

// Pop
char pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
        return '\0';
    }

    return s->arr[s->top--];
}

// Peek
char peek(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty\n");
        return '\0';
    }

    return s->arr[s->top];
}

// Display Stack
void display(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack: ");

    for(int i = s->top; i >= 0; i--)
    {
        printf("%c ", s->arr[i]);
    }

    printf("\n");
}

// Free Memory
void destroy(struct Stack *s)
{
    free(s->arr);
}

// Check Matching Brackets
bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '{' && close == '}')
        return true;

    if (open == '[' && close == ']')
        return true;

    return false;
}

// Valid Parentheses Function
bool isValid(char str[])
{
    int n = strlen(str);

    struct Stack s;
    init(&s, n);

    for(int i = 0; i < n; i++)
    {
        char ch = str[i];

        // Opening bracket
        if(ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        // Closing bracket
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(isEmpty(&s))
            {
                destroy(&s);
                return false;
            }

            char top = pop(&s);

            if(!isMatching(top, ch))
            {
                destroy(&s);
                return false;
            }
        }
    }

    bool ans = isEmpty(&s);

    destroy(&s);

    return ans;
}

int main()
{
    char str[100];

    printf("Enter expression: ");
    scanf("%99s", str);

    if(isValid(str))
        printf("Valid Parentheses\n");
    else
        printf("Invalid Parentheses\n");

    return 0;
}