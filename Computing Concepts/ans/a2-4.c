#include <stdio.h>
int main() {
    int m, n, first_flag = 0, last, i;
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("All even numbers between ");
    // Finding the last output
    for(i = n; i >= m; i--)
        if(i % 2 == 0 && i % 3 != 0){
            last = i;
            break;
        }
    for(i = m; i < last; i++) {
        // False conditions
        if(i % 2 != 0 || i % 3 == 0)
            continue;
        // Print the output prompt
        else if(i % 2 == 0 && i % 3 != 0 && !first_flag) {
            first_flag = 1;
            printf("%d and %d except those divisible by 3 are: %d, ", i, last, i);
            i++;    // Skip to next even value
            continue;
        }
        // Print the output series
        printf("%d, ", i++);    // Increment to only check for even values for optimization
    }
    printf("%d.\n", last);
    return 0;
}
