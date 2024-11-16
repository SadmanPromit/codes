#include <stdio.h>
void findNumber(int *, int, int);
int main() {
    int size, find_number;
    printf("Enter array size: ");
    scanf("%d", &size);
    int array[size];  // VLA
    printf("Enter array elements: ");
    for(int index = 0; index < size; index++)
        scanf("%d", array + index);
    printf("Enter number to find: ");
    scanf("%d", &find_number);
    findNumber(array, size, find_number);
    return 0;
}
void findNumber(int *array, int size, int find_number) {
    for(int index = 0; index < size; index++)
        if(*(array + index) == find_number)
            printf("Matching element's index = %d & memory address = %p\n", index, (void *) (array + index));
}
