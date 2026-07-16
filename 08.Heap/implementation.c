#include <stdio.h>
#include <stdlib.h>

struct MaxHeap
{
    int *arr;
    int size;
    int totalSize;
};

// Initialize Heap
void initHeap(struct MaxHeap *h, int n)
{
    h->arr = (int *)malloc(n * sizeof(int));
    h->size = 0;
    h->totalSize = n;
}

// Swap two numbers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into Heap
void insert(struct MaxHeap *h, int value)
{
    if (h->size == h->totalSize)
    {
        printf("Heap Overflow\n");
        return;
    }

    h->arr[h->size] = value;
    int index = h->size;
    h->size++;

    // Move upward
    while (index > 0 && h->arr[(index - 1) / 2] < h->arr[index])
    {
        swap(&h->arr[(index - 1) / 2], &h->arr[index]);
        index = (index - 1) / 2;
    }

    printf("%d inserted into the heap\n", value);
}

// Print Heap
void printHeap(struct MaxHeap *h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

// Heapify
void heapify(struct MaxHeap *h, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->arr[left] > h->arr[largest])
        largest = left;

    if (right < h->size && h->arr[right] > h->arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(&h->arr[index], &h->arr[largest]);
        heapify(h, largest);
    }
}

// Delete Root
void deleteHeap(struct MaxHeap *h)
{
    if (h->size == 0)
    {
        printf("Heap Underflow\n");
        return;
    }

    printf("%d deleted from the Heap!\n", h->arr[0]);

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    if (h->size == 0)
        return;

    heapify(h, 0);
}

// Free Memory
void destroyHeap(struct MaxHeap *h)
{
    free(h->arr);
    h->arr = NULL;
}

int main()
{
    struct MaxHeap h1;

    initHeap(&h1, 6);

    insert(&h1, 1);
    insert(&h1, 2);
    insert(&h1, 3);

    printHeap(&h1);

    insert(&h1, 134);
    insert(&h1, 142);
    insert(&h1, 156);

    printHeap(&h1);

    deleteHeap(&h1);
    printHeap(&h1);

    deleteHeap(&h1);
    printHeap(&h1);

    destroyHeap(&h1);

    return 0;
}