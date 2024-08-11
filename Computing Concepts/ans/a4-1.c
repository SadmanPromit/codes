#include <stdio.h>
int main() {
    int size, k;
    printf("Enter array size: ");
    scanf("%d", &size);
    int array[++size];  // VLA with k-th position included
    printf("Enter array elements: ");
    for(int index = 0; index < size - 1; index++)
        scanf("%d", &array[index]);
    printf("Enter position, k: ");
    scanf("%d", &k);
    for(int index = size - 1; index >= k + 1; index--)  // Shift right 1 position from k
        array[index] = array[index - 1];
    printf("Enter k-th element: ");
    scanf("%d", &array[k]);
    printf("Array elements after insertion: ");
    for(int index = 0; index < size; index++)
        if(index)   // Formatting
            printf(", %d", array[index]);
        else
            printf("%d", array[index]);
    printf("\n");
    return 0;
}
