#include <stdio.h>
void replacePerfectNumbers(int *array, int *size, int key);
int main() {
    int size, key;
    printf("Enter Array Size: ");
    scanf("%d", &size);
    int array[size];    // VLA
    printf("Array Elements: ");
    for(int index = 0; index < size; ++index)
        scanf("%d", &array[index]);
    printf("Key Value: ");
    scanf("%d", &key);
    replacePerfectNumbers(array, &size, key);
    for(int index = 0; index < size; ++index)
        printf("%d ", array[index]);
    printf("\n");
    return 0;
}
void replacePerfectNumbers(int *array, int *size, int key) {
    for(int *ptr = array, ifPrime = 1, primeSum = 0; ptr < array + *size; ++ptr, ifPrime = 1, primeSum = 0) {
        for(int divisor = 1; divisor < *ptr; ++divisor)
            if(*ptr % divisor == 0) {
                primeSum += divisor;
            }
        if(*ptr == primeSum)
            *ptr = key;
    }
}
