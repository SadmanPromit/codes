#include <stdio.h>
void main() {
    int i, num, count_even = 0, count_odd = 0;
    printf("Enter size of array: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter its elements:\n");
    for(i = 0; i < num; i++)
        scanf("%d", &array[i]);
    for(i = 0; i < num; i++)
        if(array[i] % 2 == 0)
            count_even++;
    for(i = 0; i < num; i++)
        if(array[i] % 2 != 0)
            count_odd++;
    printf("No. of even numbers: %d\nNo. of odd numbers: %d\n", count_even, count_odd);
}   // main
