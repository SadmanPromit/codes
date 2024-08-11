#include <stdio.h>
int main() {
    int size, index_odd = 0, index_even = 0;
    printf("Input size of the array: ");
    scanf("%d", &size);
    int array[size], array_even[size], array_odd[size];
    printf("Input elements in array: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
    for(int i = 0; i < size; i++)
        if(array[i] % 2)
            array_odd[index_odd++] = array[i];
        else
            array_even[index_even++] = array[i];
    printf("Even elements in array: ");
    for(int i = 0; i < index_even; i++)
        printf("%d ", array_even[i]);
    printf("\nOdd elements in array: ");
    for(int i = 0; i < index_odd; i++)
        printf("%d ", array_odd[i]);
    printf("\n");
    return 0;
}




