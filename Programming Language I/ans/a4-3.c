#include <stdio.h>
#define MAX_SIZE 100000 // Memory stack size depended, supports elements values from - MAX_SIZE / 2 to MAX_SIZE / 2 - 1
int main() {
    int size, offset = MAX_SIZE / 2, frequency_array[MAX_SIZE] = {0}, order_index = 0, first_printed_flag = 0;
    printf("Enter array size: ");
    scanf("%d", &size);
    int array[size], order_array[size]; // VLAs
    printf("Enter array integer elements: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
        int index = array[i] + offset;  // Shift right to handle negative elements and store it in a temporary variable
        if(frequency_array[index] == 0) // Direct Addressing strategy for optimality
            order_array[order_index++] = array[i];  // Each element's first appearing order
        frequency_array[index]++;   // Each element's frequency
    }
    printf("All unique elements (elements that occur only once): ");
    for(int i = 0; i < order_index; i++) {
        int index = order_array[i] + offset;
        if(frequency_array[index] == 1) {
            if(first_printed_flag)  // Formatting
                printf(", ");
            else
                first_printed_flag = 1;
            printf("%d", order_array[i]);
        }
    }
    printf("\n");
    return 0;
}
