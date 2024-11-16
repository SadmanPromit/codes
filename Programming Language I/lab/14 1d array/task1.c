#include <stdio.h>
void main() {
    int i, num;
    printf("Enter size of array: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter its elements:\n");
    for(i = 0; i < num; i++)
        scanf("%d", &array[i]);
    printf("Even numbers in the array are: ");
    for(i = 0; i < num; i++)
        if(array[i] % 2 == 0)
            printf("%d \t", array[i]);
    printf("\nOdd numbers in the array are: ");
    for(i = 0; i < num; i++)
        if(array[i] % 2 != 0)
            printf("%d \t", array[i]);
}   // main
