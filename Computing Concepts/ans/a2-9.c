#include <stdio.h>
int main() {
    int m, n, count = 0, first_flag = 0;
    double average;
    long long sum = 0;  // To increase range
    printf("Enter m: ");
    scanf("%d", &m);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("All palindrome numbers between %d and %d: ", m, n);
    for(int i = m; i <= n; i++) {
        // Temporary variables only needed for each iteration
        int number = i, reverse_number = 0;
        while(number != 0) {
            reverse_number = reverse_number * 10 + number % 10;
            number /= 10;
        }
        if(i == reverse_number) {
            sum += i;
            count++;
            // Formating the output properly
            if(first_flag)
                printf(", %d", i);
            else {
                printf("%d", i);
                first_flag = 1;
            }
        }
    }
    average = sum / count;
    printf(".\nSum: %lld\nCount: %d\nAverage: %lf\n", sum, count, average);
    // Reverse
    first_flag = 0; // Reset the flag for new series
    printf("All palindrome numbers in reverse order between %d and %d: ", m, n);
    for(int i = n; i >= m; i--) {
        // Temporary variables only needed for each iteration
        int number = i, reverse_number = 0;
        while(number != 0) {
            reverse_number = reverse_number * 10 + number % 10;
            number /= 10;
        }
        if(i == reverse_number)
            // Formating the output properly
            if(first_flag)
                printf(", %d", i);
            else {
                printf("%d", i);
                first_flag = 1;
            }
    }
    printf(".\n");
    return 0;
}
