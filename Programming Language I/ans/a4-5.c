#include <stdio.h>
void RevArr(int arr[], int size);
int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int arr[size];  // VLA
    printf("Enter array elements: ");
    for(int index = 0; index < size; index++)
        scanf("%d", &arr[index]);
    RevArr(arr, size);
    return 0;
}
void RevArr(int arr[], int size) {
    printf("Reversing the elements in the array = ");
    for(int index = 0; index < size / 2; index++) { // Swap up to half of the array
        int temp = arr[index];  // Temporary variable
        arr[index] = arr[size - 1 - index];
        arr[size - 1 - index] = temp;
        if(index)  // Formatting
            printf(", %d", arr[index]);   // Optimal
        else
            printf("%d", arr[index]);
    }
    for(int index = size / 2; index < size; index++)    // Printing the rest
        printf(", %d", arr[index]);
    printf("\n");
}
