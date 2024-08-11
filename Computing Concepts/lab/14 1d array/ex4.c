#include <stdio.h>
int main() {
    int num, first_flag = 0;
    printf("Enter no. of elements: ");
    scanf("%d", &num);
    int array[num];
    printf("Enter %d numbers: ", num);
    for(int i = 0; i < num; i++)
        scanf("%d", &array[i]);
    int smallest = array[0]; // Initialize the smallest element with the first element
    for(int i = 1; i < num; i++)    // Check for 2nd to last element
        if(array[i] < smallest)
            smallest = array[i];
    printf("ALL indexes in which the smallest value (= %d) of the array is present = ", smallest);
    for(int i = 0; i < num; i++)
        if(array[i] == smallest) {
            if(first_flag)  // Formatting
                printf(", ");
            else
                first_flag++;
            printf("%d", i);
        }
    printf(".\n");
    return 0;
}
