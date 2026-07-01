#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
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
    return (q->rear + 1) % q->size == q->front;
}

// Enqueue
void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue Overflow\n");
        return;
    }

    // First element
    if (isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
    }

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

    // Last element removed
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
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

    int i = q->front;

    while (1)
    {
        printf("%d ", q->arr[i]);

        if (i == q->rear)
            break;

        i = (i + 1) % q->size;
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

    init(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));

    display(&q);

    enqueue(&q, 50);
    enqueue(&q, 60);

    display(&q);

    printf("Front Element: %d\n", peek(&q));

    destroy(&q);

    return 0;
}