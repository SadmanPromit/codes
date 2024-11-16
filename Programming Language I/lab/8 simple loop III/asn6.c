#include <stdio.h>
int main() {
     int total_amount = 0, total_price = 0;
     float average_price;
    while(1) {
        // Initialize buffers inside loop to clear values in each iteration for optimization
        int buffer1, buffer2;
        printf("Enter amount (in kg): ");
        scanf("%d", &buffer1);
        // Checking false conditions
        if(buffer1 == 0)
            break;
        else if(buffer1 < 0) {
            printf("Invalid input, enter a positive number\n");
            continue;
        }
        printf("Enter price: ");
        scanf("%d", &buffer2);
        if(buffer2 == 0)
            break;
        else if(buffer2 < 0) {
            printf("Invalid input, enter a positive number\n");
            continue;
        }
        // Calculations for the true condition
        total_amount += buffer1;
        total_price += buffer2;
    }
    average_price = (float) total_price / total_amount;
    printf("Total amount (in kg): %d, Total price: %d, Average price per kg: %.2f\n", total_amount, total_price, average_price);
    return 0;
}
