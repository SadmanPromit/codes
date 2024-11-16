#include <stdio.h>
int max(int *p, int size);
int main() {
    int size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int array[size];    // VLA
    printf("Enter array elements: ");
    for(int *ptr = array; ptr < array + size; ++ptr)
        scanf("%d", ptr);
    printf("Max = %d\n", max(array, size));
    return 0;
}
int max(int *p, int size) {
    int max = *p;   // Initialize max to first element
    for(int *ptr = p; ptr < p + size; ++ptr)    // Loop from second to last element
        if(max < *ptr)
            max = *ptr;
    return max;
}
