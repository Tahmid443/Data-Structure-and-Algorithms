#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size;
    int capacity;
} Heap;

//------------------------Create Heap------------------------
Heap* createHeap(int capacity)
{
    Heap *heap = (Heap*)malloc(sizeof(Heap));

    heap->arr = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;

    return heap;
}

//------------------------Swap------------------------
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//------------------------Resize------------------------
void resizeHeap(Heap *heap)
{
    heap->capacity *= 2;
    heap->arr = (int*)realloc(heap->arr,
                              heap->capacity * sizeof(int));
}

//------------------------Heapify Up------------------------
void heapifyUp(Heap *heap, int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap->arr[parent] < heap->arr[index])
        {
            swap(&heap->arr[parent], &heap->arr[index]);
            index = parent;
        }
        else
            break;
    }
}

//------------------------Heapify Down------------------------
void heapifyDown(Heap *heap, int index)
{
    while(1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if(left < heap->size &&
           heap->arr[left] > heap->arr[largest])
            largest = left;

        if(right < heap->size &&
           heap->arr[right] > heap->arr[largest])
            largest = right;

        if(largest != index)
        {
            swap(&heap->arr[index], &heap->arr[largest]);
            index = largest;
        }
        else
            break;
    }
}

//------------------------Insert------------------------
void insert(Heap *heap, int value)
{
    if(heap->size == heap->capacity)
        resizeHeap(heap);

    heap->arr[heap->size] = value;

    heapifyUp(heap, heap->size);

    heap->size++;
}

//------------------------Peek------------------------
int peek(Heap *heap)
{
    if(heap->size == 0)
        return -1;

    return heap->arr[0];
}

//------------------------Extract Max------------------------
int extractMax(Heap *heap)
{
    if(heap->size == 0)
        return -1;

    int root = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size - 1];

    heap->size--;

    heapifyDown(heap, 0);

    return root;
}

//------------------------Delete Root------------------------
void deleteRoot(Heap *heap)
{
    if(heap->size == 0)
    {
        printf("Heap Empty\n");
        return;
    }

    printf("Deleted : %d\n", extractMax(heap));
}

//------------------------Search------------------------
int search(Heap *heap, int value)
{
    for(int i = 0; i < heap->size; i++)
    {
        if(heap->arr[i] == value)
            return i;
    }

    return -1;
}

//------------------------Increase Key------------------------
void increaseKey(Heap *heap, int index, int newValue)
{
    if(index >= heap->size)
        return;

    if(newValue < heap->arr[index])
        return;

    heap->arr[index] = newValue;

    heapifyUp(heap, index);
}

//------------------------Decrease Key------------------------
void decreaseKey(Heap *heap, int index, int newValue)
{
    if(index >= heap->size)
        return;

    if(newValue > heap->arr[index])
        return;

    heap->arr[index] = newValue;

    heapifyDown(heap, index);
}

//------------------------Build Heap------------------------
void buildHeap(Heap *heap, int arr[], int n)
{
    while(heap->capacity < n)
        resizeHeap(heap);

    heap->size = n;

    for(int i = 0; i < n; i++)
        heap->arr[i] = arr[i];

    for(int i = n/2 - 1; i >= 0; i--)
        heapifyDown(heap, i);
}

//------------------------Print------------------------
void printHeap(Heap *heap)
{
    if(heap->size == 0)
    {
        printf("Heap Empty\n");
        return;
    }

    printf("\nHeap : ");

    for(int i = 0; i < heap->size; i++)
        printf("%d ", heap->arr[i]);

    printf("\n");
}

//------------------------Heap Sort------------------------
void heapSort(Heap *heap)
{
    Heap temp = *heap;

    temp.arr = (int*)malloc(sizeof(int) * heap->capacity);

    for(int i = 0; i < heap->size; i++)
        temp.arr[i] = heap->arr[i];

    printf("\nSorted (Descending): ");

    while(temp.size > 0)
        printf("%d ", extractMax(&temp));

    printf("\n");

    free(temp.arr);
}

//------------------------Destroy------------------------
void destroyHeap(Heap *heap)
{
    free(heap->arr);
    free(heap);
}

//------------------------Main------------------------
int main()
{
    Heap *heap = createHeap(5);

    int choice, value, index;

    while(1)
    {
        printf("\n===== MAX HEAP =====\n");
        printf("1.Insert\n");
        printf("2.Delete Root\n");
        printf("3.Peek\n");
        printf("4.Search\n");
        printf("5.Print\n");
        printf("6.Increase Key\n");
        printf("7.Decrease Key\n");
        printf("8.Heap Sort\n");
        printf("9.Exit\n");

        printf("Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Value : ");
                scanf("%d", &value);
                insert(heap, value);
                break;

            case 2:
                deleteRoot(heap);
                break;

            case 3:
                printf("Maximum = %d\n", peek(heap));
                break;

            case 4:
                printf("Value : ");
                scanf("%d", &value);

                index = search(heap, value);

                if(index == -1)
                    printf("Not Found\n");
                else
                    printf("Found at Index %d\n", index);

                break;

            case 5:
                printHeap(heap);
                break;

            case 6:
                printf("Index NewValue : ");
                scanf("%d%d", &index, &value);
                increaseKey(heap, index, value);
                break;

            case 7:
                printf("Index NewValue : ");
                scanf("%d%d", &index, &value);
                decreaseKey(heap, index, value);
                break;

            case 8:
                heapSort(heap);
                break;

            case 9:
                destroyHeap(heap);
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}