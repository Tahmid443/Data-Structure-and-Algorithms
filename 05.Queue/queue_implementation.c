#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;      // Dynamic Array
    int front;
    int rear;
    int size;
};

// Initialize Queue
void init(struct Queue *q, int size)
{
    q->arr = (int *)malloc(size * sizeof(int));
    q->size = size;
    q->front = -1;
    q->rear = -1;
}

// Check Empty
int isEmpty(struct Queue *q)
{
    return q->front == -1;
}

// Check Full
int isFull(struct Queue *q)
{
    return q->rear == q->size - 1;
}

// Enqueue
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;
}

// Dequeue
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return value;
}

// Peek
int peek(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }

    return q->arr[q->front];
}

// Display
void display(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }

    printf("\n");
}

// Free Memory
void destroy(struct Queue *q)
{
    free(q->arr);
}

int main()
{
    struct Queue q;

    init(&q, 5);   // Queue size = 5

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);

    printf("Front Element: %d\n", peek(&q));

    destroy(&q);

    return 0;
}