#include <stdio.h>
int main() {
    int size, first_print_flag = 0;
    float sum = 0, average;
    printf("Enter array size: ");
    scanf("%d", &size);
    float array[size];  // VLA
    printf("Enter elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%f", &array[i]);
        sum += array[i];    // Optimal
    }
    average = sum / size;
    printf("Average = %f, the elements greater than average are: ", average);
    for(int i = 0; i < size; i++)
        if(array[i] > average) {
            if(first_print_flag)  // Formatting
                printf(", ");
            else
                first_print_flag = 1;
            printf("%.0f", array[i]);   // Formatting
        }
    printf("\n");
    return 0;
}
