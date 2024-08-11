#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reheapUp(int arr[], int i) {
    if (i && arr[(i - 1) / 2] > arr[i]) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        reheapUp(arr, (i - 1) / 2);
    }
}

void insertNode(int arr[], int *n, int Key) {
    arr[*n] = Key;
    reheapUp(arr, *n);
    (*n)++;
}

void printHeap(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[9];
    int keys[] = {23, 05, 78, 34, 63, 58, 41, 17, 36};
    int n = 0;

    for(int i = 0; i < 9; i++) {
        insertNode(arr, &n, keys[i]);
    }

    printf("Array representation of Min-Heap is: \n");
    printHeap(arr, n);

    return 0;
}
