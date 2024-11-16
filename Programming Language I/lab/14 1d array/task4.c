#include <stdio.h>
void main() {
    int num, i, k;
    printf("Enter no of elements: ");
    scanf("%d", &num);
    int arr[num];
    // Read elements in an array
    printf("Enter %d numbers: ", num);
    for(i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    printf("Index of element to delete: ");
    scanf("%d", &k);
    // Shift each array element one cell
    // Left, starting from index k + 1
    for(i = k; i < num - 1; i++)
        arr[i] = arr[i + 1];
    num--;  // Decrease No of elements
    printf("Array after deleting the element at index: %d\n", k);
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);
}
