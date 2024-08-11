#include <stdio.h>
int main() {
    int num, first_flag = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter %d numbers: ", num);
    for(int i = 0; i < num; i++)
        scanf("%d", &array[i]);
    int largest = array[0]; // Initialize the largest element with the first element
    for(int i = 1; i < num; i++)    // Check for 2nd to last element
        if(array[i] > largest)
            largest = array[i];
    printf("ALL indexes in which the largest value (= %d) of the array is present = ", largest);
    for(int i = 0; i < num; i++)
        if(array[i] == largest) {
            if(first_flag)  // Formatting
                printf(", ");
            else
                first_flag++;
            printf("%d", i);
        }
    printf(".\n");
    return 0;
}
