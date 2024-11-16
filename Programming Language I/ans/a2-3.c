#include <stdio.h>
int main() {
    int buffer, sum = 0;
    while(1) {
        printf("Enter integer number to add (0 for output): ");
        scanf("%d", &buffer);
        // False conditions
        if(buffer == 0) {
            printf("Sum = %d\n", sum);  // Output
            break;
        }
        else if(buffer < 0) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        // True condition
        sum += buffer;
    }
    return 0;
}
