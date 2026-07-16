#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *arr;      
    int top;
    int size;
};

// Initialize Stack
void init(struct Stack *s, int size)
{
    s->arr = (int *)malloc(size * sizeof(int));
    s->size = size;
    s->top = -1;
}

// Check Empty
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Check Full
int isFull(struct Stack *s)
{
    return s->top == s->size - 1;
}

// Push
void push(struct Stack *s, int value)
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
int pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return s->arr[s->top--];
}

// Peek
int peek(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty\n");
        return -1;
    }

    return s->arr[s->top];
}

// Display
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
        printf("%d ", s->arr[i]);
    }

    printf("\n");
}

// Free Memory
void destroy(struct Stack *s)
{
    free(s->arr);
}

int main()
{
    struct Stack s;

    init(&s, 5);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    display(&s);

    printf("Popped = %d\n", pop(&s));

    display(&s);

    printf("Top Element = %d\n", peek(&s));

    destroy(&s);

    return 0;
}