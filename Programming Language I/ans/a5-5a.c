#include <stdio.h>
void rev_arr(int arr1[], int rev_arr1[], int size);
int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr1[size], rev_arr1[size]; // VLAs
    printf("Enter array elements: ");
    for(int index = 0; index < size; ++index)
        scanf("%d", &arr1[index]);
    rev_arr(arr1, rev_arr1, size);
    printf("Array elements in reverse order: ");
    for(int index = 0; index < size; ++index)
        printf("%d ", rev_arr1[index]);
    printf("\n");
    return 0;
}
void rev_arr(int arr1[], int rev_arr1[], int size) {
    for(int rev_index = 0, index = size - 1; rev_index < size; ++rev_index, --index)
        rev_arr1[rev_index] = arr1[index];
}
