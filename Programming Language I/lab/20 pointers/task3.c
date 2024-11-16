#include <stdio.h>
void reversePrint(int *, int);
int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int array[size];  // VLA
    printf("Enter array elements: ");
    for(int index = 0; index < size; index++)
        scanf("%d", array + index);
    reversePrint(array, size);
    return 0;
}
void reversePrint(int *array, int size) {
    printf("Array elements in reverse order: ");
    for(--size; size >= 0; --size)
        printf("%d ", *(array + size));
    printf("\n");
}
