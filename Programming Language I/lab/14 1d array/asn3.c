#include <stdio.h>
int main() {
    int num, largest, smallest, second_largest = - 2147483648, second_smallest = 2147483647;    // int type limits for comparing values
    printf("Enter no. of elements: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter %d numbers: ", num);
    for(int i = 0; i < num; i++)
        scanf("%d", &array[i]);
    largest = smallest = array[0];  // Initialize the largest & smallest to the first element
    for(int i = 0; i < num; i++) {
        if(array[i] > largest) {
            second_largest = largest;   // Update the second largest element
            largest = array[i]; // Update the largest element
        }
        else if(array[i] > second_largest && array[i] < largest)
             second_largest = array[i];
        if(array[i] < smallest) {
            second_smallest = smallest; // Update the second smallest element
            smallest = array[i];    // Update the smallest element
        }
        else if(array[i] < second_smallest && array[i] > smallest)
             second_smallest = array[i];
    }
    printf("The 2nd largest element = %d\nThe 2nd smallest element = %d\n", second_largest, second_smallest);
    return 0;
}
