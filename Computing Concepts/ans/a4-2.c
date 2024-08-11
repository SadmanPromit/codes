#include <stdio.h>
int main() {
    int size, first_printed_flag = 0;
    float sum = 0, average;
    printf("Enter array size: ");
    scanf("%d", &size);
    float array[size];  // VLA
    printf("Enter elements: ");
    for(int index = 0; index < size; index++) {
        scanf("%f", &array[index]);
        sum += array[index];    // Optimal
    }
    average = sum / size;
    printf("Average = %f, the elements greater than average are: ", average);
    for(int index = 0; index < size; index++)
        if(array[index] > average) {
            if(first_printed_flag)  // Formatting
                printf(", ");
            else
                first_printed_flag = 1;
            printf("%.0f", array[index]);   // Formatting
        }
    printf("\n");
    return 0;
}
