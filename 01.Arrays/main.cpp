#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

// Display
void Display(struct Array arr) {
    printf("Array: ");
    for (int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
    printf("\n");
}

// Append
void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length] = x;
        arr->length++;
    }
}

// Insert
void Insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length) {
        for (int i = arr->length; i > index; i--)
            arr->A[i] = arr->A[i - 1];

        arr->A[index] = x;
        arr->length++;
    }
}

// Delete
int Delete(struct Array *arr, int index) {
    int x = -1;

    if (index >= 0 && index < arr->length) {
        x = arr->A[index];

        for (int i = index; i < arr->length - 1; i++)
            arr->A[i] = arr->A[i + 1];

        arr->length--;
    }

    return x;
}

// Linear Search
int LinearSearch(struct Array arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == key)
            return i;
    }
    return -1;
}

// Get
int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];

    return -1;
}

// Set
void Set(struct Array *arr, int index, int value) {
    if (index >= 0 && index < arr->length)
        arr->A[index] = value;
}

// Maximum
int Max(struct Array arr) {
    int max = arr.A[0];

    for (int i = 1; i < arr.length; i++)
        if (arr.A[i] > max)
            max = arr.A[i];

    return max;
}

// Minimum
int Min(struct Array arr) {
    int min = arr.A[0];

    for (int i = 1; i < arr.length; i++)
        if (arr.A[i] < min)
            min = arr.A[i];

    return min;
}

// Sum
int Sum(struct Array arr) {
    int sum = 0;

    for (int i = 0; i < arr.length; i++)
        sum += arr.A[i];

    return sum;
}

// Average
float Average(struct Array arr) {
    return (float)Sum(arr) / arr.length;
}

// Reverse
void Reverse(struct Array *arr) {
    int temp;

    for (int i = 0, j = arr->length - 1; i < j; i++, j--) {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main() {
    struct Array arr;

    arr.size = 10;
    arr.length = 5;
    arr.A = (int *)malloc(arr.size * sizeof(int));

    arr.A[0] = 10;
    arr.A[1] = 20;
    arr.A[2] = 30;
    arr.A[3] = 40;
    arr.A[4] = 50;

    Display(arr);

    Append(&arr, 60);
    Display(arr);

    Insert(&arr, 2, 25);
    Display(arr);

    Delete(&arr, 4);
    Display(arr);

    printf("Search 40 = %d\n", LinearSearch(arr, 40));

    printf("Element at index 3 = %d\n", Get(arr, 3));

    Set(&arr, 0, 100);
    Display(arr);

    printf("Maximum = %d\n", Max(arr));
    printf("Minimum = %d\n", Min(arr));
    printf("Sum = %d\n", Sum(arr));
    printf("Average = %.2f\n", Average(arr));

    Reverse(&arr);
    Display(arr);

    free(arr.A);

    return 0;
}