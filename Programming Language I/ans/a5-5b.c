#include <stdio.h>
void rev_arr(int *arr1, int *rev_arr1, int size);
int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr1[size], rev_arr1[size]; // VLA
    printf("Enter array elements: ");
    for(int *ptr = arr1; ptr < arr1 + size; ++ptr)
        scanf("%d", ptr);
    rev_arr(arr1, rev_arr1, size);
    printf("Array elements in reverse order: ");
    for(int *ptr = rev_arr1; ptr < rev_arr1 + size; ++ptr)
        printf("%d ", *ptr);
    printf("\n");
    return 0;
}
void rev_arr(int *arr1, int *rev_arr1, int size) {
    for(int *ptr = arr1 + size - 1; ptr >= arr1; --ptr, ++rev_arr1)
        *rev_arr1 = *ptr;
}
