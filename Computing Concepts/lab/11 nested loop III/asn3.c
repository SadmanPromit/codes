#include <stdio.h>
int main() {
    int n, i = 0, first_flag = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("The first %d palindrome numbers: ", n);
    while(n > 0) {
        // Temporary variables only needed for each iteration
        int number = i, reverse_number = 0;
        while(number != 0) {
            reverse_number = reverse_number * 10 + number % 10;
            number /= 10;
        }
        if(i == reverse_number) {
            // Formating the output properly
            if(first_flag)
                printf(", %d", i);
            else {
                printf("%d", i);
                first_flag = 1;
            }
            n--;
        }
        i++;
    }
    printf(".\n");
    return 0;
}
