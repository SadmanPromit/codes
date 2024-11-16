#include <stdio.h>
int main() {
    int m, n, isfirst = 0, last, i;
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
        // Print the output series
        if(i % 2 == 0 && i % 3 != 0 && isfirst == 1)
            printf("%d, ", i++);    // Increment to only check for even values for optimization
        // Print the output prompt
        else if(i % 2 == 0 && i % 3 != 0 && isfirst == 0) {
            isfirst = 1;
            printf("%d and %d except those divisible by 3 are: %d, ", i, last, i);
            continue;
        }
    }
    printf("%d\n", last);
    return 0;
}
